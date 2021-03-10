#ifndef CGA_GEOMETRY_H
#define CGA_GEOMETRY_H

#include "cga/cga.h"
#include "cga/transform.h"
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
    result.eo = 1;
    result.ei = 0.5*(norm2(position) - radius*radius);
    return result;
}

inline Vector make_imaginary_sphere(const Vector3& position, double radius)
{
    Vector result = position;
    result.eo = 1;
    result.ei = 0.5*(norm2(position) + radius*radius);
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

inline GeometryResult describe(const Vector& x)
{
    GeometryResult result;
    if (std::fabs(x.eo) < 1e-12) { // x.eo = 0
        result.type = GeometryResult::Plane;
        result.plane.normal = Vector3(x);
        result.plane.dist = x.ei;
    } else if (norm2(x)<1e-12) { // norm = 0
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

inline Bivector3 dual(const Vector3 &x)
{
    return cga::I3 * x;
}

inline Vector3 dual(const Bivector3 &x)
{
    return cga::I3 * x;
}

inline Quadvector dual(const Vector &x)
{
    return cga::I5 * x;
}

inline Trivector dual(const Bivector &x)
{
    return cga::I5 * x;
}

inline Bivector dual(const Trivector &x)
{
    return cga::I5 * x;
}

inline Vector dual(const Quadvector &x)
{
    return cga::I5 * x;
}

struct PointPair {
    bool valid;
    Vector3 point1;
    Vector3 point2;
};

inline PointPair intersect(const Vector spheres[3])
{
    PointPair intersection;
    cga::Bivector T = dual(outer(spheres[0], outer(spheres[1], spheres[2])));

    if (inner(T, T) < 0) {
        intersection.valid = false;
    } else {
        intersection.valid = true;
        cga::Rotor P(1, T/std::sqrt(inner(T, T)));
        cga::Vector Y = transform_vector(inner(T, cga::ei), P);
        intersection.point1 = describe(Y).point.position;
        Y = transform_vector(inner(T, cga::ei), reverse(P));
        intersection.point2 = describe(Y).point.position;
    }
    return intersection;
}

inline PointPair intersect(const Vector &sphere, const Bivector &circle)
{
    PointPair intersection;
    cga::Bivector T = dual(outer(sphere, circle));
    if (inner(T, T) < 0) {
        intersection.valid = false;
    } else {
        intersection.valid = true;
        cga::Rotor P(1, -T/std::sqrt(inner(T, T)));
        cga::Vector Y = -transform_vector(inner(T, cga::ei), P);
        intersection.point1 = describe(Y).point.position;
        Y = transform_vector(inner(T, cga::ei), reverse(P));
        intersection.point2 = describe(Y).point.position;
    }
    return intersection;
}
inline PointPair intersect(const Bivector &circle, const Vector &sphere)
{
    return intersect(sphere, circle);
}

} // namespace cga

#endif
