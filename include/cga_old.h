#ifndef CGA_H
#define CGA_H

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

namespace cga {

#define BINARY_OPS(Type) \
    Type operator*(const Type &x, double s) { \
        Type result(x); \
        result *= s; \
        return result; \
    } \
    Type operator*(double s, const Type &p) { \
        return p*s; \
    } \
    Type operator+(const Type &lhs, const Type &rhs) { \
        Type result(lhs); \
        result += rhs; \
        return result; \
    } \
    Type operator-(const Type &lhs, const Type &rhs) { \
        Type result(lhs); \
        result -= rhs; \
        return result; \
    }

struct Vector {
    double e1, e2, e3, no, ni;
    Vector& operator+=(const Vector &other) {
        e1 += other.e1;
        e2 += other.e2;
        e3 += other.e3;
        no += other.no;
        ni += other.ni;
        return *this;
    }
    Vector& operator-=(const Vector &other) {
        e1 -= other.e1;
        e2 -= other.e2;
        e3 -= other.e3;
        ni -= other.no;
        no -= other.ni;
        return *this;
    }
    Vector& operator*=(double s) {
        e1 *= s;
        e2 *= s;
        e3 *= s;
        no *= s;
        ni *= s;
        return *this;
    }
    Vector& operator/=(double s) {
        e1 /= s;
        e2 /= s;
        e3 /= s;
        no /= s;
        ni /= s;
        return *this;
    }
    Vector operator-()const {
        return {-e1, -e2, -e3, -no, -ni};
    }
};
BINARY_OPS(Vector)

struct Bivector {
    double e12, e23, e31;
    double e1no, e2no, e3no;
    double e1ni, e2ni, e3ni;
    double E;
    Bivector& operator+=(const Bivector &other) {
        e12 += other.e12;
        e23 += other.e23;
        e31 += other.e31;
        e1no += other.e1no;
        e2no += other.e2no;
        e3no += other.e3no;
        e1ni += other.e1ni;
        e2ni += other.e2ni;
        e3ni += other.e3ni;
        E += other.E;
        return *this;
    }
    Bivector& operator-=(const Bivector &other) {
        e12 -= other.e12;
        e23 -= other.e23;
        e31 -= other.e31;
        e1no -= other.e1no;
        e2no -= other.e2no;
        e3no -= other.e3no;
        e1ni -= other.e1ni;
        e2ni -= other.e2ni;
        e3ni -= other.e3ni;
        E -= other.E;
        return *this;
    }
    Bivector& operator*=(double s) {
        e12 *= s;
        e23 *= s;
        e31 *= s;
        e1no *= s;
        e2no *= s;
        e3no *= s;
        e1ni *= s;
        e2ni *= s;
        e3ni *= s;
        E *= s;
        return *this;
    }
    Bivector& operator/=(double s) {
        e12 /= s;
        e23 /= s;
        e31 /= s;
        e1no /= s;
        e2no /= s;
        e3no /= s;
        e1ni /= s;
        e2ni /= s;
        e3ni /= s;
        E /= s;
        return *this;
    }
    Bivector operator-()const {
        return {-e12, -e23, -e31, -e1no, -e2no, -e3no, -e1ni, -e2ni, -e3ni, -E};
    }
};
BINARY_OPS(Bivector);


struct Trivector {
    double e123;
    double e12o, e23o, e31o;
    double e12i, e23i, e31i;
    double e1oi, e2oi, e3oi;
    Trivector& operator+=(const Trivector &other) {
        e123 += other.e123;
        e12o += other.e12o;
        e23o += other.e23o;
        e31o += other.e31o;
        e12i += other.e12i;
        e23i += other.e23i;
        e31i += other.e31i;
        e1oi += other.e1oi;
        e2oi += other.e2oi;
        e3oi += other.e3oi;
        return *this;
    }
    Trivector& operator-=(const Trivector &other) {
        e123 -= other.e123;
        e12o -= other.e12o;
        e23o -= other.e23o;
        e31o -= other.e31o;
        e12i -= other.e12i;
        e23i -= other.e23i;
        e31i -= other.e31i;
        e1oi -= other.e1oi;
        e2oi -= other.e2oi;
        e3oi -= other.e3oi;
        return *this;
    }
    Trivector& operator*=(double s) {
        e123 *= s;
        e12o *= s;
        e23o *= s;
        e31o *= s;
        e12i *= s;
        e23i *= s;
        e31i *= s;
        e1oi *= s;
        e2oi *= s;
        e3oi *= s;
        return *this;
    }
    Trivector& operator/=(double s) {
        e123 /= s;
        e12o /= s;
        e23o /= s;
        e31o /= s;
        e12i /= s;
        e23i /= s;
        e31i /= s;
        e1oi /= s;
        e2oi /= s;
        e3oi /= s;
        return *this;
    }
    Trivector operator-()const {
        return {-e123, -e12o, -e23o, -e31o, -e12i, -e23i, -e31i, -e1oi, -e2oi, -e3oi};
    }
};
BINARY_OPS(Trivector)

inline double inner(const Vector &a, const Vector &b)
{
    double result = 0;
    result += a.e1*b.e1 + a.e2*b.e2 + a.e3*b.e3;
    result += - a.ni*b.no - a.no*b.ni;
    return result;
}

inline Bivector outer(const Vector &a, const Vector &b)
{
    Bivector result;

    result.e12 = a.e1*b.e2 - a.e2*b.e1;
    result.e23 = a.e2*b.e3 - a.e3*b.e2;
    result.e31 = a.e3*b.e1 - a.e1*b.e3;

    result.e1no = a.e1*b.no - a.no*b.e1;
    result.e2no = a.e2*b.no - a.no*b.e2;
    result.e3no = a.e3*b.no - a.no*b.e3;

    result.e1ni = a.e1*b.ni - a.ni*b.e1;
    result.e2ni = a.e2*b.ni - a.ni*b.e2;
    result.e3ni = a.e3*b.ni - a.ni*b.e3;

    result.E = a.no*b.ni - a.ni*b.no;

    return result;
}

inline double inner(const Bivector &a, const Bivector &b)
{
    double result;
    result += a.e12*b.e12 + a.e23*b.e23 + a.e31*b.e31;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Vector &v);
std::ostream &operator<<(std::ostream &os, const Bivector &v);

struct Rotor {
    double scalar;
    Bivector bivector;
    Rotor& operator+=(const Rotor &other) {
        scalar += other.scalar;
        bivector += other.bivector;
        return *this;
    }
    Rotor& operator-=(const Rotor &other) {
        scalar -= other.scalar;
        bivector -= other.bivector;
        return *this;
    }
    Rotor& operator*=(double s) {
        scalar *= s;
        bivector *= s;
        return *this;
    }
    Rotor& operator/=(double s) {
        scalar /= s;
        bivector /= s;
        return *this;
    }
};
BINARY_OPS(Rotor)

std::ostream &operator<<(std::ostream &os, const Rotor &r);

inline Rotor operator*(const Vector &a, const Vector &b)
{
    Rotor rotor;
    rotor.scalar = inner(a, b);
    rotor.bivector = outer(a, b);
    return rotor;
}

inline Rotor exp(const Bivector &bivector)
{
    Rotor result;
    double norm = std::sqrt(inner(bivector, bivector));
    return result;
}


} // namespace cga

#endif
