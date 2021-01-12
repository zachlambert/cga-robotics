#include "cbot/delta.h"

#include <Eigen/Dense>

namespace cbot {
namespace linalg_impl {

Delta::~Delta() = default;
Delta::Delta(Delta&&) = default;
Delta& Delta::operator=(Delta&&) = default;

class Delta::Impl {
public:
    Eigen::Vector3d n[3];
};

Delta::Delta(Config config): DeltaBase(config), pimpl(new Impl())
{
    for (int i = 0; i < 3; i++) {
        pimpl->n[i].x() = std::cos(i*M_PI*2/3);
        pimpl->n[i].y() = std::sin(i*M_PI*2/3);
    }
}

bool Delta::fk_pose(
    const Joints &joints_pos,
    JointsDep &joints_dep_pos,
    Pose &pose)
{
    return true;
}

bool Delta::fk_twist(
    const Joints &joints_pos,
    const Joints &joints_vel,
    Twist &twist)
{
    return true;
}

bool Delta::ik_pose(
    const Pose &pose,
    Joints &joints_pos)
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

} // namespace linalg_impl
} // namespace cbot
