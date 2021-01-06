#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "cga.h"

namespace cga {

inline Bivector3 make_axis(double x, double y, double z)
{
    Bivector3 result;
    result.e23 = x;
    result.e31 = y;
    result.e12 = z;
    return result;
}

inline Rotor3 make_rotation(double theta, Bivector3 axis)
{
    Rotor3 result;
    result.s = std::cos(theta/2);
    result.b = std::sin(theta/2) * axis;
    return result;
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

inline Vector3 rotate(const Vector3& x, const Rotor3 &R)
{
    auto result = R*x*reverse(R);
    return {result.v.e1, result.v.e2, result.v.e3};
}

} // namespace cga

#endif
