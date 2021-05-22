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
    bool is_valid(constraint_t constraint);

    // Implementation specific constants
    // None

    // Implementation specific state and validity flags
    Eigen::Isometry3d ee_transform;
    std::vector<Eigen::Isometry3d> transforms;
    std::vector<Eigen::Matrix<double, 6, 6>> velocity_transforms;
    Eigen::Matrix<double, 6, Eigen::Dynamic> J;
    Eigen::Matrix<double, 6, Eigen::Dynamic> J_star;
    bool transforms_valid;
    bool jacobian_valid;

    // Implementation specific function
    void update_jacobian();
    Eigen::VectorXd penalty_function();
};


Serial::Impl::Impl(const Dimensions &dim, const JointNames &joint_names):
    dim(dim), joint_names(joint_names)
{
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        joints.emplace(joint_names[i], Joint());
        transforms.push_back(Eigen::Isometry3d());
        velocity_transforms.push_back(Eigen::Matrix<double, 6, 6>());
        velocity_transforms.back().setZero();
    }

    transforms_valid = false;
    jacobian_valid = false;

    J = Eigen::Matrix<double, 6, Eigen::Dynamic>(6, joint_names.size());
    J_star = Eigen::Matrix<double, 6, Eigen::Dynamic>(6, joint_names.size());
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

Eigen::Isometry3d get_dh_transform(const Serial::DHParameter &dh)
{
    return Eigen::Translation3d(dh.a, 0, 0)
        * Eigen::AngleAxisd(dh.alpha, Eigen::Vector3d::UnitX())
        * Eigen::Translation3d(0, 0, dh.d)
        * Eigen::AngleAxisd(dh.theta, Eigen::Vector3d::UnitZ());
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

Eigen::Matrix<double, 6, 1> get_twist_coordinates(const Eigen::Isometry3d &T)
{
    Eigen::Matrix<double, 6, 1> twist;
    Eigen::MatrixXd approx = T.matrix();
    Eigen::MatrixXd identity(4,4);
    approx -= identity;
    twist(0) = -approx(2,1);
    twist(1) = approx(2,0);
    twist(2) = -approx(1,0);
    twist.block<3,1>(3,0) = approx.block<3,1>(0,3);
    return twist;
    // For more accurate twist. Don't think it's necessary for IK though.
    // The above uses a first order approximation of ln(T)
    /*
    twist.setZero();
    double theta = std::acos(0.5*(T(0,0) + T(1,1) + T(2,2)-1));
    if (std::fabs(theta)>1e-6) {
        Eigen::Vector3d axis;
        axis(0) = T(2,1) - T(1,2);
        axis(1) = T(0,2) - T(2,0);
        axis(2) = T(1,0) - T(0,1);
        axis /= (2*std::sin(theta));
        Eigen::Vector3d p = T.translation();
        Eigen::Vector3d v_pll_theta = (p.dot(axis))*axis;
        Eigen::Vector3d p_perp = p - v_pll_theta;
        Eigen::Vector3d v_perp = 0.5*(
            (std::sin(theta)/(1-std::cos(theta)))*p_perp
            - axis.cross(p_perp)
        );
        twist.block<3,1>(0,0) = axis*theta;
        twist.block<3,1>(3,0) = v_pll_theta + v_perp*theta;
        std::cout << "Perp: " << v_perp*theta << std::endl;
        std::cout << "Pll: " << v_pll_theta << std::endl;
    } else {
        twist.block<3,1>(3,0) = T.translation();
    }
    return twist;
    */
}

bool twist_is_zero(const Eigen::Matrix<double, 6, 1> &twist_vec)
{
    // |delta pos| < 1e-6
    if (twist_vec.block<3,1>(3,0).norm() > 1e-6) return false;
    // |delta theta| < 1e-3
    if (twist_vec.block<3,1>(0,0).norm() > 1e-3) return false;
    return true;
}

void get_euler_angles(const Eigen::Matrix3d &R, double &yaw, double &pitch, double &roll)
{
    pitch = std::atan2(-R(2,0), std::hypot(R(0,0), R(1,0)));
    yaw = std::atan2(R(1,0), R(0,0));
    roll = std::atan2(R(2,1), R(2,2));
}

Eigen::VectorXd Serial::Impl::penalty_function()
{
    Eigen::VectorXd delta_q(joint_names.size());
    delta_q.setZero();

    double lim = M_PI/2;
    int i = 4;

    double pos = joints[joint_names[i]].position;
    if (pos > lim) {
        delta_q(i) -= std::pow(pos-lim, 2);
    } else if (pos < -lim) {
        delta_q(i) += std::pow(pos+lim, 2);
    }

    return delta_q;
}

bool Serial::Impl::update_joint_positions()
{
    cbot::Joints initial_joints = joints;

    auto goal_transform = ee_transform;

    // Parameterise pose difference
    Eigen::Matrix<double, 6, 1> twist;

    Eigen::VectorXd delta_q(joint_names.size());
    Eigen::JacobiSVD<Eigen::Matrix<double, 6, Eigen::Dynamic>> j_svd;
    j_svd.setThreshold(0);

    Eigen::DiagonalMatrix<double, Eigen::Dynamic> W1(joint_names.size());
    W1.diagonal() << 1, 1, 1, 1, 1, 1;
    W1 = 1*W1;

    Eigen::DiagonalMatrix<double, Eigen::Dynamic> W2(joint_names.size());
    W2.diagonal() << 1, 1, 1, 1, 1, 1;
    W2 = 4*W2;

    int max_iter = 1e3;
    int i = 0;
    while (i < max_iter) {
        // Update pose with current joints and find pose difference
        update_pose();
        twist = get_twist_coordinates(ee_transform.inverse()*goal_transform);

        Eigen::VectorXd penalty = penalty_function();
        // Stop if pose_dif after updating joint positions is close to zero
        if (twist_is_zero(twist)) break;

        // Update jacobian, and find jacobian pseudoinverse
        update_jacobian();
        j_svd.compute(J, Eigen::ComputeFullU | Eigen::ComputeFullV);
        delta_q = j_svd.solve(twist);

        delta_q = W1*delta_q + W2*penalty;

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
        std::cout << "INVERSE KINEMATICS FAILED" << std::endl;
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

    constexpr std::size_t N = 50;

    Eigen::Vector3d p0 = ee_transform.translation();
    Eigen::Quaterniond q0(ee_transform.rotation());

    Eigen::Vector3d p1(
        goal.position.x,
        goal.position.y,
        goal.position.z);
    Eigen::Quaterniond q1(
        goal.orientation.w,
        goal.orientation.x,
        goal.orientation.y,
        goal.orientation.z);

    Eigen::Vector3d delta_p = p1 - p0;

    // Get angle and axis for computing angular velocity
    Eigen::Quaterniond delta_q = q0.conjugate()*q1;
    Eigen::AngleAxisd delta_R_aa(delta_q.toRotationMatrix());
    Eigen::Vector3d axis = delta_R_aa.axis();
    double delta_theta = delta_R_aa.angle(); Eigen::Vector3d p; Eigen::Quaterniond q;

    trajectory.points.resize(N);
    trajectory.names = joint_names;
    double tau, u;
    Eigen::Vector3d v, omega, q_dot;

    double max_joint_speed = 0;
    double T1 = 1.5*delta_p.norm() / constraints.max_linear_speed;
    double T2 = 1.5*delta_R_aa.angle() / constraints.max_angular_speed;
    double T = (T1 > T2 ? T1 : T2);

    if (T < 1e-6) return false; // Start and end pose close together

    for (std::size_t i = 0; i < N; i++) {
        tau = ((double)i)/(N-1);
        u = 3*std::pow(tau, 2) - 2*std::pow(tau, 3);
        p = p0 + u*delta_p;
        q = q0.slerp(u, q1);
        ee_transform = Eigen::Translation3d(p)*q;

        // IK
        if (!update_joint_positions()) return false;

        v = (6/T)*tau*(1-tau)*delta_p;
        omega = (6/T)*tau*(1-tau)*axis*delta_theta;
        twist.linear.x = v(0);
        twist.linear.y = v(1);
        twist.linear.z = v(2);
        twist.angular.x = omega(0);
        twist.angular.y = omega(1);
        twist.angular.z = omega(2);
        update_joint_velocities();

        // Copy joints into trajectory and find max joint velocity
        trajectory.points[i].positions.resize(joint_names.size());
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
        trajectory.points[i].time = T*((double)i)/(N-1);
    }
    std::cout << "TIME = " << T << std::endl;
    if (T > 2) return false;

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
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        Eigen::Vector3d pos = transforms[i].translation();
        Eigen::Matrix3d rotation = transforms[i].rotation();
        velocity_transforms[i].block<3,3>(0,0) = rotation.transpose();
        velocity_transforms[i].block<3,3>(3,3) = rotation.transpose();
        Eigen::Matrix3d skew_matrix;
        skew_matrix << 0, -pos.z(), pos.y(),
                       pos.z(), 0, -pos.x(),
                       -pos.y(), pos.x(), 0;
        velocity_transforms[i].block<3,3>(3,0) = -rotation.transpose()*skew_matrix;
    }

    for (std::size_t i = 0; i < joint_names.size(); i++) {
        if (dim.dh_parameters[i].fixed_alpha) {
            J.block<6,1>(0,i) << 0, 0, 1, 0, 0, 0;
        } else {
            J.block<6,1>(0,i) <<
                std::cos(dim.dh_parameters[i].theta),
                -std::sin(dim.dh_parameters[i].theta),
                0,
                -dim.dh_parameters[i].d*std::sin(dim.dh_parameters[i].theta),
                -dim.dh_parameters[i].d*std::cos(dim.dh_parameters[i].theta),
                0;
        }
        for (int j = i+1; j < joint_names.size(); j++) {
            J.block<6,1>(0,i) = velocity_transforms[j]*J.block<6,1>(0,i);
        }
        J_star.block<3,1>(0,i) = J.block<3,1>(0,i);
        J_star.block<3,1>(3,i) = ee_transform.rotation()*J.block<3,1>(3,i);
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
    pimpl->ee_transform =
        Eigen::Translation3d(
            pose.position.x,
            pose.position.y,
            pose.position.z)
        * Eigen::Quaterniond(
            pose.orientation.w,
            pose.orientation.x,
            pose.orientation.y,
            pose.orientation.z);
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
