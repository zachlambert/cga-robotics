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
struct Multivector3;
struct Bivector;
struct Trivector;
struct Rotor;
struct Versor;
struct Multivector;

struct Pseudoscalar3 {
    double I3;

    Pseudoscalar3(): I3(0) {}
    Pseudoscalar3(double I3): I3(I3) {}
    bool operator==(const Pseudoscalar3 &other)const;
    bool operator!=(const Pseudoscalar3 &other)const { return !(*this==other); }
    Pseudoscalar3& operator+=(const Pseudoscalar3 &other) {
        I3 += other.I3;
        return *this;
    }
    Pseudoscalar3& operator-=(const Pseudoscalar3 &other) {
        I3 -= other.I3;
        return *this;
    }
    Pseudoscalar3& operator*=(double x) {
        I3 *= x;
        return *this;
    }
    Pseudoscalar3& operator/=(double x) {
        I3 /= x;
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
    bool operator==(const Pseudoscalar &other)const;
    bool operator!=(const Pseudoscalar &other)const { return !(*this==other); }
    Pseudoscalar& operator+=(const Pseudoscalar &other) {
        I5 += other.I5;
        return *this;
    }
    Pseudoscalar& operator-=(const Pseudoscalar &other) {
        I5 -= other.I5;
        return *this;
    }
    Pseudoscalar& operator*=(double x) {
        I5 *= x;
        return *this;
    }
    Pseudoscalar& operator/=(double x) {
        I5 /= x;
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
    explicit Vector3(const Vector& other);
    bool operator==(const Vector3 &other)const;
    bool operator!=(const Vector3 &other)const { return !(*this==other); }
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
    Vector3& operator*=(double x) {
        e1 *= x;
        e2 *= x;
        e3 *= x;
        return *this;
    }
    Vector3& operator/=(double x) {
        e1 /= x;
        e2 /= x;
        e3 /= x;
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
    explicit Bivector3(const Bivector& other);
    bool operator==(const Bivector3 &other)const;
    bool operator!=(const Bivector3 &other)const { return !(*this==other); }
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
    Bivector3& operator*=(double x) {
        e23 *= x;
        e31 *= x;
        e12 *= x;
        return *this;
    }
    Bivector3& operator/=(double x) {
        e23 /= x;
        e31 /= x;
        e12 /= x;
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
    explicit Rotor3(const Rotor& other);
    explicit Rotor3(const Multivector3& other);
    bool operator==(const Rotor3 &other)const;
    bool operator!=(const Rotor3 &other)const { return !(*this==other); }
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
    Rotor3& operator*=(double x) {
        s *= x;
        b *= x;
        return *this;
    }
    Rotor3& operator/=(double x) {
        s /= x;
        b /= x;
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
    Vector(const Vector3& other);
    bool operator==(const Vector &other)const;
    bool operator!=(const Vector &other)const { return !(*this==other); }
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
    Vector& operator*=(double x) {
        e1 *= x;
        e2 *= x;
        e3 *= x;
        eo *= x;
        ei *= x;
        return *this;
    }
    Vector& operator/=(double x) {
        e1 /= x;
        e2 /= x;
        e3 /= x;
        eo /= x;
        ei /= x;
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
    bool operator==(const Quadvector &other)const;
    bool operator!=(const Quadvector &other)const { return !(*this==other); }
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
    Quadvector& operator*=(double x) {
        e123o *= x;
        e123i *= x;
        e23oi *= x;
        e31oi *= x;
        e12oi *= x;
        return *this;
    }
    Quadvector& operator/=(double x) {
        e123o /= x;
        e123i /= x;
        e23oi /= x;
        e31oi /= x;
        e12oi /= x;
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


struct Multivector3 {
    double s;
    Vector3 v;
    Bivector3 b;
    double I3;

    Multivector3(): s(0), v(), b(), I3(0) {}
    Multivector3(double s, const Vector3 &v, const Bivector3 &b, double I3): s(s), v(v), b(b), I3(I3) {}
    Multivector3(const Vector3 &v): s(0), v(v), b(), I3(0) {}
    Multivector3(const Bivector3 &b): s(0), v(), b(b), I3(0) {}
    Multivector3(const Rotor3& other);
    bool operator==(const Multivector3 &other)const;
    bool operator!=(const Multivector3 &other)const { return !(*this==other); }
    Multivector3& operator+=(const Multivector3 &other) {
        s += other.s;
        v += other.v;
        b += other.b;
        I3 += other.I3;
        return *this;
    }
    Multivector3& operator-=(const Multivector3 &other) {
        s -= other.s;
        v -= other.v;
        b -= other.b;
        I3 -= other.I3;
        return *this;
    }
    Multivector3& operator*=(double x) {
        s *= x;
        v *= x;
        b *= x;
        I3 *= x;
        return *this;
    }
    Multivector3& operator/=(double x) {
        s /= x;
        v /= x;
        b /= x;
        I3 /= x;
        return *this;
    }
    Multivector3 operator-()const {
        return {-s, -v, -b, -I3};
    };
};

inline Multivector3 operator+(const Multivector3 &lhs, const Multivector3 &rhs){
    Multivector3 result(lhs);
    result += rhs;
    return result;
}
inline Multivector3 operator-(const Multivector3 &lhs, const Multivector3 &rhs){
    Multivector3 result(lhs);
    result -= rhs;
    return result;
}
inline Multivector3 operator*(const Multivector3 &lhs, double rhs){
    Multivector3 result(lhs);
    result *= rhs;
    return result;
}
inline Multivector3 operator*(double lhs, const Multivector3 &rhs){
    return rhs*lhs;
}
inline Multivector3 operator/(const Multivector3 &lhs, double rhs){
    Multivector3 result(lhs);
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
    Bivector(const Bivector3& other);
    bool operator==(const Bivector &other)const;
    bool operator!=(const Bivector &other)const { return !(*this==other); }
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
    Bivector& operator*=(double x) {
        e23 *= x;
        e31 *= x;
        e12 *= x;
        e1o *= x;
        e2o *= x;
        e3o *= x;
        e1i *= x;
        e2i *= x;
        e3i *= x;
        eoi *= x;
        return *this;
    }
    Bivector& operator/=(double x) {
        e23 /= x;
        e31 /= x;
        e12 /= x;
        e1o /= x;
        e2o /= x;
        e3o /= x;
        e1i /= x;
        e2i /= x;
        e3i /= x;
        eoi /= x;
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
    bool operator==(const Trivector &other)const;
    bool operator!=(const Trivector &other)const { return !(*this==other); }
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
    Trivector& operator*=(double x) {
        e123 *= x;
        e23o *= x;
        e31o *= x;
        e12o *= x;
        e23i *= x;
        e31i *= x;
        e12i *= x;
        e1oi *= x;
        e2oi *= x;
        e3oi *= x;
        return *this;
    }
    Trivector& operator/=(double x) {
        e123 /= x;
        e23o /= x;
        e31o /= x;
        e12o /= x;
        e23i /= x;
        e31i /= x;
        e12i /= x;
        e1oi /= x;
        e2oi /= x;
        e3oi /= x;
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
    Rotor(const Rotor3& other);
    explicit Rotor(const Versor& other);
    explicit Rotor(const Multivector& other);
    bool operator==(const Rotor &other)const;
    bool operator!=(const Rotor &other)const { return !(*this==other); }
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
    Rotor& operator*=(double x) {
        s *= x;
        b *= x;
        return *this;
    }
    Rotor& operator/=(double x) {
        s /= x;
        b /= x;
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
    explicit Versor(const Multivector& other);
    bool operator==(const Versor &other)const;
    bool operator!=(const Versor &other)const { return !(*this==other); }
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
    Versor& operator*=(double x) {
        s *= x;
        b *= x;
        q *= x;
        return *this;
    }
    Versor& operator/=(double x) {
        s /= x;
        b /= x;
        q /= x;
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
    Multivector(const Rotor& other);
    Multivector(const Versor& other);
    bool operator==(const Multivector &other)const;
    bool operator!=(const Multivector &other)const { return !(*this==other); }
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
    Multivector& operator*=(double x) {
        s *= x;
        v *= x;
        b *= x;
        t *= x;
        q *= x;
        I5 *= x;
        return *this;
    }
    Multivector& operator/=(double x) {
        s /= x;
        v /= x;
        b /= x;
        t /= x;
        q /= x;
        I5 /= x;
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


double norm2(const Pseudoscalar3 &x);
inline double norm(const Pseudoscalar3 &x)
{
    return std::sqrt(norm2(x));
}
double norm2(const Pseudoscalar &x);
inline double norm(const Pseudoscalar &x)
{
    return std::sqrt(norm2(x));
}
double norm2(const Vector3 &x);
inline double norm(const Vector3 &x)
{
    return std::sqrt(norm2(x));
}
double norm2(const Bivector3 &x);
inline double norm(const Bivector3 &x)
{
    return std::sqrt(norm2(x));
}
double norm2(const Rotor3 &x);
inline double norm(const Rotor3 &x)
{
    return std::sqrt(norm2(x));
}
double norm2(const Vector &x);
inline double norm(const Vector &x)
{
    return std::sqrt(norm2(x));
}
double norm2(const Quadvector &x);
inline double norm(const Quadvector &x)
{
    return std::sqrt(norm2(x));
}
double operator*(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs);

Bivector operator*(const Pseudoscalar3 &lhs, const Pseudoscalar &rhs);
Bivector operator*(const Pseudoscalar &lhs, const Pseudoscalar3 &rhs);

Bivector3 operator*(const Pseudoscalar3 &lhs, const Vector3 &rhs);
Bivector3 operator*(const Vector3 &lhs, const Pseudoscalar3 &rhs);

Vector3 operator*(const Pseudoscalar3 &lhs, const Bivector3 &rhs);
Vector3 operator*(const Bivector3 &lhs, const Pseudoscalar3 &rhs);

Multivector3 operator*(const Pseudoscalar3 &lhs, const Rotor3 &rhs);
Multivector3 operator*(const Rotor3 &lhs, const Pseudoscalar3 &rhs);

Versor operator*(const Pseudoscalar3 &lhs, const Vector &rhs);
Versor operator*(const Vector &lhs, const Pseudoscalar3 &rhs);

Multivector operator*(const Pseudoscalar3 &lhs, const Quadvector &rhs);
Multivector operator*(const Quadvector &lhs, const Pseudoscalar3 &rhs);

Multivector3 operator*(const Pseudoscalar3 &lhs, const Multivector3 &rhs);
Multivector3 operator*(const Multivector3 &lhs, const Pseudoscalar3 &rhs);

Multivector operator*(const Pseudoscalar3 &lhs, const Bivector &rhs);
Multivector operator*(const Bivector &lhs, const Pseudoscalar3 &rhs);

Versor operator*(const Pseudoscalar3 &lhs, const Trivector &rhs);
Versor operator*(const Trivector &lhs, const Pseudoscalar3 &rhs);

Multivector operator*(const Pseudoscalar3 &lhs, const Rotor &rhs);
Multivector operator*(const Rotor &lhs, const Pseudoscalar3 &rhs);

Multivector operator*(const Pseudoscalar3 &lhs, const Versor &rhs);
Multivector operator*(const Versor &lhs, const Pseudoscalar3 &rhs);

Multivector operator*(const Pseudoscalar3 &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Pseudoscalar3 &rhs);

double operator*(const Pseudoscalar &lhs, const Pseudoscalar &rhs);

Quadvector operator*(const Pseudoscalar &lhs, const Vector3 &rhs);
Quadvector operator*(const Vector3 &lhs, const Pseudoscalar &rhs);

Trivector operator*(const Pseudoscalar &lhs, const Bivector3 &rhs);
Trivector operator*(const Bivector3 &lhs, const Pseudoscalar &rhs);

Multivector operator*(const Pseudoscalar &lhs, const Rotor3 &rhs);
Multivector operator*(const Rotor3 &lhs, const Pseudoscalar &rhs);

Quadvector operator*(const Pseudoscalar &lhs, const Vector &rhs);
Quadvector operator*(const Vector &lhs, const Pseudoscalar &rhs);

Vector operator*(const Pseudoscalar &lhs, const Quadvector &rhs);
Vector operator*(const Quadvector &lhs, const Pseudoscalar &rhs);

Multivector operator*(const Pseudoscalar &lhs, const Multivector3 &rhs);
Multivector operator*(const Multivector3 &lhs, const Pseudoscalar &rhs);

Trivector operator*(const Pseudoscalar &lhs, const Bivector &rhs);
Trivector operator*(const Bivector &lhs, const Pseudoscalar &rhs);

Bivector operator*(const Pseudoscalar &lhs, const Trivector &rhs);
Bivector operator*(const Trivector &lhs, const Pseudoscalar &rhs);

Multivector operator*(const Pseudoscalar &lhs, const Rotor &rhs);
Multivector operator*(const Rotor &lhs, const Pseudoscalar &rhs);

Multivector operator*(const Pseudoscalar &lhs, const Versor &rhs);
Multivector operator*(const Versor &lhs, const Pseudoscalar &rhs);

Multivector operator*(const Pseudoscalar &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Pseudoscalar &rhs);

Rotor3 operator*(const Vector3 &lhs, const Vector3 &rhs);

Multivector3 operator*(const Vector3 &lhs, const Bivector3 &rhs);
Multivector3 operator*(const Bivector3 &lhs, const Vector3 &rhs);

Multivector3 operator*(const Vector3 &lhs, const Rotor3 &rhs);
Multivector3 operator*(const Rotor3 &lhs, const Vector3 &rhs);

Rotor operator*(const Vector3 &lhs, const Vector &rhs);
Rotor operator*(const Vector &lhs, const Vector3 &rhs);

Multivector operator*(const Vector3 &lhs, const Quadvector &rhs);
Multivector operator*(const Quadvector &lhs, const Vector3 &rhs);

Multivector3 operator*(const Vector3 &lhs, const Multivector3 &rhs);
Multivector3 operator*(const Multivector3 &lhs, const Vector3 &rhs);

Multivector operator*(const Vector3 &lhs, const Bivector &rhs);
Multivector operator*(const Bivector &lhs, const Vector3 &rhs);

Versor operator*(const Vector3 &lhs, const Trivector &rhs);
Versor operator*(const Trivector &lhs, const Vector3 &rhs);

Multivector operator*(const Vector3 &lhs, const Rotor &rhs);
Multivector operator*(const Rotor &lhs, const Vector3 &rhs);

Multivector operator*(const Vector3 &lhs, const Versor &rhs);
Multivector operator*(const Versor &lhs, const Vector3 &rhs);

Multivector operator*(const Vector3 &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Vector3 &rhs);

Rotor3 operator*(const Bivector3 &lhs, const Bivector3 &rhs);

Rotor3 operator*(const Bivector3 &lhs, const Rotor3 &rhs);
Rotor3 operator*(const Rotor3 &lhs, const Bivector3 &rhs);

Multivector operator*(const Bivector3 &lhs, const Vector &rhs);
Multivector operator*(const Vector &lhs, const Bivector3 &rhs);

Versor operator*(const Bivector3 &lhs, const Quadvector &rhs);
Versor operator*(const Quadvector &lhs, const Bivector3 &rhs);

Multivector3 operator*(const Bivector3 &lhs, const Multivector3 &rhs);
Multivector3 operator*(const Multivector3 &lhs, const Bivector3 &rhs);

Versor operator*(const Bivector3 &lhs, const Bivector &rhs);
Versor operator*(const Bivector &lhs, const Bivector3 &rhs);

Multivector operator*(const Bivector3 &lhs, const Trivector &rhs);
Multivector operator*(const Trivector &lhs, const Bivector3 &rhs);

Versor operator*(const Bivector3 &lhs, const Rotor &rhs);
Versor operator*(const Rotor &lhs, const Bivector3 &rhs);

Versor operator*(const Bivector3 &lhs, const Versor &rhs);
Versor operator*(const Versor &lhs, const Bivector3 &rhs);

Multivector operator*(const Bivector3 &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Bivector3 &rhs);

Rotor3 operator*(const Rotor3 &lhs, const Rotor3 &rhs);

Multivector operator*(const Rotor3 &lhs, const Vector &rhs);
Multivector operator*(const Vector &lhs, const Rotor3 &rhs);

Versor operator*(const Rotor3 &lhs, const Quadvector &rhs);
Versor operator*(const Quadvector &lhs, const Rotor3 &rhs);

Multivector3 operator*(const Rotor3 &lhs, const Multivector3 &rhs);
Multivector3 operator*(const Multivector3 &lhs, const Rotor3 &rhs);

Versor operator*(const Rotor3 &lhs, const Bivector &rhs);
Versor operator*(const Bivector &lhs, const Rotor3 &rhs);

Multivector operator*(const Rotor3 &lhs, const Trivector &rhs);
Multivector operator*(const Trivector &lhs, const Rotor3 &rhs);

Versor operator*(const Rotor3 &lhs, const Rotor &rhs);
Versor operator*(const Rotor &lhs, const Rotor3 &rhs);

Versor operator*(const Rotor3 &lhs, const Versor &rhs);
Versor operator*(const Versor &lhs, const Rotor3 &rhs);

Multivector operator*(const Rotor3 &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Rotor3 &rhs);

Rotor operator*(const Vector &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Quadvector &rhs);
Multivector operator*(const Quadvector &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Multivector3 &rhs);
Multivector operator*(const Multivector3 &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Bivector &rhs);
Multivector operator*(const Bivector &lhs, const Vector &rhs);

Versor operator*(const Vector &lhs, const Trivector &rhs);
Versor operator*(const Trivector &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Rotor &rhs);
Multivector operator*(const Rotor &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Versor &rhs);
Multivector operator*(const Versor &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Vector &rhs);

Rotor operator*(const Quadvector &lhs, const Quadvector &rhs);

Multivector operator*(const Quadvector &lhs, const Multivector3 &rhs);
Multivector operator*(const Multivector3 &lhs, const Quadvector &rhs);

Versor operator*(const Quadvector &lhs, const Bivector &rhs);
Versor operator*(const Bivector &lhs, const Quadvector &rhs);

Multivector operator*(const Quadvector &lhs, const Trivector &rhs);
Multivector operator*(const Trivector &lhs, const Quadvector &rhs);

Versor operator*(const Quadvector &lhs, const Rotor &rhs);
Versor operator*(const Rotor &lhs, const Quadvector &rhs);

Versor operator*(const Quadvector &lhs, const Versor &rhs);
Versor operator*(const Versor &lhs, const Quadvector &rhs);

Multivector operator*(const Quadvector &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Quadvector &rhs);

Multivector3 operator*(const Multivector3 &lhs, const Multivector3 &rhs);

Multivector operator*(const Multivector3 &lhs, const Bivector &rhs);
Multivector operator*(const Bivector &lhs, const Multivector3 &rhs);

Multivector operator*(const Multivector3 &lhs, const Trivector &rhs);
Multivector operator*(const Trivector &lhs, const Multivector3 &rhs);

Multivector operator*(const Multivector3 &lhs, const Rotor &rhs);
Multivector operator*(const Rotor &lhs, const Multivector3 &rhs);

Multivector operator*(const Multivector3 &lhs, const Versor &rhs);
Multivector operator*(const Versor &lhs, const Multivector3 &rhs);

Multivector operator*(const Multivector3 &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Multivector3 &rhs);

Versor operator*(const Bivector &lhs, const Bivector &rhs);

Multivector operator*(const Bivector &lhs, const Trivector &rhs);
Multivector operator*(const Trivector &lhs, const Bivector &rhs);

Versor operator*(const Bivector &lhs, const Rotor &rhs);
Versor operator*(const Rotor &lhs, const Bivector &rhs);

Versor operator*(const Bivector &lhs, const Versor &rhs);
Versor operator*(const Versor &lhs, const Bivector &rhs);

Multivector operator*(const Bivector &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Bivector &rhs);

Versor operator*(const Trivector &lhs, const Trivector &rhs);

Multivector operator*(const Trivector &lhs, const Rotor &rhs);
Multivector operator*(const Rotor &lhs, const Trivector &rhs);

Multivector operator*(const Trivector &lhs, const Versor &rhs);
Multivector operator*(const Versor &lhs, const Trivector &rhs);

Multivector operator*(const Trivector &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Trivector &rhs);

Versor operator*(const Rotor &lhs, const Rotor &rhs);

Versor operator*(const Rotor &lhs, const Versor &rhs);
Versor operator*(const Versor &lhs, const Rotor &rhs);

Multivector operator*(const Rotor &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Rotor &rhs);

Versor operator*(const Versor &lhs, const Versor &rhs);

Multivector operator*(const Versor &lhs, const Multivector &rhs);
Multivector operator*(const Multivector &lhs, const Versor &rhs);

Multivector operator*(const Multivector &lhs, const Multivector &rhs);

double outer(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs);

double outer(const Pseudoscalar3 &lhs, const Pseudoscalar &rhs);
double outer(const Pseudoscalar &lhs, const Pseudoscalar3 &rhs);

double outer(const Pseudoscalar3 &lhs, const Vector3 &rhs);
double outer(const Vector3 &lhs, const Pseudoscalar3 &rhs);

double outer(const Pseudoscalar3 &lhs, const Bivector3 &rhs);
double outer(const Bivector3 &lhs, const Pseudoscalar3 &rhs);

Pseudoscalar3 outer(const Pseudoscalar3 &lhs, const Rotor3 &rhs);
Pseudoscalar3 outer(const Rotor3 &lhs, const Pseudoscalar3 &rhs);

Quadvector outer(const Pseudoscalar3 &lhs, const Vector &rhs);
Quadvector outer(const Vector &lhs, const Pseudoscalar3 &rhs);

double outer(const Pseudoscalar3 &lhs, const Quadvector &rhs);
double outer(const Quadvector &lhs, const Pseudoscalar3 &rhs);

Pseudoscalar3 outer(const Pseudoscalar3 &lhs, const Multivector3 &rhs);
Pseudoscalar3 outer(const Multivector3 &lhs, const Pseudoscalar3 &rhs);

Pseudoscalar outer(const Pseudoscalar3 &lhs, const Bivector &rhs);
Pseudoscalar outer(const Bivector &lhs, const Pseudoscalar3 &rhs);

double outer(const Pseudoscalar3 &lhs, const Trivector &rhs);
double outer(const Trivector &lhs, const Pseudoscalar3 &rhs);

Multivector outer(const Pseudoscalar3 &lhs, const Rotor &rhs);
Multivector outer(const Rotor &lhs, const Pseudoscalar3 &rhs);

Multivector outer(const Pseudoscalar3 &lhs, const Versor &rhs);
Multivector outer(const Versor &lhs, const Pseudoscalar3 &rhs);

Multivector outer(const Pseudoscalar3 &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Pseudoscalar3 &rhs);

double outer(const Pseudoscalar &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Vector3 &rhs);
double outer(const Vector3 &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Bivector3 &rhs);
double outer(const Bivector3 &lhs, const Pseudoscalar &rhs);

Pseudoscalar outer(const Pseudoscalar &lhs, const Rotor3 &rhs);
Pseudoscalar outer(const Rotor3 &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Vector &rhs);
double outer(const Vector &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Quadvector &rhs);
double outer(const Quadvector &lhs, const Pseudoscalar &rhs);

Pseudoscalar outer(const Pseudoscalar &lhs, const Multivector3 &rhs);
Pseudoscalar outer(const Multivector3 &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Bivector &rhs);
double outer(const Bivector &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Trivector &rhs);
double outer(const Trivector &lhs, const Pseudoscalar &rhs);

Pseudoscalar outer(const Pseudoscalar &lhs, const Rotor &rhs);
Pseudoscalar outer(const Rotor &lhs, const Pseudoscalar &rhs);

Pseudoscalar outer(const Pseudoscalar &lhs, const Versor &rhs);
Pseudoscalar outer(const Versor &lhs, const Pseudoscalar &rhs);

Pseudoscalar outer(const Pseudoscalar &lhs, const Multivector &rhs);
Pseudoscalar outer(const Multivector &lhs, const Pseudoscalar &rhs);

Bivector3 outer(const Vector3 &lhs, const Vector3 &rhs);

Pseudoscalar3 outer(const Vector3 &lhs, const Bivector3 &rhs);
Pseudoscalar3 outer(const Bivector3 &lhs, const Vector3 &rhs);

Multivector3 outer(const Vector3 &lhs, const Rotor3 &rhs);
Multivector3 outer(const Rotor3 &lhs, const Vector3 &rhs);

Bivector outer(const Vector3 &lhs, const Vector &rhs);
Bivector outer(const Vector &lhs, const Vector3 &rhs);

Pseudoscalar outer(const Vector3 &lhs, const Quadvector &rhs);
Pseudoscalar outer(const Quadvector &lhs, const Vector3 &rhs);

Multivector3 outer(const Vector3 &lhs, const Multivector3 &rhs);
Multivector3 outer(const Multivector3 &lhs, const Vector3 &rhs);

Trivector outer(const Vector3 &lhs, const Bivector &rhs);
Trivector outer(const Bivector &lhs, const Vector3 &rhs);

Quadvector outer(const Vector3 &lhs, const Trivector &rhs);
Quadvector outer(const Trivector &lhs, const Vector3 &rhs);

Multivector outer(const Vector3 &lhs, const Rotor &rhs);
Multivector outer(const Rotor &lhs, const Vector3 &rhs);

Multivector outer(const Vector3 &lhs, const Versor &rhs);
Multivector outer(const Versor &lhs, const Vector3 &rhs);

Multivector outer(const Vector3 &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Vector3 &rhs);

double outer(const Bivector3 &lhs, const Bivector3 &rhs);

Bivector3 outer(const Bivector3 &lhs, const Rotor3 &rhs);
Bivector3 outer(const Rotor3 &lhs, const Bivector3 &rhs);

Trivector outer(const Bivector3 &lhs, const Vector &rhs);
Trivector outer(const Vector &lhs, const Bivector3 &rhs);

double outer(const Bivector3 &lhs, const Quadvector &rhs);
double outer(const Quadvector &lhs, const Bivector3 &rhs);

Multivector3 outer(const Bivector3 &lhs, const Multivector3 &rhs);
Multivector3 outer(const Multivector3 &lhs, const Bivector3 &rhs);

Quadvector outer(const Bivector3 &lhs, const Bivector &rhs);
Quadvector outer(const Bivector &lhs, const Bivector3 &rhs);

Pseudoscalar outer(const Bivector3 &lhs, const Trivector &rhs);
Pseudoscalar outer(const Trivector &lhs, const Bivector3 &rhs);

Versor outer(const Bivector3 &lhs, const Rotor &rhs);
Versor outer(const Rotor &lhs, const Bivector3 &rhs);

Versor outer(const Bivector3 &lhs, const Versor &rhs);
Versor outer(const Versor &lhs, const Bivector3 &rhs);

Multivector outer(const Bivector3 &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Bivector3 &rhs);

Rotor3 outer(const Rotor3 &lhs, const Rotor3 &rhs);

Multivector outer(const Rotor3 &lhs, const Vector &rhs);
Multivector outer(const Vector &lhs, const Rotor3 &rhs);

Quadvector outer(const Rotor3 &lhs, const Quadvector &rhs);
Quadvector outer(const Quadvector &lhs, const Rotor3 &rhs);

Multivector3 outer(const Rotor3 &lhs, const Multivector3 &rhs);
Multivector3 outer(const Multivector3 &lhs, const Rotor3 &rhs);

Versor outer(const Rotor3 &lhs, const Bivector &rhs);
Versor outer(const Bivector &lhs, const Rotor3 &rhs);

Multivector outer(const Rotor3 &lhs, const Trivector &rhs);
Multivector outer(const Trivector &lhs, const Rotor3 &rhs);

Versor outer(const Rotor3 &lhs, const Rotor &rhs);
Versor outer(const Rotor &lhs, const Rotor3 &rhs);

Versor outer(const Rotor3 &lhs, const Versor &rhs);
Versor outer(const Versor &lhs, const Rotor3 &rhs);

Multivector outer(const Rotor3 &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Rotor3 &rhs);

Bivector outer(const Vector &lhs, const Vector &rhs);

Pseudoscalar outer(const Vector &lhs, const Quadvector &rhs);
Pseudoscalar outer(const Quadvector &lhs, const Vector &rhs);

Multivector outer(const Vector &lhs, const Multivector3 &rhs);
Multivector outer(const Multivector3 &lhs, const Vector &rhs);

Trivector outer(const Vector &lhs, const Bivector &rhs);
Trivector outer(const Bivector &lhs, const Vector &rhs);

Quadvector outer(const Vector &lhs, const Trivector &rhs);
Quadvector outer(const Trivector &lhs, const Vector &rhs);

Multivector outer(const Vector &lhs, const Rotor &rhs);
Multivector outer(const Rotor &lhs, const Vector &rhs);

Multivector outer(const Vector &lhs, const Versor &rhs);
Multivector outer(const Versor &lhs, const Vector &rhs);

Multivector outer(const Vector &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Vector &rhs);

double outer(const Quadvector &lhs, const Quadvector &rhs);

Multivector outer(const Quadvector &lhs, const Multivector3 &rhs);
Multivector outer(const Multivector3 &lhs, const Quadvector &rhs);

double outer(const Quadvector &lhs, const Bivector &rhs);
double outer(const Bivector &lhs, const Quadvector &rhs);

double outer(const Quadvector &lhs, const Trivector &rhs);
double outer(const Trivector &lhs, const Quadvector &rhs);

Quadvector outer(const Quadvector &lhs, const Rotor &rhs);
Quadvector outer(const Rotor &lhs, const Quadvector &rhs);

Quadvector outer(const Quadvector &lhs, const Versor &rhs);
Quadvector outer(const Versor &lhs, const Quadvector &rhs);

Multivector outer(const Quadvector &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Quadvector &rhs);

Multivector3 outer(const Multivector3 &lhs, const Multivector3 &rhs);

Multivector outer(const Multivector3 &lhs, const Bivector &rhs);
Multivector outer(const Bivector &lhs, const Multivector3 &rhs);

Multivector outer(const Multivector3 &lhs, const Trivector &rhs);
Multivector outer(const Trivector &lhs, const Multivector3 &rhs);

Multivector outer(const Multivector3 &lhs, const Rotor &rhs);
Multivector outer(const Rotor &lhs, const Multivector3 &rhs);

Multivector outer(const Multivector3 &lhs, const Versor &rhs);
Multivector outer(const Versor &lhs, const Multivector3 &rhs);

Multivector outer(const Multivector3 &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Multivector3 &rhs);

Quadvector outer(const Bivector &lhs, const Bivector &rhs);

Pseudoscalar outer(const Bivector &lhs, const Trivector &rhs);
Pseudoscalar outer(const Trivector &lhs, const Bivector &rhs);

Versor outer(const Bivector &lhs, const Rotor &rhs);
Versor outer(const Rotor &lhs, const Bivector &rhs);

Versor outer(const Bivector &lhs, const Versor &rhs);
Versor outer(const Versor &lhs, const Bivector &rhs);

Multivector outer(const Bivector &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Bivector &rhs);

double outer(const Trivector &lhs, const Trivector &rhs);

Multivector outer(const Trivector &lhs, const Rotor &rhs);
Multivector outer(const Rotor &lhs, const Trivector &rhs);

Multivector outer(const Trivector &lhs, const Versor &rhs);
Multivector outer(const Versor &lhs, const Trivector &rhs);

Multivector outer(const Trivector &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Trivector &rhs);

Versor outer(const Rotor &lhs, const Rotor &rhs);

Versor outer(const Rotor &lhs, const Versor &rhs);
Versor outer(const Versor &lhs, const Rotor &rhs);

Multivector outer(const Rotor &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Rotor &rhs);

Versor outer(const Versor &lhs, const Versor &rhs);

Multivector outer(const Versor &lhs, const Multivector &rhs);
Multivector outer(const Multivector &lhs, const Versor &rhs);

Multivector outer(const Multivector &lhs, const Multivector &rhs);

double inner(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs);

Bivector inner(const Pseudoscalar3 &lhs, const Pseudoscalar &rhs);
Bivector inner(const Pseudoscalar &lhs, const Pseudoscalar3 &rhs);

Bivector3 inner(const Pseudoscalar3 &lhs, const Vector3 &rhs);
Bivector3 inner(const Vector3 &lhs, const Pseudoscalar3 &rhs);

Vector3 inner(const Pseudoscalar3 &lhs, const Bivector3 &rhs);
Vector3 inner(const Bivector3 &lhs, const Pseudoscalar3 &rhs);

Vector3 inner(const Pseudoscalar3 &lhs, const Rotor3 &rhs);
Vector3 inner(const Rotor3 &lhs, const Pseudoscalar3 &rhs);

Bivector3 inner(const Pseudoscalar3 &lhs, const Vector &rhs);
Bivector3 inner(const Vector &lhs, const Pseudoscalar3 &rhs);

Vector inner(const Pseudoscalar3 &lhs, const Quadvector &rhs);
Vector inner(const Quadvector &lhs, const Pseudoscalar3 &rhs);

Multivector3 inner(const Pseudoscalar3 &lhs, const Multivector3 &rhs);
Multivector3 inner(const Multivector3 &lhs, const Pseudoscalar3 &rhs);

Vector3 inner(const Pseudoscalar3 &lhs, const Bivector &rhs);
Vector3 inner(const Bivector &lhs, const Pseudoscalar3 &rhs);

double inner(const Pseudoscalar3 &lhs, const Trivector &rhs);
double inner(const Trivector &lhs, const Pseudoscalar3 &rhs);

Vector3 inner(const Pseudoscalar3 &lhs, const Rotor &rhs);
Vector3 inner(const Rotor &lhs, const Pseudoscalar3 &rhs);

Vector inner(const Pseudoscalar3 &lhs, const Versor &rhs);
Vector inner(const Versor &lhs, const Pseudoscalar3 &rhs);

Multivector inner(const Pseudoscalar3 &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Pseudoscalar3 &rhs);

double inner(const Pseudoscalar &lhs, const Pseudoscalar &rhs);

Quadvector inner(const Pseudoscalar &lhs, const Vector3 &rhs);
Quadvector inner(const Vector3 &lhs, const Pseudoscalar &rhs);

Trivector inner(const Pseudoscalar &lhs, const Bivector3 &rhs);
Trivector inner(const Bivector3 &lhs, const Pseudoscalar &rhs);

Trivector inner(const Pseudoscalar &lhs, const Rotor3 &rhs);
Trivector inner(const Rotor3 &lhs, const Pseudoscalar &rhs);

Quadvector inner(const Pseudoscalar &lhs, const Vector &rhs);
Quadvector inner(const Vector &lhs, const Pseudoscalar &rhs);

Vector inner(const Pseudoscalar &lhs, const Quadvector &rhs);
Vector inner(const Quadvector &lhs, const Pseudoscalar &rhs);

Multivector inner(const Pseudoscalar &lhs, const Multivector3 &rhs);
Multivector inner(const Multivector3 &lhs, const Pseudoscalar &rhs);

Trivector inner(const Pseudoscalar &lhs, const Bivector &rhs);
Trivector inner(const Bivector &lhs, const Pseudoscalar &rhs);

Bivector inner(const Pseudoscalar &lhs, const Trivector &rhs);
Bivector inner(const Trivector &lhs, const Pseudoscalar &rhs);

Trivector inner(const Pseudoscalar &lhs, const Rotor &rhs);
Trivector inner(const Rotor &lhs, const Pseudoscalar &rhs);

Multivector inner(const Pseudoscalar &lhs, const Versor &rhs);
Multivector inner(const Versor &lhs, const Pseudoscalar &rhs);

Multivector inner(const Pseudoscalar &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Pseudoscalar &rhs);

double inner(const Vector3 &lhs, const Vector3 &rhs);

Vector3 inner(const Vector3 &lhs, const Bivector3 &rhs);
Vector3 inner(const Bivector3 &lhs, const Vector3 &rhs);

Vector3 inner(const Vector3 &lhs, const Rotor3 &rhs);
Vector3 inner(const Rotor3 &lhs, const Vector3 &rhs);

double inner(const Vector3 &lhs, const Vector &rhs);
double inner(const Vector &lhs, const Vector3 &rhs);

Trivector inner(const Vector3 &lhs, const Quadvector &rhs);
Trivector inner(const Quadvector &lhs, const Vector3 &rhs);

Multivector3 inner(const Vector3 &lhs, const Multivector3 &rhs);
Multivector3 inner(const Multivector3 &lhs, const Vector3 &rhs);

Vector inner(const Vector3 &lhs, const Bivector &rhs);
Vector inner(const Bivector &lhs, const Vector3 &rhs);

Bivector inner(const Vector3 &lhs, const Trivector &rhs);
Bivector inner(const Trivector &lhs, const Vector3 &rhs);

Vector inner(const Vector3 &lhs, const Rotor &rhs);
Vector inner(const Rotor &lhs, const Vector3 &rhs);

Multivector inner(const Vector3 &lhs, const Versor &rhs);
Multivector inner(const Versor &lhs, const Vector3 &rhs);

Multivector inner(const Vector3 &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Vector3 &rhs);

double inner(const Bivector3 &lhs, const Bivector3 &rhs);

double inner(const Bivector3 &lhs, const Rotor3 &rhs);
double inner(const Rotor3 &lhs, const Bivector3 &rhs);

Vector3 inner(const Bivector3 &lhs, const Vector &rhs);
Vector3 inner(const Vector &lhs, const Bivector3 &rhs);

Bivector inner(const Bivector3 &lhs, const Quadvector &rhs);
Bivector inner(const Quadvector &lhs, const Bivector3 &rhs);

Multivector3 inner(const Bivector3 &lhs, const Multivector3 &rhs);
Multivector3 inner(const Multivector3 &lhs, const Bivector3 &rhs);

double inner(const Bivector3 &lhs, const Bivector &rhs);
double inner(const Bivector &lhs, const Bivector3 &rhs);

Vector inner(const Bivector3 &lhs, const Trivector &rhs);
Vector inner(const Trivector &lhs, const Bivector3 &rhs);

double inner(const Bivector3 &lhs, const Rotor &rhs);
double inner(const Rotor &lhs, const Bivector3 &rhs);

Rotor inner(const Bivector3 &lhs, const Versor &rhs);
Rotor inner(const Versor &lhs, const Bivector3 &rhs);

Multivector inner(const Bivector3 &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Bivector3 &rhs);

double inner(const Rotor3 &lhs, const Rotor3 &rhs);

Vector3 inner(const Rotor3 &lhs, const Vector &rhs);
Vector3 inner(const Vector &lhs, const Rotor3 &rhs);

Bivector inner(const Rotor3 &lhs, const Quadvector &rhs);
Bivector inner(const Quadvector &lhs, const Rotor3 &rhs);

Multivector3 inner(const Rotor3 &lhs, const Multivector3 &rhs);
Multivector3 inner(const Multivector3 &lhs, const Rotor3 &rhs);

double inner(const Rotor3 &lhs, const Bivector &rhs);
double inner(const Bivector &lhs, const Rotor3 &rhs);

Vector inner(const Rotor3 &lhs, const Trivector &rhs);
Vector inner(const Trivector &lhs, const Rotor3 &rhs);

double inner(const Rotor3 &lhs, const Rotor &rhs);
double inner(const Rotor &lhs, const Rotor3 &rhs);

Rotor inner(const Rotor3 &lhs, const Versor &rhs);
Rotor inner(const Versor &lhs, const Rotor3 &rhs);

Multivector inner(const Rotor3 &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Rotor3 &rhs);

double inner(const Vector &lhs, const Vector &rhs);

Trivector inner(const Vector &lhs, const Quadvector &rhs);
Trivector inner(const Quadvector &lhs, const Vector &rhs);

Multivector3 inner(const Vector &lhs, const Multivector3 &rhs);
Multivector3 inner(const Multivector3 &lhs, const Vector &rhs);

Vector inner(const Vector &lhs, const Bivector &rhs);
Vector inner(const Bivector &lhs, const Vector &rhs);

Bivector inner(const Vector &lhs, const Trivector &rhs);
Bivector inner(const Trivector &lhs, const Vector &rhs);

Vector inner(const Vector &lhs, const Rotor &rhs);
Vector inner(const Rotor &lhs, const Vector &rhs);

Multivector inner(const Vector &lhs, const Versor &rhs);
Multivector inner(const Versor &lhs, const Vector &rhs);

Multivector inner(const Vector &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Vector &rhs);

double inner(const Quadvector &lhs, const Quadvector &rhs);

Multivector inner(const Quadvector &lhs, const Multivector3 &rhs);
Multivector inner(const Multivector3 &lhs, const Quadvector &rhs);

Bivector inner(const Quadvector &lhs, const Bivector &rhs);
Bivector inner(const Bivector &lhs, const Quadvector &rhs);

Vector inner(const Quadvector &lhs, const Trivector &rhs);
Vector inner(const Trivector &lhs, const Quadvector &rhs);

Bivector inner(const Quadvector &lhs, const Rotor &rhs);
Bivector inner(const Rotor &lhs, const Quadvector &rhs);

Rotor inner(const Quadvector &lhs, const Versor &rhs);
Rotor inner(const Versor &lhs, const Quadvector &rhs);

Multivector inner(const Quadvector &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Quadvector &rhs);

Multivector3 inner(const Multivector3 &lhs, const Multivector3 &rhs);

Multivector inner(const Multivector3 &lhs, const Bivector &rhs);
Multivector inner(const Bivector &lhs, const Multivector3 &rhs);

Multivector inner(const Multivector3 &lhs, const Trivector &rhs);
Multivector inner(const Trivector &lhs, const Multivector3 &rhs);

Multivector inner(const Multivector3 &lhs, const Rotor &rhs);
Multivector inner(const Rotor &lhs, const Multivector3 &rhs);

Multivector inner(const Multivector3 &lhs, const Versor &rhs);
Multivector inner(const Versor &lhs, const Multivector3 &rhs);

Multivector inner(const Multivector3 &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Multivector3 &rhs);

double inner(const Bivector &lhs, const Bivector &rhs);

Vector inner(const Bivector &lhs, const Trivector &rhs);
Vector inner(const Trivector &lhs, const Bivector &rhs);

double inner(const Bivector &lhs, const Rotor &rhs);
double inner(const Rotor &lhs, const Bivector &rhs);

Rotor inner(const Bivector &lhs, const Versor &rhs);
Rotor inner(const Versor &lhs, const Bivector &rhs);

Multivector inner(const Bivector &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Bivector &rhs);

double inner(const Trivector &lhs, const Trivector &rhs);

Vector inner(const Trivector &lhs, const Rotor &rhs);
Vector inner(const Rotor &lhs, const Trivector &rhs);

Vector inner(const Trivector &lhs, const Versor &rhs);
Vector inner(const Versor &lhs, const Trivector &rhs);

Multivector inner(const Trivector &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Trivector &rhs);

double inner(const Rotor &lhs, const Rotor &rhs);

Rotor inner(const Rotor &lhs, const Versor &rhs);
Rotor inner(const Versor &lhs, const Rotor &rhs);

Multivector inner(const Rotor &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Rotor &rhs);

Rotor inner(const Versor &lhs, const Versor &rhs);

Multivector inner(const Versor &lhs, const Multivector &rhs);
Multivector inner(const Multivector &lhs, const Versor &rhs);

Multivector inner(const Multivector &lhs, const Multivector &rhs);

inline Pseudoscalar3 reverse(const Pseudoscalar3 &x) { return -x; }
inline const Pseudoscalar& reverse(const Pseudoscalar &x) { return x; }
inline const Vector3& reverse(const Vector3 &x) { return x; }
inline Bivector3 reverse(const Bivector3 &x) { return -x; }
Rotor3 reverse(const Rotor3 &x);

inline const Vector& reverse(const Vector &x) { return x; }
inline const Quadvector& reverse(const Quadvector &x) { return x; }
Multivector3 reverse(const Multivector3 &x);

inline Bivector reverse(const Bivector &x) { return -x; }
inline Trivector reverse(const Trivector &x) { return -x; }
Rotor reverse(const Rotor &x);

Versor reverse(const Versor &x);

Multivector reverse(const Multivector &x);

std::ostream& operator<<(std::ostream& outs, const Pseudoscalar3 &x);
std::ostream& operator<<(std::ostream& outs, const Pseudoscalar &x);
std::ostream& operator<<(std::ostream& outs, const Vector3 &x);
std::ostream& operator<<(std::ostream& outs, const Bivector3 &x);
std::ostream& operator<<(std::ostream& outs, const Rotor3 &x);
std::ostream& operator<<(std::ostream& outs, const Vector &x);
std::ostream& operator<<(std::ostream& outs, const Quadvector &x);
std::ostream& operator<<(std::ostream& outs, const Multivector3 &x);
std::ostream& operator<<(std::ostream& outs, const Bivector &x);
std::ostream& operator<<(std::ostream& outs, const Trivector &x);
std::ostream& operator<<(std::ostream& outs, const Rotor &x);
std::ostream& operator<<(std::ostream& outs, const Versor &x);
std::ostream& operator<<(std::ostream& outs, const Multivector &x);
} // namespace cga

#endif
