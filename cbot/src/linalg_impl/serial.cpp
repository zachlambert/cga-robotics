#include "cbot/serial.h"

#include <Eigen/Dense>

#define SQ(x) (x*x)

namespace cbot {

// ========== Serial::State class definition ==========

struct Serial::Impl {
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
    bool calculate_trajectory(const Pose &goal);

    // Implementation specific constants
    // TODO

    // Implementation specific state and validity flags
    Eigen::Isometry3d ee_transform;
    std::vector<Eigen::Isometry3d> transforms;
    std::vector<Eigen::Matrix<double, 6, 6>> velocity_transforms;
    Eigen::Matrix<double, 6, Eigen::Dynamic> jacobian;
    bool transforms_valid;
    bool jacobian_valid;

    // Implementation specific function
    void update_transforms();
    void update_jacobian();
};


Serial::Impl::Impl(const Dimensions &dim, const JointNames &joint_names):
    dim(dim), joint_names(joint_names)
{
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        joints.emplace(joint_names[i], Joint());
        transforms.push_back(Eigen::Isometry3d());
        velocity_transforms.push_back(Eigen::Matrix<double, 6, 6>());
    }

    transforms_valid = false;
    jacobian_valid = false;

    jacobian = Eigen::Matrix<double, 6, Eigen::Dynamic>(joint_names.size());
}

// ========= Required functions ==========

Eigen::Quaterniond rotation_to_quaternion(const Eigen::Matrix3d &R)
{
    Eigen::Quaterniond result;
    result.w() = 0.5*std::sqrt(1 + R(0,0) + R(1,1) + R(2,2));
    result.x() = 0.25*(R(2,1)-R(1,2))/result.w();
    result.y() = 0.25*(R(0,2)-R(2,0))/result.w();
    result.z() = 0.25*(R(1,0)-R(0,1))/result.w();
    return result;
}

Eigen::Isometry3d get_dh_transform(const Serial::DHParameter &dh, double q)
{
    return Eigen::AngleAxisd(dh.alpha, Eigen::Vector3f::UnitX())
        * Eigen::Translation3d(dh.a, 0 , 0)
        * Eigen::AngleAxisd(q, Eigen::Vector3d::UnitZ())
        * Eigen::Translation3d(0, 0, dh.d);
}


bool Serial::Impl::update_pose()
{
    double q_i;
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        transforms[i] = get_dh_transform(
            dim.dh_parameters[i], joints[joint_names[i]].position);
    }

    // ee_transform = transform[0] * ... * transform[N]
    for (std::size_t i = 0; i < transforms.size(); i++) {
        ee_transform = ee_transform * transforms[i];
    }

    Eigen::Vector3d pos = ee_transform.translation();
    Eigen::Quaterniond orient = rotation_to_quaternion(ee_transform.rotation());

    pose.position.x = pos.x();
    pose.position.y = pos.y();
    pose.position.z = pos.z();
    pose.orientation.w = orient.w();
    pose.orientation.x = orient.x();
    pose.orientation.y = orient.y();
    pose.orientation.z = orient.z();

    transforms_valid = true;

    return true;
}

bool Serial::Impl::update_joint_positions()
{
    // TODO: Not implemented at the moment
    // Use Newton's method with jacobian, starting from current state
    return true;
}

bool Serial::Impl::update_twist()
{
    if (!jacobian_valid) {
        update_jacobian();
    }

    Eigen::VectorXd theta_vel(joint_names.size());
    for (int i = 0; i < 3; i++) {
        theta_vel[i] = joints.at(joint_names[i]).velocity;
    }
    Eigen::Vector3d vel = jacobian * theta_vel;

    twist.angular.x = vel[0];
    twist.angular.y = vel[0];
    twist.angular.z = vel[0];
    twist.linear.x = vel[3];
    twist.linear.y = vel[4];
    twist.linear.z = vel[5];

    return true;
}

bool Serial::Impl::update_joint_velocities()
{
    if (!jacobian_valid) {
        update_jacobian();
    }

    Eigen::VectorXd vel(6);
    vel << twist.angular.x, twist.angular.y, twist.angular.z,
           twist.linear.x, twist.linear.y, twist.linear.z;

    Eigen::Matrix<double, Eigen::Dynamic, 6> jacobian_inv =
        jacobian.completeOrthogonalDecomposition().pseudoInverse();
    Eigen::VectorXd theta_vel = jacobian_inv * vel;

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        joints[joint_names[i]].velocity = theta_vel(i);
    }

    return true;
}


// Trajectory functions

bool Serial::Impl::calculate_trajectory(const Pose &goal)
{
    if (!transforms_valid) update_pose();
    Eigen::Vector3d start_x = ee_transform.translation();
    Eigen::Quaterniond start_q = rotation_to_quaternion(
        ee_transform.rotation());

    constexpr double delta_t = 1.0/20;

    Eigen::Vector3d goal_x(
        goal.position.x, goal.position.y, goal.position.z);
    Eigen::Quaterniond goal_q(
        goal.orientation.w, goal.orientation.x, goal.orientation.y, goal.orientation.z);

    double time = ceil((goal_x - start_x).norm() / constraints.max_linear_speed);

    std::size_t N = ceil(time / delta_t);

    trajectory.points.resize(N);
    trajectory.names = joint_names;
    for (std::size_t i = 0; i < N; i++) {
        // u = normalised time
        double u = ((double)i) / N;
        trajectory.points[i].time = u * time;
        trajectory.points[i].positions.resize(joint_names.size());

        // TODO: Update joints using jacobiana and adjusting step
        // in position and quaternion.
        // Then write positions to joints

        for (std::size_t j = 0; j < joint_names.size(); j++) {
            trajectory.points[i].positions[j] = joints.at(joint_names[j]).position;
        }
    }
    return true;
}

// Implementation specific functions

void Serial::Impl::update_jacobian()
{
    if (!transforms_valid) update_transforms();
    double q_i;
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        Eigen::Vector3d pos = transforms[i].translation();
        Eigen::Matrix3d rotation = transforms[i].rotation();
        velocity_transforms[i].block<3,3>(0,0) = rotation;
        velocity_transforms[i].block<3,3>(3,3) = rotation;
        Eigen::Matrix3d skew_matrix;
        skew_matrix << 0, -pos.z(), pos.y(),
                       pos.z(), 0, -pos.x(),
                       -pos.y(), pos.x(), 0;
        velocity_transforms[i].block<3,3>(3,0) = skew_matrix * rotation;
    }

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        jacobian.block<6,1>(i,0) << 0, 0, 1, 0, 0, 0;
        for (std::size_t j = i+1; j < joint_names.size(); j++) {
            jacobian.block<6,1>(i,0) = velocity_transforms[j]*jacobian.block<6,1>(i,0);
        }
    }

    jacobian_valid = true;
}


// Constructor

// ========= Pimpl stuff ==========

Serial::Serial(const Dimensions &dim, const JointNames &joint_names):
    pimpl(new Impl(dim, joint_names)) {}

Serial::~Serial() = default;
Serial::Serial(Serial&&) = default;
Serial& Serial::operator=(Serial&&) = default;

bool Serial::update_pose() { return pimpl->update_pose(); }
bool Serial::update_twist() { return pimpl->update_twist(); }
bool Serial::update_joint_positions() { return pimpl->update_joint_positions(); }
bool Serial::update_joint_velocities() { return pimpl->update_joint_velocities(); }
bool Serial::update_dependent_joints() { return true; // Not required }
bool Serial::calculate_trajectory(const Pose &goal) { return pimpl->calculate_trajectory(goal); }

// Set trajectory constraints and get trajectory

// Setters

void Serial::set_pose(const Pose &pose) {
    pimpl->pose = pose;
    pimpl->x.x() = pose.position.x;
    pimpl->x.y() = pose.position.y;
    pimpl->x.z() = pose.position.z;
    pimpl->x_valid = true;
    pimpl->di_valid = false;
    pimpl->jacobian_valid = false;
}
void Serial::set_twist(const Twist &twist) {
    pimpl->twist = twist;
}
void Serial::set_joint_position(const std::string &name, double value) {
    if (pimpl->joints.find(name) != pimpl->joints.end() && !pimpl->joints[name].dependent) {
        pimpl->joints[name].position = value;
    }
    pimpl->x_valid = false;
    pimpl->di_valid = false;
    pimpl->jacobian_valid = false;
}
void Serial::set_joint_velocity(const std::string &name, double value) {
    if (pimpl->joints.find(name) != pimpl->joints.end() && !pimpl->joints[name].dependent) {
        pimpl->joints[name].velocity = value;
    }
}
void Serial::set_trajectory_constraints(const TrajectoryConstraints &constraints){
    pimpl->constraints = constraints;
}

// Getters

const Pose &Serial::get_pose()const{ return pimpl->pose; }
const Twist &Serial::get_twist()const{ return pimpl->twist; }
const double &Serial::get_joint_position(const std::string &name)const{
    return pimpl->joints.at(name).position;
}
const double &Serial::get_joint_velocity(const std::string &name)const{
    return pimpl->joints.at(name).velocity;
}
const JointTrajectory &Serial::get_trajectory()const{
    return pimpl->trajectory;
}


// Get joint names

const std::vector<std::string> Serial::get_independent_joint_names()const
{
    std::vector<std::string> joint_names;
    for (auto it = pimpl->joints.begin(); it != pimpl->joints.end(); it++) {
        if (!it->second.dependent) joint_names.push_back(it->first);
    }
    return joint_names;
}
const std::vector<std::string> Serial::get_dependent_joint_names()const
{
    std::vector<std::string> joint_names;
    for (auto it = pimpl->joints.begin(); it != pimpl->joints.end(); it++) {
        if (it->second.dependent) joint_names.push_back(it->first);
    }
    return joint_names;
}

} // namespace cbot
