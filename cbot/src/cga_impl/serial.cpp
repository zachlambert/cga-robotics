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
    Eigen::Matrix<double, 6, Eigen::Dynamic> J, J_star;
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

    J = Eigen::Matrix<double, 6, Eigen::Dynamic>(6, joint_names.size());
    J_star = Eigen::Matrix<double, 6, Eigen::Dynamic>(6, joint_names.size());
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

Eigen::Matrix<double, 6, 1> get_twist_coordinates(const cga::Versor &T)
{
    cga::Versor one;
    one.s = 1;
    cga::Versor approx = 2*(one - T);

    Eigen::Matrix<double, 6, 1> twist;
    twist(0) = approx.b.e23;
    twist(1) = approx.b.e31;
    twist(2) = approx.b.e12;
    twist(3) = approx.b.e1i;
    twist(4) = approx.b.e2i;
    twist(5) = approx.b.e3i;
    return twist;
}

bool twist_is_zero(const Eigen::Matrix<double, 6, 1> &twist_vec)
{
    // |Position dif| < 1e-6
    if (twist_vec.block<3,1>(3,0).norm() > 1e-6) return false;
    // |delta theta| < 1e-6
    if (twist_vec.block<3,1>(0,0).norm() > 1e-6) return false;
    return true;
}

bool Serial::Impl::update_joint_positions()
{
    cbot::Joints initial_joints = joints;

    auto goal_transform = ee_transform;
    Eigen::Matrix<double, 6, 1> twist;

    Eigen::VectorXd delta_q(joint_names.size());
    Eigen::JacobiSVD<Eigen::Matrix<double, 6, Eigen::Dynamic>> j_svd;
    j_svd.setThreshold(1e-3);

    int max_iter = 1e3;
    int i = 0;
    while (i < max_iter) {
        // Update pose with current joints and find pose difference
        update_pose();
        twist = get_twist_coordinates(cga::reverse(ee_transform)*goal_transform);

        // Stop if pose_dif after updating joint positions is close to zero
        if (twist_is_zero(twist)) break;

        // Update jacobian, and find jacobian pseudoinverse
        update_jacobian();
        j_svd.compute(J, Eigen::ComputeFullU | Eigen::ComputeFullV);
        delta_q = j_svd.solve(twist);

        for (std::size_t j = 0; j < joint_names.size(); j++) {
            double pos = joints[joint_names[j]].position;
            pos += delta_q(j);
            while (pos < -M_PI) pos += 2*M_PI;
            while (pos > M_PI) pos -= 2*M_PI;
            joints[joint_names[j]].position = pos;
        }
        i++;
    }
    if (i >= max_iter) {
        std::cerr << "INVERSE KINEMATICS FAILED" << std::endl;
        joints = initial_joints;
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
    Eigen::Matrix<double, 6, 1> vel = J_star * theta_vel;

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

    Eigen::VectorXd twist_vec(6);
    twist_vec << twist.angular.x, twist.angular.y, twist.angular.z,
           twist.linear.x, twist.linear.y, twist.linear.z;

    Eigen::JacobiSVD<Eigen::Matrix<double, 6, Eigen::Dynamic>> j_svd;
    j_svd.setThreshold(1e-3);
    j_svd.compute(J_star, Eigen::ComputeFullU | Eigen::ComputeFullV);
    Eigen::VectorXd q_dot = j_svd.solve(twist_vec);

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        joints[joint_names[i]].velocity = q_dot(i);
    }

    return true;
}


// Trajectory functions

bool Serial::Impl::calculate_trajectory(const Pose &goal)
{
    if (!transforms_valid) update_pose();

    cga::Vector3 p0;
    cga::Rotor3 R0;
    cga::extract_components(ee_transform, R0, p0);

    cga::Vector3 p1(
        goal.position.x,
        goal.position.y,
        goal.position.z);
    cga::Rotor3 R1(
        goal.orientation.w,
        cga::Bivector3(
        -goal.orientation.x,
        -goal.orientation.y,
        -goal.orientation.z));

    cga::Vector3 delta_p = p1 - p0;
    cga::Rotor3 delta_R = R0*cga::reverse(R1);

    double delta_theta = 2*std::acos(delta_R.s);
    cga::Bivector3 axis = delta_R.b / std::sin(delta_theta/2);

    trajectory.names = joint_names;
    double tau, u;
    cga::Vector3 v;
    cga::Bivector3 omega;

    double max_joint_speed = 0;
    double T1 = 1.5*cga::norm(delta_p) / constraints.max_linear_speed;
    double T2 = 1.5*delta_theta / constraints.max_angular_speed;
    double T = (T1 > T2 ? T1 : T2);

    static constexpr double delta_t = 1e-2;
    std::size_t N = (T / delta_t) + 1;
    std::cout << "N = " << N << std::endl;
    trajectory.points.resize(N);

    cga::Vector3 p;
    cga::Rotor3 R;
    for (std::size_t i = 0; i < N; i++) {
        tau = ((double)(i+1))/N;
        u = 3*std::pow(tau, 2) - 2*std::pow(tau, 3);
        p = p0 + u*delta_p;
        R = cga::slerp(R0, R1, u);
        ee_transform = cga::make_translation(p.e1, p.e2, p.e3)*R;

        // IK
        if (!update_joint_positions()) return false;

        v = (6/T)*tau*(1-tau)*delta_p;
        omega = (6/T)*tau*(1-tau)*axis*delta_theta;
        twist.linear.x = v.e1;
        twist.linear.y = v.e2;
        twist.linear.z = v.e3;
        twist.angular.x = omega.e23;
        twist.angular.y = omega.e31;
        twist.angular.z = omega.e12;
        update_joint_velocities();

        // Copy joints into trajectory and find max joint velocity
        std::cout << "A" << std::endl;
        trajectory.points[i].positions.resize(joint_names.size());
        std::cout << "B" << std::endl;
        for (std::size_t j = 0; j < joint_names.size(); j++) {
            trajectory.points[i].positions[j] = joints.at(joint_names[j]).position;
            double joint_speed = std::abs(joints.at(joint_names[j]).velocity);

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
    std::cout << "RETURNING" << std::endl;
    return true;
}

// Check state validity

bool Serial::Impl::is_valid(constraint_t constraint)
{
    if (constraint != nullptr && !constraint(joints)) return false;

    if (!jacobian_valid) update_jacobian();
    Eigen::JacobiSVD<Eigen::Matrix<double, 6, Eigen::Dynamic>> j_svd;
    j_svd.compute(J, Eigen::ComputeFullU | Eigen::ComputeFullV);
    if (j_svd.singularValues().minCoeff() < 0.1) return false;

    return true;
}

// Implementation specific functions

void Serial::Impl::update_jacobian()
{
    if (!transforms_valid) update_pose();

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
        for (int j = i+1; j < joint_names.size();  j++) {
            columns[i] = (cga::reverse(transforms[j])*columns[i]*transforms[j]).b;
        }
    }

    cga::Rotor3 ee_R;
    cga::Vector3 ee_p;
    cga::extract_components(ee_transform, ee_R, ee_p);

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        J(0,i) = columns[i].e23;
        J(1,i) = columns[i].e31;
        J(2,i) = columns[i].e12;
        J(3,i) = columns[i].e1i;
        J(4,i) = columns[i].e2i;
        J(5,i) = columns[i].e3i;
        J_star.block<3,1>(0,i) = J.block<3,1>(0,i);
        columns[i] = (ee_R*columns[i]*cga::reverse(ee_R)).b;
        J_star(3,i) = columns[i].e1i;
        J_star(4,i) = columns[i].e2i;
        J_star(5,i) = columns[i].e3i;
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
