#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "gen/cga.h"
#include <iostream>

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

inline Vector make_sphere(const Vector3& position, double radius)
{
    Vector result = position;
    result.ei = -0.5*radius*radius;
    return result;
}

inline Vector make_imaginary_sphere(const Vector3& position, double radius)
{
    Vector result = position;
    result.ei = 0.5*radius*radius;
    return result;
}

struct GeometryResult {
    enum Type {
        Point,
        Plane,
        Sphere
    };
    Type type;
    union {
        struct {
            Vector3 position;
        } point;
        struct {
            Vector3 normal;
            double dist;
        } plane;
        struct {
            Vector3 position;
            double radius;
            bool real;
        } sphere;
    };
    GeometryResult(){}
};

GeometryResult describe(const Vector& x)
{
    GeometryResult result;
    if (x.eo == 0) {
        result.type = GeometryResult::Plane;
        result.plane.normal = Vector3(x);
        result.plane.dist = x.ei;
    } else if (norm2(x)==0) {
        result.type = GeometryResult::Point;
        result.point.position = Vector3(x/x.eo);
    } else {
        result.type = GeometryResult::Sphere;
        double radius2 = norm2(x);
        result.sphere.real = (radius2 > 0);
        result.sphere.position = Vector3(x/x.eo);
        result.sphere.radius = std::sqrt(std::fabs(radius2));
    }
    return result;
}

inline std::ostream& operator<<(std::ostream &outs, const GeometryResult &geometry)
{
    switch(geometry.type) {
        case GeometryResult::Point:
            std::cout << "Point: (";
            std::cout << geometry.point.position.e1 << ", ";
            std::cout << geometry.point.position.e2 << ", ";
            std::cout << geometry.point.position.e3 << ")";
            break;
        case GeometryResult::Plane:
            std::cout << "Plane: d=" << geometry.plane.dist;
            std::cout << ", pos=(" << geometry.plane.normal.e1 << ", ";
            std::cout << geometry.plane.normal.e2 << ", ";
            std::cout << geometry.plane.normal.e3 << ")";
            break;
        case GeometryResult::Sphere:
            std::cout << "Sphere: r=" << geometry.sphere.radius;
            std::cout << ", pos=(" << geometry.sphere.position.e1 << ", ";
            std::cout << geometry.sphere.position.e2 << ", ";
            std::cout << geometry.sphere.position.e3 << ")";
            std::cout << (geometry.sphere.real ? "" : " [imaginary]");
            break;
    }
    return outs;
}

Quadvector dual(const Vector &x)
{
    return cga::Pseudoscalar(1) * x;
}

Trivector dual(const Bivector &x)
{
    return cga::Pseudoscalar(1) * x;
}

Bivector dual(const Trivector &x)
{
    return cga::Pseudoscalar(1) * x;
}

Vector dual(const Quadvector &x)
{
    return cga::Pseudoscalar(1) * x;
}

} // namespace cga

#endif
