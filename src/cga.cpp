#include "cga.h"

namespace cga {

Rotor3 operator*(const Vector3 &lhs, const Vector3 &rhs) {
    Rotor3 result;
    result.s = lhs.e1*rhs.e1 + lhs.e2*rhs.e2 + lhs.e3*rhs.e3;
    result.b.e23 = lhs.e2*rhs.e3 - lhs.e3*rhs.e2;
    result.b.e31 = -lhs.e1*rhs.e3 + lhs.e3*rhs.e1;
    result.b.e12 = lhs.e1*rhs.e2 - lhs.e2*rhs.e1;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Bivector3 &rhs) {
    Multivector result;
    result.v.e1 = -lhs.e2*rhs.e12 + lhs.e3*rhs.e31;
    result.v.e2 = lhs.e1*rhs.e12 - lhs.e3*rhs.e23;
    result.v.e3 = -lhs.e1*rhs.e31 + lhs.e2*rhs.e23;
    result.t.e123 = lhs.e1*rhs.e23 + lhs.e2*rhs.e31 + lhs.e3*rhs.e12;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Rotor3 &rhs) {
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s - lhs.e2*rhs.b.e12 + lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12 + lhs.e2*rhs.s - lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31 + lhs.e2*rhs.b.e23 + lhs.e3*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23 + lhs.e2*rhs.b.e31 + lhs.e3*rhs.b.e12;
    return result;
}

Rotor3 operator*(const Bivector3 &lhs, const Bivector3 &rhs) {
    Rotor3 result;
    result.s = -lhs.e12*rhs.e12 - lhs.e23*rhs.e23 - lhs.e31*rhs.e31;
    result.b.e23 = lhs.e12*rhs.e31 - lhs.e31*rhs.e12;
    result.b.e31 = -lhs.e12*rhs.e23 + lhs.e23*rhs.e12;
    result.b.e12 = -lhs.e23*rhs.e31 + lhs.e31*rhs.e23;
    return result;
}

Rotor3 operator*(const Bivector3 &lhs, const Rotor3 &rhs) {
    Rotor3 result;
    result.s = -lhs.e12*rhs.b.e12 - lhs.e23*rhs.b.e23 - lhs.e31*rhs.b.e31;
    result.b.e23 = lhs.e12*rhs.b.e31 + lhs.e23*rhs.s - lhs.e31*rhs.b.e12;
    result.b.e31 = -lhs.e12*rhs.b.e23 + lhs.e23*rhs.b.e12 + lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s - lhs.e23*rhs.b.e31 + lhs.e31*rhs.b.e23;
    return result;
}

Rotor3 operator*(const Rotor3 &lhs, const Rotor3 &rhs) {
    Rotor3 result;
    result.s = -lhs.b.e12*rhs.b.e12 - lhs.b.e23*rhs.b.e23 - lhs.b.e31*rhs.b.e31 + lhs.s*rhs.s;
    result.b.e23 = lhs.b.e12*rhs.b.e31 + lhs.b.e23*rhs.s - lhs.b.e31*rhs.b.e12 + lhs.s*rhs.b.e23;
    result.b.e31 = -lhs.b.e12*rhs.b.e23 + lhs.b.e23*rhs.b.e12 + lhs.b.e31*rhs.s + lhs.s*rhs.b.e31;
    result.b.e12 = lhs.b.e12*rhs.s - lhs.b.e23*rhs.b.e31 + lhs.b.e31*rhs.b.e23 + lhs.s*rhs.b.e12;
    return result;
}

Bivector3 outer(const Vector3 &lhs, const Vector3 &rhs) {
    Bivector3 result;
    result.e23 = lhs.e2*rhs.e3 - lhs.e3*rhs.e2;
    result.e31 = -lhs.e1*rhs.e3 + lhs.e3*rhs.e1;
    result.e12 = lhs.e1*rhs.e2 - lhs.e2*rhs.e1;
    return result;
}

Pseudoscalar3 outer(const Vector3 &lhs, const Bivector3 &rhs) {
    Pseudoscalar3 result;
    result.I3 = lhs.e1*rhs.e23 + lhs.e2*rhs.e31 + lhs.e3*rhs.e12;
    return result;
}

Multivector outer(const Vector3 &lhs, const Rotor3 &rhs) {
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23 + lhs.e2*rhs.b.e31 + lhs.e3*rhs.b.e12;
    return result;
}

double outer(const Bivector3 &lhs, const Bivector3 &rhs) {
    double result;
    return result;
}

Bivector3 outer(const Bivector3 &lhs, const Rotor3 &rhs) {
    Bivector3 result;
    result.e23 = lhs.e23*rhs.s;
    result.e31 = lhs.e31*rhs.s;
    result.e12 = lhs.e12*rhs.s;
    return result;
}

Rotor3 outer(const Rotor3 &lhs, const Rotor3 &rhs) {
    Rotor3 result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.b.e23*rhs.s + lhs.s*rhs.b.e23;
    result.b.e31 = lhs.b.e31*rhs.s + lhs.s*rhs.b.e31;
    result.b.e12 = lhs.b.e12*rhs.s + lhs.s*rhs.b.e12;
    return result;
}

double inner(const Vector3 &lhs, const Vector3 &rhs) {
    double result;
    result = lhs.e1*rhs.e1 + lhs.e2*rhs.e2 + lhs.e3*rhs.e3;
    return result;
}

Vector3 inner(const Vector3 &lhs, const Bivector3 &rhs) {
    Vector3 result;
    result.e1 = -lhs.e2*rhs.e12 + lhs.e3*rhs.e31;
    result.e2 = lhs.e1*rhs.e12 - lhs.e3*rhs.e23;
    result.e3 = -lhs.e1*rhs.e31 + lhs.e2*rhs.e23;
    return result;
}

Vector3 inner(const Vector3 &lhs, const Rotor3 &rhs) {
    Vector3 result;
    result.e1 = -lhs.e2*rhs.b.e12 + lhs.e3*rhs.b.e31;
    result.e2 = lhs.e1*rhs.b.e12 - lhs.e3*rhs.b.e23;
    result.e3 = -lhs.e1*rhs.b.e31 + lhs.e2*rhs.b.e23;
    return result;
}

double inner(const Bivector3 &lhs, const Bivector3 &rhs) {
    double result;
    result = -lhs.e12*rhs.e12 - lhs.e23*rhs.e23 - lhs.e31*rhs.e31;
    return result;
}

double inner(const Bivector3 &lhs, const Rotor3 &rhs) {
    double result;
    result = -lhs.e12*rhs.b.e12 - lhs.e23*rhs.b.e23 - lhs.e31*rhs.b.e31;
    return result;
}

double inner(const Rotor3 &lhs, const Rotor3 &rhs) {
    double result;
    result = -lhs.b.e12*rhs.b.e12 - lhs.b.e23*rhs.b.e23 - lhs.b.e31*rhs.b.e31;
    return result;
}

Rotor3 reverse(const Rotor3 &x) {
    Rotor3 result;
    result.s = x.s;
    result.b.e23 = -x.b.e23;
    result.b.e31 = -x.b.e31;
    result.b.e12 = -x.b.e12;
    return result;
}

} // namespace cga
