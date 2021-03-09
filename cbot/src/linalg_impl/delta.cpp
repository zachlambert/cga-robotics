#include "cbot/delta.h"

#include <Eigen/Dense>

#define SQ(x) (x*x)

namespace cbot {

// ========== Delta::State class definition ==========

struct Delta::Impl {
    Impl(const Dimensions &dim, const JointNames &joint_names);

    // Required constants
    Dimensions dim;
    JointNames joint_names;

    // Required state
    Pose pose;
    Twist twist;
    Joints joints;
    TrajectoryConstraints constraints;
    JointTrajectory trajectory;

    // Required functions
    bool update_pose();
    bool update_twist();
    bool update_joint_positions();
    bool update_joint_velocities();
    bool update_dependent_joints();
    bool calculate_trajectory(const Pose &goal);
    bool is_valid(constraint_t constraint);

    // Implementation specific constants
    Eigen::Vector3d u[3]; // Unit vector to each base joint
    Eigen::Vector3d v[3]; // v[i] perpendicular to u[i]
    Eigen::Matrix3d R[3]; // R[i] rotates x into frame aligned with upper link

    // Implementation specific state and validity flags
    Eigen::Vector3d x;
    Eigen::Vector3d d[3];
    Eigen::Matrix3d jx, jtheta;
    bool x_valid;
    bool di_valid;
    bool jacobian_valid;

    // Implementation specific function
    void update_x();
    void update_jacobian();
};


Delta::Impl::Impl(const Dimensions &dim, const JointNames &joint_names):
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

    x_valid = false;
    jacobian_valid = false;

    // Set pose orientation to a constant value
    pose.orientation.w = 1/std::sqrt(2);
    pose.orientation.y = 1/std::sqrt(2);

    // Angular velocity always zero
    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 0;
}

// ========= Required functions ==========

bool Delta::Impl::update_pose()
{
    double theta_i;
    for (int i = 0; i < 3; i++) {
        theta_i = joints.at(joint_names.theta[i]).position;
        d[i] = u[i] * (dim.r_base + dim.l_upper*std::cos(theta_i) - dim.r_ee);
        d[i].z() = -dim.l_upper * std::sin(theta_i);
    }
    di_valid = true;

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
    x_valid = true;

    pose.position.x = x.x();
    pose.position.y = x.y();
    pose.position.z = x.z();

    return true;
}

bool Delta::Impl::update_joint_positions()
{
    Eigen::Vector3d xi;
    for (int i = 0; i < 3; i++) {
        // Rotate into frame where u[i] = x.
        xi = R[i].transpose() * x;
        // Change to displacement between base joint and
        // end effector joint
        xi.x() += dim.r_ee - dim.r_base;

        double k = (SQ(dim.l_lower) - SQ(dim.l_upper) - xi.squaredNorm()) / (-2*dim.l_upper);

        double P = -xi.z(); // Make it positive downard
        double Q = xi.x();

        double R = std::hypot(xi.x(), xi.z());
        double alpha = std::atan2(xi.x(), -xi.z());

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

bool Delta::Impl::update_twist()
{
    if (!jacobian_valid) {
        update_jacobian();
    }
    Eigen::Vector3d theta_vel;
    for (int i = 0; i < 3; i++) {
        theta_vel[i] = joints.at(joint_names.theta[i]).velocity;
    }
    Eigen::Vector3d vel = jx.inverse() * jtheta * theta_vel;

    twist.linear.x = vel[0];
    twist.linear.y = vel[1];
    twist.linear.z = vel[2];

    return true;
}

bool Delta::Impl::update_joint_velocities()
{
    if (!jacobian_valid) {
        update_jacobian();
    }

    Eigen::Vector3d vel(twist.linear.x, twist.linear.y, twist.linear.z);
    Eigen::Vector3d theta_vel = jtheta.inverse() * jx * vel;

    for (int i = 0; i < 3; i++) {
        joints[joint_names.theta[i]].velocity = theta_vel(i);
    }

    return true;
}

bool Delta::Impl::update_dependent_joints()
{
    if (!x_valid) {
        update_pose();
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

// Trajectory functions

bool Delta::Impl::calculate_trajectory(const Pose &goal)
{
    if (!x_valid) {
        update_pose();
    }

    constexpr double delta_t = 1.0/20;

    Eigen::Vector3d start_x = x;
    Eigen::Vector3d goal_x(goal.position.x, goal.position.y, goal.position.z);
    double time = ceil((goal_x - start_x).norm() / constraints.max_linear_speed);

    std::size_t N = ceil(time / delta_t);

    trajectory.points.resize(N);
    trajectory.names = joint_names.theta;
    for (std::size_t i = 0; i < N; i++) {
        // u = normalised time
        double u = ((double)i) / N;
        trajectory.points[i].time = u * time;
        trajectory.points[i].positions.resize(joint_names.theta.size());

        // For now just fit a linear trajectory
        x = start_x + u * (goal_x - start_x);
        if (!update_joint_positions()) {
            return false;
        }

        for (std::size_t j = 0; j < joint_names.theta.size(); j++) {
            trajectory.points[i].positions[j] = joints.at(joint_names.theta[j]).position;
        }
    }
    return true;
}

// Check state validity

bool Delta::Impl::is_valid(constraint_t constraint)
{
    if (constraint != nullptr && !constraint(joints)) return false;

    if (!jacobian_valid) update_jacobian();
    for (int i = 0; i < 3; i++) {
        if (std::fabs(jtheta(i,i)) < 0.2) return false;
    }

    return true;
}

// Implementation specific functions

void Delta::Impl::update_jacobian()
{
    if (!x_valid) {
        update_pose();
    }

    double theta_i;
    Eigen::Vector3d n, v_hat;
    for (int i = 0; i < 3; i++){
        theta_i = joints.at(joint_names.theta[i]).position;
        n = (x - d[i]).normalized();
        v_hat = -dim.l_lower*(std::sin(theta_i)*u[i] + std::cos(theta_i)*Eigen::Vector3d(0,0,1));
        jx.block<1, 3>(i, 0) = n;
        jtheta(i, i) = n.dot(v_hat);
    }
    jacobian_valid = true;
}

// Constructor

// ========= Pimpl stuff ==========

Delta::Delta(const Dimensions &dim, const JointNames &joint_names):
    pimpl(new Impl(dim, joint_names)) {}

Delta::~Delta() = default;
Delta::Delta(Delta&&) = default;
Delta& Delta::operator=(Delta&&) = default;

bool Delta::update_pose() { return pimpl->update_pose(); }
bool Delta::update_twist() { return pimpl->update_twist(); }
bool Delta::update_joint_positions() { return pimpl->update_joint_positions(); }
bool Delta::update_joint_velocities() { return pimpl->update_joint_velocities(); }
bool Delta::update_dependent_joints() { return pimpl->update_dependent_joints(); }
bool Delta::calculate_trajectory(const Pose &goal) { return pimpl->calculate_trajectory(goal); }
bool Delta::is_valid(constraint_t constraint) { return pimpl->is_valid(constraint); }

// Set trajectory constraints and get trajectory

// Setters

void Delta::set_pose(const Pose &pose) {
    pimpl->pose = pose;
    pimpl->x.x() = pose.position.x;
    pimpl->x.y() = pose.position.y;
    pimpl->x.z() = pose.position.z;
    pimpl->x_valid = true;
    pimpl->di_valid = false;
    pimpl->jacobian_valid = false;
}
void Delta::set_twist(const Twist &twist) {
    pimpl->twist = twist;
}
void Delta::set_joint_position(const std::string &name, double value) {
    if (pimpl->joints.find(name) != pimpl->joints.end() && !pimpl->joints[name].dependent) {
        pimpl->joints[name].position = value;
    }
    pimpl->x_valid = false;
    pimpl->di_valid = false;
    pimpl->jacobian_valid = false;
}
void Delta::set_joint_velocity(const std::string &name, double value) {
    if (pimpl->joints.find(name) != pimpl->joints.end() && !pimpl->joints[name].dependent) {
        pimpl->joints[name].velocity = value;
    }
}
void Delta::set_trajectory_constraints(const TrajectoryConstraints &constraints){
    pimpl->constraints = constraints;
}

// Getters

const Pose &Delta::get_pose()const{ return pimpl->pose; }
const Twist &Delta::get_twist()const{ return pimpl->twist; }
const double &Delta::get_joint_position(const std::string &name)const{
    return pimpl->joints.at(name).position;
}
const double &Delta::get_joint_velocity(const std::string &name)const{
    return pimpl->joints.at(name).velocity;
}
const JointTrajectory &Delta::get_trajectory()const{
    return pimpl->trajectory;
}


// Get joint names

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
