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
    const std::vector<std::string> &joint_names,
    std::vector<double> &joint_positions,
    Pose &pose)
{
    // Relevant angles
    double theta[3], alpha[3], beta[3], gamma[3];

    // Get theta positions
    for (int i = 0; i < 3; i++) {
        for (std::size_t j = 0; j < joint_names.size(); j++) {
            if (config.joints.theta_names[i] == joint_names[j]) {
                theta[i] = joint_positions[j];
                break;
            }
        }
    }

    cga::Vector A_sphere[3];
    for (int i = 0; i < 3; i++) {
        cga::Vector3 a = pimpl->n[i] * (
            config.dim.base_radius + config.dim.upper_length*std::cos(theta[i]));
        a.e3 = -config.dim.upper_length*std::sin(theta[i]);
        A_sphere[i] = cga::make_sphere(a, config.dim.lower_length);
    }

    // Put alpha, beta, gamma into joint vectors
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
