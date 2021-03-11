#include "cbot/serial.h"

#include "cga/cga.h"
#include "cga/geometry.h"
#include "cga/transform.h"
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
    bool is_valid(constraint_t constraint);

    // Implementation specific constants
    // None

    // Implementation specific state and validity flags
    cga::Versor ee_transform;
    std::vector<cga::Versor> transforms;
    Eigen::Matrix<double, 6, Eigen::Dynamic> jacobian;
    bool transforms_valid;
    bool jacobian_valid;

    // Implementation specific function
    void update_jacobian();
};


Serial::Impl::Impl(const Dimensions &dim, const JointNames &joint_names):
    dim(dim), joint_names(joint_names)
{
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        joints.emplace(joint_names[i], Joint());
        transforms.push_back(cga::Versor());
    }

    transforms_valid = false;
    jacobian_valid = false;

    jacobian = Eigen::Matrix<double, 6, Eigen::Dynamic>(6, joint_names.size());
}

// ========= Required functions ==========

cga::Versor get_dh_transform(const Serial::DHParameter &dh)
{
    return cga::make_translation(dh.a, 0, 0)
        * cga::make_rotation(dh.alpha, cga::make_axis(1, 0, 0))
        * cga::make_translation(0, 0, dh.d)
        * cga::make_rotation(dh.theta, cga::make_axis(0, 0, 1));
}

bool Serial::Impl::update_pose()
{
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        dim.dh_parameters[i].set_q(joints[joint_names[i]].position);
        transforms[i] = get_dh_transform(dim.dh_parameters[i]);
    }

    // ee_transform = transform[0] * ... * transform[N]
    ee_transform = transforms[0];
    for (std::size_t i = 1; i < transforms.size(); i++) {
        ee_transform = ee_transform * transforms[i];
    }

    cga::Rotor3 R;
    cga::Vector3 p;
    cga::extract_components(ee_transform, R, p);

    pose.position.x = p.e1;
    pose.position.y = p.e2;
    pose.position.z = p.e3;
    pose.orientation.w = R.s;
    pose.orientation.x = -R.b.e23;
    pose.orientation.y = -R.b.e31;
    pose.orientation.z = -R.b.e12;

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
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        theta_vel[i] = joints.at(joint_names[i]).velocity;
    }
    Eigen::Matrix<double, 6, 1> vel = jacobian * theta_vel;

    twist.angular.x = vel[0];
    twist.angular.y = vel[1];
    twist.angular.z = vel[2];
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
    cga::Vector3 start_x;
    cga::Rotor3 start_q;
    cga::extract_components(ee_transform, start_q, start_x);

    constexpr double delta_t = 1.0/20;

    cga::Vector3 goal_x(
        goal.position.x, goal.position.y, goal.position.z);
    cga::Rotor3 goal_q(
        goal.orientation.w, cga::Bivector3(goal.orientation.x, goal.orientation.y, goal.orientation.z));

    double time = ceil(cga::norm(goal_x - start_x)) / constraints.max_linear_speed;

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

// Check state validity

bool Serial::Impl::is_valid(constraint_t constraint)
{
    if (constraint != nullptr && !constraint(joints)) return false;

    if (!jacobian_valid) update_jacobian();
    // if (std::fabs(jacobian.determinant()) < 0.015) return false;
    // TODO: Disabling this for now, since makes control difficult.
    // May be more suitable to only use this when planning trajectories.

    return true;
}

// Implementation specific functions

void Serial::Impl::update_jacobian()
{
    if (!transforms_valid) update_pose();

    cga::Rotor3 ee_R;
    cga::Vector3 ee_p;
    cga::extract_components(ee_transform, ee_R, ee_p);

    std::vector<cga::Bivector> columns(joint_names.size());

    std::cout << "Updating jacobian" << std::endl;

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        if (dim.dh_parameters[i].fixed_alpha) {
            columns[i].e12 = 1;
        } else {
            columns[i].e23 = std::cos(dim.dh_parameters[i].theta);
            columns[i].e31 = -std::sin(dim.dh_parameters[i].theta);
            columns[i].e1i = -dim.dh_parameters[i].d*std::sin(dim.dh_parameters[i].theta);
            columns[i].e2i = -dim.dh_parameters[i].d*std::cos(dim.dh_parameters[i].theta);
        }
        for (std::size_t j = i+1; j < joint_names.size(); j++) {
            columns[i] = (cga::reverse(transforms[i])*columns[i]*transforms[i]).b;
        }
        // Refer back to the root frame
        columns[i] = (ee_R*columns[i]*cga::reverse(ee_R)).b;
    }

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        jacobian(0,i) = columns[i].e23;
        jacobian(1,i) = columns[i].e31;
        jacobian(2,i) = columns[i].e12;
        jacobian(3,i) = columns[i].e1i;
        jacobian(4,i) = columns[i].e2i;
        jacobian(5,i) = columns[i].e3i;
    }
    std::cout << "Jacobian:" << std::endl << jacobian << std::endl;

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
bool Serial::update_dependent_joints() { return true; } // Not required
bool Serial::calculate_trajectory(const Pose &goal) { return pimpl->calculate_trajectory(goal); }
bool Serial::is_valid(constraint_t constraint) {
    return pimpl->is_valid(constraint);
}

// Set trajectory constraints and get trajectory

// Setters

void Serial::set_pose(const Pose &pose) {
    pimpl->pose = pose;
    auto T_ee = cga::make_translation(pose.position.x, pose.position.y, pose.position.z);
    auto R_ee = cga::make_rotation(
        pose.orientation.w,
        cga::Bivector3(pose.orientation.x, pose.orientation.y, pose.orientation.z)
    );
    pimpl->ee_transform = T_ee * R_ee;
    pimpl->transforms_valid = false;
    pimpl->jacobian_valid = false;
}
void Serial::set_twist(const Twist &twist) {
    pimpl->twist = twist;
}
void Serial::set_joint_position(const std::string &name, double value) {
    if (pimpl->joints.find(name) != pimpl->joints.end() && !pimpl->joints[name].dependent) {
        pimpl->joints[name].position = value;
    }
    pimpl->transforms_valid = false;
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
