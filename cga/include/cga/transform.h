#ifndef CGA_TRANSFORM_H
#define CGA_TRANSFORM_H

#include <iostream>
#include "cga/cga.h"
#include "cga/constants.h"

namespace cga {

inline Bivector3 make_axis(double x, double y, double z)
{
    return cga::Bivector3(x, y, z);
}

inline Rotor3 make_rotation(double theta, Bivector3 axis)
{
    return Rotor3(std::cos(theta/2), -std::sin(theta/2)*axis);
}

inline Rotor make_translation(double x, double y, double z)
{
    Rotor result;
    result.s = 1;
    result.b.e1i = -0.5*x;
    result.b.e2i = -0.5*y;
    result.b.e3i = -0.5*z;
    return result;
}

inline Vector3 transform_vector(const Vector3 &x, const Rotor3 &R)
{
    return (R*x*reverse(R)).v;
}
inline Vector transform_vector(const Vector &x, const Rotor3 &R)
{
    return (R*x*reverse(R)).v;
}
inline Vector transform_vector(const Vector &x, const Rotor &R)
{
    return (R*x*reverse(R)).v;
}
inline Vector transform_vector(const Vector &x, const Versor &R)
{
    return (R*x*reverse(R)).v;
}

inline void extract_components(const Versor &V, Rotor3 &R, Vector3 &p)
{
    cga::Vector P = (V*eo*reverse(V)).v;
    p = cga::Vector3(P.e1, P.e2, P.e3) / P.eo;
    auto T = cga::make_translation(p.e1, p.e2, p.e3);
    R = cga::Rotor3(cga::Rotor(cga::reverse(T)*V));
}

inline cga::Rotor3 slerp(const Rotor3 &R0, const Rotor3 &R1, double u)
{
    cga::Rotor3 delta = cga::reverse(R0)*R1;
    double half_angle = std::acos(delta.s);
    cga::Bivector3 axis = -delta.b / std::sin(half_angle);

    if (half_angle > M_PI) half_angle -= 2*M_PI;
    cga::Rotor3 delta_R_u(
        std::cos(u*half_angle),
        std::sin(-u*half_angle)*axis);

    return R0*delta_R_u;
}

} // namespace cga

#endif
