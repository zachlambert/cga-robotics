#include "cbot/delta.h"

#include <Eigen/Dense>

#define SQ(x) (x*x)

namespace cbot {

// ========== Delta::Impl class definition ==========

class Delta::Impl {
public:
    Impl(const Dimensions &dim, const JointNames &joint_names);
    bool update_pose(const Joints &joints, Pose &pose);
    bool update_twist(const Joints &joints, Twist &twist);
    bool update_joint_positions(const Pose &pose, Joints &joints);
    bool update_joint_velocities(const Twist &twist, Joints &joints);
    bool update_dependent_joints(Joints &joints);
    bool calculate_trajectory(const Joints &joints, const Pose &pose, const TrajectoryConstraints &constraints, JointTrajectory &trajectory);

    // Computation valid flags
    bool position_valid; // d[3], x
    bool jacobian_valid; // jx and jtheta

    Pose pose;
    Twist twist;
    Joints joints;

private:
    void update_jacobian(const Joints &joints_pos);

    Dimensions dim;
    JointNames joint_names;

    // Unit vectors towards and perpendicular to each base joint
    Eigen::Vector3d u[3];
    Eigen::Vector3d v[3];
    Eigen::Matrix3d R[3];

    Eigen::Vector3d d[3];
    Eigen::Vector3d x; // End effector position

    // For calculating jacobian
    Eigen::Matrix3d jx, jtheta;
};

Delta::Impl::Impl(
    const Dimensions &dim, const JointNames &joint_names):
        dim(dim), joint_names(joint_names)
{
    for (int i = 0; i<3; i++) {
        joints.emplace(joint_names.theta[i], Joint());
        joints.emplace(joint_names.alpha[i], Joint(true));
        joints.emplace(joint_names.beta[i], Joint(true));
        joints.emplace(joint_names.gamma[i], Joint(true));
    }
    auto angle_axis= Eigen::AngleAxisd();
    angle_axis.axis() = Eigen::Vector3d(0, 0, 1);
    for (int i = 0; i < 3; i++) {
        angle_axis.angle() = i*M_PI*2/3;
        R[i] = angle_axis.toRotationMatrix();
        u[i] = R[i].col(0);
        v[i] = R[i].col(1);
    }

    position_valid = false;
    jacobian_valid = false;
}


// ========= Delta::Impl kinematics methods =========

bool Delta::Impl::update_pose(const Joints &joints, Pose &pose)
{
    double theta_i;
    for (int i = 0; i < 3; i++) {
        theta_i = joints.at(joint_names.theta[i]).position;
        d[i] = u[i] * (dim.r_base + dim.l_upper*std::cos(theta_i) - dim.r_ee);
        d[i].z() = -dim.l_upper * std::sin(theta_i);
    }

    // Form a circle of possible ee position from the second
    // and third two pseudo-elbow position
    auto centre = 0.5*(d[0] + d[1]);
    auto u1 = (d[1]-d[0]).normalized();
    auto u3 = u1.cross(d[2]-d[0]).normalized();
    auto u2 = u3.cross(u1);

    double w = 0.5*(d[1] - d[0]).norm();
    double r = std::sqrt(SQ(dim.l_lower) - SQ(w));
    double p = (d[2] - centre).dot(u1);
    double q = (d[2] - centre).dot(u2);
    double t = std::hypot(p, q);

    double cos_alpha = (SQ(t) - SQ(w)) / (2*q*r);
    // Plus or minus. Using plus for end effector below base
    double sin_alpha = std::sqrt(1 - SQ(cos_alpha));

    x = centre + r*u2*cos_alpha - r*u3*sin_alpha;
    position_valid = true;

    pose.position.x = x.x();
    pose.position.y = x.y();
    pose.position.z = x.z();
    pose.orientation.w = 1/std::sqrt(2);
    pose.orientation.y = 1/std::sqrt(2);

    return true;
}

bool Delta::Impl::update_joint_positions( const Pose &pose, Joints &joints)
{
    x.x() = pose.position.x;
    x.y() = pose.position.y;
    x.z() = -pose.position.z; // Use z positive downward

    Eigen::Vector3d yi;
    for (int i = 0; i < 3; i++) {
        // Rotate into frame where u[i] = x.
        yi = R[i].transpose() * x;
        // Change to displacement between base joint and
        // end effector joint
        yi.x() += dim.r_ee - dim.r_base;

        double k = (SQ(dim.l_lower) - SQ(dim.l_upper) - yi.squaredNorm()) / (-2*dim.l_upper);

        double P = yi.z();
        double Q = yi.x();

        double R = std::hypot(yi.x(), yi.z());
        double alpha = std::atan2(yi.x(), yi.z());

        if (std::fabs(k/R) > 1) return false;

        double sum = std::asin(k/R);
        double solution1 = sum - alpha;
        double solution2 = M_PI - sum - alpha;
        if (solution1 < -M_PI) solution1 += 2*M_PI;
        if (solution2 < -M_PI) solution2 += 2*M_PI;
        if (solution2 > M_PI) solution2 -= 2*M_PI;

        joints[joint_names.theta[i]].position =
            fabs(solution1) < fabs(solution2) ? solution1 : solution2;
    }
    return true;
}

bool Delta::Impl::update_twist(const Joints &joints, Twist &twist)
{
    if (!jacobian_valid) {
        update_jacobian(joints);
    }
    Eigen::Vector3d theta_vel;
    for (int i = 0; i < 3; i++) {
        theta_vel[i] = joints.at(joint_names.theta[i]).velocity;
    }
    Eigen::Vector3d vel = jx.inverse() * jtheta * theta_vel;

    twist.linear.x = vel[0];
    twist.linear.y = vel[1];
    twist.linear.z = vel[2];
    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 0;

    return true;
}

bool Delta::Impl::update_joint_velocities(const Twist &twist, Joints &joints)
{
    if (!jacobian_valid) {
        update_jacobian(joints);
    }

    Eigen::Vector3d vel(twist.linear.x, twist.linear.y, twist.linear.z);
    Eigen::Vector3d theta_vel = jtheta.inverse() * jx * vel;

    for (int i = 0; i < 3; i++) {
        joints[joint_names.theta[i]].velocity = theta_vel(i);
    }

    return true;
}

bool Delta::Impl::update_dependent_joints(Joints &joints)
{
    if (!position_valid) {
        Pose pose; // unused
        update_pose(joints, pose);
    }

    Eigen::Vector3d lower_disp;
    double theta_i, alpha_i, beta_i, gamma_i;
    for (int i = 0; i < 3; i++) {
        lower_disp = x - d[i];

        theta_i = joints[joint_names.theta[i]].position;
        gamma_i = std::atan2(
            -lower_disp.z(),
            -lower_disp.dot(u[i])
        );
        beta_i = std::asin(
            lower_disp.dot(v[i]) / dim.l_lower
        );
        alpha_i = M_PI - theta_i - gamma_i;

        joints[joint_names.alpha[i]].position = alpha_i;
        joints[joint_names.beta[i]].position = beta_i;
        joints[joint_names.gamma[i]].position = gamma_i;
    }
    return true;
}

bool Delta::Impl::calculate_trajectory(const Joints &joints, const Pose &goal, const TrajectoryConstraints &constraints, JointTrajectory &trajectory)
{
    if (!position_valid) {
        Pose pose; // unused
        update_pose(joints, pose);
    }

    constexpr double delta_t = 1.0/20;

    Eigen::Vector3d start_y = y;
    Eigen::Vector3d goal_y(goal.position.x, goal.position.y, goal.position.z);
    double time = ceil((goal_y - start_y).norm() / constraints.max_linear_speed);

    std::size_t N = ceil(time / delta_t);

    Eigen::Vector3d current_y;
    Pose current_pose;
    Joints current_joints;
    trajectory.points.resize(N);
    trajectory.names = joint_names.theta;
    for (std::size_t i = 0; i < N; i++) {
        // u = normalised time
        double u = ((double)i) / N;
        trajectory.points[i].time = u * time;
        trajectory.points[i].positions.resize(joint_names.theta.size());

        // For now just fit a linear trajectory
        current_y = start_y + u * (goal_y - start_y);
        current_pose.position.x = current_y.x();
        current_pose.position.y = current_y.y();
        current_pose.position.z = current_y.z();
        if (!update_joint_positions(current_pose, current_joints)) {
            return false;
        }

        for (std::size_t j = 0; j < joint_names.theta.size(); j++) {
            trajectory.points[i].positions[j] = current_joints.at(joint_names.theta[j]).position;
        }
    }
    return true;
}

void Delta::Impl::update_jacobian(const Joints &joints)
{
    if (!position_valid) {
        Pose pose; // Unused
        update_pose(joints, pose);
    }

    double theta_i;
    for (int i = 0; i < 3; i++){
        theta_i = joints.at(joint_names.theta[i]).position;

        jtheta.block<1, 1>(i, i) = y.transpose()*jA[i]*s[i] + jB[i]*s[i];
        jx.block<1, 3>(i, 0) = s[i].transpose()*jC[i] + jD[i] - y.transpose();
    }
    jacobian_valid = true;
}


// ========== Pimpl stuff ==========

Delta::Delta(const Dimensions &dim, const JointNames &joint_names):
    pimpl(new Impl(dim, joint_names)) {
}

Delta::~Delta() = default;
Delta::Delta(Delta&&) = default;
Delta& Delta::operator=(Delta&&) = default;

bool Delta::update_pose() {
    return pimpl->update_pose(joints, pose);
}
bool Delta::update_twist() {
    return pimpl->update_twist(joints, twist);
}
bool Delta::update_joint_positions() {
    return pimpl->update_joint_positions(pose, joints);
}
bool Delta::update_joint_velocities() {
    return pimpl->update_joint_velocities(twist, joints);
}
bool Delta::update_dependent_joints() {
    return pimpl->update_dependent_joints(joints);
}
bool Delta::calculate_trajectory(const Pose &pose, const TrajectoryConstraints &constraints, JointTrajectory &trajectory) {
    return pimpl->calculate_trajectory(joints, pose, constraints, trajectory);
}

// Getters and setters

const Pose &get_pose()const{ return pimpl->pose; }
const Twist &get_twist()const{ return pimpl->twist; }
const Joints &get_joint_position(const std::string &name)const{
    return pimpl->joints.at(name).position;
}
const Joints &get_joint_velocity(const std::string &name)const{
    return pimpl->joints.at(name).velocity;
}

void Delta::set_pose(const Pose &pose) {
    pimpl->pose = pose;
    pimpl->position_valid = false;
    pimpl->jacobian_valid = false;
}
void Delta::set_twist(const Twist &twist) {
    pimpl->twist = twist;
}
void Delta::set_joint_position(const std::string &name, double value) {
    if (joints.find(name) != joints.end() && !joints[name].dependent) {
        joints[name].position = value;
    }
    pimpl->position_valid = false;
    pimpl->jacobian_valid = false;
}
void Delta::set_joint_velocity(const std::string &name, double value) {
    if (joints.find(name) != joints.end() && !joints[name].dependent) {
        joints[name].velocity = value;
    }
}

const std::vector<std::string> Delta::get_independent_joint_names()const
{
    std::vector<std::string> joint_names;
    for (auto it = pimpl->joints.begin(); it != pimpl->joints.end(); it++) {
        if (!it->second.dependent) joint_names.push_back(it->first);
    }
    return joint_names;
}
const std::vector<std::string> Delta::get_dependent_joint_names()const
{
    std::vector<std::string> joint_names;
    for (auto it = pimpl->joints.begin(); it != pimpl->joints.end(); it++) {
        if (it->second.dependent) joint_names.push_back(it->first);
    }
    return joint_names;
}

} // namespace cbot
