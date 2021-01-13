#include "cbot/delta.h"

#include "cga/cga.h"
#include "cga/geometry.h"
#include "cga/transform.h"

namespace cbot {
namespace cga_impl {

Delta::~Delta() = default;
Delta::Delta(Delta&&) = default;
Delta& Delta::operator=(Delta&&) = default;

class Delta::Impl {
public:
    cga::Vector3 n[3];
    cga::Vector3 n_perp[3];
};

Delta::Delta(Config config): DeltaBase(config), pimpl(new Impl())
{
    for (int i = 0; i < 3; i++) {
        pimpl->n[i].e1 = std::cos(i*M_PI*2/3);
        pimpl->n[i].e2 = std::sin(i*M_PI*2/3);
        pimpl->n_perp[i].e1 = -pimpl->n[i].e2;
        pimpl->n_perp[i].e2 = pimpl->n[i].e1;
    }
}

bool Delta::fk_pose(
    const Joints &joints_pos,
    JointsDep &joints_dep_pos,
    Pose &pose)
{
    // Location of each pseudo-elbow point, and corresponding spheres
    cga::Vector3 a[3];
    cga::Vector A_sphere[3];
    for (int i = 0; i < 3; i++) {
        a[i] = pimpl->n[i] * (
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
    cga::Vector3 lower_disp;
    for (int i = 0; i < 3; i++) {
        lower_disp = y - a[i];
        joints_dep_pos.gamma[i] = std::atan2(
            -inner(lower_disp, cga::Vector3(0, 0, 1)),
            -inner(lower_disp, pimpl->n[i])
        );
        joints_dep_pos.beta[i] = std::asin(
            inner(lower_disp, pimpl->n_perp[i]) / config.l_lower
        );
        joints_dep_pos.alpha[i] = M_PI - joints_pos.theta[i] - joints_dep_pos.gamma[i];
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

bool Delta::ik_pose(
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
        s = pimpl->n[i]*(config.r_base - config.r_ee);
        C = outer(
            // Intersect plane of upper link with ..
            dual(outer(s, cga::e3)),
            // .. sphere about joint, of radius = upper length
            cga::make_sphere(s, config.l_upper)
        );
        result = cga::intersect(C, Sigma_y);
        if (!result.valid) return false;
        a = (inner(result.point1, pimpl->n[i]) > inner(result.point2, pimpl->n[i]) ?
            result.point1 : result.point2);
        upper_disp = a - s;
        joints_pos.theta[i] = std::asin(-upper_disp.e3/config.l_upper);
    }
    return true;
}

bool Delta::fk_twist(
    const Joints &joints_pos,
    const Joints &joints_vel,
    Twist &twist)
{
    return true;
}

bool Delta::ik_twist(
    const Twist &twist,
    const Joints &joints_pos,
    Joints &joints_vel)
{
    return true;
}

} // namespace cga_impl
} // namespace cbot
