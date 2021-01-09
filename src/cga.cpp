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
