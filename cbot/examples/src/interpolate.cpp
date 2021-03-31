
#include <cmath>
#include <Eigen/Dense>
#include "cga/transform.h"

Eigen::Quaterniond angle_axis_q(double angle, const Eigen::Vector3d &n)
{
    Eigen::Quaterniond q;
    q.w() = std::cos(angle/2);
    q.x() = std::sin(angle/2)*n.x();
    q.y() = std::sin(angle/2)*n.y();
    q.z() = std::sin(angle/2)*n.z();
    return q;
}

cga::Rotor3 angle_axis_r(double angle, const Eigen::Vector3d &n)
{
    cga::Rotor3 R;
    R.s = std::cos(angle/2);
    R.b.e23 = -std::sin(angle/2)*n.x();
    R.b.e31 = -std::sin(angle/2)*n.y();
    R.b.e12 = -std::sin(angle/2)*n.z();
    return R;
}

int main()
{
    double theta1 = 0.5;
    Eigen::Vector3d n1(1, 2, 3);
    n1.normalize();

    double theta2 = 1.2;
    Eigen::Vector3d n2(-1, -2, 2);
    n2.normalize();

    cga::Rotor3 r1 = angle_axis_r(theta1, n1);
    cga::Rotor3 r2 = angle_axis_r(theta2, n2);

    double u = 0;
    while (u <= 1) {
        std::cout << "u = " << u << std::endl;
        cga::Rotor3 r = cga::slerp(r1, r2, u);
        std::cout << "w=" << r.s;
        std::cout << ", x=" << -r.b.e23;
        std::cout << ", y=" << -r.b.e31;
        std::cout << ", z=" << -r.b.e12;
        std::cout << std::endl;
        u += 0.1;
    }
    std::cout << "r1" << std::endl;
    std::cout << "w=" << r1.s;
    std::cout << ", x=" << -r1.b.e23;
    std::cout << ", y=" << -r1.b.e31;
    std::cout << ", z=" << -r1.b.e12 << std::endl;
    std::cout << "r2" << std::endl;
    std::cout << "w=" << r2.s;
    std::cout << ", x=" << -r2.b.e23;
    std::cout << ", y=" << -r2.b.e31;
    std::cout << ", z=" << -r2.b.e12 << std::endl;

    // Eigen::Quaterniond q = angle_axis_q(theta1, n1).slerp(u, angle_axis_q(theta2, n2));
    // std::cout << "w=" << q.w() << std::endl;
    // std::cout << "x=" << q.x() << ", y=" << q.y() << ", z=" << q.z() << std::endl;


    return 0;
}
