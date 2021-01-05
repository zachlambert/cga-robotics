#ifndef OBJECTS_H
#define OBJECTS_H

#include "cga.h"

namespace cga {

struct Point: public Vector {
    // Constraints:
    // - eo = 0
    // - ei = 0
};

inline Point make_point(double x, double y, double z) {
    Point result;
    result.e1 = x;
    result.e2 = y;
    result.e3 = z;
    return result;
}

struct CPoint: public Vector {
    // Constraints:
    // - ei = 0.5*(e1^2 + e2^2 + e3^2)
};

inline CPoint up(const Point &p)
{
    double sq_norm = p.e1*p.e1 + p.e2*p.e2 + p.e3*p.e3;
    CPoint result;
    result.e1 = p.e1;
    result.e2 = p.e2;
    result.e3 = p.e3;
    result.no = 1;
    result.ni = 0.5*sq_norm;
    return result;
}

inline Point down(const CPoint &cp)
{
    Point result;
    result.e1 = cp.e1 / cp.no;
    result.e2 = cp.e2 / cp.no;
    result.e3 = cp.e3 / cp.no;
    return result;
}

struct Orientation: public Rotor {
    // Constraints:
    // - Has structure cos(theta/2) - B sin(theta/2)
    //   where B is a bivector with components e12, e23, e31 only
};

} // namespace cga

#endif
