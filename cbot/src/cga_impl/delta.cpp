#include "cbot/delta.h"

#include "cga/cga.h"
#include "cga/geometry.h"
#include "cga/transform.h"
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
    cga::Vector3 u[3]; // Unit vector to each base joint
    cga::Vector3 v[3]; // v[i] perpendicular to u[i]
    Eigen::Matrix3d R[3]; // R[i] rotates x into frame aligned with upper link

    // Implementation specific state and validity flags
    cga::Vector3 x;
    double orientation;
    cga::Vector3 d[3];
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
    joints.emplace(joint_names.theta_4, Joint());

    for (int i = 0; i < 3; i++) {
        u[i].e1 = std::cos(i*M_PI*2/3);
        u[i].e2 = std::sin(i*M_PI*2/3);
        v[i].e1 = -u[i].e2;
        v[i].e2 = u[i].e1;
    }

    x_valid = false;
    jacobian_valid = false;

    // Set pose orientation to a constant value
    pose.orientation.w = 1;

    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 0;
}

// ========= Required functions ==========

bool Delta::Impl::update_pose()
{
    // Location of each pseudo-elbow point, and corresponding spheres
    cga::Vector D_sphere[3];
    double theta_i;
    for (int i = 0; i < 3; i++) {
        theta_i = joints.at(joint_names.theta[i]).position;
        d[i] = u[i] * (
            dim.r_base + dim.l_upper * std::cos(theta_i) - dim.r_ee
        );
        d[i].e3 = -dim.l_upper*std::sin(theta_i);
        D_sphere[i] = cga::make_sphere(d[i], dim.l_lower);
    }

    auto result = cga::intersect(D_sphere);
    if (!result.valid) return false;

    x = (result.point1.e3 < result.point2.e3 ? result.point1 : result.point2);
    x_valid = true;

    // Read end effector position from y
    pose.position.x = x.e1;
    pose.position.y = x.e2;
    pose.position.z = x.e3 - dim.gripper_offset;

    orientation = joints.at(joint_names.theta_4).position;
    pose.orientation.w = std::cos(orientation/2);
    pose.orientation.z = std::sin(orientation/2);

    return true;
}

bool Delta::Impl::update_joint_positions()
{
    cga::Vector sphere_x = cga::make_sphere(x, dim.l_lower);
    cga::Vector3 f, upper_disp;
    cga::Bivector F;
    cga::PointPair result;
    for (int i = 0; i < 3; i++) {
        f = u[i]*(dim.r_base - dim.r_ee);
        F = outer(
            // Intersect plane of upper link with ..
            cga::dual(cga::outer(u[i], cga::e3)),
            // .. sphere about joint, of radius = upper length
            cga::make_sphere(f, dim.l_upper)
        );
        result = cga::intersect(F, sphere_x);
        if (!result.valid) return false;
        d[i] = (inner(result.point1, u[i]) > inner(result.point2, u[i]) ?
            result.point1 : result.point2);
        upper_disp = d[i] - f;
        joints.at(joint_names.theta[i]).position = std::asin(-upper_disp.e3/dim.l_upper);
    }

    joints.at(joint_names.theta_4).position = orientation;
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

    twist.angular.z = joints.at(joint_names.theta_4).velocity;

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

    joints.at(joint_names.theta_4).velocity = twist.angular.z;

    return true;
}

bool Delta::Impl::update_dependent_joints()
{
    if (!x_valid) {
        update_pose();
    }

    cga::Vector3 lower_disp;
    double theta_i, alpha_i, beta_i, gamma_i;
    for (int i = 0; i < 3; i++) {
        lower_disp = x - d[i];

        theta_i = joints[joint_names.theta[i]].position;
        gamma_i = std::atan2(
            -lower_disp.e3,
            -cga::inner(lower_disp, u[i])
        );
        beta_i = std::asin(
            cga::inner(lower_disp, v[i]) / dim.l_lower
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

    cga::Vector3 x0 = x;
    cga::Vector3 x1(goal.position.x, goal.position.y, goal.position.z+dim.gripper_offset);

    double R0 = orientation;
    double R1;
    if (goal.orientation.z > 0) {
        R1 = 2*std::acos(goal.orientation.w);
    } else {
        R1 = 2*M_PI - 2*std::acos(goal.orientation.w);
    }

    cga::Vector3 delta_x = x1 - x0;
    double delta_R = R1 - R0;
    if (delta_R > M_PI) delta_R -= 2*M_PI;
    if (delta_R < -M_PI) delta_R += 2*M_PI;

    trajectory.names = joint_names.theta;
    trajectory.names.push_back(joint_names.theta_4);
    double tau, u;
    cga::Vector3 v;
    double omega;

    double max_joint_speed = 0;
    double T1 = 1.5*cga::norm(delta_x) / constraints.max_linear_speed;
    double T2 = 1.5*delta_R / constraints.max_angular_speed;
    double T = (T1 > T2 ? T1 : T2);

    static constexpr double delta_t = 1e-2;
    std::size_t N = (T / delta_t) + 1;
    trajectory.points.resize(N);

    for (std::size_t i = 0; i < N; i++) {
        tau = ((double)(i+1))/N;
        u = 3*std::pow(tau, 2) - 2*std::pow(tau, 3);
        x = x0 + u*delta_x;
        orientation = R0 + u*delta_R;

        // IK
        if (!update_joint_positions()) return false;

        v = (6/T)*tau*(1-tau)*delta_x;
        omega = (6/T)*tau*(1-tau)*delta_R;
        twist.linear.x = v.e1;
        twist.linear.y = v.e2;
        twist.linear.z = v.e3;
        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = omega;
        update_joint_velocities();

        // Copy joints into trajectory and find max joint velocity
        trajectory.points[i].positions.resize(4);
        for (std::size_t j = 0; j < 4; j++) {
            Joint &joint = joints.at(trajectory.names[j]);
            trajectory.points[i].positions[j] = joint.position;
            double joint_speed = std::abs(joint.velocity);
            if (joint_speed > max_joint_speed) {
                max_joint_speed = joint_speed;
            }
        }
    }

    if (max_joint_speed > constraints.max_joint_speed) {
        T = max_joint_speed / constraints.max_joint_speed;
    }
    for (std::size_t i = 0; i < N; i++) {
        trajectory.points[i].time = T*((double)(i+1))/N;
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
    cga::Vector3 n, v_hat;
    for (int i = 0; i < 3; i++){
        theta_i = joints.at(joint_names.theta[i]).position;
        n = (x - d[i])/cga::norm(x - d[i]);
        v_hat = -dim.l_lower*(std::sin(theta_i)*u[i] + std::cos(theta_i)*cga::Vector3(0,0,1));
        jx.block<1, 3>(i, 0) = Eigen::Vector3d(n.e1, n.e2, n.e3);
        jtheta(i, i) = cga::inner(n, v_hat);
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
    pimpl->x.e1 = pose.position.x;
    pimpl->x.e2 = pose.position.y;
    pimpl->x.e3 = pose.position.z+pimpl->dim.gripper_offset;
    if (pose.orientation.z > 0) {
        pimpl->orientation = 2*std::acos(pose.orientation.w);
    } else {
        pimpl->orientation = 2*M_PI - 2*std::acos(pose.orientation.w);
    }
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
