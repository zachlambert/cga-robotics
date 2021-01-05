#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "cga.h"
#include "objects.h"

namespace cga {

struct Rotation: Rotor {
    // Constraints:
    // - Only has components: scalar, e12, e23, e31
};

struct Translation: Rotor {
    // Constraints:
    // - Scalar = 1
    // - Only other components are e1i, e2i, e3i
};

struct RigidBody: Rotor {
    // May make mor
};

inline Bivector make_axis(double x, double y, double z)
{
    Bivector result;
    result.e23 = x;
    result.e31 = y;
    result.e12 = z;
    return result;
}

inline Rotation make_rotation(double theta, Bivector axis)
{
    Rotation result;
    result.scalar = std::cos(theta/2);
    result.bivector = std::sin(theta/2) * axis;
    return result;
}

inline Translation make_translation(double x, double y, double z)
{
    Translation result;
    result.scalar = 1;
    result.bivector.e1ni = -0.5*x;
    result.bivector.e2ni = -0.5*y;
    result.bivector.e3ni = -0.5*z;
    return result;
}

} // namespace cga

#endif
