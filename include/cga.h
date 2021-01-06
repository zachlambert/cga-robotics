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
    double e1, e2, e3, eo, ei;
    Vector& operator+=(const Vector &other) {
        e1 += other.e1;
        e2 += other.e2;
        e3 += other.e3;
        eo += other.eo;
        ei += other.ei;
        return *this;
    }
    Vector& operator-=(const Vector &other) {
        e1 -= other.e1;
        e2 -= other.e2;
        e3 -= other.e3;
        ei -= other.eo;
        eo -= other.ei;
        return *this;
    }
    Vector& operator*=(double s) {
        e1 *= s;
        e2 *= s;
        e3 *= s;
        eo *= s;
        ei *= s;
        return *this;
    }
    Vector& operator/=(double s) {
        e1 /= s;
        e2 /= s;
        e3 /= s;
        eo /= s;
        ei /= s;
        return *this;
    }
    Vector operator-()const {
        return {-e1, -e2, -e3, -eo, -ei};
    }
};
BINARY_OPS(Vector)
const Vector& reverse(const Vector &v)
{
    return v;
}

struct Bivector {
    double e23, e31, e12;
    double e1o, e2o, e3o;
    double e1i, e2i, e3i;
    double eoi;
    Bivector& operator+=(const Bivector &other) {
        e23 += other.e23;
        e31 += other.e31;
        e12 += other.e12;
        e1o += other.e1o;
        e2o += other.e2o;
        e3o += other.e3o;
        e1i += other.e1i;
        e2i += other.e2i;
        e3i += other.e3i;
        eoi += other.eoi;
        return *this;
    }
    Bivector& operator-=(const Bivector &other) {
        e12 -= other.e12;
        e23 -= other.e23;
        e31 -= other.e31;
        e1o -= other.e1o;
        e2o -= other.e2o;
        e3o -= other.e3o;
        e1i -= other.e1i;
        e2i -= other.e2i;
        e3i -= other.e3i;
        eoi -= other.eoi;
        return *this;
    }
    Bivector& operator*=(double s) {
        e12 *= s;
        e23 *= s;
        e31 *= s;
        e1o *= s;
        e2o *= s;
        e3o *= s;
        e1i *= s;
        e2i *= s;
        e3i *= s;
        eoi *= s;
        return *this;
    }
    Bivector& operator/=(double s) {
        e12 /= s;
        e23 /= s;
        e31 /= s;
        e1o /= s;
        e2o /= s;
        e3o /= s;
        e1i /= s;
        e2i /= s;
        e3i /= s;
        eoi /= s;
        return *this;
    }
    Bivector operator-()const {
        return {-e12, -e23, -e31, -e1o, -e2o, -e3o, -e1i, -e2i, -e3i, -eoi};
    }
};
BINARY_OPS(Bivector);
Bivector reverse(const Bivector &b)
{
    return -b;
}

struct Trivector {
    double e123;
    double e23o, e31o, e12o;
    double e23i, e31i, e12i;
    double e1oi, e2oi, e3oi;
    Trivector& operator+=(const Trivector &other) {
        e123 += other.e123;
        e23o += other.e23o;
        e31o += other.e31o;
        e12o += other.e12o;
        e23i += other.e23i;
        e31i += other.e31i;
        e12i += other.e12i;
        e1oi += other.e1oi;
        e2oi += other.e2oi;
        e3oi += other.e3oi;
        return *this;
    }
    Trivector& operator-=(const Trivector &other) {
        e123 -= other.e123;
        e23o -= other.e23o;
        e31o -= other.e31o;
        e12o -= other.e12o;
        e23i -= other.e23i;
        e31i -= other.e31i;
        e12i -= other.e12i;
        e1oi -= other.e1oi;
        e2oi -= other.e2oi;
        e3oi -= other.e3oi;
        return *this;
    }
    Trivector& operator*=(double s) {
        e123 *= s;
        e23o *= s;
        e31o *= s;
        e12o *= s;
        e23i *= s;
        e31i *= s;
        e12i *= s;
        e1oi *= s;
        e2oi *= s;
        e3oi *= s;
        return *this;
    }
    Trivector& operator/=(double s) {
        e123 /= s;
        e23o /= s;
        e31o /= s;
        e12o /= s;
        e23i /= s;
        e31i /= s;
        e12i /= s;
        e1oi /= s;
        e2oi /= s;
        e3oi /= s;
        return *this;
    }
    Trivector operator-()const {
        return {-e123, -e23o, -e31o, -e12o, -e23i, -e31i, -e12i, -e1oi, -e2oi, -e3oi};
    }
};
BINARY_OPS(Trivector)
Trivector reverse(const Trivector &t) {
    return -t;
}

struct Quadvector{
    double e123o, e123i, e23oi, e31oi, e12oi;
    Quadvector& operator+=(const Quadvector &other) {
        e123o += other.e123o;
        e123i += other.e123i;
        e23oi += other.e31oi;
        e23oi += other.e23oi;
        e12oi += other.e12oi;
        return *this;
    }
    Quadvector& operator-=(const Quadvector &other) {
        e123o -= other.e123o;
        e123i -= other.e123i;
        e23oi -= other.e31oi;
        e23oi -= other.e23oi;
        e12oi -= other.e12oi;
        return *this;
    }
    Quadvector& operator*=(double s) {
        e123o *= s;
        e123i *= s;
        e23oi *= s;
        e31oi *= s;
        e12oi *= s;
        return *this;
    }
    Quadvector& operator/=(double s) {
        e123o /= s;
        e123i /= s;
        e23oi /= s;
        e31oi /= s;
        e12oi /= s;
        return *this;
    }
    Quadvector operator-()const {
        return {-e123o, -e123i, -e23oi, -e31oi, -e12oi};
    }
};
BINARY_OPS(Quadvector)
const Quadvector& reverse(const Quadvector &q)
{
    return q;
}

struct Pseudoscalar {
    double I5;
    Pseudoscalar& operator+=(const Pseudoscalar &other) {
        I5 += other.I5;
        return *this;
    }
    Pseudoscalar& operator-=(const Pseudoscalar &other) {
        I5 -= other.I5;
        return *this;
    }
    Pseudoscalar& operator*=(double s) {
        I5 *= s;
        return *this;
    }
    Pseudoscalar& operator/=(double s) {
        I5 /= s;
        return *this;
    }
    Pseudoscalar operator-()const {
        return {-I5};
    }
};
BINARY_OPS(Pseudoscalar)
const Pseudoscalar& reverse(const Pseudoscalar &p)
{
    return p;
}


// Compound structs

struct Rotor {
    double s;
    Bivector b;
    Rotor& operator+=(const Rotor &other) {
        s += other.s;
        b += other.b;
        return *this;
    }
    Rotor& operator-=(const Rotor &other) {
        s -= other.s;
        b -= other.b;
        return *this;
    }
    Rotor& operator*=(double other_s) {
        s *= other_s;
        b *= other_s;
        return *this;
    }
    Rotor& operator/=(double other_s) {
        s /= other_s;
        b /= other_s;
        return *this;
    }
    Rotor operator-()const {
        return {-s, -b};
    }
};
BINARY_OPS(Rotor)
Rotor reverse(const Rotor &rotor) {
    return {rotor.s, reverse(rotor.b)};
}

struct Versor {
    double s;
    Bivector b;
    Quadvector q;
    Versor& operator+=(const Versor &other) {
        s += other.s;
        b += other.b;
        q += other.q;
        return *this;
    }
    Versor& operator-=(const Versor &other) {
        s -= other.s;
        b -= other.b;
        q -= other.q;
        return *this;
    }
    Versor& operator*=(double other_s) {
        s *= other_s;
        b *= other_s;
        q *= other_s;
        return *this;
    }
    Versor& operator/=(double other_s) {
        s /= other_s;
        b /= other_s;
        q /= other_s;
        return *this;
    }
    Versor operator-()const {
        return {-s, -b, -q};
    }
};
BINARY_OPS(Versor)
Versor reverse(const Versor &versor) {
    return {versor.s, reverse(versor.b), reverse(versor.q)};
}

struct Multivector {
    double s;
    Vector v;
    Bivector b;
    Trivector t;
    Quadvector q;
    Pseudoscalar p;

    Multivector& operator+=(const Multivector &other) {
        s += other.s;
        b += other.b;
        t += other.t;
        q += other.q;
        p += other.p;
        return *this;
    }
    Multivector& operator-=(const Multivector &other) {
        s -= other.s;
        v -= other.v;
        b -= other.b;
        t -= other.t;
        q -= other.q;
        p -= other.p;
        return *this;
    }
    Multivector& operator*=(double other_s) {
        s *= other_s;
        v *= other_s;
        b *= other_s;
        t *= other_s;
        q *= other_s;
        p *= other_s;
        return *this;
    }
    Multivector& operator/=(double other_s) {
        s /= other_s;
        v /= other_s;
        b /= other_s;
        t /= other_s;
        q /= other_s;
        p /= other_s;
        return *this;
    }
    Multivector operator-()const {
        return {-s, -v, -b, -t, -q, -p};
    }
};
Multivector reverse(const Multivector &mv) {
    return {mv.s, reverse(mv.v), reverse(mv.b), reverse(mv.t), reverse(mv.q), reverse(mv.p) };
}

// Vector x Vector

inline double inner(const Vector &a, const Vector &b)
{
    double result = 0;
    result += a.e1*b.e1 + a.e2*b.e2 + a.e3*b.e3;
    result += - a.ei*b.eo - a.eo*b.ei;
    return result;
}
inline Bivector outer(const Vector &a, const Vector &b)
{
    Bivector result;

    result.e12 = a.e1*b.e2 - a.e2*b.e1;
    result.e23 = a.e2*b.e3 - a.e3*b.e2;
    result.e31 = a.e3*b.e1 - a.e1*b.e3;

    result.e1o = a.e1*b.eo - a.eo*b.e1;
    result.e2o = a.e2*b.eo - a.eo*b.e2;
    result.e3o = a.e3*b.eo - a.eo*b.e3;

    result.e1i = a.e1*b.ei - a.ei*b.e1;
    result.e2i = a.e2*b.ei - a.ei*b.e2;
    result.e3i = a.e3*b.ei - a.ei*b.e3;

    result.eoi = a.eo*b.ei - a.ei*b.eo;

    return result;
}
inline Rotor operator*(const Vector &a, const Vector &b)
{
    Rotor result;
    result.s = inner(a, b);
    result.b = outer(a, b);
    return result;
}


// Vector x Bivector

inline Vector inner(const Vector &a, const Bivector &b)
{
    Vector result;

    result.e1 = a.e3*b.e31 - a.e2*b.e12 + a.eo*b.e1i - a.ei*b.e1o;
    result.e2 = a.e1*b.e12 - a.e3*b.e23 + a.eo*b.e2i - a.ei*b.e2o;
    result.e3 = a.e2*b.e23 - a.e1*b.e31 + a.eo*b.e3i - a.ei*b.e3o;

    result.eo = a.e1*b.e1o + a.e2*b.e2o + a.e3*b.e3o;
    result.ei = a.e1*b.e1i + a.e2*b.e2i + a.e3*b.e3i;

    return result;
}
inline Vector inner(const Bivector &a, const Vector &b) { return inner(b, a); }

inline Trivector outer(const Vector &a, const Bivector &b)
{
    Trivector result;

    result.e123 = a.e1*b.e23 + a.e2*b.e31 + a.e3*b.e12;

    result.e23o = a.e2*b.e3o - a.e3*b.e2o + a.eo*b.e23;
    result.e31o = a.e3*b.e1o - a.e1*b.e3o + a.eo*b.e31;
    result.e12o = a.e1*b.e2o - a.e2*b.e1o + a.eo*b.e12;

    result.e23i = a.e2*b.e3i - a.e3*b.e2i + a.ei*b.e23;
    result.e31i = a.e3*b.e1i - a.e1*b.e3i + a.ei*b.e31;
    result.e12i = a.e1*b.e2i - a.e2*b.e1i + a.ei*b.e12;

    result.e1oi = a.e1*b.eoi - a.eo*b.e1i + a.ei*b.e1o;
    result.e2oi = a.e2*b.eoi - a.eo*b.e2i + a.ei*b.e2o;
    result.e3oi = a.e3*b.eoi - a.eo*b.e3i + a.ei*b.e3o;

    return result;
}
inline Trivector outer(const Bivector &a, const Vector &b) { return outer(b, a); }


// Vector x Trivector

inline Multivector operator*(const Vector &a, const Bivector &b)
{
    Multivector result;
    result.v = inner(a, b);
    result.t = outer(a, b);
    return result;
}
inline Multivector operator*(const Bivector &a, const Vector &b) { return a*b; }

inline double inner(const Bivector &a, const Bivector &b)
{
    double result;
    result += a.e12*b.e12 + a.e23*b.e23 + a.e31*b.e31;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Vector &v);
std::ostream &operator<<(std::ostream &os, const Bivector &v);

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
    double eorm = std::sqrt(inner(bivector, bivector));
    return result;
}


} // namespace cga

#endif
