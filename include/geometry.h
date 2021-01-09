#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "cga.h"

namespace cga {

inline Vector make_point(const Vector3 &x)
{
    Vector result = x;
    result.eo = 1;
    result.ei = 0.5*norm2(x);
    return result;
}

inline Vector make_plane(const Vector3 &normal, double dist)
{
    Vector result = normal / norm(normal); // Ensure normalised
    result.ei = dist;
    return result;
}

inline Vector make_sphere(const Vector3& origin, double radius)
{
    Vector result = origin;
    result.ei = -0.5*radius*radius;
    return result;
}

inline Vector make_imaginary_sphere(const Vector3& origin, double radius)
{
    Vector result = origin;
    result.ei = 0.5*radius*radius;
    return result;
}

inline Vector3 extract_point(const Vector &x)
{
    return Vector3(x) / x.eo;
}

} // namespace cga

#endif
