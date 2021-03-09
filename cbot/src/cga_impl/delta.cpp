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
    for (int i = 0; i < 3; i++) {
        u[i].e1 = std::cos(i*M_PI*2/3);
        u[i].e2 = std::sin(i*M_PI*2/3);
        v[i].e1 = -u[i].e2;
        v[i].e2 = u[i].e1;
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
    pose.position.z = x.e3;

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
            dual(outer(f, cga::e3)),
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

    constexpr double delta_t = 1.0/20;

    cga::Vector3 start_x = x;
    cga::Vector3 goal_x(goal.position.x, goal.position.y, goal.position.z);
    double time = ceil(cga::norm(goal_x - start_x) / constraints.max_linear_speed);

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
    pimpl->x.e3 = pose.position.z;
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
