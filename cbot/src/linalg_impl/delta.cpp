#include "cbot/delta.h"

#include <Eigen/Dense>

#define SQ(x) (x*x)

namespace cbot {
namespace linalg_impl {


// ========== Delta::Impl class definition ==========

class Delta::Impl {
public:
    Impl(const Config &config);
    bool fk_pose(const Joints &joints_pos, JointsDep *joints_dep_pos, Pose &pose);
    bool fk_twist(const Joints &joints_pos, const Joints &joints_vel, Twist &twist);
    bool ik_pose( const Pose &pose, Joints &joints_pos);
    bool ik_twist( const Twist &twist, const Joints &joints_pos, Joints &joints_vel);

private:
    Eigen::MatrixXd get_inverse_jacobian(const Joints &joints_pos);

    Config config;
    Eigen::Vector3d n[3];
    Eigen::Vector3d n_perp[3];
    Eigen::Matrix3d n_R[3];
    
    // For calculating jacobian
    Eigen::Matrix3d A[3];
    Eigen::Matrix<double, 2, 3> B[3];
    Eigen::Matrix<double, 3, 2> C[3];
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
}


// ========= Delta::Impl kinematics methods =========

bool Delta::Impl::fk_pose(
    const Joints &joints_pos,
    JointsDep *joints_dep_pos,
    Pose &pose)
{
    Eigen::Vector3d a[3];
    for (int i = 0; i < 3; i++) {
        a[i] = n[i] * (config.r_base + config.l_upper*std::cos(joints_pos.theta[i]) - config.r_ee);
        a[i].z() = -config.l_upper * std::sin(joints_pos.theta[i]);
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

    auto y = centre + R*u2*std::cos(alpha) - R*u1*std::sin(alpha);

    if (joints_dep_pos) {
        Eigen::Vector3d lower_disp;
        for (int i = 0; i < 3; i++) {
            lower_disp = y - a[i];

            lower_disp = y - a[i];
            joints_dep_pos->gamma[i] = std::atan2(
                -lower_disp.z(),
                -lower_disp.dot(n[i])
            );
            joints_dep_pos->beta[i] = std::asin(
                lower_disp.dot(n_perp[i]) / config.l_lower
            );
            joints_dep_pos->alpha[i] = M_PI - joints_pos.theta[i] - joints_dep_pos->gamma[i];
        }
    }

    pose.position.x = y.x();
    pose.position.y = y.y();
    pose.position.z = y.z();
    pose.orientation.w = 1/std::sqrt(2);
    pose.orientation.y = 1/std::sqrt(2);

    return true;
}

bool Delta::Impl::ik_pose(
    const Pose &pose,
    Joints &joints_pos)
{
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

        joints_pos.theta[i] = fabs(solution1) < fabs(solution2) ? solution1 : solution2;
    }
    return true;
}

bool Delta::Impl::fk_twist(
    const Joints &joints_pos,
    const Joints &joints_vel,
    Twist &twist)
{
    Eigen::Matrix3d jacobian = get_inverse_jacobian(joints_pos).inverse();
    Eigen::Vector3d theta_vel;
    for (int i = 0; i < 3; i++) theta_vel[i] = joints_vel.theta[i];
    Eigen::Vector3d vel = jacobian * theta_vel;

    twist.linear.x = vel[0];
    twist.linear.y = vel[1];
    twist.linear.z = vel[2];
    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 0;

    return true;
}

bool Delta::Impl::ik_twist(
    const Twist &twist,
    const Joints &joints_pos,
    Joints &joints_vel)
{
    Eigen::Matrix3d inverse_jacobian = get_inverse_jacobian(joints_pos);

    Eigen::Vector3d vel(twist.linear.x, twist.linear.y, twist.linear.z);
    Eigen::Vector3d theta_vel = inverse_jacobian * vel;

    for (int i = 0; i < 3; i++) joints_vel.theta[i] = theta_vel(i);

    return true;
}


Eigen::MatrixXd Delta::Impl::get_inverse_jacobian(const Joints &joints_pos)
{
    Pose pose;
    fk_pose(joints_pos, 0, pose);
    Eigen::Vector3d y(pose.position.x, pose.position.y, pose.position.z);

    Eigen::Matrix3d inverse_jacobian;
    Eigen::Vector2d s[3];
    double denom;
    for (int i = 0; i < 3; i++){
        s[i](0) = sin(joints_pos.theta[i]);
        s[i](1) = cos(joints_pos.theta[i]);

        denom = y.transpose()*C[i]*s[i];
        inverse_jacobian.block<1, 3>(i, 0) =
            (y.transpose()*A[i] + s[i].transpose()*B[i]) / denom;
    }

    return inverse_jacobian;
}


// ========== Pimpl stuff ==========

Delta::Delta(Config config): pimpl(new Impl(config)) {}
Delta::~Delta() = default;
Delta::Delta(Delta&&) = default;
Delta& Delta::operator=(Delta&&) = default;

bool Delta::fk_pose(const Joints &joints_pos, JointsDep *joints_dep_pos, Pose &pose) {
    return pimpl->fk_pose(joints_pos, joints_dep_pos, pose);
}
bool Delta::ik_pose(const Pose &pose, Joints &joints_pos) {
    return pimpl->ik_pose(pose, joints_pos);
}
bool Delta::fk_twist(const Joints &joints_pos, const Joints &joints_vel, Twist &twist) {
    return pimpl->fk_twist(joints_pos, joints_vel, twist);
}
bool Delta::ik_twist(const Twist &twist, const Joints &joints_pos, Joints &joints_vel) {
    return pimpl->ik_twist(twist, joints_pos, joints_vel);
}


} // namespace linalg_impl
} // namespace cbot
