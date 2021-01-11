#include "cbot/delta.h"

namespace cbot {
namespace cga_impl {

Delta::~Delta() = default;
Delta::Delta(Delta&&) = default;
Delta& Delta::operator=(Delta&&) = default;

class Delta::Impl {
public:
    double joint_pos[3];
};

Delta::Delta(Config config): DeltaBase(config), pimpl(new Impl())
{

}

bool Delta::fk_pose(
    const std::vector<std::string> &joint_names,
    std::vector<double> &joint_positions,
    Pose &pose)
{
    return true;
}

bool Delta::fk_twist(
    const std::vector<std::string> &joint_names,
    const std::vector<double> &joint_positions,
    const std::vector<double> &joint_velocities,
    Twist &twist)
{
    return true;
}

bool Delta::ik_pose(
    const Pose &pose,
    const std::vector<std::string> &joint_names,
    std::vector<double> &joints_positions)
{
    return true;
}

bool Delta::ik_twist(
    const Twist &twist,
    const std::vector<std::string> &joint_names,
    const std::vector<double> &joints_positions,
    std::vector<double> &joints_velocities)
{
    return true;
}

bool Delta::force_control(
    const Twist &twist,
    const std::vector<std::string> &joint_names,
    const std::vector<double> &joint_positions,
    std::vector<double> &joint_torques)
{
    return true;
}

} // namespace cga_impl
} // namespace cbot
