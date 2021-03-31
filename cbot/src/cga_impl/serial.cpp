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

Eigen::Matrix<double, 6, 1> pose_dif(const cga::Versor &current, const cga::Versor &goal)
{
    Eigen::Matrix<double, 6, 1> difference;
    cga::Vector3 current_x, goal_x;
    cga::Rotor3 current_q, goal_q;
    cga::extract_components(current, current_q, current_x);
    cga::extract_components(goal, goal_q, goal_x);

    difference.block<3,1>(3,0) << goal_x.e1-current_x.e1, goal_x.e2-current_x.e2, goal_x.e3-current_x.e3;

    cga::Rotor3 delta_rotation = goal_q*cga::reverse(current_q);
    double delta_theta = 2*std::acos(delta_rotation.s);
    if (std::fabs(delta_theta) > 1e-6) {
        cga::Bivector3 axis = -delta_rotation.b / std::sin(delta_theta/2);
        axis *= delta_theta;
        difference.block<3,1>(0,0) << axis.e23, axis.e31, axis.e12;
    } else {
        difference.block<3,1>(0,0) = Eigen::Vector3d(0, 0, 0);
    }
    return difference;
}

bool pose_dif_is_zero(const Eigen::Matrix<double, 6, 1> &dif)
{
    // |Position dif| < 1e-3
    if (dif.block<3,1>(3,0).norm() > 1e-3) return false;
    // |delta theta| < 1e-2
    if (dif.block<3,1>(0,0).norm() > 1e-3) return false;
    return true;
}

bool Serial::Impl::update_joint_positions()
{
    auto goal_transform = ee_transform;

    Eigen::Matrix<double, 6, 1> dif;

    Eigen::VectorXd delta_q(joint_names.size());
    Eigen::JacobiSVD<Eigen::Matrix<double, 6, Eigen::Dynamic>> j_svd;

    int max_iter = 100;
    int i = 0;
    while (i < max_iter) {
        // Update pose with current joints and find pose difference
        update_pose();
        dif = pose_dif(ee_transform, goal_transform);

        // Stop if pose_dif after updating joint positions is close to zero
        if (pose_dif_is_zero(dif)) break;

        // Update jacobian, and find jacobian pseudoinverse
        update_jacobian();
        j_svd.compute(jacobian, Eigen::ComputeFullU | Eigen::ComputeFullV);
        delta_q = j_svd.solve(dif);
        for (std::size_t j = 0; j < joint_names.size(); j++) {
            joints[joint_names[j]].position += delta_q(j);
        }
        i++;
    }
    for (std::size_t j = 0; j < joint_names.size(); j++) {
        double pos = joints[joint_names[j]].position;
        while (pos < -M_PI) pos += 2*M_PI;
        while (pos > M_PI) pos -= 2*M_PI;
        joints[joint_names[j]].position = pos;
    }
    if (i >= max_iter) {
        return false;
    } else {
        return true;
    }
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
    cga::Rotor3 start_q;
    cga::Vector3 start_x;
    cga::extract_components(ee_transform, start_q, start_x);

    constexpr double delta_t = 1e-2;

    cga::Vector3 goal_x(
        goal.position.x, goal.position.y, goal.position.z);
    cga::Rotor3 goal_q(
        goal.orientation.w, cga::Bivector3(-goal.orientation.x, -goal.orientation.y, -goal.orientation.z));
    cga::Versor goal_transform =
        cga::make_translation(goal_x.e1, goal_x.e2, goal_x.e3) * goal_q;

    auto start_dif = pose_dif(ee_transform, goal_transform);

    double time_r = ceil(start_dif.block<3,1>(0,0).norm() / constraints.max_angular_speed);
    double time_p = ceil(start_dif.block<3,1>(3,0).norm() / constraints.max_linear_speed);
    double time = time_r > time_p ? time_r : time_p;

    std::size_t N = ceil(time / delta_t);

    trajectory.points.resize(N);
    trajectory.names = joint_names;
    cga::Vector3 x;
    cga::Rotor3 q;
    for (std::size_t i = 0; i < N; i++) {
        // u = normalised time
        double u = ((double)i) / (N-1);
        trajectory.points[i].time = u * time;
        trajectory.points[i].positions.resize(joint_names.size());

        x = (1-u)*start_x + u*goal_x;
        q = cga::slerp(start_q, goal_q, u);
        ee_transform = cga::make_translation(x.e1, x.e2, x.e3) * q;
        if (!update_joint_positions()) {
            std::cerr << "Trajectory failed" << std::endl;
            return false;
        }

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

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        if (dim.dh_parameters[i].fixed_alpha) {
            columns[i].e12 = 1;
        } else {
            columns[i].e23 = std::cos(dim.dh_parameters[i].theta);
            columns[i].e31 = -std::sin(dim.dh_parameters[i].theta);
            columns[i].e1i = -dim.dh_parameters[i].d*std::sin(dim.dh_parameters[i].theta);
            columns[i].e2i = -dim.dh_parameters[i].d*std::cos(dim.dh_parameters[i].theta);
        }
        for (int j = i; j >= 0;  j--) {
            columns[i] = (transforms[j]*columns[i]*cga::reverse(transforms[j])).b;
        }
    }

    auto adjustment = cga::make_translation(-ee_p.e1, -ee_p.e2, -ee_p.e3);
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        columns[i] = (adjustment*columns[i]*cga::reverse(adjustment)).b;
    }

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        jacobian(0,i) = columns[i].e23;
        jacobian(1,i) = columns[i].e31;
        jacobian(2,i) = columns[i].e12;
        jacobian(3,i) = columns[i].e1i;
        jacobian(4,i) = columns[i].e2i;
        jacobian(5,i) = columns[i].e3i;
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
    cga::Rotor3 R_ee;
    R_ee.s = pose.orientation.w;
    R_ee.b.e23 = -pose.orientation.x;
    R_ee.b.e31 = -pose.orientation.y;
    R_ee.b.e12 = -pose.orientation.z;
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
