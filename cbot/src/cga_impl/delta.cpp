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
    // Location of each pseudo-elbow point
    cga::Vector3 a[3];
    // Conformal vector reprsenting a sphere about each pseudo-elbow point
    cga::Vector A_sphere[3];
    for (int i = 0; i < 3; i++) {
        a[i] = pimpl->n[i] * (
            config.r_base + config.l_upper * std::cos(joints_pos.theta[i]) - config.r_ee
        );
        std::cout << "a["<<i<<"] = " << a[i] << std::endl;
        a[i].e3 = -config.l_upper*std::sin(joints_pos.theta[i]);
        std::cout << "a["<<i<<"] = " << a[i] << std::endl;
        A_sphere[i] = cga::make_sphere(a[i], config.l_lower);
    }

    cga::Bivector T = cga::Pseudoscalar(1)
        *outer(A_sphere[0], outer(A_sphere[1], A_sphere[2]));

    if ((T*T).s < 0) return false;

    cga::Versor P;
    P.s = 1;
    P.b = T/std::sqrt(((T*T).s));

    cga::Vector Y = -(reverse(P) * inner(T, cga::Vector(0, 0, 0, 0, 1)) * P).v;

    cga::Vector3 y = describe(Y).point.position;
    pose.position.x = y.e1;
    pose.position.y = y.e2;
    pose.position.z = y.e3;

    std::cout << "Y = " << Y << std::endl;
    std::cout <<" y = " << y << std::endl;

    cga::Vector3 lower_disp;
    for (int i = 0; i < 3; i++) {
        lower_disp = y - a[i];
        joints_dep_pos.alpha[i] = std::atan2(
            -inner(lower_disp, cga::Vector3(0, 0, 1)),
            -inner(lower_disp, pimpl->n[i])
        );
        joints_dep_pos.beta[i] = std::atan2(
            inner(lower_disp, pimpl->n_perp[i]),
            inner(lower_disp,
                -std::cos(joints_dep_pos.alpha[i])*pimpl->n[i]
                -std::sin(joints_dep_pos.alpha[i])*cga::Vector3(0, 0, 1))
        );
    }

    for (int i = 0; i < 3; i++) {
        joints_dep_pos.gamma[i] = joints_dep_pos.alpha[i];
        joints_dep_pos.alpha[i] = M_PI - joints_pos.theta[i] - joints_dep_pos.alpha[i];
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

} // namespace cga_impl
} // namespace cbot
