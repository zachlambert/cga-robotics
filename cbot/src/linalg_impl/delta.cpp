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
    Eigen::Matrix3d A;
    Eigen::Vector3d b, x;
    for (int i = 0; i < 3; i++) {
        A.row(i) = pimpl->n[i] * (
            config.r_base
            + config.l_lower*std::cos(joints_pos.theta[i])
        );
        A.row(i).z() =
            -config.l_upper*std::sin(joints_pos.theta[i]);

        b[i] = (config.l_lower*config.l_lower)
            - config.r_ee * (
                config.r_base + config.l_upper*std::cos(joints_pos.theta[i]));
    }
    x = A.inverse() * b;

    return true;
}

bool Delta::fk_twist(
    const Joints &joints_pos,
    const Joints &joints_vel,
    Twist &twist)
{
    return true;
}

} // namespace linalg_impl
} // namespace cbot
