#include <cmath>
#include <iostream>

struct Vector {
    double e1;
    double e2;
    double e3;
    double eo;
    double ei;
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


struct Quadvector {
    double e123o;
    double e123i;
    double e23oi;
    double e31oi;
    double e12oi;
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


struct Pseudoscalar {
    double p;
    Pseudoscalar& operator+=(const Pseudoscalar &other) {
        p += other.p;
        return *this;
    }
    Pseudoscalar& operator-=(const Pseudoscalar &other) {
        p -= other.p;
        return *this;
    }
    Pseudoscalar& operator*=(double s) {
        p *= s;
        return *this;
    }
    Pseudoscalar& operator/=(double s) {
        p /= s;
        return *this;
    }
    Pseudoscalar operator-()const {
        return {-p};
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


struct Rotor {
    double s;
    Bivector b;
    Rotor& operator+=(const Rotor &other) {
        s += other.s;
        b.e23 += other.b.e23;
        b.e31 += other.b.e31;
        b.e12 += other.b.e12;
        b.e1o += other.b.e1o;
        b.e2o += other.b.e2o;
        b.e3o += other.b.e3o;
        b.e1i += other.b.e1i;
        b.e2i += other.b.e2i;
        b.e3i += other.b.e3i;
        b.eoi += other.b.eoi;
        return *this;
    }
    Rotor& operator-=(const Rotor &other) {
        s -= other.s;
        b.e23 -= other.b.e23;
        b.e31 -= other.b.e31;
        b.e12 -= other.b.e12;
        b.e1o -= other.b.e1o;
        b.e2o -= other.b.e2o;
        b.e3o -= other.b.e3o;
        b.e1i -= other.b.e1i;
        b.e2i -= other.b.e2i;
        b.e3i -= other.b.e3i;
        b.eoi -= other.b.eoi;
        return *this;
    }
    Rotor& operator*=(double s) {
        s *= s;
        b.e23 *= s;
        b.e31 *= s;
        b.e12 *= s;
        b.e1o *= s;
        b.e2o *= s;
        b.e3o *= s;
        b.e1i *= s;
        b.e2i *= s;
        b.e3i *= s;
        b.eoi *= s;
        return *this;
    }
    Rotor& operator/=(double s) {
        s /= s;
        b.e23 /= s;
        b.e31 /= s;
        b.e12 /= s;
        b.e1o /= s;
        b.e2o /= s;
        b.e3o /= s;
        b.e1i /= s;
        b.e2i /= s;
        b.e3i /= s;
        b.eoi /= s;
        return *this;
    }
    Rotor operator-()const {
        return {-s, -b.e23, -b.e31, -b.e12, -b.e1o, -b.e2o, -b.e3o, -b.e1i, -b.e2i, -b.e3i, -b.eoi};
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
    Versor& operator+=(const Versor &other) {
        s += other.s;
        b.e23 += other.b.e23;
        b.e31 += other.b.e31;
        b.e12 += other.b.e12;
        b.e1o += other.b.e1o;
        b.e2o += other.b.e2o;
        b.e3o += other.b.e3o;
        b.e1i += other.b.e1i;
        b.e2i += other.b.e2i;
        b.e3i += other.b.e3i;
        b.eoi += other.b.eoi;
        q.e123o += other.q.e123o;
        q.e123i += other.q.e123i;
        q.e23oi += other.q.e23oi;
        q.e31oi += other.q.e31oi;
        q.e12oi += other.q.e12oi;
        return *this;
    }
    Versor& operator-=(const Versor &other) {
        s -= other.s;
        b.e23 -= other.b.e23;
        b.e31 -= other.b.e31;
        b.e12 -= other.b.e12;
        b.e1o -= other.b.e1o;
        b.e2o -= other.b.e2o;
        b.e3o -= other.b.e3o;
        b.e1i -= other.b.e1i;
        b.e2i -= other.b.e2i;
        b.e3i -= other.b.e3i;
        b.eoi -= other.b.eoi;
        q.e123o -= other.q.e123o;
        q.e123i -= other.q.e123i;
        q.e23oi -= other.q.e23oi;
        q.e31oi -= other.q.e31oi;
        q.e12oi -= other.q.e12oi;
        return *this;
    }
    Versor& operator*=(double s) {
        s *= s;
        b.e23 *= s;
        b.e31 *= s;
        b.e12 *= s;
        b.e1o *= s;
        b.e2o *= s;
        b.e3o *= s;
        b.e1i *= s;
        b.e2i *= s;
        b.e3i *= s;
        b.eoi *= s;
        q.e123o *= s;
        q.e123i *= s;
        q.e23oi *= s;
        q.e31oi *= s;
        q.e12oi *= s;
        return *this;
    }
    Versor& operator/=(double s) {
        s /= s;
        b.e23 /= s;
        b.e31 /= s;
        b.e12 /= s;
        b.e1o /= s;
        b.e2o /= s;
        b.e3o /= s;
        b.e1i /= s;
        b.e2i /= s;
        b.e3i /= s;
        b.eoi /= s;
        q.e123o /= s;
        q.e123i /= s;
        q.e23oi /= s;
        q.e31oi /= s;
        q.e12oi /= s;
        return *this;
    }
    Versor operator-()const {
        return {-s, -b.e23, -b.e31, -b.e12, -b.e1o, -b.e2o, -b.e3o, -b.e1i, -b.e2i, -b.e3i, -b.eoi, -q.e123o, -q.e123i, -q.e23oi, -q.e31oi, -q.e12oi};
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
    double p;
    Multivector& operator+=(const Multivector &other) {
        s += other.s;
        v.e1 += other.v.e1;
        v.e2 += other.v.e2;
        v.e3 += other.v.e3;
        v.eo += other.v.eo;
        v.ei += other.v.ei;
        b.e23 += other.b.e23;
        b.e31 += other.b.e31;
        b.e12 += other.b.e12;
        b.e1o += other.b.e1o;
        b.e2o += other.b.e2o;
        b.e3o += other.b.e3o;
        b.e1i += other.b.e1i;
        b.e2i += other.b.e2i;
        b.e3i += other.b.e3i;
        b.eoi += other.b.eoi;
        t.e123 += other.t.e123;
        t.e23o += other.t.e23o;
        t.e31o += other.t.e31o;
        t.e12o += other.t.e12o;
        t.e23i += other.t.e23i;
        t.e31i += other.t.e31i;
        t.e12i += other.t.e12i;
        t.e1oi += other.t.e1oi;
        t.e2oi += other.t.e2oi;
        t.e3oi += other.t.e3oi;
        q.e123o += other.q.e123o;
        q.e123i += other.q.e123i;
        q.e23oi += other.q.e23oi;
        q.e31oi += other.q.e31oi;
        q.e12oi += other.q.e12oi;
        p += other.p;
        return *this;
    }
    Multivector& operator-=(const Multivector &other) {
        s -= other.s;
        v.e1 -= other.v.e1;
        v.e2 -= other.v.e2;
        v.e3 -= other.v.e3;
        v.eo -= other.v.eo;
        v.ei -= other.v.ei;
        b.e23 -= other.b.e23;
        b.e31 -= other.b.e31;
        b.e12 -= other.b.e12;
        b.e1o -= other.b.e1o;
        b.e2o -= other.b.e2o;
        b.e3o -= other.b.e3o;
        b.e1i -= other.b.e1i;
        b.e2i -= other.b.e2i;
        b.e3i -= other.b.e3i;
        b.eoi -= other.b.eoi;
        t.e123 -= other.t.e123;
        t.e23o -= other.t.e23o;
        t.e31o -= other.t.e31o;
        t.e12o -= other.t.e12o;
        t.e23i -= other.t.e23i;
        t.e31i -= other.t.e31i;
        t.e12i -= other.t.e12i;
        t.e1oi -= other.t.e1oi;
        t.e2oi -= other.t.e2oi;
        t.e3oi -= other.t.e3oi;
        q.e123o -= other.q.e123o;
        q.e123i -= other.q.e123i;
        q.e23oi -= other.q.e23oi;
        q.e31oi -= other.q.e31oi;
        q.e12oi -= other.q.e12oi;
        p -= other.p;
        return *this;
    }
    Multivector& operator*=(double s) {
        s *= s;
        v.e1 *= s;
        v.e2 *= s;
        v.e3 *= s;
        v.eo *= s;
        v.ei *= s;
        b.e23 *= s;
        b.e31 *= s;
        b.e12 *= s;
        b.e1o *= s;
        b.e2o *= s;
        b.e3o *= s;
        b.e1i *= s;
        b.e2i *= s;
        b.e3i *= s;
        b.eoi *= s;
        t.e123 *= s;
        t.e23o *= s;
        t.e31o *= s;
        t.e12o *= s;
        t.e23i *= s;
        t.e31i *= s;
        t.e12i *= s;
        t.e1oi *= s;
        t.e2oi *= s;
        t.e3oi *= s;
        q.e123o *= s;
        q.e123i *= s;
        q.e23oi *= s;
        q.e31oi *= s;
        q.e12oi *= s;
        p *= s;
        return *this;
    }
    Multivector& operator/=(double s) {
        s /= s;
        v.e1 /= s;
        v.e2 /= s;
        v.e3 /= s;
        v.eo /= s;
        v.ei /= s;
        b.e23 /= s;
        b.e31 /= s;
        b.e12 /= s;
        b.e1o /= s;
        b.e2o /= s;
        b.e3o /= s;
        b.e1i /= s;
        b.e2i /= s;
        b.e3i /= s;
        b.eoi /= s;
        t.e123 /= s;
        t.e23o /= s;
        t.e31o /= s;
        t.e12o /= s;
        t.e23i /= s;
        t.e31i /= s;
        t.e12i /= s;
        t.e1oi /= s;
        t.e2oi /= s;
        t.e3oi /= s;
        q.e123o /= s;
        q.e123i /= s;
        q.e23oi /= s;
        q.e31oi /= s;
        q.e12oi /= s;
        p /= s;
        return *this;
    }
    Multivector operator-()const {
        return {-s, -v.e1, -v.e2, -v.e3, -v.eo, -v.ei, -b.e23, -b.e31, -b.e12, -b.e1o, -b.e2o, -b.e3o, -b.e1i, -b.e2i, -b.e3i, -b.eoi, -t.e123, -t.e23o, -t.e31o, -t.e12o, -t.e23i, -t.e31i, -t.e12i, -t.e1oi, -t.e2oi, -t.e3oi, -q.e123o, -q.e123i, -q.e23oi, -q.e31oi, -q.e12oi, -p};
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


Rotor operator*(const Vector &lhs, const Vector &rhs);

Bivector outer(const Vector &lhs, const Vector &rhs);

double inner(const Vector &lhs, const Vector &rhs);

Multivector operator*(const Vector &lhs, const Bivector &rhs);

Multivector operator*(const Bivector &lhs, const Vector &rhs)
{
    return rhs*lhs;
}

Trivector outer(const Vector &lhs, const Bivector &rhs);

Trivector outer(const Bivector &lhs, const Vector &rhs)
{
    return outer(rhs, lhs);
}

Vector inner(const Vector &lhs, const Bivector &rhs);

Vector inner(const Bivector &lhs, const Vector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Vector &lhs, const Trivector &rhs);

Versor operator*(const Trivector &lhs, const Vector &rhs)
{
    return rhs*lhs;
}

Quadvector outer(const Vector &lhs, const Trivector &rhs);

Quadvector outer(const Trivector &lhs, const Vector &rhs)
{
    return outer(rhs, lhs);
}

Bivector inner(const Vector &lhs, const Trivector &rhs);

Bivector inner(const Trivector &lhs, const Vector &rhs)
{
    return inner(rhs, lhs);
}

Multivector operator*(const Vector &lhs, const Quadvector &rhs);

Multivector operator*(const Quadvector &lhs, const Vector &rhs)
{
    return rhs*lhs;
}

Pseudoscalar outer(const Vector &lhs, const Quadvector &rhs);

Pseudoscalar outer(const Quadvector &lhs, const Vector &rhs)
{
    return outer(rhs, lhs);
}

Trivector inner(const Vector &lhs, const Quadvector &rhs);

Trivector inner(const Quadvector &lhs, const Vector &rhs)
{
    return inner(rhs, lhs);
}

Quadvector operator*(const Vector &lhs, const Pseudoscalar &rhs);

Quadvector operator*(const Pseudoscalar &lhs, const Vector &rhs)
{
    return rhs*lhs;
}

Quadvector outer(const Vector &lhs, const Pseudoscalar &rhs);

Quadvector outer(const Pseudoscalar &lhs, const Vector &rhs)
{
    return outer(rhs, lhs);
}

Quadvector inner(const Vector &lhs, const Pseudoscalar &rhs);

Quadvector inner(const Pseudoscalar &lhs, const Vector &rhs)
{
    return inner(rhs, lhs);
}

Multivector operator*(const Vector &lhs, const Rotor &rhs);

Multivector operator*(const Rotor &lhs, const Vector &rhs)
{
    return rhs*lhs;
}

Multivector outer(const Vector &lhs, const Rotor &rhs);

Multivector outer(const Rotor &lhs, const Vector &rhs)
{
    return outer(rhs, lhs);
}

Vector inner(const Vector &lhs, const Rotor &rhs);

Vector inner(const Rotor &lhs, const Vector &rhs)
{
    return inner(rhs, lhs);
}

Multivector operator*(const Vector &lhs, const Versor &rhs);

Multivector operator*(const Versor &lhs, const Vector &rhs)
{
    return rhs*lhs;
}

Multivector outer(const Vector &lhs, const Versor &rhs);

Multivector outer(const Versor &lhs, const Vector &rhs)
{
    return outer(rhs, lhs);
}

Multivector inner(const Vector &lhs, const Versor &rhs);

Multivector inner(const Versor &lhs, const Vector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Bivector &lhs, const Bivector &rhs);

Quadvector outer(const Bivector &lhs, const Bivector &rhs);

double inner(const Bivector &lhs, const Bivector &rhs);

Multivector operator*(const Bivector &lhs, const Trivector &rhs);

Multivector operator*(const Trivector &lhs, const Bivector &rhs)
{
    return rhs*lhs;
}

Pseudoscalar outer(const Bivector &lhs, const Trivector &rhs);

Pseudoscalar outer(const Trivector &lhs, const Bivector &rhs)
{
    return outer(rhs, lhs);
}

Vector inner(const Bivector &lhs, const Trivector &rhs);

Vector inner(const Trivector &lhs, const Bivector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Bivector &lhs, const Quadvector &rhs);

Versor operator*(const Quadvector &lhs, const Bivector &rhs)
{
    return rhs*lhs;
}

Quadvector outer(const Bivector &lhs, const Quadvector &rhs);

Quadvector outer(const Quadvector &lhs, const Bivector &rhs)
{
    return outer(rhs, lhs);
}

Bivector inner(const Bivector &lhs, const Quadvector &rhs);

Bivector inner(const Quadvector &lhs, const Bivector &rhs)
{
    return inner(rhs, lhs);
}

Trivector operator*(const Bivector &lhs, const Pseudoscalar &rhs);

Trivector operator*(const Pseudoscalar &lhs, const Bivector &rhs)
{
    return rhs*lhs;
}

Trivector outer(const Bivector &lhs, const Pseudoscalar &rhs);

Trivector outer(const Pseudoscalar &lhs, const Bivector &rhs)
{
    return outer(rhs, lhs);
}

Trivector inner(const Bivector &lhs, const Pseudoscalar &rhs);

Trivector inner(const Pseudoscalar &lhs, const Bivector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Bivector &lhs, const Rotor &rhs);

Versor operator*(const Rotor &lhs, const Bivector &rhs)
{
    return rhs*lhs;
}

Versor outer(const Bivector &lhs, const Rotor &rhs);

Versor outer(const Rotor &lhs, const Bivector &rhs)
{
    return outer(rhs, lhs);
}

Rotor inner(const Bivector &lhs, const Rotor &rhs);

Rotor inner(const Rotor &lhs, const Bivector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Bivector &lhs, const Versor &rhs);

Versor operator*(const Versor &lhs, const Bivector &rhs)
{
    return rhs*lhs;
}

Versor outer(const Bivector &lhs, const Versor &rhs);

Versor outer(const Versor &lhs, const Bivector &rhs)
{
    return outer(rhs, lhs);
}

Rotor inner(const Bivector &lhs, const Versor &rhs);

Rotor inner(const Versor &lhs, const Bivector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Trivector &lhs, const Trivector &rhs);

Quadvector outer(const Trivector &lhs, const Trivector &rhs);

double inner(const Trivector &lhs, const Trivector &rhs);

Multivector operator*(const Trivector &lhs, const Quadvector &rhs);

Multivector operator*(const Quadvector &lhs, const Trivector &rhs)
{
    return rhs*lhs;
}

Trivector outer(const Trivector &lhs, const Quadvector &rhs);

Trivector outer(const Quadvector &lhs, const Trivector &rhs)
{
    return outer(rhs, lhs);
}

Vector inner(const Trivector &lhs, const Quadvector &rhs);

Vector inner(const Quadvector &lhs, const Trivector &rhs)
{
    return inner(rhs, lhs);
}

Bivector operator*(const Trivector &lhs, const Pseudoscalar &rhs);

Bivector operator*(const Pseudoscalar &lhs, const Trivector &rhs)
{
    return rhs*lhs;
}

Bivector outer(const Trivector &lhs, const Pseudoscalar &rhs);

Bivector outer(const Pseudoscalar &lhs, const Trivector &rhs)
{
    return outer(rhs, lhs);
}

Bivector inner(const Trivector &lhs, const Pseudoscalar &rhs);

Bivector inner(const Pseudoscalar &lhs, const Trivector &rhs)
{
    return inner(rhs, lhs);
}

Multivector operator*(const Trivector &lhs, const Rotor &rhs);

Multivector operator*(const Rotor &lhs, const Trivector &rhs)
{
    return rhs*lhs;
}

Multivector outer(const Trivector &lhs, const Rotor &rhs);

Multivector outer(const Rotor &lhs, const Trivector &rhs)
{
    return outer(rhs, lhs);
}

Multivector inner(const Trivector &lhs, const Rotor &rhs);

Multivector inner(const Rotor &lhs, const Trivector &rhs)
{
    return inner(rhs, lhs);
}

Multivector operator*(const Trivector &lhs, const Versor &rhs);

Multivector operator*(const Versor &lhs, const Trivector &rhs)
{
    return rhs*lhs;
}

Multivector outer(const Trivector &lhs, const Versor &rhs);

Multivector outer(const Versor &lhs, const Trivector &rhs)
{
    return outer(rhs, lhs);
}

Multivector inner(const Trivector &lhs, const Versor &rhs);

Multivector inner(const Versor &lhs, const Trivector &rhs)
{
    return inner(rhs, lhs);
}

Rotor operator*(const Quadvector &lhs, const Quadvector &rhs);

Bivector outer(const Quadvector &lhs, const Quadvector &rhs);

double inner(const Quadvector &lhs, const Quadvector &rhs);

Vector operator*(const Quadvector &lhs, const Pseudoscalar &rhs);

Vector operator*(const Pseudoscalar &lhs, const Quadvector &rhs)
{
    return rhs*lhs;
}

Vector outer(const Quadvector &lhs, const Pseudoscalar &rhs);

Vector outer(const Pseudoscalar &lhs, const Quadvector &rhs)
{
    return outer(rhs, lhs);
}

Vector inner(const Quadvector &lhs, const Pseudoscalar &rhs);

Vector inner(const Pseudoscalar &lhs, const Quadvector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Quadvector &lhs, const Rotor &rhs);

Versor operator*(const Rotor &lhs, const Quadvector &rhs)
{
    return rhs*lhs;
}

Quadvector outer(const Quadvector &lhs, const Rotor &rhs);

Quadvector outer(const Rotor &lhs, const Quadvector &rhs)
{
    return outer(rhs, lhs);
}

Versor inner(const Quadvector &lhs, const Rotor &rhs);

Versor inner(const Rotor &lhs, const Quadvector &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Quadvector &lhs, const Versor &rhs);

Versor operator*(const Versor &lhs, const Quadvector &rhs)
{
    return rhs*lhs;
}

Versor outer(const Quadvector &lhs, const Versor &rhs);

Versor outer(const Versor &lhs, const Quadvector &rhs)
{
    return outer(rhs, lhs);
}

Versor inner(const Quadvector &lhs, const Versor &rhs);

Versor inner(const Versor &lhs, const Quadvector &rhs)
{
    return inner(rhs, lhs);
}

double operator*(const Pseudoscalar &lhs, const Pseudoscalar &rhs);

double outer(const Pseudoscalar &lhs, const Pseudoscalar &rhs);

double inner(const Pseudoscalar &lhs, const Pseudoscalar &rhs);

Multivector operator*(const Pseudoscalar &lhs, const Rotor &rhs);

Multivector operator*(const Rotor &lhs, const Pseudoscalar &rhs)
{
    return rhs*lhs;
}

Multivector outer(const Pseudoscalar &lhs, const Rotor &rhs);

Multivector outer(const Rotor &lhs, const Pseudoscalar &rhs)
{
    return outer(rhs, lhs);
}

Multivector inner(const Pseudoscalar &lhs, const Rotor &rhs);

Multivector inner(const Rotor &lhs, const Pseudoscalar &rhs)
{
    return inner(rhs, lhs);
}

Multivector operator*(const Pseudoscalar &lhs, const Versor &rhs);

Multivector operator*(const Versor &lhs, const Pseudoscalar &rhs)
{
    return rhs*lhs;
}

Multivector outer(const Pseudoscalar &lhs, const Versor &rhs);

Multivector outer(const Versor &lhs, const Pseudoscalar &rhs)
{
    return outer(rhs, lhs);
}

Multivector inner(const Pseudoscalar &lhs, const Versor &rhs);

Multivector inner(const Versor &lhs, const Pseudoscalar &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Rotor &lhs, const Rotor &rhs);

Versor outer(const Rotor &lhs, const Rotor &rhs);

Rotor inner(const Rotor &lhs, const Rotor &rhs);

Versor operator*(const Rotor &lhs, const Versor &rhs);

Versor operator*(const Versor &lhs, const Rotor &rhs)
{
    return rhs*lhs;
}

Versor outer(const Rotor &lhs, const Versor &rhs);

Versor outer(const Versor &lhs, const Rotor &rhs)
{
    return outer(rhs, lhs);
}

Versor inner(const Rotor &lhs, const Versor &rhs);

Versor inner(const Versor &lhs, const Rotor &rhs)
{
    return inner(rhs, lhs);
}

Versor operator*(const Versor &lhs, const Versor &rhs);

Versor outer(const Versor &lhs, const Versor &rhs);

Versor inner(const Versor &lhs, const Versor &rhs);

const Vector& reverse(const Vector &x) {
    return x;
}
double norm2(const Vector &x) {
    return inner(x, x);
}
double norm(const Vector &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Vector &x);Bivector reverse(const Bivector &x) {
    return -x;
}
double norm2(const Bivector &x) {
    return inner(x, x);
}
double norm(const Bivector &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Bivector &x);Trivector reverse(const Trivector &x) {
    return -x;
}
double norm2(const Trivector &x) {
    return inner(x, x);
}
double norm(const Trivector &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Trivector &x);const Quadvector& reverse(const Quadvector &x) {
    return x;
}
double norm2(const Quadvector &x) {
    return inner(x, x);
}
double norm(const Quadvector &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Quadvector &x);const Pseudoscalar& reverse(const Pseudoscalar &x) {
    return x;
}
double norm2(const Pseudoscalar &x) {
    return inner(x, x);
}
double norm(const Pseudoscalar &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Pseudoscalar &x);Rotor reverse(const Rotor &x) {
    return {x.s, -x.b.e23, -x.b.e31, -x.b.e12, -x.b.e1o, -x.b.e2o, -x.b.e3o, -x.b.e1i, -x.b.e2i, -x.b.e3i, -x.b.eoi};
}
double norm2(const Rotor &x) {
    return inner(x, x);
}
double norm(const Rotor &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Rotor &x);Versor reverse(const Versor &x) {
    return {x.s, -x.b.e23, -x.b.e31, -x.b.e12, -x.b.e1o, -x.b.e2o, -x.b.e3o, -x.b.e1i, -x.b.e2i, -x.b.e3i, -x.b.eoi, x.q.e123o, x.q.e123i, x.q.e23oi, x.q.e31oi, x.q.e12oi};
}
double norm2(const Versor &x) {
    return inner(x, x);
}
double norm(const Versor &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Versor &x);Multivector reverse(const Multivector &x) {
    return {x.s, x.v.e1, x.v.e2, x.v.e3, x.v.eo, x.v.ei, -x.b.e23, -x.b.e31, -x.b.e12, -x.b.e1o, -x.b.e2o, -x.b.e3o, -x.b.e1i, -x.b.e2i, -x.b.e3i, -x.b.eoi, -x.t.e123, -x.t.e23o, -x.t.e31o, -x.t.e12o, -x.t.e23i, -x.t.e31i, -x.t.e12i, -x.t.e1oi, -x.t.e2oi, -x.t.e3oi, x.q.e123o, x.q.e123i, x.q.e23oi, x.q.e31oi, x.q.e12oi, x.p};
}
double norm2(const Multivector &x) {
    return inner(x, x);
}
double norm(const Multivector &x) {
    return std::sqrt(inner(x, x));
}
std::ostream& operator<<(std::ostream& outs, const Multivector &x);