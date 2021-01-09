#include "cga.h"

namespace cga {

double operator*(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs) {
    double result;
    result = -lhs.I3*rhs.I3;
    return result;
}
Bivector operator*(const Pseudoscalar3 &lhs, const Pseudoscalar &rhs) {
    Bivector result;
    result.eoi = -1.0*lhs.I3*rhs.I5;
    return result;
}
Bivector3 operator*(const Pseudoscalar3 &lhs, const Vector3 &rhs) {
    Bivector3 result;
    result.e23 = lhs.I3*rhs.e1;
    result.e31 = lhs.I3*rhs.e2;
    result.e12 = lhs.I3*rhs.e3;
    return result;
}
Vector3 operator*(const Pseudoscalar3 &lhs, const Bivector3 &rhs) {
    Vector3 result;
    result.e1 = -lhs.I3*rhs.e23;
    result.e2 = -lhs.I3*rhs.e31;
    result.e3 = -lhs.I3*rhs.e12;
    return result;
}
Multivector operator*(const Pseudoscalar3 &lhs, const Rotor3 &rhs) {
    Multivector result;
    result.v.e1 = -lhs.I3*rhs.b.e23;
    result.v.e2 = -lhs.I3*rhs.b.e31;
    result.v.e3 = -lhs.I3*rhs.b.e12;
    result.t.e123 = lhs.I3*rhs.s;
    return result;
}
Versor operator*(const Pseudoscalar3 &lhs, const Vector &rhs) {
    Versor result;
    result.b.e23 = lhs.I3*rhs.e1;
    result.b.e31 = lhs.I3*rhs.e2;
    result.b.e12 = lhs.I3*rhs.e3;
    result.q.e123o = 1.0*lhs.I3*rhs.eo;
    result.q.e123i = 1.0*lhs.I3*rhs.ei;
    return result;
}
Multivector operator*(const Pseudoscalar3 &lhs, const Quadvector &rhs) {
    Multivector result;
    result.v.eo = -1.0*lhs.I3*rhs.e123o;
    result.v.ei = -1.0*lhs.I3*rhs.e123i;
    result.t.e1oi = -1.0*lhs.I3*rhs.e23oi;
    result.t.e2oi = -1.0*lhs.I3*rhs.e31oi;
    result.t.e3oi = -1.0*lhs.I3*rhs.e12oi;
    return result;
}
Multivector operator*(const Pseudoscalar3 &lhs, const Bivector &rhs) {
    Multivector result;
    result.v.e1 = -lhs.I3*rhs.e23;
    result.v.e2 = -lhs.I3*rhs.e31;
    result.v.e3 = -lhs.I3*rhs.e12;
    result.t.e23o = 1.0*lhs.I3*rhs.e1o;
    result.t.e31o = 1.0*lhs.I3*rhs.e2o;
    result.t.e12o = 1.0*lhs.I3*rhs.e3o;
    result.t.e23i = 1.0*lhs.I3*rhs.e1i;
    result.t.e31i = 1.0*lhs.I3*rhs.e2i;
    result.t.e12i = 1.0*lhs.I3*rhs.e3i;
    result.I5 = 1.0*lhs.I3*rhs.eoi;
    return result;
}
Versor operator*(const Pseudoscalar3 &lhs, const Trivector &rhs) {
    Versor result;
    result.s = -lhs.I3*rhs.e123;
    result.b.e1o = -1.0*lhs.I3*rhs.e23o;
    result.b.e2o = -1.0*lhs.I3*rhs.e31o;
    result.b.e3o = -1.0*lhs.I3*rhs.e12o;
    result.b.e1i = -1.0*lhs.I3*rhs.e23i;
    result.b.e2i = -1.0*lhs.I3*rhs.e31i;
    result.b.e3i = -1.0*lhs.I3*rhs.e12i;
    result.q.e23oi = 1.0*lhs.I3*rhs.e1oi;
    result.q.e31oi = 1.0*lhs.I3*rhs.e2oi;
    result.q.e12oi = 1.0*lhs.I3*rhs.e3oi;
    return result;
}
Multivector operator*(const Pseudoscalar3 &lhs, const Rotor &rhs) {
    Multivector result;
    result.v.e1 = -lhs.I3*rhs.b.e23;
    result.v.e2 = -lhs.I3*rhs.b.e31;
    result.v.e3 = -lhs.I3*rhs.b.e12;
    result.t.e123 = lhs.I3*rhs.s;
    result.t.e23o = 1.0*lhs.I3*rhs.b.e1o;
    result.t.e31o = 1.0*lhs.I3*rhs.b.e2o;
    result.t.e12o = 1.0*lhs.I3*rhs.b.e3o;
    result.t.e23i = 1.0*lhs.I3*rhs.b.e1i;
    result.t.e31i = 1.0*lhs.I3*rhs.b.e2i;
    result.t.e12i = 1.0*lhs.I3*rhs.b.e3i;
    result.I5 = 1.0*lhs.I3*rhs.b.eoi;
    return result;
}
Multivector operator*(const Pseudoscalar3 &lhs, const Versor &rhs) {
    Multivector result;
    result.v.e1 = -lhs.I3*rhs.b.e23;
    result.v.e2 = -lhs.I3*rhs.b.e31;
    result.v.e3 = -lhs.I3*rhs.b.e12;
    result.v.eo = -1.0*lhs.I3*rhs.q.e123o;
    result.v.ei = -1.0*lhs.I3*rhs.q.e123i;
    result.t.e123 = lhs.I3*rhs.s;
    result.t.e23o = 1.0*lhs.I3*rhs.b.e1o;
    result.t.e31o = 1.0*lhs.I3*rhs.b.e2o;
    result.t.e12o = 1.0*lhs.I3*rhs.b.e3o;
    result.t.e23i = 1.0*lhs.I3*rhs.b.e1i;
    result.t.e31i = 1.0*lhs.I3*rhs.b.e2i;
    result.t.e12i = 1.0*lhs.I3*rhs.b.e3i;
    result.t.e1oi = -1.0*lhs.I3*rhs.q.e23oi;
    result.t.e2oi = -1.0*lhs.I3*rhs.q.e31oi;
    result.t.e3oi = -1.0*lhs.I3*rhs.q.e12oi;
    result.I5 = 1.0*lhs.I3*rhs.b.eoi;
    return result;
}
Multivector operator*(const Pseudoscalar3 &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -lhs.I3*rhs.t.e123;
    result.v.e1 = -lhs.I3*rhs.b.e23;
    result.v.e2 = -lhs.I3*rhs.b.e31;
    result.v.e3 = -lhs.I3*rhs.b.e12;
    result.v.eo = -1.0*lhs.I3*rhs.q.e123o;
    result.v.ei = -1.0*lhs.I3*rhs.q.e123i;
    result.b.e23 = lhs.I3*rhs.v.e1;
    result.b.e31 = lhs.I3*rhs.v.e2;
    result.b.e12 = lhs.I3*rhs.v.e3;
    result.b.e1o = -1.0*lhs.I3*rhs.t.e23o;
    result.b.e2o = -1.0*lhs.I3*rhs.t.e31o;
    result.b.e3o = -1.0*lhs.I3*rhs.t.e12o;
    result.b.e1i = -1.0*lhs.I3*rhs.t.e23i;
    result.b.e2i = -1.0*lhs.I3*rhs.t.e31i;
    result.b.e3i = -1.0*lhs.I3*rhs.t.e12i;
    result.b.eoi = -1.0*lhs.I3*rhs.I5;
    result.t.e123 = lhs.I3*rhs.s;
    result.t.e23o = 1.0*lhs.I3*rhs.b.e1o;
    result.t.e31o = 1.0*lhs.I3*rhs.b.e2o;
    result.t.e12o = 1.0*lhs.I3*rhs.b.e3o;
    result.t.e23i = 1.0*lhs.I3*rhs.b.e1i;
    result.t.e31i = 1.0*lhs.I3*rhs.b.e2i;
    result.t.e12i = 1.0*lhs.I3*rhs.b.e3i;
    result.t.e1oi = -1.0*lhs.I3*rhs.q.e23oi;
    result.t.e2oi = -1.0*lhs.I3*rhs.q.e31oi;
    result.t.e3oi = -1.0*lhs.I3*rhs.q.e12oi;
    result.q.e123o = 1.0*lhs.I3*rhs.v.eo;
    result.q.e123i = 1.0*lhs.I3*rhs.v.ei;
    result.q.e23oi = 1.0*lhs.I3*rhs.t.e1oi;
    result.q.e31oi = 1.0*lhs.I3*rhs.t.e2oi;
    result.q.e12oi = 1.0*lhs.I3*rhs.t.e3oi;
    result.I5 = 1.0*lhs.I3*rhs.b.eoi;
    return result;
}
double operator*(const Pseudoscalar &lhs, const Pseudoscalar &rhs) {
    double result;
    result = -1.0*lhs.I5*rhs.I5;
    return result;
}
Quadvector operator*(const Pseudoscalar &lhs, const Vector3 &rhs) {
    Quadvector result;
    result.e23oi = 1.0*lhs.I5*rhs.e1;
    result.e31oi = 1.0*lhs.I5*rhs.e2;
    result.e12oi = 1.0*lhs.I5*rhs.e3;
    return result;
}
Trivector operator*(const Pseudoscalar &lhs, const Bivector3 &rhs) {
    Trivector result;
    result.e1oi = -1.0*lhs.I5*rhs.e23;
    result.e2oi = -1.0*lhs.I5*rhs.e31;
    result.e3oi = -1.0*lhs.I5*rhs.e12;
    return result;
}
Multivector operator*(const Pseudoscalar &lhs, const Rotor3 &rhs) {
    Multivector result;
    result.t.e1oi = -1.0*lhs.I5*rhs.b.e23;
    result.t.e2oi = -1.0*lhs.I5*rhs.b.e31;
    result.t.e3oi = -1.0*lhs.I5*rhs.b.e12;
    result.I5 = 1.0*lhs.I5*rhs.s;
    return result;
}
Quadvector operator*(const Pseudoscalar &lhs, const Vector &rhs) {
    Quadvector result;
    result.e123o = -1.0*lhs.I5*rhs.eo;
    result.e123i = 1.0*lhs.I5*rhs.ei;
    result.e23oi = 1.0*lhs.I5*rhs.e1;
    result.e31oi = 1.0*lhs.I5*rhs.e2;
    result.e12oi = 1.0*lhs.I5*rhs.e3;
    return result;
}
Vector operator*(const Pseudoscalar &lhs, const Quadvector &rhs) {
    Vector result;
    result.e1 = -1.0*lhs.I5*rhs.e23oi;
    result.e2 = -1.0*lhs.I5*rhs.e31oi;
    result.e3 = -1.0*lhs.I5*rhs.e12oi;
    result.eo = 1.0*lhs.I5*rhs.e123o;
    result.ei = -1.0*lhs.I5*rhs.e123i;
    return result;
}
Trivector operator*(const Pseudoscalar &lhs, const Bivector &rhs) {
    Trivector result;
    result.e123 = 1.0*lhs.I5*rhs.eoi;
    result.e23o = -1.0*lhs.I5*rhs.e1o;
    result.e31o = -1.0*lhs.I5*rhs.e2o;
    result.e12o = -1.0*lhs.I5*rhs.e3o;
    result.e23i = 1.0*lhs.I5*rhs.e1i;
    result.e31i = 1.0*lhs.I5*rhs.e2i;
    result.e12i = 1.0*lhs.I5*rhs.e3i;
    result.e1oi = -1.0*lhs.I5*rhs.e23;
    result.e2oi = -1.0*lhs.I5*rhs.e31;
    result.e3oi = -1.0*lhs.I5*rhs.e12;
    return result;
}
Bivector operator*(const Pseudoscalar &lhs, const Trivector &rhs) {
    Bivector result;
    result.e23 = 1.0*lhs.I5*rhs.e1oi;
    result.e31 = 1.0*lhs.I5*rhs.e2oi;
    result.e12 = 1.0*lhs.I5*rhs.e3oi;
    result.e1o = 1.0*lhs.I5*rhs.e23o;
    result.e2o = 1.0*lhs.I5*rhs.e31o;
    result.e3o = 1.0*lhs.I5*rhs.e12o;
    result.e1i = -1.0*lhs.I5*rhs.e23i;
    result.e2i = -1.0*lhs.I5*rhs.e31i;
    result.e3i = -1.0*lhs.I5*rhs.e12i;
    result.eoi = -1.0*lhs.I5*rhs.e123;
    return result;
}
Multivector operator*(const Pseudoscalar &lhs, const Rotor &rhs) {
    Multivector result;
    result.t.e123 = 1.0*lhs.I5*rhs.b.eoi;
    result.t.e23o = -1.0*lhs.I5*rhs.b.e1o;
    result.t.e31o = -1.0*lhs.I5*rhs.b.e2o;
    result.t.e12o = -1.0*lhs.I5*rhs.b.e3o;
    result.t.e23i = 1.0*lhs.I5*rhs.b.e1i;
    result.t.e31i = 1.0*lhs.I5*rhs.b.e2i;
    result.t.e12i = 1.0*lhs.I5*rhs.b.e3i;
    result.t.e1oi = -1.0*lhs.I5*rhs.b.e23;
    result.t.e2oi = -1.0*lhs.I5*rhs.b.e31;
    result.t.e3oi = -1.0*lhs.I5*rhs.b.e12;
    result.I5 = 1.0*lhs.I5*rhs.s;
    return result;
}
Multivector operator*(const Pseudoscalar &lhs, const Versor &rhs) {
    Multivector result;
    result.v.e1 = -1.0*lhs.I5*rhs.q.e23oi;
    result.v.e2 = -1.0*lhs.I5*rhs.q.e31oi;
    result.v.e3 = -1.0*lhs.I5*rhs.q.e12oi;
    result.v.eo = 1.0*lhs.I5*rhs.q.e123o;
    result.v.ei = -1.0*lhs.I5*rhs.q.e123i;
    result.t.e123 = 1.0*lhs.I5*rhs.b.eoi;
    result.t.e23o = -1.0*lhs.I5*rhs.b.e1o;
    result.t.e31o = -1.0*lhs.I5*rhs.b.e2o;
    result.t.e12o = -1.0*lhs.I5*rhs.b.e3o;
    result.t.e23i = 1.0*lhs.I5*rhs.b.e1i;
    result.t.e31i = 1.0*lhs.I5*rhs.b.e2i;
    result.t.e12i = 1.0*lhs.I5*rhs.b.e3i;
    result.t.e1oi = -1.0*lhs.I5*rhs.b.e23;
    result.t.e2oi = -1.0*lhs.I5*rhs.b.e31;
    result.t.e3oi = -1.0*lhs.I5*rhs.b.e12;
    result.I5 = 1.0*lhs.I5*rhs.s;
    return result;
}
Multivector operator*(const Pseudoscalar &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.I5*rhs.I5;
    result.v.e1 = -1.0*lhs.I5*rhs.q.e23oi;
    result.v.e2 = -1.0*lhs.I5*rhs.q.e31oi;
    result.v.e3 = -1.0*lhs.I5*rhs.q.e12oi;
    result.v.eo = 1.0*lhs.I5*rhs.q.e123o;
    result.v.ei = -1.0*lhs.I5*rhs.q.e123i;
    result.b.e23 = 1.0*lhs.I5*rhs.t.e1oi;
    result.b.e31 = 1.0*lhs.I5*rhs.t.e2oi;
    result.b.e12 = 1.0*lhs.I5*rhs.t.e3oi;
    result.b.e1o = 1.0*lhs.I5*rhs.t.e23o;
    result.b.e2o = 1.0*lhs.I5*rhs.t.e31o;
    result.b.e3o = 1.0*lhs.I5*rhs.t.e12o;
    result.b.e1i = -1.0*lhs.I5*rhs.t.e23i;
    result.b.e2i = -1.0*lhs.I5*rhs.t.e31i;
    result.b.e3i = -1.0*lhs.I5*rhs.t.e12i;
    result.b.eoi = -1.0*lhs.I5*rhs.t.e123;
    result.t.e123 = 1.0*lhs.I5*rhs.b.eoi;
    result.t.e23o = -1.0*lhs.I5*rhs.b.e1o;
    result.t.e31o = -1.0*lhs.I5*rhs.b.e2o;
    result.t.e12o = -1.0*lhs.I5*rhs.b.e3o;
    result.t.e23i = 1.0*lhs.I5*rhs.b.e1i;
    result.t.e31i = 1.0*lhs.I5*rhs.b.e2i;
    result.t.e12i = 1.0*lhs.I5*rhs.b.e3i;
    result.t.e1oi = -1.0*lhs.I5*rhs.b.e23;
    result.t.e2oi = -1.0*lhs.I5*rhs.b.e31;
    result.t.e3oi = -1.0*lhs.I5*rhs.b.e12;
    result.q.e123o = -1.0*lhs.I5*rhs.v.eo;
    result.q.e123i = 1.0*lhs.I5*rhs.v.ei;
    result.q.e23oi = 1.0*lhs.I5*rhs.v.e1;
    result.q.e31oi = 1.0*lhs.I5*rhs.v.e2;
    result.q.e12oi = 1.0*lhs.I5*rhs.v.e3;
    result.I5 = 1.0*lhs.I5*rhs.s;
    return result;
}
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
Rotor operator*(const Vector3 &lhs, const Vector &rhs) {
    Rotor result;
    result.s = lhs.e1*rhs.e1 + lhs.e2*rhs.e2 + lhs.e3*rhs.e3;
    result.b.e23 = lhs.e2*rhs.e3 - lhs.e3*rhs.e2;
    result.b.e31 = -lhs.e1*rhs.e3 + lhs.e3*rhs.e1;
    result.b.e12 = lhs.e1*rhs.e2 - lhs.e2*rhs.e1;
    result.b.e1o = 1.0*lhs.e1*rhs.eo;
    result.b.e2o = 1.0*lhs.e2*rhs.eo;
    result.b.e3o = 1.0*lhs.e3*rhs.eo;
    result.b.e1i = 1.0*lhs.e1*rhs.ei;
    result.b.e2i = 1.0*lhs.e2*rhs.ei;
    result.b.e3i = 1.0*lhs.e3*rhs.ei;
    return result;
}
Multivector operator*(const Vector3 &lhs, const Quadvector &rhs) {
    Multivector result;
    result.t.e23o = 1.0*lhs.e1*rhs.e123o;
    result.t.e31o = 1.0*lhs.e2*rhs.e123o;
    result.t.e12o = 1.0*lhs.e3*rhs.e123o;
    result.t.e23i = 1.0*lhs.e1*rhs.e123i;
    result.t.e31i = 1.0*lhs.e2*rhs.e123i;
    result.t.e12i = 1.0*lhs.e3*rhs.e123i;
    result.t.e1oi = -1.0*lhs.e2*rhs.e12oi + 1.0*lhs.e3*rhs.e31oi;
    result.t.e2oi = 1.0*lhs.e1*rhs.e12oi - 1.0*lhs.e3*rhs.e23oi;
    result.t.e3oi = -1.0*lhs.e1*rhs.e31oi + 1.0*lhs.e2*rhs.e23oi;
    result.I5 = 1.0*lhs.e1*rhs.e23oi + 1.0*lhs.e2*rhs.e31oi + 1.0*lhs.e3*rhs.e12oi;
    return result;
}
Multivector operator*(const Vector3 &lhs, const Bivector &rhs) {
    Multivector result;
    result.v.e1 = -lhs.e2*rhs.e12 + lhs.e3*rhs.e31;
    result.v.e2 = lhs.e1*rhs.e12 - lhs.e3*rhs.e23;
    result.v.e3 = -lhs.e1*rhs.e31 + lhs.e2*rhs.e23;
    result.v.eo = 1.0*lhs.e1*rhs.e1o + 1.0*lhs.e2*rhs.e2o + 1.0*lhs.e3*rhs.e3o;
    result.v.ei = 1.0*lhs.e1*rhs.e1i + 1.0*lhs.e2*rhs.e2i + 1.0*lhs.e3*rhs.e3i;
    result.t.e123 = lhs.e1*rhs.e23 + lhs.e2*rhs.e31 + lhs.e3*rhs.e12;
    result.t.e23o = 1.0*lhs.e2*rhs.e3o - 1.0*lhs.e3*rhs.e2o;
    result.t.e31o = -1.0*lhs.e1*rhs.e3o + 1.0*lhs.e3*rhs.e1o;
    result.t.e12o = 1.0*lhs.e1*rhs.e2o - 1.0*lhs.e2*rhs.e1o;
    result.t.e23i = 1.0*lhs.e2*rhs.e3i - 1.0*lhs.e3*rhs.e2i;
    result.t.e31i = -1.0*lhs.e1*rhs.e3i + 1.0*lhs.e3*rhs.e1i;
    result.t.e12i = 1.0*lhs.e1*rhs.e2i - 1.0*lhs.e2*rhs.e1i;
    result.t.e1oi = 1.0*lhs.e1*rhs.eoi;
    result.t.e2oi = 1.0*lhs.e2*rhs.eoi;
    result.t.e3oi = 1.0*lhs.e3*rhs.eoi;
    return result;
}
Versor operator*(const Vector3 &lhs, const Trivector &rhs) {
    Versor result;
    result.b.e23 = lhs.e1*rhs.e123;
    result.b.e31 = lhs.e2*rhs.e123;
    result.b.e12 = lhs.e3*rhs.e123;
    result.b.e1o = -1.0*lhs.e2*rhs.e12o + 1.0*lhs.e3*rhs.e31o;
    result.b.e2o = 1.0*lhs.e1*rhs.e12o - 1.0*lhs.e3*rhs.e23o;
    result.b.e3o = -1.0*lhs.e1*rhs.e31o + 1.0*lhs.e2*rhs.e23o;
    result.b.e1i = -1.0*lhs.e2*rhs.e12i + 1.0*lhs.e3*rhs.e31i;
    result.b.e2i = 1.0*lhs.e1*rhs.e12i - 1.0*lhs.e3*rhs.e23i;
    result.b.e3i = -1.0*lhs.e1*rhs.e31i + 1.0*lhs.e2*rhs.e23i;
    result.b.eoi = 1.0*lhs.e1*rhs.e1oi + 1.0*lhs.e2*rhs.e2oi + 1.0*lhs.e3*rhs.e3oi;
    result.q.e123o = 1.0*lhs.e1*rhs.e23o + 1.0*lhs.e2*rhs.e31o + 1.0*lhs.e3*rhs.e12o;
    result.q.e123i = 1.0*lhs.e1*rhs.e23i + 1.0*lhs.e2*rhs.e31i + 1.0*lhs.e3*rhs.e12i;
    result.q.e23oi = 1.0*lhs.e2*rhs.e3oi - 1.0*lhs.e3*rhs.e2oi;
    result.q.e31oi = -1.0*lhs.e1*rhs.e3oi + 1.0*lhs.e3*rhs.e1oi;
    result.q.e12oi = 1.0*lhs.e1*rhs.e2oi - 1.0*lhs.e2*rhs.e1oi;
    return result;
}
Multivector operator*(const Vector3 &lhs, const Rotor &rhs) {
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s - lhs.e2*rhs.b.e12 + lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12 + lhs.e2*rhs.s - lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31 + lhs.e2*rhs.b.e23 + lhs.e3*rhs.s;
    result.v.eo = 1.0*lhs.e1*rhs.b.e1o + 1.0*lhs.e2*rhs.b.e2o + 1.0*lhs.e3*rhs.b.e3o;
    result.v.ei = 1.0*lhs.e1*rhs.b.e1i + 1.0*lhs.e2*rhs.b.e2i + 1.0*lhs.e3*rhs.b.e3i;
    result.t.e123 = lhs.e1*rhs.b.e23 + lhs.e2*rhs.b.e31 + lhs.e3*rhs.b.e12;
    result.t.e23o = 1.0*lhs.e2*rhs.b.e3o - 1.0*lhs.e3*rhs.b.e2o;
    result.t.e31o = -1.0*lhs.e1*rhs.b.e3o + 1.0*lhs.e3*rhs.b.e1o;
    result.t.e12o = 1.0*lhs.e1*rhs.b.e2o - 1.0*lhs.e2*rhs.b.e1o;
    result.t.e23i = 1.0*lhs.e2*rhs.b.e3i - 1.0*lhs.e3*rhs.b.e2i;
    result.t.e31i = -1.0*lhs.e1*rhs.b.e3i + 1.0*lhs.e3*rhs.b.e1i;
    result.t.e12i = 1.0*lhs.e1*rhs.b.e2i - 1.0*lhs.e2*rhs.b.e1i;
    result.t.e1oi = 1.0*lhs.e1*rhs.b.eoi;
    result.t.e2oi = 1.0*lhs.e2*rhs.b.eoi;
    result.t.e3oi = 1.0*lhs.e3*rhs.b.eoi;
    return result;
}
Multivector operator*(const Vector3 &lhs, const Versor &rhs) {
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s - lhs.e2*rhs.b.e12 + lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12 + lhs.e2*rhs.s - lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31 + lhs.e2*rhs.b.e23 + lhs.e3*rhs.s;
    result.v.eo = 1.0*lhs.e1*rhs.b.e1o + 1.0*lhs.e2*rhs.b.e2o + 1.0*lhs.e3*rhs.b.e3o;
    result.v.ei = 1.0*lhs.e1*rhs.b.e1i + 1.0*lhs.e2*rhs.b.e2i + 1.0*lhs.e3*rhs.b.e3i;
    result.t.e123 = lhs.e1*rhs.b.e23 + lhs.e2*rhs.b.e31 + lhs.e3*rhs.b.e12;
    result.t.e23o = 1.0*lhs.e1*rhs.q.e123o + 1.0*lhs.e2*rhs.b.e3o - 1.0*lhs.e3*rhs.b.e2o;
    result.t.e31o = -1.0*lhs.e1*rhs.b.e3o + 1.0*lhs.e2*rhs.q.e123o + 1.0*lhs.e3*rhs.b.e1o;
    result.t.e12o = 1.0*lhs.e1*rhs.b.e2o - 1.0*lhs.e2*rhs.b.e1o + 1.0*lhs.e3*rhs.q.e123o;
    result.t.e23i = 1.0*lhs.e1*rhs.q.e123i + 1.0*lhs.e2*rhs.b.e3i - 1.0*lhs.e3*rhs.b.e2i;
    result.t.e31i = -1.0*lhs.e1*rhs.b.e3i + 1.0*lhs.e2*rhs.q.e123i + 1.0*lhs.e3*rhs.b.e1i;
    result.t.e12i = 1.0*lhs.e1*rhs.b.e2i - 1.0*lhs.e2*rhs.b.e1i + 1.0*lhs.e3*rhs.q.e123i;
    result.t.e1oi = 1.0*lhs.e1*rhs.b.eoi - 1.0*lhs.e2*rhs.q.e12oi + 1.0*lhs.e3*rhs.q.e31oi;
    result.t.e2oi = 1.0*lhs.e1*rhs.q.e12oi + 1.0*lhs.e2*rhs.b.eoi - 1.0*lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -1.0*lhs.e1*rhs.q.e31oi + 1.0*lhs.e2*rhs.q.e23oi + 1.0*lhs.e3*rhs.b.eoi;
    result.I5 = 1.0*lhs.e1*rhs.q.e23oi + 1.0*lhs.e2*rhs.q.e31oi + 1.0*lhs.e3*rhs.q.e12oi;
    return result;
}
Multivector operator*(const Vector3 &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = lhs.e1*rhs.v.e1 + lhs.e2*rhs.v.e2 + lhs.e3*rhs.v.e3;
    result.v.e1 = lhs.e1*rhs.s - lhs.e2*rhs.b.e12 + lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12 + lhs.e2*rhs.s - lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31 + lhs.e2*rhs.b.e23 + lhs.e3*rhs.s;
    result.v.eo = 1.0*lhs.e1*rhs.b.e1o + 1.0*lhs.e2*rhs.b.e2o + 1.0*lhs.e3*rhs.b.e3o;
    result.v.ei = 1.0*lhs.e1*rhs.b.e1i + 1.0*lhs.e2*rhs.b.e2i + 1.0*lhs.e3*rhs.b.e3i;
    result.b.e23 = lhs.e1*rhs.t.e123 + lhs.e2*rhs.v.e3 - lhs.e3*rhs.v.e2;
    result.b.e31 = -lhs.e1*rhs.v.e3 + lhs.e2*rhs.t.e123 + lhs.e3*rhs.v.e1;
    result.b.e12 = lhs.e1*rhs.v.e2 - lhs.e2*rhs.v.e1 + lhs.e3*rhs.t.e123;
    result.b.e1o = 1.0*lhs.e1*rhs.v.eo - 1.0*lhs.e2*rhs.t.e12o + 1.0*lhs.e3*rhs.t.e31o;
    result.b.e2o = 1.0*lhs.e1*rhs.t.e12o + 1.0*lhs.e2*rhs.v.eo - 1.0*lhs.e3*rhs.t.e23o;
    result.b.e3o = -1.0*lhs.e1*rhs.t.e31o + 1.0*lhs.e2*rhs.t.e23o + 1.0*lhs.e3*rhs.v.eo;
    result.b.e1i = 1.0*lhs.e1*rhs.v.ei - 1.0*lhs.e2*rhs.t.e12i + 1.0*lhs.e3*rhs.t.e31i;
    result.b.e2i = 1.0*lhs.e1*rhs.t.e12i + 1.0*lhs.e2*rhs.v.ei - 1.0*lhs.e3*rhs.t.e23i;
    result.b.e3i = -1.0*lhs.e1*rhs.t.e31i + 1.0*lhs.e2*rhs.t.e23i + 1.0*lhs.e3*rhs.v.ei;
    result.b.eoi = 1.0*lhs.e1*rhs.t.e1oi + 1.0*lhs.e2*rhs.t.e2oi + 1.0*lhs.e3*rhs.t.e3oi;
    result.t.e123 = lhs.e1*rhs.b.e23 + lhs.e2*rhs.b.e31 + lhs.e3*rhs.b.e12;
    result.t.e23o = 1.0*lhs.e1*rhs.q.e123o + 1.0*lhs.e2*rhs.b.e3o - 1.0*lhs.e3*rhs.b.e2o;
    result.t.e31o = -1.0*lhs.e1*rhs.b.e3o + 1.0*lhs.e2*rhs.q.e123o + 1.0*lhs.e3*rhs.b.e1o;
    result.t.e12o = 1.0*lhs.e1*rhs.b.e2o - 1.0*lhs.e2*rhs.b.e1o + 1.0*lhs.e3*rhs.q.e123o;
    result.t.e23i = 1.0*lhs.e1*rhs.q.e123i + 1.0*lhs.e2*rhs.b.e3i - 1.0*lhs.e3*rhs.b.e2i;
    result.t.e31i = -1.0*lhs.e1*rhs.b.e3i + 1.0*lhs.e2*rhs.q.e123i + 1.0*lhs.e3*rhs.b.e1i;
    result.t.e12i = 1.0*lhs.e1*rhs.b.e2i - 1.0*lhs.e2*rhs.b.e1i + 1.0*lhs.e3*rhs.q.e123i;
    result.t.e1oi = 1.0*lhs.e1*rhs.b.eoi - 1.0*lhs.e2*rhs.q.e12oi + 1.0*lhs.e3*rhs.q.e31oi;
    result.t.e2oi = 1.0*lhs.e1*rhs.q.e12oi + 1.0*lhs.e2*rhs.b.eoi - 1.0*lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -1.0*lhs.e1*rhs.q.e31oi + 1.0*lhs.e2*rhs.q.e23oi + 1.0*lhs.e3*rhs.b.eoi;
    result.q.e123o = 1.0*lhs.e1*rhs.t.e23o + 1.0*lhs.e2*rhs.t.e31o + 1.0*lhs.e3*rhs.t.e12o;
    result.q.e123i = 1.0*lhs.e1*rhs.t.e23i + 1.0*lhs.e2*rhs.t.e31i + 1.0*lhs.e3*rhs.t.e12i;
    result.q.e23oi = 1.0*lhs.e1*rhs.I5 + 1.0*lhs.e2*rhs.t.e3oi - 1.0*lhs.e3*rhs.t.e2oi;
    result.q.e31oi = -1.0*lhs.e1*rhs.t.e3oi + 1.0*lhs.e2*rhs.I5 + 1.0*lhs.e3*rhs.t.e1oi;
    result.q.e12oi = 1.0*lhs.e1*rhs.t.e2oi - 1.0*lhs.e2*rhs.t.e1oi + 1.0*lhs.e3*rhs.I5;
    result.I5 = 1.0*lhs.e1*rhs.q.e23oi + 1.0*lhs.e2*rhs.q.e31oi + 1.0*lhs.e3*rhs.q.e12oi;
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
Multivector operator*(const Bivector3 &lhs, const Vector &rhs) {
    Multivector result;
    result.v.e1 = lhs.e12*rhs.e2 - lhs.e31*rhs.e3;
    result.v.e2 = -lhs.e12*rhs.e1 + lhs.e23*rhs.e3;
    result.v.e3 = -lhs.e23*rhs.e2 + lhs.e31*rhs.e1;
    result.t.e123 = lhs.e12*rhs.e3 + lhs.e23*rhs.e1 + lhs.e31*rhs.e2;
    result.t.e23o = 1.0*lhs.e23*rhs.eo;
    result.t.e31o = 1.0*lhs.e31*rhs.eo;
    result.t.e12o = 1.0*lhs.e12*rhs.eo;
    result.t.e23i = 1.0*lhs.e23*rhs.ei;
    result.t.e31i = 1.0*lhs.e31*rhs.ei;
    result.t.e12i = 1.0*lhs.e12*rhs.ei;
    return result;
}
Versor operator*(const Bivector3 &lhs, const Quadvector &rhs) {
    Versor result;
    result.b.e1o = -1.0*lhs.e23*rhs.e123o;
    result.b.e2o = -1.0*lhs.e31*rhs.e123o;
    result.b.e3o = -1.0*lhs.e12*rhs.e123o;
    result.b.e1i = -1.0*lhs.e23*rhs.e123i;
    result.b.e2i = -1.0*lhs.e31*rhs.e123i;
    result.b.e3i = -1.0*lhs.e12*rhs.e123i;
    result.b.eoi = -1.0*lhs.e12*rhs.e12oi - 1.0*lhs.e23*rhs.e23oi - 1.0*lhs.e31*rhs.e31oi;
    result.q.e23oi = 1.0*lhs.e12*rhs.e31oi - 1.0*lhs.e31*rhs.e12oi;
    result.q.e31oi = -1.0*lhs.e12*rhs.e23oi + 1.0*lhs.e23*rhs.e12oi;
    result.q.e12oi = -1.0*lhs.e23*rhs.e31oi + 1.0*lhs.e31*rhs.e23oi;
    return result;
}
Versor operator*(const Bivector3 &lhs, const Bivector &rhs) {
    Versor result;
    result.s = -lhs.e12*rhs.e12 - lhs.e23*rhs.e23 - lhs.e31*rhs.e31;
    result.b.e23 = lhs.e12*rhs.e31 - lhs.e31*rhs.e12;
    result.b.e31 = -lhs.e12*rhs.e23 + lhs.e23*rhs.e12;
    result.b.e12 = -lhs.e23*rhs.e31 + lhs.e31*rhs.e23;
    result.b.e1o = 1.0*lhs.e12*rhs.e2o - 1.0*lhs.e31*rhs.e3o;
    result.b.e2o = -1.0*lhs.e12*rhs.e1o + 1.0*lhs.e23*rhs.e3o;
    result.b.e3o = -1.0*lhs.e23*rhs.e2o + 1.0*lhs.e31*rhs.e1o;
    result.b.e1i = 1.0*lhs.e12*rhs.e2i - 1.0*lhs.e31*rhs.e3i;
    result.b.e2i = -1.0*lhs.e12*rhs.e1i + 1.0*lhs.e23*rhs.e3i;
    result.b.e3i = -1.0*lhs.e23*rhs.e2i + 1.0*lhs.e31*rhs.e1i;
    result.q.e123o = 1.0*lhs.e12*rhs.e3o + 1.0*lhs.e23*rhs.e1o + 1.0*lhs.e31*rhs.e2o;
    result.q.e123i = 1.0*lhs.e12*rhs.e3i + 1.0*lhs.e23*rhs.e1i + 1.0*lhs.e31*rhs.e2i;
    result.q.e23oi = 1.0*lhs.e23*rhs.eoi;
    result.q.e31oi = 1.0*lhs.e31*rhs.eoi;
    result.q.e12oi = 1.0*lhs.e12*rhs.eoi;
    return result;
}
Multivector operator*(const Bivector3 &lhs, const Trivector &rhs) {
    Multivector result;
    result.v.e1 = -lhs.e23*rhs.e123;
    result.v.e2 = -lhs.e31*rhs.e123;
    result.v.e3 = -lhs.e12*rhs.e123;
    result.v.eo = -1.0*lhs.e12*rhs.e12o - 1.0*lhs.e23*rhs.e23o - 1.0*lhs.e31*rhs.e31o;
    result.v.ei = -1.0*lhs.e12*rhs.e12i - 1.0*lhs.e23*rhs.e23i - 1.0*lhs.e31*rhs.e31i;
    result.t.e23o = 1.0*lhs.e12*rhs.e31o - 1.0*lhs.e31*rhs.e12o;
    result.t.e31o = -1.0*lhs.e12*rhs.e23o + 1.0*lhs.e23*rhs.e12o;
    result.t.e12o = -1.0*lhs.e23*rhs.e31o + 1.0*lhs.e31*rhs.e23o;
    result.t.e23i = 1.0*lhs.e12*rhs.e31i - 1.0*lhs.e31*rhs.e12i;
    result.t.e31i = -1.0*lhs.e12*rhs.e23i + 1.0*lhs.e23*rhs.e12i;
    result.t.e12i = -1.0*lhs.e23*rhs.e31i + 1.0*lhs.e31*rhs.e23i;
    result.t.e1oi = 1.0*lhs.e12*rhs.e2oi - 1.0*lhs.e31*rhs.e3oi;
    result.t.e2oi = -1.0*lhs.e12*rhs.e1oi + 1.0*lhs.e23*rhs.e3oi;
    result.t.e3oi = -1.0*lhs.e23*rhs.e2oi + 1.0*lhs.e31*rhs.e1oi;
    result.I5 = 1.0*lhs.e12*rhs.e3oi + 1.0*lhs.e23*rhs.e1oi + 1.0*lhs.e31*rhs.e2oi;
    return result;
}
Versor operator*(const Bivector3 &lhs, const Rotor &rhs) {
    Versor result;
    result.s = -lhs.e12*rhs.b.e12 - lhs.e23*rhs.b.e23 - lhs.e31*rhs.b.e31;
    result.b.e23 = lhs.e12*rhs.b.e31 + lhs.e23*rhs.s - lhs.e31*rhs.b.e12;
    result.b.e31 = -lhs.e12*rhs.b.e23 + lhs.e23*rhs.b.e12 + lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s - lhs.e23*rhs.b.e31 + lhs.e31*rhs.b.e23;
    result.b.e1o = 1.0*lhs.e12*rhs.b.e2o - 1.0*lhs.e31*rhs.b.e3o;
    result.b.e2o = -1.0*lhs.e12*rhs.b.e1o + 1.0*lhs.e23*rhs.b.e3o;
    result.b.e3o = -1.0*lhs.e23*rhs.b.e2o + 1.0*lhs.e31*rhs.b.e1o;
    result.b.e1i = 1.0*lhs.e12*rhs.b.e2i - 1.0*lhs.e31*rhs.b.e3i;
    result.b.e2i = -1.0*lhs.e12*rhs.b.e1i + 1.0*lhs.e23*rhs.b.e3i;
    result.b.e3i = -1.0*lhs.e23*rhs.b.e2i + 1.0*lhs.e31*rhs.b.e1i;
    result.q.e123o = 1.0*lhs.e12*rhs.b.e3o + 1.0*lhs.e23*rhs.b.e1o + 1.0*lhs.e31*rhs.b.e2o;
    result.q.e123i = 1.0*lhs.e12*rhs.b.e3i + 1.0*lhs.e23*rhs.b.e1i + 1.0*lhs.e31*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.e23*rhs.b.eoi;
    result.q.e31oi = 1.0*lhs.e31*rhs.b.eoi;
    result.q.e12oi = 1.0*lhs.e12*rhs.b.eoi;
    return result;
}
Versor operator*(const Bivector3 &lhs, const Versor &rhs) {
    Versor result;
    result.s = -lhs.e12*rhs.b.e12 - lhs.e23*rhs.b.e23 - lhs.e31*rhs.b.e31;
    result.b.e23 = lhs.e12*rhs.b.e31 + lhs.e23*rhs.s - lhs.e31*rhs.b.e12;
    result.b.e31 = -lhs.e12*rhs.b.e23 + lhs.e23*rhs.b.e12 + lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s - lhs.e23*rhs.b.e31 + lhs.e31*rhs.b.e23;
    result.b.e1o = 1.0*lhs.e12*rhs.b.e2o - 1.0*lhs.e23*rhs.q.e123o - 1.0*lhs.e31*rhs.b.e3o;
    result.b.e2o = -1.0*lhs.e12*rhs.b.e1o + 1.0*lhs.e23*rhs.b.e3o - 1.0*lhs.e31*rhs.q.e123o;
    result.b.e3o = -1.0*lhs.e12*rhs.q.e123o - 1.0*lhs.e23*rhs.b.e2o + 1.0*lhs.e31*rhs.b.e1o;
    result.b.e1i = 1.0*lhs.e12*rhs.b.e2i - 1.0*lhs.e23*rhs.q.e123i - 1.0*lhs.e31*rhs.b.e3i;
    result.b.e2i = -1.0*lhs.e12*rhs.b.e1i + 1.0*lhs.e23*rhs.b.e3i - 1.0*lhs.e31*rhs.q.e123i;
    result.b.e3i = -1.0*lhs.e12*rhs.q.e123i - 1.0*lhs.e23*rhs.b.e2i + 1.0*lhs.e31*rhs.b.e1i;
    result.b.eoi = -1.0*lhs.e12*rhs.q.e12oi - 1.0*lhs.e23*rhs.q.e23oi - 1.0*lhs.e31*rhs.q.e31oi;
    result.q.e123o = 1.0*lhs.e12*rhs.b.e3o + 1.0*lhs.e23*rhs.b.e1o + 1.0*lhs.e31*rhs.b.e2o;
    result.q.e123i = 1.0*lhs.e12*rhs.b.e3i + 1.0*lhs.e23*rhs.b.e1i + 1.0*lhs.e31*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.e12*rhs.q.e31oi + 1.0*lhs.e23*rhs.b.eoi - 1.0*lhs.e31*rhs.q.e12oi;
    result.q.e31oi = -1.0*lhs.e12*rhs.q.e23oi + 1.0*lhs.e23*rhs.q.e12oi + 1.0*lhs.e31*rhs.b.eoi;
    result.q.e12oi = 1.0*lhs.e12*rhs.b.eoi - 1.0*lhs.e23*rhs.q.e31oi + 1.0*lhs.e31*rhs.q.e23oi;
    return result;
}
Multivector operator*(const Bivector3 &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -lhs.e12*rhs.b.e12 - lhs.e23*rhs.b.e23 - lhs.e31*rhs.b.e31;
    result.v.e1 = lhs.e12*rhs.v.e2 - lhs.e23*rhs.t.e123 - lhs.e31*rhs.v.e3;
    result.v.e2 = -lhs.e12*rhs.v.e1 + lhs.e23*rhs.v.e3 - lhs.e31*rhs.t.e123;
    result.v.e3 = -lhs.e12*rhs.t.e123 - lhs.e23*rhs.v.e2 + lhs.e31*rhs.v.e1;
    result.v.eo = -1.0*lhs.e12*rhs.t.e12o - 1.0*lhs.e23*rhs.t.e23o - 1.0*lhs.e31*rhs.t.e31o;
    result.v.ei = -1.0*lhs.e12*rhs.t.e12i - 1.0*lhs.e23*rhs.t.e23i - 1.0*lhs.e31*rhs.t.e31i;
    result.b.e23 = lhs.e12*rhs.b.e31 + lhs.e23*rhs.s - lhs.e31*rhs.b.e12;
    result.b.e31 = -lhs.e12*rhs.b.e23 + lhs.e23*rhs.b.e12 + lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s - lhs.e23*rhs.b.e31 + lhs.e31*rhs.b.e23;
    result.b.e1o = 1.0*lhs.e12*rhs.b.e2o - 1.0*lhs.e23*rhs.q.e123o - 1.0*lhs.e31*rhs.b.e3o;
    result.b.e2o = -1.0*lhs.e12*rhs.b.e1o + 1.0*lhs.e23*rhs.b.e3o - 1.0*lhs.e31*rhs.q.e123o;
    result.b.e3o = -1.0*lhs.e12*rhs.q.e123o - 1.0*lhs.e23*rhs.b.e2o + 1.0*lhs.e31*rhs.b.e1o;
    result.b.e1i = 1.0*lhs.e12*rhs.b.e2i - 1.0*lhs.e23*rhs.q.e123i - 1.0*lhs.e31*rhs.b.e3i;
    result.b.e2i = -1.0*lhs.e12*rhs.b.e1i + 1.0*lhs.e23*rhs.b.e3i - 1.0*lhs.e31*rhs.q.e123i;
    result.b.e3i = -1.0*lhs.e12*rhs.q.e123i - 1.0*lhs.e23*rhs.b.e2i + 1.0*lhs.e31*rhs.b.e1i;
    result.b.eoi = -1.0*lhs.e12*rhs.q.e12oi - 1.0*lhs.e23*rhs.q.e23oi - 1.0*lhs.e31*rhs.q.e31oi;
    result.t.e123 = lhs.e12*rhs.v.e3 + lhs.e23*rhs.v.e1 + lhs.e31*rhs.v.e2;
    result.t.e23o = 1.0*lhs.e12*rhs.t.e31o + 1.0*lhs.e23*rhs.v.eo - 1.0*lhs.e31*rhs.t.e12o;
    result.t.e31o = -1.0*lhs.e12*rhs.t.e23o + 1.0*lhs.e23*rhs.t.e12o + 1.0*lhs.e31*rhs.v.eo;
    result.t.e12o = 1.0*lhs.e12*rhs.v.eo - 1.0*lhs.e23*rhs.t.e31o + 1.0*lhs.e31*rhs.t.e23o;
    result.t.e23i = 1.0*lhs.e12*rhs.t.e31i + 1.0*lhs.e23*rhs.v.ei - 1.0*lhs.e31*rhs.t.e12i;
    result.t.e31i = -1.0*lhs.e12*rhs.t.e23i + 1.0*lhs.e23*rhs.t.e12i + 1.0*lhs.e31*rhs.v.ei;
    result.t.e12i = 1.0*lhs.e12*rhs.v.ei - 1.0*lhs.e23*rhs.t.e31i + 1.0*lhs.e31*rhs.t.e23i;
    result.t.e1oi = 1.0*lhs.e12*rhs.t.e2oi - 1.0*lhs.e23*rhs.I5 - 1.0*lhs.e31*rhs.t.e3oi;
    result.t.e2oi = -1.0*lhs.e12*rhs.t.e1oi + 1.0*lhs.e23*rhs.t.e3oi - 1.0*lhs.e31*rhs.I5;
    result.t.e3oi = -1.0*lhs.e12*rhs.I5 - 1.0*lhs.e23*rhs.t.e2oi + 1.0*lhs.e31*rhs.t.e1oi;
    result.q.e123o = 1.0*lhs.e12*rhs.b.e3o + 1.0*lhs.e23*rhs.b.e1o + 1.0*lhs.e31*rhs.b.e2o;
    result.q.e123i = 1.0*lhs.e12*rhs.b.e3i + 1.0*lhs.e23*rhs.b.e1i + 1.0*lhs.e31*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.e12*rhs.q.e31oi + 1.0*lhs.e23*rhs.b.eoi - 1.0*lhs.e31*rhs.q.e12oi;
    result.q.e31oi = -1.0*lhs.e12*rhs.q.e23oi + 1.0*lhs.e23*rhs.q.e12oi + 1.0*lhs.e31*rhs.b.eoi;
    result.q.e12oi = 1.0*lhs.e12*rhs.b.eoi - 1.0*lhs.e23*rhs.q.e31oi + 1.0*lhs.e31*rhs.q.e23oi;
    result.I5 = 1.0*lhs.e12*rhs.t.e3oi + 1.0*lhs.e23*rhs.t.e1oi + 1.0*lhs.e31*rhs.t.e2oi;
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
Multivector operator*(const Rotor3 &lhs, const Vector &rhs) {
    Multivector result;
    result.v.e1 = lhs.b.e12*rhs.e2 - lhs.b.e31*rhs.e3 + lhs.s*rhs.e1;
    result.v.e2 = -lhs.b.e12*rhs.e1 + lhs.b.e23*rhs.e3 + lhs.s*rhs.e2;
    result.v.e3 = -lhs.b.e23*rhs.e2 + lhs.b.e31*rhs.e1 + lhs.s*rhs.e3;
    result.v.eo = 1.0*lhs.s*rhs.eo;
    result.v.ei = 1.0*lhs.s*rhs.ei;
    result.t.e123 = lhs.b.e12*rhs.e3 + lhs.b.e23*rhs.e1 + lhs.b.e31*rhs.e2;
    result.t.e23o = 1.0*lhs.b.e23*rhs.eo;
    result.t.e31o = 1.0*lhs.b.e31*rhs.eo;
    result.t.e12o = 1.0*lhs.b.e12*rhs.eo;
    result.t.e23i = 1.0*lhs.b.e23*rhs.ei;
    result.t.e31i = 1.0*lhs.b.e31*rhs.ei;
    result.t.e12i = 1.0*lhs.b.e12*rhs.ei;
    return result;
}
Versor operator*(const Rotor3 &lhs, const Quadvector &rhs) {
    Versor result;
    result.b.e1o = -1.0*lhs.b.e23*rhs.e123o;
    result.b.e2o = -1.0*lhs.b.e31*rhs.e123o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.e123o;
    result.b.e1i = -1.0*lhs.b.e23*rhs.e123i;
    result.b.e2i = -1.0*lhs.b.e31*rhs.e123i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.e123i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.e12oi - 1.0*lhs.b.e23*rhs.e23oi - 1.0*lhs.b.e31*rhs.e31oi;
    result.q.e123o = 1.0*lhs.s*rhs.e123o;
    result.q.e123i = 1.0*lhs.s*rhs.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.e31oi - 1.0*lhs.b.e31*rhs.e12oi + 1.0*lhs.s*rhs.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.e23oi + 1.0*lhs.b.e23*rhs.e12oi + 1.0*lhs.s*rhs.e31oi;
    result.q.e12oi = -1.0*lhs.b.e23*rhs.e31oi + 1.0*lhs.b.e31*rhs.e23oi + 1.0*lhs.s*rhs.e12oi;
    return result;
}
Versor operator*(const Rotor3 &lhs, const Bivector &rhs) {
    Versor result;
    result.s = -lhs.b.e12*rhs.e12 - lhs.b.e23*rhs.e23 - lhs.b.e31*rhs.e31;
    result.b.e23 = lhs.b.e12*rhs.e31 - lhs.b.e31*rhs.e12 + lhs.s*rhs.e23;
    result.b.e31 = -lhs.b.e12*rhs.e23 + lhs.b.e23*rhs.e12 + lhs.s*rhs.e31;
    result.b.e12 = -lhs.b.e23*rhs.e31 + lhs.b.e31*rhs.e23 + lhs.s*rhs.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.e2o - 1.0*lhs.b.e31*rhs.e3o + 1.0*lhs.s*rhs.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.e1o + 1.0*lhs.b.e23*rhs.e3o + 1.0*lhs.s*rhs.e2o;
    result.b.e3o = -1.0*lhs.b.e23*rhs.e2o + 1.0*lhs.b.e31*rhs.e1o + 1.0*lhs.s*rhs.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.e2i - 1.0*lhs.b.e31*rhs.e3i + 1.0*lhs.s*rhs.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.e1i + 1.0*lhs.b.e23*rhs.e3i + 1.0*lhs.s*rhs.e2i;
    result.b.e3i = -1.0*lhs.b.e23*rhs.e2i + 1.0*lhs.b.e31*rhs.e1i + 1.0*lhs.s*rhs.e3i;
    result.b.eoi = 1.0*lhs.s*rhs.eoi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.e3o + 1.0*lhs.b.e23*rhs.e1o + 1.0*lhs.b.e31*rhs.e2o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.e3i + 1.0*lhs.b.e23*rhs.e1i + 1.0*lhs.b.e31*rhs.e2i;
    result.q.e23oi = 1.0*lhs.b.e23*rhs.eoi;
    result.q.e31oi = 1.0*lhs.b.e31*rhs.eoi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.eoi;
    return result;
}
Multivector operator*(const Rotor3 &lhs, const Trivector &rhs) {
    Multivector result;
    result.v.e1 = -lhs.b.e23*rhs.e123;
    result.v.e2 = -lhs.b.e31*rhs.e123;
    result.v.e3 = -lhs.b.e12*rhs.e123;
    result.v.eo = -1.0*lhs.b.e12*rhs.e12o - 1.0*lhs.b.e23*rhs.e23o - 1.0*lhs.b.e31*rhs.e31o;
    result.v.ei = -1.0*lhs.b.e12*rhs.e12i - 1.0*lhs.b.e23*rhs.e23i - 1.0*lhs.b.e31*rhs.e31i;
    result.t.e123 = lhs.s*rhs.e123;
    result.t.e23o = 1.0*lhs.b.e12*rhs.e31o - 1.0*lhs.b.e31*rhs.e12o + 1.0*lhs.s*rhs.e23o;
    result.t.e31o = -1.0*lhs.b.e12*rhs.e23o + 1.0*lhs.b.e23*rhs.e12o + 1.0*lhs.s*rhs.e31o;
    result.t.e12o = -1.0*lhs.b.e23*rhs.e31o + 1.0*lhs.b.e31*rhs.e23o + 1.0*lhs.s*rhs.e12o;
    result.t.e23i = 1.0*lhs.b.e12*rhs.e31i - 1.0*lhs.b.e31*rhs.e12i + 1.0*lhs.s*rhs.e23i;
    result.t.e31i = -1.0*lhs.b.e12*rhs.e23i + 1.0*lhs.b.e23*rhs.e12i + 1.0*lhs.s*rhs.e31i;
    result.t.e12i = -1.0*lhs.b.e23*rhs.e31i + 1.0*lhs.b.e31*rhs.e23i + 1.0*lhs.s*rhs.e12i;
    result.t.e1oi = 1.0*lhs.b.e12*rhs.e2oi - 1.0*lhs.b.e31*rhs.e3oi + 1.0*lhs.s*rhs.e1oi;
    result.t.e2oi = -1.0*lhs.b.e12*rhs.e1oi + 1.0*lhs.b.e23*rhs.e3oi + 1.0*lhs.s*rhs.e2oi;
    result.t.e3oi = -1.0*lhs.b.e23*rhs.e2oi + 1.0*lhs.b.e31*rhs.e1oi + 1.0*lhs.s*rhs.e3oi;
    result.I5 = 1.0*lhs.b.e12*rhs.e3oi + 1.0*lhs.b.e23*rhs.e1oi + 1.0*lhs.b.e31*rhs.e2oi;
    return result;
}
Versor operator*(const Rotor3 &lhs, const Rotor &rhs) {
    Versor result;
    result.s = -lhs.b.e12*rhs.b.e12 - lhs.b.e23*rhs.b.e23 - lhs.b.e31*rhs.b.e31 + lhs.s*rhs.s;
    result.b.e23 = lhs.b.e12*rhs.b.e31 + lhs.b.e23*rhs.s - lhs.b.e31*rhs.b.e12 + lhs.s*rhs.b.e23;
    result.b.e31 = -lhs.b.e12*rhs.b.e23 + lhs.b.e23*rhs.b.e12 + lhs.b.e31*rhs.s + lhs.s*rhs.b.e31;
    result.b.e12 = lhs.b.e12*rhs.s - lhs.b.e23*rhs.b.e31 + lhs.b.e31*rhs.b.e23 + lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e23*rhs.b.e3i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e31*rhs.b.e1i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = 1.0*lhs.s*rhs.b.eoi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e31*rhs.b.e2o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = 1.0*lhs.b.e31*rhs.b.eoi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi;
    return result;
}
Versor operator*(const Rotor3 &lhs, const Versor &rhs) {
    Versor result;
    result.s = -lhs.b.e12*rhs.b.e12 - lhs.b.e23*rhs.b.e23 - lhs.b.e31*rhs.b.e31 + lhs.s*rhs.s;
    result.b.e23 = lhs.b.e12*rhs.b.e31 + lhs.b.e23*rhs.s - lhs.b.e31*rhs.b.e12 + lhs.s*rhs.b.e23;
    result.b.e31 = -lhs.b.e12*rhs.b.e23 + lhs.b.e23*rhs.b.e12 + lhs.b.e31*rhs.s + lhs.s*rhs.b.e31;
    result.b.e12 = lhs.b.e12*rhs.s - lhs.b.e23*rhs.b.e31 + lhs.b.e31*rhs.b.e23 + lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e23*rhs.b.e3o - 1.0*lhs.b.e31*rhs.q.e123o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e123i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e31*rhs.b.e1i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.q.e12oi - 1.0*lhs.b.e23*rhs.q.e23oi - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.s*rhs.b.eoi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.s*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.s*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e23*rhs.b.eoi - 1.0*lhs.b.e31*rhs.q.e12oi + 1.0*lhs.s*rhs.q.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.s*rhs.q.e31oi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi - 1.0*lhs.b.e23*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.s*rhs.q.e12oi;
    return result;
}
Multivector operator*(const Rotor3 &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -lhs.b.e12*rhs.b.e12 - lhs.b.e23*rhs.b.e23 - lhs.b.e31*rhs.b.e31 + lhs.s*rhs.s;
    result.v.e1 = lhs.b.e12*rhs.v.e2 - lhs.b.e23*rhs.t.e123 - lhs.b.e31*rhs.v.e3 + lhs.s*rhs.v.e1;
    result.v.e2 = -lhs.b.e12*rhs.v.e1 + lhs.b.e23*rhs.v.e3 - lhs.b.e31*rhs.t.e123 + lhs.s*rhs.v.e2;
    result.v.e3 = -lhs.b.e12*rhs.t.e123 - lhs.b.e23*rhs.v.e2 + lhs.b.e31*rhs.v.e1 + lhs.s*rhs.v.e3;
    result.v.eo = -1.0*lhs.b.e12*rhs.t.e12o - 1.0*lhs.b.e23*rhs.t.e23o - 1.0*lhs.b.e31*rhs.t.e31o + 1.0*lhs.s*rhs.v.eo;
    result.v.ei = -1.0*lhs.b.e12*rhs.t.e12i - 1.0*lhs.b.e23*rhs.t.e23i - 1.0*lhs.b.e31*rhs.t.e31i + 1.0*lhs.s*rhs.v.ei;
    result.b.e23 = lhs.b.e12*rhs.b.e31 + lhs.b.e23*rhs.s - lhs.b.e31*rhs.b.e12 + lhs.s*rhs.b.e23;
    result.b.e31 = -lhs.b.e12*rhs.b.e23 + lhs.b.e23*rhs.b.e12 + lhs.b.e31*rhs.s + lhs.s*rhs.b.e31;
    result.b.e12 = lhs.b.e12*rhs.s - lhs.b.e23*rhs.b.e31 + lhs.b.e31*rhs.b.e23 + lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e23*rhs.b.e3o - 1.0*lhs.b.e31*rhs.q.e123o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e123i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e31*rhs.b.e1i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.q.e12oi - 1.0*lhs.b.e23*rhs.q.e23oi - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.s*rhs.b.eoi;
    result.t.e123 = lhs.b.e12*rhs.v.e3 + lhs.b.e23*rhs.v.e1 + lhs.b.e31*rhs.v.e2 + lhs.s*rhs.t.e123;
    result.t.e23o = 1.0*lhs.b.e12*rhs.t.e31o + 1.0*lhs.b.e23*rhs.v.eo - 1.0*lhs.b.e31*rhs.t.e12o + 1.0*lhs.s*rhs.t.e23o;
    result.t.e31o = -1.0*lhs.b.e12*rhs.t.e23o + 1.0*lhs.b.e23*rhs.t.e12o + 1.0*lhs.b.e31*rhs.v.eo + 1.0*lhs.s*rhs.t.e31o;
    result.t.e12o = 1.0*lhs.b.e12*rhs.v.eo - 1.0*lhs.b.e23*rhs.t.e31o + 1.0*lhs.b.e31*rhs.t.e23o + 1.0*lhs.s*rhs.t.e12o;
    result.t.e23i = 1.0*lhs.b.e12*rhs.t.e31i + 1.0*lhs.b.e23*rhs.v.ei - 1.0*lhs.b.e31*rhs.t.e12i + 1.0*lhs.s*rhs.t.e23i;
    result.t.e31i = -1.0*lhs.b.e12*rhs.t.e23i + 1.0*lhs.b.e23*rhs.t.e12i + 1.0*lhs.b.e31*rhs.v.ei + 1.0*lhs.s*rhs.t.e31i;
    result.t.e12i = 1.0*lhs.b.e12*rhs.v.ei - 1.0*lhs.b.e23*rhs.t.e31i + 1.0*lhs.b.e31*rhs.t.e23i + 1.0*lhs.s*rhs.t.e12i;
    result.t.e1oi = 1.0*lhs.b.e12*rhs.t.e2oi - 1.0*lhs.b.e23*rhs.I5 - 1.0*lhs.b.e31*rhs.t.e3oi + 1.0*lhs.s*rhs.t.e1oi;
    result.t.e2oi = -1.0*lhs.b.e12*rhs.t.e1oi + 1.0*lhs.b.e23*rhs.t.e3oi - 1.0*lhs.b.e31*rhs.I5 + 1.0*lhs.s*rhs.t.e2oi;
    result.t.e3oi = -1.0*lhs.b.e12*rhs.I5 - 1.0*lhs.b.e23*rhs.t.e2oi + 1.0*lhs.b.e31*rhs.t.e1oi + 1.0*lhs.s*rhs.t.e3oi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.s*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.s*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e23*rhs.b.eoi - 1.0*lhs.b.e31*rhs.q.e12oi + 1.0*lhs.s*rhs.q.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.s*rhs.q.e31oi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi - 1.0*lhs.b.e23*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.s*rhs.q.e12oi;
    result.I5 = 1.0*lhs.b.e12*rhs.t.e3oi + 1.0*lhs.b.e23*rhs.t.e1oi + 1.0*lhs.b.e31*rhs.t.e2oi + 1.0*lhs.s*rhs.I5;
    return result;
}
Rotor operator*(const Vector &lhs, const Vector &rhs) {
    Rotor result;
    result.s = 1.0*lhs.e1*rhs.e1 + 1.0*lhs.e2*rhs.e2 + 1.0*lhs.e3*rhs.e3 - 1.0*lhs.ei*rhs.eo - 1.0*lhs.eo*rhs.ei;
    result.b.e23 = lhs.e2*rhs.e3 - lhs.e3*rhs.e2;
    result.b.e31 = -lhs.e1*rhs.e3 + lhs.e3*rhs.e1;
    result.b.e12 = lhs.e1*rhs.e2 - lhs.e2*rhs.e1;
    result.b.e1o = 1.0*lhs.e1*rhs.eo - 1.0*lhs.eo*rhs.e1;
    result.b.e2o = 1.0*lhs.e2*rhs.eo - 1.0*lhs.eo*rhs.e2;
    result.b.e3o = 1.0*lhs.e3*rhs.eo - 1.0*lhs.eo*rhs.e3;
    result.b.e1i = 1.0*lhs.e1*rhs.ei - 1.0*lhs.ei*rhs.e1;
    result.b.e2i = 1.0*lhs.e2*rhs.ei - 1.0*lhs.ei*rhs.e2;
    result.b.e3i = 1.0*lhs.e3*rhs.ei - 1.0*lhs.ei*rhs.e3;
    result.b.eoi = -1.0*lhs.ei*rhs.eo + 1.0*lhs.eo*rhs.ei;
    return result;
}
Multivector operator*(const Vector &lhs, const Quadvector &rhs) {
    Multivector result;
    result.t.e123 = 1.0*lhs.ei*rhs.e123o + 1.0*lhs.eo*rhs.e123i;
    result.t.e23o = 1.0*lhs.e1*rhs.e123o + 1.0*lhs.eo*rhs.e23oi;
    result.t.e31o = 1.0*lhs.e2*rhs.e123o + 1.0*lhs.eo*rhs.e31oi;
    result.t.e12o = 1.0*lhs.e3*rhs.e123o + 1.0*lhs.eo*rhs.e12oi;
    result.t.e23i = 1.0*lhs.e1*rhs.e123i - 1.0*lhs.ei*rhs.e23oi;
    result.t.e31i = 1.0*lhs.e2*rhs.e123i - 1.0*lhs.ei*rhs.e31oi;
    result.t.e12i = 1.0*lhs.e3*rhs.e123i - 1.0*lhs.ei*rhs.e12oi;
    result.t.e1oi = -1.0*lhs.e2*rhs.e12oi + 1.0*lhs.e3*rhs.e31oi;
    result.t.e2oi = 1.0*lhs.e1*rhs.e12oi - 1.0*lhs.e3*rhs.e23oi;
    result.t.e3oi = -1.0*lhs.e1*rhs.e31oi + 1.0*lhs.e2*rhs.e23oi;
    result.I5 = 1.0*lhs.e1*rhs.e23oi + 1.0*lhs.e2*rhs.e31oi + 1.0*lhs.e3*rhs.e12oi + 1.0*lhs.ei*rhs.e123o - 1.0*lhs.eo*rhs.e123i;
    return result;
}
Multivector operator*(const Vector &lhs, const Bivector &rhs) {
    Multivector result;
    result.v.e1 = -1.0*lhs.e2*rhs.e12 + 1.0*lhs.e3*rhs.e31 + 1.0*lhs.ei*rhs.e1o + 1.0*lhs.eo*rhs.e1i;
    result.v.e2 = 1.0*lhs.e1*rhs.e12 - 1.0*lhs.e3*rhs.e23 + 1.0*lhs.ei*rhs.e2o + 1.0*lhs.eo*rhs.e2i;
    result.v.e3 = -1.0*lhs.e1*rhs.e31 + 1.0*lhs.e2*rhs.e23 + 1.0*lhs.ei*rhs.e3o + 1.0*lhs.eo*rhs.e3i;
    result.v.eo = 1.0*lhs.e1*rhs.e1o + 1.0*lhs.e2*rhs.e2o + 1.0*lhs.e3*rhs.e3o + 1.0*lhs.eo*rhs.eoi;
    result.v.ei = 1.0*lhs.e1*rhs.e1i + 1.0*lhs.e2*rhs.e2i + 1.0*lhs.e3*rhs.e3i - 1.0*lhs.ei*rhs.eoi;
    result.t.e123 = lhs.e1*rhs.e23 + lhs.e2*rhs.e31 + lhs.e3*rhs.e12;
    result.t.e23o = 1.0*lhs.e2*rhs.e3o - 1.0*lhs.e3*rhs.e2o + 1.0*lhs.eo*rhs.e23;
    result.t.e31o = -1.0*lhs.e1*rhs.e3o + 1.0*lhs.e3*rhs.e1o + 1.0*lhs.eo*rhs.e31;
    result.t.e12o = 1.0*lhs.e1*rhs.e2o - 1.0*lhs.e2*rhs.e1o + 1.0*lhs.eo*rhs.e12;
    result.t.e23i = 1.0*lhs.e2*rhs.e3i - 1.0*lhs.e3*rhs.e2i + 1.0*lhs.ei*rhs.e23;
    result.t.e31i = -1.0*lhs.e1*rhs.e3i + 1.0*lhs.e3*rhs.e1i + 1.0*lhs.ei*rhs.e31;
    result.t.e12i = 1.0*lhs.e1*rhs.e2i - 1.0*lhs.e2*rhs.e1i + 1.0*lhs.ei*rhs.e12;
    result.t.e1oi = 1.0*lhs.e1*rhs.eoi + 1.0*lhs.ei*rhs.e1o - 1.0*lhs.eo*rhs.e1i;
    result.t.e2oi = 1.0*lhs.e2*rhs.eoi + 1.0*lhs.ei*rhs.e2o - 1.0*lhs.eo*rhs.e2i;
    result.t.e3oi = 1.0*lhs.e3*rhs.eoi + 1.0*lhs.ei*rhs.e3o - 1.0*lhs.eo*rhs.e3i;
    return result;
}
Versor operator*(const Vector &lhs, const Trivector &rhs) {
    Versor result;
    result.b.e23 = 1.0*lhs.e1*rhs.e123 - 1.0*lhs.ei*rhs.e23o - 1.0*lhs.eo*rhs.e23i;
    result.b.e31 = 1.0*lhs.e2*rhs.e123 - 1.0*lhs.ei*rhs.e31o - 1.0*lhs.eo*rhs.e31i;
    result.b.e12 = 1.0*lhs.e3*rhs.e123 - 1.0*lhs.ei*rhs.e12o - 1.0*lhs.eo*rhs.e12i;
    result.b.e1o = -1.0*lhs.e2*rhs.e12o + 1.0*lhs.e3*rhs.e31o - 1.0*lhs.eo*rhs.e1oi;
    result.b.e2o = 1.0*lhs.e1*rhs.e12o - 1.0*lhs.e3*rhs.e23o - 1.0*lhs.eo*rhs.e2oi;
    result.b.e3o = -1.0*lhs.e1*rhs.e31o + 1.0*lhs.e2*rhs.e23o - 1.0*lhs.eo*rhs.e3oi;
    result.b.e1i = -1.0*lhs.e2*rhs.e12i + 1.0*lhs.e3*rhs.e31i + 1.0*lhs.ei*rhs.e1oi;
    result.b.e2i = 1.0*lhs.e1*rhs.e12i - 1.0*lhs.e3*rhs.e23i + 1.0*lhs.ei*rhs.e2oi;
    result.b.e3i = -1.0*lhs.e1*rhs.e31i + 1.0*lhs.e2*rhs.e23i + 1.0*lhs.ei*rhs.e3oi;
    result.b.eoi = 1.0*lhs.e1*rhs.e1oi + 1.0*lhs.e2*rhs.e2oi + 1.0*lhs.e3*rhs.e3oi;
    result.q.e123o = 1.0*lhs.e1*rhs.e23o + 1.0*lhs.e2*rhs.e31o + 1.0*lhs.e3*rhs.e12o - 1.0*lhs.eo*rhs.e123;
    result.q.e123i = 1.0*lhs.e1*rhs.e23i + 1.0*lhs.e2*rhs.e31i + 1.0*lhs.e3*rhs.e12i - 1.0*lhs.ei*rhs.e123;
    result.q.e23oi = 1.0*lhs.e2*rhs.e3oi - 1.0*lhs.e3*rhs.e2oi - 1.0*lhs.ei*rhs.e23o + 1.0*lhs.eo*rhs.e23i;
    result.q.e31oi = -1.0*lhs.e1*rhs.e3oi + 1.0*lhs.e3*rhs.e1oi - 1.0*lhs.ei*rhs.e31o + 1.0*lhs.eo*rhs.e31i;
    result.q.e12oi = 1.0*lhs.e1*rhs.e2oi - 1.0*lhs.e2*rhs.e1oi - 1.0*lhs.ei*rhs.e12o + 1.0*lhs.eo*rhs.e12i;
    return result;
}
Multivector operator*(const Vector &lhs, const Rotor &rhs) {
    Multivector result;
    result.v.e1 = 1.0*lhs.e1*rhs.s - 1.0*lhs.e2*rhs.b.e12 + 1.0*lhs.e3*rhs.b.e31 + 1.0*lhs.ei*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e1i;
    result.v.e2 = 1.0*lhs.e1*rhs.b.e12 + 1.0*lhs.e2*rhs.s - 1.0*lhs.e3*rhs.b.e23 + 1.0*lhs.ei*rhs.b.e2o + 1.0*lhs.eo*rhs.b.e2i;
    result.v.e3 = -1.0*lhs.e1*rhs.b.e31 + 1.0*lhs.e2*rhs.b.e23 + 1.0*lhs.e3*rhs.s + 1.0*lhs.ei*rhs.b.e3o + 1.0*lhs.eo*rhs.b.e3i;
    result.v.eo = 1.0*lhs.e1*rhs.b.e1o + 1.0*lhs.e2*rhs.b.e2o + 1.0*lhs.e3*rhs.b.e3o + 1.0*lhs.eo*rhs.b.eoi + 1.0*lhs.eo*rhs.s;
    result.v.ei = 1.0*lhs.e1*rhs.b.e1i + 1.0*lhs.e2*rhs.b.e2i + 1.0*lhs.e3*rhs.b.e3i - 1.0*lhs.ei*rhs.b.eoi + 1.0*lhs.ei*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23 + lhs.e2*rhs.b.e31 + lhs.e3*rhs.b.e12;
    result.t.e23o = 1.0*lhs.e2*rhs.b.e3o - 1.0*lhs.e3*rhs.b.e2o + 1.0*lhs.eo*rhs.b.e23;
    result.t.e31o = -1.0*lhs.e1*rhs.b.e3o + 1.0*lhs.e3*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e31;
    result.t.e12o = 1.0*lhs.e1*rhs.b.e2o - 1.0*lhs.e2*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e12;
    result.t.e23i = 1.0*lhs.e2*rhs.b.e3i - 1.0*lhs.e3*rhs.b.e2i + 1.0*lhs.ei*rhs.b.e23;
    result.t.e31i = -1.0*lhs.e1*rhs.b.e3i + 1.0*lhs.e3*rhs.b.e1i + 1.0*lhs.ei*rhs.b.e31;
    result.t.e12i = 1.0*lhs.e1*rhs.b.e2i - 1.0*lhs.e2*rhs.b.e1i + 1.0*lhs.ei*rhs.b.e12;
    result.t.e1oi = 1.0*lhs.e1*rhs.b.eoi + 1.0*lhs.ei*rhs.b.e1o - 1.0*lhs.eo*rhs.b.e1i;
    result.t.e2oi = 1.0*lhs.e2*rhs.b.eoi + 1.0*lhs.ei*rhs.b.e2o - 1.0*lhs.eo*rhs.b.e2i;
    result.t.e3oi = 1.0*lhs.e3*rhs.b.eoi + 1.0*lhs.ei*rhs.b.e3o - 1.0*lhs.eo*rhs.b.e3i;
    return result;
}
Multivector operator*(const Vector &lhs, const Versor &rhs) {
    Multivector result;
    result.v.e1 = 1.0*lhs.e1*rhs.s - 1.0*lhs.e2*rhs.b.e12 + 1.0*lhs.e3*rhs.b.e31 + 1.0*lhs.ei*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e1i;
    result.v.e2 = 1.0*lhs.e1*rhs.b.e12 + 1.0*lhs.e2*rhs.s - 1.0*lhs.e3*rhs.b.e23 + 1.0*lhs.ei*rhs.b.e2o + 1.0*lhs.eo*rhs.b.e2i;
    result.v.e3 = -1.0*lhs.e1*rhs.b.e31 + 1.0*lhs.e2*rhs.b.e23 + 1.0*lhs.e3*rhs.s + 1.0*lhs.ei*rhs.b.e3o + 1.0*lhs.eo*rhs.b.e3i;
    result.v.eo = 1.0*lhs.e1*rhs.b.e1o + 1.0*lhs.e2*rhs.b.e2o + 1.0*lhs.e3*rhs.b.e3o + 1.0*lhs.eo*rhs.b.eoi + 1.0*lhs.eo*rhs.s;
    result.v.ei = 1.0*lhs.e1*rhs.b.e1i + 1.0*lhs.e2*rhs.b.e2i + 1.0*lhs.e3*rhs.b.e3i - 1.0*lhs.ei*rhs.b.eoi + 1.0*lhs.ei*rhs.s;
    result.t.e123 = 1.0*lhs.e1*rhs.b.e23 + 1.0*lhs.e2*rhs.b.e31 + 1.0*lhs.e3*rhs.b.e12 + 1.0*lhs.ei*rhs.q.e123o + 1.0*lhs.eo*rhs.q.e123i;
    result.t.e23o = 1.0*lhs.e1*rhs.q.e123o + 1.0*lhs.e2*rhs.b.e3o - 1.0*lhs.e3*rhs.b.e2o + 1.0*lhs.eo*rhs.b.e23 + 1.0*lhs.eo*rhs.q.e23oi;
    result.t.e31o = -1.0*lhs.e1*rhs.b.e3o + 1.0*lhs.e2*rhs.q.e123o + 1.0*lhs.e3*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e31 + 1.0*lhs.eo*rhs.q.e31oi;
    result.t.e12o = 1.0*lhs.e1*rhs.b.e2o - 1.0*lhs.e2*rhs.b.e1o + 1.0*lhs.e3*rhs.q.e123o + 1.0*lhs.eo*rhs.b.e12 + 1.0*lhs.eo*rhs.q.e12oi;
    result.t.e23i = 1.0*lhs.e1*rhs.q.e123i + 1.0*lhs.e2*rhs.b.e3i - 1.0*lhs.e3*rhs.b.e2i + 1.0*lhs.ei*rhs.b.e23 - 1.0*lhs.ei*rhs.q.e23oi;
    result.t.e31i = -1.0*lhs.e1*rhs.b.e3i + 1.0*lhs.e2*rhs.q.e123i + 1.0*lhs.e3*rhs.b.e1i + 1.0*lhs.ei*rhs.b.e31 - 1.0*lhs.ei*rhs.q.e31oi;
    result.t.e12i = 1.0*lhs.e1*rhs.b.e2i - 1.0*lhs.e2*rhs.b.e1i + 1.0*lhs.e3*rhs.q.e123i + 1.0*lhs.ei*rhs.b.e12 - 1.0*lhs.ei*rhs.q.e12oi;
    result.t.e1oi = 1.0*lhs.e1*rhs.b.eoi - 1.0*lhs.e2*rhs.q.e12oi + 1.0*lhs.e3*rhs.q.e31oi + 1.0*lhs.ei*rhs.b.e1o - 1.0*lhs.eo*rhs.b.e1i;
    result.t.e2oi = 1.0*lhs.e1*rhs.q.e12oi + 1.0*lhs.e2*rhs.b.eoi - 1.0*lhs.e3*rhs.q.e23oi + 1.0*lhs.ei*rhs.b.e2o - 1.0*lhs.eo*rhs.b.e2i;
    result.t.e3oi = -1.0*lhs.e1*rhs.q.e31oi + 1.0*lhs.e2*rhs.q.e23oi + 1.0*lhs.e3*rhs.b.eoi + 1.0*lhs.ei*rhs.b.e3o - 1.0*lhs.eo*rhs.b.e3i;
    result.I5 = 1.0*lhs.e1*rhs.q.e23oi + 1.0*lhs.e2*rhs.q.e31oi + 1.0*lhs.e3*rhs.q.e12oi + 1.0*lhs.ei*rhs.q.e123o - 1.0*lhs.eo*rhs.q.e123i;
    return result;
}
Multivector operator*(const Vector &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = 1.0*lhs.e1*rhs.v.e1 + 1.0*lhs.e2*rhs.v.e2 + 1.0*lhs.e3*rhs.v.e3 - 1.0*lhs.ei*rhs.v.eo - 1.0*lhs.eo*rhs.v.ei;
    result.v.e1 = 1.0*lhs.e1*rhs.s - 1.0*lhs.e2*rhs.b.e12 + 1.0*lhs.e3*rhs.b.e31 + 1.0*lhs.ei*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e1i;
    result.v.e2 = 1.0*lhs.e1*rhs.b.e12 + 1.0*lhs.e2*rhs.s - 1.0*lhs.e3*rhs.b.e23 + 1.0*lhs.ei*rhs.b.e2o + 1.0*lhs.eo*rhs.b.e2i;
    result.v.e3 = -1.0*lhs.e1*rhs.b.e31 + 1.0*lhs.e2*rhs.b.e23 + 1.0*lhs.e3*rhs.s + 1.0*lhs.ei*rhs.b.e3o + 1.0*lhs.eo*rhs.b.e3i;
    result.v.eo = 1.0*lhs.e1*rhs.b.e1o + 1.0*lhs.e2*rhs.b.e2o + 1.0*lhs.e3*rhs.b.e3o + 1.0*lhs.eo*rhs.b.eoi + 1.0*lhs.eo*rhs.s;
    result.v.ei = 1.0*lhs.e1*rhs.b.e1i + 1.0*lhs.e2*rhs.b.e2i + 1.0*lhs.e3*rhs.b.e3i - 1.0*lhs.ei*rhs.b.eoi + 1.0*lhs.ei*rhs.s;
    result.b.e23 = 1.0*lhs.e1*rhs.t.e123 + 1.0*lhs.e2*rhs.v.e3 - 1.0*lhs.e3*rhs.v.e2 - 1.0*lhs.ei*rhs.t.e23o - 1.0*lhs.eo*rhs.t.e23i;
    result.b.e31 = -1.0*lhs.e1*rhs.v.e3 + 1.0*lhs.e2*rhs.t.e123 + 1.0*lhs.e3*rhs.v.e1 - 1.0*lhs.ei*rhs.t.e31o - 1.0*lhs.eo*rhs.t.e31i;
    result.b.e12 = 1.0*lhs.e1*rhs.v.e2 - 1.0*lhs.e2*rhs.v.e1 + 1.0*lhs.e3*rhs.t.e123 - 1.0*lhs.ei*rhs.t.e12o - 1.0*lhs.eo*rhs.t.e12i;
    result.b.e1o = 1.0*lhs.e1*rhs.v.eo - 1.0*lhs.e2*rhs.t.e12o + 1.0*lhs.e3*rhs.t.e31o - 1.0*lhs.eo*rhs.t.e1oi - 1.0*lhs.eo*rhs.v.e1;
    result.b.e2o = 1.0*lhs.e1*rhs.t.e12o + 1.0*lhs.e2*rhs.v.eo - 1.0*lhs.e3*rhs.t.e23o - 1.0*lhs.eo*rhs.t.e2oi - 1.0*lhs.eo*rhs.v.e2;
    result.b.e3o = -1.0*lhs.e1*rhs.t.e31o + 1.0*lhs.e2*rhs.t.e23o + 1.0*lhs.e3*rhs.v.eo - 1.0*lhs.eo*rhs.t.e3oi - 1.0*lhs.eo*rhs.v.e3;
    result.b.e1i = 1.0*lhs.e1*rhs.v.ei - 1.0*lhs.e2*rhs.t.e12i + 1.0*lhs.e3*rhs.t.e31i + 1.0*lhs.ei*rhs.t.e1oi - 1.0*lhs.ei*rhs.v.e1;
    result.b.e2i = 1.0*lhs.e1*rhs.t.e12i + 1.0*lhs.e2*rhs.v.ei - 1.0*lhs.e3*rhs.t.e23i + 1.0*lhs.ei*rhs.t.e2oi - 1.0*lhs.ei*rhs.v.e2;
    result.b.e3i = -1.0*lhs.e1*rhs.t.e31i + 1.0*lhs.e2*rhs.t.e23i + 1.0*lhs.e3*rhs.v.ei + 1.0*lhs.ei*rhs.t.e3oi - 1.0*lhs.ei*rhs.v.e3;
    result.b.eoi = 1.0*lhs.e1*rhs.t.e1oi + 1.0*lhs.e2*rhs.t.e2oi + 1.0*lhs.e3*rhs.t.e3oi - 1.0*lhs.ei*rhs.v.eo + 1.0*lhs.eo*rhs.v.ei;
    result.t.e123 = 1.0*lhs.e1*rhs.b.e23 + 1.0*lhs.e2*rhs.b.e31 + 1.0*lhs.e3*rhs.b.e12 + 1.0*lhs.ei*rhs.q.e123o + 1.0*lhs.eo*rhs.q.e123i;
    result.t.e23o = 1.0*lhs.e1*rhs.q.e123o + 1.0*lhs.e2*rhs.b.e3o - 1.0*lhs.e3*rhs.b.e2o + 1.0*lhs.eo*rhs.b.e23 + 1.0*lhs.eo*rhs.q.e23oi;
    result.t.e31o = -1.0*lhs.e1*rhs.b.e3o + 1.0*lhs.e2*rhs.q.e123o + 1.0*lhs.e3*rhs.b.e1o + 1.0*lhs.eo*rhs.b.e31 + 1.0*lhs.eo*rhs.q.e31oi;
    result.t.e12o = 1.0*lhs.e1*rhs.b.e2o - 1.0*lhs.e2*rhs.b.e1o + 1.0*lhs.e3*rhs.q.e123o + 1.0*lhs.eo*rhs.b.e12 + 1.0*lhs.eo*rhs.q.e12oi;
    result.t.e23i = 1.0*lhs.e1*rhs.q.e123i + 1.0*lhs.e2*rhs.b.e3i - 1.0*lhs.e3*rhs.b.e2i + 1.0*lhs.ei*rhs.b.e23 - 1.0*lhs.ei*rhs.q.e23oi;
    result.t.e31i = -1.0*lhs.e1*rhs.b.e3i + 1.0*lhs.e2*rhs.q.e123i + 1.0*lhs.e3*rhs.b.e1i + 1.0*lhs.ei*rhs.b.e31 - 1.0*lhs.ei*rhs.q.e31oi;
    result.t.e12i = 1.0*lhs.e1*rhs.b.e2i - 1.0*lhs.e2*rhs.b.e1i + 1.0*lhs.e3*rhs.q.e123i + 1.0*lhs.ei*rhs.b.e12 - 1.0*lhs.ei*rhs.q.e12oi;
    result.t.e1oi = 1.0*lhs.e1*rhs.b.eoi - 1.0*lhs.e2*rhs.q.e12oi + 1.0*lhs.e3*rhs.q.e31oi + 1.0*lhs.ei*rhs.b.e1o - 1.0*lhs.eo*rhs.b.e1i;
    result.t.e2oi = 1.0*lhs.e1*rhs.q.e12oi + 1.0*lhs.e2*rhs.b.eoi - 1.0*lhs.e3*rhs.q.e23oi + 1.0*lhs.ei*rhs.b.e2o - 1.0*lhs.eo*rhs.b.e2i;
    result.t.e3oi = -1.0*lhs.e1*rhs.q.e31oi + 1.0*lhs.e2*rhs.q.e23oi + 1.0*lhs.e3*rhs.b.eoi + 1.0*lhs.ei*rhs.b.e3o - 1.0*lhs.eo*rhs.b.e3i;
    result.q.e123o = 1.0*lhs.e1*rhs.t.e23o + 1.0*lhs.e2*rhs.t.e31o + 1.0*lhs.e3*rhs.t.e12o - 1.0*lhs.eo*rhs.I5 - 1.0*lhs.eo*rhs.t.e123;
    result.q.e123i = 1.0*lhs.e1*rhs.t.e23i + 1.0*lhs.e2*rhs.t.e31i + 1.0*lhs.e3*rhs.t.e12i + 1.0*lhs.ei*rhs.I5 - 1.0*lhs.ei*rhs.t.e123;
    result.q.e23oi = 1.0*lhs.e1*rhs.I5 + 1.0*lhs.e2*rhs.t.e3oi - 1.0*lhs.e3*rhs.t.e2oi - 1.0*lhs.ei*rhs.t.e23o + 1.0*lhs.eo*rhs.t.e23i;
    result.q.e31oi = -1.0*lhs.e1*rhs.t.e3oi + 1.0*lhs.e2*rhs.I5 + 1.0*lhs.e3*rhs.t.e1oi - 1.0*lhs.ei*rhs.t.e31o + 1.0*lhs.eo*rhs.t.e31i;
    result.q.e12oi = 1.0*lhs.e1*rhs.t.e2oi - 1.0*lhs.e2*rhs.t.e1oi + 1.0*lhs.e3*rhs.I5 - 1.0*lhs.ei*rhs.t.e12o + 1.0*lhs.eo*rhs.t.e12i;
    result.I5 = 1.0*lhs.e1*rhs.q.e23oi + 1.0*lhs.e2*rhs.q.e31oi + 1.0*lhs.e3*rhs.q.e12oi + 1.0*lhs.ei*rhs.q.e123o - 1.0*lhs.eo*rhs.q.e123i;
    return result;
}
Rotor operator*(const Quadvector &lhs, const Quadvector &rhs) {
    Rotor result;
    result.s = -1.0*lhs.e123i*rhs.e123o - 1.0*lhs.e123o*rhs.e123i - 1.0*lhs.e12oi*rhs.e12oi - 1.0*lhs.e23oi*rhs.e23oi - 1.0*lhs.e31oi*rhs.e31oi;
    result.b.e23 = 1.0*lhs.e12oi*rhs.e31oi - 1.0*lhs.e31oi*rhs.e12oi;
    result.b.e31 = -1.0*lhs.e12oi*rhs.e23oi + 1.0*lhs.e23oi*rhs.e12oi;
    result.b.e12 = -1.0*lhs.e23oi*rhs.e31oi + 1.0*lhs.e31oi*rhs.e23oi;
    result.b.e1o = -1.0*lhs.e123o*rhs.e23oi + 1.0*lhs.e23oi*rhs.e123o;
    result.b.e2o = -1.0*lhs.e123o*rhs.e31oi + 1.0*lhs.e31oi*rhs.e123o;
    result.b.e3o = -1.0*lhs.e123o*rhs.e12oi + 1.0*lhs.e12oi*rhs.e123o;
    result.b.e1i = 1.0*lhs.e123i*rhs.e23oi - 1.0*lhs.e23oi*rhs.e123i;
    result.b.e2i = 1.0*lhs.e123i*rhs.e31oi - 1.0*lhs.e31oi*rhs.e123i;
    result.b.e3i = 1.0*lhs.e123i*rhs.e12oi - 1.0*lhs.e12oi*rhs.e123i;
    result.b.eoi = -1.0*lhs.e123i*rhs.e123o + 1.0*lhs.e123o*rhs.e123i;
    return result;
}
Versor operator*(const Quadvector &lhs, const Bivector &rhs) {
    Versor result;
    result.b.e23 = 1.0*lhs.e123i*rhs.e1o + 1.0*lhs.e123o*rhs.e1i + 1.0*lhs.e23oi*rhs.eoi;
    result.b.e31 = 1.0*lhs.e123i*rhs.e2o + 1.0*lhs.e123o*rhs.e2i + 1.0*lhs.e31oi*rhs.eoi;
    result.b.e12 = 1.0*lhs.e123i*rhs.e3o + 1.0*lhs.e123o*rhs.e3i + 1.0*lhs.e12oi*rhs.eoi;
    result.b.e1o = -1.0*lhs.e123o*rhs.e23 - 1.0*lhs.e12oi*rhs.e2o + 1.0*lhs.e31oi*rhs.e3o;
    result.b.e2o = -1.0*lhs.e123o*rhs.e31 + 1.0*lhs.e12oi*rhs.e1o - 1.0*lhs.e23oi*rhs.e3o;
    result.b.e3o = -1.0*lhs.e123o*rhs.e12 + 1.0*lhs.e23oi*rhs.e2o - 1.0*lhs.e31oi*rhs.e1o;
    result.b.e1i = -1.0*lhs.e123i*rhs.e23 + 1.0*lhs.e12oi*rhs.e2i - 1.0*lhs.e31oi*rhs.e3i;
    result.b.e2i = -1.0*lhs.e123i*rhs.e31 - 1.0*lhs.e12oi*rhs.e1i + 1.0*lhs.e23oi*rhs.e3i;
    result.b.e3i = -1.0*lhs.e123i*rhs.e12 - 1.0*lhs.e23oi*rhs.e2i + 1.0*lhs.e31oi*rhs.e1i;
    result.b.eoi = -1.0*lhs.e12oi*rhs.e12 - 1.0*lhs.e23oi*rhs.e23 - 1.0*lhs.e31oi*rhs.e31;
    result.q.e123o = 1.0*lhs.e123o*rhs.eoi - 1.0*lhs.e12oi*rhs.e3o - 1.0*lhs.e23oi*rhs.e1o - 1.0*lhs.e31oi*rhs.e2o;
    result.q.e123i = -1.0*lhs.e123i*rhs.eoi + 1.0*lhs.e12oi*rhs.e3i + 1.0*lhs.e23oi*rhs.e1i + 1.0*lhs.e31oi*rhs.e2i;
    result.q.e23oi = 1.0*lhs.e123i*rhs.e1o - 1.0*lhs.e123o*rhs.e1i + 1.0*lhs.e12oi*rhs.e31 - 1.0*lhs.e31oi*rhs.e12;
    result.q.e31oi = 1.0*lhs.e123i*rhs.e2o - 1.0*lhs.e123o*rhs.e2i - 1.0*lhs.e12oi*rhs.e23 + 1.0*lhs.e23oi*rhs.e12;
    result.q.e12oi = 1.0*lhs.e123i*rhs.e3o - 1.0*lhs.e123o*rhs.e3i - 1.0*lhs.e23oi*rhs.e31 + 1.0*lhs.e31oi*rhs.e23;
    return result;
}
Multivector operator*(const Quadvector &lhs, const Trivector &rhs) {
    Multivector result;
    result.v.e1 = 1.0*lhs.e123i*rhs.e23o + 1.0*lhs.e123o*rhs.e23i + 1.0*lhs.e12oi*rhs.e2oi - 1.0*lhs.e31oi*rhs.e3oi;
    result.v.e2 = 1.0*lhs.e123i*rhs.e31o + 1.0*lhs.e123o*rhs.e31i - 1.0*lhs.e12oi*rhs.e1oi + 1.0*lhs.e23oi*rhs.e3oi;
    result.v.e3 = 1.0*lhs.e123i*rhs.e12o + 1.0*lhs.e123o*rhs.e12i - 1.0*lhs.e23oi*rhs.e2oi + 1.0*lhs.e31oi*rhs.e1oi;
    result.v.eo = 1.0*lhs.e123o*rhs.e123 + 1.0*lhs.e12oi*rhs.e12o + 1.0*lhs.e23oi*rhs.e23o + 1.0*lhs.e31oi*rhs.e31o;
    result.v.ei = 1.0*lhs.e123i*rhs.e123 - 1.0*lhs.e12oi*rhs.e12i - 1.0*lhs.e23oi*rhs.e23i - 1.0*lhs.e31oi*rhs.e31i;
    result.t.e123 = 1.0*lhs.e12oi*rhs.e3oi + 1.0*lhs.e23oi*rhs.e1oi + 1.0*lhs.e31oi*rhs.e2oi;
    result.t.e23o = -1.0*lhs.e123o*rhs.e1oi - 1.0*lhs.e12oi*rhs.e31o + 1.0*lhs.e31oi*rhs.e12o;
    result.t.e31o = -1.0*lhs.e123o*rhs.e2oi + 1.0*lhs.e12oi*rhs.e23o - 1.0*lhs.e23oi*rhs.e12o;
    result.t.e12o = -1.0*lhs.e123o*rhs.e3oi + 1.0*lhs.e23oi*rhs.e31o - 1.0*lhs.e31oi*rhs.e23o;
    result.t.e23i = 1.0*lhs.e123i*rhs.e1oi + 1.0*lhs.e12oi*rhs.e31i - 1.0*lhs.e31oi*rhs.e12i;
    result.t.e31i = 1.0*lhs.e123i*rhs.e2oi - 1.0*lhs.e12oi*rhs.e23i + 1.0*lhs.e23oi*rhs.e12i;
    result.t.e12i = 1.0*lhs.e123i*rhs.e3oi - 1.0*lhs.e23oi*rhs.e31i + 1.0*lhs.e31oi*rhs.e23i;
    result.t.e1oi = 1.0*lhs.e123i*rhs.e23o - 1.0*lhs.e123o*rhs.e23i - 1.0*lhs.e23oi*rhs.e123;
    result.t.e2oi = 1.0*lhs.e123i*rhs.e31o - 1.0*lhs.e123o*rhs.e31i - 1.0*lhs.e31oi*rhs.e123;
    result.t.e3oi = 1.0*lhs.e123i*rhs.e12o - 1.0*lhs.e123o*rhs.e12i - 1.0*lhs.e12oi*rhs.e123;
    return result;
}
Versor operator*(const Quadvector &lhs, const Rotor &rhs) {
    Versor result;
    result.b.e23 = 1.0*lhs.e123i*rhs.b.e1o + 1.0*lhs.e123o*rhs.b.e1i + 1.0*lhs.e23oi*rhs.b.eoi;
    result.b.e31 = 1.0*lhs.e123i*rhs.b.e2o + 1.0*lhs.e123o*rhs.b.e2i + 1.0*lhs.e31oi*rhs.b.eoi;
    result.b.e12 = 1.0*lhs.e123i*rhs.b.e3o + 1.0*lhs.e123o*rhs.b.e3i + 1.0*lhs.e12oi*rhs.b.eoi;
    result.b.e1o = -1.0*lhs.e123o*rhs.b.e23 - 1.0*lhs.e12oi*rhs.b.e2o + 1.0*lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -1.0*lhs.e123o*rhs.b.e31 + 1.0*lhs.e12oi*rhs.b.e1o - 1.0*lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -1.0*lhs.e123o*rhs.b.e12 + 1.0*lhs.e23oi*rhs.b.e2o - 1.0*lhs.e31oi*rhs.b.e1o;
    result.b.e1i = -1.0*lhs.e123i*rhs.b.e23 + 1.0*lhs.e12oi*rhs.b.e2i - 1.0*lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -1.0*lhs.e123i*rhs.b.e31 - 1.0*lhs.e12oi*rhs.b.e1i + 1.0*lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -1.0*lhs.e123i*rhs.b.e12 - 1.0*lhs.e23oi*rhs.b.e2i + 1.0*lhs.e31oi*rhs.b.e1i;
    result.b.eoi = -1.0*lhs.e12oi*rhs.b.e12 - 1.0*lhs.e23oi*rhs.b.e23 - 1.0*lhs.e31oi*rhs.b.e31;
    result.q.e123o = 1.0*lhs.e123o*rhs.b.eoi + 1.0*lhs.e123o*rhs.s - 1.0*lhs.e12oi*rhs.b.e3o - 1.0*lhs.e23oi*rhs.b.e1o - 1.0*lhs.e31oi*rhs.b.e2o;
    result.q.e123i = -1.0*lhs.e123i*rhs.b.eoi + 1.0*lhs.e123i*rhs.s + 1.0*lhs.e12oi*rhs.b.e3i + 1.0*lhs.e23oi*rhs.b.e1i + 1.0*lhs.e31oi*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.e123i*rhs.b.e1o - 1.0*lhs.e123o*rhs.b.e1i + 1.0*lhs.e12oi*rhs.b.e31 + 1.0*lhs.e23oi*rhs.s - 1.0*lhs.e31oi*rhs.b.e12;
    result.q.e31oi = 1.0*lhs.e123i*rhs.b.e2o - 1.0*lhs.e123o*rhs.b.e2i - 1.0*lhs.e12oi*rhs.b.e23 + 1.0*lhs.e23oi*rhs.b.e12 + 1.0*lhs.e31oi*rhs.s;
    result.q.e12oi = 1.0*lhs.e123i*rhs.b.e3o - 1.0*lhs.e123o*rhs.b.e3i + 1.0*lhs.e12oi*rhs.s - 1.0*lhs.e23oi*rhs.b.e31 + 1.0*lhs.e31oi*rhs.b.e23;
    return result;
}
Versor operator*(const Quadvector &lhs, const Versor &rhs) {
    Versor result;
    result.s = -1.0*lhs.e123i*rhs.q.e123o - 1.0*lhs.e123o*rhs.q.e123i - 1.0*lhs.e12oi*rhs.q.e12oi - 1.0*lhs.e23oi*rhs.q.e23oi - 1.0*lhs.e31oi*rhs.q.e31oi;
    result.b.e23 = 1.0*lhs.e123i*rhs.b.e1o + 1.0*lhs.e123o*rhs.b.e1i + 1.0*lhs.e12oi*rhs.q.e31oi + 1.0*lhs.e23oi*rhs.b.eoi - 1.0*lhs.e31oi*rhs.q.e12oi;
    result.b.e31 = 1.0*lhs.e123i*rhs.b.e2o + 1.0*lhs.e123o*rhs.b.e2i - 1.0*lhs.e12oi*rhs.q.e23oi + 1.0*lhs.e23oi*rhs.q.e12oi + 1.0*lhs.e31oi*rhs.b.eoi;
    result.b.e12 = 1.0*lhs.e123i*rhs.b.e3o + 1.0*lhs.e123o*rhs.b.e3i + 1.0*lhs.e12oi*rhs.b.eoi - 1.0*lhs.e23oi*rhs.q.e31oi + 1.0*lhs.e31oi*rhs.q.e23oi;
    result.b.e1o = -1.0*lhs.e123o*rhs.b.e23 - 1.0*lhs.e123o*rhs.q.e23oi - 1.0*lhs.e12oi*rhs.b.e2o + 1.0*lhs.e23oi*rhs.q.e123o + 1.0*lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -1.0*lhs.e123o*rhs.b.e31 - 1.0*lhs.e123o*rhs.q.e31oi + 1.0*lhs.e12oi*rhs.b.e1o - 1.0*lhs.e23oi*rhs.b.e3o + 1.0*lhs.e31oi*rhs.q.e123o;
    result.b.e3o = -1.0*lhs.e123o*rhs.b.e12 - 1.0*lhs.e123o*rhs.q.e12oi + 1.0*lhs.e12oi*rhs.q.e123o + 1.0*lhs.e23oi*rhs.b.e2o - 1.0*lhs.e31oi*rhs.b.e1o;
    result.b.e1i = -1.0*lhs.e123i*rhs.b.e23 + 1.0*lhs.e123i*rhs.q.e23oi + 1.0*lhs.e12oi*rhs.b.e2i - 1.0*lhs.e23oi*rhs.q.e123i - 1.0*lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -1.0*lhs.e123i*rhs.b.e31 + 1.0*lhs.e123i*rhs.q.e31oi - 1.0*lhs.e12oi*rhs.b.e1i + 1.0*lhs.e23oi*rhs.b.e3i - 1.0*lhs.e31oi*rhs.q.e123i;
    result.b.e3i = -1.0*lhs.e123i*rhs.b.e12 + 1.0*lhs.e123i*rhs.q.e12oi - 1.0*lhs.e12oi*rhs.q.e123i - 1.0*lhs.e23oi*rhs.b.e2i + 1.0*lhs.e31oi*rhs.b.e1i;
    result.b.eoi = -1.0*lhs.e123i*rhs.q.e123o + 1.0*lhs.e123o*rhs.q.e123i - 1.0*lhs.e12oi*rhs.b.e12 - 1.0*lhs.e23oi*rhs.b.e23 - 1.0*lhs.e31oi*rhs.b.e31;
    result.q.e123o = 1.0*lhs.e123o*rhs.b.eoi + 1.0*lhs.e123o*rhs.s - 1.0*lhs.e12oi*rhs.b.e3o - 1.0*lhs.e23oi*rhs.b.e1o - 1.0*lhs.e31oi*rhs.b.e2o;
    result.q.e123i = -1.0*lhs.e123i*rhs.b.eoi + 1.0*lhs.e123i*rhs.s + 1.0*lhs.e12oi*rhs.b.e3i + 1.0*lhs.e23oi*rhs.b.e1i + 1.0*lhs.e31oi*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.e123i*rhs.b.e1o - 1.0*lhs.e123o*rhs.b.e1i + 1.0*lhs.e12oi*rhs.b.e31 + 1.0*lhs.e23oi*rhs.s - 1.0*lhs.e31oi*rhs.b.e12;
    result.q.e31oi = 1.0*lhs.e123i*rhs.b.e2o - 1.0*lhs.e123o*rhs.b.e2i - 1.0*lhs.e12oi*rhs.b.e23 + 1.0*lhs.e23oi*rhs.b.e12 + 1.0*lhs.e31oi*rhs.s;
    result.q.e12oi = 1.0*lhs.e123i*rhs.b.e3o - 1.0*lhs.e123o*rhs.b.e3i + 1.0*lhs.e12oi*rhs.s - 1.0*lhs.e23oi*rhs.b.e31 + 1.0*lhs.e31oi*rhs.b.e23;
    return result;
}
Multivector operator*(const Quadvector &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.e123i*rhs.q.e123o - 1.0*lhs.e123o*rhs.q.e123i - 1.0*lhs.e12oi*rhs.q.e12oi - 1.0*lhs.e23oi*rhs.q.e23oi - 1.0*lhs.e31oi*rhs.q.e31oi;
    result.v.e1 = 1.0*lhs.e123i*rhs.t.e23o + 1.0*lhs.e123o*rhs.t.e23i + 1.0*lhs.e12oi*rhs.t.e2oi - 1.0*lhs.e23oi*rhs.I5 - 1.0*lhs.e31oi*rhs.t.e3oi;
    result.v.e2 = 1.0*lhs.e123i*rhs.t.e31o + 1.0*lhs.e123o*rhs.t.e31i - 1.0*lhs.e12oi*rhs.t.e1oi + 1.0*lhs.e23oi*rhs.t.e3oi - 1.0*lhs.e31oi*rhs.I5;
    result.v.e3 = 1.0*lhs.e123i*rhs.t.e12o + 1.0*lhs.e123o*rhs.t.e12i - 1.0*lhs.e12oi*rhs.I5 - 1.0*lhs.e23oi*rhs.t.e2oi + 1.0*lhs.e31oi*rhs.t.e1oi;
    result.v.eo = 1.0*lhs.e123o*rhs.I5 + 1.0*lhs.e123o*rhs.t.e123 + 1.0*lhs.e12oi*rhs.t.e12o + 1.0*lhs.e23oi*rhs.t.e23o + 1.0*lhs.e31oi*rhs.t.e31o;
    result.v.ei = -1.0*lhs.e123i*rhs.I5 + 1.0*lhs.e123i*rhs.t.e123 - 1.0*lhs.e12oi*rhs.t.e12i - 1.0*lhs.e23oi*rhs.t.e23i - 1.0*lhs.e31oi*rhs.t.e31i;
    result.b.e23 = 1.0*lhs.e123i*rhs.b.e1o + 1.0*lhs.e123o*rhs.b.e1i + 1.0*lhs.e12oi*rhs.q.e31oi + 1.0*lhs.e23oi*rhs.b.eoi - 1.0*lhs.e31oi*rhs.q.e12oi;
    result.b.e31 = 1.0*lhs.e123i*rhs.b.e2o + 1.0*lhs.e123o*rhs.b.e2i - 1.0*lhs.e12oi*rhs.q.e23oi + 1.0*lhs.e23oi*rhs.q.e12oi + 1.0*lhs.e31oi*rhs.b.eoi;
    result.b.e12 = 1.0*lhs.e123i*rhs.b.e3o + 1.0*lhs.e123o*rhs.b.e3i + 1.0*lhs.e12oi*rhs.b.eoi - 1.0*lhs.e23oi*rhs.q.e31oi + 1.0*lhs.e31oi*rhs.q.e23oi;
    result.b.e1o = -1.0*lhs.e123o*rhs.b.e23 - 1.0*lhs.e123o*rhs.q.e23oi - 1.0*lhs.e12oi*rhs.b.e2o + 1.0*lhs.e23oi*rhs.q.e123o + 1.0*lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -1.0*lhs.e123o*rhs.b.e31 - 1.0*lhs.e123o*rhs.q.e31oi + 1.0*lhs.e12oi*rhs.b.e1o - 1.0*lhs.e23oi*rhs.b.e3o + 1.0*lhs.e31oi*rhs.q.e123o;
    result.b.e3o = -1.0*lhs.e123o*rhs.b.e12 - 1.0*lhs.e123o*rhs.q.e12oi + 1.0*lhs.e12oi*rhs.q.e123o + 1.0*lhs.e23oi*rhs.b.e2o - 1.0*lhs.e31oi*rhs.b.e1o;
    result.b.e1i = -1.0*lhs.e123i*rhs.b.e23 + 1.0*lhs.e123i*rhs.q.e23oi + 1.0*lhs.e12oi*rhs.b.e2i - 1.0*lhs.e23oi*rhs.q.e123i - 1.0*lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -1.0*lhs.e123i*rhs.b.e31 + 1.0*lhs.e123i*rhs.q.e31oi - 1.0*lhs.e12oi*rhs.b.e1i + 1.0*lhs.e23oi*rhs.b.e3i - 1.0*lhs.e31oi*rhs.q.e123i;
    result.b.e3i = -1.0*lhs.e123i*rhs.b.e12 + 1.0*lhs.e123i*rhs.q.e12oi - 1.0*lhs.e12oi*rhs.q.e123i - 1.0*lhs.e23oi*rhs.b.e2i + 1.0*lhs.e31oi*rhs.b.e1i;
    result.b.eoi = -1.0*lhs.e123i*rhs.q.e123o + 1.0*lhs.e123o*rhs.q.e123i - 1.0*lhs.e12oi*rhs.b.e12 - 1.0*lhs.e23oi*rhs.b.e23 - 1.0*lhs.e31oi*rhs.b.e31;
    result.t.e123 = -1.0*lhs.e123i*rhs.v.eo - 1.0*lhs.e123o*rhs.v.ei + 1.0*lhs.e12oi*rhs.t.e3oi + 1.0*lhs.e23oi*rhs.t.e1oi + 1.0*lhs.e31oi*rhs.t.e2oi;
    result.t.e23o = -1.0*lhs.e123o*rhs.t.e1oi - 1.0*lhs.e123o*rhs.v.e1 - 1.0*lhs.e12oi*rhs.t.e31o - 1.0*lhs.e23oi*rhs.v.eo + 1.0*lhs.e31oi*rhs.t.e12o;
    result.t.e31o = -1.0*lhs.e123o*rhs.t.e2oi - 1.0*lhs.e123o*rhs.v.e2 + 1.0*lhs.e12oi*rhs.t.e23o - 1.0*lhs.e23oi*rhs.t.e12o - 1.0*lhs.e31oi*rhs.v.eo;
    result.t.e12o = -1.0*lhs.e123o*rhs.t.e3oi - 1.0*lhs.e123o*rhs.v.e3 - 1.0*lhs.e12oi*rhs.v.eo + 1.0*lhs.e23oi*rhs.t.e31o - 1.0*lhs.e31oi*rhs.t.e23o;
    result.t.e23i = 1.0*lhs.e123i*rhs.t.e1oi - 1.0*lhs.e123i*rhs.v.e1 + 1.0*lhs.e12oi*rhs.t.e31i + 1.0*lhs.e23oi*rhs.v.ei - 1.0*lhs.e31oi*rhs.t.e12i;
    result.t.e31i = 1.0*lhs.e123i*rhs.t.e2oi - 1.0*lhs.e123i*rhs.v.e2 - 1.0*lhs.e12oi*rhs.t.e23i + 1.0*lhs.e23oi*rhs.t.e12i + 1.0*lhs.e31oi*rhs.v.ei;
    result.t.e12i = 1.0*lhs.e123i*rhs.t.e3oi - 1.0*lhs.e123i*rhs.v.e3 + 1.0*lhs.e12oi*rhs.v.ei - 1.0*lhs.e23oi*rhs.t.e31i + 1.0*lhs.e31oi*rhs.t.e23i;
    result.t.e1oi = 1.0*lhs.e123i*rhs.t.e23o - 1.0*lhs.e123o*rhs.t.e23i + 1.0*lhs.e12oi*rhs.v.e2 - 1.0*lhs.e23oi*rhs.t.e123 - 1.0*lhs.e31oi*rhs.v.e3;
    result.t.e2oi = 1.0*lhs.e123i*rhs.t.e31o - 1.0*lhs.e123o*rhs.t.e31i - 1.0*lhs.e12oi*rhs.v.e1 + 1.0*lhs.e23oi*rhs.v.e3 - 1.0*lhs.e31oi*rhs.t.e123;
    result.t.e3oi = 1.0*lhs.e123i*rhs.t.e12o - 1.0*lhs.e123o*rhs.t.e12i - 1.0*lhs.e12oi*rhs.t.e123 - 1.0*lhs.e23oi*rhs.v.e2 + 1.0*lhs.e31oi*rhs.v.e1;
    result.q.e123o = 1.0*lhs.e123o*rhs.b.eoi + 1.0*lhs.e123o*rhs.s - 1.0*lhs.e12oi*rhs.b.e3o - 1.0*lhs.e23oi*rhs.b.e1o - 1.0*lhs.e31oi*rhs.b.e2o;
    result.q.e123i = -1.0*lhs.e123i*rhs.b.eoi + 1.0*lhs.e123i*rhs.s + 1.0*lhs.e12oi*rhs.b.e3i + 1.0*lhs.e23oi*rhs.b.e1i + 1.0*lhs.e31oi*rhs.b.e2i;
    result.q.e23oi = 1.0*lhs.e123i*rhs.b.e1o - 1.0*lhs.e123o*rhs.b.e1i + 1.0*lhs.e12oi*rhs.b.e31 + 1.0*lhs.e23oi*rhs.s - 1.0*lhs.e31oi*rhs.b.e12;
    result.q.e31oi = 1.0*lhs.e123i*rhs.b.e2o - 1.0*lhs.e123o*rhs.b.e2i - 1.0*lhs.e12oi*rhs.b.e23 + 1.0*lhs.e23oi*rhs.b.e12 + 1.0*lhs.e31oi*rhs.s;
    result.q.e12oi = 1.0*lhs.e123i*rhs.b.e3o - 1.0*lhs.e123o*rhs.b.e3i + 1.0*lhs.e12oi*rhs.s - 1.0*lhs.e23oi*rhs.b.e31 + 1.0*lhs.e31oi*rhs.b.e23;
    result.I5 = -1.0*lhs.e123i*rhs.v.eo + 1.0*lhs.e123o*rhs.v.ei + 1.0*lhs.e12oi*rhs.v.e3 + 1.0*lhs.e23oi*rhs.v.e1 + 1.0*lhs.e31oi*rhs.v.e2;
    return result;
}
Versor operator*(const Bivector &lhs, const Bivector &rhs) {
    Versor result;
    result.s = -1.0*lhs.e12*rhs.e12 + 1.0*lhs.e1i*rhs.e1o + 1.0*lhs.e1o*rhs.e1i - 1.0*lhs.e23*rhs.e23 + 1.0*lhs.e2i*rhs.e2o + 1.0*lhs.e2o*rhs.e2i - 1.0*lhs.e31*rhs.e31 + 1.0*lhs.e3i*rhs.e3o + 1.0*lhs.e3o*rhs.e3i + 1.0*lhs.eoi*rhs.eoi;
    result.b.e23 = 1.0*lhs.e12*rhs.e31 + 1.0*lhs.e2i*rhs.e3o + 1.0*lhs.e2o*rhs.e3i - 1.0*lhs.e31*rhs.e12 - 1.0*lhs.e3i*rhs.e2o - 1.0*lhs.e3o*rhs.e2i;
    result.b.e31 = -1.0*lhs.e12*rhs.e23 - 1.0*lhs.e1i*rhs.e3o - 1.0*lhs.e1o*rhs.e3i + 1.0*lhs.e23*rhs.e12 + 1.0*lhs.e3i*rhs.e1o + 1.0*lhs.e3o*rhs.e1i;
    result.b.e12 = 1.0*lhs.e1i*rhs.e2o + 1.0*lhs.e1o*rhs.e2i - 1.0*lhs.e23*rhs.e31 - 1.0*lhs.e2i*rhs.e1o - 1.0*lhs.e2o*rhs.e1i + 1.0*lhs.e31*rhs.e23;
    result.b.e1o = 1.0*lhs.e12*rhs.e2o + 1.0*lhs.e1o*rhs.eoi - 1.0*lhs.e2o*rhs.e12 - 1.0*lhs.e31*rhs.e3o + 1.0*lhs.e3o*rhs.e31 - 1.0*lhs.eoi*rhs.e1o;
    result.b.e2o = -1.0*lhs.e12*rhs.e1o + 1.0*lhs.e1o*rhs.e12 + 1.0*lhs.e23*rhs.e3o + 1.0*lhs.e2o*rhs.eoi - 1.0*lhs.e3o*rhs.e23 - 1.0*lhs.eoi*rhs.e2o;
    result.b.e3o = -1.0*lhs.e1o*rhs.e31 - 1.0*lhs.e23*rhs.e2o + 1.0*lhs.e2o*rhs.e23 + 1.0*lhs.e31*rhs.e1o + 1.0*lhs.e3o*rhs.eoi - 1.0*lhs.eoi*rhs.e3o;
    result.b.e1i = 1.0*lhs.e12*rhs.e2i - 1.0*lhs.e1i*rhs.eoi - 1.0*lhs.e2i*rhs.e12 - 1.0*lhs.e31*rhs.e3i + 1.0*lhs.e3i*rhs.e31 + 1.0*lhs.eoi*rhs.e1i;
    result.b.e2i = -1.0*lhs.e12*rhs.e1i + 1.0*lhs.e1i*rhs.e12 + 1.0*lhs.e23*rhs.e3i - 1.0*lhs.e2i*rhs.eoi - 1.0*lhs.e3i*rhs.e23 + 1.0*lhs.eoi*rhs.e2i;
    result.b.e3i = -1.0*lhs.e1i*rhs.e31 - 1.0*lhs.e23*rhs.e2i + 1.0*lhs.e2i*rhs.e23 + 1.0*lhs.e31*rhs.e1i - 1.0*lhs.e3i*rhs.eoi + 1.0*lhs.eoi*rhs.e3i;
    result.b.eoi = 1.0*lhs.e1i*rhs.e1o - 1.0*lhs.e1o*rhs.e1i + 1.0*lhs.e2i*rhs.e2o - 1.0*lhs.e2o*rhs.e2i + 1.0*lhs.e3i*rhs.e3o - 1.0*lhs.e3o*rhs.e3i;
    result.q.e123o = 1.0*lhs.e12*rhs.e3o + 1.0*lhs.e1o*rhs.e23 + 1.0*lhs.e23*rhs.e1o + 1.0*lhs.e2o*rhs.e31 + 1.0*lhs.e31*rhs.e2o + 1.0*lhs.e3o*rhs.e12;
    result.q.e123i = 1.0*lhs.e12*rhs.e3i + 1.0*lhs.e1i*rhs.e23 + 1.0*lhs.e23*rhs.e1i + 1.0*lhs.e2i*rhs.e31 + 1.0*lhs.e31*rhs.e2i + 1.0*lhs.e3i*rhs.e12;
    result.q.e23oi = 1.0*lhs.e23*rhs.eoi + 1.0*lhs.e2i*rhs.e3o - 1.0*lhs.e2o*rhs.e3i - 1.0*lhs.e3i*rhs.e2o + 1.0*lhs.e3o*rhs.e2i + 1.0*lhs.eoi*rhs.e23;
    result.q.e31oi = -1.0*lhs.e1i*rhs.e3o + 1.0*lhs.e1o*rhs.e3i + 1.0*lhs.e31*rhs.eoi + 1.0*lhs.e3i*rhs.e1o - 1.0*lhs.e3o*rhs.e1i + 1.0*lhs.eoi*rhs.e31;
    result.q.e12oi = 1.0*lhs.e12*rhs.eoi + 1.0*lhs.e1i*rhs.e2o - 1.0*lhs.e1o*rhs.e2i - 1.0*lhs.e2i*rhs.e1o + 1.0*lhs.e2o*rhs.e1i + 1.0*lhs.eoi*rhs.e12;
    return result;
}
Multivector operator*(const Bivector &lhs, const Trivector &rhs) {
    Multivector result;
    result.v.e1 = -1.0*lhs.e23*rhs.e123 + 1.0*lhs.e2i*rhs.e12o + 1.0*lhs.e2o*rhs.e12i - 1.0*lhs.e3i*rhs.e31o - 1.0*lhs.e3o*rhs.e31i + 1.0*lhs.eoi*rhs.e1oi;
    result.v.e2 = -1.0*lhs.e1i*rhs.e12o - 1.0*lhs.e1o*rhs.e12i - 1.0*lhs.e31*rhs.e123 + 1.0*lhs.e3i*rhs.e23o + 1.0*lhs.e3o*rhs.e23i + 1.0*lhs.eoi*rhs.e2oi;
    result.v.e3 = -1.0*lhs.e12*rhs.e123 + 1.0*lhs.e1i*rhs.e31o + 1.0*lhs.e1o*rhs.e31i - 1.0*lhs.e2i*rhs.e23o - 1.0*lhs.e2o*rhs.e23i + 1.0*lhs.eoi*rhs.e3oi;
    result.v.eo = -1.0*lhs.e12*rhs.e12o - 1.0*lhs.e1o*rhs.e1oi - 1.0*lhs.e23*rhs.e23o - 1.0*lhs.e2o*rhs.e2oi - 1.0*lhs.e31*rhs.e31o - 1.0*lhs.e3o*rhs.e3oi;
    result.v.ei = -1.0*lhs.e12*rhs.e12i + 1.0*lhs.e1i*rhs.e1oi - 1.0*lhs.e23*rhs.e23i + 1.0*lhs.e2i*rhs.e2oi - 1.0*lhs.e31*rhs.e31i + 1.0*lhs.e3i*rhs.e3oi;
    result.t.e123 = -1.0*lhs.e1i*rhs.e23o - 1.0*lhs.e1o*rhs.e23i - 1.0*lhs.e2i*rhs.e31o - 1.0*lhs.e2o*rhs.e31i - 1.0*lhs.e3i*rhs.e12o - 1.0*lhs.e3o*rhs.e12i;
    result.t.e23o = 1.0*lhs.e12*rhs.e31o - 1.0*lhs.e1o*rhs.e123 - 1.0*lhs.e2o*rhs.e3oi - 1.0*lhs.e31*rhs.e12o + 1.0*lhs.e3o*rhs.e2oi - 1.0*lhs.eoi*rhs.e23o;
    result.t.e31o = -1.0*lhs.e12*rhs.e23o + 1.0*lhs.e1o*rhs.e3oi + 1.0*lhs.e23*rhs.e12o - 1.0*lhs.e2o*rhs.e123 - 1.0*lhs.e3o*rhs.e1oi - 1.0*lhs.eoi*rhs.e31o;
    result.t.e12o = -1.0*lhs.e1o*rhs.e2oi - 1.0*lhs.e23*rhs.e31o + 1.0*lhs.e2o*rhs.e1oi + 1.0*lhs.e31*rhs.e23o - 1.0*lhs.e3o*rhs.e123 - 1.0*lhs.eoi*rhs.e12o;
    result.t.e23i = 1.0*lhs.e12*rhs.e31i - 1.0*lhs.e1i*rhs.e123 + 1.0*lhs.e2i*rhs.e3oi - 1.0*lhs.e31*rhs.e12i - 1.0*lhs.e3i*rhs.e2oi + 1.0*lhs.eoi*rhs.e23i;
    result.t.e31i = -1.0*lhs.e12*rhs.e23i - 1.0*lhs.e1i*rhs.e3oi + 1.0*lhs.e23*rhs.e12i - 1.0*lhs.e2i*rhs.e123 + 1.0*lhs.e3i*rhs.e1oi + 1.0*lhs.eoi*rhs.e31i;
    result.t.e12i = 1.0*lhs.e1i*rhs.e2oi - 1.0*lhs.e23*rhs.e31i - 1.0*lhs.e2i*rhs.e1oi + 1.0*lhs.e31*rhs.e23i - 1.0*lhs.e3i*rhs.e123 + 1.0*lhs.eoi*rhs.e12i;
    result.t.e1oi = 1.0*lhs.e12*rhs.e2oi + 1.0*lhs.e2i*rhs.e12o - 1.0*lhs.e2o*rhs.e12i - 1.0*lhs.e31*rhs.e3oi - 1.0*lhs.e3i*rhs.e31o + 1.0*lhs.e3o*rhs.e31i;
    result.t.e2oi = -1.0*lhs.e12*rhs.e1oi - 1.0*lhs.e1i*rhs.e12o + 1.0*lhs.e1o*rhs.e12i + 1.0*lhs.e23*rhs.e3oi + 1.0*lhs.e3i*rhs.e23o - 1.0*lhs.e3o*rhs.e23i;
    result.t.e3oi = 1.0*lhs.e1i*rhs.e31o - 1.0*lhs.e1o*rhs.e31i - 1.0*lhs.e23*rhs.e2oi - 1.0*lhs.e2i*rhs.e23o + 1.0*lhs.e2o*rhs.e23i + 1.0*lhs.e31*rhs.e1oi;
    result.I5 = 1.0*lhs.e12*rhs.e3oi - 1.0*lhs.e1i*rhs.e23o + 1.0*lhs.e1o*rhs.e23i + 1.0*lhs.e23*rhs.e1oi - 1.0*lhs.e2i*rhs.e31o + 1.0*lhs.e2o*rhs.e31i + 1.0*lhs.e31*rhs.e2oi - 1.0*lhs.e3i*rhs.e12o + 1.0*lhs.e3o*rhs.e12i + 1.0*lhs.eoi*rhs.e123;
    return result;
}
Versor operator*(const Bivector &lhs, const Rotor &rhs) {
    Versor result;
    result.s = -1.0*lhs.e12*rhs.b.e12 + 1.0*lhs.e1i*rhs.b.e1o + 1.0*lhs.e1o*rhs.b.e1i - 1.0*lhs.e23*rhs.b.e23 + 1.0*lhs.e2i*rhs.b.e2o + 1.0*lhs.e2o*rhs.b.e2i - 1.0*lhs.e31*rhs.b.e31 + 1.0*lhs.e3i*rhs.b.e3o + 1.0*lhs.e3o*rhs.b.e3i + 1.0*lhs.eoi*rhs.b.eoi;
    result.b.e23 = 1.0*lhs.e12*rhs.b.e31 + 1.0*lhs.e23*rhs.s + 1.0*lhs.e2i*rhs.b.e3o + 1.0*lhs.e2o*rhs.b.e3i - 1.0*lhs.e31*rhs.b.e12 - 1.0*lhs.e3i*rhs.b.e2o - 1.0*lhs.e3o*rhs.b.e2i;
    result.b.e31 = -1.0*lhs.e12*rhs.b.e23 - 1.0*lhs.e1i*rhs.b.e3o - 1.0*lhs.e1o*rhs.b.e3i + 1.0*lhs.e23*rhs.b.e12 + 1.0*lhs.e31*rhs.s + 1.0*lhs.e3i*rhs.b.e1o + 1.0*lhs.e3o*rhs.b.e1i;
    result.b.e12 = 1.0*lhs.e12*rhs.s + 1.0*lhs.e1i*rhs.b.e2o + 1.0*lhs.e1o*rhs.b.e2i - 1.0*lhs.e23*rhs.b.e31 - 1.0*lhs.e2i*rhs.b.e1o - 1.0*lhs.e2o*rhs.b.e1i + 1.0*lhs.e31*rhs.b.e23;
    result.b.e1o = 1.0*lhs.e12*rhs.b.e2o + 1.0*lhs.e1o*rhs.b.eoi + 1.0*lhs.e1o*rhs.s - 1.0*lhs.e2o*rhs.b.e12 - 1.0*lhs.e31*rhs.b.e3o + 1.0*lhs.e3o*rhs.b.e31 - 1.0*lhs.eoi*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.e12*rhs.b.e1o + 1.0*lhs.e1o*rhs.b.e12 + 1.0*lhs.e23*rhs.b.e3o + 1.0*lhs.e2o*rhs.b.eoi + 1.0*lhs.e2o*rhs.s - 1.0*lhs.e3o*rhs.b.e23 - 1.0*lhs.eoi*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.e1o*rhs.b.e31 - 1.0*lhs.e23*rhs.b.e2o + 1.0*lhs.e2o*rhs.b.e23 + 1.0*lhs.e31*rhs.b.e1o + 1.0*lhs.e3o*rhs.b.eoi + 1.0*lhs.e3o*rhs.s - 1.0*lhs.eoi*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.e12*rhs.b.e2i - 1.0*lhs.e1i*rhs.b.eoi + 1.0*lhs.e1i*rhs.s - 1.0*lhs.e2i*rhs.b.e12 - 1.0*lhs.e31*rhs.b.e3i + 1.0*lhs.e3i*rhs.b.e31 + 1.0*lhs.eoi*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.e12*rhs.b.e1i + 1.0*lhs.e1i*rhs.b.e12 + 1.0*lhs.e23*rhs.b.e3i - 1.0*lhs.e2i*rhs.b.eoi + 1.0*lhs.e2i*rhs.s - 1.0*lhs.e3i*rhs.b.e23 + 1.0*lhs.eoi*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.e1i*rhs.b.e31 - 1.0*lhs.e23*rhs.b.e2i + 1.0*lhs.e2i*rhs.b.e23 + 1.0*lhs.e31*rhs.b.e1i - 1.0*lhs.e3i*rhs.b.eoi + 1.0*lhs.e3i*rhs.s + 1.0*lhs.eoi*rhs.b.e3i;
    result.b.eoi = 1.0*lhs.e1i*rhs.b.e1o - 1.0*lhs.e1o*rhs.b.e1i + 1.0*lhs.e2i*rhs.b.e2o - 1.0*lhs.e2o*rhs.b.e2i + 1.0*lhs.e3i*rhs.b.e3o - 1.0*lhs.e3o*rhs.b.e3i + 1.0*lhs.eoi*rhs.s;
    result.q.e123o = 1.0*lhs.e12*rhs.b.e3o + 1.0*lhs.e1o*rhs.b.e23 + 1.0*lhs.e23*rhs.b.e1o + 1.0*lhs.e2o*rhs.b.e31 + 1.0*lhs.e31*rhs.b.e2o + 1.0*lhs.e3o*rhs.b.e12;
    result.q.e123i = 1.0*lhs.e12*rhs.b.e3i + 1.0*lhs.e1i*rhs.b.e23 + 1.0*lhs.e23*rhs.b.e1i + 1.0*lhs.e2i*rhs.b.e31 + 1.0*lhs.e31*rhs.b.e2i + 1.0*lhs.e3i*rhs.b.e12;
    result.q.e23oi = 1.0*lhs.e23*rhs.b.eoi + 1.0*lhs.e2i*rhs.b.e3o - 1.0*lhs.e2o*rhs.b.e3i - 1.0*lhs.e3i*rhs.b.e2o + 1.0*lhs.e3o*rhs.b.e2i + 1.0*lhs.eoi*rhs.b.e23;
    result.q.e31oi = -1.0*lhs.e1i*rhs.b.e3o + 1.0*lhs.e1o*rhs.b.e3i + 1.0*lhs.e31*rhs.b.eoi + 1.0*lhs.e3i*rhs.b.e1o - 1.0*lhs.e3o*rhs.b.e1i + 1.0*lhs.eoi*rhs.b.e31;
    result.q.e12oi = 1.0*lhs.e12*rhs.b.eoi + 1.0*lhs.e1i*rhs.b.e2o - 1.0*lhs.e1o*rhs.b.e2i - 1.0*lhs.e2i*rhs.b.e1o + 1.0*lhs.e2o*rhs.b.e1i + 1.0*lhs.eoi*rhs.b.e12;
    return result;
}
Versor operator*(const Bivector &lhs, const Versor &rhs) {
    Versor result;
    result.s = -1.0*lhs.e12*rhs.b.e12 + 1.0*lhs.e1i*rhs.b.e1o + 1.0*lhs.e1o*rhs.b.e1i - 1.0*lhs.e23*rhs.b.e23 + 1.0*lhs.e2i*rhs.b.e2o + 1.0*lhs.e2o*rhs.b.e2i - 1.0*lhs.e31*rhs.b.e31 + 1.0*lhs.e3i*rhs.b.e3o + 1.0*lhs.e3o*rhs.b.e3i + 1.0*lhs.eoi*rhs.b.eoi;
    result.b.e23 = 1.0*lhs.e12*rhs.b.e31 + 1.0*lhs.e1i*rhs.q.e123o + 1.0*lhs.e1o*rhs.q.e123i + 1.0*lhs.e23*rhs.s + 1.0*lhs.e2i*rhs.b.e3o + 1.0*lhs.e2o*rhs.b.e3i - 1.0*lhs.e31*rhs.b.e12 - 1.0*lhs.e3i*rhs.b.e2o - 1.0*lhs.e3o*rhs.b.e2i + 1.0*lhs.eoi*rhs.q.e23oi;
    result.b.e31 = -1.0*lhs.e12*rhs.b.e23 - 1.0*lhs.e1i*rhs.b.e3o - 1.0*lhs.e1o*rhs.b.e3i + 1.0*lhs.e23*rhs.b.e12 + 1.0*lhs.e2i*rhs.q.e123o + 1.0*lhs.e2o*rhs.q.e123i + 1.0*lhs.e31*rhs.s + 1.0*lhs.e3i*rhs.b.e1o + 1.0*lhs.e3o*rhs.b.e1i + 1.0*lhs.eoi*rhs.q.e31oi;
    result.b.e12 = 1.0*lhs.e12*rhs.s + 1.0*lhs.e1i*rhs.b.e2o + 1.0*lhs.e1o*rhs.b.e2i - 1.0*lhs.e23*rhs.b.e31 - 1.0*lhs.e2i*rhs.b.e1o - 1.0*lhs.e2o*rhs.b.e1i + 1.0*lhs.e31*rhs.b.e23 + 1.0*lhs.e3i*rhs.q.e123o + 1.0*lhs.e3o*rhs.q.e123i + 1.0*lhs.eoi*rhs.q.e12oi;
    result.b.e1o = 1.0*lhs.e12*rhs.b.e2o + 1.0*lhs.e1o*rhs.b.eoi + 1.0*lhs.e1o*rhs.s - 1.0*lhs.e23*rhs.q.e123o - 1.0*lhs.e2o*rhs.b.e12 - 1.0*lhs.e2o*rhs.q.e12oi - 1.0*lhs.e31*rhs.b.e3o + 1.0*lhs.e3o*rhs.b.e31 + 1.0*lhs.e3o*rhs.q.e31oi - 1.0*lhs.eoi*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.e12*rhs.b.e1o + 1.0*lhs.e1o*rhs.b.e12 + 1.0*lhs.e1o*rhs.q.e12oi + 1.0*lhs.e23*rhs.b.e3o + 1.0*lhs.e2o*rhs.b.eoi + 1.0*lhs.e2o*rhs.s - 1.0*lhs.e31*rhs.q.e123o - 1.0*lhs.e3o*rhs.b.e23 - 1.0*lhs.e3o*rhs.q.e23oi - 1.0*lhs.eoi*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.e12*rhs.q.e123o - 1.0*lhs.e1o*rhs.b.e31 - 1.0*lhs.e1o*rhs.q.e31oi - 1.0*lhs.e23*rhs.b.e2o + 1.0*lhs.e2o*rhs.b.e23 + 1.0*lhs.e2o*rhs.q.e23oi + 1.0*lhs.e31*rhs.b.e1o + 1.0*lhs.e3o*rhs.b.eoi + 1.0*lhs.e3o*rhs.s - 1.0*lhs.eoi*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.e12*rhs.b.e2i - 1.0*lhs.e1i*rhs.b.eoi + 1.0*lhs.e1i*rhs.s - 1.0*lhs.e23*rhs.q.e123i - 1.0*lhs.e2i*rhs.b.e12 + 1.0*lhs.e2i*rhs.q.e12oi - 1.0*lhs.e31*rhs.b.e3i + 1.0*lhs.e3i*rhs.b.e31 - 1.0*lhs.e3i*rhs.q.e31oi + 1.0*lhs.eoi*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.e12*rhs.b.e1i + 1.0*lhs.e1i*rhs.b.e12 - 1.0*lhs.e1i*rhs.q.e12oi + 1.0*lhs.e23*rhs.b.e3i - 1.0*lhs.e2i*rhs.b.eoi + 1.0*lhs.e2i*rhs.s - 1.0*lhs.e31*rhs.q.e123i - 1.0*lhs.e3i*rhs.b.e23 + 1.0*lhs.e3i*rhs.q.e23oi + 1.0*lhs.eoi*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.e12*rhs.q.e123i - 1.0*lhs.e1i*rhs.b.e31 + 1.0*lhs.e1i*rhs.q.e31oi - 1.0*lhs.e23*rhs.b.e2i + 1.0*lhs.e2i*rhs.b.e23 - 1.0*lhs.e2i*rhs.q.e23oi + 1.0*lhs.e31*rhs.b.e1i - 1.0*lhs.e3i*rhs.b.eoi + 1.0*lhs.e3i*rhs.s + 1.0*lhs.eoi*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.e12*rhs.q.e12oi + 1.0*lhs.e1i*rhs.b.e1o - 1.0*lhs.e1o*rhs.b.e1i - 1.0*lhs.e23*rhs.q.e23oi + 1.0*lhs.e2i*rhs.b.e2o - 1.0*lhs.e2o*rhs.b.e2i - 1.0*lhs.e31*rhs.q.e31oi + 1.0*lhs.e3i*rhs.b.e3o - 1.0*lhs.e3o*rhs.b.e3i + 1.0*lhs.eoi*rhs.s;
    result.q.e123o = 1.0*lhs.e12*rhs.b.e3o + 1.0*lhs.e1o*rhs.b.e23 + 1.0*lhs.e1o*rhs.q.e23oi + 1.0*lhs.e23*rhs.b.e1o + 1.0*lhs.e2o*rhs.b.e31 + 1.0*lhs.e2o*rhs.q.e31oi + 1.0*lhs.e31*rhs.b.e2o + 1.0*lhs.e3o*rhs.b.e12 + 1.0*lhs.e3o*rhs.q.e12oi - 1.0*lhs.eoi*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.e12*rhs.b.e3i + 1.0*lhs.e1i*rhs.b.e23 - 1.0*lhs.e1i*rhs.q.e23oi + 1.0*lhs.e23*rhs.b.e1i + 1.0*lhs.e2i*rhs.b.e31 - 1.0*lhs.e2i*rhs.q.e31oi + 1.0*lhs.e31*rhs.b.e2i + 1.0*lhs.e3i*rhs.b.e12 - 1.0*lhs.e3i*rhs.q.e12oi + 1.0*lhs.eoi*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.e12*rhs.q.e31oi + 1.0*lhs.e1i*rhs.q.e123o - 1.0*lhs.e1o*rhs.q.e123i + 1.0*lhs.e23*rhs.b.eoi + 1.0*lhs.e2i*rhs.b.e3o - 1.0*lhs.e2o*rhs.b.e3i - 1.0*lhs.e31*rhs.q.e12oi - 1.0*lhs.e3i*rhs.b.e2o + 1.0*lhs.e3o*rhs.b.e2i + 1.0*lhs.eoi*rhs.b.e23;
    result.q.e31oi = -1.0*lhs.e12*rhs.q.e23oi - 1.0*lhs.e1i*rhs.b.e3o + 1.0*lhs.e1o*rhs.b.e3i + 1.0*lhs.e23*rhs.q.e12oi + 1.0*lhs.e2i*rhs.q.e123o - 1.0*lhs.e2o*rhs.q.e123i + 1.0*lhs.e31*rhs.b.eoi + 1.0*lhs.e3i*rhs.b.e1o - 1.0*lhs.e3o*rhs.b.e1i + 1.0*lhs.eoi*rhs.b.e31;
    result.q.e12oi = 1.0*lhs.e12*rhs.b.eoi + 1.0*lhs.e1i*rhs.b.e2o - 1.0*lhs.e1o*rhs.b.e2i - 1.0*lhs.e23*rhs.q.e31oi - 1.0*lhs.e2i*rhs.b.e1o + 1.0*lhs.e2o*rhs.b.e1i + 1.0*lhs.e31*rhs.q.e23oi + 1.0*lhs.e3i*rhs.q.e123o - 1.0*lhs.e3o*rhs.q.e123i + 1.0*lhs.eoi*rhs.b.e12;
    return result;
}
Multivector operator*(const Bivector &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.e12*rhs.b.e12 + 1.0*lhs.e1i*rhs.b.e1o + 1.0*lhs.e1o*rhs.b.e1i - 1.0*lhs.e23*rhs.b.e23 + 1.0*lhs.e2i*rhs.b.e2o + 1.0*lhs.e2o*rhs.b.e2i - 1.0*lhs.e31*rhs.b.e31 + 1.0*lhs.e3i*rhs.b.e3o + 1.0*lhs.e3o*rhs.b.e3i + 1.0*lhs.eoi*rhs.b.eoi;
    result.v.e1 = 1.0*lhs.e12*rhs.v.e2 - 1.0*lhs.e1i*rhs.v.eo - 1.0*lhs.e1o*rhs.v.ei - 1.0*lhs.e23*rhs.t.e123 + 1.0*lhs.e2i*rhs.t.e12o + 1.0*lhs.e2o*rhs.t.e12i - 1.0*lhs.e31*rhs.v.e3 - 1.0*lhs.e3i*rhs.t.e31o - 1.0*lhs.e3o*rhs.t.e31i + 1.0*lhs.eoi*rhs.t.e1oi;
    result.v.e2 = -1.0*lhs.e12*rhs.v.e1 - 1.0*lhs.e1i*rhs.t.e12o - 1.0*lhs.e1o*rhs.t.e12i + 1.0*lhs.e23*rhs.v.e3 - 1.0*lhs.e2i*rhs.v.eo - 1.0*lhs.e2o*rhs.v.ei - 1.0*lhs.e31*rhs.t.e123 + 1.0*lhs.e3i*rhs.t.e23o + 1.0*lhs.e3o*rhs.t.e23i + 1.0*lhs.eoi*rhs.t.e2oi;
    result.v.e3 = -1.0*lhs.e12*rhs.t.e123 + 1.0*lhs.e1i*rhs.t.e31o + 1.0*lhs.e1o*rhs.t.e31i - 1.0*lhs.e23*rhs.v.e2 - 1.0*lhs.e2i*rhs.t.e23o - 1.0*lhs.e2o*rhs.t.e23i + 1.0*lhs.e31*rhs.v.e1 - 1.0*lhs.e3i*rhs.v.eo - 1.0*lhs.e3o*rhs.v.ei + 1.0*lhs.eoi*rhs.t.e3oi;
    result.v.eo = -1.0*lhs.e12*rhs.t.e12o - 1.0*lhs.e1o*rhs.t.e1oi - 1.0*lhs.e1o*rhs.v.e1 - 1.0*lhs.e23*rhs.t.e23o - 1.0*lhs.e2o*rhs.t.e2oi - 1.0*lhs.e2o*rhs.v.e2 - 1.0*lhs.e31*rhs.t.e31o - 1.0*lhs.e3o*rhs.t.e3oi - 1.0*lhs.e3o*rhs.v.e3 - 1.0*lhs.eoi*rhs.v.eo;
    result.v.ei = -1.0*lhs.e12*rhs.t.e12i + 1.0*lhs.e1i*rhs.t.e1oi - 1.0*lhs.e1i*rhs.v.e1 - 1.0*lhs.e23*rhs.t.e23i + 1.0*lhs.e2i*rhs.t.e2oi - 1.0*lhs.e2i*rhs.v.e2 - 1.0*lhs.e31*rhs.t.e31i + 1.0*lhs.e3i*rhs.t.e3oi - 1.0*lhs.e3i*rhs.v.e3 + 1.0*lhs.eoi*rhs.v.ei;
    result.b.e23 = 1.0*lhs.e12*rhs.b.e31 + 1.0*lhs.e1i*rhs.q.e123o + 1.0*lhs.e1o*rhs.q.e123i + 1.0*lhs.e23*rhs.s + 1.0*lhs.e2i*rhs.b.e3o + 1.0*lhs.e2o*rhs.b.e3i - 1.0*lhs.e31*rhs.b.e12 - 1.0*lhs.e3i*rhs.b.e2o - 1.0*lhs.e3o*rhs.b.e2i + 1.0*lhs.eoi*rhs.q.e23oi;
    result.b.e31 = -1.0*lhs.e12*rhs.b.e23 - 1.0*lhs.e1i*rhs.b.e3o - 1.0*lhs.e1o*rhs.b.e3i + 1.0*lhs.e23*rhs.b.e12 + 1.0*lhs.e2i*rhs.q.e123o + 1.0*lhs.e2o*rhs.q.e123i + 1.0*lhs.e31*rhs.s + 1.0*lhs.e3i*rhs.b.e1o + 1.0*lhs.e3o*rhs.b.e1i + 1.0*lhs.eoi*rhs.q.e31oi;
    result.b.e12 = 1.0*lhs.e12*rhs.s + 1.0*lhs.e1i*rhs.b.e2o + 1.0*lhs.e1o*rhs.b.e2i - 1.0*lhs.e23*rhs.b.e31 - 1.0*lhs.e2i*rhs.b.e1o - 1.0*lhs.e2o*rhs.b.e1i + 1.0*lhs.e31*rhs.b.e23 + 1.0*lhs.e3i*rhs.q.e123o + 1.0*lhs.e3o*rhs.q.e123i + 1.0*lhs.eoi*rhs.q.e12oi;
    result.b.e1o = 1.0*lhs.e12*rhs.b.e2o + 1.0*lhs.e1o*rhs.b.eoi + 1.0*lhs.e1o*rhs.s - 1.0*lhs.e23*rhs.q.e123o - 1.0*lhs.e2o*rhs.b.e12 - 1.0*lhs.e2o*rhs.q.e12oi - 1.0*lhs.e31*rhs.b.e3o + 1.0*lhs.e3o*rhs.b.e31 + 1.0*lhs.e3o*rhs.q.e31oi - 1.0*lhs.eoi*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.e12*rhs.b.e1o + 1.0*lhs.e1o*rhs.b.e12 + 1.0*lhs.e1o*rhs.q.e12oi + 1.0*lhs.e23*rhs.b.e3o + 1.0*lhs.e2o*rhs.b.eoi + 1.0*lhs.e2o*rhs.s - 1.0*lhs.e31*rhs.q.e123o - 1.0*lhs.e3o*rhs.b.e23 - 1.0*lhs.e3o*rhs.q.e23oi - 1.0*lhs.eoi*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.e12*rhs.q.e123o - 1.0*lhs.e1o*rhs.b.e31 - 1.0*lhs.e1o*rhs.q.e31oi - 1.0*lhs.e23*rhs.b.e2o + 1.0*lhs.e2o*rhs.b.e23 + 1.0*lhs.e2o*rhs.q.e23oi + 1.0*lhs.e31*rhs.b.e1o + 1.0*lhs.e3o*rhs.b.eoi + 1.0*lhs.e3o*rhs.s - 1.0*lhs.eoi*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.e12*rhs.b.e2i - 1.0*lhs.e1i*rhs.b.eoi + 1.0*lhs.e1i*rhs.s - 1.0*lhs.e23*rhs.q.e123i - 1.0*lhs.e2i*rhs.b.e12 + 1.0*lhs.e2i*rhs.q.e12oi - 1.0*lhs.e31*rhs.b.e3i + 1.0*lhs.e3i*rhs.b.e31 - 1.0*lhs.e3i*rhs.q.e31oi + 1.0*lhs.eoi*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.e12*rhs.b.e1i + 1.0*lhs.e1i*rhs.b.e12 - 1.0*lhs.e1i*rhs.q.e12oi + 1.0*lhs.e23*rhs.b.e3i - 1.0*lhs.e2i*rhs.b.eoi + 1.0*lhs.e2i*rhs.s - 1.0*lhs.e31*rhs.q.e123i - 1.0*lhs.e3i*rhs.b.e23 + 1.0*lhs.e3i*rhs.q.e23oi + 1.0*lhs.eoi*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.e12*rhs.q.e123i - 1.0*lhs.e1i*rhs.b.e31 + 1.0*lhs.e1i*rhs.q.e31oi - 1.0*lhs.e23*rhs.b.e2i + 1.0*lhs.e2i*rhs.b.e23 - 1.0*lhs.e2i*rhs.q.e23oi + 1.0*lhs.e31*rhs.b.e1i - 1.0*lhs.e3i*rhs.b.eoi + 1.0*lhs.e3i*rhs.s + 1.0*lhs.eoi*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.e12*rhs.q.e12oi + 1.0*lhs.e1i*rhs.b.e1o - 1.0*lhs.e1o*rhs.b.e1i - 1.0*lhs.e23*rhs.q.e23oi + 1.0*lhs.e2i*rhs.b.e2o - 1.0*lhs.e2o*rhs.b.e2i - 1.0*lhs.e31*rhs.q.e31oi + 1.0*lhs.e3i*rhs.b.e3o - 1.0*lhs.e3o*rhs.b.e3i + 1.0*lhs.eoi*rhs.s;
    result.t.e123 = 1.0*lhs.e12*rhs.v.e3 - 1.0*lhs.e1i*rhs.t.e23o - 1.0*lhs.e1o*rhs.t.e23i + 1.0*lhs.e23*rhs.v.e1 - 1.0*lhs.e2i*rhs.t.e31o - 1.0*lhs.e2o*rhs.t.e31i + 1.0*lhs.e31*rhs.v.e2 - 1.0*lhs.e3i*rhs.t.e12o - 1.0*lhs.e3o*rhs.t.e12i + 1.0*lhs.eoi*rhs.I5;
    result.t.e23o = 1.0*lhs.e12*rhs.t.e31o - 1.0*lhs.e1o*rhs.I5 - 1.0*lhs.e1o*rhs.t.e123 + 1.0*lhs.e23*rhs.v.eo - 1.0*lhs.e2o*rhs.t.e3oi - 1.0*lhs.e2o*rhs.v.e3 - 1.0*lhs.e31*rhs.t.e12o + 1.0*lhs.e3o*rhs.t.e2oi + 1.0*lhs.e3o*rhs.v.e2 - 1.0*lhs.eoi*rhs.t.e23o;
    result.t.e31o = -1.0*lhs.e12*rhs.t.e23o + 1.0*lhs.e1o*rhs.t.e3oi + 1.0*lhs.e1o*rhs.v.e3 + 1.0*lhs.e23*rhs.t.e12o - 1.0*lhs.e2o*rhs.I5 - 1.0*lhs.e2o*rhs.t.e123 + 1.0*lhs.e31*rhs.v.eo - 1.0*lhs.e3o*rhs.t.e1oi - 1.0*lhs.e3o*rhs.v.e1 - 1.0*lhs.eoi*rhs.t.e31o;
    result.t.e12o = 1.0*lhs.e12*rhs.v.eo - 1.0*lhs.e1o*rhs.t.e2oi - 1.0*lhs.e1o*rhs.v.e2 - 1.0*lhs.e23*rhs.t.e31o + 1.0*lhs.e2o*rhs.t.e1oi + 1.0*lhs.e2o*rhs.v.e1 + 1.0*lhs.e31*rhs.t.e23o - 1.0*lhs.e3o*rhs.I5 - 1.0*lhs.e3o*rhs.t.e123 - 1.0*lhs.eoi*rhs.t.e12o;
    result.t.e23i = 1.0*lhs.e12*rhs.t.e31i + 1.0*lhs.e1i*rhs.I5 - 1.0*lhs.e1i*rhs.t.e123 + 1.0*lhs.e23*rhs.v.ei + 1.0*lhs.e2i*rhs.t.e3oi - 1.0*lhs.e2i*rhs.v.e3 - 1.0*lhs.e31*rhs.t.e12i - 1.0*lhs.e3i*rhs.t.e2oi + 1.0*lhs.e3i*rhs.v.e2 + 1.0*lhs.eoi*rhs.t.e23i;
    result.t.e31i = -1.0*lhs.e12*rhs.t.e23i - 1.0*lhs.e1i*rhs.t.e3oi + 1.0*lhs.e1i*rhs.v.e3 + 1.0*lhs.e23*rhs.t.e12i + 1.0*lhs.e2i*rhs.I5 - 1.0*lhs.e2i*rhs.t.e123 + 1.0*lhs.e31*rhs.v.ei + 1.0*lhs.e3i*rhs.t.e1oi - 1.0*lhs.e3i*rhs.v.e1 + 1.0*lhs.eoi*rhs.t.e31i;
    result.t.e12i = 1.0*lhs.e12*rhs.v.ei + 1.0*lhs.e1i*rhs.t.e2oi - 1.0*lhs.e1i*rhs.v.e2 - 1.0*lhs.e23*rhs.t.e31i - 1.0*lhs.e2i*rhs.t.e1oi + 1.0*lhs.e2i*rhs.v.e1 + 1.0*lhs.e31*rhs.t.e23i + 1.0*lhs.e3i*rhs.I5 - 1.0*lhs.e3i*rhs.t.e123 + 1.0*lhs.eoi*rhs.t.e12i;
    result.t.e1oi = 1.0*lhs.e12*rhs.t.e2oi - 1.0*lhs.e1i*rhs.v.eo + 1.0*lhs.e1o*rhs.v.ei - 1.0*lhs.e23*rhs.I5 + 1.0*lhs.e2i*rhs.t.e12o - 1.0*lhs.e2o*rhs.t.e12i - 1.0*lhs.e31*rhs.t.e3oi - 1.0*lhs.e3i*rhs.t.e31o + 1.0*lhs.e3o*rhs.t.e31i + 1.0*lhs.eoi*rhs.v.e1;
    result.t.e2oi = -1.0*lhs.e12*rhs.t.e1oi - 1.0*lhs.e1i*rhs.t.e12o + 1.0*lhs.e1o*rhs.t.e12i + 1.0*lhs.e23*rhs.t.e3oi - 1.0*lhs.e2i*rhs.v.eo + 1.0*lhs.e2o*rhs.v.ei - 1.0*lhs.e31*rhs.I5 + 1.0*lhs.e3i*rhs.t.e23o - 1.0*lhs.e3o*rhs.t.e23i + 1.0*lhs.eoi*rhs.v.e2;
    result.t.e3oi = -1.0*lhs.e12*rhs.I5 + 1.0*lhs.e1i*rhs.t.e31o - 1.0*lhs.e1o*rhs.t.e31i - 1.0*lhs.e23*rhs.t.e2oi - 1.0*lhs.e2i*rhs.t.e23o + 1.0*lhs.e2o*rhs.t.e23i + 1.0*lhs.e31*rhs.t.e1oi - 1.0*lhs.e3i*rhs.v.eo + 1.0*lhs.e3o*rhs.v.ei + 1.0*lhs.eoi*rhs.v.e3;
    result.q.e123o = 1.0*lhs.e12*rhs.b.e3o + 1.0*lhs.e1o*rhs.b.e23 + 1.0*lhs.e1o*rhs.q.e23oi + 1.0*lhs.e23*rhs.b.e1o + 1.0*lhs.e2o*rhs.b.e31 + 1.0*lhs.e2o*rhs.q.e31oi + 1.0*lhs.e31*rhs.b.e2o + 1.0*lhs.e3o*rhs.b.e12 + 1.0*lhs.e3o*rhs.q.e12oi - 1.0*lhs.eoi*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.e12*rhs.b.e3i + 1.0*lhs.e1i*rhs.b.e23 - 1.0*lhs.e1i*rhs.q.e23oi + 1.0*lhs.e23*rhs.b.e1i + 1.0*lhs.e2i*rhs.b.e31 - 1.0*lhs.e2i*rhs.q.e31oi + 1.0*lhs.e31*rhs.b.e2i + 1.0*lhs.e3i*rhs.b.e12 - 1.0*lhs.e3i*rhs.q.e12oi + 1.0*lhs.eoi*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.e12*rhs.q.e31oi + 1.0*lhs.e1i*rhs.q.e123o - 1.0*lhs.e1o*rhs.q.e123i + 1.0*lhs.e23*rhs.b.eoi + 1.0*lhs.e2i*rhs.b.e3o - 1.0*lhs.e2o*rhs.b.e3i - 1.0*lhs.e31*rhs.q.e12oi - 1.0*lhs.e3i*rhs.b.e2o + 1.0*lhs.e3o*rhs.b.e2i + 1.0*lhs.eoi*rhs.b.e23;
    result.q.e31oi = -1.0*lhs.e12*rhs.q.e23oi - 1.0*lhs.e1i*rhs.b.e3o + 1.0*lhs.e1o*rhs.b.e3i + 1.0*lhs.e23*rhs.q.e12oi + 1.0*lhs.e2i*rhs.q.e123o - 1.0*lhs.e2o*rhs.q.e123i + 1.0*lhs.e31*rhs.b.eoi + 1.0*lhs.e3i*rhs.b.e1o - 1.0*lhs.e3o*rhs.b.e1i + 1.0*lhs.eoi*rhs.b.e31;
    result.q.e12oi = 1.0*lhs.e12*rhs.b.eoi + 1.0*lhs.e1i*rhs.b.e2o - 1.0*lhs.e1o*rhs.b.e2i - 1.0*lhs.e23*rhs.q.e31oi - 1.0*lhs.e2i*rhs.b.e1o + 1.0*lhs.e2o*rhs.b.e1i + 1.0*lhs.e31*rhs.q.e23oi + 1.0*lhs.e3i*rhs.q.e123o - 1.0*lhs.e3o*rhs.q.e123i + 1.0*lhs.eoi*rhs.b.e12;
    result.I5 = 1.0*lhs.e12*rhs.t.e3oi - 1.0*lhs.e1i*rhs.t.e23o + 1.0*lhs.e1o*rhs.t.e23i + 1.0*lhs.e23*rhs.t.e1oi - 1.0*lhs.e2i*rhs.t.e31o + 1.0*lhs.e2o*rhs.t.e31i + 1.0*lhs.e31*rhs.t.e2oi - 1.0*lhs.e3i*rhs.t.e12o + 1.0*lhs.e3o*rhs.t.e12i + 1.0*lhs.eoi*rhs.t.e123;
    return result;
}
Versor operator*(const Trivector &lhs, const Trivector &rhs) {
    Versor result;
    result.s = -1.0*lhs.e123*rhs.e123 + 1.0*lhs.e12i*rhs.e12o + 1.0*lhs.e12o*rhs.e12i + 1.0*lhs.e1oi*rhs.e1oi + 1.0*lhs.e23i*rhs.e23o + 1.0*lhs.e23o*rhs.e23i + 1.0*lhs.e2oi*rhs.e2oi + 1.0*lhs.e31i*rhs.e31o + 1.0*lhs.e31o*rhs.e31i + 1.0*lhs.e3oi*rhs.e3oi;
    result.b.e23 = -1.0*lhs.e12i*rhs.e31o - 1.0*lhs.e12o*rhs.e31i + 1.0*lhs.e2oi*rhs.e3oi + 1.0*lhs.e31i*rhs.e12o + 1.0*lhs.e31o*rhs.e12i - 1.0*lhs.e3oi*rhs.e2oi;
    result.b.e31 = 1.0*lhs.e12i*rhs.e23o + 1.0*lhs.e12o*rhs.e23i - 1.0*lhs.e1oi*rhs.e3oi - 1.0*lhs.e23i*rhs.e12o - 1.0*lhs.e23o*rhs.e12i + 1.0*lhs.e3oi*rhs.e1oi;
    result.b.e12 = 1.0*lhs.e1oi*rhs.e2oi + 1.0*lhs.e23i*rhs.e31o + 1.0*lhs.e23o*rhs.e31i - 1.0*lhs.e2oi*rhs.e1oi - 1.0*lhs.e31i*rhs.e23o - 1.0*lhs.e31o*rhs.e23i;
    result.b.e1o = -1.0*lhs.e123*rhs.e23o - 1.0*lhs.e12o*rhs.e2oi + 1.0*lhs.e23o*rhs.e123 + 1.0*lhs.e2oi*rhs.e12o + 1.0*lhs.e31o*rhs.e3oi - 1.0*lhs.e3oi*rhs.e31o;
    result.b.e2o = -1.0*lhs.e123*rhs.e31o + 1.0*lhs.e12o*rhs.e1oi - 1.0*lhs.e1oi*rhs.e12o - 1.0*lhs.e23o*rhs.e3oi + 1.0*lhs.e31o*rhs.e123 + 1.0*lhs.e3oi*rhs.e23o;
    result.b.e3o = -1.0*lhs.e123*rhs.e12o + 1.0*lhs.e12o*rhs.e123 + 1.0*lhs.e1oi*rhs.e31o + 1.0*lhs.e23o*rhs.e2oi - 1.0*lhs.e2oi*rhs.e23o - 1.0*lhs.e31o*rhs.e1oi;
    result.b.e1i = -1.0*lhs.e123*rhs.e23i + 1.0*lhs.e12i*rhs.e2oi + 1.0*lhs.e23i*rhs.e123 - 1.0*lhs.e2oi*rhs.e12i - 1.0*lhs.e31i*rhs.e3oi + 1.0*lhs.e3oi*rhs.e31i;
    result.b.e2i = -1.0*lhs.e123*rhs.e31i - 1.0*lhs.e12i*rhs.e1oi + 1.0*lhs.e1oi*rhs.e12i + 1.0*lhs.e23i*rhs.e3oi + 1.0*lhs.e31i*rhs.e123 - 1.0*lhs.e3oi*rhs.e23i;
    result.b.e3i = -1.0*lhs.e123*rhs.e12i + 1.0*lhs.e12i*rhs.e123 - 1.0*lhs.e1oi*rhs.e31i - 1.0*lhs.e23i*rhs.e2oi + 1.0*lhs.e2oi*rhs.e23i + 1.0*lhs.e31i*rhs.e1oi;
    result.b.eoi = 1.0*lhs.e12i*rhs.e12o - 1.0*lhs.e12o*rhs.e12i + 1.0*lhs.e23i*rhs.e23o - 1.0*lhs.e23o*rhs.e23i + 1.0*lhs.e31i*rhs.e31o - 1.0*lhs.e31o*rhs.e31i;
    result.q.e123o = -1.0*lhs.e12o*rhs.e3oi - 1.0*lhs.e1oi*rhs.e23o - 1.0*lhs.e23o*rhs.e1oi - 1.0*lhs.e2oi*rhs.e31o - 1.0*lhs.e31o*rhs.e2oi - 1.0*lhs.e3oi*rhs.e12o;
    result.q.e123i = 1.0*lhs.e12i*rhs.e3oi + 1.0*lhs.e1oi*rhs.e23i + 1.0*lhs.e23i*rhs.e1oi + 1.0*lhs.e2oi*rhs.e31i + 1.0*lhs.e31i*rhs.e2oi + 1.0*lhs.e3oi*rhs.e12i;
    result.q.e23oi = 1.0*lhs.e123*rhs.e1oi - 1.0*lhs.e12i*rhs.e31o + 1.0*lhs.e12o*rhs.e31i + 1.0*lhs.e1oi*rhs.e123 + 1.0*lhs.e31i*rhs.e12o - 1.0*lhs.e31o*rhs.e12i;
    result.q.e31oi = 1.0*lhs.e123*rhs.e2oi + 1.0*lhs.e12i*rhs.e23o - 1.0*lhs.e12o*rhs.e23i - 1.0*lhs.e23i*rhs.e12o + 1.0*lhs.e23o*rhs.e12i + 1.0*lhs.e2oi*rhs.e123;
    result.q.e12oi = 1.0*lhs.e123*rhs.e3oi + 1.0*lhs.e23i*rhs.e31o - 1.0*lhs.e23o*rhs.e31i - 1.0*lhs.e31i*rhs.e23o + 1.0*lhs.e31o*rhs.e23i + 1.0*lhs.e3oi*rhs.e123;
    return result;
}
Multivector operator*(const Trivector &lhs, const Rotor &rhs) {
    Multivector result;
    result.v.e1 = -1.0*lhs.e123*rhs.b.e23 + 1.0*lhs.e12i*rhs.b.e2o + 1.0*lhs.e12o*rhs.b.e2i + 1.0*lhs.e1oi*rhs.b.eoi - 1.0*lhs.e31i*rhs.b.e3o - 1.0*lhs.e31o*rhs.b.e3i;
    result.v.e2 = -1.0*lhs.e123*rhs.b.e31 - 1.0*lhs.e12i*rhs.b.e1o - 1.0*lhs.e12o*rhs.b.e1i + 1.0*lhs.e23i*rhs.b.e3o + 1.0*lhs.e23o*rhs.b.e3i + 1.0*lhs.e2oi*rhs.b.eoi;
    result.v.e3 = -1.0*lhs.e123*rhs.b.e12 - 1.0*lhs.e23i*rhs.b.e2o - 1.0*lhs.e23o*rhs.b.e2i + 1.0*lhs.e31i*rhs.b.e1o + 1.0*lhs.e31o*rhs.b.e1i + 1.0*lhs.e3oi*rhs.b.eoi;
    result.v.eo = -1.0*lhs.e12o*rhs.b.e12 - 1.0*lhs.e1oi*rhs.b.e1o - 1.0*lhs.e23o*rhs.b.e23 - 1.0*lhs.e2oi*rhs.b.e2o - 1.0*lhs.e31o*rhs.b.e31 - 1.0*lhs.e3oi*rhs.b.e3o;
    result.v.ei = -1.0*lhs.e12i*rhs.b.e12 + 1.0*lhs.e1oi*rhs.b.e1i - 1.0*lhs.e23i*rhs.b.e23 + 1.0*lhs.e2oi*rhs.b.e2i - 1.0*lhs.e31i*rhs.b.e31 + 1.0*lhs.e3oi*rhs.b.e3i;
    result.t.e123 = 1.0*lhs.e123*rhs.s + 1.0*lhs.e12i*rhs.b.e3o + 1.0*lhs.e12o*rhs.b.e3i + 1.0*lhs.e23i*rhs.b.e1o + 1.0*lhs.e23o*rhs.b.e1i + 1.0*lhs.e31i*rhs.b.e2o + 1.0*lhs.e31o*rhs.b.e2i;
    result.t.e23o = 1.0*lhs.e123*rhs.b.e1o + 1.0*lhs.e12o*rhs.b.e31 + 1.0*lhs.e23o*rhs.b.eoi + 1.0*lhs.e23o*rhs.s - 1.0*lhs.e2oi*rhs.b.e3o - 1.0*lhs.e31o*rhs.b.e12 + 1.0*lhs.e3oi*rhs.b.e2o;
    result.t.e31o = 1.0*lhs.e123*rhs.b.e2o - 1.0*lhs.e12o*rhs.b.e23 + 1.0*lhs.e1oi*rhs.b.e3o + 1.0*lhs.e23o*rhs.b.e12 + 1.0*lhs.e31o*rhs.b.eoi + 1.0*lhs.e31o*rhs.s - 1.0*lhs.e3oi*rhs.b.e1o;
    result.t.e12o = 1.0*lhs.e123*rhs.b.e3o + 1.0*lhs.e12o*rhs.b.eoi + 1.0*lhs.e12o*rhs.s - 1.0*lhs.e1oi*rhs.b.e2o - 1.0*lhs.e23o*rhs.b.e31 + 1.0*lhs.e2oi*rhs.b.e1o + 1.0*lhs.e31o*rhs.b.e23;
    result.t.e23i = 1.0*lhs.e123*rhs.b.e1i + 1.0*lhs.e12i*rhs.b.e31 - 1.0*lhs.e23i*rhs.b.eoi + 1.0*lhs.e23i*rhs.s + 1.0*lhs.e2oi*rhs.b.e3i - 1.0*lhs.e31i*rhs.b.e12 - 1.0*lhs.e3oi*rhs.b.e2i;
    result.t.e31i = 1.0*lhs.e123*rhs.b.e2i - 1.0*lhs.e12i*rhs.b.e23 - 1.0*lhs.e1oi*rhs.b.e3i + 1.0*lhs.e23i*rhs.b.e12 - 1.0*lhs.e31i*rhs.b.eoi + 1.0*lhs.e31i*rhs.s + 1.0*lhs.e3oi*rhs.b.e1i;
    result.t.e12i = 1.0*lhs.e123*rhs.b.e3i - 1.0*lhs.e12i*rhs.b.eoi + 1.0*lhs.e12i*rhs.s + 1.0*lhs.e1oi*rhs.b.e2i - 1.0*lhs.e23i*rhs.b.e31 - 1.0*lhs.e2oi*rhs.b.e1i + 1.0*lhs.e31i*rhs.b.e23;
    result.t.e1oi = 1.0*lhs.e12i*rhs.b.e2o - 1.0*lhs.e12o*rhs.b.e2i + 1.0*lhs.e1oi*rhs.s - 1.0*lhs.e2oi*rhs.b.e12 - 1.0*lhs.e31i*rhs.b.e3o + 1.0*lhs.e31o*rhs.b.e3i + 1.0*lhs.e3oi*rhs.b.e31;
    result.t.e2oi = -1.0*lhs.e12i*rhs.b.e1o + 1.0*lhs.e12o*rhs.b.e1i + 1.0*lhs.e1oi*rhs.b.e12 + 1.0*lhs.e23i*rhs.b.e3o - 1.0*lhs.e23o*rhs.b.e3i + 1.0*lhs.e2oi*rhs.s - 1.0*lhs.e3oi*rhs.b.e23;
    result.t.e3oi = -1.0*lhs.e1oi*rhs.b.e31 - 1.0*lhs.e23i*rhs.b.e2o + 1.0*lhs.e23o*rhs.b.e2i + 1.0*lhs.e2oi*rhs.b.e23 + 1.0*lhs.e31i*rhs.b.e1o - 1.0*lhs.e31o*rhs.b.e1i + 1.0*lhs.e3oi*rhs.s;
    result.I5 = 1.0*lhs.e123*rhs.b.eoi + 1.0*lhs.e12i*rhs.b.e3o - 1.0*lhs.e12o*rhs.b.e3i + 1.0*lhs.e1oi*rhs.b.e23 + 1.0*lhs.e23i*rhs.b.e1o - 1.0*lhs.e23o*rhs.b.e1i + 1.0*lhs.e2oi*rhs.b.e31 + 1.0*lhs.e31i*rhs.b.e2o - 1.0*lhs.e31o*rhs.b.e2i + 1.0*lhs.e3oi*rhs.b.e12;
    return result;
}
Multivector operator*(const Trivector &lhs, const Versor &rhs) {
    Multivector result;
    result.v.e1 = -1.0*lhs.e123*rhs.b.e23 + 1.0*lhs.e12i*rhs.b.e2o + 1.0*lhs.e12o*rhs.b.e2i + 1.0*lhs.e1oi*rhs.b.eoi - 1.0*lhs.e23i*rhs.q.e123o - 1.0*lhs.e23o*rhs.q.e123i - 1.0*lhs.e2oi*rhs.q.e12oi - 1.0*lhs.e31i*rhs.b.e3o - 1.0*lhs.e31o*rhs.b.e3i + 1.0*lhs.e3oi*rhs.q.e31oi;
    result.v.e2 = -1.0*lhs.e123*rhs.b.e31 - 1.0*lhs.e12i*rhs.b.e1o - 1.0*lhs.e12o*rhs.b.e1i + 1.0*lhs.e1oi*rhs.q.e12oi + 1.0*lhs.e23i*rhs.b.e3o + 1.0*lhs.e23o*rhs.b.e3i + 1.0*lhs.e2oi*rhs.b.eoi - 1.0*lhs.e31i*rhs.q.e123o - 1.0*lhs.e31o*rhs.q.e123i - 1.0*lhs.e3oi*rhs.q.e23oi;
    result.v.e3 = -1.0*lhs.e123*rhs.b.e12 - 1.0*lhs.e12i*rhs.q.e123o - 1.0*lhs.e12o*rhs.q.e123i - 1.0*lhs.e1oi*rhs.q.e31oi - 1.0*lhs.e23i*rhs.b.e2o - 1.0*lhs.e23o*rhs.b.e2i + 1.0*lhs.e2oi*rhs.q.e23oi + 1.0*lhs.e31i*rhs.b.e1o + 1.0*lhs.e31o*rhs.b.e1i + 1.0*lhs.e3oi*rhs.b.eoi;
    result.v.eo = -1.0*lhs.e123*rhs.q.e123o - 1.0*lhs.e12o*rhs.b.e12 - 1.0*lhs.e12o*rhs.q.e12oi - 1.0*lhs.e1oi*rhs.b.e1o - 1.0*lhs.e23o*rhs.b.e23 - 1.0*lhs.e23o*rhs.q.e23oi - 1.0*lhs.e2oi*rhs.b.e2o - 1.0*lhs.e31o*rhs.b.e31 - 1.0*lhs.e31o*rhs.q.e31oi - 1.0*lhs.e3oi*rhs.b.e3o;
    result.v.ei = -1.0*lhs.e123*rhs.q.e123i - 1.0*lhs.e12i*rhs.b.e12 + 1.0*lhs.e12i*rhs.q.e12oi + 1.0*lhs.e1oi*rhs.b.e1i - 1.0*lhs.e23i*rhs.b.e23 + 1.0*lhs.e23i*rhs.q.e23oi + 1.0*lhs.e2oi*rhs.b.e2i - 1.0*lhs.e31i*rhs.b.e31 + 1.0*lhs.e31i*rhs.q.e31oi + 1.0*lhs.e3oi*rhs.b.e3i;
    result.t.e123 = 1.0*lhs.e123*rhs.s + 1.0*lhs.e12i*rhs.b.e3o + 1.0*lhs.e12o*rhs.b.e3i + 1.0*lhs.e1oi*rhs.q.e23oi + 1.0*lhs.e23i*rhs.b.e1o + 1.0*lhs.e23o*rhs.b.e1i + 1.0*lhs.e2oi*rhs.q.e31oi + 1.0*lhs.e31i*rhs.b.e2o + 1.0*lhs.e31o*rhs.b.e2i + 1.0*lhs.e3oi*rhs.q.e12oi;
    result.t.e23o = 1.0*lhs.e123*rhs.b.e1o + 1.0*lhs.e12o*rhs.b.e31 + 1.0*lhs.e12o*rhs.q.e31oi - 1.0*lhs.e1oi*rhs.q.e123o + 1.0*lhs.e23o*rhs.b.eoi + 1.0*lhs.e23o*rhs.s - 1.0*lhs.e2oi*rhs.b.e3o - 1.0*lhs.e31o*rhs.b.e12 - 1.0*lhs.e31o*rhs.q.e12oi + 1.0*lhs.e3oi*rhs.b.e2o;
    result.t.e31o = 1.0*lhs.e123*rhs.b.e2o - 1.0*lhs.e12o*rhs.b.e23 - 1.0*lhs.e12o*rhs.q.e23oi + 1.0*lhs.e1oi*rhs.b.e3o + 1.0*lhs.e23o*rhs.b.e12 + 1.0*lhs.e23o*rhs.q.e12oi - 1.0*lhs.e2oi*rhs.q.e123o + 1.0*lhs.e31o*rhs.b.eoi + 1.0*lhs.e31o*rhs.s - 1.0*lhs.e3oi*rhs.b.e1o;
    result.t.e12o = 1.0*lhs.e123*rhs.b.e3o + 1.0*lhs.e12o*rhs.b.eoi + 1.0*lhs.e12o*rhs.s - 1.0*lhs.e1oi*rhs.b.e2o - 1.0*lhs.e23o*rhs.b.e31 - 1.0*lhs.e23o*rhs.q.e31oi + 1.0*lhs.e2oi*rhs.b.e1o + 1.0*lhs.e31o*rhs.b.e23 + 1.0*lhs.e31o*rhs.q.e23oi - 1.0*lhs.e3oi*rhs.q.e123o;
    result.t.e23i = 1.0*lhs.e123*rhs.b.e1i + 1.0*lhs.e12i*rhs.b.e31 - 1.0*lhs.e12i*rhs.q.e31oi + 1.0*lhs.e1oi*rhs.q.e123i - 1.0*lhs.e23i*rhs.b.eoi + 1.0*lhs.e23i*rhs.s + 1.0*lhs.e2oi*rhs.b.e3i - 1.0*lhs.e31i*rhs.b.e12 + 1.0*lhs.e31i*rhs.q.e12oi - 1.0*lhs.e3oi*rhs.b.e2i;
    result.t.e31i = 1.0*lhs.e123*rhs.b.e2i - 1.0*lhs.e12i*rhs.b.e23 + 1.0*lhs.e12i*rhs.q.e23oi - 1.0*lhs.e1oi*rhs.b.e3i + 1.0*lhs.e23i*rhs.b.e12 - 1.0*lhs.e23i*rhs.q.e12oi + 1.0*lhs.e2oi*rhs.q.e123i - 1.0*lhs.e31i*rhs.b.eoi + 1.0*lhs.e31i*rhs.s + 1.0*lhs.e3oi*rhs.b.e1i;
    result.t.e12i = 1.0*lhs.e123*rhs.b.e3i - 1.0*lhs.e12i*rhs.b.eoi + 1.0*lhs.e12i*rhs.s + 1.0*lhs.e1oi*rhs.b.e2i - 1.0*lhs.e23i*rhs.b.e31 + 1.0*lhs.e23i*rhs.q.e31oi - 1.0*lhs.e2oi*rhs.b.e1i + 1.0*lhs.e31i*rhs.b.e23 - 1.0*lhs.e31i*rhs.q.e23oi + 1.0*lhs.e3oi*rhs.q.e123i;
    result.t.e1oi = -1.0*lhs.e123*rhs.q.e23oi + 1.0*lhs.e12i*rhs.b.e2o - 1.0*lhs.e12o*rhs.b.e2i + 1.0*lhs.e1oi*rhs.s - 1.0*lhs.e23i*rhs.q.e123o + 1.0*lhs.e23o*rhs.q.e123i - 1.0*lhs.e2oi*rhs.b.e12 - 1.0*lhs.e31i*rhs.b.e3o + 1.0*lhs.e31o*rhs.b.e3i + 1.0*lhs.e3oi*rhs.b.e31;
    result.t.e2oi = -1.0*lhs.e123*rhs.q.e31oi - 1.0*lhs.e12i*rhs.b.e1o + 1.0*lhs.e12o*rhs.b.e1i + 1.0*lhs.e1oi*rhs.b.e12 + 1.0*lhs.e23i*rhs.b.e3o - 1.0*lhs.e23o*rhs.b.e3i + 1.0*lhs.e2oi*rhs.s - 1.0*lhs.e31i*rhs.q.e123o + 1.0*lhs.e31o*rhs.q.e123i - 1.0*lhs.e3oi*rhs.b.e23;
    result.t.e3oi = -1.0*lhs.e123*rhs.q.e12oi - 1.0*lhs.e12i*rhs.q.e123o + 1.0*lhs.e12o*rhs.q.e123i - 1.0*lhs.e1oi*rhs.b.e31 - 1.0*lhs.e23i*rhs.b.e2o + 1.0*lhs.e23o*rhs.b.e2i + 1.0*lhs.e2oi*rhs.b.e23 + 1.0*lhs.e31i*rhs.b.e1o - 1.0*lhs.e31o*rhs.b.e1i + 1.0*lhs.e3oi*rhs.s;
    result.I5 = 1.0*lhs.e123*rhs.b.eoi + 1.0*lhs.e12i*rhs.b.e3o - 1.0*lhs.e12o*rhs.b.e3i + 1.0*lhs.e1oi*rhs.b.e23 + 1.0*lhs.e23i*rhs.b.e1o - 1.0*lhs.e23o*rhs.b.e1i + 1.0*lhs.e2oi*rhs.b.e31 + 1.0*lhs.e31i*rhs.b.e2o - 1.0*lhs.e31o*rhs.b.e2i + 1.0*lhs.e3oi*rhs.b.e12;
    return result;
}
Multivector operator*(const Trivector &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.e123*rhs.t.e123 + 1.0*lhs.e12i*rhs.t.e12o + 1.0*lhs.e12o*rhs.t.e12i + 1.0*lhs.e1oi*rhs.t.e1oi + 1.0*lhs.e23i*rhs.t.e23o + 1.0*lhs.e23o*rhs.t.e23i + 1.0*lhs.e2oi*rhs.t.e2oi + 1.0*lhs.e31i*rhs.t.e31o + 1.0*lhs.e31o*rhs.t.e31i + 1.0*lhs.e3oi*rhs.t.e3oi;
    result.v.e1 = -1.0*lhs.e123*rhs.b.e23 + 1.0*lhs.e12i*rhs.b.e2o + 1.0*lhs.e12o*rhs.b.e2i + 1.0*lhs.e1oi*rhs.b.eoi - 1.0*lhs.e23i*rhs.q.e123o - 1.0*lhs.e23o*rhs.q.e123i - 1.0*lhs.e2oi*rhs.q.e12oi - 1.0*lhs.e31i*rhs.b.e3o - 1.0*lhs.e31o*rhs.b.e3i + 1.0*lhs.e3oi*rhs.q.e31oi;
    result.v.e2 = -1.0*lhs.e123*rhs.b.e31 - 1.0*lhs.e12i*rhs.b.e1o - 1.0*lhs.e12o*rhs.b.e1i + 1.0*lhs.e1oi*rhs.q.e12oi + 1.0*lhs.e23i*rhs.b.e3o + 1.0*lhs.e23o*rhs.b.e3i + 1.0*lhs.e2oi*rhs.b.eoi - 1.0*lhs.e31i*rhs.q.e123o - 1.0*lhs.e31o*rhs.q.e123i - 1.0*lhs.e3oi*rhs.q.e23oi;
    result.v.e3 = -1.0*lhs.e123*rhs.b.e12 - 1.0*lhs.e12i*rhs.q.e123o - 1.0*lhs.e12o*rhs.q.e123i - 1.0*lhs.e1oi*rhs.q.e31oi - 1.0*lhs.e23i*rhs.b.e2o - 1.0*lhs.e23o*rhs.b.e2i + 1.0*lhs.e2oi*rhs.q.e23oi + 1.0*lhs.e31i*rhs.b.e1o + 1.0*lhs.e31o*rhs.b.e1i + 1.0*lhs.e3oi*rhs.b.eoi;
    result.v.eo = -1.0*lhs.e123*rhs.q.e123o - 1.0*lhs.e12o*rhs.b.e12 - 1.0*lhs.e12o*rhs.q.e12oi - 1.0*lhs.e1oi*rhs.b.e1o - 1.0*lhs.e23o*rhs.b.e23 - 1.0*lhs.e23o*rhs.q.e23oi - 1.0*lhs.e2oi*rhs.b.e2o - 1.0*lhs.e31o*rhs.b.e31 - 1.0*lhs.e31o*rhs.q.e31oi - 1.0*lhs.e3oi*rhs.b.e3o;
    result.v.ei = -1.0*lhs.e123*rhs.q.e123i - 1.0*lhs.e12i*rhs.b.e12 + 1.0*lhs.e12i*rhs.q.e12oi + 1.0*lhs.e1oi*rhs.b.e1i - 1.0*lhs.e23i*rhs.b.e23 + 1.0*lhs.e23i*rhs.q.e23oi + 1.0*lhs.e2oi*rhs.b.e2i - 1.0*lhs.e31i*rhs.b.e31 + 1.0*lhs.e31i*rhs.q.e31oi + 1.0*lhs.e3oi*rhs.b.e3i;
    result.b.e23 = 1.0*lhs.e123*rhs.v.e1 - 1.0*lhs.e12i*rhs.t.e31o - 1.0*lhs.e12o*rhs.t.e31i + 1.0*lhs.e1oi*rhs.I5 - 1.0*lhs.e23i*rhs.v.eo - 1.0*lhs.e23o*rhs.v.ei + 1.0*lhs.e2oi*rhs.t.e3oi + 1.0*lhs.e31i*rhs.t.e12o + 1.0*lhs.e31o*rhs.t.e12i - 1.0*lhs.e3oi*rhs.t.e2oi;
    result.b.e31 = 1.0*lhs.e123*rhs.v.e2 + 1.0*lhs.e12i*rhs.t.e23o + 1.0*lhs.e12o*rhs.t.e23i - 1.0*lhs.e1oi*rhs.t.e3oi - 1.0*lhs.e23i*rhs.t.e12o - 1.0*lhs.e23o*rhs.t.e12i + 1.0*lhs.e2oi*rhs.I5 - 1.0*lhs.e31i*rhs.v.eo - 1.0*lhs.e31o*rhs.v.ei + 1.0*lhs.e3oi*rhs.t.e1oi;
    result.b.e12 = 1.0*lhs.e123*rhs.v.e3 - 1.0*lhs.e12i*rhs.v.eo - 1.0*lhs.e12o*rhs.v.ei + 1.0*lhs.e1oi*rhs.t.e2oi + 1.0*lhs.e23i*rhs.t.e31o + 1.0*lhs.e23o*rhs.t.e31i - 1.0*lhs.e2oi*rhs.t.e1oi - 1.0*lhs.e31i*rhs.t.e23o - 1.0*lhs.e31o*rhs.t.e23i + 1.0*lhs.e3oi*rhs.I5;
    result.b.e1o = -1.0*lhs.e123*rhs.t.e23o - 1.0*lhs.e12o*rhs.t.e2oi - 1.0*lhs.e12o*rhs.v.e2 - 1.0*lhs.e1oi*rhs.v.eo + 1.0*lhs.e23o*rhs.I5 + 1.0*lhs.e23o*rhs.t.e123 + 1.0*lhs.e2oi*rhs.t.e12o + 1.0*lhs.e31o*rhs.t.e3oi + 1.0*lhs.e31o*rhs.v.e3 - 1.0*lhs.e3oi*rhs.t.e31o;
    result.b.e2o = -1.0*lhs.e123*rhs.t.e31o + 1.0*lhs.e12o*rhs.t.e1oi + 1.0*lhs.e12o*rhs.v.e1 - 1.0*lhs.e1oi*rhs.t.e12o - 1.0*lhs.e23o*rhs.t.e3oi - 1.0*lhs.e23o*rhs.v.e3 - 1.0*lhs.e2oi*rhs.v.eo + 1.0*lhs.e31o*rhs.I5 + 1.0*lhs.e31o*rhs.t.e123 + 1.0*lhs.e3oi*rhs.t.e23o;
    result.b.e3o = -1.0*lhs.e123*rhs.t.e12o + 1.0*lhs.e12o*rhs.I5 + 1.0*lhs.e12o*rhs.t.e123 + 1.0*lhs.e1oi*rhs.t.e31o + 1.0*lhs.e23o*rhs.t.e2oi + 1.0*lhs.e23o*rhs.v.e2 - 1.0*lhs.e2oi*rhs.t.e23o - 1.0*lhs.e31o*rhs.t.e1oi - 1.0*lhs.e31o*rhs.v.e1 - 1.0*lhs.e3oi*rhs.v.eo;
    result.b.e1i = -1.0*lhs.e123*rhs.t.e23i + 1.0*lhs.e12i*rhs.t.e2oi - 1.0*lhs.e12i*rhs.v.e2 + 1.0*lhs.e1oi*rhs.v.ei - 1.0*lhs.e23i*rhs.I5 + 1.0*lhs.e23i*rhs.t.e123 - 1.0*lhs.e2oi*rhs.t.e12i - 1.0*lhs.e31i*rhs.t.e3oi + 1.0*lhs.e31i*rhs.v.e3 + 1.0*lhs.e3oi*rhs.t.e31i;
    result.b.e2i = -1.0*lhs.e123*rhs.t.e31i - 1.0*lhs.e12i*rhs.t.e1oi + 1.0*lhs.e12i*rhs.v.e1 + 1.0*lhs.e1oi*rhs.t.e12i + 1.0*lhs.e23i*rhs.t.e3oi - 1.0*lhs.e23i*rhs.v.e3 + 1.0*lhs.e2oi*rhs.v.ei - 1.0*lhs.e31i*rhs.I5 + 1.0*lhs.e31i*rhs.t.e123 - 1.0*lhs.e3oi*rhs.t.e23i;
    result.b.e3i = -1.0*lhs.e123*rhs.t.e12i - 1.0*lhs.e12i*rhs.I5 + 1.0*lhs.e12i*rhs.t.e123 - 1.0*lhs.e1oi*rhs.t.e31i - 1.0*lhs.e23i*rhs.t.e2oi + 1.0*lhs.e23i*rhs.v.e2 + 1.0*lhs.e2oi*rhs.t.e23i + 1.0*lhs.e31i*rhs.t.e1oi - 1.0*lhs.e31i*rhs.v.e1 + 1.0*lhs.e3oi*rhs.v.ei;
    result.b.eoi = -1.0*lhs.e123*rhs.I5 + 1.0*lhs.e12i*rhs.t.e12o - 1.0*lhs.e12o*rhs.t.e12i + 1.0*lhs.e1oi*rhs.v.e1 + 1.0*lhs.e23i*rhs.t.e23o - 1.0*lhs.e23o*rhs.t.e23i + 1.0*lhs.e2oi*rhs.v.e2 + 1.0*lhs.e31i*rhs.t.e31o - 1.0*lhs.e31o*rhs.t.e31i + 1.0*lhs.e3oi*rhs.v.e3;
    result.t.e123 = 1.0*lhs.e123*rhs.s + 1.0*lhs.e12i*rhs.b.e3o + 1.0*lhs.e12o*rhs.b.e3i + 1.0*lhs.e1oi*rhs.q.e23oi + 1.0*lhs.e23i*rhs.b.e1o + 1.0*lhs.e23o*rhs.b.e1i + 1.0*lhs.e2oi*rhs.q.e31oi + 1.0*lhs.e31i*rhs.b.e2o + 1.0*lhs.e31o*rhs.b.e2i + 1.0*lhs.e3oi*rhs.q.e12oi;
    result.t.e23o = 1.0*lhs.e123*rhs.b.e1o + 1.0*lhs.e12o*rhs.b.e31 + 1.0*lhs.e12o*rhs.q.e31oi - 1.0*lhs.e1oi*rhs.q.e123o + 1.0*lhs.e23o*rhs.b.eoi + 1.0*lhs.e23o*rhs.s - 1.0*lhs.e2oi*rhs.b.e3o - 1.0*lhs.e31o*rhs.b.e12 - 1.0*lhs.e31o*rhs.q.e12oi + 1.0*lhs.e3oi*rhs.b.e2o;
    result.t.e31o = 1.0*lhs.e123*rhs.b.e2o - 1.0*lhs.e12o*rhs.b.e23 - 1.0*lhs.e12o*rhs.q.e23oi + 1.0*lhs.e1oi*rhs.b.e3o + 1.0*lhs.e23o*rhs.b.e12 + 1.0*lhs.e23o*rhs.q.e12oi - 1.0*lhs.e2oi*rhs.q.e123o + 1.0*lhs.e31o*rhs.b.eoi + 1.0*lhs.e31o*rhs.s - 1.0*lhs.e3oi*rhs.b.e1o;
    result.t.e12o = 1.0*lhs.e123*rhs.b.e3o + 1.0*lhs.e12o*rhs.b.eoi + 1.0*lhs.e12o*rhs.s - 1.0*lhs.e1oi*rhs.b.e2o - 1.0*lhs.e23o*rhs.b.e31 - 1.0*lhs.e23o*rhs.q.e31oi + 1.0*lhs.e2oi*rhs.b.e1o + 1.0*lhs.e31o*rhs.b.e23 + 1.0*lhs.e31o*rhs.q.e23oi - 1.0*lhs.e3oi*rhs.q.e123o;
    result.t.e23i = 1.0*lhs.e123*rhs.b.e1i + 1.0*lhs.e12i*rhs.b.e31 - 1.0*lhs.e12i*rhs.q.e31oi + 1.0*lhs.e1oi*rhs.q.e123i - 1.0*lhs.e23i*rhs.b.eoi + 1.0*lhs.e23i*rhs.s + 1.0*lhs.e2oi*rhs.b.e3i - 1.0*lhs.e31i*rhs.b.e12 + 1.0*lhs.e31i*rhs.q.e12oi - 1.0*lhs.e3oi*rhs.b.e2i;
    result.t.e31i = 1.0*lhs.e123*rhs.b.e2i - 1.0*lhs.e12i*rhs.b.e23 + 1.0*lhs.e12i*rhs.q.e23oi - 1.0*lhs.e1oi*rhs.b.e3i + 1.0*lhs.e23i*rhs.b.e12 - 1.0*lhs.e23i*rhs.q.e12oi + 1.0*lhs.e2oi*rhs.q.e123i - 1.0*lhs.e31i*rhs.b.eoi + 1.0*lhs.e31i*rhs.s + 1.0*lhs.e3oi*rhs.b.e1i;
    result.t.e12i = 1.0*lhs.e123*rhs.b.e3i - 1.0*lhs.e12i*rhs.b.eoi + 1.0*lhs.e12i*rhs.s + 1.0*lhs.e1oi*rhs.b.e2i - 1.0*lhs.e23i*rhs.b.e31 + 1.0*lhs.e23i*rhs.q.e31oi - 1.0*lhs.e2oi*rhs.b.e1i + 1.0*lhs.e31i*rhs.b.e23 - 1.0*lhs.e31i*rhs.q.e23oi + 1.0*lhs.e3oi*rhs.q.e123i;
    result.t.e1oi = -1.0*lhs.e123*rhs.q.e23oi + 1.0*lhs.e12i*rhs.b.e2o - 1.0*lhs.e12o*rhs.b.e2i + 1.0*lhs.e1oi*rhs.s - 1.0*lhs.e23i*rhs.q.e123o + 1.0*lhs.e23o*rhs.q.e123i - 1.0*lhs.e2oi*rhs.b.e12 - 1.0*lhs.e31i*rhs.b.e3o + 1.0*lhs.e31o*rhs.b.e3i + 1.0*lhs.e3oi*rhs.b.e31;
    result.t.e2oi = -1.0*lhs.e123*rhs.q.e31oi - 1.0*lhs.e12i*rhs.b.e1o + 1.0*lhs.e12o*rhs.b.e1i + 1.0*lhs.e1oi*rhs.b.e12 + 1.0*lhs.e23i*rhs.b.e3o - 1.0*lhs.e23o*rhs.b.e3i + 1.0*lhs.e2oi*rhs.s - 1.0*lhs.e31i*rhs.q.e123o + 1.0*lhs.e31o*rhs.q.e123i - 1.0*lhs.e3oi*rhs.b.e23;
    result.t.e3oi = -1.0*lhs.e123*rhs.q.e12oi - 1.0*lhs.e12i*rhs.q.e123o + 1.0*lhs.e12o*rhs.q.e123i - 1.0*lhs.e1oi*rhs.b.e31 - 1.0*lhs.e23i*rhs.b.e2o + 1.0*lhs.e23o*rhs.b.e2i + 1.0*lhs.e2oi*rhs.b.e23 + 1.0*lhs.e31i*rhs.b.e1o - 1.0*lhs.e31o*rhs.b.e1i + 1.0*lhs.e3oi*rhs.s;
    result.q.e123o = 1.0*lhs.e123*rhs.v.eo - 1.0*lhs.e12o*rhs.t.e3oi - 1.0*lhs.e12o*rhs.v.e3 - 1.0*lhs.e1oi*rhs.t.e23o - 1.0*lhs.e23o*rhs.t.e1oi - 1.0*lhs.e23o*rhs.v.e1 - 1.0*lhs.e2oi*rhs.t.e31o - 1.0*lhs.e31o*rhs.t.e2oi - 1.0*lhs.e31o*rhs.v.e2 - 1.0*lhs.e3oi*rhs.t.e12o;
    result.q.e123i = 1.0*lhs.e123*rhs.v.ei + 1.0*lhs.e12i*rhs.t.e3oi - 1.0*lhs.e12i*rhs.v.e3 + 1.0*lhs.e1oi*rhs.t.e23i + 1.0*lhs.e23i*rhs.t.e1oi - 1.0*lhs.e23i*rhs.v.e1 + 1.0*lhs.e2oi*rhs.t.e31i + 1.0*lhs.e31i*rhs.t.e2oi - 1.0*lhs.e31i*rhs.v.e2 + 1.0*lhs.e3oi*rhs.t.e12i;
    result.q.e23oi = 1.0*lhs.e123*rhs.t.e1oi - 1.0*lhs.e12i*rhs.t.e31o + 1.0*lhs.e12o*rhs.t.e31i + 1.0*lhs.e1oi*rhs.t.e123 - 1.0*lhs.e23i*rhs.v.eo + 1.0*lhs.e23o*rhs.v.ei + 1.0*lhs.e2oi*rhs.v.e3 + 1.0*lhs.e31i*rhs.t.e12o - 1.0*lhs.e31o*rhs.t.e12i - 1.0*lhs.e3oi*rhs.v.e2;
    result.q.e31oi = 1.0*lhs.e123*rhs.t.e2oi + 1.0*lhs.e12i*rhs.t.e23o - 1.0*lhs.e12o*rhs.t.e23i - 1.0*lhs.e1oi*rhs.v.e3 - 1.0*lhs.e23i*rhs.t.e12o + 1.0*lhs.e23o*rhs.t.e12i + 1.0*lhs.e2oi*rhs.t.e123 - 1.0*lhs.e31i*rhs.v.eo + 1.0*lhs.e31o*rhs.v.ei + 1.0*lhs.e3oi*rhs.v.e1;
    result.q.e12oi = 1.0*lhs.e123*rhs.t.e3oi - 1.0*lhs.e12i*rhs.v.eo + 1.0*lhs.e12o*rhs.v.ei + 1.0*lhs.e1oi*rhs.v.e2 + 1.0*lhs.e23i*rhs.t.e31o - 1.0*lhs.e23o*rhs.t.e31i - 1.0*lhs.e2oi*rhs.v.e1 - 1.0*lhs.e31i*rhs.t.e23o + 1.0*lhs.e31o*rhs.t.e23i + 1.0*lhs.e3oi*rhs.t.e123;
    result.I5 = 1.0*lhs.e123*rhs.b.eoi + 1.0*lhs.e12i*rhs.b.e3o - 1.0*lhs.e12o*rhs.b.e3i + 1.0*lhs.e1oi*rhs.b.e23 + 1.0*lhs.e23i*rhs.b.e1o - 1.0*lhs.e23o*rhs.b.e1i + 1.0*lhs.e2oi*rhs.b.e31 + 1.0*lhs.e31i*rhs.b.e2o - 1.0*lhs.e31o*rhs.b.e2i + 1.0*lhs.e3oi*rhs.b.e12;
    return result;
}
Versor operator*(const Rotor &lhs, const Rotor &rhs) {
    Versor result;
    result.s = -1.0*lhs.b.e12*rhs.b.e12 + 1.0*lhs.b.e1i*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.b.e23 + 1.0*lhs.b.e2i*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e31 + 1.0*lhs.b.e3i*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.b.eoi + 1.0*lhs.s*rhs.s;
    result.b.e23 = 1.0*lhs.b.e12*rhs.b.e31 + 1.0*lhs.b.e23*rhs.s + 1.0*lhs.b.e2i*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.b.e2o - 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.s*rhs.b.e23;
    result.b.e31 = -1.0*lhs.b.e12*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.b.e3o - 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e12 + 1.0*lhs.b.e31*rhs.s + 1.0*lhs.b.e3i*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.s*rhs.b.e31;
    result.b.e12 = 1.0*lhs.b.e12*rhs.s + 1.0*lhs.b.e1i*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.b.e1o - 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e23 + 1.0*lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.eoi + 1.0*lhs.b.e1o*rhs.s - 1.0*lhs.b.e2o*rhs.b.e12 - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e31 - 1.0*lhs.b.eoi*rhs.b.e1o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e12 + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.eoi + 1.0*lhs.b.e2o*rhs.s - 1.0*lhs.b.e3o*rhs.b.e23 - 1.0*lhs.b.eoi*rhs.b.e2o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e1o*rhs.b.e31 - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e23 + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.eoi + 1.0*lhs.b.e3o*rhs.s - 1.0*lhs.b.eoi*rhs.b.e3o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e1i*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.s - 1.0*lhs.b.e2i*rhs.b.e12 - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.b.e3i*rhs.b.e31 + 1.0*lhs.b.eoi*rhs.b.e1i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e1i*rhs.b.e12 + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e2i*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.s - 1.0*lhs.b.e3i*rhs.b.e23 + 1.0*lhs.b.eoi*rhs.b.e2i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e1i*rhs.b.e31 - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e2i*rhs.b.e23 + 1.0*lhs.b.e31*rhs.b.e1i - 1.0*lhs.b.e3i*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.s + 1.0*lhs.b.eoi*rhs.b.e3i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = 1.0*lhs.b.e1i*rhs.b.e1o - 1.0*lhs.b.e1o*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e2o - 1.0*lhs.b.e2o*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e3o - 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.s + 1.0*lhs.s*rhs.b.eoi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e23 + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e31 + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e12;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e1i*rhs.b.e23 + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e31 + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e12;
    result.q.e23oi = 1.0*lhs.b.e23*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.b.e3o - 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e3i*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = -1.0*lhs.b.e1i*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.b.e1o - 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.b.e2o - 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e2i*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e12;
    return result;
}
Versor operator*(const Rotor &lhs, const Versor &rhs) {
    Versor result;
    result.s = -1.0*lhs.b.e12*rhs.b.e12 + 1.0*lhs.b.e1i*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.b.e23 + 1.0*lhs.b.e2i*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e31 + 1.0*lhs.b.e3i*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.b.eoi + 1.0*lhs.s*rhs.s;
    result.b.e23 = 1.0*lhs.b.e12*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e123o + 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.s + 1.0*lhs.b.e2i*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.b.e2o - 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.q.e23oi + 1.0*lhs.s*rhs.b.e23;
    result.b.e31 = -1.0*lhs.b.e12*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.b.e3o - 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e123o + 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.s + 1.0*lhs.b.e3i*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.q.e31oi + 1.0*lhs.s*rhs.b.e31;
    result.b.e12 = 1.0*lhs.b.e12*rhs.s + 1.0*lhs.b.e1i*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.b.e1o - 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e123o + 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.q.e12oi + 1.0*lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.eoi + 1.0*lhs.b.e1o*rhs.s - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.b.e12 - 1.0*lhs.b.e2o*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e31 + 1.0*lhs.b.e3o*rhs.q.e31oi - 1.0*lhs.b.eoi*rhs.b.e1o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e12 + 1.0*lhs.b.e1o*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.eoi + 1.0*lhs.b.e2o*rhs.s - 1.0*lhs.b.e31*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.b.e23 - 1.0*lhs.b.e3o*rhs.q.e23oi - 1.0*lhs.b.eoi*rhs.b.e2o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.b.e31 - 1.0*lhs.b.e1o*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e23 + 1.0*lhs.b.e2o*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.eoi + 1.0*lhs.b.e3o*rhs.s - 1.0*lhs.b.eoi*rhs.b.e3o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e1i*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.s - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e2i*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.b.e3i*rhs.b.e31 - 1.0*lhs.b.e3i*rhs.q.e31oi + 1.0*lhs.b.eoi*rhs.b.e1i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e1i*rhs.b.e12 - 1.0*lhs.b.e1i*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e2i*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.s - 1.0*lhs.b.e31*rhs.q.e123i - 1.0*lhs.b.e3i*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e23oi + 1.0*lhs.b.eoi*rhs.b.e2i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e1i*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e2i*rhs.b.e23 - 1.0*lhs.b.e2i*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1i - 1.0*lhs.b.e3i*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.s + 1.0*lhs.b.eoi*rhs.b.e3i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.q.e12oi + 1.0*lhs.b.e1i*rhs.b.e1o - 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.q.e23oi + 1.0*lhs.b.e2i*rhs.b.e2o - 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.b.e3i*rhs.b.e3o - 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.s + 1.0*lhs.s*rhs.b.eoi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e23 + 1.0*lhs.b.e1o*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e31 + 1.0*lhs.b.e2o*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e12 + 1.0*lhs.b.e3o*rhs.q.e12oi - 1.0*lhs.b.eoi*rhs.q.e123o + 1.0*lhs.s*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e1i*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.q.e12oi + 1.0*lhs.b.eoi*rhs.q.e123i + 1.0*lhs.s*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e1i*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.b.e3o - 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e12oi - 1.0*lhs.b.e3i*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.b.e23 + 1.0*lhs.s*rhs.q.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.q.e23oi - 1.0*lhs.b.e1i*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e2i*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.b.e1o - 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e31 + 1.0*lhs.s*rhs.q.e31oi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.b.e2o - 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e31oi - 1.0*lhs.b.e2i*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.b.e3i*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.b.e12 + 1.0*lhs.s*rhs.q.e12oi;
    return result;
}
Multivector operator*(const Rotor &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.b.e12*rhs.b.e12 + 1.0*lhs.b.e1i*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.b.e23 + 1.0*lhs.b.e2i*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e31 + 1.0*lhs.b.e3i*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.b.eoi + 1.0*lhs.s*rhs.s;
    result.v.e1 = 1.0*lhs.b.e12*rhs.v.e2 - 1.0*lhs.b.e1i*rhs.v.eo - 1.0*lhs.b.e1o*rhs.v.ei - 1.0*lhs.b.e23*rhs.t.e123 + 1.0*lhs.b.e2i*rhs.t.e12o + 1.0*lhs.b.e2o*rhs.t.e12i - 1.0*lhs.b.e31*rhs.v.e3 - 1.0*lhs.b.e3i*rhs.t.e31o - 1.0*lhs.b.e3o*rhs.t.e31i + 1.0*lhs.b.eoi*rhs.t.e1oi + 1.0*lhs.s*rhs.v.e1;
    result.v.e2 = -1.0*lhs.b.e12*rhs.v.e1 - 1.0*lhs.b.e1i*rhs.t.e12o - 1.0*lhs.b.e1o*rhs.t.e12i + 1.0*lhs.b.e23*rhs.v.e3 - 1.0*lhs.b.e2i*rhs.v.eo - 1.0*lhs.b.e2o*rhs.v.ei - 1.0*lhs.b.e31*rhs.t.e123 + 1.0*lhs.b.e3i*rhs.t.e23o + 1.0*lhs.b.e3o*rhs.t.e23i + 1.0*lhs.b.eoi*rhs.t.e2oi + 1.0*lhs.s*rhs.v.e2;
    result.v.e3 = -1.0*lhs.b.e12*rhs.t.e123 + 1.0*lhs.b.e1i*rhs.t.e31o + 1.0*lhs.b.e1o*rhs.t.e31i - 1.0*lhs.b.e23*rhs.v.e2 - 1.0*lhs.b.e2i*rhs.t.e23o - 1.0*lhs.b.e2o*rhs.t.e23i + 1.0*lhs.b.e31*rhs.v.e1 - 1.0*lhs.b.e3i*rhs.v.eo - 1.0*lhs.b.e3o*rhs.v.ei + 1.0*lhs.b.eoi*rhs.t.e3oi + 1.0*lhs.s*rhs.v.e3;
    result.v.eo = -1.0*lhs.b.e12*rhs.t.e12o - 1.0*lhs.b.e1o*rhs.t.e1oi - 1.0*lhs.b.e1o*rhs.v.e1 - 1.0*lhs.b.e23*rhs.t.e23o - 1.0*lhs.b.e2o*rhs.t.e2oi - 1.0*lhs.b.e2o*rhs.v.e2 - 1.0*lhs.b.e31*rhs.t.e31o - 1.0*lhs.b.e3o*rhs.t.e3oi - 1.0*lhs.b.e3o*rhs.v.e3 - 1.0*lhs.b.eoi*rhs.v.eo + 1.0*lhs.s*rhs.v.eo;
    result.v.ei = -1.0*lhs.b.e12*rhs.t.e12i + 1.0*lhs.b.e1i*rhs.t.e1oi - 1.0*lhs.b.e1i*rhs.v.e1 - 1.0*lhs.b.e23*rhs.t.e23i + 1.0*lhs.b.e2i*rhs.t.e2oi - 1.0*lhs.b.e2i*rhs.v.e2 - 1.0*lhs.b.e31*rhs.t.e31i + 1.0*lhs.b.e3i*rhs.t.e3oi - 1.0*lhs.b.e3i*rhs.v.e3 + 1.0*lhs.b.eoi*rhs.v.ei + 1.0*lhs.s*rhs.v.ei;
    result.b.e23 = 1.0*lhs.b.e12*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e123o + 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.s + 1.0*lhs.b.e2i*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.b.e2o - 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.q.e23oi + 1.0*lhs.s*rhs.b.e23;
    result.b.e31 = -1.0*lhs.b.e12*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.b.e3o - 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e123o + 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.s + 1.0*lhs.b.e3i*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.q.e31oi + 1.0*lhs.s*rhs.b.e31;
    result.b.e12 = 1.0*lhs.b.e12*rhs.s + 1.0*lhs.b.e1i*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.b.e1o - 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e123o + 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.q.e12oi + 1.0*lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.eoi + 1.0*lhs.b.e1o*rhs.s - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.b.e12 - 1.0*lhs.b.e2o*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e31 + 1.0*lhs.b.e3o*rhs.q.e31oi - 1.0*lhs.b.eoi*rhs.b.e1o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e12 + 1.0*lhs.b.e1o*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.eoi + 1.0*lhs.b.e2o*rhs.s - 1.0*lhs.b.e31*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.b.e23 - 1.0*lhs.b.e3o*rhs.q.e23oi - 1.0*lhs.b.eoi*rhs.b.e2o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.b.e31 - 1.0*lhs.b.e1o*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e23 + 1.0*lhs.b.e2o*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.eoi + 1.0*lhs.b.e3o*rhs.s - 1.0*lhs.b.eoi*rhs.b.e3o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e1i*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.s - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e2i*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.b.e3i*rhs.b.e31 - 1.0*lhs.b.e3i*rhs.q.e31oi + 1.0*lhs.b.eoi*rhs.b.e1i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e1i*rhs.b.e12 - 1.0*lhs.b.e1i*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e2i*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.s - 1.0*lhs.b.e31*rhs.q.e123i - 1.0*lhs.b.e3i*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e23oi + 1.0*lhs.b.eoi*rhs.b.e2i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e1i*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e2i*rhs.b.e23 - 1.0*lhs.b.e2i*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1i - 1.0*lhs.b.e3i*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.s + 1.0*lhs.b.eoi*rhs.b.e3i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.q.e12oi + 1.0*lhs.b.e1i*rhs.b.e1o - 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.q.e23oi + 1.0*lhs.b.e2i*rhs.b.e2o - 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.b.e3i*rhs.b.e3o - 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.s + 1.0*lhs.s*rhs.b.eoi;
    result.t.e123 = 1.0*lhs.b.e12*rhs.v.e3 - 1.0*lhs.b.e1i*rhs.t.e23o - 1.0*lhs.b.e1o*rhs.t.e23i + 1.0*lhs.b.e23*rhs.v.e1 - 1.0*lhs.b.e2i*rhs.t.e31o - 1.0*lhs.b.e2o*rhs.t.e31i + 1.0*lhs.b.e31*rhs.v.e2 - 1.0*lhs.b.e3i*rhs.t.e12o - 1.0*lhs.b.e3o*rhs.t.e12i + 1.0*lhs.b.eoi*rhs.I5 + 1.0*lhs.s*rhs.t.e123;
    result.t.e23o = 1.0*lhs.b.e12*rhs.t.e31o - 1.0*lhs.b.e1o*rhs.I5 - 1.0*lhs.b.e1o*rhs.t.e123 + 1.0*lhs.b.e23*rhs.v.eo - 1.0*lhs.b.e2o*rhs.t.e3oi - 1.0*lhs.b.e2o*rhs.v.e3 - 1.0*lhs.b.e31*rhs.t.e12o + 1.0*lhs.b.e3o*rhs.t.e2oi + 1.0*lhs.b.e3o*rhs.v.e2 - 1.0*lhs.b.eoi*rhs.t.e23o + 1.0*lhs.s*rhs.t.e23o;
    result.t.e31o = -1.0*lhs.b.e12*rhs.t.e23o + 1.0*lhs.b.e1o*rhs.t.e3oi + 1.0*lhs.b.e1o*rhs.v.e3 + 1.0*lhs.b.e23*rhs.t.e12o - 1.0*lhs.b.e2o*rhs.I5 - 1.0*lhs.b.e2o*rhs.t.e123 + 1.0*lhs.b.e31*rhs.v.eo - 1.0*lhs.b.e3o*rhs.t.e1oi - 1.0*lhs.b.e3o*rhs.v.e1 - 1.0*lhs.b.eoi*rhs.t.e31o + 1.0*lhs.s*rhs.t.e31o;
    result.t.e12o = 1.0*lhs.b.e12*rhs.v.eo - 1.0*lhs.b.e1o*rhs.t.e2oi - 1.0*lhs.b.e1o*rhs.v.e2 - 1.0*lhs.b.e23*rhs.t.e31o + 1.0*lhs.b.e2o*rhs.t.e1oi + 1.0*lhs.b.e2o*rhs.v.e1 + 1.0*lhs.b.e31*rhs.t.e23o - 1.0*lhs.b.e3o*rhs.I5 - 1.0*lhs.b.e3o*rhs.t.e123 - 1.0*lhs.b.eoi*rhs.t.e12o + 1.0*lhs.s*rhs.t.e12o;
    result.t.e23i = 1.0*lhs.b.e12*rhs.t.e31i + 1.0*lhs.b.e1i*rhs.I5 - 1.0*lhs.b.e1i*rhs.t.e123 + 1.0*lhs.b.e23*rhs.v.ei + 1.0*lhs.b.e2i*rhs.t.e3oi - 1.0*lhs.b.e2i*rhs.v.e3 - 1.0*lhs.b.e31*rhs.t.e12i - 1.0*lhs.b.e3i*rhs.t.e2oi + 1.0*lhs.b.e3i*rhs.v.e2 + 1.0*lhs.b.eoi*rhs.t.e23i + 1.0*lhs.s*rhs.t.e23i;
    result.t.e31i = -1.0*lhs.b.e12*rhs.t.e23i - 1.0*lhs.b.e1i*rhs.t.e3oi + 1.0*lhs.b.e1i*rhs.v.e3 + 1.0*lhs.b.e23*rhs.t.e12i + 1.0*lhs.b.e2i*rhs.I5 - 1.0*lhs.b.e2i*rhs.t.e123 + 1.0*lhs.b.e31*rhs.v.ei + 1.0*lhs.b.e3i*rhs.t.e1oi - 1.0*lhs.b.e3i*rhs.v.e1 + 1.0*lhs.b.eoi*rhs.t.e31i + 1.0*lhs.s*rhs.t.e31i;
    result.t.e12i = 1.0*lhs.b.e12*rhs.v.ei + 1.0*lhs.b.e1i*rhs.t.e2oi - 1.0*lhs.b.e1i*rhs.v.e2 - 1.0*lhs.b.e23*rhs.t.e31i - 1.0*lhs.b.e2i*rhs.t.e1oi + 1.0*lhs.b.e2i*rhs.v.e1 + 1.0*lhs.b.e31*rhs.t.e23i + 1.0*lhs.b.e3i*rhs.I5 - 1.0*lhs.b.e3i*rhs.t.e123 + 1.0*lhs.b.eoi*rhs.t.e12i + 1.0*lhs.s*rhs.t.e12i;
    result.t.e1oi = 1.0*lhs.b.e12*rhs.t.e2oi - 1.0*lhs.b.e1i*rhs.v.eo + 1.0*lhs.b.e1o*rhs.v.ei - 1.0*lhs.b.e23*rhs.I5 + 1.0*lhs.b.e2i*rhs.t.e12o - 1.0*lhs.b.e2o*rhs.t.e12i - 1.0*lhs.b.e31*rhs.t.e3oi - 1.0*lhs.b.e3i*rhs.t.e31o + 1.0*lhs.b.e3o*rhs.t.e31i + 1.0*lhs.b.eoi*rhs.v.e1 + 1.0*lhs.s*rhs.t.e1oi;
    result.t.e2oi = -1.0*lhs.b.e12*rhs.t.e1oi - 1.0*lhs.b.e1i*rhs.t.e12o + 1.0*lhs.b.e1o*rhs.t.e12i + 1.0*lhs.b.e23*rhs.t.e3oi - 1.0*lhs.b.e2i*rhs.v.eo + 1.0*lhs.b.e2o*rhs.v.ei - 1.0*lhs.b.e31*rhs.I5 + 1.0*lhs.b.e3i*rhs.t.e23o - 1.0*lhs.b.e3o*rhs.t.e23i + 1.0*lhs.b.eoi*rhs.v.e2 + 1.0*lhs.s*rhs.t.e2oi;
    result.t.e3oi = -1.0*lhs.b.e12*rhs.I5 + 1.0*lhs.b.e1i*rhs.t.e31o - 1.0*lhs.b.e1o*rhs.t.e31i - 1.0*lhs.b.e23*rhs.t.e2oi - 1.0*lhs.b.e2i*rhs.t.e23o + 1.0*lhs.b.e2o*rhs.t.e23i + 1.0*lhs.b.e31*rhs.t.e1oi - 1.0*lhs.b.e3i*rhs.v.eo + 1.0*lhs.b.e3o*rhs.v.ei + 1.0*lhs.b.eoi*rhs.v.e3 + 1.0*lhs.s*rhs.t.e3oi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e23 + 1.0*lhs.b.e1o*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e31 + 1.0*lhs.b.e2o*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e12 + 1.0*lhs.b.e3o*rhs.q.e12oi - 1.0*lhs.b.eoi*rhs.q.e123o + 1.0*lhs.s*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e1i*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.q.e12oi + 1.0*lhs.b.eoi*rhs.q.e123i + 1.0*lhs.s*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e1i*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.b.e3o - 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e12oi - 1.0*lhs.b.e3i*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.b.e23 + 1.0*lhs.s*rhs.q.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.q.e23oi - 1.0*lhs.b.e1i*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e2i*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.b.e1o - 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e31 + 1.0*lhs.s*rhs.q.e31oi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.b.e2o - 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e31oi - 1.0*lhs.b.e2i*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.b.e3i*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.b.e12 + 1.0*lhs.s*rhs.q.e12oi;
    result.I5 = 1.0*lhs.b.e12*rhs.t.e3oi - 1.0*lhs.b.e1i*rhs.t.e23o + 1.0*lhs.b.e1o*rhs.t.e23i + 1.0*lhs.b.e23*rhs.t.e1oi - 1.0*lhs.b.e2i*rhs.t.e31o + 1.0*lhs.b.e2o*rhs.t.e31i + 1.0*lhs.b.e31*rhs.t.e2oi - 1.0*lhs.b.e3i*rhs.t.e12o + 1.0*lhs.b.e3o*rhs.t.e12i + 1.0*lhs.b.eoi*rhs.t.e123 + 1.0*lhs.s*rhs.I5;
    return result;
}
Versor operator*(const Versor &lhs, const Versor &rhs) {
    Versor result;
    result.s = -1.0*lhs.b.e12*rhs.b.e12 + 1.0*lhs.b.e1i*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.b.e23 + 1.0*lhs.b.e2i*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e31 + 1.0*lhs.b.e3i*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.b.eoi - 1.0*lhs.q.e123i*rhs.q.e123o - 1.0*lhs.q.e123o*rhs.q.e123i - 1.0*lhs.q.e12oi*rhs.q.e12oi - 1.0*lhs.q.e23oi*rhs.q.e23oi - 1.0*lhs.q.e31oi*rhs.q.e31oi + 1.0*lhs.s*rhs.s;
    result.b.e23 = 1.0*lhs.b.e12*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e123o + 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.s + 1.0*lhs.b.e2i*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.b.e2o - 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.q.e23oi + 1.0*lhs.q.e123i*rhs.b.e1o + 1.0*lhs.q.e123o*rhs.b.e1i + 1.0*lhs.q.e12oi*rhs.q.e31oi + 1.0*lhs.q.e23oi*rhs.b.eoi - 1.0*lhs.q.e31oi*rhs.q.e12oi + 1.0*lhs.s*rhs.b.e23;
    result.b.e31 = -1.0*lhs.b.e12*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.b.e3o - 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e123o + 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.s + 1.0*lhs.b.e3i*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.q.e31oi + 1.0*lhs.q.e123i*rhs.b.e2o + 1.0*lhs.q.e123o*rhs.b.e2i - 1.0*lhs.q.e12oi*rhs.q.e23oi + 1.0*lhs.q.e23oi*rhs.q.e12oi + 1.0*lhs.q.e31oi*rhs.b.eoi + 1.0*lhs.s*rhs.b.e31;
    result.b.e12 = 1.0*lhs.b.e12*rhs.s + 1.0*lhs.b.e1i*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.b.e1o - 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e123o + 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.q.e12oi + 1.0*lhs.q.e123i*rhs.b.e3o + 1.0*lhs.q.e123o*rhs.b.e3i + 1.0*lhs.q.e12oi*rhs.b.eoi - 1.0*lhs.q.e23oi*rhs.q.e31oi + 1.0*lhs.q.e31oi*rhs.q.e23oi + 1.0*lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.eoi + 1.0*lhs.b.e1o*rhs.s - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.b.e12 - 1.0*lhs.b.e2o*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e31 + 1.0*lhs.b.e3o*rhs.q.e31oi - 1.0*lhs.b.eoi*rhs.b.e1o - 1.0*lhs.q.e123o*rhs.b.e23 - 1.0*lhs.q.e123o*rhs.q.e23oi - 1.0*lhs.q.e12oi*rhs.b.e2o + 1.0*lhs.q.e23oi*rhs.q.e123o + 1.0*lhs.q.e31oi*rhs.b.e3o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e12 + 1.0*lhs.b.e1o*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.eoi + 1.0*lhs.b.e2o*rhs.s - 1.0*lhs.b.e31*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.b.e23 - 1.0*lhs.b.e3o*rhs.q.e23oi - 1.0*lhs.b.eoi*rhs.b.e2o - 1.0*lhs.q.e123o*rhs.b.e31 - 1.0*lhs.q.e123o*rhs.q.e31oi + 1.0*lhs.q.e12oi*rhs.b.e1o - 1.0*lhs.q.e23oi*rhs.b.e3o + 1.0*lhs.q.e31oi*rhs.q.e123o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.b.e31 - 1.0*lhs.b.e1o*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e23 + 1.0*lhs.b.e2o*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.eoi + 1.0*lhs.b.e3o*rhs.s - 1.0*lhs.b.eoi*rhs.b.e3o - 1.0*lhs.q.e123o*rhs.b.e12 - 1.0*lhs.q.e123o*rhs.q.e12oi + 1.0*lhs.q.e12oi*rhs.q.e123o + 1.0*lhs.q.e23oi*rhs.b.e2o - 1.0*lhs.q.e31oi*rhs.b.e1o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e1i*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.s - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e2i*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.b.e3i*rhs.b.e31 - 1.0*lhs.b.e3i*rhs.q.e31oi + 1.0*lhs.b.eoi*rhs.b.e1i - 1.0*lhs.q.e123i*rhs.b.e23 + 1.0*lhs.q.e123i*rhs.q.e23oi + 1.0*lhs.q.e12oi*rhs.b.e2i - 1.0*lhs.q.e23oi*rhs.q.e123i - 1.0*lhs.q.e31oi*rhs.b.e3i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e1i*rhs.b.e12 - 1.0*lhs.b.e1i*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e2i*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.s - 1.0*lhs.b.e31*rhs.q.e123i - 1.0*lhs.b.e3i*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e23oi + 1.0*lhs.b.eoi*rhs.b.e2i - 1.0*lhs.q.e123i*rhs.b.e31 + 1.0*lhs.q.e123i*rhs.q.e31oi - 1.0*lhs.q.e12oi*rhs.b.e1i + 1.0*lhs.q.e23oi*rhs.b.e3i - 1.0*lhs.q.e31oi*rhs.q.e123i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e1i*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e2i*rhs.b.e23 - 1.0*lhs.b.e2i*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1i - 1.0*lhs.b.e3i*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.s + 1.0*lhs.b.eoi*rhs.b.e3i - 1.0*lhs.q.e123i*rhs.b.e12 + 1.0*lhs.q.e123i*rhs.q.e12oi - 1.0*lhs.q.e12oi*rhs.q.e123i - 1.0*lhs.q.e23oi*rhs.b.e2i + 1.0*lhs.q.e31oi*rhs.b.e1i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.q.e12oi + 1.0*lhs.b.e1i*rhs.b.e1o - 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.q.e23oi + 1.0*lhs.b.e2i*rhs.b.e2o - 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.b.e3i*rhs.b.e3o - 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.s - 1.0*lhs.q.e123i*rhs.q.e123o + 1.0*lhs.q.e123o*rhs.q.e123i - 1.0*lhs.q.e12oi*rhs.b.e12 - 1.0*lhs.q.e23oi*rhs.b.e23 - 1.0*lhs.q.e31oi*rhs.b.e31 + 1.0*lhs.s*rhs.b.eoi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e23 + 1.0*lhs.b.e1o*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e31 + 1.0*lhs.b.e2o*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e12 + 1.0*lhs.b.e3o*rhs.q.e12oi - 1.0*lhs.b.eoi*rhs.q.e123o + 1.0*lhs.q.e123o*rhs.b.eoi + 1.0*lhs.q.e123o*rhs.s - 1.0*lhs.q.e12oi*rhs.b.e3o - 1.0*lhs.q.e23oi*rhs.b.e1o - 1.0*lhs.q.e31oi*rhs.b.e2o + 1.0*lhs.s*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e1i*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.q.e12oi + 1.0*lhs.b.eoi*rhs.q.e123i - 1.0*lhs.q.e123i*rhs.b.eoi + 1.0*lhs.q.e123i*rhs.s + 1.0*lhs.q.e12oi*rhs.b.e3i + 1.0*lhs.q.e23oi*rhs.b.e1i + 1.0*lhs.q.e31oi*rhs.b.e2i + 1.0*lhs.s*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e1i*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.b.e3o - 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e12oi - 1.0*lhs.b.e3i*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.b.e23 + 1.0*lhs.q.e123i*rhs.b.e1o - 1.0*lhs.q.e123o*rhs.b.e1i + 1.0*lhs.q.e12oi*rhs.b.e31 + 1.0*lhs.q.e23oi*rhs.s - 1.0*lhs.q.e31oi*rhs.b.e12 + 1.0*lhs.s*rhs.q.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.q.e23oi - 1.0*lhs.b.e1i*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e2i*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.b.e1o - 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e31 + 1.0*lhs.q.e123i*rhs.b.e2o - 1.0*lhs.q.e123o*rhs.b.e2i - 1.0*lhs.q.e12oi*rhs.b.e23 + 1.0*lhs.q.e23oi*rhs.b.e12 + 1.0*lhs.q.e31oi*rhs.s + 1.0*lhs.s*rhs.q.e31oi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.b.e2o - 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e31oi - 1.0*lhs.b.e2i*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.b.e3i*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.b.e12 + 1.0*lhs.q.e123i*rhs.b.e3o - 1.0*lhs.q.e123o*rhs.b.e3i + 1.0*lhs.q.e12oi*rhs.s - 1.0*lhs.q.e23oi*rhs.b.e31 + 1.0*lhs.q.e31oi*rhs.b.e23 + 1.0*lhs.s*rhs.q.e12oi;
    return result;
}
Multivector operator*(const Versor &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.b.e12*rhs.b.e12 + 1.0*lhs.b.e1i*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.b.e23 + 1.0*lhs.b.e2i*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e31 + 1.0*lhs.b.e3i*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.b.eoi - 1.0*lhs.q.e123i*rhs.q.e123o - 1.0*lhs.q.e123o*rhs.q.e123i - 1.0*lhs.q.e12oi*rhs.q.e12oi - 1.0*lhs.q.e23oi*rhs.q.e23oi - 1.0*lhs.q.e31oi*rhs.q.e31oi + 1.0*lhs.s*rhs.s;
    result.v.e1 = 1.0*lhs.b.e12*rhs.v.e2 - 1.0*lhs.b.e1i*rhs.v.eo - 1.0*lhs.b.e1o*rhs.v.ei - 1.0*lhs.b.e23*rhs.t.e123 + 1.0*lhs.b.e2i*rhs.t.e12o + 1.0*lhs.b.e2o*rhs.t.e12i - 1.0*lhs.b.e31*rhs.v.e3 - 1.0*lhs.b.e3i*rhs.t.e31o - 1.0*lhs.b.e3o*rhs.t.e31i + 1.0*lhs.b.eoi*rhs.t.e1oi + 1.0*lhs.q.e123i*rhs.t.e23o + 1.0*lhs.q.e123o*rhs.t.e23i + 1.0*lhs.q.e12oi*rhs.t.e2oi - 1.0*lhs.q.e23oi*rhs.I5 - 1.0*lhs.q.e31oi*rhs.t.e3oi + 1.0*lhs.s*rhs.v.e1;
    result.v.e2 = -1.0*lhs.b.e12*rhs.v.e1 - 1.0*lhs.b.e1i*rhs.t.e12o - 1.0*lhs.b.e1o*rhs.t.e12i + 1.0*lhs.b.e23*rhs.v.e3 - 1.0*lhs.b.e2i*rhs.v.eo - 1.0*lhs.b.e2o*rhs.v.ei - 1.0*lhs.b.e31*rhs.t.e123 + 1.0*lhs.b.e3i*rhs.t.e23o + 1.0*lhs.b.e3o*rhs.t.e23i + 1.0*lhs.b.eoi*rhs.t.e2oi + 1.0*lhs.q.e123i*rhs.t.e31o + 1.0*lhs.q.e123o*rhs.t.e31i - 1.0*lhs.q.e12oi*rhs.t.e1oi + 1.0*lhs.q.e23oi*rhs.t.e3oi - 1.0*lhs.q.e31oi*rhs.I5 + 1.0*lhs.s*rhs.v.e2;
    result.v.e3 = -1.0*lhs.b.e12*rhs.t.e123 + 1.0*lhs.b.e1i*rhs.t.e31o + 1.0*lhs.b.e1o*rhs.t.e31i - 1.0*lhs.b.e23*rhs.v.e2 - 1.0*lhs.b.e2i*rhs.t.e23o - 1.0*lhs.b.e2o*rhs.t.e23i + 1.0*lhs.b.e31*rhs.v.e1 - 1.0*lhs.b.e3i*rhs.v.eo - 1.0*lhs.b.e3o*rhs.v.ei + 1.0*lhs.b.eoi*rhs.t.e3oi + 1.0*lhs.q.e123i*rhs.t.e12o + 1.0*lhs.q.e123o*rhs.t.e12i - 1.0*lhs.q.e12oi*rhs.I5 - 1.0*lhs.q.e23oi*rhs.t.e2oi + 1.0*lhs.q.e31oi*rhs.t.e1oi + 1.0*lhs.s*rhs.v.e3;
    result.v.eo = -1.0*lhs.b.e12*rhs.t.e12o - 1.0*lhs.b.e1o*rhs.t.e1oi - 1.0*lhs.b.e1o*rhs.v.e1 - 1.0*lhs.b.e23*rhs.t.e23o - 1.0*lhs.b.e2o*rhs.t.e2oi - 1.0*lhs.b.e2o*rhs.v.e2 - 1.0*lhs.b.e31*rhs.t.e31o - 1.0*lhs.b.e3o*rhs.t.e3oi - 1.0*lhs.b.e3o*rhs.v.e3 - 1.0*lhs.b.eoi*rhs.v.eo + 1.0*lhs.q.e123o*rhs.I5 + 1.0*lhs.q.e123o*rhs.t.e123 + 1.0*lhs.q.e12oi*rhs.t.e12o + 1.0*lhs.q.e23oi*rhs.t.e23o + 1.0*lhs.q.e31oi*rhs.t.e31o + 1.0*lhs.s*rhs.v.eo;
    result.v.ei = -1.0*lhs.b.e12*rhs.t.e12i + 1.0*lhs.b.e1i*rhs.t.e1oi - 1.0*lhs.b.e1i*rhs.v.e1 - 1.0*lhs.b.e23*rhs.t.e23i + 1.0*lhs.b.e2i*rhs.t.e2oi - 1.0*lhs.b.e2i*rhs.v.e2 - 1.0*lhs.b.e31*rhs.t.e31i + 1.0*lhs.b.e3i*rhs.t.e3oi - 1.0*lhs.b.e3i*rhs.v.e3 + 1.0*lhs.b.eoi*rhs.v.ei - 1.0*lhs.q.e123i*rhs.I5 + 1.0*lhs.q.e123i*rhs.t.e123 - 1.0*lhs.q.e12oi*rhs.t.e12i - 1.0*lhs.q.e23oi*rhs.t.e23i - 1.0*lhs.q.e31oi*rhs.t.e31i + 1.0*lhs.s*rhs.v.ei;
    result.b.e23 = 1.0*lhs.b.e12*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e123o + 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.s + 1.0*lhs.b.e2i*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.b.e2o - 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.q.e23oi + 1.0*lhs.q.e123i*rhs.b.e1o + 1.0*lhs.q.e123o*rhs.b.e1i + 1.0*lhs.q.e12oi*rhs.q.e31oi + 1.0*lhs.q.e23oi*rhs.b.eoi - 1.0*lhs.q.e31oi*rhs.q.e12oi + 1.0*lhs.s*rhs.b.e23;
    result.b.e31 = -1.0*lhs.b.e12*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.b.e3o - 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e123o + 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.s + 1.0*lhs.b.e3i*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.q.e31oi + 1.0*lhs.q.e123i*rhs.b.e2o + 1.0*lhs.q.e123o*rhs.b.e2i - 1.0*lhs.q.e12oi*rhs.q.e23oi + 1.0*lhs.q.e23oi*rhs.q.e12oi + 1.0*lhs.q.e31oi*rhs.b.eoi + 1.0*lhs.s*rhs.b.e31;
    result.b.e12 = 1.0*lhs.b.e12*rhs.s + 1.0*lhs.b.e1i*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.b.e1o - 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e123o + 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.q.e12oi + 1.0*lhs.q.e123i*rhs.b.e3o + 1.0*lhs.q.e123o*rhs.b.e3i + 1.0*lhs.q.e12oi*rhs.b.eoi - 1.0*lhs.q.e23oi*rhs.q.e31oi + 1.0*lhs.q.e31oi*rhs.q.e23oi + 1.0*lhs.s*rhs.b.e12;
    result.b.e1o = 1.0*lhs.b.e12*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.eoi + 1.0*lhs.b.e1o*rhs.s - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.b.e12 - 1.0*lhs.b.e2o*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e31 + 1.0*lhs.b.e3o*rhs.q.e31oi - 1.0*lhs.b.eoi*rhs.b.e1o - 1.0*lhs.q.e123o*rhs.b.e23 - 1.0*lhs.q.e123o*rhs.q.e23oi - 1.0*lhs.q.e12oi*rhs.b.e2o + 1.0*lhs.q.e23oi*rhs.q.e123o + 1.0*lhs.q.e31oi*rhs.b.e3o + 1.0*lhs.s*rhs.b.e1o;
    result.b.e2o = -1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e12 + 1.0*lhs.b.e1o*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.eoi + 1.0*lhs.b.e2o*rhs.s - 1.0*lhs.b.e31*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.b.e23 - 1.0*lhs.b.e3o*rhs.q.e23oi - 1.0*lhs.b.eoi*rhs.b.e2o - 1.0*lhs.q.e123o*rhs.b.e31 - 1.0*lhs.q.e123o*rhs.q.e31oi + 1.0*lhs.q.e12oi*rhs.b.e1o - 1.0*lhs.q.e23oi*rhs.b.e3o + 1.0*lhs.q.e31oi*rhs.q.e123o + 1.0*lhs.s*rhs.b.e2o;
    result.b.e3o = -1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.b.e31 - 1.0*lhs.b.e1o*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e23 + 1.0*lhs.b.e2o*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.eoi + 1.0*lhs.b.e3o*rhs.s - 1.0*lhs.b.eoi*rhs.b.e3o - 1.0*lhs.q.e123o*rhs.b.e12 - 1.0*lhs.q.e123o*rhs.q.e12oi + 1.0*lhs.q.e12oi*rhs.q.e123o + 1.0*lhs.q.e23oi*rhs.b.e2o - 1.0*lhs.q.e31oi*rhs.b.e1o + 1.0*lhs.s*rhs.b.e3o;
    result.b.e1i = 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e1i*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.s - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e2i*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.b.e3i*rhs.b.e31 - 1.0*lhs.b.e3i*rhs.q.e31oi + 1.0*lhs.b.eoi*rhs.b.e1i - 1.0*lhs.q.e123i*rhs.b.e23 + 1.0*lhs.q.e123i*rhs.q.e23oi + 1.0*lhs.q.e12oi*rhs.b.e2i - 1.0*lhs.q.e23oi*rhs.q.e123i - 1.0*lhs.q.e31oi*rhs.b.e3i + 1.0*lhs.s*rhs.b.e1i;
    result.b.e2i = -1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e1i*rhs.b.e12 - 1.0*lhs.b.e1i*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e2i*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.s - 1.0*lhs.b.e31*rhs.q.e123i - 1.0*lhs.b.e3i*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e23oi + 1.0*lhs.b.eoi*rhs.b.e2i - 1.0*lhs.q.e123i*rhs.b.e31 + 1.0*lhs.q.e123i*rhs.q.e31oi - 1.0*lhs.q.e12oi*rhs.b.e1i + 1.0*lhs.q.e23oi*rhs.b.e3i - 1.0*lhs.q.e31oi*rhs.q.e123i + 1.0*lhs.s*rhs.b.e2i;
    result.b.e3i = -1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e1i*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e2i*rhs.b.e23 - 1.0*lhs.b.e2i*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1i - 1.0*lhs.b.e3i*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.s + 1.0*lhs.b.eoi*rhs.b.e3i - 1.0*lhs.q.e123i*rhs.b.e12 + 1.0*lhs.q.e123i*rhs.q.e12oi - 1.0*lhs.q.e12oi*rhs.q.e123i - 1.0*lhs.q.e23oi*rhs.b.e2i + 1.0*lhs.q.e31oi*rhs.b.e1i + 1.0*lhs.s*rhs.b.e3i;
    result.b.eoi = -1.0*lhs.b.e12*rhs.q.e12oi + 1.0*lhs.b.e1i*rhs.b.e1o - 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.q.e23oi + 1.0*lhs.b.e2i*rhs.b.e2o - 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.b.e3i*rhs.b.e3o - 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.s - 1.0*lhs.q.e123i*rhs.q.e123o + 1.0*lhs.q.e123o*rhs.q.e123i - 1.0*lhs.q.e12oi*rhs.b.e12 - 1.0*lhs.q.e23oi*rhs.b.e23 - 1.0*lhs.q.e31oi*rhs.b.e31 + 1.0*lhs.s*rhs.b.eoi;
    result.t.e123 = 1.0*lhs.b.e12*rhs.v.e3 - 1.0*lhs.b.e1i*rhs.t.e23o - 1.0*lhs.b.e1o*rhs.t.e23i + 1.0*lhs.b.e23*rhs.v.e1 - 1.0*lhs.b.e2i*rhs.t.e31o - 1.0*lhs.b.e2o*rhs.t.e31i + 1.0*lhs.b.e31*rhs.v.e2 - 1.0*lhs.b.e3i*rhs.t.e12o - 1.0*lhs.b.e3o*rhs.t.e12i + 1.0*lhs.b.eoi*rhs.I5 - 1.0*lhs.q.e123i*rhs.v.eo - 1.0*lhs.q.e123o*rhs.v.ei + 1.0*lhs.q.e12oi*rhs.t.e3oi + 1.0*lhs.q.e23oi*rhs.t.e1oi + 1.0*lhs.q.e31oi*rhs.t.e2oi + 1.0*lhs.s*rhs.t.e123;
    result.t.e23o = 1.0*lhs.b.e12*rhs.t.e31o - 1.0*lhs.b.e1o*rhs.I5 - 1.0*lhs.b.e1o*rhs.t.e123 + 1.0*lhs.b.e23*rhs.v.eo - 1.0*lhs.b.e2o*rhs.t.e3oi - 1.0*lhs.b.e2o*rhs.v.e3 - 1.0*lhs.b.e31*rhs.t.e12o + 1.0*lhs.b.e3o*rhs.t.e2oi + 1.0*lhs.b.e3o*rhs.v.e2 - 1.0*lhs.b.eoi*rhs.t.e23o - 1.0*lhs.q.e123o*rhs.t.e1oi - 1.0*lhs.q.e123o*rhs.v.e1 - 1.0*lhs.q.e12oi*rhs.t.e31o - 1.0*lhs.q.e23oi*rhs.v.eo + 1.0*lhs.q.e31oi*rhs.t.e12o + 1.0*lhs.s*rhs.t.e23o;
    result.t.e31o = -1.0*lhs.b.e12*rhs.t.e23o + 1.0*lhs.b.e1o*rhs.t.e3oi + 1.0*lhs.b.e1o*rhs.v.e3 + 1.0*lhs.b.e23*rhs.t.e12o - 1.0*lhs.b.e2o*rhs.I5 - 1.0*lhs.b.e2o*rhs.t.e123 + 1.0*lhs.b.e31*rhs.v.eo - 1.0*lhs.b.e3o*rhs.t.e1oi - 1.0*lhs.b.e3o*rhs.v.e1 - 1.0*lhs.b.eoi*rhs.t.e31o - 1.0*lhs.q.e123o*rhs.t.e2oi - 1.0*lhs.q.e123o*rhs.v.e2 + 1.0*lhs.q.e12oi*rhs.t.e23o - 1.0*lhs.q.e23oi*rhs.t.e12o - 1.0*lhs.q.e31oi*rhs.v.eo + 1.0*lhs.s*rhs.t.e31o;
    result.t.e12o = 1.0*lhs.b.e12*rhs.v.eo - 1.0*lhs.b.e1o*rhs.t.e2oi - 1.0*lhs.b.e1o*rhs.v.e2 - 1.0*lhs.b.e23*rhs.t.e31o + 1.0*lhs.b.e2o*rhs.t.e1oi + 1.0*lhs.b.e2o*rhs.v.e1 + 1.0*lhs.b.e31*rhs.t.e23o - 1.0*lhs.b.e3o*rhs.I5 - 1.0*lhs.b.e3o*rhs.t.e123 - 1.0*lhs.b.eoi*rhs.t.e12o - 1.0*lhs.q.e123o*rhs.t.e3oi - 1.0*lhs.q.e123o*rhs.v.e3 - 1.0*lhs.q.e12oi*rhs.v.eo + 1.0*lhs.q.e23oi*rhs.t.e31o - 1.0*lhs.q.e31oi*rhs.t.e23o + 1.0*lhs.s*rhs.t.e12o;
    result.t.e23i = 1.0*lhs.b.e12*rhs.t.e31i + 1.0*lhs.b.e1i*rhs.I5 - 1.0*lhs.b.e1i*rhs.t.e123 + 1.0*lhs.b.e23*rhs.v.ei + 1.0*lhs.b.e2i*rhs.t.e3oi - 1.0*lhs.b.e2i*rhs.v.e3 - 1.0*lhs.b.e31*rhs.t.e12i - 1.0*lhs.b.e3i*rhs.t.e2oi + 1.0*lhs.b.e3i*rhs.v.e2 + 1.0*lhs.b.eoi*rhs.t.e23i + 1.0*lhs.q.e123i*rhs.t.e1oi - 1.0*lhs.q.e123i*rhs.v.e1 + 1.0*lhs.q.e12oi*rhs.t.e31i + 1.0*lhs.q.e23oi*rhs.v.ei - 1.0*lhs.q.e31oi*rhs.t.e12i + 1.0*lhs.s*rhs.t.e23i;
    result.t.e31i = -1.0*lhs.b.e12*rhs.t.e23i - 1.0*lhs.b.e1i*rhs.t.e3oi + 1.0*lhs.b.e1i*rhs.v.e3 + 1.0*lhs.b.e23*rhs.t.e12i + 1.0*lhs.b.e2i*rhs.I5 - 1.0*lhs.b.e2i*rhs.t.e123 + 1.0*lhs.b.e31*rhs.v.ei + 1.0*lhs.b.e3i*rhs.t.e1oi - 1.0*lhs.b.e3i*rhs.v.e1 + 1.0*lhs.b.eoi*rhs.t.e31i + 1.0*lhs.q.e123i*rhs.t.e2oi - 1.0*lhs.q.e123i*rhs.v.e2 - 1.0*lhs.q.e12oi*rhs.t.e23i + 1.0*lhs.q.e23oi*rhs.t.e12i + 1.0*lhs.q.e31oi*rhs.v.ei + 1.0*lhs.s*rhs.t.e31i;
    result.t.e12i = 1.0*lhs.b.e12*rhs.v.ei + 1.0*lhs.b.e1i*rhs.t.e2oi - 1.0*lhs.b.e1i*rhs.v.e2 - 1.0*lhs.b.e23*rhs.t.e31i - 1.0*lhs.b.e2i*rhs.t.e1oi + 1.0*lhs.b.e2i*rhs.v.e1 + 1.0*lhs.b.e31*rhs.t.e23i + 1.0*lhs.b.e3i*rhs.I5 - 1.0*lhs.b.e3i*rhs.t.e123 + 1.0*lhs.b.eoi*rhs.t.e12i + 1.0*lhs.q.e123i*rhs.t.e3oi - 1.0*lhs.q.e123i*rhs.v.e3 + 1.0*lhs.q.e12oi*rhs.v.ei - 1.0*lhs.q.e23oi*rhs.t.e31i + 1.0*lhs.q.e31oi*rhs.t.e23i + 1.0*lhs.s*rhs.t.e12i;
    result.t.e1oi = 1.0*lhs.b.e12*rhs.t.e2oi - 1.0*lhs.b.e1i*rhs.v.eo + 1.0*lhs.b.e1o*rhs.v.ei - 1.0*lhs.b.e23*rhs.I5 + 1.0*lhs.b.e2i*rhs.t.e12o - 1.0*lhs.b.e2o*rhs.t.e12i - 1.0*lhs.b.e31*rhs.t.e3oi - 1.0*lhs.b.e3i*rhs.t.e31o + 1.0*lhs.b.e3o*rhs.t.e31i + 1.0*lhs.b.eoi*rhs.v.e1 + 1.0*lhs.q.e123i*rhs.t.e23o - 1.0*lhs.q.e123o*rhs.t.e23i + 1.0*lhs.q.e12oi*rhs.v.e2 - 1.0*lhs.q.e23oi*rhs.t.e123 - 1.0*lhs.q.e31oi*rhs.v.e3 + 1.0*lhs.s*rhs.t.e1oi;
    result.t.e2oi = -1.0*lhs.b.e12*rhs.t.e1oi - 1.0*lhs.b.e1i*rhs.t.e12o + 1.0*lhs.b.e1o*rhs.t.e12i + 1.0*lhs.b.e23*rhs.t.e3oi - 1.0*lhs.b.e2i*rhs.v.eo + 1.0*lhs.b.e2o*rhs.v.ei - 1.0*lhs.b.e31*rhs.I5 + 1.0*lhs.b.e3i*rhs.t.e23o - 1.0*lhs.b.e3o*rhs.t.e23i + 1.0*lhs.b.eoi*rhs.v.e2 + 1.0*lhs.q.e123i*rhs.t.e31o - 1.0*lhs.q.e123o*rhs.t.e31i - 1.0*lhs.q.e12oi*rhs.v.e1 + 1.0*lhs.q.e23oi*rhs.v.e3 - 1.0*lhs.q.e31oi*rhs.t.e123 + 1.0*lhs.s*rhs.t.e2oi;
    result.t.e3oi = -1.0*lhs.b.e12*rhs.I5 + 1.0*lhs.b.e1i*rhs.t.e31o - 1.0*lhs.b.e1o*rhs.t.e31i - 1.0*lhs.b.e23*rhs.t.e2oi - 1.0*lhs.b.e2i*rhs.t.e23o + 1.0*lhs.b.e2o*rhs.t.e23i + 1.0*lhs.b.e31*rhs.t.e1oi - 1.0*lhs.b.e3i*rhs.v.eo + 1.0*lhs.b.e3o*rhs.v.ei + 1.0*lhs.b.eoi*rhs.v.e3 + 1.0*lhs.q.e123i*rhs.t.e12o - 1.0*lhs.q.e123o*rhs.t.e12i - 1.0*lhs.q.e12oi*rhs.t.e123 - 1.0*lhs.q.e23oi*rhs.v.e2 + 1.0*lhs.q.e31oi*rhs.v.e1 + 1.0*lhs.s*rhs.t.e3oi;
    result.q.e123o = 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e23 + 1.0*lhs.b.e1o*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e31 + 1.0*lhs.b.e2o*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e12 + 1.0*lhs.b.e3o*rhs.q.e12oi - 1.0*lhs.b.eoi*rhs.q.e123o + 1.0*lhs.q.e123o*rhs.b.eoi + 1.0*lhs.q.e123o*rhs.s - 1.0*lhs.q.e12oi*rhs.b.e3o - 1.0*lhs.q.e23oi*rhs.b.e1o - 1.0*lhs.q.e31oi*rhs.b.e2o + 1.0*lhs.s*rhs.q.e123o;
    result.q.e123i = 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e1i*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.q.e12oi + 1.0*lhs.b.eoi*rhs.q.e123i - 1.0*lhs.q.e123i*rhs.b.eoi + 1.0*lhs.q.e123i*rhs.s + 1.0*lhs.q.e12oi*rhs.b.e3i + 1.0*lhs.q.e23oi*rhs.b.e1i + 1.0*lhs.q.e31oi*rhs.b.e2i + 1.0*lhs.s*rhs.q.e123i;
    result.q.e23oi = 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e1i*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.b.e3o - 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e12oi - 1.0*lhs.b.e3i*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.b.e23 + 1.0*lhs.q.e123i*rhs.b.e1o - 1.0*lhs.q.e123o*rhs.b.e1i + 1.0*lhs.q.e12oi*rhs.b.e31 + 1.0*lhs.q.e23oi*rhs.s - 1.0*lhs.q.e31oi*rhs.b.e12 + 1.0*lhs.s*rhs.q.e23oi;
    result.q.e31oi = -1.0*lhs.b.e12*rhs.q.e23oi - 1.0*lhs.b.e1i*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e2i*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.b.e1o - 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e31 + 1.0*lhs.q.e123i*rhs.b.e2o - 1.0*lhs.q.e123o*rhs.b.e2i - 1.0*lhs.q.e12oi*rhs.b.e23 + 1.0*lhs.q.e23oi*rhs.b.e12 + 1.0*lhs.q.e31oi*rhs.s + 1.0*lhs.s*rhs.q.e31oi;
    result.q.e12oi = 1.0*lhs.b.e12*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.b.e2o - 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e31oi - 1.0*lhs.b.e2i*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.b.e3i*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.b.e12 + 1.0*lhs.q.e123i*rhs.b.e3o - 1.0*lhs.q.e123o*rhs.b.e3i + 1.0*lhs.q.e12oi*rhs.s - 1.0*lhs.q.e23oi*rhs.b.e31 + 1.0*lhs.q.e31oi*rhs.b.e23 + 1.0*lhs.s*rhs.q.e12oi;
    result.I5 = 1.0*lhs.b.e12*rhs.t.e3oi - 1.0*lhs.b.e1i*rhs.t.e23o + 1.0*lhs.b.e1o*rhs.t.e23i + 1.0*lhs.b.e23*rhs.t.e1oi - 1.0*lhs.b.e2i*rhs.t.e31o + 1.0*lhs.b.e2o*rhs.t.e31i + 1.0*lhs.b.e31*rhs.t.e2oi - 1.0*lhs.b.e3i*rhs.t.e12o + 1.0*lhs.b.e3o*rhs.t.e12i + 1.0*lhs.b.eoi*rhs.t.e123 - 1.0*lhs.q.e123i*rhs.v.eo + 1.0*lhs.q.e123o*rhs.v.ei + 1.0*lhs.q.e12oi*rhs.v.e3 + 1.0*lhs.q.e23oi*rhs.v.e1 + 1.0*lhs.q.e31oi*rhs.v.e2 + 1.0*lhs.s*rhs.I5;
    return result;
}
Multivector operator*(const Multivector &lhs, const Multivector &rhs) {
    Multivector result;
    result.s = -1.0*lhs.I5*rhs.I5 - 1.0*lhs.b.e12*rhs.b.e12 + 1.0*lhs.b.e1i*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.b.e23 + 1.0*lhs.b.e2i*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.b.e31 + 1.0*lhs.b.e3i*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.b.eoi - 1.0*lhs.q.e123i*rhs.q.e123o - 1.0*lhs.q.e123o*rhs.q.e123i - 1.0*lhs.q.e12oi*rhs.q.e12oi - 1.0*lhs.q.e23oi*rhs.q.e23oi - 1.0*lhs.q.e31oi*rhs.q.e31oi + 1.0*lhs.s*rhs.s - 1.0*lhs.t.e123*rhs.t.e123 + 1.0*lhs.t.e12i*rhs.t.e12o + 1.0*lhs.t.e12o*rhs.t.e12i + 1.0*lhs.t.e1oi*rhs.t.e1oi + 1.0*lhs.t.e23i*rhs.t.e23o + 1.0*lhs.t.e23o*rhs.t.e23i + 1.0*lhs.t.e2oi*rhs.t.e2oi + 1.0*lhs.t.e31i*rhs.t.e31o + 1.0*lhs.t.e31o*rhs.t.e31i + 1.0*lhs.t.e3oi*rhs.t.e3oi + 1.0*lhs.v.e1*rhs.v.e1 + 1.0*lhs.v.e2*rhs.v.e2 + 1.0*lhs.v.e3*rhs.v.e3 - 1.0*lhs.v.ei*rhs.v.eo - 1.0*lhs.v.eo*rhs.v.ei;
    result.v.e1 = -1.0*lhs.I5*rhs.q.e23oi + 1.0*lhs.b.e12*rhs.v.e2 - 1.0*lhs.b.e1i*rhs.v.eo - 1.0*lhs.b.e1o*rhs.v.ei - 1.0*lhs.b.e23*rhs.t.e123 + 1.0*lhs.b.e2i*rhs.t.e12o + 1.0*lhs.b.e2o*rhs.t.e12i - 1.0*lhs.b.e31*rhs.v.e3 - 1.0*lhs.b.e3i*rhs.t.e31o - 1.0*lhs.b.e3o*rhs.t.e31i + 1.0*lhs.b.eoi*rhs.t.e1oi + 1.0*lhs.q.e123i*rhs.t.e23o + 1.0*lhs.q.e123o*rhs.t.e23i + 1.0*lhs.q.e12oi*rhs.t.e2oi - 1.0*lhs.q.e23oi*rhs.I5 - 1.0*lhs.q.e31oi*rhs.t.e3oi + 1.0*lhs.s*rhs.v.e1 - 1.0*lhs.t.e123*rhs.b.e23 + 1.0*lhs.t.e12i*rhs.b.e2o + 1.0*lhs.t.e12o*rhs.b.e2i + 1.0*lhs.t.e1oi*rhs.b.eoi - 1.0*lhs.t.e23i*rhs.q.e123o - 1.0*lhs.t.e23o*rhs.q.e123i - 1.0*lhs.t.e2oi*rhs.q.e12oi - 1.0*lhs.t.e31i*rhs.b.e3o - 1.0*lhs.t.e31o*rhs.b.e3i + 1.0*lhs.t.e3oi*rhs.q.e31oi + 1.0*lhs.v.e1*rhs.s - 1.0*lhs.v.e2*rhs.b.e12 + 1.0*lhs.v.e3*rhs.b.e31 + 1.0*lhs.v.ei*rhs.b.e1o + 1.0*lhs.v.eo*rhs.b.e1i;
    result.v.e2 = -1.0*lhs.I5*rhs.q.e31oi - 1.0*lhs.b.e12*rhs.v.e1 - 1.0*lhs.b.e1i*rhs.t.e12o - 1.0*lhs.b.e1o*rhs.t.e12i + 1.0*lhs.b.e23*rhs.v.e3 - 1.0*lhs.b.e2i*rhs.v.eo - 1.0*lhs.b.e2o*rhs.v.ei - 1.0*lhs.b.e31*rhs.t.e123 + 1.0*lhs.b.e3i*rhs.t.e23o + 1.0*lhs.b.e3o*rhs.t.e23i + 1.0*lhs.b.eoi*rhs.t.e2oi + 1.0*lhs.q.e123i*rhs.t.e31o + 1.0*lhs.q.e123o*rhs.t.e31i - 1.0*lhs.q.e12oi*rhs.t.e1oi + 1.0*lhs.q.e23oi*rhs.t.e3oi - 1.0*lhs.q.e31oi*rhs.I5 + 1.0*lhs.s*rhs.v.e2 - 1.0*lhs.t.e123*rhs.b.e31 - 1.0*lhs.t.e12i*rhs.b.e1o - 1.0*lhs.t.e12o*rhs.b.e1i + 1.0*lhs.t.e1oi*rhs.q.e12oi + 1.0*lhs.t.e23i*rhs.b.e3o + 1.0*lhs.t.e23o*rhs.b.e3i + 1.0*lhs.t.e2oi*rhs.b.eoi - 1.0*lhs.t.e31i*rhs.q.e123o - 1.0*lhs.t.e31o*rhs.q.e123i - 1.0*lhs.t.e3oi*rhs.q.e23oi + 1.0*lhs.v.e1*rhs.b.e12 + 1.0*lhs.v.e2*rhs.s - 1.0*lhs.v.e3*rhs.b.e23 + 1.0*lhs.v.ei*rhs.b.e2o + 1.0*lhs.v.eo*rhs.b.e2i;
    result.v.e3 = -1.0*lhs.I5*rhs.q.e12oi - 1.0*lhs.b.e12*rhs.t.e123 + 1.0*lhs.b.e1i*rhs.t.e31o + 1.0*lhs.b.e1o*rhs.t.e31i - 1.0*lhs.b.e23*rhs.v.e2 - 1.0*lhs.b.e2i*rhs.t.e23o - 1.0*lhs.b.e2o*rhs.t.e23i + 1.0*lhs.b.e31*rhs.v.e1 - 1.0*lhs.b.e3i*rhs.v.eo - 1.0*lhs.b.e3o*rhs.v.ei + 1.0*lhs.b.eoi*rhs.t.e3oi + 1.0*lhs.q.e123i*rhs.t.e12o + 1.0*lhs.q.e123o*rhs.t.e12i - 1.0*lhs.q.e12oi*rhs.I5 - 1.0*lhs.q.e23oi*rhs.t.e2oi + 1.0*lhs.q.e31oi*rhs.t.e1oi + 1.0*lhs.s*rhs.v.e3 - 1.0*lhs.t.e123*rhs.b.e12 - 1.0*lhs.t.e12i*rhs.q.e123o - 1.0*lhs.t.e12o*rhs.q.e123i - 1.0*lhs.t.e1oi*rhs.q.e31oi - 1.0*lhs.t.e23i*rhs.b.e2o - 1.0*lhs.t.e23o*rhs.b.e2i + 1.0*lhs.t.e2oi*rhs.q.e23oi + 1.0*lhs.t.e31i*rhs.b.e1o + 1.0*lhs.t.e31o*rhs.b.e1i + 1.0*lhs.t.e3oi*rhs.b.eoi - 1.0*lhs.v.e1*rhs.b.e31 + 1.0*lhs.v.e2*rhs.b.e23 + 1.0*lhs.v.e3*rhs.s + 1.0*lhs.v.ei*rhs.b.e3o + 1.0*lhs.v.eo*rhs.b.e3i;
    result.v.eo = 1.0*lhs.I5*rhs.q.e123o - 1.0*lhs.b.e12*rhs.t.e12o - 1.0*lhs.b.e1o*rhs.t.e1oi - 1.0*lhs.b.e1o*rhs.v.e1 - 1.0*lhs.b.e23*rhs.t.e23o - 1.0*lhs.b.e2o*rhs.t.e2oi - 1.0*lhs.b.e2o*rhs.v.e2 - 1.0*lhs.b.e31*rhs.t.e31o - 1.0*lhs.b.e3o*rhs.t.e3oi - 1.0*lhs.b.e3o*rhs.v.e3 - 1.0*lhs.b.eoi*rhs.v.eo + 1.0*lhs.q.e123o*rhs.I5 + 1.0*lhs.q.e123o*rhs.t.e123 + 1.0*lhs.q.e12oi*rhs.t.e12o + 1.0*lhs.q.e23oi*rhs.t.e23o + 1.0*lhs.q.e31oi*rhs.t.e31o + 1.0*lhs.s*rhs.v.eo - 1.0*lhs.t.e123*rhs.q.e123o - 1.0*lhs.t.e12o*rhs.b.e12 - 1.0*lhs.t.e12o*rhs.q.e12oi - 1.0*lhs.t.e1oi*rhs.b.e1o - 1.0*lhs.t.e23o*rhs.b.e23 - 1.0*lhs.t.e23o*rhs.q.e23oi - 1.0*lhs.t.e2oi*rhs.b.e2o - 1.0*lhs.t.e31o*rhs.b.e31 - 1.0*lhs.t.e31o*rhs.q.e31oi - 1.0*lhs.t.e3oi*rhs.b.e3o + 1.0*lhs.v.e1*rhs.b.e1o + 1.0*lhs.v.e2*rhs.b.e2o + 1.0*lhs.v.e3*rhs.b.e3o + 1.0*lhs.v.eo*rhs.b.eoi + 1.0*lhs.v.eo*rhs.s;
    result.v.ei = -1.0*lhs.I5*rhs.q.e123i - 1.0*lhs.b.e12*rhs.t.e12i + 1.0*lhs.b.e1i*rhs.t.e1oi - 1.0*lhs.b.e1i*rhs.v.e1 - 1.0*lhs.b.e23*rhs.t.e23i + 1.0*lhs.b.e2i*rhs.t.e2oi - 1.0*lhs.b.e2i*rhs.v.e2 - 1.0*lhs.b.e31*rhs.t.e31i + 1.0*lhs.b.e3i*rhs.t.e3oi - 1.0*lhs.b.e3i*rhs.v.e3 + 1.0*lhs.b.eoi*rhs.v.ei - 1.0*lhs.q.e123i*rhs.I5 + 1.0*lhs.q.e123i*rhs.t.e123 - 1.0*lhs.q.e12oi*rhs.t.e12i - 1.0*lhs.q.e23oi*rhs.t.e23i - 1.0*lhs.q.e31oi*rhs.t.e31i + 1.0*lhs.s*rhs.v.ei - 1.0*lhs.t.e123*rhs.q.e123i - 1.0*lhs.t.e12i*rhs.b.e12 + 1.0*lhs.t.e12i*rhs.q.e12oi + 1.0*lhs.t.e1oi*rhs.b.e1i - 1.0*lhs.t.e23i*rhs.b.e23 + 1.0*lhs.t.e23i*rhs.q.e23oi + 1.0*lhs.t.e2oi*rhs.b.e2i - 1.0*lhs.t.e31i*rhs.b.e31 + 1.0*lhs.t.e31i*rhs.q.e31oi + 1.0*lhs.t.e3oi*rhs.b.e3i + 1.0*lhs.v.e1*rhs.b.e1i + 1.0*lhs.v.e2*rhs.b.e2i + 1.0*lhs.v.e3*rhs.b.e3i - 1.0*lhs.v.ei*rhs.b.eoi + 1.0*lhs.v.ei*rhs.s;
    result.b.e23 = 1.0*lhs.I5*rhs.t.e1oi + 1.0*lhs.b.e12*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e123o + 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.s + 1.0*lhs.b.e2i*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.b.e2o - 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.q.e23oi + 1.0*lhs.q.e123i*rhs.b.e1o + 1.0*lhs.q.e123o*rhs.b.e1i + 1.0*lhs.q.e12oi*rhs.q.e31oi + 1.0*lhs.q.e23oi*rhs.b.eoi - 1.0*lhs.q.e31oi*rhs.q.e12oi + 1.0*lhs.s*rhs.b.e23 + 1.0*lhs.t.e123*rhs.v.e1 - 1.0*lhs.t.e12i*rhs.t.e31o - 1.0*lhs.t.e12o*rhs.t.e31i + 1.0*lhs.t.e1oi*rhs.I5 - 1.0*lhs.t.e23i*rhs.v.eo - 1.0*lhs.t.e23o*rhs.v.ei + 1.0*lhs.t.e2oi*rhs.t.e3oi + 1.0*lhs.t.e31i*rhs.t.e12o + 1.0*lhs.t.e31o*rhs.t.e12i - 1.0*lhs.t.e3oi*rhs.t.e2oi + 1.0*lhs.v.e1*rhs.t.e123 + 1.0*lhs.v.e2*rhs.v.e3 - 1.0*lhs.v.e3*rhs.v.e2 - 1.0*lhs.v.ei*rhs.t.e23o - 1.0*lhs.v.eo*rhs.t.e23i;
    result.b.e31 = 1.0*lhs.I5*rhs.t.e2oi - 1.0*lhs.b.e12*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.b.e3o - 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e123o + 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.s + 1.0*lhs.b.e3i*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.q.e31oi + 1.0*lhs.q.e123i*rhs.b.e2o + 1.0*lhs.q.e123o*rhs.b.e2i - 1.0*lhs.q.e12oi*rhs.q.e23oi + 1.0*lhs.q.e23oi*rhs.q.e12oi + 1.0*lhs.q.e31oi*rhs.b.eoi + 1.0*lhs.s*rhs.b.e31 + 1.0*lhs.t.e123*rhs.v.e2 + 1.0*lhs.t.e12i*rhs.t.e23o + 1.0*lhs.t.e12o*rhs.t.e23i - 1.0*lhs.t.e1oi*rhs.t.e3oi - 1.0*lhs.t.e23i*rhs.t.e12o - 1.0*lhs.t.e23o*rhs.t.e12i + 1.0*lhs.t.e2oi*rhs.I5 - 1.0*lhs.t.e31i*rhs.v.eo - 1.0*lhs.t.e31o*rhs.v.ei + 1.0*lhs.t.e3oi*rhs.t.e1oi - 1.0*lhs.v.e1*rhs.v.e3 + 1.0*lhs.v.e2*rhs.t.e123 + 1.0*lhs.v.e3*rhs.v.e1 - 1.0*lhs.v.ei*rhs.t.e31o - 1.0*lhs.v.eo*rhs.t.e31i;
    result.b.e12 = 1.0*lhs.I5*rhs.t.e3oi + 1.0*lhs.b.e12*rhs.s + 1.0*lhs.b.e1i*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.b.e1o - 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e123o + 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.q.e12oi + 1.0*lhs.q.e123i*rhs.b.e3o + 1.0*lhs.q.e123o*rhs.b.e3i + 1.0*lhs.q.e12oi*rhs.b.eoi - 1.0*lhs.q.e23oi*rhs.q.e31oi + 1.0*lhs.q.e31oi*rhs.q.e23oi + 1.0*lhs.s*rhs.b.e12 + 1.0*lhs.t.e123*rhs.v.e3 - 1.0*lhs.t.e12i*rhs.v.eo - 1.0*lhs.t.e12o*rhs.v.ei + 1.0*lhs.t.e1oi*rhs.t.e2oi + 1.0*lhs.t.e23i*rhs.t.e31o + 1.0*lhs.t.e23o*rhs.t.e31i - 1.0*lhs.t.e2oi*rhs.t.e1oi - 1.0*lhs.t.e31i*rhs.t.e23o - 1.0*lhs.t.e31o*rhs.t.e23i + 1.0*lhs.t.e3oi*rhs.I5 + 1.0*lhs.v.e1*rhs.v.e2 - 1.0*lhs.v.e2*rhs.v.e1 + 1.0*lhs.v.e3*rhs.t.e123 - 1.0*lhs.v.ei*rhs.t.e12o - 1.0*lhs.v.eo*rhs.t.e12i;
    result.b.e1o = 1.0*lhs.I5*rhs.t.e23o + 1.0*lhs.b.e12*rhs.b.e2o + 1.0*lhs.b.e1o*rhs.b.eoi + 1.0*lhs.b.e1o*rhs.s - 1.0*lhs.b.e23*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.b.e12 - 1.0*lhs.b.e2o*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3o + 1.0*lhs.b.e3o*rhs.b.e31 + 1.0*lhs.b.e3o*rhs.q.e31oi - 1.0*lhs.b.eoi*rhs.b.e1o - 1.0*lhs.q.e123o*rhs.b.e23 - 1.0*lhs.q.e123o*rhs.q.e23oi - 1.0*lhs.q.e12oi*rhs.b.e2o + 1.0*lhs.q.e23oi*rhs.q.e123o + 1.0*lhs.q.e31oi*rhs.b.e3o + 1.0*lhs.s*rhs.b.e1o - 1.0*lhs.t.e123*rhs.t.e23o - 1.0*lhs.t.e12o*rhs.t.e2oi - 1.0*lhs.t.e12o*rhs.v.e2 - 1.0*lhs.t.e1oi*rhs.v.eo + 1.0*lhs.t.e23o*rhs.I5 + 1.0*lhs.t.e23o*rhs.t.e123 + 1.0*lhs.t.e2oi*rhs.t.e12o + 1.0*lhs.t.e31o*rhs.t.e3oi + 1.0*lhs.t.e31o*rhs.v.e3 - 1.0*lhs.t.e3oi*rhs.t.e31o + 1.0*lhs.v.e1*rhs.v.eo - 1.0*lhs.v.e2*rhs.t.e12o + 1.0*lhs.v.e3*rhs.t.e31o - 1.0*lhs.v.eo*rhs.t.e1oi - 1.0*lhs.v.eo*rhs.v.e1;
    result.b.e2o = 1.0*lhs.I5*rhs.t.e31o - 1.0*lhs.b.e12*rhs.b.e1o + 1.0*lhs.b.e1o*rhs.b.e12 + 1.0*lhs.b.e1o*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3o + 1.0*lhs.b.e2o*rhs.b.eoi + 1.0*lhs.b.e2o*rhs.s - 1.0*lhs.b.e31*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.b.e23 - 1.0*lhs.b.e3o*rhs.q.e23oi - 1.0*lhs.b.eoi*rhs.b.e2o - 1.0*lhs.q.e123o*rhs.b.e31 - 1.0*lhs.q.e123o*rhs.q.e31oi + 1.0*lhs.q.e12oi*rhs.b.e1o - 1.0*lhs.q.e23oi*rhs.b.e3o + 1.0*lhs.q.e31oi*rhs.q.e123o + 1.0*lhs.s*rhs.b.e2o - 1.0*lhs.t.e123*rhs.t.e31o + 1.0*lhs.t.e12o*rhs.t.e1oi + 1.0*lhs.t.e12o*rhs.v.e1 - 1.0*lhs.t.e1oi*rhs.t.e12o - 1.0*lhs.t.e23o*rhs.t.e3oi - 1.0*lhs.t.e23o*rhs.v.e3 - 1.0*lhs.t.e2oi*rhs.v.eo + 1.0*lhs.t.e31o*rhs.I5 + 1.0*lhs.t.e31o*rhs.t.e123 + 1.0*lhs.t.e3oi*rhs.t.e23o + 1.0*lhs.v.e1*rhs.t.e12o + 1.0*lhs.v.e2*rhs.v.eo - 1.0*lhs.v.e3*rhs.t.e23o - 1.0*lhs.v.eo*rhs.t.e2oi - 1.0*lhs.v.eo*rhs.v.e2;
    result.b.e3o = 1.0*lhs.I5*rhs.t.e12o - 1.0*lhs.b.e12*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.b.e31 - 1.0*lhs.b.e1o*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2o + 1.0*lhs.b.e2o*rhs.b.e23 + 1.0*lhs.b.e2o*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1o + 1.0*lhs.b.e3o*rhs.b.eoi + 1.0*lhs.b.e3o*rhs.s - 1.0*lhs.b.eoi*rhs.b.e3o - 1.0*lhs.q.e123o*rhs.b.e12 - 1.0*lhs.q.e123o*rhs.q.e12oi + 1.0*lhs.q.e12oi*rhs.q.e123o + 1.0*lhs.q.e23oi*rhs.b.e2o - 1.0*lhs.q.e31oi*rhs.b.e1o + 1.0*lhs.s*rhs.b.e3o - 1.0*lhs.t.e123*rhs.t.e12o + 1.0*lhs.t.e12o*rhs.I5 + 1.0*lhs.t.e12o*rhs.t.e123 + 1.0*lhs.t.e1oi*rhs.t.e31o + 1.0*lhs.t.e23o*rhs.t.e2oi + 1.0*lhs.t.e23o*rhs.v.e2 - 1.0*lhs.t.e2oi*rhs.t.e23o - 1.0*lhs.t.e31o*rhs.t.e1oi - 1.0*lhs.t.e31o*rhs.v.e1 - 1.0*lhs.t.e3oi*rhs.v.eo - 1.0*lhs.v.e1*rhs.t.e31o + 1.0*lhs.v.e2*rhs.t.e23o + 1.0*lhs.v.e3*rhs.v.eo - 1.0*lhs.v.eo*rhs.t.e3oi - 1.0*lhs.v.eo*rhs.v.e3;
    result.b.e1i = -1.0*lhs.I5*rhs.t.e23i + 1.0*lhs.b.e12*rhs.b.e2i - 1.0*lhs.b.e1i*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.s - 1.0*lhs.b.e23*rhs.q.e123i - 1.0*lhs.b.e2i*rhs.b.e12 + 1.0*lhs.b.e2i*rhs.q.e12oi - 1.0*lhs.b.e31*rhs.b.e3i + 1.0*lhs.b.e3i*rhs.b.e31 - 1.0*lhs.b.e3i*rhs.q.e31oi + 1.0*lhs.b.eoi*rhs.b.e1i - 1.0*lhs.q.e123i*rhs.b.e23 + 1.0*lhs.q.e123i*rhs.q.e23oi + 1.0*lhs.q.e12oi*rhs.b.e2i - 1.0*lhs.q.e23oi*rhs.q.e123i - 1.0*lhs.q.e31oi*rhs.b.e3i + 1.0*lhs.s*rhs.b.e1i - 1.0*lhs.t.e123*rhs.t.e23i + 1.0*lhs.t.e12i*rhs.t.e2oi - 1.0*lhs.t.e12i*rhs.v.e2 + 1.0*lhs.t.e1oi*rhs.v.ei - 1.0*lhs.t.e23i*rhs.I5 + 1.0*lhs.t.e23i*rhs.t.e123 - 1.0*lhs.t.e2oi*rhs.t.e12i - 1.0*lhs.t.e31i*rhs.t.e3oi + 1.0*lhs.t.e31i*rhs.v.e3 + 1.0*lhs.t.e3oi*rhs.t.e31i + 1.0*lhs.v.e1*rhs.v.ei - 1.0*lhs.v.e2*rhs.t.e12i + 1.0*lhs.v.e3*rhs.t.e31i + 1.0*lhs.v.ei*rhs.t.e1oi - 1.0*lhs.v.ei*rhs.v.e1;
    result.b.e2i = -1.0*lhs.I5*rhs.t.e31i - 1.0*lhs.b.e12*rhs.b.e1i + 1.0*lhs.b.e1i*rhs.b.e12 - 1.0*lhs.b.e1i*rhs.q.e12oi + 1.0*lhs.b.e23*rhs.b.e3i - 1.0*lhs.b.e2i*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.s - 1.0*lhs.b.e31*rhs.q.e123i - 1.0*lhs.b.e3i*rhs.b.e23 + 1.0*lhs.b.e3i*rhs.q.e23oi + 1.0*lhs.b.eoi*rhs.b.e2i - 1.0*lhs.q.e123i*rhs.b.e31 + 1.0*lhs.q.e123i*rhs.q.e31oi - 1.0*lhs.q.e12oi*rhs.b.e1i + 1.0*lhs.q.e23oi*rhs.b.e3i - 1.0*lhs.q.e31oi*rhs.q.e123i + 1.0*lhs.s*rhs.b.e2i - 1.0*lhs.t.e123*rhs.t.e31i - 1.0*lhs.t.e12i*rhs.t.e1oi + 1.0*lhs.t.e12i*rhs.v.e1 + 1.0*lhs.t.e1oi*rhs.t.e12i + 1.0*lhs.t.e23i*rhs.t.e3oi - 1.0*lhs.t.e23i*rhs.v.e3 + 1.0*lhs.t.e2oi*rhs.v.ei - 1.0*lhs.t.e31i*rhs.I5 + 1.0*lhs.t.e31i*rhs.t.e123 - 1.0*lhs.t.e3oi*rhs.t.e23i + 1.0*lhs.v.e1*rhs.t.e12i + 1.0*lhs.v.e2*rhs.v.ei - 1.0*lhs.v.e3*rhs.t.e23i + 1.0*lhs.v.ei*rhs.t.e2oi - 1.0*lhs.v.ei*rhs.v.e2;
    result.b.e3i = -1.0*lhs.I5*rhs.t.e12i - 1.0*lhs.b.e12*rhs.q.e123i - 1.0*lhs.b.e1i*rhs.b.e31 + 1.0*lhs.b.e1i*rhs.q.e31oi - 1.0*lhs.b.e23*rhs.b.e2i + 1.0*lhs.b.e2i*rhs.b.e23 - 1.0*lhs.b.e2i*rhs.q.e23oi + 1.0*lhs.b.e31*rhs.b.e1i - 1.0*lhs.b.e3i*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.s + 1.0*lhs.b.eoi*rhs.b.e3i - 1.0*lhs.q.e123i*rhs.b.e12 + 1.0*lhs.q.e123i*rhs.q.e12oi - 1.0*lhs.q.e12oi*rhs.q.e123i - 1.0*lhs.q.e23oi*rhs.b.e2i + 1.0*lhs.q.e31oi*rhs.b.e1i + 1.0*lhs.s*rhs.b.e3i - 1.0*lhs.t.e123*rhs.t.e12i - 1.0*lhs.t.e12i*rhs.I5 + 1.0*lhs.t.e12i*rhs.t.e123 - 1.0*lhs.t.e1oi*rhs.t.e31i - 1.0*lhs.t.e23i*rhs.t.e2oi + 1.0*lhs.t.e23i*rhs.v.e2 + 1.0*lhs.t.e2oi*rhs.t.e23i + 1.0*lhs.t.e31i*rhs.t.e1oi - 1.0*lhs.t.e31i*rhs.v.e1 + 1.0*lhs.t.e3oi*rhs.v.ei - 1.0*lhs.v.e1*rhs.t.e31i + 1.0*lhs.v.e2*rhs.t.e23i + 1.0*lhs.v.e3*rhs.v.ei + 1.0*lhs.v.ei*rhs.t.e3oi - 1.0*lhs.v.ei*rhs.v.e3;
    result.b.eoi = -1.0*lhs.I5*rhs.t.e123 - 1.0*lhs.b.e12*rhs.q.e12oi + 1.0*lhs.b.e1i*rhs.b.e1o - 1.0*lhs.b.e1o*rhs.b.e1i - 1.0*lhs.b.e23*rhs.q.e23oi + 1.0*lhs.b.e2i*rhs.b.e2o - 1.0*lhs.b.e2o*rhs.b.e2i - 1.0*lhs.b.e31*rhs.q.e31oi + 1.0*lhs.b.e3i*rhs.b.e3o - 1.0*lhs.b.e3o*rhs.b.e3i + 1.0*lhs.b.eoi*rhs.s - 1.0*lhs.q.e123i*rhs.q.e123o + 1.0*lhs.q.e123o*rhs.q.e123i - 1.0*lhs.q.e12oi*rhs.b.e12 - 1.0*lhs.q.e23oi*rhs.b.e23 - 1.0*lhs.q.e31oi*rhs.b.e31 + 1.0*lhs.s*rhs.b.eoi - 1.0*lhs.t.e123*rhs.I5 + 1.0*lhs.t.e12i*rhs.t.e12o - 1.0*lhs.t.e12o*rhs.t.e12i + 1.0*lhs.t.e1oi*rhs.v.e1 + 1.0*lhs.t.e23i*rhs.t.e23o - 1.0*lhs.t.e23o*rhs.t.e23i + 1.0*lhs.t.e2oi*rhs.v.e2 + 1.0*lhs.t.e31i*rhs.t.e31o - 1.0*lhs.t.e31o*rhs.t.e31i + 1.0*lhs.t.e3oi*rhs.v.e3 + 1.0*lhs.v.e1*rhs.t.e1oi + 1.0*lhs.v.e2*rhs.t.e2oi + 1.0*lhs.v.e3*rhs.t.e3oi - 1.0*lhs.v.ei*rhs.v.eo + 1.0*lhs.v.eo*rhs.v.ei;
    result.t.e123 = 1.0*lhs.I5*rhs.b.eoi + 1.0*lhs.b.e12*rhs.v.e3 - 1.0*lhs.b.e1i*rhs.t.e23o - 1.0*lhs.b.e1o*rhs.t.e23i + 1.0*lhs.b.e23*rhs.v.e1 - 1.0*lhs.b.e2i*rhs.t.e31o - 1.0*lhs.b.e2o*rhs.t.e31i + 1.0*lhs.b.e31*rhs.v.e2 - 1.0*lhs.b.e3i*rhs.t.e12o - 1.0*lhs.b.e3o*rhs.t.e12i + 1.0*lhs.b.eoi*rhs.I5 - 1.0*lhs.q.e123i*rhs.v.eo - 1.0*lhs.q.e123o*rhs.v.ei + 1.0*lhs.q.e12oi*rhs.t.e3oi + 1.0*lhs.q.e23oi*rhs.t.e1oi + 1.0*lhs.q.e31oi*rhs.t.e2oi + 1.0*lhs.s*rhs.t.e123 + 1.0*lhs.t.e123*rhs.s + 1.0*lhs.t.e12i*rhs.b.e3o + 1.0*lhs.t.e12o*rhs.b.e3i + 1.0*lhs.t.e1oi*rhs.q.e23oi + 1.0*lhs.t.e23i*rhs.b.e1o + 1.0*lhs.t.e23o*rhs.b.e1i + 1.0*lhs.t.e2oi*rhs.q.e31oi + 1.0*lhs.t.e31i*rhs.b.e2o + 1.0*lhs.t.e31o*rhs.b.e2i + 1.0*lhs.t.e3oi*rhs.q.e12oi + 1.0*lhs.v.e1*rhs.b.e23 + 1.0*lhs.v.e2*rhs.b.e31 + 1.0*lhs.v.e3*rhs.b.e12 + 1.0*lhs.v.ei*rhs.q.e123o + 1.0*lhs.v.eo*rhs.q.e123i;
    result.t.e23o = -1.0*lhs.I5*rhs.b.e1o + 1.0*lhs.b.e12*rhs.t.e31o - 1.0*lhs.b.e1o*rhs.I5 - 1.0*lhs.b.e1o*rhs.t.e123 + 1.0*lhs.b.e23*rhs.v.eo - 1.0*lhs.b.e2o*rhs.t.e3oi - 1.0*lhs.b.e2o*rhs.v.e3 - 1.0*lhs.b.e31*rhs.t.e12o + 1.0*lhs.b.e3o*rhs.t.e2oi + 1.0*lhs.b.e3o*rhs.v.e2 - 1.0*lhs.b.eoi*rhs.t.e23o - 1.0*lhs.q.e123o*rhs.t.e1oi - 1.0*lhs.q.e123o*rhs.v.e1 - 1.0*lhs.q.e12oi*rhs.t.e31o - 1.0*lhs.q.e23oi*rhs.v.eo + 1.0*lhs.q.e31oi*rhs.t.e12o + 1.0*lhs.s*rhs.t.e23o + 1.0*lhs.t.e123*rhs.b.e1o + 1.0*lhs.t.e12o*rhs.b.e31 + 1.0*lhs.t.e12o*rhs.q.e31oi - 1.0*lhs.t.e1oi*rhs.q.e123o + 1.0*lhs.t.e23o*rhs.b.eoi + 1.0*lhs.t.e23o*rhs.s - 1.0*lhs.t.e2oi*rhs.b.e3o - 1.0*lhs.t.e31o*rhs.b.e12 - 1.0*lhs.t.e31o*rhs.q.e12oi + 1.0*lhs.t.e3oi*rhs.b.e2o + 1.0*lhs.v.e1*rhs.q.e123o + 1.0*lhs.v.e2*rhs.b.e3o - 1.0*lhs.v.e3*rhs.b.e2o + 1.0*lhs.v.eo*rhs.b.e23 + 1.0*lhs.v.eo*rhs.q.e23oi;
    result.t.e31o = -1.0*lhs.I5*rhs.b.e2o - 1.0*lhs.b.e12*rhs.t.e23o + 1.0*lhs.b.e1o*rhs.t.e3oi + 1.0*lhs.b.e1o*rhs.v.e3 + 1.0*lhs.b.e23*rhs.t.e12o - 1.0*lhs.b.e2o*rhs.I5 - 1.0*lhs.b.e2o*rhs.t.e123 + 1.0*lhs.b.e31*rhs.v.eo - 1.0*lhs.b.e3o*rhs.t.e1oi - 1.0*lhs.b.e3o*rhs.v.e1 - 1.0*lhs.b.eoi*rhs.t.e31o - 1.0*lhs.q.e123o*rhs.t.e2oi - 1.0*lhs.q.e123o*rhs.v.e2 + 1.0*lhs.q.e12oi*rhs.t.e23o - 1.0*lhs.q.e23oi*rhs.t.e12o - 1.0*lhs.q.e31oi*rhs.v.eo + 1.0*lhs.s*rhs.t.e31o + 1.0*lhs.t.e123*rhs.b.e2o - 1.0*lhs.t.e12o*rhs.b.e23 - 1.0*lhs.t.e12o*rhs.q.e23oi + 1.0*lhs.t.e1oi*rhs.b.e3o + 1.0*lhs.t.e23o*rhs.b.e12 + 1.0*lhs.t.e23o*rhs.q.e12oi - 1.0*lhs.t.e2oi*rhs.q.e123o + 1.0*lhs.t.e31o*rhs.b.eoi + 1.0*lhs.t.e31o*rhs.s - 1.0*lhs.t.e3oi*rhs.b.e1o - 1.0*lhs.v.e1*rhs.b.e3o + 1.0*lhs.v.e2*rhs.q.e123o + 1.0*lhs.v.e3*rhs.b.e1o + 1.0*lhs.v.eo*rhs.b.e31 + 1.0*lhs.v.eo*rhs.q.e31oi;
    result.t.e12o = -1.0*lhs.I5*rhs.b.e3o + 1.0*lhs.b.e12*rhs.v.eo - 1.0*lhs.b.e1o*rhs.t.e2oi - 1.0*lhs.b.e1o*rhs.v.e2 - 1.0*lhs.b.e23*rhs.t.e31o + 1.0*lhs.b.e2o*rhs.t.e1oi + 1.0*lhs.b.e2o*rhs.v.e1 + 1.0*lhs.b.e31*rhs.t.e23o - 1.0*lhs.b.e3o*rhs.I5 - 1.0*lhs.b.e3o*rhs.t.e123 - 1.0*lhs.b.eoi*rhs.t.e12o - 1.0*lhs.q.e123o*rhs.t.e3oi - 1.0*lhs.q.e123o*rhs.v.e3 - 1.0*lhs.q.e12oi*rhs.v.eo + 1.0*lhs.q.e23oi*rhs.t.e31o - 1.0*lhs.q.e31oi*rhs.t.e23o + 1.0*lhs.s*rhs.t.e12o + 1.0*lhs.t.e123*rhs.b.e3o + 1.0*lhs.t.e12o*rhs.b.eoi + 1.0*lhs.t.e12o*rhs.s - 1.0*lhs.t.e1oi*rhs.b.e2o - 1.0*lhs.t.e23o*rhs.b.e31 - 1.0*lhs.t.e23o*rhs.q.e31oi + 1.0*lhs.t.e2oi*rhs.b.e1o + 1.0*lhs.t.e31o*rhs.b.e23 + 1.0*lhs.t.e31o*rhs.q.e23oi - 1.0*lhs.t.e3oi*rhs.q.e123o + 1.0*lhs.v.e1*rhs.b.e2o - 1.0*lhs.v.e2*rhs.b.e1o + 1.0*lhs.v.e3*rhs.q.e123o + 1.0*lhs.v.eo*rhs.b.e12 + 1.0*lhs.v.eo*rhs.q.e12oi;
    result.t.e23i = 1.0*lhs.I5*rhs.b.e1i + 1.0*lhs.b.e12*rhs.t.e31i + 1.0*lhs.b.e1i*rhs.I5 - 1.0*lhs.b.e1i*rhs.t.e123 + 1.0*lhs.b.e23*rhs.v.ei + 1.0*lhs.b.e2i*rhs.t.e3oi - 1.0*lhs.b.e2i*rhs.v.e3 - 1.0*lhs.b.e31*rhs.t.e12i - 1.0*lhs.b.e3i*rhs.t.e2oi + 1.0*lhs.b.e3i*rhs.v.e2 + 1.0*lhs.b.eoi*rhs.t.e23i + 1.0*lhs.q.e123i*rhs.t.e1oi - 1.0*lhs.q.e123i*rhs.v.e1 + 1.0*lhs.q.e12oi*rhs.t.e31i + 1.0*lhs.q.e23oi*rhs.v.ei - 1.0*lhs.q.e31oi*rhs.t.e12i + 1.0*lhs.s*rhs.t.e23i + 1.0*lhs.t.e123*rhs.b.e1i + 1.0*lhs.t.e12i*rhs.b.e31 - 1.0*lhs.t.e12i*rhs.q.e31oi + 1.0*lhs.t.e1oi*rhs.q.e123i - 1.0*lhs.t.e23i*rhs.b.eoi + 1.0*lhs.t.e23i*rhs.s + 1.0*lhs.t.e2oi*rhs.b.e3i - 1.0*lhs.t.e31i*rhs.b.e12 + 1.0*lhs.t.e31i*rhs.q.e12oi - 1.0*lhs.t.e3oi*rhs.b.e2i + 1.0*lhs.v.e1*rhs.q.e123i + 1.0*lhs.v.e2*rhs.b.e3i - 1.0*lhs.v.e3*rhs.b.e2i + 1.0*lhs.v.ei*rhs.b.e23 - 1.0*lhs.v.ei*rhs.q.e23oi;
    result.t.e31i = 1.0*lhs.I5*rhs.b.e2i - 1.0*lhs.b.e12*rhs.t.e23i - 1.0*lhs.b.e1i*rhs.t.e3oi + 1.0*lhs.b.e1i*rhs.v.e3 + 1.0*lhs.b.e23*rhs.t.e12i + 1.0*lhs.b.e2i*rhs.I5 - 1.0*lhs.b.e2i*rhs.t.e123 + 1.0*lhs.b.e31*rhs.v.ei + 1.0*lhs.b.e3i*rhs.t.e1oi - 1.0*lhs.b.e3i*rhs.v.e1 + 1.0*lhs.b.eoi*rhs.t.e31i + 1.0*lhs.q.e123i*rhs.t.e2oi - 1.0*lhs.q.e123i*rhs.v.e2 - 1.0*lhs.q.e12oi*rhs.t.e23i + 1.0*lhs.q.e23oi*rhs.t.e12i + 1.0*lhs.q.e31oi*rhs.v.ei + 1.0*lhs.s*rhs.t.e31i + 1.0*lhs.t.e123*rhs.b.e2i - 1.0*lhs.t.e12i*rhs.b.e23 + 1.0*lhs.t.e12i*rhs.q.e23oi - 1.0*lhs.t.e1oi*rhs.b.e3i + 1.0*lhs.t.e23i*rhs.b.e12 - 1.0*lhs.t.e23i*rhs.q.e12oi + 1.0*lhs.t.e2oi*rhs.q.e123i - 1.0*lhs.t.e31i*rhs.b.eoi + 1.0*lhs.t.e31i*rhs.s + 1.0*lhs.t.e3oi*rhs.b.e1i - 1.0*lhs.v.e1*rhs.b.e3i + 1.0*lhs.v.e2*rhs.q.e123i + 1.0*lhs.v.e3*rhs.b.e1i + 1.0*lhs.v.ei*rhs.b.e31 - 1.0*lhs.v.ei*rhs.q.e31oi;
    result.t.e12i = 1.0*lhs.I5*rhs.b.e3i + 1.0*lhs.b.e12*rhs.v.ei + 1.0*lhs.b.e1i*rhs.t.e2oi - 1.0*lhs.b.e1i*rhs.v.e2 - 1.0*lhs.b.e23*rhs.t.e31i - 1.0*lhs.b.e2i*rhs.t.e1oi + 1.0*lhs.b.e2i*rhs.v.e1 + 1.0*lhs.b.e31*rhs.t.e23i + 1.0*lhs.b.e3i*rhs.I5 - 1.0*lhs.b.e3i*rhs.t.e123 + 1.0*lhs.b.eoi*rhs.t.e12i + 1.0*lhs.q.e123i*rhs.t.e3oi - 1.0*lhs.q.e123i*rhs.v.e3 + 1.0*lhs.q.e12oi*rhs.v.ei - 1.0*lhs.q.e23oi*rhs.t.e31i + 1.0*lhs.q.e31oi*rhs.t.e23i + 1.0*lhs.s*rhs.t.e12i + 1.0*lhs.t.e123*rhs.b.e3i - 1.0*lhs.t.e12i*rhs.b.eoi + 1.0*lhs.t.e12i*rhs.s + 1.0*lhs.t.e1oi*rhs.b.e2i - 1.0*lhs.t.e23i*rhs.b.e31 + 1.0*lhs.t.e23i*rhs.q.e31oi - 1.0*lhs.t.e2oi*rhs.b.e1i + 1.0*lhs.t.e31i*rhs.b.e23 - 1.0*lhs.t.e31i*rhs.q.e23oi + 1.0*lhs.t.e3oi*rhs.q.e123i + 1.0*lhs.v.e1*rhs.b.e2i - 1.0*lhs.v.e2*rhs.b.e1i + 1.0*lhs.v.e3*rhs.q.e123i + 1.0*lhs.v.ei*rhs.b.e12 - 1.0*lhs.v.ei*rhs.q.e12oi;
    result.t.e1oi = -1.0*lhs.I5*rhs.b.e23 + 1.0*lhs.b.e12*rhs.t.e2oi - 1.0*lhs.b.e1i*rhs.v.eo + 1.0*lhs.b.e1o*rhs.v.ei - 1.0*lhs.b.e23*rhs.I5 + 1.0*lhs.b.e2i*rhs.t.e12o - 1.0*lhs.b.e2o*rhs.t.e12i - 1.0*lhs.b.e31*rhs.t.e3oi - 1.0*lhs.b.e3i*rhs.t.e31o + 1.0*lhs.b.e3o*rhs.t.e31i + 1.0*lhs.b.eoi*rhs.v.e1 + 1.0*lhs.q.e123i*rhs.t.e23o - 1.0*lhs.q.e123o*rhs.t.e23i + 1.0*lhs.q.e12oi*rhs.v.e2 - 1.0*lhs.q.e23oi*rhs.t.e123 - 1.0*lhs.q.e31oi*rhs.v.e3 + 1.0*lhs.s*rhs.t.e1oi - 1.0*lhs.t.e123*rhs.q.e23oi + 1.0*lhs.t.e12i*rhs.b.e2o - 1.0*lhs.t.e12o*rhs.b.e2i + 1.0*lhs.t.e1oi*rhs.s - 1.0*lhs.t.e23i*rhs.q.e123o + 1.0*lhs.t.e23o*rhs.q.e123i - 1.0*lhs.t.e2oi*rhs.b.e12 - 1.0*lhs.t.e31i*rhs.b.e3o + 1.0*lhs.t.e31o*rhs.b.e3i + 1.0*lhs.t.e3oi*rhs.b.e31 + 1.0*lhs.v.e1*rhs.b.eoi - 1.0*lhs.v.e2*rhs.q.e12oi + 1.0*lhs.v.e3*rhs.q.e31oi + 1.0*lhs.v.ei*rhs.b.e1o - 1.0*lhs.v.eo*rhs.b.e1i;
    result.t.e2oi = -1.0*lhs.I5*rhs.b.e31 - 1.0*lhs.b.e12*rhs.t.e1oi - 1.0*lhs.b.e1i*rhs.t.e12o + 1.0*lhs.b.e1o*rhs.t.e12i + 1.0*lhs.b.e23*rhs.t.e3oi - 1.0*lhs.b.e2i*rhs.v.eo + 1.0*lhs.b.e2o*rhs.v.ei - 1.0*lhs.b.e31*rhs.I5 + 1.0*lhs.b.e3i*rhs.t.e23o - 1.0*lhs.b.e3o*rhs.t.e23i + 1.0*lhs.b.eoi*rhs.v.e2 + 1.0*lhs.q.e123i*rhs.t.e31o - 1.0*lhs.q.e123o*rhs.t.e31i - 1.0*lhs.q.e12oi*rhs.v.e1 + 1.0*lhs.q.e23oi*rhs.v.e3 - 1.0*lhs.q.e31oi*rhs.t.e123 + 1.0*lhs.s*rhs.t.e2oi - 1.0*lhs.t.e123*rhs.q.e31oi - 1.0*lhs.t.e12i*rhs.b.e1o + 1.0*lhs.t.e12o*rhs.b.e1i + 1.0*lhs.t.e1oi*rhs.b.e12 + 1.0*lhs.t.e23i*rhs.b.e3o - 1.0*lhs.t.e23o*rhs.b.e3i + 1.0*lhs.t.e2oi*rhs.s - 1.0*lhs.t.e31i*rhs.q.e123o + 1.0*lhs.t.e31o*rhs.q.e123i - 1.0*lhs.t.e3oi*rhs.b.e23 + 1.0*lhs.v.e1*rhs.q.e12oi + 1.0*lhs.v.e2*rhs.b.eoi - 1.0*lhs.v.e3*rhs.q.e23oi + 1.0*lhs.v.ei*rhs.b.e2o - 1.0*lhs.v.eo*rhs.b.e2i;
    result.t.e3oi = -1.0*lhs.I5*rhs.b.e12 - 1.0*lhs.b.e12*rhs.I5 + 1.0*lhs.b.e1i*rhs.t.e31o - 1.0*lhs.b.e1o*rhs.t.e31i - 1.0*lhs.b.e23*rhs.t.e2oi - 1.0*lhs.b.e2i*rhs.t.e23o + 1.0*lhs.b.e2o*rhs.t.e23i + 1.0*lhs.b.e31*rhs.t.e1oi - 1.0*lhs.b.e3i*rhs.v.eo + 1.0*lhs.b.e3o*rhs.v.ei + 1.0*lhs.b.eoi*rhs.v.e3 + 1.0*lhs.q.e123i*rhs.t.e12o - 1.0*lhs.q.e123o*rhs.t.e12i - 1.0*lhs.q.e12oi*rhs.t.e123 - 1.0*lhs.q.e23oi*rhs.v.e2 + 1.0*lhs.q.e31oi*rhs.v.e1 + 1.0*lhs.s*rhs.t.e3oi - 1.0*lhs.t.e123*rhs.q.e12oi - 1.0*lhs.t.e12i*rhs.q.e123o + 1.0*lhs.t.e12o*rhs.q.e123i - 1.0*lhs.t.e1oi*rhs.b.e31 - 1.0*lhs.t.e23i*rhs.b.e2o + 1.0*lhs.t.e23o*rhs.b.e2i + 1.0*lhs.t.e2oi*rhs.b.e23 + 1.0*lhs.t.e31i*rhs.b.e1o - 1.0*lhs.t.e31o*rhs.b.e1i + 1.0*lhs.t.e3oi*rhs.s - 1.0*lhs.v.e1*rhs.q.e31oi + 1.0*lhs.v.e2*rhs.q.e23oi + 1.0*lhs.v.e3*rhs.b.eoi + 1.0*lhs.v.ei*rhs.b.e3o - 1.0*lhs.v.eo*rhs.b.e3i;
    result.q.e123o = -1.0*lhs.I5*rhs.v.eo + 1.0*lhs.b.e12*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e23 + 1.0*lhs.b.e1o*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e31 + 1.0*lhs.b.e2o*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e12 + 1.0*lhs.b.e3o*rhs.q.e12oi - 1.0*lhs.b.eoi*rhs.q.e123o + 1.0*lhs.q.e123o*rhs.b.eoi + 1.0*lhs.q.e123o*rhs.s - 1.0*lhs.q.e12oi*rhs.b.e3o - 1.0*lhs.q.e23oi*rhs.b.e1o - 1.0*lhs.q.e31oi*rhs.b.e2o + 1.0*lhs.s*rhs.q.e123o + 1.0*lhs.t.e123*rhs.v.eo - 1.0*lhs.t.e12o*rhs.t.e3oi - 1.0*lhs.t.e12o*rhs.v.e3 - 1.0*lhs.t.e1oi*rhs.t.e23o - 1.0*lhs.t.e23o*rhs.t.e1oi - 1.0*lhs.t.e23o*rhs.v.e1 - 1.0*lhs.t.e2oi*rhs.t.e31o - 1.0*lhs.t.e31o*rhs.t.e2oi - 1.0*lhs.t.e31o*rhs.v.e2 - 1.0*lhs.t.e3oi*rhs.t.e12o + 1.0*lhs.v.e1*rhs.t.e23o + 1.0*lhs.v.e2*rhs.t.e31o + 1.0*lhs.v.e3*rhs.t.e12o - 1.0*lhs.v.eo*rhs.I5 - 1.0*lhs.v.eo*rhs.t.e123;
    result.q.e123i = 1.0*lhs.I5*rhs.v.ei + 1.0*lhs.b.e12*rhs.b.e3i + 1.0*lhs.b.e1i*rhs.b.e23 - 1.0*lhs.b.e1i*rhs.q.e23oi + 1.0*lhs.b.e23*rhs.b.e1i + 1.0*lhs.b.e2i*rhs.b.e31 - 1.0*lhs.b.e2i*rhs.q.e31oi + 1.0*lhs.b.e31*rhs.b.e2i + 1.0*lhs.b.e3i*rhs.b.e12 - 1.0*lhs.b.e3i*rhs.q.e12oi + 1.0*lhs.b.eoi*rhs.q.e123i - 1.0*lhs.q.e123i*rhs.b.eoi + 1.0*lhs.q.e123i*rhs.s + 1.0*lhs.q.e12oi*rhs.b.e3i + 1.0*lhs.q.e23oi*rhs.b.e1i + 1.0*lhs.q.e31oi*rhs.b.e2i + 1.0*lhs.s*rhs.q.e123i + 1.0*lhs.t.e123*rhs.v.ei + 1.0*lhs.t.e12i*rhs.t.e3oi - 1.0*lhs.t.e12i*rhs.v.e3 + 1.0*lhs.t.e1oi*rhs.t.e23i + 1.0*lhs.t.e23i*rhs.t.e1oi - 1.0*lhs.t.e23i*rhs.v.e1 + 1.0*lhs.t.e2oi*rhs.t.e31i + 1.0*lhs.t.e31i*rhs.t.e2oi - 1.0*lhs.t.e31i*rhs.v.e2 + 1.0*lhs.t.e3oi*rhs.t.e12i + 1.0*lhs.v.e1*rhs.t.e23i + 1.0*lhs.v.e2*rhs.t.e31i + 1.0*lhs.v.e3*rhs.t.e12i + 1.0*lhs.v.ei*rhs.I5 - 1.0*lhs.v.ei*rhs.t.e123;
    result.q.e23oi = 1.0*lhs.I5*rhs.v.e1 + 1.0*lhs.b.e12*rhs.q.e31oi + 1.0*lhs.b.e1i*rhs.q.e123o - 1.0*lhs.b.e1o*rhs.q.e123i + 1.0*lhs.b.e23*rhs.b.eoi + 1.0*lhs.b.e2i*rhs.b.e3o - 1.0*lhs.b.e2o*rhs.b.e3i - 1.0*lhs.b.e31*rhs.q.e12oi - 1.0*lhs.b.e3i*rhs.b.e2o + 1.0*lhs.b.e3o*rhs.b.e2i + 1.0*lhs.b.eoi*rhs.b.e23 + 1.0*lhs.q.e123i*rhs.b.e1o - 1.0*lhs.q.e123o*rhs.b.e1i + 1.0*lhs.q.e12oi*rhs.b.e31 + 1.0*lhs.q.e23oi*rhs.s - 1.0*lhs.q.e31oi*rhs.b.e12 + 1.0*lhs.s*rhs.q.e23oi + 1.0*lhs.t.e123*rhs.t.e1oi - 1.0*lhs.t.e12i*rhs.t.e31o + 1.0*lhs.t.e12o*rhs.t.e31i + 1.0*lhs.t.e1oi*rhs.t.e123 - 1.0*lhs.t.e23i*rhs.v.eo + 1.0*lhs.t.e23o*rhs.v.ei + 1.0*lhs.t.e2oi*rhs.v.e3 + 1.0*lhs.t.e31i*rhs.t.e12o - 1.0*lhs.t.e31o*rhs.t.e12i - 1.0*lhs.t.e3oi*rhs.v.e2 + 1.0*lhs.v.e1*rhs.I5 + 1.0*lhs.v.e2*rhs.t.e3oi - 1.0*lhs.v.e3*rhs.t.e2oi - 1.0*lhs.v.ei*rhs.t.e23o + 1.0*lhs.v.eo*rhs.t.e23i;
    result.q.e31oi = 1.0*lhs.I5*rhs.v.e2 - 1.0*lhs.b.e12*rhs.q.e23oi - 1.0*lhs.b.e1i*rhs.b.e3o + 1.0*lhs.b.e1o*rhs.b.e3i + 1.0*lhs.b.e23*rhs.q.e12oi + 1.0*lhs.b.e2i*rhs.q.e123o - 1.0*lhs.b.e2o*rhs.q.e123i + 1.0*lhs.b.e31*rhs.b.eoi + 1.0*lhs.b.e3i*rhs.b.e1o - 1.0*lhs.b.e3o*rhs.b.e1i + 1.0*lhs.b.eoi*rhs.b.e31 + 1.0*lhs.q.e123i*rhs.b.e2o - 1.0*lhs.q.e123o*rhs.b.e2i - 1.0*lhs.q.e12oi*rhs.b.e23 + 1.0*lhs.q.e23oi*rhs.b.e12 + 1.0*lhs.q.e31oi*rhs.s + 1.0*lhs.s*rhs.q.e31oi + 1.0*lhs.t.e123*rhs.t.e2oi + 1.0*lhs.t.e12i*rhs.t.e23o - 1.0*lhs.t.e12o*rhs.t.e23i - 1.0*lhs.t.e1oi*rhs.v.e3 - 1.0*lhs.t.e23i*rhs.t.e12o + 1.0*lhs.t.e23o*rhs.t.e12i + 1.0*lhs.t.e2oi*rhs.t.e123 - 1.0*lhs.t.e31i*rhs.v.eo + 1.0*lhs.t.e31o*rhs.v.ei + 1.0*lhs.t.e3oi*rhs.v.e1 - 1.0*lhs.v.e1*rhs.t.e3oi + 1.0*lhs.v.e2*rhs.I5 + 1.0*lhs.v.e3*rhs.t.e1oi - 1.0*lhs.v.ei*rhs.t.e31o + 1.0*lhs.v.eo*rhs.t.e31i;
    result.q.e12oi = 1.0*lhs.I5*rhs.v.e3 + 1.0*lhs.b.e12*rhs.b.eoi + 1.0*lhs.b.e1i*rhs.b.e2o - 1.0*lhs.b.e1o*rhs.b.e2i - 1.0*lhs.b.e23*rhs.q.e31oi - 1.0*lhs.b.e2i*rhs.b.e1o + 1.0*lhs.b.e2o*rhs.b.e1i + 1.0*lhs.b.e31*rhs.q.e23oi + 1.0*lhs.b.e3i*rhs.q.e123o - 1.0*lhs.b.e3o*rhs.q.e123i + 1.0*lhs.b.eoi*rhs.b.e12 + 1.0*lhs.q.e123i*rhs.b.e3o - 1.0*lhs.q.e123o*rhs.b.e3i + 1.0*lhs.q.e12oi*rhs.s - 1.0*lhs.q.e23oi*rhs.b.e31 + 1.0*lhs.q.e31oi*rhs.b.e23 + 1.0*lhs.s*rhs.q.e12oi + 1.0*lhs.t.e123*rhs.t.e3oi - 1.0*lhs.t.e12i*rhs.v.eo + 1.0*lhs.t.e12o*rhs.v.ei + 1.0*lhs.t.e1oi*rhs.v.e2 + 1.0*lhs.t.e23i*rhs.t.e31o - 1.0*lhs.t.e23o*rhs.t.e31i - 1.0*lhs.t.e2oi*rhs.v.e1 - 1.0*lhs.t.e31i*rhs.t.e23o + 1.0*lhs.t.e31o*rhs.t.e23i + 1.0*lhs.t.e3oi*rhs.t.e123 + 1.0*lhs.v.e1*rhs.t.e2oi - 1.0*lhs.v.e2*rhs.t.e1oi + 1.0*lhs.v.e3*rhs.I5 - 1.0*lhs.v.ei*rhs.t.e12o + 1.0*lhs.v.eo*rhs.t.e12i;
    result.I5 = 1.0*lhs.I5*rhs.s + 1.0*lhs.b.e12*rhs.t.e3oi - 1.0*lhs.b.e1i*rhs.t.e23o + 1.0*lhs.b.e1o*rhs.t.e23i + 1.0*lhs.b.e23*rhs.t.e1oi - 1.0*lhs.b.e2i*rhs.t.e31o + 1.0*lhs.b.e2o*rhs.t.e31i + 1.0*lhs.b.e31*rhs.t.e2oi - 1.0*lhs.b.e3i*rhs.t.e12o + 1.0*lhs.b.e3o*rhs.t.e12i + 1.0*lhs.b.eoi*rhs.t.e123 - 1.0*lhs.q.e123i*rhs.v.eo + 1.0*lhs.q.e123o*rhs.v.ei + 1.0*lhs.q.e12oi*rhs.v.e3 + 1.0*lhs.q.e23oi*rhs.v.e1 + 1.0*lhs.q.e31oi*rhs.v.e2 + 1.0*lhs.s*rhs.I5 + 1.0*lhs.t.e123*rhs.b.eoi + 1.0*lhs.t.e12i*rhs.b.e3o - 1.0*lhs.t.e12o*rhs.b.e3i + 1.0*lhs.t.e1oi*rhs.b.e23 + 1.0*lhs.t.e23i*rhs.b.e1o - 1.0*lhs.t.e23o*rhs.b.e1i + 1.0*lhs.t.e2oi*rhs.b.e31 + 1.0*lhs.t.e31i*rhs.b.e2o - 1.0*lhs.t.e31o*rhs.b.e2i + 1.0*lhs.t.e3oi*rhs.b.e12 + 1.0*lhs.v.e1*rhs.q.e23oi + 1.0*lhs.v.e2*rhs.q.e31oi + 1.0*lhs.v.e3*rhs.q.e12oi + 1.0*lhs.v.ei*rhs.q.e123o - 1.0*lhs.v.eo*rhs.q.e123i;
    return result;
}
} // namespace cga
