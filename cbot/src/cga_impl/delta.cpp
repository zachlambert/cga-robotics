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
};

Delta::Delta(Config config): DeltaBase(config), pimpl(new Impl())
{
    for (int i = 0; i < 3; i++) {
        pimpl->n[i].e1 = std::cos(i*M_PI*2/3);
        pimpl->n[i].e2 = std::sin(i*M_PI*2/3);
    }
}

bool Delta::fk_pose(
    const Joints &joints_pos,
    JointsDep &joints_dep_pos,
    Pose &pose)
{
    // cga::Vector A_sphere[3];
    // for (int i = 0; i < 3; i++) {
    //     cga::Vector3 a = pimpl->n[i] * (
    //         config.r_base + config.l_upper * std::cos(joints_pos.theta[i])
    //     );
    //     a.e3 = -config.l_upper*std::sin(joints_pos.theta[i]);

    //     A_sphere[i] = cga::make_sphere(a, config.l_lower);
    // }

    // Put alpha, beta, gamma into joint vectors
    return true;
}

bool Delta::fk_twist(
    const Joints &joints_pos,
    const Joints &joints_vel,
    Twist &twist)
{
    return true;
}

} // namespace cga_impl
} // namespace cbot
