#include "cbot/delta.h"

#include <Eigen/Dense>

#define SQ(x) (x*x)

namespace cbot {

// ========== Delta::Impl class definition ==========

class Delta::Impl {
public:
    Impl(const Config &config);
    bool update_pose(const Joints &joints, Pose &pose);
    bool update_twist(const Joints &joints, Twist &twist);
    bool update_joint_positions(const Pose &pose, Joints &joints);
    bool update_joint_velocities(const Twist &twist, Joints &joints);
    bool update_dependent_joints(Joints &joints);

private:
    void update_inverse_jacobian(const Joints &joints_pos);

    Config config;
    Eigen::Vector3d n[3];
    Eigen::Vector3d n_perp[3];
    Eigen::Matrix3d n_R[3];

    Eigen::Vector3d a[3];
    Eigen::Vector3d y; // End effector position
    // For calculating jacobian
    Eigen::Matrix3d inverse_jacobian;
    Eigen::Matrix3d A[3];
    Eigen::Matrix<double, 2, 3> B[3];
    Eigen::Matrix<double, 3, 2> C[3];

    // flags
    bool position_valid; // a[3], y
    bool inverse_jacobian_valid; // inverse_jacobian
};

Delta::Impl::Impl(const Config &config): config(config) {

    auto angle_axis= Eigen::AngleAxisd();
    angle_axis.axis() = Eigen::Vector3d(0, 0, 1);
    for (int i = 0; i < 3; i++) {
        angle_axis.angle() = i*M_PI*2/3;
        n_R[i] = angle_axis.toRotationMatrix();
        n[i] = n_R[i].col(0);
        n_perp[i] = n_R[i].col(1);

        A[i] = -2*n[i]*n[i].transpose() + n_perp[i]*n_perp[i].transpose();
        A[i](2, 2) = 1;
        B[i] <<  0,          0,         1,
                -2*n[i](0), -2*n[i](1), 0;
        B[i] *= config.l_upper;
        C[i] << 2*n[i](0), 0,
                2*n[i](1), 0,
                0,         2;
        C[i] *= config.l_upper;
    }

    position_valid = false;
    inverse_jacobian_valid = false;
}


// ========= Delta::Impl kinematics methods =========

bool Delta::Impl::update_pose(const Joints &joints, Pose &pose)
{
    double theta_i;
    for (int i = 0; i < 3; i++) {
        theta_i = joints.at(config.theta[i]).position;
        a[i] = n[i] * (config.r_base + config.l_upper*std::cos(theta_i) - config.r_ee);
        a[i].z() = -config.l_upper * std::sin(theta_i);
    }

    // Form a circle of possible ee position from the second
    // and third two pseudo-elbow position
    auto centre = 0.5*(a[1] + a[2]);
    auto u1 = (a[1]-a[0]).cross(a[2]-a[0]);
    u1.normalize();
    auto u2 = u1.cross(a[2] - a[1]);
    u2.normalize();

    double a01_half_norm = (a[2] - a[1]).norm() / 2;
    double R = std::sqrt(SQ(config.l_lower) - SQ(a01_half_norm));
    double d = (centre - a[0]).norm();
    // Plus or minus
    double alpha = std::acos((SQ(config.l_lower) - SQ(R) - SQ(d)) / (-2*R*d));

    y = centre + R*u2*std::cos(alpha) - R*u1*std::sin(alpha);
    position_valid = true;

    pose.position.x = y.x();
    pose.position.y = y.y();
    pose.position.z = y.z();
    pose.orientation.w = 1/std::sqrt(2);
    pose.orientation.y = 1/std::sqrt(2);

    return true;
}

bool Delta::Impl::update_joint_positions( const Pose &pose, Joints &joints)
{
    // (Not using the y saved for FK and updating dependent joints)
    Eigen::Vector3d y;
    y.x() = pose.position.x;
    y.y() = pose.position.y;
    y.z() = -pose.position.z; // Use z positive downward

    Eigen::Vector3d yi;
    for (int i = 0; i < 3; i++) {
        // Rotate into frame where n[i] = x.
        yi = n_R[i].transpose() * y;
        // Change to displacement between base joint and
        // end effector joint
        yi.x() += config.r_ee - config.r_base;

        double k = (SQ(config.l_lower) - SQ(config.l_upper) - yi.squaredNorm()) / (-2*config.l_upper);

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

        joints[config.theta[i]].position =
            fabs(solution1) < fabs(solution2) ? solution1 : solution2;
    }
    return true;
}

bool Delta::Impl::update_twist(const Joints &joints, Twist &twist)
{
    if (!inverse_jacobian_valid) {
        update_inverse_jacobian(joints);
    }
    Eigen::Vector3d theta_vel;
    for (int i = 0; i < 3; i++) {
        theta_vel[i] = joints.at(config.theta[i]).velocity;
    }
    Eigen::Vector3d vel = inverse_jacobian.inverse() * theta_vel;

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
    if (!inverse_jacobian_valid) {
        update_inverse_jacobian(joints);
    }

    Eigen::Vector3d vel(twist.linear.x, twist.linear.y, twist.linear.z);
    Eigen::Vector3d theta_vel = inverse_jacobian * vel;

    for (int i = 0; i < 3; i++) {
        joints[config.theta[i]].velocity = theta_vel(i);
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
        lower_disp = y - a[i];

        theta_i = joints[config.theta[i]].position;
        gamma_i = std::atan2(
            -lower_disp.z(),
            -lower_disp.dot(n[i])
        );
        beta_i = std::asin(
            lower_disp.dot(n_perp[i]) / config.l_lower
        );
        alpha_i = M_PI - theta_i - gamma_i;

        joints[config.alpha[i]].position = alpha_i;
        joints[config.beta[i]].position = beta_i;
        joints[config.gamma[i]].position = gamma_i;
    }
}

void Delta::Impl::update_inverse_jacobian(const Joints &joints)
{
    if (!position_valid) {
        Pose pose; // Unused
        update_pose(joints, pose);
    }

    Eigen::Vector2d s[3];
    double theta_i, denom;
    for (int i = 0; i < 3; i++){
        theta_i = joints.at(config.theta[i]).position;
        s[i](0) = sin(theta_i);
        s[i](1) = cos(theta_i);

        denom = y.transpose()*C[i]*s[i];
        inverse_jacobian.block<1, 3>(i, 0) =
            (y.transpose()*A[i] + s[i].transpose()*B[i]) / denom;
    }
}


// ========== Pimpl stuff ==========

Delta::Delta(Config config): pimpl(new Impl(config)) {}
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

// Setters

// For now, only set member variables.
// However, have chosen to add getters/setters such that the implementation
// knows when certain things have changed, meaning some calculations need
// to be invalidated.
// eg: Changing pose or joint position invalidates the Jacobian

void Delta::set_pose(const Pose &pose) {
    this->pose = pose;
}
void Delta::set_twist(const Twist &twist) {
    this->twist = twist;
}
void Delta::set_joint_position(const std::string &name, double value) {
    if (joints.find(name) != joints.end() && !joints[name].dependent) {
        joints[name].position = value;
    }
}
void Delta::set_joint_velocity(const std::string &name, double value) {
    if (joints.find(name) != joints.end() && !joints[name].dependent) {
        joints[name].velocity = value;
    }
}

} // namespace cbot
