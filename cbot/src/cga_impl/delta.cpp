#include "cbot/delta.h"

#include "cga/cga.h"
#include "cga/geometry.h"
#include "cga/transform.h"

#define SQ(x) (x*x)

namespace cbot {
namespace cga_impl {


// ========== Delta::Impl class definition ==========

class Delta::Impl {
public:
    Impl(const Config &config);
    bool fk_pose(const Joints &joints_pos, JointsDep *joints_dep_pos, Pose &pose);
    bool fk_twist(const Joints &joints_pos, const Joints &joints_vel, Twist &twist);
    bool ik_pose( const Pose &pose, Joints &joints_pos);
    bool ik_twist( const Twist &twist, const Joints &joints_pos, Joints &joints_vel);

private:

    Config config;
    cga::Vector3 n[3];
    cga::Vector3 n_perp[3];
};

Delta::Impl::Impl(const Config &config): config(config) {
    for (int i = 0; i < 3; i++) {
        n[i].e1 = std::cos(i*M_PI*2/3);
        n[i].e2 = std::sin(i*M_PI*2/3);
        n_perp[i].e1 = -n[i].e2;
        n_perp[i].e2 = n[i].e1;
    }
}


// ========= Delta::Impl kinematics methods =========

bool Delta::Impl::fk_pose(
    const Joints &joints_pos,
    JointsDep *joints_dep_pos,
    Pose &pose)
{
    // Location of each pseudo-elbow point, and corresponding spheres
    cga::Vector3 a[3];
    cga::Vector A_sphere[3];
    for (int i = 0; i < 3; i++) {
        a[i] = n[i] * (
            config.r_base + config.l_upper * std::cos(joints_pos.theta[i]) - config.r_ee
        );
        a[i].e3 = -config.l_upper*std::sin(joints_pos.theta[i]);
        A_sphere[i] = cga::make_sphere(a[i], config.l_lower);
    }

    auto result = cga::intersect(A_sphere);
    if (!result.valid) return false;

    cga::Vector3 y =
        (result.point1.e3 < result.point2.e3 ? result.point1 : result.point2);

    // Displacement between the end effector position and pseudo-elbow
    // position, from which the configuration of the parallel linkage can
    // be determined with simple trigonometry
    if (joints_dep_pos) {
        cga::Vector3 lower_disp;
        for (int i = 0; i < 3; i++) {
            lower_disp = y - a[i];
            joints_dep_pos->gamma[i] = std::atan2(
                -inner(lower_disp, cga::Vector3(0, 0, 1)),
                -inner(lower_disp, n[i])
            );
            joints_dep_pos->beta[i] = std::asin(
                inner(lower_disp, n_perp[i]) / config.l_lower
            );
            joints_dep_pos->alpha[i] = M_PI - joints_pos.theta[i] - joints_dep_pos->gamma[i];
        }
    }

    // Read end effector position from y
    pose.position.x = y.e1;
    pose.position.y = y.e2;
    pose.position.z = y.e3;

    // Always point downward
    pose.orientation.w = 1/std::sqrt(2);
    pose.orientation.y = 1/std::sqrt(2);

    return true;
}

bool Delta::Impl::ik_pose(
    const Pose &pose,
    Joints &joints_pos)
{
    cga::Vector3 y;
    y.e1 = pose.position.x;
    y.e2 = pose.position.y;
    y.e3 = pose.position.z;

    cga::Vector Sigma_y = cga::make_sphere(y, config.l_lower);
    cga::Vector3 s, a, upper_disp;
    cga::Bivector C;
    cga::PointPair result;
    for (int i = 0; i < 3; i++) {
        s = n[i]*(config.r_base - config.r_ee);
        C = outer(
            // Intersect plane of upper link with ..
            dual(outer(s, cga::e3)),
            // .. sphere about joint, of radius = upper length
            cga::make_sphere(s, config.l_upper)
        );
        result = cga::intersect(C, Sigma_y);
        if (!result.valid) return false;
        a = (inner(result.point1, n[i]) > inner(result.point2, n[i]) ?
            result.point1 : result.point2);
        upper_disp = a - s;
        joints_pos.theta[i] = std::asin(-upper_disp.e3/config.l_upper);
    }
    return true;
}

bool Delta::Impl::fk_twist(
    const Joints &joints_pos,
    const Joints &joints_vel,
    Twist &twist)
{
    // JointsDep joints_dep;
    // Pose pose;
    // fk_pose(joints_pos, joints_dep, pose);


    return true;
}

bool Delta::Impl::ik_twist(
    const Twist &twist,
    const Joints &joints_pos,
    Joints &joints_vel)
{
    return true;
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
