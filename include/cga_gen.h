#include <cmath>

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


const Vector& reverse(const Vector &x) {
    return x;
}
double norm2(const Vector &x) {
    return inner(x, x);
}
double norm(const Vector &x) {
    return std::sqrt(inner(x, x));
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


Bivector reverse(const Bivector &x) {
    return -x;
}
double norm2(const Bivector &x) {
    return inner(x, x);
}
double norm(const Bivector &x) {
    return std::sqrt(inner(x, x));
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


Rotor reverse(const Rotor &x) {
    return {x.s, -x.b};
}
double norm2(const Rotor &x) {
    return inner(x, x);
}
double norm(const Rotor &x) {
    return std::sqrt(inner(x, x));
}
const Vector& reverse(const Vector &x) {
    return x;
}
double norm2(const Vector &x) {
    return inner(x, x);
}
double norm(const Vector &x) {
    return std::sqrt(inner(x, x));
}
Bivector reverse(const Bivector &x) {
    return -x;
}
double norm2(const Bivector &x) {
    return inner(x, x);
}
double norm(const Bivector &x) {
    return std::sqrt(inner(x, x));
}
Rotor reverse(const Rotor &x) {
    return {x.s, -x.b};
}
double norm2(const Rotor &x) {
    return inner(x, x);
}
double norm(const Rotor &x) {
    return std::sqrt(inner(x, x));
}
