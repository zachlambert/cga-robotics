#ifndef CGA_H
#define CGA_H

#include <cmath>
#include <iostream>

namespace cga {

struct Pseudoscalar3;
struct Pseudoscalar;
struct Vector3;
struct Bivector3;
struct Rotor3;
struct Vector;
struct Quadvector;
struct Bivector;
struct Trivector;
struct Rotor;
struct Versor;
struct Multivector;

struct Pseudoscalar3 {
    double I3;

    Pseudoscalar3(): I3(0) {}
    Pseudoscalar3(double I3): I3(I3) {}
    Pseudoscalar3& operator+=(const Pseudoscalar3 &other) {
        I3 += other.I3;
        return *this;
    }
    Pseudoscalar3& operator-=(const Pseudoscalar3 &other) {
        I3 -= other.I3;
        return *this;
    }
    Pseudoscalar3& operator*=(double s) {
        I3 *= s;
        return *this;
    }
    Pseudoscalar3& operator/=(double s) {
        I3 /= s;
        return *this;
    }
    Pseudoscalar3 operator-()const {
        return {-I3};
    };
};

inline Pseudoscalar3 operator+(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs){
    Pseudoscalar3 result(lhs);
    result += rhs;
    return result;
}
inline Pseudoscalar3 operator-(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs){
    Pseudoscalar3 result(lhs);
    result -= rhs;
    return result;
}
inline Pseudoscalar3 operator*(const Pseudoscalar3 &lhs, double rhs){
    Pseudoscalar3 result(lhs);
    result *= rhs;
    return result;
}
inline Pseudoscalar3 operator*(double lhs, const Pseudoscalar3 &rhs){
    return rhs*lhs;
}
inline Pseudoscalar3 operator/(const Pseudoscalar3 &lhs, double rhs){
    Pseudoscalar3 result(lhs);
    result /= rhs;
    return result;
}


struct Pseudoscalar {
    double I5;

    Pseudoscalar(): I5(0) {}
    Pseudoscalar(double I5): I5(I5) {}
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
    };
};

inline Pseudoscalar operator+(const Pseudoscalar &lhs, const Pseudoscalar &rhs){
    Pseudoscalar result(lhs);
    result += rhs;
    return result;
}
inline Pseudoscalar operator-(const Pseudoscalar &lhs, const Pseudoscalar &rhs){
    Pseudoscalar result(lhs);
    result -= rhs;
    return result;
}
inline Pseudoscalar operator*(const Pseudoscalar &lhs, double rhs){
    Pseudoscalar result(lhs);
    result *= rhs;
    return result;
}
inline Pseudoscalar operator*(double lhs, const Pseudoscalar &rhs){
    return rhs*lhs;
}
inline Pseudoscalar operator/(const Pseudoscalar &lhs, double rhs){
    Pseudoscalar result(lhs);
    result /= rhs;
    return result;
}


struct Vector3 {
    double e1;
    double e2;
    double e3;

    Vector3(): e1(0), e2(0), e3(0) {}
    Vector3(double e1, double e2, double e3): e1(e1), e2(e2), e3(e3) {}
    Vector3& operator+=(const Vector3 &other) {
        e1 += other.e1;
        e2 += other.e2;
        e3 += other.e3;
        return *this;
    }
    Vector3& operator-=(const Vector3 &other) {
        e1 -= other.e1;
        e2 -= other.e2;
        e3 -= other.e3;
        return *this;
    }
    Vector3& operator*=(double s) {
        e1 *= s;
        e2 *= s;
        e3 *= s;
        return *this;
    }
    Vector3& operator/=(double s) {
        e1 /= s;
        e2 /= s;
        e3 /= s;
        return *this;
    }
    Vector3 operator-()const {
        return {-e1, -e2, -e3};
    };
};

inline Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs){
    Vector3 result(lhs);
    result += rhs;
    return result;
}
inline Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs){
    Vector3 result(lhs);
    result -= rhs;
    return result;
}
inline Vector3 operator*(const Vector3 &lhs, double rhs){
    Vector3 result(lhs);
    result *= rhs;
    return result;
}
inline Vector3 operator*(double lhs, const Vector3 &rhs){
    return rhs*lhs;
}
inline Vector3 operator/(const Vector3 &lhs, double rhs){
    Vector3 result(lhs);
    result /= rhs;
    return result;
}


struct Bivector3 {
    double e23;
    double e31;
    double e12;

    Bivector3(): e23(0), e31(0), e12(0) {}
    Bivector3(double e23, double e31, double e12): e23(e23), e31(e31), e12(e12) {}
    Bivector3& operator+=(const Bivector3 &other) {
        e23 += other.e23;
        e31 += other.e31;
        e12 += other.e12;
        return *this;
    }
    Bivector3& operator-=(const Bivector3 &other) {
        e23 -= other.e23;
        e31 -= other.e31;
        e12 -= other.e12;
        return *this;
    }
    Bivector3& operator*=(double s) {
        e23 *= s;
        e31 *= s;
        e12 *= s;
        return *this;
    }
    Bivector3& operator/=(double s) {
        e23 /= s;
        e31 /= s;
        e12 /= s;
        return *this;
    }
    Bivector3 operator-()const {
        return {-e23, -e31, -e12};
    };
};

inline Bivector3 operator+(const Bivector3 &lhs, const Bivector3 &rhs){
    Bivector3 result(lhs);
    result += rhs;
    return result;
}
inline Bivector3 operator-(const Bivector3 &lhs, const Bivector3 &rhs){
    Bivector3 result(lhs);
    result -= rhs;
    return result;
}
inline Bivector3 operator*(const Bivector3 &lhs, double rhs){
    Bivector3 result(lhs);
    result *= rhs;
    return result;
}
inline Bivector3 operator*(double lhs, const Bivector3 &rhs){
    return rhs*lhs;
}
inline Bivector3 operator/(const Bivector3 &lhs, double rhs){
    Bivector3 result(lhs);
    result /= rhs;
    return result;
}


struct Rotor3 {
    double s;
    Bivector3 b;

    Rotor3(): s(0), b() {}
    Rotor3(double s, const Bivector3 &b): s(s), b(b) {}
    Rotor3(const Bivector3 &b): s(0), b(b) {}
    Rotor3& operator+=(const Rotor3 &other) {
        s += other.s;
        b += other.b;
        return *this;
    }
    Rotor3& operator-=(const Rotor3 &other) {
        s -= other.s;
        b -= other.b;
        return *this;
    }
    Rotor3& operator*=(double s) {
        s *= s;
        b *= s;
        return *this;
    }
    Rotor3& operator/=(double s) {
        s /= s;
        b /= s;
        return *this;
    }
    Rotor3 operator-()const {
        return {-s, -b};
    };
};

inline Rotor3 operator+(const Rotor3 &lhs, const Rotor3 &rhs){
    Rotor3 result(lhs);
    result += rhs;
    return result;
}
inline Rotor3 operator-(const Rotor3 &lhs, const Rotor3 &rhs){
    Rotor3 result(lhs);
    result -= rhs;
    return result;
}
inline Rotor3 operator*(const Rotor3 &lhs, double rhs){
    Rotor3 result(lhs);
    result *= rhs;
    return result;
}
inline Rotor3 operator*(double lhs, const Rotor3 &rhs){
    return rhs*lhs;
}
inline Rotor3 operator/(const Rotor3 &lhs, double rhs){
    Rotor3 result(lhs);
    result /= rhs;
    return result;
}


struct Vector {
    double e1;
    double e2;
    double e3;
    double eo;
    double ei;

    Vector(): e1(0), e2(0), e3(0), eo(0), ei(0) {}
    Vector(double e1, double e2, double e3, double eo, double ei): e1(e1), e2(e2), e3(e3), eo(eo), ei(ei) {}
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
        eo -= other.eo;
        ei -= other.ei;
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
    };
};

inline Vector operator+(const Vector &lhs, const Vector &rhs){
    Vector result(lhs);
    result += rhs;
    return result;
}
inline Vector operator-(const Vector &lhs, const Vector &rhs){
    Vector result(lhs);
    result -= rhs;
    return result;
}
inline Vector operator*(const Vector &lhs, double rhs){
    Vector result(lhs);
    result *= rhs;
    return result;
}
inline Vector operator*(double lhs, const Vector &rhs){
    return rhs*lhs;
}
inline Vector operator/(const Vector &lhs, double rhs){
    Vector result(lhs);
    result /= rhs;
    return result;
}


struct Quadvector {
    double e123o;
    double e123i;
    double e23oi;
    double e31oi;
    double e12oi;

    Quadvector(): e123o(0), e123i(0), e23oi(0), e31oi(0), e12oi(0) {}
    Quadvector(double e123o, double e123i, double e23oi, double e31oi, double e12oi): e123o(e123o), e123i(e123i), e23oi(e23oi), e31oi(e31oi), e12oi(e12oi) {}
    Quadvector& operator+=(const Quadvector &other) {
        e123o += other.e123o;
        e123i += other.e123i;
        e23oi += other.e23oi;
        e31oi += other.e31oi;
        e12oi += other.e12oi;
        return *this;
    }
    Quadvector& operator-=(const Quadvector &other) {
        e123o -= other.e123o;
        e123i -= other.e123i;
        e23oi -= other.e23oi;
        e31oi -= other.e31oi;
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
    };
};

inline Quadvector operator+(const Quadvector &lhs, const Quadvector &rhs){
    Quadvector result(lhs);
    result += rhs;
    return result;
}
inline Quadvector operator-(const Quadvector &lhs, const Quadvector &rhs){
    Quadvector result(lhs);
    result -= rhs;
    return result;
}
inline Quadvector operator*(const Quadvector &lhs, double rhs){
    Quadvector result(lhs);
    result *= rhs;
    return result;
}
inline Quadvector operator*(double lhs, const Quadvector &rhs){
    return rhs*lhs;
}
inline Quadvector operator/(const Quadvector &lhs, double rhs){
    Quadvector result(lhs);
    result /= rhs;
    return result;
}


struct Bivector {
    double e23;
    double e31;
    double e12;
    double e1o;
    double e2o;
    double e3o;
    double e1i;
    double e2i;
    double e3i;
    double eoi;

    Bivector(): e23(0), e31(0), e12(0), e1o(0), e2o(0), e3o(0), e1i(0), e2i(0), e3i(0), eoi(0) {}
    Bivector(double e23, double e31, double e12, double e1o, double e2o, double e3o, double e1i, double e2i, double e3i, double eoi): e23(e23), e31(e31), e12(e12), e1o(e1o), e2o(e2o), e3o(e3o), e1i(e1i), e2i(e2i), e3i(e3i), eoi(eoi) {}
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
        e23 -= other.e23;
        e31 -= other.e31;
        e12 -= other.e12;
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
        e23 *= s;
        e31 *= s;
        e12 *= s;
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
        e23 /= s;
        e31 /= s;
        e12 /= s;
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
        return {-e23, -e31, -e12, -e1o, -e2o, -e3o, -e1i, -e2i, -e3i, -eoi};
    };
};

inline Bivector operator+(const Bivector &lhs, const Bivector &rhs){
    Bivector result(lhs);
    result += rhs;
    return result;
}
inline Bivector operator-(const Bivector &lhs, const Bivector &rhs){
    Bivector result(lhs);
    result -= rhs;
    return result;
}
inline Bivector operator*(const Bivector &lhs, double rhs){
    Bivector result(lhs);
    result *= rhs;
    return result;
}
inline Bivector operator*(double lhs, const Bivector &rhs){
    return rhs*lhs;
}
inline Bivector operator/(const Bivector &lhs, double rhs){
    Bivector result(lhs);
    result /= rhs;
    return result;
}


struct Trivector {
    double e123;
    double e23o;
    double e31o;
    double e12o;
    double e23i;
    double e31i;
    double e12i;
    double e1oi;
    double e2oi;
    double e3oi;

    Trivector(): e123(0), e23o(0), e31o(0), e12o(0), e23i(0), e31i(0), e12i(0), e1oi(0), e2oi(0), e3oi(0) {}
    Trivector(double e123, double e23o, double e31o, double e12o, double e23i, double e31i, double e12i, double e1oi, double e2oi, double e3oi): e123(e123), e23o(e23o), e31o(e31o), e12o(e12o), e23i(e23i), e31i(e31i), e12i(e12i), e1oi(e1oi), e2oi(e2oi), e3oi(e3oi) {}
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
    };
};

inline Trivector operator+(const Trivector &lhs, const Trivector &rhs){
    Trivector result(lhs);
    result += rhs;
    return result;
}
inline Trivector operator-(const Trivector &lhs, const Trivector &rhs){
    Trivector result(lhs);
    result -= rhs;
    return result;
}
inline Trivector operator*(const Trivector &lhs, double rhs){
    Trivector result(lhs);
    result *= rhs;
    return result;
}
inline Trivector operator*(double lhs, const Trivector &rhs){
    return rhs*lhs;
}
inline Trivector operator/(const Trivector &lhs, double rhs){
    Trivector result(lhs);
    result /= rhs;
    return result;
}


struct Rotor {
    double s;
    Bivector b;

    Rotor(): s(0), b() {}
    Rotor(double s, const Bivector &b): s(s), b(b) {}
    Rotor(const Bivector &b): s(0), b(b) {}
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
    Rotor& operator*=(double s) {
        s *= s;
        b *= s;
        return *this;
    }
    Rotor& operator/=(double s) {
        s /= s;
        b /= s;
        return *this;
    }
    Rotor operator-()const {
        return {-s, -b};
    };
};

inline Rotor operator+(const Rotor &lhs, const Rotor &rhs){
    Rotor result(lhs);
    result += rhs;
    return result;
}
inline Rotor operator-(const Rotor &lhs, const Rotor &rhs){
    Rotor result(lhs);
    result -= rhs;
    return result;
}
inline Rotor operator*(const Rotor &lhs, double rhs){
    Rotor result(lhs);
    result *= rhs;
    return result;
}
inline Rotor operator*(double lhs, const Rotor &rhs){
    return rhs*lhs;
}
inline Rotor operator/(const Rotor &lhs, double rhs){
    Rotor result(lhs);
    result /= rhs;
    return result;
}


struct Versor {
    double s;
    Bivector b;
    Quadvector q;

    Versor(): s(0), b(), q() {}
    Versor(double s, const Bivector &b, const Quadvector &q): s(s), b(b), q(q) {}
    Versor(const Bivector &b): s(0), b(b), q() {}
    Versor(const Quadvector &q): s(0), b(), q(q) {}
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
    Versor& operator*=(double s) {
        s *= s;
        b *= s;
        q *= s;
        return *this;
    }
    Versor& operator/=(double s) {
        s /= s;
        b /= s;
        q /= s;
        return *this;
    }
    Versor operator-()const {
        return {-s, -b, -q};
    };
};

inline Versor operator+(const Versor &lhs, const Versor &rhs){
    Versor result(lhs);
    result += rhs;
    return result;
}
inline Versor operator-(const Versor &lhs, const Versor &rhs){
    Versor result(lhs);
    result -= rhs;
    return result;
}
inline Versor operator*(const Versor &lhs, double rhs){
    Versor result(lhs);
    result *= rhs;
    return result;
}
inline Versor operator*(double lhs, const Versor &rhs){
    return rhs*lhs;
}
inline Versor operator/(const Versor &lhs, double rhs){
    Versor result(lhs);
    result /= rhs;
    return result;
}


struct Multivector {
    double s;
    Vector v;
    Bivector b;
    Trivector t;
    Quadvector q;
    double I5;

    Multivector(): s(0), v(), b(), t(), q(), I5(0) {}
    Multivector(double s, const Vector &v, const Bivector &b, const Trivector &t, const Quadvector &q, double I5): s(s), v(v), b(b), t(t), q(q), I5(I5) {}
    Multivector(const Vector &v): s(0), v(v), b(), t(), q(), I5(0) {}
    Multivector(const Bivector &b): s(0), v(), b(b), t(), q(), I5(0) {}
    Multivector(const Trivector &t): s(0), v(), b(), t(t), q(), I5(0) {}
    Multivector(const Quadvector &q): s(0), v(), b(), t(), q(q), I5(0) {}
    Multivector& operator+=(const Multivector &other) {
        s += other.s;
        v += other.v;
        b += other.b;
        t += other.t;
        q += other.q;
        I5 += other.I5;
        return *this;
    }
    Multivector& operator-=(const Multivector &other) {
        s -= other.s;
        v -= other.v;
        b -= other.b;
        t -= other.t;
        q -= other.q;
        I5 -= other.I5;
        return *this;
    }
    Multivector& operator*=(double s) {
        s *= s;
        v *= s;
        b *= s;
        t *= s;
        q *= s;
        I5 *= s;
        return *this;
    }
    Multivector& operator/=(double s) {
        s /= s;
        v /= s;
        b /= s;
        t /= s;
        q /= s;
        I5 /= s;
        return *this;
    }
    Multivector operator-()const {
        return {-s, -v, -b, -t, -q, -I5};
    };
};

inline Multivector operator+(const Multivector &lhs, const Multivector &rhs){
    Multivector result(lhs);
    result += rhs;
    return result;
}
inline Multivector operator-(const Multivector &lhs, const Multivector &rhs){
    Multivector result(lhs);
    result -= rhs;
    return result;
}
inline Multivector operator*(const Multivector &lhs, double rhs){
    Multivector result(lhs);
    result *= rhs;
    return result;
}
inline Multivector operator*(double lhs, const Multivector &rhs){
    return rhs*lhs;
}
inline Multivector operator/(const Multivector &lhs, double rhs){
    Multivector result(lhs);
    result /= rhs;
    return result;
}


Rotor3 operator*(const Vector3 &lhs, const Vector3 &rhs);

Multivector operator*(const Vector3 &lhs, const Bivector3 &rhs);
Multivector operator*(const Bivector3 &lhs, const Vector3 &rhs) {
    return rhs*lhs;
}

Multivector operator*(const Vector3 &lhs, const Rotor3 &rhs);
Multivector operator*(const Rotor3 &lhs, const Vector3 &rhs) {
    return rhs*lhs;
}

Rotor3 operator*(const Bivector3 &lhs, const Bivector3 &rhs);

Rotor3 operator*(const Bivector3 &lhs, const Rotor3 &rhs);
Rotor3 operator*(const Rotor3 &lhs, const Bivector3 &rhs) {
    return rhs*lhs;
}

Rotor3 operator*(const Rotor3 &lhs, const Rotor3 &rhs);

Bivector3 outer(const Vector3 &lhs, const Vector3 &rhs);

Pseudoscalar3 outer(const Vector3 &lhs, const Bivector3 &rhs);
Pseudoscalar3 outer(const Bivector3 &lhs, const Vector3 &rhs) {
    return outer(rhs, lhs);
}

Multivector outer(const Vector3 &lhs, const Rotor3 &rhs);
Multivector outer(const Rotor3 &lhs, const Vector3 &rhs) {
    return outer(rhs, lhs);
}

double outer(const Bivector3 &lhs, const Bivector3 &rhs);

Bivector3 outer(const Bivector3 &lhs, const Rotor3 &rhs);
Bivector3 outer(const Rotor3 &lhs, const Bivector3 &rhs) {
    return outer(rhs, lhs);
}

Rotor3 outer(const Rotor3 &lhs, const Rotor3 &rhs);

double inner(const Vector3 &lhs, const Vector3 &rhs);

Vector3 inner(const Vector3 &lhs, const Bivector3 &rhs);
Vector3 inner(const Bivector3 &lhs, const Vector3 &rhs) {
    return inner(rhs, lhs);
}

Vector3 inner(const Vector3 &lhs, const Rotor3 &rhs);
Vector3 inner(const Rotor3 &lhs, const Vector3 &rhs) {
    return inner(rhs, lhs);
}

double inner(const Bivector3 &lhs, const Bivector3 &rhs);

double inner(const Bivector3 &lhs, const Rotor3 &rhs);
double inner(const Rotor3 &lhs, const Bivector3 &rhs) {
    return inner(rhs, lhs);
}

double inner(const Rotor3 &lhs, const Rotor3 &rhs);

inline const Vector3& reverse(const Vector3 &x) { return x; }
inline Bivector3 reverse(const Bivector3 &x) { return -x; }
Rotor3 reverse(const Rotor3 &x);

} // namespace cga

#endif
