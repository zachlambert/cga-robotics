#include "cga.h"

namespace cga {

double operator*(const Pseudoscalar &lhs, const Pseudoscalar &rhs)
{
    double result;
    result = -lhs.p*rhs.p;
    return result;
}

double outer(const Pseudoscalar &lhs, const Pseudoscalar &rhs)
{
    double result;
    result = -lhs.p*rhs.p;
    return result;
}

double inner(const Pseudoscalar &lhs, const Pseudoscalar &rhs)
{
    double result;
    result = -lhs.p*rhs.p;
    return result;
}

Bivector operator*(const Pseudoscalar &lhs, const Pseudoscalar3 &rhs)
{
    Bivector result;
    result.eoi = -lhs.p*rhs.p;
    return result;
}

Bivector outer(const Pseudoscalar &lhs, const Pseudoscalar3 &rhs)
{
    Bivector result;
    result.eoi = -lhs.p*rhs.p;
    return result;
}

Bivector inner(const Pseudoscalar &lhs, const Pseudoscalar3 &rhs)
{
    Bivector result;
    result.eoi = -lhs.p*rhs.p;
    return result;
}

Quadvector operator*(const Pseudoscalar &lhs, const Vector3 &rhs)
{
    Quadvector result;
    result.e23oi = lhs.p*rhs.e1;
    result.e31oi = lhs.p*rhs.e2;
    result.e12oi = lhs.p*rhs.e3;
    return result;
}

Quadvector outer(const Pseudoscalar &lhs, const Vector3 &rhs)
{
    Quadvector result;
    result.e23oi = lhs.p*rhs.e1;
    result.e31oi = lhs.p*rhs.e2;
    result.e12oi = lhs.p*rhs.e3;
    return result;
}

Quadvector inner(const Pseudoscalar &lhs, const Vector3 &rhs)
{
    Quadvector result;
    result.e23oi = lhs.p*rhs.e1;
    result.e31oi = lhs.p*rhs.e2;
    result.e12oi = lhs.p*rhs.e3;
    return result;
}

Trivector operator*(const Pseudoscalar &lhs, const Bivector3 &rhs)
{
    Trivector result;
    result.e1oi = -lhs.p*rhs.e23;
    result.e2oi = -lhs.p*rhs.e31;
    result.e3oi = -lhs.p*rhs.e12;
    return result;
}

Trivector outer(const Pseudoscalar &lhs, const Bivector3 &rhs)
{
    Trivector result;
    result.e1oi = -lhs.p*rhs.e23;
    result.e2oi = -lhs.p*rhs.e31;
    result.e3oi = -lhs.p*rhs.e12;
    return result;
}

Trivector inner(const Pseudoscalar &lhs, const Bivector3 &rhs)
{
    Trivector result;
    result.e1oi = -lhs.p*rhs.e23;
    result.e2oi = -lhs.p*rhs.e31;
    result.e3oi = -lhs.p*rhs.e12;
    return result;
}

Multivector operator*(const Pseudoscalar &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector outer(const Pseudoscalar &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector inner(const Pseudoscalar &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Quadvector operator*(const Pseudoscalar &lhs, const Vector &rhs)
{
    Quadvector result;
    result.e123o = -lhs.p*rhs.eo;
    result.e123i = lhs.p*rhs.ei;
    result.e23oi = lhs.p*rhs.e1;
    result.e31oi = lhs.p*rhs.e2;
    result.e12oi = lhs.p*rhs.e3;
    return result;
}

Quadvector outer(const Pseudoscalar &lhs, const Vector &rhs)
{
    Quadvector result;
    result.e123o = -lhs.p*rhs.eo;
    result.e123i = lhs.p*rhs.ei;
    result.e23oi = lhs.p*rhs.e1;
    result.e31oi = lhs.p*rhs.e2;
    result.e12oi = lhs.p*rhs.e3;
    return result;
}

Quadvector inner(const Pseudoscalar &lhs, const Vector &rhs)
{
    Quadvector result;
    result.e123o = -lhs.p*rhs.eo;
    result.e123i = lhs.p*rhs.ei;
    result.e23oi = lhs.p*rhs.e1;
    result.e31oi = lhs.p*rhs.e2;
    result.e12oi = lhs.p*rhs.e3;
    return result;
}

Vector operator*(const Pseudoscalar &lhs, const Quadvector &rhs)
{
    Vector result;
    result.e1 = -lhs.p*rhs.e23oi;
    result.e2 = -lhs.p*rhs.e31oi;
    result.e3 = -lhs.p*rhs.e12oi;
    result.eo = 0.5*lhs.p*rhs.e123i;
    result.ei = -lhs.p*rhs.e123i;
    return result;
}

Vector outer(const Pseudoscalar &lhs, const Quadvector &rhs)
{
    Vector result;
    result.e1 = -lhs.p*rhs.e23oi;
    result.e2 = -lhs.p*rhs.e31oi;
    result.e3 = -lhs.p*rhs.e12oi;
    result.eo = 0.5*lhs.p*rhs.e123i;
    result.ei = -lhs.p*rhs.e123i;
    return result;
}

Vector inner(const Pseudoscalar &lhs, const Quadvector &rhs)
{
    Vector result;
    result.e1 = -lhs.p*rhs.e23oi;
    result.e2 = -lhs.p*rhs.e31oi;
    result.e3 = -lhs.p*rhs.e12oi;
    result.eo = 0.5*lhs.p*rhs.e123i;
    result.ei = -lhs.p*rhs.e123i;
    return result;
}

Trivector operator*(const Pseudoscalar &lhs, const Bivector &rhs)
{
    Trivector result;
    result.e123 = lhs.p*rhs.eoi;
    result.e23o = -lhs.p*rhs.e1o;
    result.e31o = -lhs.p*rhs.e2o;
    result.e12o = -lhs.p*rhs.e3o;
    result.e23i = lhs.p*rhs.e1i;
    result.e31i = lhs.p*rhs.e2i;
    result.e12i = lhs.p*rhs.e3i;
    result.e1oi = -lhs.p*rhs.e23;
    result.e2oi = -lhs.p*rhs.e31;
    result.e3oi = -lhs.p*rhs.e12;
    return result;
}

Trivector outer(const Pseudoscalar &lhs, const Bivector &rhs)
{
    Trivector result;
    result.e123 = lhs.p*rhs.eoi;
    result.e23o = -lhs.p*rhs.e1o;
    result.e31o = -lhs.p*rhs.e2o;
    result.e12o = -lhs.p*rhs.e3o;
    result.e23i = lhs.p*rhs.e1i;
    result.e31i = lhs.p*rhs.e2i;
    result.e12i = lhs.p*rhs.e3i;
    result.e1oi = -lhs.p*rhs.e23;
    result.e2oi = -lhs.p*rhs.e31;
    result.e3oi = -lhs.p*rhs.e12;
    return result;
}

Trivector inner(const Pseudoscalar &lhs, const Bivector &rhs)
{
    Trivector result;
    result.e123 = lhs.p*rhs.eoi;
    result.e23o = -lhs.p*rhs.e1o;
    result.e31o = -lhs.p*rhs.e2o;
    result.e12o = -lhs.p*rhs.e3o;
    result.e23i = lhs.p*rhs.e1i;
    result.e31i = lhs.p*rhs.e2i;
    result.e12i = lhs.p*rhs.e3i;
    result.e1oi = -lhs.p*rhs.e23;
    result.e2oi = -lhs.p*rhs.e31;
    result.e3oi = -lhs.p*rhs.e12;
    return result;
}

Bivector operator*(const Pseudoscalar &lhs, const Trivector &rhs)
{
    Bivector result;
    result.e23 = lhs.p*rhs.e1oi;
    result.e31 = lhs.p*rhs.e2oi;
    result.e12 = lhs.p*rhs.e3oi;
    result.e1o = lhs.p*rhs.e23o;
    result.e2o = lhs.p*rhs.e31o;
    result.e3o = lhs.p*rhs.e12o;
    result.e1i = -lhs.p*rhs.e23i;
    result.e2i = -lhs.p*rhs.e31i;
    result.e3i = -lhs.p*rhs.e12i;
    result.eoi = -lhs.p*rhs.e123;
    return result;
}

Bivector outer(const Pseudoscalar &lhs, const Trivector &rhs)
{
    Bivector result;
    result.e23 = lhs.p*rhs.e1oi;
    result.e31 = lhs.p*rhs.e2oi;
    result.e12 = lhs.p*rhs.e3oi;
    result.e1o = lhs.p*rhs.e23o;
    result.e2o = lhs.p*rhs.e31o;
    result.e3o = lhs.p*rhs.e12o;
    result.e1i = -lhs.p*rhs.e23i;
    result.e2i = -lhs.p*rhs.e31i;
    result.e3i = -lhs.p*rhs.e12i;
    result.eoi = -lhs.p*rhs.e123;
    return result;
}

Bivector inner(const Pseudoscalar &lhs, const Trivector &rhs)
{
    Bivector result;
    result.e23 = lhs.p*rhs.e1oi;
    result.e31 = lhs.p*rhs.e2oi;
    result.e12 = lhs.p*rhs.e3oi;
    result.e1o = lhs.p*rhs.e23o;
    result.e2o = lhs.p*rhs.e31o;
    result.e3o = lhs.p*rhs.e12o;
    result.e1i = -lhs.p*rhs.e23i;
    result.e2i = -lhs.p*rhs.e31i;
    result.e3i = -lhs.p*rhs.e12i;
    result.eoi = -lhs.p*rhs.e123;
    return result;
}

Multivector operator*(const Pseudoscalar &lhs, const Rotor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector outer(const Pseudoscalar &lhs, const Rotor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector inner(const Pseudoscalar &lhs, const Rotor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector operator*(const Pseudoscalar &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.q.e23oi;
    result.v.e2 = -lhs.p*rhs.q.e31oi;
    result.v.e3 = -lhs.p*rhs.q.e12oi;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector outer(const Pseudoscalar &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.q.e23oi;
    result.v.e2 = -lhs.p*rhs.q.e31oi;
    result.v.e3 = -lhs.p*rhs.q.e12oi;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector inner(const Pseudoscalar &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.q.e23oi;
    result.v.e2 = -lhs.p*rhs.q.e31oi;
    result.v.e3 = -lhs.p*rhs.q.e12oi;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector operator*(const Pseudoscalar &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.p*rhs.p;
    result.v.e1 = -lhs.p*rhs.q.e23oi;
    result.v.e2 = -lhs.p*rhs.q.e31oi;
    result.v.e3 = -lhs.p*rhs.q.e12oi;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.p*rhs.t.e1oi;
    result.b.e31 = lhs.p*rhs.t.e2oi;
    result.b.e12 = lhs.p*rhs.t.e3oi;
    result.b.e1o = lhs.p*rhs.t.e23o;
    result.b.e2o = lhs.p*rhs.t.e31o;
    result.b.e3o = lhs.p*rhs.t.e12o;
    result.b.e1i = -lhs.p*rhs.t.e23i;
    result.b.e2i = -lhs.p*rhs.t.e31i;
    result.b.e3i = -lhs.p*rhs.t.e12i;
    result.b.eoi = -lhs.p*rhs.t.e123;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.q.e123o = -lhs.p*rhs.v.eo;
    result.q.e123i = lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.p*rhs.v.e1;
    result.q.e31oi = lhs.p*rhs.v.e2;
    result.q.e12oi = lhs.p*rhs.v.e3;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector outer(const Pseudoscalar &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.p*rhs.p;
    result.v.e1 = -lhs.p*rhs.q.e23oi;
    result.v.e2 = -lhs.p*rhs.q.e31oi;
    result.v.e3 = -lhs.p*rhs.q.e12oi;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.p*rhs.t.e1oi;
    result.b.e31 = lhs.p*rhs.t.e2oi;
    result.b.e12 = lhs.p*rhs.t.e3oi;
    result.b.e1o = lhs.p*rhs.t.e23o;
    result.b.e2o = lhs.p*rhs.t.e31o;
    result.b.e3o = lhs.p*rhs.t.e12o;
    result.b.e1i = -lhs.p*rhs.t.e23i;
    result.b.e2i = -lhs.p*rhs.t.e31i;
    result.b.e3i = -lhs.p*rhs.t.e12i;
    result.b.eoi = -lhs.p*rhs.t.e123;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.q.e123o = -lhs.p*rhs.v.eo;
    result.q.e123i = lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.p*rhs.v.e1;
    result.q.e31oi = lhs.p*rhs.v.e2;
    result.q.e12oi = lhs.p*rhs.v.e3;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector inner(const Pseudoscalar &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.p*rhs.p;
    result.v.e1 = -lhs.p*rhs.q.e23oi;
    result.v.e2 = -lhs.p*rhs.q.e31oi;
    result.v.e3 = -lhs.p*rhs.q.e12oi;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.p*rhs.t.e1oi;
    result.b.e31 = lhs.p*rhs.t.e2oi;
    result.b.e12 = lhs.p*rhs.t.e3oi;
    result.b.e1o = lhs.p*rhs.t.e23o;
    result.b.e2o = lhs.p*rhs.t.e31o;
    result.b.e3o = lhs.p*rhs.t.e12o;
    result.b.e1i = -lhs.p*rhs.t.e23i;
    result.b.e2i = -lhs.p*rhs.t.e31i;
    result.b.e3i = -lhs.p*rhs.t.e12i;
    result.b.eoi = -lhs.p*rhs.t.e123;
    result.t.e123 = lhs.p*rhs.b.eoi;
    result.t.e23o = -lhs.p*rhs.b.e1o;
    result.t.e31o = -lhs.p*rhs.b.e2o;
    result.t.e12o = -lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.b.e23;
    result.t.e2oi = -lhs.p*rhs.b.e31;
    result.t.e3oi = -lhs.p*rhs.b.e12;
    result.q.e123o = -lhs.p*rhs.v.eo;
    result.q.e123i = lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.p*rhs.v.e1;
    result.q.e31oi = lhs.p*rhs.v.e2;
    result.q.e12oi = lhs.p*rhs.v.e3;
    result.p = lhs.p*rhs.s;
    return result;
}

double operator*(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs)
{
    double result;
    result = -lhs.p*rhs.p;
    return result;
}

double inner(const Pseudoscalar3 &lhs, const Pseudoscalar3 &rhs)
{
    double result;
    result = -lhs.p*rhs.p;
    return result;
}

Bivector3 operator*(const Pseudoscalar3 &lhs, const Vector3 &rhs)
{
    Bivector3 result;
    result.e23 = lhs.p*rhs.e1;
    result.e31 = lhs.p*rhs.e2;
    result.e12 = lhs.p*rhs.e3;
    return result;
}

Bivector3 inner(const Pseudoscalar3 &lhs, const Vector3 &rhs)
{
    Bivector3 result;
    result.e23 = lhs.p*rhs.e1;
    result.e31 = lhs.p*rhs.e2;
    result.e12 = lhs.p*rhs.e3;
    return result;
}

Vector3 operator*(const Pseudoscalar3 &lhs, const Bivector3 &rhs)
{
    Vector3 result;
    result.e1 = -lhs.p*rhs.e23;
    result.e2 = -lhs.p*rhs.e31;
    result.e3 = -lhs.p*rhs.e12;
    return result;
}

Vector3 inner(const Pseudoscalar3 &lhs, const Bivector3 &rhs)
{
    Vector3 result;
    result.e1 = -lhs.p*rhs.e23;
    result.e2 = -lhs.p*rhs.e31;
    result.e3 = -lhs.p*rhs.e12;
    return result;
}

Multivector operator*(const Pseudoscalar3 &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.t.e123 = lhs.p*rhs.s;
    return result;
}

Pseudoscalar3 outer(const Pseudoscalar3 &lhs, const Rotor3 &rhs)
{
    Pseudoscalar3 result;
    result.p = lhs.p*rhs.s;
    return result;
}

Multivector inner(const Pseudoscalar3 &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.t.e123 = lhs.p*rhs.s;
    return result;
}

Versor operator*(const Pseudoscalar3 &lhs, const Vector &rhs)
{
    Versor result;
    result.b.e23 = lhs.p*rhs.e1;
    result.b.e31 = lhs.p*rhs.e2;
    result.b.e12 = lhs.p*rhs.e3;
    result.q.e123o = lhs.p*rhs.eo;
    result.q.e123i = lhs.p*rhs.ei;
    return result;
}

Quadvector outer(const Pseudoscalar3 &lhs, const Vector &rhs)
{
    Quadvector result;
    result.e123o = lhs.p*rhs.eo;
    result.e123i = lhs.p*rhs.ei;
    return result;
}

Bivector3 inner(const Pseudoscalar3 &lhs, const Vector &rhs)
{
    Bivector3 result;
    result.e23 = lhs.p*rhs.e1;
    result.e31 = lhs.p*rhs.e2;
    result.e12 = lhs.p*rhs.e3;
    return result;
}

Multivector operator*(const Pseudoscalar3 &lhs, const Quadvector &rhs)
{
    Multivector result;
    result.v.eo = 0.5*lhs.p*rhs.e123i;
    result.v.ei = -lhs.p*rhs.e123i;
    result.t.e1oi = -lhs.p*rhs.e23oi;
    result.t.e2oi = -lhs.p*rhs.e31oi;
    result.t.e3oi = -lhs.p*rhs.e12oi;
    return result;
}

Trivector outer(const Pseudoscalar3 &lhs, const Quadvector &rhs)
{
    Trivector result;
    result.e1oi = -lhs.p*rhs.e23oi;
    result.e2oi = -lhs.p*rhs.e31oi;
    result.e3oi = -lhs.p*rhs.e12oi;
    return result;
}

Vector inner(const Pseudoscalar3 &lhs, const Quadvector &rhs)
{
    Vector result;
    result.eo = 0.5*lhs.p*rhs.e123i;
    result.ei = -lhs.p*rhs.e123i;
    return result;
}

Multivector operator*(const Pseudoscalar3 &lhs, const Bivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.e23;
    result.v.e2 = -lhs.p*rhs.e31;
    result.v.e3 = -lhs.p*rhs.e12;
    result.t.e23o = lhs.p*rhs.e1o;
    result.t.e31o = lhs.p*rhs.e2o;
    result.t.e12o = lhs.p*rhs.e3o;
    result.t.e23i = lhs.p*rhs.e1i;
    result.t.e31i = lhs.p*rhs.e2i;
    result.t.e12i = lhs.p*rhs.e3i;
    result.p = lhs.p*rhs.eoi;
    return result;
}

Pseudoscalar outer(const Pseudoscalar3 &lhs, const Bivector &rhs)
{
    Pseudoscalar result;
    result.p = lhs.p*rhs.eoi;
    return result;
}

Vector3 inner(const Pseudoscalar3 &lhs, const Bivector &rhs)
{
    Vector3 result;
    result.e1 = -lhs.p*rhs.e23;
    result.e2 = -lhs.p*rhs.e31;
    result.e3 = -lhs.p*rhs.e12;
    return result;
}

Versor operator*(const Pseudoscalar3 &lhs, const Trivector &rhs)
{
    Versor result;
    result.s = -lhs.p*rhs.e123;
    result.b.e1o = -lhs.p*rhs.e23o;
    result.b.e2o = -lhs.p*rhs.e31o;
    result.b.e3o = -lhs.p*rhs.e12o;
    result.b.e1i = -lhs.p*rhs.e23i;
    result.b.e2i = -lhs.p*rhs.e31i;
    result.b.e3i = -lhs.p*rhs.e12i;
    result.q.e23oi = lhs.p*rhs.e1oi;
    result.q.e31oi = lhs.p*rhs.e2oi;
    result.q.e12oi = lhs.p*rhs.e3oi;
    return result;
}

Quadvector outer(const Pseudoscalar3 &lhs, const Trivector &rhs)
{
    Quadvector result;
    result.e23oi = lhs.p*rhs.e1oi;
    result.e31oi = lhs.p*rhs.e2oi;
    result.e12oi = lhs.p*rhs.e3oi;
    return result;
}

double inner(const Pseudoscalar3 &lhs, const Trivector &rhs)
{
    double result;
    result = -lhs.p*rhs.e123;
    return result;
}

Multivector operator*(const Pseudoscalar3 &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.t.e123 = lhs.p*rhs.s;
    result.t.e23o = lhs.p*rhs.b.e1o;
    result.t.e31o = lhs.p*rhs.b.e2o;
    result.t.e12o = lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.p = lhs.p*rhs.b.eoi;
    return result;
}

Multivector outer(const Pseudoscalar3 &lhs, const Rotor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.p*rhs.s;
    result.p = lhs.p*rhs.b.eoi;
    return result;
}

Multivector inner(const Pseudoscalar3 &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.t.e123 = lhs.p*rhs.s;
    return result;
}

Multivector operator*(const Pseudoscalar3 &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.t.e123 = lhs.p*rhs.s;
    result.t.e23o = lhs.p*rhs.b.e1o;
    result.t.e31o = lhs.p*rhs.b.e2o;
    result.t.e12o = lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.q.e23oi;
    result.t.e2oi = -lhs.p*rhs.q.e31oi;
    result.t.e3oi = -lhs.p*rhs.q.e12oi;
    result.p = lhs.p*rhs.b.eoi;
    return result;
}

Multivector outer(const Pseudoscalar3 &lhs, const Versor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.p*rhs.s;
    result.t.e1oi = -lhs.p*rhs.q.e23oi;
    result.t.e2oi = -lhs.p*rhs.q.e31oi;
    result.t.e3oi = -lhs.p*rhs.q.e12oi;
    result.p = lhs.p*rhs.b.eoi;
    return result;
}

Multivector inner(const Pseudoscalar3 &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.t.e123 = lhs.p*rhs.s;
    return result;
}

Multivector operator*(const Pseudoscalar3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.p*rhs.t.e123;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.p*rhs.v.e1;
    result.b.e31 = lhs.p*rhs.v.e2;
    result.b.e12 = lhs.p*rhs.v.e3;
    result.b.e1o = -lhs.p*rhs.t.e23o;
    result.b.e2o = -lhs.p*rhs.t.e31o;
    result.b.e3o = -lhs.p*rhs.t.e12o;
    result.b.e1i = -lhs.p*rhs.t.e23i;
    result.b.e2i = -lhs.p*rhs.t.e31i;
    result.b.e3i = -lhs.p*rhs.t.e12i;
    result.b.eoi = -lhs.p*rhs.p;
    result.t.e123 = lhs.p*rhs.s;
    result.t.e23o = lhs.p*rhs.b.e1o;
    result.t.e31o = lhs.p*rhs.b.e2o;
    result.t.e12o = lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.p*rhs.b.e3i;
    result.t.e1oi = -lhs.p*rhs.q.e23oi;
    result.t.e2oi = -lhs.p*rhs.q.e31oi;
    result.t.e3oi = -lhs.p*rhs.q.e12oi;
    result.q.e123o = lhs.p*rhs.v.eo;
    result.q.e123i = lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.p*rhs.t.e1oi;
    result.q.e31oi = lhs.p*rhs.t.e2oi;
    result.q.e12oi = lhs.p*rhs.t.e3oi;
    result.p = lhs.p*rhs.b.eoi;
    return result;
}

Multivector outer(const Pseudoscalar3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.b.eoi = -lhs.p*rhs.p;
    result.t.e123 = lhs.p*rhs.s;
    result.t.e1oi = -lhs.p*rhs.q.e23oi;
    result.t.e2oi = -lhs.p*rhs.q.e31oi;
    result.t.e3oi = -lhs.p*rhs.q.e12oi;
    result.q.e123o = lhs.p*rhs.v.eo;
    result.q.e123i = lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.p*rhs.t.e1oi;
    result.q.e31oi = lhs.p*rhs.t.e2oi;
    result.q.e12oi = lhs.p*rhs.t.e3oi;
    result.p = lhs.p*rhs.b.eoi;
    return result;
}

Multivector inner(const Pseudoscalar3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.p*rhs.t.e123;
    result.v.e1 = -lhs.p*rhs.b.e23;
    result.v.e2 = -lhs.p*rhs.b.e31;
    result.v.e3 = -lhs.p*rhs.b.e12;
    result.v.eo = 0.5*lhs.p*rhs.q.e123i;
    result.v.ei = -lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.p*rhs.v.e1;
    result.b.e31 = lhs.p*rhs.v.e2;
    result.b.e12 = lhs.p*rhs.v.e3;
    result.b.eoi = -lhs.p*rhs.p;
    result.t.e123 = lhs.p*rhs.s;
    return result;
}

Rotor3 operator*(const Vector3 &lhs, const Vector3 &rhs)
{
    Rotor3 result;
    result.s = lhs.e1*rhs.e1+lhs.e2*rhs.e2+lhs.e3*rhs.e3;
    result.b.e23 = lhs.e2*rhs.e3-lhs.e3*rhs.e2;
    result.b.e31 = -lhs.e1*rhs.e3+lhs.e3*rhs.e1;
    result.b.e12 = lhs.e1*rhs.e2-lhs.e2*rhs.e1;
    return result;
}

Bivector3 outer(const Vector3 &lhs, const Vector3 &rhs)
{
    Bivector3 result;
    result.e23 = lhs.e2*rhs.e3-lhs.e3*rhs.e2;
    result.e31 = -lhs.e1*rhs.e3+lhs.e3*rhs.e1;
    result.e12 = lhs.e1*rhs.e2-lhs.e2*rhs.e1;
    return result;
}

double inner(const Vector3 &lhs, const Vector3 &rhs)
{
    double result;
    result = lhs.e1*rhs.e1+lhs.e2*rhs.e2+lhs.e3*rhs.e3;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Bivector3 &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e2*rhs.e12+lhs.e3*rhs.e31;
    result.v.e2 = lhs.e1*rhs.e12-lhs.e3*rhs.e23;
    result.v.e3 = -lhs.e1*rhs.e31+lhs.e2*rhs.e23;
    result.t.e123 = lhs.e1*rhs.e23+lhs.e2*rhs.e31+lhs.e3*rhs.e12;
    return result;
}

Pseudoscalar3 outer(const Vector3 &lhs, const Bivector3 &rhs)
{
    Pseudoscalar3 result;
    result.p = lhs.e1*rhs.e23+lhs.e2*rhs.e31+lhs.e3*rhs.e12;
    return result;
}

Vector3 inner(const Vector3 &lhs, const Bivector3 &rhs)
{
    Vector3 result;
    result.e1 = -lhs.e2*rhs.e12+lhs.e3*rhs.e31;
    result.e2 = lhs.e1*rhs.e12-lhs.e3*rhs.e23;
    result.e3 = -lhs.e1*rhs.e31+lhs.e2*rhs.e23;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    return result;
}

Multivector outer(const Vector3 &lhs, const Rotor3 &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    return result;
}

Vector3 inner(const Vector3 &lhs, const Rotor3 &rhs)
{
    Vector3 result;
    result.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    return result;
}

Rotor operator*(const Vector3 &lhs, const Vector &rhs)
{
    Rotor result;
    result.s = lhs.e1*rhs.e1+lhs.e2*rhs.e2+lhs.e3*rhs.e3;
    result.b.e23 = lhs.e2*rhs.e3-lhs.e3*rhs.e2;
    result.b.e31 = -lhs.e1*rhs.e3+lhs.e3*rhs.e1;
    result.b.e12 = lhs.e1*rhs.e2-lhs.e2*rhs.e1;
    result.b.e1o = lhs.e1*rhs.eo;
    result.b.e2o = lhs.e2*rhs.eo;
    result.b.e3o = lhs.e3*rhs.eo;
    result.b.e1i = lhs.e1*rhs.ei;
    result.b.e2i = lhs.e2*rhs.ei;
    result.b.e3i = lhs.e3*rhs.ei;
    return result;
}

Bivector outer(const Vector3 &lhs, const Vector &rhs)
{
    Bivector result;
    result.e23 = lhs.e2*rhs.e3-lhs.e3*rhs.e2;
    result.e31 = -lhs.e1*rhs.e3+lhs.e3*rhs.e1;
    result.e12 = lhs.e1*rhs.e2-lhs.e2*rhs.e1;
    result.e1o = lhs.e1*rhs.eo;
    result.e2o = lhs.e2*rhs.eo;
    result.e3o = lhs.e3*rhs.eo;
    result.e1i = lhs.e1*rhs.ei;
    result.e2i = lhs.e2*rhs.ei;
    result.e3i = lhs.e3*rhs.ei;
    return result;
}

double inner(const Vector3 &lhs, const Vector &rhs)
{
    double result;
    result = lhs.e1*rhs.e1+lhs.e2*rhs.e2+lhs.e3*rhs.e3;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Quadvector &rhs)
{
    Multivector result;
    result.t.e23o = lhs.e1*rhs.e123o;
    result.t.e31o = lhs.e2*rhs.e123o;
    result.t.e12o = lhs.e3*rhs.e123o;
    result.t.e23i = lhs.e1*rhs.e123i;
    result.t.e31i = lhs.e2*rhs.e123i;
    result.t.e12i = lhs.e3*rhs.e123i;
    result.t.e1oi = -lhs.e2*rhs.e12oi+lhs.e3*rhs.e31oi;
    result.t.e2oi = lhs.e1*rhs.e12oi-lhs.e3*rhs.e23oi;
    result.t.e3oi = -lhs.e1*rhs.e31oi+lhs.e2*rhs.e23oi;
    result.p = lhs.e1*rhs.e23oi+lhs.e2*rhs.e31oi+lhs.e3*rhs.e12oi;
    return result;
}

Pseudoscalar outer(const Vector3 &lhs, const Quadvector &rhs)
{
    Pseudoscalar result;
    result.p = lhs.e1*rhs.e23oi+lhs.e2*rhs.e31oi+lhs.e3*rhs.e12oi;
    return result;
}

Trivector inner(const Vector3 &lhs, const Quadvector &rhs)
{
    Trivector result;
    result.e23o = lhs.e1*rhs.e123o;
    result.e31o = lhs.e2*rhs.e123o;
    result.e12o = lhs.e3*rhs.e123o;
    result.e23i = lhs.e1*rhs.e123i;
    result.e31i = lhs.e2*rhs.e123i;
    result.e12i = lhs.e3*rhs.e123i;
    result.e1oi = -lhs.e2*rhs.e12oi+lhs.e3*rhs.e31oi;
    result.e2oi = lhs.e1*rhs.e12oi-lhs.e3*rhs.e23oi;
    result.e3oi = -lhs.e1*rhs.e31oi+lhs.e2*rhs.e23oi;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Bivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e2*rhs.e12+lhs.e3*rhs.e31;
    result.v.e2 = lhs.e1*rhs.e12-lhs.e3*rhs.e23;
    result.v.e3 = -lhs.e1*rhs.e31+lhs.e2*rhs.e23;
    result.v.eo = -0.5*lhs.e1*rhs.e1i-0.5*lhs.e2*rhs.e2i-0.5*lhs.e3*rhs.e3i;
    result.v.ei = lhs.e1*rhs.e1i+lhs.e2*rhs.e2i+lhs.e3*rhs.e3i;
    result.t.e123 = lhs.e1*rhs.e23+lhs.e2*rhs.e31+lhs.e3*rhs.e12;
    result.t.e23o = lhs.e2*rhs.e3o-lhs.e3*rhs.e2o;
    result.t.e31o = -lhs.e1*rhs.e3o+lhs.e3*rhs.e1o;
    result.t.e12o = lhs.e1*rhs.e2o-lhs.e2*rhs.e1o;
    result.t.e23i = lhs.e2*rhs.e3i-lhs.e3*rhs.e2i;
    result.t.e31i = -lhs.e1*rhs.e3i+lhs.e3*rhs.e1i;
    result.t.e12i = lhs.e1*rhs.e2i-lhs.e2*rhs.e1i;
    result.t.e1oi = lhs.e1*rhs.eoi;
    result.t.e2oi = lhs.e2*rhs.eoi;
    result.t.e3oi = lhs.e3*rhs.eoi;
    return result;
}

Trivector outer(const Vector3 &lhs, const Bivector &rhs)
{
    Trivector result;
    result.e123 = lhs.e1*rhs.e23+lhs.e2*rhs.e31+lhs.e3*rhs.e12;
    result.e23o = lhs.e2*rhs.e3o-lhs.e3*rhs.e2o;
    result.e31o = -lhs.e1*rhs.e3o+lhs.e3*rhs.e1o;
    result.e12o = lhs.e1*rhs.e2o-lhs.e2*rhs.e1o;
    result.e23i = lhs.e2*rhs.e3i-lhs.e3*rhs.e2i;
    result.e31i = -lhs.e1*rhs.e3i+lhs.e3*rhs.e1i;
    result.e12i = lhs.e1*rhs.e2i-lhs.e2*rhs.e1i;
    result.e1oi = lhs.e1*rhs.eoi;
    result.e2oi = lhs.e2*rhs.eoi;
    result.e3oi = lhs.e3*rhs.eoi;
    return result;
}

Vector inner(const Vector3 &lhs, const Bivector &rhs)
{
    Vector result;
    result.e1 = -lhs.e2*rhs.e12+lhs.e3*rhs.e31;
    result.e2 = lhs.e1*rhs.e12-lhs.e3*rhs.e23;
    result.e3 = -lhs.e1*rhs.e31+lhs.e2*rhs.e23;
    result.eo = -0.5*lhs.e1*rhs.e1i-0.5*lhs.e2*rhs.e2i-0.5*lhs.e3*rhs.e3i;
    result.ei = lhs.e1*rhs.e1i+lhs.e2*rhs.e2i+lhs.e3*rhs.e3i;
    return result;
}

Versor operator*(const Vector3 &lhs, const Trivector &rhs)
{
    Versor result;
    result.b.e23 = lhs.e1*rhs.e123;
    result.b.e31 = lhs.e2*rhs.e123;
    result.b.e12 = lhs.e3*rhs.e123;
    result.b.e1o = -lhs.e2*rhs.e12o+lhs.e3*rhs.e31o;
    result.b.e2o = lhs.e1*rhs.e12o-lhs.e3*rhs.e23o;
    result.b.e3o = -lhs.e1*rhs.e31o+lhs.e2*rhs.e23o;
    result.b.e1i = -lhs.e2*rhs.e12i+lhs.e3*rhs.e31i;
    result.b.e2i = lhs.e1*rhs.e12i-lhs.e3*rhs.e23i;
    result.b.e3i = -lhs.e1*rhs.e31i+lhs.e2*rhs.e23i;
    result.b.eoi = lhs.e1*rhs.e1oi+lhs.e2*rhs.e2oi+lhs.e3*rhs.e3oi;
    result.q.e123o = lhs.e1*rhs.e23o+lhs.e2*rhs.e31o+lhs.e3*rhs.e12o;
    result.q.e123i = lhs.e1*rhs.e23i+lhs.e2*rhs.e31i+lhs.e3*rhs.e12i;
    result.q.e23oi = lhs.e2*rhs.e3oi-lhs.e3*rhs.e2oi;
    result.q.e31oi = -lhs.e1*rhs.e3oi+lhs.e3*rhs.e1oi;
    result.q.e12oi = lhs.e1*rhs.e2oi-lhs.e2*rhs.e1oi;
    return result;
}

Quadvector outer(const Vector3 &lhs, const Trivector &rhs)
{
    Quadvector result;
    result.e123o = lhs.e1*rhs.e23o+lhs.e2*rhs.e31o+lhs.e3*rhs.e12o;
    result.e123i = lhs.e1*rhs.e23i+lhs.e2*rhs.e31i+lhs.e3*rhs.e12i;
    result.e23oi = lhs.e2*rhs.e3oi-lhs.e3*rhs.e2oi;
    result.e31oi = -lhs.e1*rhs.e3oi+lhs.e3*rhs.e1oi;
    result.e12oi = lhs.e1*rhs.e2oi-lhs.e2*rhs.e1oi;
    return result;
}

Bivector inner(const Vector3 &lhs, const Trivector &rhs)
{
    Bivector result;
    result.e23 = lhs.e1*rhs.e123;
    result.e31 = lhs.e2*rhs.e123;
    result.e12 = lhs.e3*rhs.e123;
    result.e1o = -lhs.e2*rhs.e12o+lhs.e3*rhs.e31o;
    result.e2o = lhs.e1*rhs.e12o-lhs.e3*rhs.e23o;
    result.e3o = -lhs.e1*rhs.e31o+lhs.e2*rhs.e23o;
    result.e1i = -lhs.e2*rhs.e12i+lhs.e3*rhs.e31i;
    result.e2i = lhs.e1*rhs.e12i-lhs.e3*rhs.e23i;
    result.e3i = -lhs.e1*rhs.e31i+lhs.e2*rhs.e23i;
    result.eoi = lhs.e1*rhs.e1oi+lhs.e2*rhs.e2oi+lhs.e3*rhs.e3oi;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i;
    result.t.e1oi = lhs.e1*rhs.b.eoi;
    result.t.e2oi = lhs.e2*rhs.b.eoi;
    result.t.e3oi = lhs.e3*rhs.b.eoi;
    return result;
}

Multivector outer(const Vector3 &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i;
    result.t.e1oi = lhs.e1*rhs.b.eoi;
    result.t.e2oi = lhs.e2*rhs.b.eoi;
    result.t.e3oi = lhs.e3*rhs.b.eoi;
    return result;
}

Vector inner(const Vector3 &lhs, const Rotor &rhs)
{
    Vector result;
    result.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i;
    result.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e1*rhs.q.e123o+lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e2*rhs.q.e123o+lhs.e3*rhs.b.e1o;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.e3*rhs.q.e123o;
    result.t.e23i = lhs.e1*rhs.q.e123i+lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e2*rhs.q.e123i+lhs.e3*rhs.b.e1i;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.e3*rhs.q.e123i;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi;
    result.t.e2oi = lhs.e1*rhs.q.e12oi+lhs.e2*rhs.b.eoi-lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi+lhs.e3*rhs.b.eoi;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi;
    return result;
}

Multivector outer(const Vector3 &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i;
    result.t.e1oi = lhs.e1*rhs.b.eoi;
    result.t.e2oi = lhs.e2*rhs.b.eoi;
    result.t.e3oi = lhs.e3*rhs.b.eoi;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi;
    return result;
}

Multivector inner(const Vector3 &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i;
    result.t.e23o = lhs.e1*rhs.q.e123o;
    result.t.e31o = lhs.e2*rhs.q.e123o;
    result.t.e12o = lhs.e3*rhs.q.e123o;
    result.t.e23i = lhs.e1*rhs.q.e123i;
    result.t.e31i = lhs.e2*rhs.q.e123i;
    result.t.e12i = lhs.e3*rhs.q.e123i;
    result.t.e1oi = -lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi;
    result.t.e2oi = lhs.e1*rhs.q.e12oi-lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi;
    return result;
}

Multivector operator*(const Vector3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.e1*rhs.v.e1+lhs.e2*rhs.v.e2+lhs.e3*rhs.v.e3;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i;
    result.b.e23 = lhs.e1*rhs.t.e123+lhs.e2*rhs.v.e3-lhs.e3*rhs.v.e2;
    result.b.e31 = -lhs.e1*rhs.v.e3+lhs.e2*rhs.t.e123+lhs.e3*rhs.v.e1;
    result.b.e12 = lhs.e1*rhs.v.e2-lhs.e2*rhs.v.e1+lhs.e3*rhs.t.e123;
    result.b.e1o = lhs.e1*rhs.v.eo-lhs.e2*rhs.t.e12o+lhs.e3*rhs.t.e31o;
    result.b.e2o = lhs.e1*rhs.t.e12o+lhs.e2*rhs.v.eo-lhs.e3*rhs.t.e23o;
    result.b.e3o = -lhs.e1*rhs.t.e31o+lhs.e2*rhs.t.e23o+lhs.e3*rhs.v.eo;
    result.b.e1i = lhs.e1*rhs.v.ei-lhs.e2*rhs.t.e12i+lhs.e3*rhs.t.e31i;
    result.b.e2i = lhs.e1*rhs.t.e12i+lhs.e2*rhs.v.ei-lhs.e3*rhs.t.e23i;
    result.b.e3i = -lhs.e1*rhs.t.e31i+lhs.e2*rhs.t.e23i+lhs.e3*rhs.v.ei;
    result.b.eoi = lhs.e1*rhs.t.e1oi+lhs.e2*rhs.t.e2oi+lhs.e3*rhs.t.e3oi;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e1*rhs.q.e123o+lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e2*rhs.q.e123o+lhs.e3*rhs.b.e1o;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.e3*rhs.q.e123o;
    result.t.e23i = lhs.e1*rhs.q.e123i+lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e2*rhs.q.e123i+lhs.e3*rhs.b.e1i;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.e3*rhs.q.e123i;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi;
    result.t.e2oi = lhs.e1*rhs.q.e12oi+lhs.e2*rhs.b.eoi-lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi+lhs.e3*rhs.b.eoi;
    result.q.e123o = lhs.e1*rhs.t.e23o+lhs.e2*rhs.t.e31o+lhs.e3*rhs.t.e12o;
    result.q.e123i = lhs.e1*rhs.t.e23i+lhs.e2*rhs.t.e31i+lhs.e3*rhs.t.e12i;
    result.q.e23oi = lhs.e1*rhs.p+lhs.e2*rhs.t.e3oi-lhs.e3*rhs.t.e2oi;
    result.q.e31oi = -lhs.e1*rhs.t.e3oi+lhs.e2*rhs.p+lhs.e3*rhs.t.e1oi;
    result.q.e12oi = lhs.e1*rhs.t.e2oi-lhs.e2*rhs.t.e1oi+lhs.e3*rhs.p;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi;
    return result;
}

Multivector outer(const Vector3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.b.e23 = lhs.e2*rhs.v.e3-lhs.e3*rhs.v.e2;
    result.b.e31 = -lhs.e1*rhs.v.e3+lhs.e3*rhs.v.e1;
    result.b.e12 = lhs.e1*rhs.v.e2-lhs.e2*rhs.v.e1;
    result.b.e1o = lhs.e1*rhs.v.eo;
    result.b.e2o = lhs.e2*rhs.v.eo;
    result.b.e3o = lhs.e3*rhs.v.eo;
    result.b.e1i = lhs.e1*rhs.v.ei;
    result.b.e2i = lhs.e2*rhs.v.ei;
    result.b.e3i = lhs.e3*rhs.v.ei;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i;
    result.t.e1oi = lhs.e1*rhs.b.eoi;
    result.t.e2oi = lhs.e2*rhs.b.eoi;
    result.t.e3oi = lhs.e3*rhs.b.eoi;
    result.q.e123o = lhs.e1*rhs.t.e23o+lhs.e2*rhs.t.e31o+lhs.e3*rhs.t.e12o;
    result.q.e123i = lhs.e1*rhs.t.e23i+lhs.e2*rhs.t.e31i+lhs.e3*rhs.t.e12i;
    result.q.e23oi = lhs.e1*rhs.p+lhs.e2*rhs.t.e3oi-lhs.e3*rhs.t.e2oi;
    result.q.e31oi = -lhs.e1*rhs.t.e3oi+lhs.e2*rhs.p+lhs.e3*rhs.t.e1oi;
    result.q.e12oi = lhs.e1*rhs.t.e2oi-lhs.e2*rhs.t.e1oi+lhs.e3*rhs.p;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi;
    return result;
}

Multivector inner(const Vector3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.e1*rhs.v.e1+lhs.e2*rhs.v.e2+lhs.e3*rhs.v.e3;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i;
    result.b.e23 = lhs.e1*rhs.t.e123;
    result.b.e31 = lhs.e2*rhs.t.e123;
    result.b.e12 = lhs.e3*rhs.t.e123;
    result.b.e1o = -lhs.e2*rhs.t.e12o+lhs.e3*rhs.t.e31o;
    result.b.e2o = lhs.e1*rhs.t.e12o-lhs.e3*rhs.t.e23o;
    result.b.e3o = -lhs.e1*rhs.t.e31o+lhs.e2*rhs.t.e23o;
    result.b.e1i = -lhs.e2*rhs.t.e12i+lhs.e3*rhs.t.e31i;
    result.b.e2i = lhs.e1*rhs.t.e12i-lhs.e3*rhs.t.e23i;
    result.b.e3i = -lhs.e1*rhs.t.e31i+lhs.e2*rhs.t.e23i;
    result.b.eoi = lhs.e1*rhs.t.e1oi+lhs.e2*rhs.t.e2oi+lhs.e3*rhs.t.e3oi;
    result.t.e23o = lhs.e1*rhs.q.e123o;
    result.t.e31o = lhs.e2*rhs.q.e123o;
    result.t.e12o = lhs.e3*rhs.q.e123o;
    result.t.e23i = lhs.e1*rhs.q.e123i;
    result.t.e31i = lhs.e2*rhs.q.e123i;
    result.t.e12i = lhs.e3*rhs.q.e123i;
    result.t.e1oi = -lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi;
    result.t.e2oi = lhs.e1*rhs.q.e12oi-lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi;
    result.q.e23oi = lhs.e1*rhs.p;
    result.q.e31oi = lhs.e2*rhs.p;
    result.q.e12oi = lhs.e3*rhs.p;
    return result;
}

Rotor3 operator*(const Bivector3 &lhs, const Bivector3 &rhs)
{
    Rotor3 result;
    result.s = -lhs.e12*rhs.e12-lhs.e31*rhs.e31-lhs.e23*rhs.e23;
    result.b.e23 = lhs.e12*rhs.e31-lhs.e31*rhs.e12;
    result.b.e31 = -lhs.e12*rhs.e23+lhs.e23*rhs.e12;
    result.b.e12 = lhs.e31*rhs.e23-lhs.e23*rhs.e31;
    return result;
}

double inner(const Bivector3 &lhs, const Bivector3 &rhs)
{
    double result;
    result = -lhs.e12*rhs.e12-lhs.e31*rhs.e31-lhs.e23*rhs.e23;
    return result;
}

Rotor3 operator*(const Bivector3 &lhs, const Rotor3 &rhs)
{
    Rotor3 result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e23*rhs.s;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s+lhs.e23*rhs.b.e12;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23-lhs.e23*rhs.b.e31;
    return result;
}

Bivector3 outer(const Bivector3 &lhs, const Rotor3 &rhs)
{
    Bivector3 result;
    result.e23 = lhs.e23*rhs.s;
    result.e31 = lhs.e31*rhs.s;
    result.e12 = lhs.e12*rhs.s;
    return result;
}

Rotor3 inner(const Bivector3 &lhs, const Rotor3 &rhs)
{
    Rotor3 result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    return result;
}

Multivector operator*(const Bivector3 &lhs, const Vector &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e12*rhs.e2-lhs.e31*rhs.e3;
    result.v.e2 = -lhs.e12*rhs.e1+lhs.e23*rhs.e3;
    result.v.e3 = lhs.e31*rhs.e1-lhs.e23*rhs.e2;
    result.t.e123 = lhs.e12*rhs.e3+lhs.e31*rhs.e2+lhs.e23*rhs.e1;
    result.t.e23o = lhs.e23*rhs.eo;
    result.t.e31o = lhs.e31*rhs.eo;
    result.t.e12o = lhs.e12*rhs.eo;
    result.t.e23i = lhs.e23*rhs.ei;
    result.t.e31i = lhs.e31*rhs.ei;
    result.t.e12i = lhs.e12*rhs.ei;
    return result;
}

Trivector outer(const Bivector3 &lhs, const Vector &rhs)
{
    Trivector result;
    result.e123 = lhs.e12*rhs.e3+lhs.e31*rhs.e2+lhs.e23*rhs.e1;
    result.e23o = lhs.e23*rhs.eo;
    result.e31o = lhs.e31*rhs.eo;
    result.e12o = lhs.e12*rhs.eo;
    result.e23i = lhs.e23*rhs.ei;
    result.e31i = lhs.e31*rhs.ei;
    result.e12i = lhs.e12*rhs.ei;
    return result;
}

Vector3 inner(const Bivector3 &lhs, const Vector &rhs)
{
    Vector3 result;
    result.e1 = lhs.e12*rhs.e2-lhs.e31*rhs.e3;
    result.e2 = -lhs.e12*rhs.e1+lhs.e23*rhs.e3;
    result.e3 = lhs.e31*rhs.e1-lhs.e23*rhs.e2;
    return result;
}

Versor operator*(const Bivector3 &lhs, const Quadvector &rhs)
{
    Versor result;
    result.b.e1o = -lhs.e23*rhs.e123o;
    result.b.e2o = -lhs.e31*rhs.e123o;
    result.b.e3o = -lhs.e12*rhs.e123o;
    result.b.e1i = -lhs.e23*rhs.e123i;
    result.b.e2i = -lhs.e31*rhs.e123i;
    result.b.e3i = -lhs.e12*rhs.e123i;
    result.b.eoi = -lhs.e12*rhs.e12oi-lhs.e31*rhs.e31oi-lhs.e23*rhs.e23oi;
    result.q.e23oi = lhs.e12*rhs.e31oi-lhs.e31*rhs.e12oi;
    result.q.e31oi = -lhs.e12*rhs.e23oi+lhs.e23*rhs.e12oi;
    result.q.e12oi = lhs.e31*rhs.e23oi-lhs.e23*rhs.e31oi;
    return result;
}

Quadvector outer(const Bivector3 &lhs, const Quadvector &rhs)
{
    Quadvector result;
    result.e23oi = lhs.e12*rhs.e31oi-lhs.e31*rhs.e12oi;
    result.e31oi = -lhs.e12*rhs.e23oi+lhs.e23*rhs.e12oi;
    result.e12oi = lhs.e31*rhs.e23oi-lhs.e23*rhs.e31oi;
    return result;
}

Bivector inner(const Bivector3 &lhs, const Quadvector &rhs)
{
    Bivector result;
    result.e1o = -lhs.e23*rhs.e123o;
    result.e2o = -lhs.e31*rhs.e123o;
    result.e3o = -lhs.e12*rhs.e123o;
    result.e1i = -lhs.e23*rhs.e123i;
    result.e2i = -lhs.e31*rhs.e123i;
    result.e3i = -lhs.e12*rhs.e123i;
    result.eoi = -lhs.e12*rhs.e12oi-lhs.e31*rhs.e31oi-lhs.e23*rhs.e23oi;
    return result;
}

Versor operator*(const Bivector3 &lhs, const Bivector &rhs)
{
    Versor result;
    result.s = -lhs.e12*rhs.e12-lhs.e31*rhs.e31-lhs.e23*rhs.e23;
    result.b.e23 = lhs.e12*rhs.e31-lhs.e31*rhs.e12;
    result.b.e31 = -lhs.e12*rhs.e23+lhs.e23*rhs.e12;
    result.b.e12 = lhs.e31*rhs.e23-lhs.e23*rhs.e31;
    result.b.e1o = lhs.e12*rhs.e2o-lhs.e31*rhs.e3o;
    result.b.e2o = -lhs.e12*rhs.e1o+lhs.e23*rhs.e3o;
    result.b.e3o = lhs.e31*rhs.e1o-lhs.e23*rhs.e2o;
    result.b.e1i = lhs.e12*rhs.e2i-lhs.e31*rhs.e3i;
    result.b.e2i = -lhs.e12*rhs.e1i+lhs.e23*rhs.e3i;
    result.b.e3i = lhs.e31*rhs.e1i-lhs.e23*rhs.e2i;
    result.q.e123o = lhs.e12*rhs.e3o+lhs.e31*rhs.e2o+lhs.e23*rhs.e1o;
    result.q.e123i = lhs.e12*rhs.e3i+lhs.e31*rhs.e2i+lhs.e23*rhs.e1i;
    result.q.e23oi = lhs.e23*rhs.eoi;
    result.q.e31oi = lhs.e31*rhs.eoi;
    result.q.e12oi = lhs.e12*rhs.eoi;
    return result;
}

Quadvector outer(const Bivector3 &lhs, const Bivector &rhs)
{
    Quadvector result;
    result.e123o = lhs.e12*rhs.e3o+lhs.e31*rhs.e2o+lhs.e23*rhs.e1o;
    result.e123i = lhs.e12*rhs.e3i+lhs.e31*rhs.e2i+lhs.e23*rhs.e1i;
    result.e23oi = lhs.e23*rhs.eoi;
    result.e31oi = lhs.e31*rhs.eoi;
    result.e12oi = lhs.e12*rhs.eoi;
    return result;
}

double inner(const Bivector3 &lhs, const Bivector &rhs)
{
    double result;
    result = -lhs.e12*rhs.e12-lhs.e31*rhs.e31-lhs.e23*rhs.e23;
    return result;
}

Multivector operator*(const Bivector3 &lhs, const Trivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e23*rhs.e123;
    result.v.e2 = -lhs.e31*rhs.e123;
    result.v.e3 = -lhs.e12*rhs.e123;
    result.v.eo = 0.5*lhs.e12*rhs.e12i+0.5*lhs.e31*rhs.e31i+0.5*lhs.e23*rhs.e23i;
    result.v.ei = -lhs.e12*rhs.e12i-lhs.e31*rhs.e31i-lhs.e23*rhs.e23i;
    result.t.e23o = lhs.e12*rhs.e31o-lhs.e31*rhs.e12o;
    result.t.e31o = -lhs.e12*rhs.e23o+lhs.e23*rhs.e12o;
    result.t.e12o = lhs.e31*rhs.e23o-lhs.e23*rhs.e31o;
    result.t.e23i = lhs.e12*rhs.e31i-lhs.e31*rhs.e12i;
    result.t.e31i = -lhs.e12*rhs.e23i+lhs.e23*rhs.e12i;
    result.t.e12i = lhs.e31*rhs.e23i-lhs.e23*rhs.e31i;
    result.t.e1oi = lhs.e12*rhs.e2oi-lhs.e31*rhs.e3oi;
    result.t.e2oi = -lhs.e12*rhs.e1oi+lhs.e23*rhs.e3oi;
    result.t.e3oi = lhs.e31*rhs.e1oi-lhs.e23*rhs.e2oi;
    result.p = lhs.e12*rhs.e3oi+lhs.e31*rhs.e2oi+lhs.e23*rhs.e1oi;
    return result;
}

Pseudoscalar outer(const Bivector3 &lhs, const Trivector &rhs)
{
    Pseudoscalar result;
    result.p = lhs.e12*rhs.e3oi+lhs.e31*rhs.e2oi+lhs.e23*rhs.e1oi;
    return result;
}

Vector inner(const Bivector3 &lhs, const Trivector &rhs)
{
    Vector result;
    result.e1 = -lhs.e23*rhs.e123;
    result.e2 = -lhs.e31*rhs.e123;
    result.e3 = -lhs.e12*rhs.e123;
    result.eo = 0.5*lhs.e12*rhs.e12i+0.5*lhs.e31*rhs.e31i+0.5*lhs.e23*rhs.e23i;
    result.ei = -lhs.e12*rhs.e12i-lhs.e31*rhs.e31i-lhs.e23*rhs.e23i;
    return result;
}

Versor operator*(const Bivector3 &lhs, const Rotor &rhs)
{
    Versor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e23*rhs.s;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s+lhs.e23*rhs.b.e12;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23-lhs.e23*rhs.b.e31;
    result.b.e1o = lhs.e12*rhs.b.e2o-lhs.e31*rhs.b.e3o;
    result.b.e2o = -lhs.e12*rhs.b.e1o+lhs.e23*rhs.b.e3o;
    result.b.e3o = lhs.e31*rhs.b.e1o-lhs.e23*rhs.b.e2o;
    result.b.e1i = lhs.e12*rhs.b.e2i-lhs.e31*rhs.b.e3i;
    result.b.e2i = -lhs.e12*rhs.b.e1i+lhs.e23*rhs.b.e3i;
    result.b.e3i = lhs.e31*rhs.b.e1i-lhs.e23*rhs.b.e2i;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e23*rhs.b.e1o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e23*rhs.b.e1i;
    result.q.e23oi = lhs.e23*rhs.b.eoi;
    result.q.e31oi = lhs.e31*rhs.b.eoi;
    result.q.e12oi = lhs.e12*rhs.b.eoi;
    return result;
}

Versor outer(const Bivector3 &lhs, const Rotor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e23*rhs.b.e1o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e23*rhs.b.e1i;
    result.q.e23oi = lhs.e23*rhs.b.eoi;
    result.q.e31oi = lhs.e31*rhs.b.eoi;
    result.q.e12oi = lhs.e12*rhs.b.eoi;
    return result;
}

Rotor3 inner(const Bivector3 &lhs, const Rotor &rhs)
{
    Rotor3 result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    return result;
}

Versor operator*(const Bivector3 &lhs, const Versor &rhs)
{
    Versor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e23*rhs.s;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s+lhs.e23*rhs.b.e12;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23-lhs.e23*rhs.b.e31;
    result.b.e1o = lhs.e12*rhs.b.e2o-lhs.e31*rhs.b.e3o-lhs.e23*rhs.q.e123o;
    result.b.e2o = -lhs.e12*rhs.b.e1o-lhs.e31*rhs.q.e123o+lhs.e23*rhs.b.e3o;
    result.b.e3o = -lhs.e12*rhs.q.e123o+lhs.e31*rhs.b.e1o-lhs.e23*rhs.b.e2o;
    result.b.e1i = lhs.e12*rhs.b.e2i-lhs.e31*rhs.b.e3i-lhs.e23*rhs.q.e123i;
    result.b.e2i = -lhs.e12*rhs.b.e1i-lhs.e31*rhs.q.e123i+lhs.e23*rhs.b.e3i;
    result.b.e3i = -lhs.e12*rhs.q.e123i+lhs.e31*rhs.b.e1i-lhs.e23*rhs.b.e2i;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e23*rhs.q.e23oi;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e23*rhs.b.e1o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e23*rhs.b.e1i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi+lhs.e23*rhs.b.eoi;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e23*rhs.q.e31oi;
    return result;
}

Versor outer(const Bivector3 &lhs, const Versor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e23*rhs.b.e1o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e23*rhs.b.e1i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi+lhs.e23*rhs.b.eoi;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e23*rhs.q.e31oi;
    return result;
}

Rotor inner(const Bivector3 &lhs, const Versor &rhs)
{
    Rotor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.b.e1o = -lhs.e23*rhs.q.e123o;
    result.b.e2o = -lhs.e31*rhs.q.e123o;
    result.b.e3o = -lhs.e12*rhs.q.e123o;
    result.b.e1i = -lhs.e23*rhs.q.e123i;
    result.b.e2i = -lhs.e31*rhs.q.e123i;
    result.b.e3i = -lhs.e12*rhs.q.e123i;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e23*rhs.q.e23oi;
    return result;
}

Multivector operator*(const Bivector3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.v.e1 = lhs.e12*rhs.v.e2-lhs.e31*rhs.v.e3-lhs.e23*rhs.t.e123;
    result.v.e2 = -lhs.e12*rhs.v.e1-lhs.e31*rhs.t.e123+lhs.e23*rhs.v.e3;
    result.v.e3 = -lhs.e12*rhs.t.e123+lhs.e31*rhs.v.e1-lhs.e23*rhs.v.e2;
    result.v.eo = 0.5*lhs.e12*rhs.t.e12i+0.5*lhs.e31*rhs.t.e31i+0.5*lhs.e23*rhs.t.e23i;
    result.v.ei = -lhs.e12*rhs.t.e12i-lhs.e31*rhs.t.e31i-lhs.e23*rhs.t.e23i;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e23*rhs.s;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s+lhs.e23*rhs.b.e12;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23-lhs.e23*rhs.b.e31;
    result.b.e1o = lhs.e12*rhs.b.e2o-lhs.e31*rhs.b.e3o-lhs.e23*rhs.q.e123o;
    result.b.e2o = -lhs.e12*rhs.b.e1o-lhs.e31*rhs.q.e123o+lhs.e23*rhs.b.e3o;
    result.b.e3o = -lhs.e12*rhs.q.e123o+lhs.e31*rhs.b.e1o-lhs.e23*rhs.b.e2o;
    result.b.e1i = lhs.e12*rhs.b.e2i-lhs.e31*rhs.b.e3i-lhs.e23*rhs.q.e123i;
    result.b.e2i = -lhs.e12*rhs.b.e1i-lhs.e31*rhs.q.e123i+lhs.e23*rhs.b.e3i;
    result.b.e3i = -lhs.e12*rhs.q.e123i+lhs.e31*rhs.b.e1i-lhs.e23*rhs.b.e2i;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e23*rhs.q.e23oi;
    result.t.e123 = lhs.e12*rhs.v.e3+lhs.e31*rhs.v.e2+lhs.e23*rhs.v.e1;
    result.t.e23o = lhs.e12*rhs.t.e31o-lhs.e31*rhs.t.e12o+lhs.e23*rhs.v.eo;
    result.t.e31o = -lhs.e12*rhs.t.e23o+lhs.e31*rhs.v.eo+lhs.e23*rhs.t.e12o;
    result.t.e12o = lhs.e12*rhs.v.eo+lhs.e31*rhs.t.e23o-lhs.e23*rhs.t.e31o;
    result.t.e23i = lhs.e12*rhs.t.e31i-lhs.e31*rhs.t.e12i+lhs.e23*rhs.v.ei;
    result.t.e31i = -lhs.e12*rhs.t.e23i+lhs.e31*rhs.v.ei+lhs.e23*rhs.t.e12i;
    result.t.e12i = lhs.e12*rhs.v.ei+lhs.e31*rhs.t.e23i-lhs.e23*rhs.t.e31i;
    result.t.e1oi = lhs.e12*rhs.t.e2oi-lhs.e31*rhs.t.e3oi-lhs.e23*rhs.p;
    result.t.e2oi = -lhs.e12*rhs.t.e1oi-lhs.e31*rhs.p+lhs.e23*rhs.t.e3oi;
    result.t.e3oi = -lhs.e12*rhs.p+lhs.e31*rhs.t.e1oi-lhs.e23*rhs.t.e2oi;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e23*rhs.b.e1o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e23*rhs.b.e1i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi+lhs.e23*rhs.b.eoi;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e23*rhs.q.e31oi;
    result.p = lhs.e12*rhs.t.e3oi+lhs.e31*rhs.t.e2oi+lhs.e23*rhs.t.e1oi;
    return result;
}

Multivector outer(const Bivector3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.t.e123 = lhs.e12*rhs.v.e3+lhs.e31*rhs.v.e2+lhs.e23*rhs.v.e1;
    result.t.e23o = lhs.e23*rhs.v.eo;
    result.t.e31o = lhs.e31*rhs.v.eo;
    result.t.e12o = lhs.e12*rhs.v.eo;
    result.t.e23i = lhs.e23*rhs.v.ei;
    result.t.e31i = lhs.e31*rhs.v.ei;
    result.t.e12i = lhs.e12*rhs.v.ei;
    result.t.e1oi = -lhs.e23*rhs.p;
    result.t.e2oi = -lhs.e31*rhs.p;
    result.t.e3oi = -lhs.e12*rhs.p;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e23*rhs.b.e1o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e23*rhs.b.e1i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi+lhs.e23*rhs.b.eoi;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e23*rhs.q.e31oi;
    result.p = lhs.e12*rhs.t.e3oi+lhs.e31*rhs.t.e2oi+lhs.e23*rhs.t.e1oi;
    return result;
}

Multivector inner(const Bivector3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31-lhs.e23*rhs.b.e23;
    result.v.e1 = lhs.e12*rhs.v.e2-lhs.e31*rhs.v.e3-lhs.e23*rhs.t.e123;
    result.v.e2 = -lhs.e12*rhs.v.e1-lhs.e31*rhs.t.e123+lhs.e23*rhs.v.e3;
    result.v.e3 = -lhs.e12*rhs.t.e123+lhs.e31*rhs.v.e1-lhs.e23*rhs.v.e2;
    result.v.eo = 0.5*lhs.e12*rhs.t.e12i+0.5*lhs.e31*rhs.t.e31i+0.5*lhs.e23*rhs.t.e23i;
    result.v.ei = -lhs.e12*rhs.t.e12i-lhs.e31*rhs.t.e31i-lhs.e23*rhs.t.e23i;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.b.e1o = -lhs.e23*rhs.q.e123o;
    result.b.e2o = -lhs.e31*rhs.q.e123o;
    result.b.e3o = -lhs.e12*rhs.q.e123o;
    result.b.e1i = -lhs.e23*rhs.q.e123i;
    result.b.e2i = -lhs.e31*rhs.q.e123i;
    result.b.e3i = -lhs.e12*rhs.q.e123i;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e23*rhs.q.e23oi;
    result.t.e1oi = -lhs.e23*rhs.p;
    result.t.e2oi = -lhs.e31*rhs.p;
    result.t.e3oi = -lhs.e12*rhs.p;
    return result;
}

Rotor3 operator*(const Rotor3 &lhs, const Rotor3 &rhs)
{
    Rotor3 result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s+lhs.b.e23*rhs.b.e12;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23-lhs.b.e23*rhs.b.e31;
    return result;
}

Rotor3 outer(const Rotor3 &lhs, const Rotor3 &rhs)
{
    Rotor3 result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    return result;
}

Rotor3 inner(const Rotor3 &lhs, const Rotor3 &rhs)
{
    Rotor3 result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    return result;
}

Multivector operator*(const Rotor3 &lhs, const Vector &rhs)
{
    Multivector result;
    result.v.e1 = lhs.s*rhs.e1+lhs.b.e12*rhs.e2-lhs.b.e31*rhs.e3;
    result.v.e2 = lhs.s*rhs.e2-lhs.b.e12*rhs.e1+lhs.b.e23*rhs.e3;
    result.v.e3 = lhs.s*rhs.e3+lhs.b.e31*rhs.e1-lhs.b.e23*rhs.e2;
    result.v.eo = -0.5*lhs.s*rhs.ei;
    result.v.ei = lhs.s*rhs.ei;
    result.t.e123 = lhs.b.e12*rhs.e3+lhs.b.e31*rhs.e2+lhs.b.e23*rhs.e1;
    result.t.e23o = lhs.b.e23*rhs.eo;
    result.t.e31o = lhs.b.e31*rhs.eo;
    result.t.e12o = lhs.b.e12*rhs.eo;
    result.t.e23i = lhs.b.e23*rhs.ei;
    result.t.e31i = lhs.b.e31*rhs.ei;
    result.t.e12i = lhs.b.e12*rhs.ei;
    return result;
}

Multivector outer(const Rotor3 &lhs, const Vector &rhs)
{
    Multivector result;
    result.v.e1 = lhs.s*rhs.e1;
    result.v.e2 = lhs.s*rhs.e2;
    result.v.e3 = lhs.s*rhs.e3;
    result.v.eo = -0.5*lhs.s*rhs.ei;
    result.v.ei = lhs.s*rhs.ei;
    result.t.e123 = lhs.b.e12*rhs.e3+lhs.b.e31*rhs.e2+lhs.b.e23*rhs.e1;
    result.t.e23o = lhs.b.e23*rhs.eo;
    result.t.e31o = lhs.b.e31*rhs.eo;
    result.t.e12o = lhs.b.e12*rhs.eo;
    result.t.e23i = lhs.b.e23*rhs.ei;
    result.t.e31i = lhs.b.e31*rhs.ei;
    result.t.e12i = lhs.b.e12*rhs.ei;
    return result;
}

Vector inner(const Rotor3 &lhs, const Vector &rhs)
{
    Vector result;
    result.e1 = lhs.s*rhs.e1+lhs.b.e12*rhs.e2-lhs.b.e31*rhs.e3;
    result.e2 = lhs.s*rhs.e2-lhs.b.e12*rhs.e1+lhs.b.e23*rhs.e3;
    result.e3 = lhs.s*rhs.e3+lhs.b.e31*rhs.e1-lhs.b.e23*rhs.e2;
    result.eo = -0.5*lhs.s*rhs.ei;
    result.ei = lhs.s*rhs.ei;
    return result;
}

Versor operator*(const Rotor3 &lhs, const Quadvector &rhs)
{
    Versor result;
    result.b.e1o = -lhs.b.e23*rhs.e123o;
    result.b.e2o = -lhs.b.e31*rhs.e123o;
    result.b.e3o = -lhs.b.e12*rhs.e123o;
    result.b.e1i = -lhs.b.e23*rhs.e123i;
    result.b.e2i = -lhs.b.e31*rhs.e123i;
    result.b.e3i = -lhs.b.e12*rhs.e123i;
    result.b.eoi = -lhs.b.e12*rhs.e12oi-lhs.b.e31*rhs.e31oi-lhs.b.e23*rhs.e23oi;
    result.q.e123o = lhs.s*rhs.e123o;
    result.q.e123i = lhs.s*rhs.e123i;
    result.q.e23oi = lhs.s*rhs.e23oi+lhs.b.e12*rhs.e31oi-lhs.b.e31*rhs.e12oi;
    result.q.e31oi = lhs.s*rhs.e31oi-lhs.b.e12*rhs.e23oi+lhs.b.e23*rhs.e12oi;
    result.q.e12oi = lhs.s*rhs.e12oi+lhs.b.e31*rhs.e23oi-lhs.b.e23*rhs.e31oi;
    return result;
}

Quadvector outer(const Rotor3 &lhs, const Quadvector &rhs)
{
    Quadvector result;
    result.e123o = lhs.s*rhs.e123o;
    result.e123i = lhs.s*rhs.e123i;
    result.e23oi = lhs.s*rhs.e23oi+lhs.b.e12*rhs.e31oi-lhs.b.e31*rhs.e12oi;
    result.e31oi = lhs.s*rhs.e31oi-lhs.b.e12*rhs.e23oi+lhs.b.e23*rhs.e12oi;
    result.e12oi = lhs.s*rhs.e12oi+lhs.b.e31*rhs.e23oi-lhs.b.e23*rhs.e31oi;
    return result;
}

Versor inner(const Rotor3 &lhs, const Quadvector &rhs)
{
    Versor result;
    result.b.e1o = -lhs.b.e23*rhs.e123o;
    result.b.e2o = -lhs.b.e31*rhs.e123o;
    result.b.e3o = -lhs.b.e12*rhs.e123o;
    result.b.e1i = -lhs.b.e23*rhs.e123i;
    result.b.e2i = -lhs.b.e31*rhs.e123i;
    result.b.e3i = -lhs.b.e12*rhs.e123i;
    result.b.eoi = -lhs.b.e12*rhs.e12oi-lhs.b.e31*rhs.e31oi-lhs.b.e23*rhs.e23oi;
    result.q.e123o = lhs.s*rhs.e123o;
    result.q.e123i = lhs.s*rhs.e123i;
    result.q.e23oi = lhs.s*rhs.e23oi;
    result.q.e31oi = lhs.s*rhs.e31oi;
    result.q.e12oi = lhs.s*rhs.e12oi;
    return result;
}

Versor operator*(const Rotor3 &lhs, const Bivector &rhs)
{
    Versor result;
    result.s = -lhs.b.e12*rhs.e12-lhs.b.e31*rhs.e31-lhs.b.e23*rhs.e23;
    result.b.e23 = lhs.s*rhs.e23+lhs.b.e12*rhs.e31-lhs.b.e31*rhs.e12;
    result.b.e31 = lhs.s*rhs.e31-lhs.b.e12*rhs.e23+lhs.b.e23*rhs.e12;
    result.b.e12 = lhs.s*rhs.e12+lhs.b.e31*rhs.e23-lhs.b.e23*rhs.e31;
    result.b.e1o = lhs.s*rhs.e1o+lhs.b.e12*rhs.e2o-lhs.b.e31*rhs.e3o;
    result.b.e2o = lhs.s*rhs.e2o-lhs.b.e12*rhs.e1o+lhs.b.e23*rhs.e3o;
    result.b.e3o = lhs.s*rhs.e3o+lhs.b.e31*rhs.e1o-lhs.b.e23*rhs.e2o;
    result.b.e1i = lhs.s*rhs.e1i+lhs.b.e12*rhs.e2i-lhs.b.e31*rhs.e3i;
    result.b.e2i = lhs.s*rhs.e2i-lhs.b.e12*rhs.e1i+lhs.b.e23*rhs.e3i;
    result.b.e3i = lhs.s*rhs.e3i+lhs.b.e31*rhs.e1i-lhs.b.e23*rhs.e2i;
    result.b.eoi = lhs.s*rhs.eoi;
    result.q.e123o = lhs.b.e12*rhs.e3o+lhs.b.e31*rhs.e2o+lhs.b.e23*rhs.e1o;
    result.q.e123i = lhs.b.e12*rhs.e3i+lhs.b.e31*rhs.e2i+lhs.b.e23*rhs.e1i;
    result.q.e23oi = lhs.b.e23*rhs.eoi;
    result.q.e31oi = lhs.b.e31*rhs.eoi;
    result.q.e12oi = lhs.b.e12*rhs.eoi;
    return result;
}

Versor outer(const Rotor3 &lhs, const Bivector &rhs)
{
    Versor result;
    result.b.e23 = lhs.s*rhs.e23;
    result.b.e31 = lhs.s*rhs.e31;
    result.b.e12 = lhs.s*rhs.e12;
    result.b.e1o = lhs.s*rhs.e1o;
    result.b.e2o = lhs.s*rhs.e2o;
    result.b.e3o = lhs.s*rhs.e3o;
    result.b.e1i = lhs.s*rhs.e1i;
    result.b.e2i = lhs.s*rhs.e2i;
    result.b.e3i = lhs.s*rhs.e3i;
    result.b.eoi = lhs.s*rhs.eoi;
    result.q.e123o = lhs.b.e12*rhs.e3o+lhs.b.e31*rhs.e2o+lhs.b.e23*rhs.e1o;
    result.q.e123i = lhs.b.e12*rhs.e3i+lhs.b.e31*rhs.e2i+lhs.b.e23*rhs.e1i;
    result.q.e23oi = lhs.b.e23*rhs.eoi;
    result.q.e31oi = lhs.b.e31*rhs.eoi;
    result.q.e12oi = lhs.b.e12*rhs.eoi;
    return result;
}

Rotor inner(const Rotor3 &lhs, const Bivector &rhs)
{
    Rotor result;
    result.s = -lhs.b.e12*rhs.e12-lhs.b.e31*rhs.e31-lhs.b.e23*rhs.e23;
    result.b.e23 = lhs.s*rhs.e23;
    result.b.e31 = lhs.s*rhs.e31;
    result.b.e12 = lhs.s*rhs.e12;
    result.b.e1o = lhs.s*rhs.e1o;
    result.b.e2o = lhs.s*rhs.e2o;
    result.b.e3o = lhs.s*rhs.e3o;
    result.b.e1i = lhs.s*rhs.e1i;
    result.b.e2i = lhs.s*rhs.e2i;
    result.b.e3i = lhs.s*rhs.e3i;
    result.b.eoi = lhs.s*rhs.eoi;
    return result;
}

Multivector operator*(const Rotor3 &lhs, const Trivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.b.e23*rhs.e123;
    result.v.e2 = -lhs.b.e31*rhs.e123;
    result.v.e3 = -lhs.b.e12*rhs.e123;
    result.v.eo = 0.5*lhs.b.e12*rhs.e12i+0.5*lhs.b.e31*rhs.e31i+0.5*lhs.b.e23*rhs.e23i;
    result.v.ei = -lhs.b.e12*rhs.e12i-lhs.b.e31*rhs.e31i-lhs.b.e23*rhs.e23i;
    result.t.e123 = lhs.s*rhs.e123;
    result.t.e23o = lhs.s*rhs.e23o+lhs.b.e12*rhs.e31o-lhs.b.e31*rhs.e12o;
    result.t.e31o = lhs.s*rhs.e31o-lhs.b.e12*rhs.e23o+lhs.b.e23*rhs.e12o;
    result.t.e12o = lhs.s*rhs.e12o+lhs.b.e31*rhs.e23o-lhs.b.e23*rhs.e31o;
    result.t.e23i = lhs.s*rhs.e23i+lhs.b.e12*rhs.e31i-lhs.b.e31*rhs.e12i;
    result.t.e31i = lhs.s*rhs.e31i-lhs.b.e12*rhs.e23i+lhs.b.e23*rhs.e12i;
    result.t.e12i = lhs.s*rhs.e12i+lhs.b.e31*rhs.e23i-lhs.b.e23*rhs.e31i;
    result.t.e1oi = lhs.s*rhs.e1oi+lhs.b.e12*rhs.e2oi-lhs.b.e31*rhs.e3oi;
    result.t.e2oi = lhs.s*rhs.e2oi-lhs.b.e12*rhs.e1oi+lhs.b.e23*rhs.e3oi;
    result.t.e3oi = lhs.s*rhs.e3oi+lhs.b.e31*rhs.e1oi-lhs.b.e23*rhs.e2oi;
    result.p = lhs.b.e12*rhs.e3oi+lhs.b.e31*rhs.e2oi+lhs.b.e23*rhs.e1oi;
    return result;
}

Multivector outer(const Rotor3 &lhs, const Trivector &rhs)
{
    Multivector result;
    result.t.e123 = lhs.s*rhs.e123;
    result.t.e23o = lhs.s*rhs.e23o;
    result.t.e31o = lhs.s*rhs.e31o;
    result.t.e12o = lhs.s*rhs.e12o;
    result.t.e23i = lhs.s*rhs.e23i;
    result.t.e31i = lhs.s*rhs.e31i;
    result.t.e12i = lhs.s*rhs.e12i;
    result.t.e1oi = lhs.s*rhs.e1oi;
    result.t.e2oi = lhs.s*rhs.e2oi;
    result.t.e3oi = lhs.s*rhs.e3oi;
    result.p = lhs.b.e12*rhs.e3oi+lhs.b.e31*rhs.e2oi+lhs.b.e23*rhs.e1oi;
    return result;
}

Multivector inner(const Rotor3 &lhs, const Trivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.b.e23*rhs.e123;
    result.v.e2 = -lhs.b.e31*rhs.e123;
    result.v.e3 = -lhs.b.e12*rhs.e123;
    result.v.eo = 0.5*lhs.b.e12*rhs.e12i+0.5*lhs.b.e31*rhs.e31i+0.5*lhs.b.e23*rhs.e23i;
    result.v.ei = -lhs.b.e12*rhs.e12i-lhs.b.e31*rhs.e31i-lhs.b.e23*rhs.e23i;
    result.t.e123 = lhs.s*rhs.e123;
    result.t.e23o = lhs.s*rhs.e23o;
    result.t.e31o = lhs.s*rhs.e31o;
    result.t.e12o = lhs.s*rhs.e12o;
    result.t.e23i = lhs.s*rhs.e23i;
    result.t.e31i = lhs.s*rhs.e31i;
    result.t.e12i = lhs.s*rhs.e12i;
    result.t.e1oi = lhs.s*rhs.e1oi;
    result.t.e2oi = lhs.s*rhs.e2oi;
    result.t.e3oi = lhs.s*rhs.e3oi;
    return result;
}

Versor operator*(const Rotor3 &lhs, const Rotor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s+lhs.b.e23*rhs.b.e12;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23-lhs.b.e23*rhs.b.e31;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o+lhs.b.e23*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e31*rhs.b.e1o-lhs.b.e23*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i+lhs.b.e23*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e31*rhs.b.e1i-lhs.b.e23*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi;
    result.q.e123o = lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e23*rhs.b.e1o;
    result.q.e123i = lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e23*rhs.b.e1i;
    result.q.e23oi = lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = lhs.b.e31*rhs.b.eoi;
    result.q.e12oi = lhs.b.e12*rhs.b.eoi;
    return result;
}

Versor outer(const Rotor3 &lhs, const Rotor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi;
    result.q.e123o = lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e23*rhs.b.e1o;
    result.q.e123i = lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e23*rhs.b.e1i;
    result.q.e23oi = lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = lhs.b.e31*rhs.b.eoi;
    result.q.e12oi = lhs.b.e12*rhs.b.eoi;
    return result;
}

Rotor inner(const Rotor3 &lhs, const Rotor &rhs)
{
    Rotor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi;
    return result;
}

Versor operator*(const Rotor3 &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s+lhs.b.e23*rhs.b.e12;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23-lhs.b.e23*rhs.b.e31;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o-lhs.b.e23*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e23*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e23*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i-lhs.b.e23*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e23*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e23*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e23*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e23*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi+lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e23*rhs.q.e31oi;
    return result;
}

Versor outer(const Rotor3 &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e23*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e23*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi+lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e23*rhs.q.e31oi;
    return result;
}

Versor inner(const Rotor3 &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o-lhs.b.e23*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e31*rhs.q.e123o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o;
    result.b.e1i = lhs.s*rhs.b.e1i-lhs.b.e23*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e31*rhs.q.e123i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi;
    result.q.e123o = lhs.s*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi;
    result.q.e31oi = lhs.s*rhs.q.e31oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi;
    return result;
}

Multivector operator*(const Rotor3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e23*rhs.t.e123;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123+lhs.b.e23*rhs.v.e3;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1-lhs.b.e23*rhs.v.e2;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e23*rhs.t.e23i;
    result.v.ei = lhs.s*rhs.v.ei-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e23*rhs.t.e23i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s+lhs.b.e23*rhs.b.e12;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23-lhs.b.e23*rhs.b.e31;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o-lhs.b.e23*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e23*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e23*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i-lhs.b.e23*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e23*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e23*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2+lhs.b.e23*rhs.v.e1;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.b.e12*rhs.t.e31o-lhs.b.e31*rhs.t.e12o+lhs.b.e23*rhs.v.eo;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.b.e12*rhs.t.e23o+lhs.b.e31*rhs.v.eo+lhs.b.e23*rhs.t.e12o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.b.e12*rhs.v.eo+lhs.b.e31*rhs.t.e23o-lhs.b.e23*rhs.t.e31o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e12*rhs.t.e31i-lhs.b.e31*rhs.t.e12i+lhs.b.e23*rhs.v.ei;
    result.t.e31i = lhs.s*rhs.t.e31i-lhs.b.e12*rhs.t.e23i+lhs.b.e31*rhs.v.ei+lhs.b.e23*rhs.t.e12i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e12*rhs.v.ei+lhs.b.e31*rhs.t.e23i-lhs.b.e23*rhs.t.e31i;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.b.e12*rhs.t.e2oi-lhs.b.e31*rhs.t.e3oi-lhs.b.e23*rhs.p;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e12*rhs.t.e1oi-lhs.b.e31*rhs.p+lhs.b.e23*rhs.t.e3oi;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p+lhs.b.e31*rhs.t.e1oi-lhs.b.e23*rhs.t.e2oi;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e23*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e23*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi+lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e23*rhs.q.e31oi;
    result.p = lhs.s*rhs.p+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e23*rhs.t.e1oi;
    return result;
}

Multivector outer(const Rotor3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s;
    result.v.e1 = lhs.s*rhs.v.e1;
    result.v.e2 = lhs.s*rhs.v.e2;
    result.v.e3 = lhs.s*rhs.v.e3;
    result.v.eo = -0.5*lhs.s*rhs.v.ei;
    result.v.ei = lhs.s*rhs.v.ei;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2+lhs.b.e23*rhs.v.e1;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.b.e23*rhs.v.eo;
    result.t.e31o = lhs.s*rhs.t.e31o+lhs.b.e31*rhs.v.eo;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.b.e12*rhs.v.eo;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e23*rhs.v.ei;
    result.t.e31i = lhs.s*rhs.t.e31i+lhs.b.e31*rhs.v.ei;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e12*rhs.v.ei;
    result.t.e1oi = lhs.s*rhs.t.e1oi-lhs.b.e23*rhs.p;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e31*rhs.p;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e23*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e23*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi+lhs.b.e23*rhs.b.eoi;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e23*rhs.q.e12oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e23*rhs.q.e31oi;
    result.p = lhs.s*rhs.p+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e23*rhs.t.e1oi;
    return result;
}

Multivector inner(const Rotor3 &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31-lhs.b.e23*rhs.b.e23;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e23*rhs.t.e123;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123+lhs.b.e23*rhs.v.e3;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1-lhs.b.e23*rhs.v.e2;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e23*rhs.t.e23i;
    result.v.ei = lhs.s*rhs.v.ei-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e23*rhs.t.e23i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o-lhs.b.e23*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e31*rhs.q.e123o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o;
    result.b.e1i = lhs.s*rhs.b.e1i-lhs.b.e23*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e31*rhs.q.e123i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi;
    result.t.e123 = lhs.s*rhs.t.e123;
    result.t.e23o = lhs.s*rhs.t.e23o;
    result.t.e31o = lhs.s*rhs.t.e31o;
    result.t.e12o = lhs.s*rhs.t.e12o;
    result.t.e23i = lhs.s*rhs.t.e23i;
    result.t.e31i = lhs.s*rhs.t.e31i;
    result.t.e12i = lhs.s*rhs.t.e12i;
    result.t.e1oi = lhs.s*rhs.t.e1oi-lhs.b.e23*rhs.p;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e31*rhs.p;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p;
    result.q.e123o = lhs.s*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi;
    result.q.e31oi = lhs.s*rhs.q.e31oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi;
    result.p = lhs.s*rhs.p;
    return result;
}

Rotor operator*(const Vector &lhs, const Vector &rhs)
{
    Rotor result;
    result.s = lhs.e1*rhs.e1+lhs.e2*rhs.e2+lhs.e3*rhs.e3-lhs.eo*rhs.ei-lhs.ei*rhs.eo;
    result.b.e23 = lhs.e2*rhs.e3-lhs.e3*rhs.e2;
    result.b.e31 = -lhs.e1*rhs.e3+lhs.e3*rhs.e1;
    result.b.e12 = lhs.e1*rhs.e2-lhs.e2*rhs.e1;
    result.b.e1o = lhs.e1*rhs.eo-lhs.eo*rhs.e1;
    result.b.e2o = lhs.e2*rhs.eo-lhs.eo*rhs.e2;
    result.b.e3o = lhs.e3*rhs.eo-lhs.eo*rhs.e3;
    result.b.e1i = lhs.e1*rhs.ei-lhs.ei*rhs.e1;
    result.b.e2i = lhs.e2*rhs.ei-lhs.ei*rhs.e2;
    result.b.e3i = lhs.e3*rhs.ei-lhs.ei*rhs.e3;
    result.b.eoi = lhs.eo*rhs.ei-lhs.ei*rhs.eo;
    return result;
}

Bivector outer(const Vector &lhs, const Vector &rhs)
{
    Bivector result;
    result.e23 = lhs.e2*rhs.e3-lhs.e3*rhs.e2;
    result.e31 = -lhs.e1*rhs.e3+lhs.e3*rhs.e1;
    result.e12 = lhs.e1*rhs.e2-lhs.e2*rhs.e1;
    result.e1o = lhs.e1*rhs.eo-lhs.eo*rhs.e1;
    result.e2o = lhs.e2*rhs.eo-lhs.eo*rhs.e2;
    result.e3o = lhs.e3*rhs.eo-lhs.eo*rhs.e3;
    result.e1i = lhs.e1*rhs.ei-lhs.ei*rhs.e1;
    result.e2i = lhs.e2*rhs.ei-lhs.ei*rhs.e2;
    result.e3i = lhs.e3*rhs.ei-lhs.ei*rhs.e3;
    result.eoi = lhs.eo*rhs.ei-lhs.ei*rhs.eo;
    return result;
}

double inner(const Vector &lhs, const Vector &rhs)
{
    double result;
    result = lhs.e1*rhs.e1+lhs.e2*rhs.e2+lhs.e3*rhs.e3-lhs.eo*rhs.ei-lhs.ei*rhs.eo;
    return result;
}

Multivector operator*(const Vector &lhs, const Quadvector &rhs)
{
    Multivector result;
    result.t.e123 = lhs.eo*rhs.e123i+lhs.ei*rhs.e123o;
    result.t.e23o = lhs.e1*rhs.e123o+lhs.eo*rhs.e23oi;
    result.t.e31o = lhs.e2*rhs.e123o+lhs.eo*rhs.e31oi;
    result.t.e12o = lhs.e3*rhs.e123o+lhs.eo*rhs.e12oi;
    result.t.e23i = lhs.e1*rhs.e123i-lhs.ei*rhs.e23oi;
    result.t.e31i = lhs.e2*rhs.e123i-lhs.ei*rhs.e31oi;
    result.t.e12i = lhs.e3*rhs.e123i-lhs.ei*rhs.e12oi;
    result.t.e1oi = -lhs.e2*rhs.e12oi+lhs.e3*rhs.e31oi;
    result.t.e2oi = lhs.e1*rhs.e12oi-lhs.e3*rhs.e23oi;
    result.t.e3oi = -lhs.e1*rhs.e31oi+lhs.e2*rhs.e23oi;
    result.p = lhs.e1*rhs.e23oi+lhs.e2*rhs.e31oi+lhs.e3*rhs.e12oi-lhs.eo*rhs.e123i+lhs.ei*rhs.e123o;
    return result;
}

Pseudoscalar outer(const Vector &lhs, const Quadvector &rhs)
{
    Pseudoscalar result;
    result.p = lhs.e1*rhs.e23oi+lhs.e2*rhs.e31oi+lhs.e3*rhs.e12oi-lhs.eo*rhs.e123i+lhs.ei*rhs.e123o;
    return result;
}

Trivector inner(const Vector &lhs, const Quadvector &rhs)
{
    Trivector result;
    result.e123 = lhs.eo*rhs.e123i+lhs.ei*rhs.e123o;
    result.e23o = lhs.e1*rhs.e123o+lhs.eo*rhs.e23oi;
    result.e31o = lhs.e2*rhs.e123o+lhs.eo*rhs.e31oi;
    result.e12o = lhs.e3*rhs.e123o+lhs.eo*rhs.e12oi;
    result.e23i = lhs.e1*rhs.e123i-lhs.ei*rhs.e23oi;
    result.e31i = lhs.e2*rhs.e123i-lhs.ei*rhs.e31oi;
    result.e12i = lhs.e3*rhs.e123i-lhs.ei*rhs.e12oi;
    result.e1oi = -lhs.e2*rhs.e12oi+lhs.e3*rhs.e31oi;
    result.e2oi = lhs.e1*rhs.e12oi-lhs.e3*rhs.e23oi;
    result.e3oi = -lhs.e1*rhs.e31oi+lhs.e2*rhs.e23oi;
    return result;
}

Multivector operator*(const Vector &lhs, const Bivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e2*rhs.e12+lhs.e3*rhs.e31+lhs.eo*rhs.e1i+lhs.ei*rhs.e1o;
    result.v.e2 = lhs.e1*rhs.e12-lhs.e3*rhs.e23+lhs.eo*rhs.e2i+lhs.ei*rhs.e2o;
    result.v.e3 = -lhs.e1*rhs.e31+lhs.e2*rhs.e23+lhs.eo*rhs.e3i+lhs.ei*rhs.e3o;
    result.v.eo = -0.5*lhs.e1*rhs.e1i-0.5*lhs.e2*rhs.e2i-0.5*lhs.e3*rhs.e3i+0.5*lhs.ei*rhs.eoi;
    result.v.ei = lhs.e1*rhs.e1i+lhs.e2*rhs.e2i+lhs.e3*rhs.e3i-lhs.ei*rhs.eoi;
    result.t.e123 = lhs.e1*rhs.e23+lhs.e2*rhs.e31+lhs.e3*rhs.e12;
    result.t.e23o = lhs.e2*rhs.e3o-lhs.e3*rhs.e2o+lhs.eo*rhs.e23;
    result.t.e31o = -lhs.e1*rhs.e3o+lhs.e3*rhs.e1o+lhs.eo*rhs.e31;
    result.t.e12o = lhs.e1*rhs.e2o-lhs.e2*rhs.e1o+lhs.eo*rhs.e12;
    result.t.e23i = lhs.e2*rhs.e3i-lhs.e3*rhs.e2i+lhs.ei*rhs.e23;
    result.t.e31i = -lhs.e1*rhs.e3i+lhs.e3*rhs.e1i+lhs.ei*rhs.e31;
    result.t.e12i = lhs.e1*rhs.e2i-lhs.e2*rhs.e1i+lhs.ei*rhs.e12;
    result.t.e1oi = lhs.e1*rhs.eoi-lhs.eo*rhs.e1i+lhs.ei*rhs.e1o;
    result.t.e2oi = lhs.e2*rhs.eoi-lhs.eo*rhs.e2i+lhs.ei*rhs.e2o;
    result.t.e3oi = lhs.e3*rhs.eoi-lhs.eo*rhs.e3i+lhs.ei*rhs.e3o;
    return result;
}

Trivector outer(const Vector &lhs, const Bivector &rhs)
{
    Trivector result;
    result.e123 = lhs.e1*rhs.e23+lhs.e2*rhs.e31+lhs.e3*rhs.e12;
    result.e23o = lhs.e2*rhs.e3o-lhs.e3*rhs.e2o+lhs.eo*rhs.e23;
    result.e31o = -lhs.e1*rhs.e3o+lhs.e3*rhs.e1o+lhs.eo*rhs.e31;
    result.e12o = lhs.e1*rhs.e2o-lhs.e2*rhs.e1o+lhs.eo*rhs.e12;
    result.e23i = lhs.e2*rhs.e3i-lhs.e3*rhs.e2i+lhs.ei*rhs.e23;
    result.e31i = -lhs.e1*rhs.e3i+lhs.e3*rhs.e1i+lhs.ei*rhs.e31;
    result.e12i = lhs.e1*rhs.e2i-lhs.e2*rhs.e1i+lhs.ei*rhs.e12;
    result.e1oi = lhs.e1*rhs.eoi-lhs.eo*rhs.e1i+lhs.ei*rhs.e1o;
    result.e2oi = lhs.e2*rhs.eoi-lhs.eo*rhs.e2i+lhs.ei*rhs.e2o;
    result.e3oi = lhs.e3*rhs.eoi-lhs.eo*rhs.e3i+lhs.ei*rhs.e3o;
    return result;
}

Vector inner(const Vector &lhs, const Bivector &rhs)
{
    Vector result;
    result.e1 = -lhs.e2*rhs.e12+lhs.e3*rhs.e31+lhs.eo*rhs.e1i+lhs.ei*rhs.e1o;
    result.e2 = lhs.e1*rhs.e12-lhs.e3*rhs.e23+lhs.eo*rhs.e2i+lhs.ei*rhs.e2o;
    result.e3 = -lhs.e1*rhs.e31+lhs.e2*rhs.e23+lhs.eo*rhs.e3i+lhs.ei*rhs.e3o;
    result.eo = -0.5*lhs.e1*rhs.e1i-0.5*lhs.e2*rhs.e2i-0.5*lhs.e3*rhs.e3i+0.5*lhs.ei*rhs.eoi;
    result.ei = lhs.e1*rhs.e1i+lhs.e2*rhs.e2i+lhs.e3*rhs.e3i-lhs.ei*rhs.eoi;
    return result;
}

Versor operator*(const Vector &lhs, const Trivector &rhs)
{
    Versor result;
    result.b.e23 = lhs.e1*rhs.e123-lhs.eo*rhs.e23i-lhs.ei*rhs.e23o;
    result.b.e31 = lhs.e2*rhs.e123-lhs.eo*rhs.e31i-lhs.ei*rhs.e31o;
    result.b.e12 = lhs.e3*rhs.e123-lhs.eo*rhs.e12i-lhs.ei*rhs.e12o;
    result.b.e1o = -lhs.e2*rhs.e12o+lhs.e3*rhs.e31o-lhs.eo*rhs.e1oi;
    result.b.e2o = lhs.e1*rhs.e12o-lhs.e3*rhs.e23o-lhs.eo*rhs.e2oi;
    result.b.e3o = -lhs.e1*rhs.e31o+lhs.e2*rhs.e23o-lhs.eo*rhs.e3oi;
    result.b.e1i = -lhs.e2*rhs.e12i+lhs.e3*rhs.e31i+lhs.ei*rhs.e1oi;
    result.b.e2i = lhs.e1*rhs.e12i-lhs.e3*rhs.e23i+lhs.ei*rhs.e2oi;
    result.b.e3i = -lhs.e1*rhs.e31i+lhs.e2*rhs.e23i+lhs.ei*rhs.e3oi;
    result.b.eoi = lhs.e1*rhs.e1oi+lhs.e2*rhs.e2oi+lhs.e3*rhs.e3oi;
    result.q.e123o = lhs.e1*rhs.e23o+lhs.e2*rhs.e31o+lhs.e3*rhs.e12o-lhs.eo*rhs.e123;
    result.q.e123i = lhs.e1*rhs.e23i+lhs.e2*rhs.e31i+lhs.e3*rhs.e12i-lhs.ei*rhs.e123;
    result.q.e23oi = lhs.e2*rhs.e3oi-lhs.e3*rhs.e2oi+lhs.eo*rhs.e23i-lhs.ei*rhs.e23o;
    result.q.e31oi = -lhs.e1*rhs.e3oi+lhs.e3*rhs.e1oi+lhs.eo*rhs.e31i-lhs.ei*rhs.e31o;
    result.q.e12oi = lhs.e1*rhs.e2oi-lhs.e2*rhs.e1oi+lhs.eo*rhs.e12i-lhs.ei*rhs.e12o;
    return result;
}

Quadvector outer(const Vector &lhs, const Trivector &rhs)
{
    Quadvector result;
    result.e123o = lhs.e1*rhs.e23o+lhs.e2*rhs.e31o+lhs.e3*rhs.e12o-lhs.eo*rhs.e123;
    result.e123i = lhs.e1*rhs.e23i+lhs.e2*rhs.e31i+lhs.e3*rhs.e12i-lhs.ei*rhs.e123;
    result.e23oi = lhs.e2*rhs.e3oi-lhs.e3*rhs.e2oi+lhs.eo*rhs.e23i-lhs.ei*rhs.e23o;
    result.e31oi = -lhs.e1*rhs.e3oi+lhs.e3*rhs.e1oi+lhs.eo*rhs.e31i-lhs.ei*rhs.e31o;
    result.e12oi = lhs.e1*rhs.e2oi-lhs.e2*rhs.e1oi+lhs.eo*rhs.e12i-lhs.ei*rhs.e12o;
    return result;
}

Bivector inner(const Vector &lhs, const Trivector &rhs)
{
    Bivector result;
    result.e23 = lhs.e1*rhs.e123-lhs.eo*rhs.e23i-lhs.ei*rhs.e23o;
    result.e31 = lhs.e2*rhs.e123-lhs.eo*rhs.e31i-lhs.ei*rhs.e31o;
    result.e12 = lhs.e3*rhs.e123-lhs.eo*rhs.e12i-lhs.ei*rhs.e12o;
    result.e1o = -lhs.e2*rhs.e12o+lhs.e3*rhs.e31o-lhs.eo*rhs.e1oi;
    result.e2o = lhs.e1*rhs.e12o-lhs.e3*rhs.e23o-lhs.eo*rhs.e2oi;
    result.e3o = -lhs.e1*rhs.e31o+lhs.e2*rhs.e23o-lhs.eo*rhs.e3oi;
    result.e1i = -lhs.e2*rhs.e12i+lhs.e3*rhs.e31i+lhs.ei*rhs.e1oi;
    result.e2i = lhs.e1*rhs.e12i-lhs.e3*rhs.e23i+lhs.ei*rhs.e2oi;
    result.e3i = -lhs.e1*rhs.e31i+lhs.e2*rhs.e23i+lhs.ei*rhs.e3oi;
    result.eoi = lhs.e1*rhs.e1oi+lhs.e2*rhs.e2oi+lhs.e3*rhs.e3oi;
    return result;
}

Multivector operator*(const Vector &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31+lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23+lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s+lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i-0.5*lhs.ei*rhs.s+0.5*lhs.ei*rhs.b.eoi;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i+lhs.ei*rhs.s-lhs.ei*rhs.b.eoi;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o+lhs.eo*rhs.b.e23;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o+lhs.eo*rhs.b.e31;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.eo*rhs.b.e12;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i+lhs.ei*rhs.b.e23;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i+lhs.ei*rhs.b.e31;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.ei*rhs.b.e12;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.t.e2oi = lhs.e2*rhs.b.eoi-lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.t.e3oi = lhs.e3*rhs.b.eoi-lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    return result;
}

Multivector outer(const Vector &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.ei*rhs.s;
    result.v.ei = lhs.ei*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o+lhs.eo*rhs.b.e23;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o+lhs.eo*rhs.b.e31;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.eo*rhs.b.e12;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i+lhs.ei*rhs.b.e23;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i+lhs.ei*rhs.b.e31;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.ei*rhs.b.e12;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.t.e2oi = lhs.e2*rhs.b.eoi-lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.t.e3oi = lhs.e3*rhs.b.eoi-lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    return result;
}

Vector inner(const Vector &lhs, const Rotor &rhs)
{
    Vector result;
    result.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31+lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23+lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s+lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i-0.5*lhs.ei*rhs.s+0.5*lhs.ei*rhs.b.eoi;
    result.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i+lhs.ei*rhs.s-lhs.ei*rhs.b.eoi;
    return result;
}

Multivector operator*(const Vector &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31+lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23+lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s+lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i-0.5*lhs.ei*rhs.s+0.5*lhs.ei*rhs.b.eoi;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i+lhs.ei*rhs.s-lhs.ei*rhs.b.eoi;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12+lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    result.t.e23o = lhs.e1*rhs.q.e123o+lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o+lhs.eo*rhs.b.e23+lhs.eo*rhs.q.e23oi;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e2*rhs.q.e123o+lhs.e3*rhs.b.e1o+lhs.eo*rhs.b.e31+lhs.eo*rhs.q.e31oi;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.e3*rhs.q.e123o+lhs.eo*rhs.b.e12+lhs.eo*rhs.q.e12oi;
    result.t.e23i = lhs.e1*rhs.q.e123i+lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i+lhs.ei*rhs.b.e23-lhs.ei*rhs.q.e23oi;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e2*rhs.q.e123i+lhs.e3*rhs.b.e1i+lhs.ei*rhs.b.e31-lhs.ei*rhs.q.e31oi;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.e3*rhs.q.e123i+lhs.ei*rhs.b.e12-lhs.ei*rhs.q.e12oi;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi-lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.t.e2oi = lhs.e1*rhs.q.e12oi+lhs.e2*rhs.b.eoi-lhs.e3*rhs.q.e23oi-lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi+lhs.e3*rhs.b.eoi-lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi-lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    return result;
}

Multivector outer(const Vector &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.ei*rhs.s;
    result.v.ei = lhs.ei*rhs.s;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o+lhs.eo*rhs.b.e23;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o+lhs.eo*rhs.b.e31;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.eo*rhs.b.e12;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i+lhs.ei*rhs.b.e23;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i+lhs.ei*rhs.b.e31;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.ei*rhs.b.e12;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.t.e2oi = lhs.e2*rhs.b.eoi-lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.t.e3oi = lhs.e3*rhs.b.eoi-lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi-lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    return result;
}

Multivector inner(const Vector &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31+lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23+lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s+lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i-0.5*lhs.ei*rhs.s+0.5*lhs.ei*rhs.b.eoi;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i+lhs.ei*rhs.s-lhs.ei*rhs.b.eoi;
    result.t.e123 = lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    result.t.e23o = lhs.e1*rhs.q.e123o+lhs.eo*rhs.q.e23oi;
    result.t.e31o = lhs.e2*rhs.q.e123o+lhs.eo*rhs.q.e31oi;
    result.t.e12o = lhs.e3*rhs.q.e123o+lhs.eo*rhs.q.e12oi;
    result.t.e23i = lhs.e1*rhs.q.e123i-lhs.ei*rhs.q.e23oi;
    result.t.e31i = lhs.e2*rhs.q.e123i-lhs.ei*rhs.q.e31oi;
    result.t.e12i = lhs.e3*rhs.q.e123i-lhs.ei*rhs.q.e12oi;
    result.t.e1oi = -lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi;
    result.t.e2oi = lhs.e1*rhs.q.e12oi-lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi;
    return result;
}

Multivector operator*(const Vector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.e1*rhs.v.e1+lhs.e2*rhs.v.e2+lhs.e3*rhs.v.e3-lhs.eo*rhs.v.ei-lhs.ei*rhs.v.eo;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31+lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23+lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s+lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i-0.5*lhs.ei*rhs.s+0.5*lhs.ei*rhs.b.eoi;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i+lhs.ei*rhs.s-lhs.ei*rhs.b.eoi;
    result.b.e23 = lhs.e1*rhs.t.e123+lhs.e2*rhs.v.e3-lhs.e3*rhs.v.e2-lhs.eo*rhs.t.e23i-lhs.ei*rhs.t.e23o;
    result.b.e31 = -lhs.e1*rhs.v.e3+lhs.e2*rhs.t.e123+lhs.e3*rhs.v.e1-lhs.eo*rhs.t.e31i-lhs.ei*rhs.t.e31o;
    result.b.e12 = lhs.e1*rhs.v.e2-lhs.e2*rhs.v.e1+lhs.e3*rhs.t.e123-lhs.eo*rhs.t.e12i-lhs.ei*rhs.t.e12o;
    result.b.e1o = lhs.e1*rhs.v.eo-lhs.e2*rhs.t.e12o+lhs.e3*rhs.t.e31o-lhs.eo*rhs.v.e1-lhs.eo*rhs.t.e1oi;
    result.b.e2o = lhs.e1*rhs.t.e12o+lhs.e2*rhs.v.eo-lhs.e3*rhs.t.e23o-lhs.eo*rhs.v.e2-lhs.eo*rhs.t.e2oi;
    result.b.e3o = -lhs.e1*rhs.t.e31o+lhs.e2*rhs.t.e23o+lhs.e3*rhs.v.eo-lhs.eo*rhs.v.e3-lhs.eo*rhs.t.e3oi;
    result.b.e1i = lhs.e1*rhs.v.ei-lhs.e2*rhs.t.e12i+lhs.e3*rhs.t.e31i-lhs.ei*rhs.v.e1+lhs.ei*rhs.t.e1oi;
    result.b.e2i = lhs.e1*rhs.t.e12i+lhs.e2*rhs.v.ei-lhs.e3*rhs.t.e23i-lhs.ei*rhs.v.e2+lhs.ei*rhs.t.e2oi;
    result.b.e3i = -lhs.e1*rhs.t.e31i+lhs.e2*rhs.t.e23i+lhs.e3*rhs.v.ei-lhs.ei*rhs.v.e3+lhs.ei*rhs.t.e3oi;
    result.b.eoi = lhs.e1*rhs.t.e1oi+lhs.e2*rhs.t.e2oi+lhs.e3*rhs.t.e3oi+lhs.eo*rhs.v.ei-lhs.ei*rhs.v.eo;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12+lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    result.t.e23o = lhs.e1*rhs.q.e123o+lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o+lhs.eo*rhs.b.e23+lhs.eo*rhs.q.e23oi;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e2*rhs.q.e123o+lhs.e3*rhs.b.e1o+lhs.eo*rhs.b.e31+lhs.eo*rhs.q.e31oi;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.e3*rhs.q.e123o+lhs.eo*rhs.b.e12+lhs.eo*rhs.q.e12oi;
    result.t.e23i = lhs.e1*rhs.q.e123i+lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i+lhs.ei*rhs.b.e23-lhs.ei*rhs.q.e23oi;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e2*rhs.q.e123i+lhs.e3*rhs.b.e1i+lhs.ei*rhs.b.e31-lhs.ei*rhs.q.e31oi;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.e3*rhs.q.e123i+lhs.ei*rhs.b.e12-lhs.ei*rhs.q.e12oi;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi-lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.t.e2oi = lhs.e1*rhs.q.e12oi+lhs.e2*rhs.b.eoi-lhs.e3*rhs.q.e23oi-lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi+lhs.e3*rhs.b.eoi-lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.q.e123o = lhs.e1*rhs.t.e23o+lhs.e2*rhs.t.e31o+lhs.e3*rhs.t.e12o-lhs.eo*rhs.t.e123-lhs.eo*rhs.p;
    result.q.e123i = lhs.e1*rhs.t.e23i+lhs.e2*rhs.t.e31i+lhs.e3*rhs.t.e12i-lhs.ei*rhs.t.e123+lhs.ei*rhs.p;
    result.q.e23oi = lhs.e1*rhs.p+lhs.e2*rhs.t.e3oi-lhs.e3*rhs.t.e2oi+lhs.eo*rhs.t.e23i-lhs.ei*rhs.t.e23o;
    result.q.e31oi = -lhs.e1*rhs.t.e3oi+lhs.e2*rhs.p+lhs.e3*rhs.t.e1oi+lhs.eo*rhs.t.e31i-lhs.ei*rhs.t.e31o;
    result.q.e12oi = lhs.e1*rhs.t.e2oi-lhs.e2*rhs.t.e1oi+lhs.e3*rhs.p+lhs.eo*rhs.t.e12i-lhs.ei*rhs.t.e12o;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi-lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    return result;
}

Multivector outer(const Vector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e1*rhs.s;
    result.v.e2 = lhs.e2*rhs.s;
    result.v.e3 = lhs.e3*rhs.s;
    result.v.eo = -0.5*lhs.ei*rhs.s;
    result.v.ei = lhs.ei*rhs.s;
    result.b.e23 = lhs.e2*rhs.v.e3-lhs.e3*rhs.v.e2;
    result.b.e31 = -lhs.e1*rhs.v.e3+lhs.e3*rhs.v.e1;
    result.b.e12 = lhs.e1*rhs.v.e2-lhs.e2*rhs.v.e1;
    result.b.e1o = lhs.e1*rhs.v.eo-lhs.eo*rhs.v.e1;
    result.b.e2o = lhs.e2*rhs.v.eo-lhs.eo*rhs.v.e2;
    result.b.e3o = lhs.e3*rhs.v.eo-lhs.eo*rhs.v.e3;
    result.b.e1i = lhs.e1*rhs.v.ei-lhs.ei*rhs.v.e1;
    result.b.e2i = lhs.e2*rhs.v.ei-lhs.ei*rhs.v.e2;
    result.b.e3i = lhs.e3*rhs.v.ei-lhs.ei*rhs.v.e3;
    result.b.eoi = lhs.eo*rhs.v.ei-lhs.ei*rhs.v.eo;
    result.t.e123 = lhs.e1*rhs.b.e23+lhs.e2*rhs.b.e31+lhs.e3*rhs.b.e12;
    result.t.e23o = lhs.e2*rhs.b.e3o-lhs.e3*rhs.b.e2o+lhs.eo*rhs.b.e23;
    result.t.e31o = -lhs.e1*rhs.b.e3o+lhs.e3*rhs.b.e1o+lhs.eo*rhs.b.e31;
    result.t.e12o = lhs.e1*rhs.b.e2o-lhs.e2*rhs.b.e1o+lhs.eo*rhs.b.e12;
    result.t.e23i = lhs.e2*rhs.b.e3i-lhs.e3*rhs.b.e2i+lhs.ei*rhs.b.e23;
    result.t.e31i = -lhs.e1*rhs.b.e3i+lhs.e3*rhs.b.e1i+lhs.ei*rhs.b.e31;
    result.t.e12i = lhs.e1*rhs.b.e2i-lhs.e2*rhs.b.e1i+lhs.ei*rhs.b.e12;
    result.t.e1oi = lhs.e1*rhs.b.eoi-lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.t.e2oi = lhs.e2*rhs.b.eoi-lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.t.e3oi = lhs.e3*rhs.b.eoi-lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.q.e123o = lhs.e1*rhs.t.e23o+lhs.e2*rhs.t.e31o+lhs.e3*rhs.t.e12o-lhs.eo*rhs.t.e123-lhs.eo*rhs.p;
    result.q.e123i = lhs.e1*rhs.t.e23i+lhs.e2*rhs.t.e31i+lhs.e3*rhs.t.e12i-lhs.ei*rhs.t.e123+lhs.ei*rhs.p;
    result.q.e23oi = lhs.e1*rhs.p+lhs.e2*rhs.t.e3oi-lhs.e3*rhs.t.e2oi+lhs.eo*rhs.t.e23i-lhs.ei*rhs.t.e23o;
    result.q.e31oi = -lhs.e1*rhs.t.e3oi+lhs.e2*rhs.p+lhs.e3*rhs.t.e1oi+lhs.eo*rhs.t.e31i-lhs.ei*rhs.t.e31o;
    result.q.e12oi = lhs.e1*rhs.t.e2oi-lhs.e2*rhs.t.e1oi+lhs.e3*rhs.p+lhs.eo*rhs.t.e12i-lhs.ei*rhs.t.e12o;
    result.p = lhs.e1*rhs.q.e23oi+lhs.e2*rhs.q.e31oi+lhs.e3*rhs.q.e12oi-lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    return result;
}

Multivector inner(const Vector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.e1*rhs.v.e1+lhs.e2*rhs.v.e2+lhs.e3*rhs.v.e3-lhs.eo*rhs.v.ei-lhs.ei*rhs.v.eo;
    result.v.e1 = lhs.e1*rhs.s-lhs.e2*rhs.b.e12+lhs.e3*rhs.b.e31+lhs.eo*rhs.b.e1i+lhs.ei*rhs.b.e1o;
    result.v.e2 = lhs.e1*rhs.b.e12+lhs.e2*rhs.s-lhs.e3*rhs.b.e23+lhs.eo*rhs.b.e2i+lhs.ei*rhs.b.e2o;
    result.v.e3 = -lhs.e1*rhs.b.e31+lhs.e2*rhs.b.e23+lhs.e3*rhs.s+lhs.eo*rhs.b.e3i+lhs.ei*rhs.b.e3o;
    result.v.eo = -0.5*lhs.e1*rhs.b.e1i-0.5*lhs.e2*rhs.b.e2i-0.5*lhs.e3*rhs.b.e3i-0.5*lhs.ei*rhs.s+0.5*lhs.ei*rhs.b.eoi;
    result.v.ei = lhs.e1*rhs.b.e1i+lhs.e2*rhs.b.e2i+lhs.e3*rhs.b.e3i+lhs.ei*rhs.s-lhs.ei*rhs.b.eoi;
    result.b.e23 = lhs.e1*rhs.t.e123-lhs.eo*rhs.t.e23i-lhs.ei*rhs.t.e23o;
    result.b.e31 = lhs.e2*rhs.t.e123-lhs.eo*rhs.t.e31i-lhs.ei*rhs.t.e31o;
    result.b.e12 = lhs.e3*rhs.t.e123-lhs.eo*rhs.t.e12i-lhs.ei*rhs.t.e12o;
    result.b.e1o = -lhs.e2*rhs.t.e12o+lhs.e3*rhs.t.e31o-lhs.eo*rhs.t.e1oi;
    result.b.e2o = lhs.e1*rhs.t.e12o-lhs.e3*rhs.t.e23o-lhs.eo*rhs.t.e2oi;
    result.b.e3o = -lhs.e1*rhs.t.e31o+lhs.e2*rhs.t.e23o-lhs.eo*rhs.t.e3oi;
    result.b.e1i = -lhs.e2*rhs.t.e12i+lhs.e3*rhs.t.e31i+lhs.ei*rhs.t.e1oi;
    result.b.e2i = lhs.e1*rhs.t.e12i-lhs.e3*rhs.t.e23i+lhs.ei*rhs.t.e2oi;
    result.b.e3i = -lhs.e1*rhs.t.e31i+lhs.e2*rhs.t.e23i+lhs.ei*rhs.t.e3oi;
    result.b.eoi = lhs.e1*rhs.t.e1oi+lhs.e2*rhs.t.e2oi+lhs.e3*rhs.t.e3oi;
    result.t.e123 = lhs.eo*rhs.q.e123i+lhs.ei*rhs.q.e123o;
    result.t.e23o = lhs.e1*rhs.q.e123o+lhs.eo*rhs.q.e23oi;
    result.t.e31o = lhs.e2*rhs.q.e123o+lhs.eo*rhs.q.e31oi;
    result.t.e12o = lhs.e3*rhs.q.e123o+lhs.eo*rhs.q.e12oi;
    result.t.e23i = lhs.e1*rhs.q.e123i-lhs.ei*rhs.q.e23oi;
    result.t.e31i = lhs.e2*rhs.q.e123i-lhs.ei*rhs.q.e31oi;
    result.t.e12i = lhs.e3*rhs.q.e123i-lhs.ei*rhs.q.e12oi;
    result.t.e1oi = -lhs.e2*rhs.q.e12oi+lhs.e3*rhs.q.e31oi;
    result.t.e2oi = lhs.e1*rhs.q.e12oi-lhs.e3*rhs.q.e23oi;
    result.t.e3oi = -lhs.e1*rhs.q.e31oi+lhs.e2*rhs.q.e23oi;
    result.q.e123o = -lhs.eo*rhs.p;
    result.q.e123i = lhs.ei*rhs.p;
    result.q.e23oi = lhs.e1*rhs.p;
    result.q.e31oi = lhs.e2*rhs.p;
    result.q.e12oi = lhs.e3*rhs.p;
    return result;
}

Rotor operator*(const Quadvector &lhs, const Quadvector &rhs)
{
    Rotor result;
    result.s = -lhs.e123o*rhs.e123i-lhs.e123i*rhs.e123o-lhs.e12oi*rhs.e12oi-lhs.e31oi*rhs.e31oi-lhs.e23oi*rhs.e23oi;
    result.b.e23 = lhs.e12oi*rhs.e31oi-lhs.e31oi*rhs.e12oi;
    result.b.e31 = -lhs.e12oi*rhs.e23oi+lhs.e23oi*rhs.e12oi;
    result.b.e12 = lhs.e31oi*rhs.e23oi-lhs.e23oi*rhs.e31oi;
    result.b.e1o = -lhs.e123o*rhs.e23oi+lhs.e23oi*rhs.e123o;
    result.b.e2o = -lhs.e123o*rhs.e31oi+lhs.e31oi*rhs.e123o;
    result.b.e3o = -lhs.e123o*rhs.e12oi+lhs.e12oi*rhs.e123o;
    result.b.e1i = lhs.e123i*rhs.e23oi-lhs.e23oi*rhs.e123i;
    result.b.e2i = lhs.e123i*rhs.e31oi-lhs.e31oi*rhs.e123i;
    result.b.e3i = lhs.e123i*rhs.e12oi-lhs.e12oi*rhs.e123i;
    result.b.eoi = lhs.e123o*rhs.e123i-lhs.e123i*rhs.e123o;
    return result;
}

Bivector outer(const Quadvector &lhs, const Quadvector &rhs)
{
    Bivector result;
    result.e23 = lhs.e12oi*rhs.e31oi-lhs.e31oi*rhs.e12oi;
    result.e31 = -lhs.e12oi*rhs.e23oi+lhs.e23oi*rhs.e12oi;
    result.e12 = lhs.e31oi*rhs.e23oi-lhs.e23oi*rhs.e31oi;
    result.e1o = -lhs.e123o*rhs.e23oi+lhs.e23oi*rhs.e123o;
    result.e2o = -lhs.e123o*rhs.e31oi+lhs.e31oi*rhs.e123o;
    result.e3o = -lhs.e123o*rhs.e12oi+lhs.e12oi*rhs.e123o;
    result.e1i = lhs.e123i*rhs.e23oi-lhs.e23oi*rhs.e123i;
    result.e2i = lhs.e123i*rhs.e31oi-lhs.e31oi*rhs.e123i;
    result.e3i = lhs.e123i*rhs.e12oi-lhs.e12oi*rhs.e123i;
    result.eoi = lhs.e123o*rhs.e123i-lhs.e123i*rhs.e123o;
    return result;
}

double inner(const Quadvector &lhs, const Quadvector &rhs)
{
    double result;
    result = -lhs.e123o*rhs.e123i-lhs.e123i*rhs.e123o-lhs.e12oi*rhs.e12oi-lhs.e31oi*rhs.e31oi-lhs.e23oi*rhs.e23oi;
    return result;
}

Versor operator*(const Quadvector &lhs, const Bivector &rhs)
{
    Versor result;
    result.b.e23 = lhs.e123o*rhs.e1i+lhs.e123i*rhs.e1o+lhs.e23oi*rhs.eoi;
    result.b.e31 = lhs.e123o*rhs.e2i+lhs.e123i*rhs.e2o+lhs.e31oi*rhs.eoi;
    result.b.e12 = lhs.e123o*rhs.e3i+lhs.e123i*rhs.e3o+lhs.e12oi*rhs.eoi;
    result.b.e1o = -lhs.e123o*rhs.e23-lhs.e12oi*rhs.e2o+lhs.e31oi*rhs.e3o;
    result.b.e2o = -lhs.e123o*rhs.e31+lhs.e12oi*rhs.e1o-lhs.e23oi*rhs.e3o;
    result.b.e3o = -lhs.e123o*rhs.e12-lhs.e31oi*rhs.e1o+lhs.e23oi*rhs.e2o;
    result.b.e1i = -lhs.e123i*rhs.e23+lhs.e12oi*rhs.e2i-lhs.e31oi*rhs.e3i;
    result.b.e2i = -lhs.e123i*rhs.e31-lhs.e12oi*rhs.e1i+lhs.e23oi*rhs.e3i;
    result.b.e3i = -lhs.e123i*rhs.e12+lhs.e31oi*rhs.e1i-lhs.e23oi*rhs.e2i;
    result.b.eoi = -lhs.e12oi*rhs.e12-lhs.e31oi*rhs.e31-lhs.e23oi*rhs.e23;
    result.q.e123o = lhs.e123o*rhs.eoi-lhs.e12oi*rhs.e3o-lhs.e31oi*rhs.e2o-lhs.e23oi*rhs.e1o;
    result.q.e123i = -lhs.e123i*rhs.eoi+lhs.e12oi*rhs.e3i+lhs.e31oi*rhs.e2i+lhs.e23oi*rhs.e1i;
    result.q.e23oi = -lhs.e123o*rhs.e1i+lhs.e123i*rhs.e1o+lhs.e12oi*rhs.e31-lhs.e31oi*rhs.e12;
    result.q.e31oi = -lhs.e123o*rhs.e2i+lhs.e123i*rhs.e2o-lhs.e12oi*rhs.e23+lhs.e23oi*rhs.e12;
    result.q.e12oi = -lhs.e123o*rhs.e3i+lhs.e123i*rhs.e3o+lhs.e31oi*rhs.e23-lhs.e23oi*rhs.e31;
    return result;
}

Quadvector outer(const Quadvector &lhs, const Bivector &rhs)
{
    Quadvector result;
    result.e123o = lhs.e123o*rhs.eoi-lhs.e12oi*rhs.e3o-lhs.e31oi*rhs.e2o-lhs.e23oi*rhs.e1o;
    result.e123i = -lhs.e123i*rhs.eoi+lhs.e12oi*rhs.e3i+lhs.e31oi*rhs.e2i+lhs.e23oi*rhs.e1i;
    result.e23oi = -lhs.e123o*rhs.e1i+lhs.e123i*rhs.e1o+lhs.e12oi*rhs.e31-lhs.e31oi*rhs.e12;
    result.e31oi = -lhs.e123o*rhs.e2i+lhs.e123i*rhs.e2o-lhs.e12oi*rhs.e23+lhs.e23oi*rhs.e12;
    result.e12oi = -lhs.e123o*rhs.e3i+lhs.e123i*rhs.e3o+lhs.e31oi*rhs.e23-lhs.e23oi*rhs.e31;
    return result;
}

Bivector inner(const Quadvector &lhs, const Bivector &rhs)
{
    Bivector result;
    result.e23 = lhs.e123o*rhs.e1i+lhs.e123i*rhs.e1o+lhs.e23oi*rhs.eoi;
    result.e31 = lhs.e123o*rhs.e2i+lhs.e123i*rhs.e2o+lhs.e31oi*rhs.eoi;
    result.e12 = lhs.e123o*rhs.e3i+lhs.e123i*rhs.e3o+lhs.e12oi*rhs.eoi;
    result.e1o = -lhs.e123o*rhs.e23-lhs.e12oi*rhs.e2o+lhs.e31oi*rhs.e3o;
    result.e2o = -lhs.e123o*rhs.e31+lhs.e12oi*rhs.e1o-lhs.e23oi*rhs.e3o;
    result.e3o = -lhs.e123o*rhs.e12-lhs.e31oi*rhs.e1o+lhs.e23oi*rhs.e2o;
    result.e1i = -lhs.e123i*rhs.e23+lhs.e12oi*rhs.e2i-lhs.e31oi*rhs.e3i;
    result.e2i = -lhs.e123i*rhs.e31-lhs.e12oi*rhs.e1i+lhs.e23oi*rhs.e3i;
    result.e3i = -lhs.e123i*rhs.e12+lhs.e31oi*rhs.e1i-lhs.e23oi*rhs.e2i;
    result.eoi = -lhs.e12oi*rhs.e12-lhs.e31oi*rhs.e31-lhs.e23oi*rhs.e23;
    return result;
}

Multivector operator*(const Quadvector &lhs, const Trivector &rhs)
{
    Multivector result;
    result.v.e1 = lhs.e123o*rhs.e23i+lhs.e123i*rhs.e23o+lhs.e12oi*rhs.e2oi-lhs.e31oi*rhs.e3oi;
    result.v.e2 = lhs.e123o*rhs.e31i+lhs.e123i*rhs.e31o-lhs.e12oi*rhs.e1oi+lhs.e23oi*rhs.e3oi;
    result.v.e3 = lhs.e123o*rhs.e12i+lhs.e123i*rhs.e12o+lhs.e31oi*rhs.e1oi-lhs.e23oi*rhs.e2oi;
    result.v.eo = -0.5*lhs.e123i*rhs.e123+0.5*lhs.e12oi*rhs.e12i+0.5*lhs.e31oi*rhs.e31i+0.5*lhs.e23oi*rhs.e23i;
    result.v.ei = lhs.e123i*rhs.e123-lhs.e12oi*rhs.e12i-lhs.e31oi*rhs.e31i-lhs.e23oi*rhs.e23i;
    result.t.e123 = lhs.e12oi*rhs.e3oi+lhs.e31oi*rhs.e2oi+lhs.e23oi*rhs.e1oi;
    result.t.e23o = -lhs.e123o*rhs.e1oi-lhs.e12oi*rhs.e31o+lhs.e31oi*rhs.e12o;
    result.t.e31o = -lhs.e123o*rhs.e2oi+lhs.e12oi*rhs.e23o-lhs.e23oi*rhs.e12o;
    result.t.e12o = -lhs.e123o*rhs.e3oi-lhs.e31oi*rhs.e23o+lhs.e23oi*rhs.e31o;
    result.t.e23i = lhs.e123i*rhs.e1oi+lhs.e12oi*rhs.e31i-lhs.e31oi*rhs.e12i;
    result.t.e31i = lhs.e123i*rhs.e2oi-lhs.e12oi*rhs.e23i+lhs.e23oi*rhs.e12i;
    result.t.e12i = lhs.e123i*rhs.e3oi+lhs.e31oi*rhs.e23i-lhs.e23oi*rhs.e31i;
    result.t.e1oi = -lhs.e123o*rhs.e23i+lhs.e123i*rhs.e23o-lhs.e23oi*rhs.e123;
    result.t.e2oi = -lhs.e123o*rhs.e31i+lhs.e123i*rhs.e31o-lhs.e31oi*rhs.e123;
    result.t.e3oi = -lhs.e123o*rhs.e12i+lhs.e123i*rhs.e12o-lhs.e12oi*rhs.e123;
    return result;
}

Trivector outer(const Quadvector &lhs, const Trivector &rhs)
{
    Trivector result;
    result.e123 = lhs.e12oi*rhs.e3oi+lhs.e31oi*rhs.e2oi+lhs.e23oi*rhs.e1oi;
    result.e23o = -lhs.e123o*rhs.e1oi-lhs.e12oi*rhs.e31o+lhs.e31oi*rhs.e12o;
    result.e31o = -lhs.e123o*rhs.e2oi+lhs.e12oi*rhs.e23o-lhs.e23oi*rhs.e12o;
    result.e12o = -lhs.e123o*rhs.e3oi-lhs.e31oi*rhs.e23o+lhs.e23oi*rhs.e31o;
    result.e23i = lhs.e123i*rhs.e1oi+lhs.e12oi*rhs.e31i-lhs.e31oi*rhs.e12i;
    result.e31i = lhs.e123i*rhs.e2oi-lhs.e12oi*rhs.e23i+lhs.e23oi*rhs.e12i;
    result.e12i = lhs.e123i*rhs.e3oi+lhs.e31oi*rhs.e23i-lhs.e23oi*rhs.e31i;
    result.e1oi = -lhs.e123o*rhs.e23i+lhs.e123i*rhs.e23o-lhs.e23oi*rhs.e123;
    result.e2oi = -lhs.e123o*rhs.e31i+lhs.e123i*rhs.e31o-lhs.e31oi*rhs.e123;
    result.e3oi = -lhs.e123o*rhs.e12i+lhs.e123i*rhs.e12o-lhs.e12oi*rhs.e123;
    return result;
}

Vector inner(const Quadvector &lhs, const Trivector &rhs)
{
    Vector result;
    result.e1 = lhs.e123o*rhs.e23i+lhs.e123i*rhs.e23o+lhs.e12oi*rhs.e2oi-lhs.e31oi*rhs.e3oi;
    result.e2 = lhs.e123o*rhs.e31i+lhs.e123i*rhs.e31o-lhs.e12oi*rhs.e1oi+lhs.e23oi*rhs.e3oi;
    result.e3 = lhs.e123o*rhs.e12i+lhs.e123i*rhs.e12o+lhs.e31oi*rhs.e1oi-lhs.e23oi*rhs.e2oi;
    result.eo = -0.5*lhs.e123i*rhs.e123+0.5*lhs.e12oi*rhs.e12i+0.5*lhs.e31oi*rhs.e31i+0.5*lhs.e23oi*rhs.e23i;
    result.ei = lhs.e123i*rhs.e123-lhs.e12oi*rhs.e12i-lhs.e31oi*rhs.e31i-lhs.e23oi*rhs.e23i;
    return result;
}

Versor operator*(const Quadvector &lhs, const Rotor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o+lhs.e31oi*rhs.b.eoi;
    result.b.e12 = lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.b.eoi;
    result.b.e1o = -lhs.e123o*rhs.b.e23-lhs.e12oi*rhs.b.e2o+lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -lhs.e123o*rhs.b.e31+lhs.e12oi*rhs.b.e1o-lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -lhs.e123o*rhs.b.e12-lhs.e31oi*rhs.b.e1o+lhs.e23oi*rhs.b.e2o;
    result.b.e1i = -lhs.e123i*rhs.b.e23+lhs.e12oi*rhs.b.e2i-lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -lhs.e123i*rhs.b.e31-lhs.e12oi*rhs.b.e1i+lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -lhs.e123i*rhs.b.e12+lhs.e31oi*rhs.b.e1i-lhs.e23oi*rhs.b.e2i;
    result.b.eoi = -lhs.e12oi*rhs.b.e12-lhs.e31oi*rhs.b.e31-lhs.e23oi*rhs.b.e23;
    result.q.e123o = lhs.e123o*rhs.s+lhs.e123o*rhs.b.eoi-lhs.e12oi*rhs.b.e3o-lhs.e31oi*rhs.b.e2o-lhs.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.e123i*rhs.s-lhs.e123i*rhs.b.eoi+lhs.e12oi*rhs.b.e3i+lhs.e31oi*rhs.b.e2i+lhs.e23oi*rhs.b.e1i;
    result.q.e23oi = -lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.b.e31-lhs.e31oi*rhs.b.e12+lhs.e23oi*rhs.s;
    result.q.e31oi = -lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.b.e23+lhs.e31oi*rhs.s+lhs.e23oi*rhs.b.e12;
    result.q.e12oi = -lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.s+lhs.e31oi*rhs.b.e23-lhs.e23oi*rhs.b.e31;
    return result;
}

Quadvector outer(const Quadvector &lhs, const Rotor &rhs)
{
    Quadvector result;
    result.e123o = lhs.e123o*rhs.s+lhs.e123o*rhs.b.eoi-lhs.e12oi*rhs.b.e3o-lhs.e31oi*rhs.b.e2o-lhs.e23oi*rhs.b.e1o;
    result.e123i = lhs.e123i*rhs.s-lhs.e123i*rhs.b.eoi+lhs.e12oi*rhs.b.e3i+lhs.e31oi*rhs.b.e2i+lhs.e23oi*rhs.b.e1i;
    result.e23oi = -lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.b.e31-lhs.e31oi*rhs.b.e12+lhs.e23oi*rhs.s;
    result.e31oi = -lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.b.e23+lhs.e31oi*rhs.s+lhs.e23oi*rhs.b.e12;
    result.e12oi = -lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.s+lhs.e31oi*rhs.b.e23-lhs.e23oi*rhs.b.e31;
    return result;
}

Versor inner(const Quadvector &lhs, const Rotor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o+lhs.e31oi*rhs.b.eoi;
    result.b.e12 = lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.b.eoi;
    result.b.e1o = -lhs.e123o*rhs.b.e23-lhs.e12oi*rhs.b.e2o+lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -lhs.e123o*rhs.b.e31+lhs.e12oi*rhs.b.e1o-lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -lhs.e123o*rhs.b.e12-lhs.e31oi*rhs.b.e1o+lhs.e23oi*rhs.b.e2o;
    result.b.e1i = -lhs.e123i*rhs.b.e23+lhs.e12oi*rhs.b.e2i-lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -lhs.e123i*rhs.b.e31-lhs.e12oi*rhs.b.e1i+lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -lhs.e123i*rhs.b.e12+lhs.e31oi*rhs.b.e1i-lhs.e23oi*rhs.b.e2i;
    result.b.eoi = -lhs.e12oi*rhs.b.e12-lhs.e31oi*rhs.b.e31-lhs.e23oi*rhs.b.e23;
    result.q.e123o = lhs.e123o*rhs.s;
    result.q.e123i = lhs.e123i*rhs.s;
    result.q.e23oi = lhs.e23oi*rhs.s;
    result.q.e31oi = lhs.e31oi*rhs.s;
    result.q.e12oi = lhs.e12oi*rhs.s;
    return result;
}

Versor operator*(const Quadvector &lhs, const Versor &rhs)
{
    Versor result;
    result.s = -lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o-lhs.e12oi*rhs.q.e12oi-lhs.e31oi*rhs.q.e31oi-lhs.e23oi*rhs.q.e23oi;
    result.b.e23 = lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.q.e31oi-lhs.e31oi*rhs.q.e12oi+lhs.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.q.e23oi+lhs.e31oi*rhs.b.eoi+lhs.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.b.eoi+lhs.e31oi*rhs.q.e23oi-lhs.e23oi*rhs.q.e31oi;
    result.b.e1o = -lhs.e123o*rhs.b.e23-lhs.e123o*rhs.q.e23oi-lhs.e12oi*rhs.b.e2o+lhs.e31oi*rhs.b.e3o+lhs.e23oi*rhs.q.e123o;
    result.b.e2o = -lhs.e123o*rhs.b.e31-lhs.e123o*rhs.q.e31oi+lhs.e12oi*rhs.b.e1o+lhs.e31oi*rhs.q.e123o-lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -lhs.e123o*rhs.b.e12-lhs.e123o*rhs.q.e12oi+lhs.e12oi*rhs.q.e123o-lhs.e31oi*rhs.b.e1o+lhs.e23oi*rhs.b.e2o;
    result.b.e1i = -lhs.e123i*rhs.b.e23+lhs.e123i*rhs.q.e23oi+lhs.e12oi*rhs.b.e2i-lhs.e31oi*rhs.b.e3i-lhs.e23oi*rhs.q.e123i;
    result.b.e2i = -lhs.e123i*rhs.b.e31+lhs.e123i*rhs.q.e31oi-lhs.e12oi*rhs.b.e1i-lhs.e31oi*rhs.q.e123i+lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -lhs.e123i*rhs.b.e12+lhs.e123i*rhs.q.e12oi-lhs.e12oi*rhs.q.e123i+lhs.e31oi*rhs.b.e1i-lhs.e23oi*rhs.b.e2i;
    result.b.eoi = lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o-lhs.e12oi*rhs.b.e12-lhs.e31oi*rhs.b.e31-lhs.e23oi*rhs.b.e23;
    result.q.e123o = lhs.e123o*rhs.s+lhs.e123o*rhs.b.eoi-lhs.e12oi*rhs.b.e3o-lhs.e31oi*rhs.b.e2o-lhs.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.e123i*rhs.s-lhs.e123i*rhs.b.eoi+lhs.e12oi*rhs.b.e3i+lhs.e31oi*rhs.b.e2i+lhs.e23oi*rhs.b.e1i;
    result.q.e23oi = -lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.b.e31-lhs.e31oi*rhs.b.e12+lhs.e23oi*rhs.s;
    result.q.e31oi = -lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.b.e23+lhs.e31oi*rhs.s+lhs.e23oi*rhs.b.e12;
    result.q.e12oi = -lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.s+lhs.e31oi*rhs.b.e23-lhs.e23oi*rhs.b.e31;
    return result;
}

Versor outer(const Quadvector &lhs, const Versor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e12oi*rhs.q.e31oi-lhs.e31oi*rhs.q.e12oi;
    result.b.e31 = -lhs.e12oi*rhs.q.e23oi+lhs.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.e31oi*rhs.q.e23oi-lhs.e23oi*rhs.q.e31oi;
    result.b.e1o = -lhs.e123o*rhs.q.e23oi+lhs.e23oi*rhs.q.e123o;
    result.b.e2o = -lhs.e123o*rhs.q.e31oi+lhs.e31oi*rhs.q.e123o;
    result.b.e3o = -lhs.e123o*rhs.q.e12oi+lhs.e12oi*rhs.q.e123o;
    result.b.e1i = lhs.e123i*rhs.q.e23oi-lhs.e23oi*rhs.q.e123i;
    result.b.e2i = lhs.e123i*rhs.q.e31oi-lhs.e31oi*rhs.q.e123i;
    result.b.e3i = lhs.e123i*rhs.q.e12oi-lhs.e12oi*rhs.q.e123i;
    result.b.eoi = lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o;
    result.q.e123o = lhs.e123o*rhs.s+lhs.e123o*rhs.b.eoi-lhs.e12oi*rhs.b.e3o-lhs.e31oi*rhs.b.e2o-lhs.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.e123i*rhs.s-lhs.e123i*rhs.b.eoi+lhs.e12oi*rhs.b.e3i+lhs.e31oi*rhs.b.e2i+lhs.e23oi*rhs.b.e1i;
    result.q.e23oi = -lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.b.e31-lhs.e31oi*rhs.b.e12+lhs.e23oi*rhs.s;
    result.q.e31oi = -lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.b.e23+lhs.e31oi*rhs.s+lhs.e23oi*rhs.b.e12;
    result.q.e12oi = -lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.s+lhs.e31oi*rhs.b.e23-lhs.e23oi*rhs.b.e31;
    return result;
}

Versor inner(const Quadvector &lhs, const Versor &rhs)
{
    Versor result;
    result.s = -lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o-lhs.e12oi*rhs.q.e12oi-lhs.e31oi*rhs.q.e31oi-lhs.e23oi*rhs.q.e23oi;
    result.b.e23 = lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o+lhs.e31oi*rhs.b.eoi;
    result.b.e12 = lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.b.eoi;
    result.b.e1o = -lhs.e123o*rhs.b.e23-lhs.e12oi*rhs.b.e2o+lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -lhs.e123o*rhs.b.e31+lhs.e12oi*rhs.b.e1o-lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -lhs.e123o*rhs.b.e12-lhs.e31oi*rhs.b.e1o+lhs.e23oi*rhs.b.e2o;
    result.b.e1i = -lhs.e123i*rhs.b.e23+lhs.e12oi*rhs.b.e2i-lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -lhs.e123i*rhs.b.e31-lhs.e12oi*rhs.b.e1i+lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -lhs.e123i*rhs.b.e12+lhs.e31oi*rhs.b.e1i-lhs.e23oi*rhs.b.e2i;
    result.b.eoi = -lhs.e12oi*rhs.b.e12-lhs.e31oi*rhs.b.e31-lhs.e23oi*rhs.b.e23;
    result.q.e123o = lhs.e123o*rhs.s;
    result.q.e123i = lhs.e123i*rhs.s;
    result.q.e23oi = lhs.e23oi*rhs.s;
    result.q.e31oi = lhs.e31oi*rhs.s;
    result.q.e12oi = lhs.e12oi*rhs.s;
    return result;
}

Multivector operator*(const Quadvector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o-lhs.e12oi*rhs.q.e12oi-lhs.e31oi*rhs.q.e31oi-lhs.e23oi*rhs.q.e23oi;
    result.v.e1 = lhs.e123o*rhs.t.e23i+lhs.e123i*rhs.t.e23o+lhs.e12oi*rhs.t.e2oi-lhs.e31oi*rhs.t.e3oi-lhs.e23oi*rhs.p;
    result.v.e2 = lhs.e123o*rhs.t.e31i+lhs.e123i*rhs.t.e31o-lhs.e12oi*rhs.t.e1oi-lhs.e31oi*rhs.p+lhs.e23oi*rhs.t.e3oi;
    result.v.e3 = lhs.e123o*rhs.t.e12i+lhs.e123i*rhs.t.e12o-lhs.e12oi*rhs.p+lhs.e31oi*rhs.t.e1oi-lhs.e23oi*rhs.t.e2oi;
    result.v.eo = -0.5*lhs.e123i*rhs.t.e123+0.5*lhs.e123i*rhs.p+0.5*lhs.e12oi*rhs.t.e12i+0.5*lhs.e31oi*rhs.t.e31i+0.5*lhs.e23oi*rhs.t.e23i;
    result.v.ei = lhs.e123i*rhs.t.e123-lhs.e123i*rhs.p-lhs.e12oi*rhs.t.e12i-lhs.e31oi*rhs.t.e31i-lhs.e23oi*rhs.t.e23i;
    result.b.e23 = lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.q.e31oi-lhs.e31oi*rhs.q.e12oi+lhs.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.q.e23oi+lhs.e31oi*rhs.b.eoi+lhs.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.b.eoi+lhs.e31oi*rhs.q.e23oi-lhs.e23oi*rhs.q.e31oi;
    result.b.e1o = -lhs.e123o*rhs.b.e23-lhs.e123o*rhs.q.e23oi-lhs.e12oi*rhs.b.e2o+lhs.e31oi*rhs.b.e3o+lhs.e23oi*rhs.q.e123o;
    result.b.e2o = -lhs.e123o*rhs.b.e31-lhs.e123o*rhs.q.e31oi+lhs.e12oi*rhs.b.e1o+lhs.e31oi*rhs.q.e123o-lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -lhs.e123o*rhs.b.e12-lhs.e123o*rhs.q.e12oi+lhs.e12oi*rhs.q.e123o-lhs.e31oi*rhs.b.e1o+lhs.e23oi*rhs.b.e2o;
    result.b.e1i = -lhs.e123i*rhs.b.e23+lhs.e123i*rhs.q.e23oi+lhs.e12oi*rhs.b.e2i-lhs.e31oi*rhs.b.e3i-lhs.e23oi*rhs.q.e123i;
    result.b.e2i = -lhs.e123i*rhs.b.e31+lhs.e123i*rhs.q.e31oi-lhs.e12oi*rhs.b.e1i-lhs.e31oi*rhs.q.e123i+lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -lhs.e123i*rhs.b.e12+lhs.e123i*rhs.q.e12oi-lhs.e12oi*rhs.q.e123i+lhs.e31oi*rhs.b.e1i-lhs.e23oi*rhs.b.e2i;
    result.b.eoi = lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o-lhs.e12oi*rhs.b.e12-lhs.e31oi*rhs.b.e31-lhs.e23oi*rhs.b.e23;
    result.t.e123 = -lhs.e123o*rhs.v.ei-lhs.e123i*rhs.v.eo+lhs.e12oi*rhs.t.e3oi+lhs.e31oi*rhs.t.e2oi+lhs.e23oi*rhs.t.e1oi;
    result.t.e23o = -lhs.e123o*rhs.v.e1-lhs.e123o*rhs.t.e1oi-lhs.e12oi*rhs.t.e31o+lhs.e31oi*rhs.t.e12o-lhs.e23oi*rhs.v.eo;
    result.t.e31o = -lhs.e123o*rhs.v.e2-lhs.e123o*rhs.t.e2oi+lhs.e12oi*rhs.t.e23o-lhs.e31oi*rhs.v.eo-lhs.e23oi*rhs.t.e12o;
    result.t.e12o = -lhs.e123o*rhs.v.e3-lhs.e123o*rhs.t.e3oi-lhs.e12oi*rhs.v.eo-lhs.e31oi*rhs.t.e23o+lhs.e23oi*rhs.t.e31o;
    result.t.e23i = -lhs.e123i*rhs.v.e1+lhs.e123i*rhs.t.e1oi+lhs.e12oi*rhs.t.e31i-lhs.e31oi*rhs.t.e12i+lhs.e23oi*rhs.v.ei;
    result.t.e31i = -lhs.e123i*rhs.v.e2+lhs.e123i*rhs.t.e2oi-lhs.e12oi*rhs.t.e23i+lhs.e31oi*rhs.v.ei+lhs.e23oi*rhs.t.e12i;
    result.t.e12i = -lhs.e123i*rhs.v.e3+lhs.e123i*rhs.t.e3oi+lhs.e12oi*rhs.v.ei+lhs.e31oi*rhs.t.e23i-lhs.e23oi*rhs.t.e31i;
    result.t.e1oi = -lhs.e123o*rhs.t.e23i+lhs.e123i*rhs.t.e23o+lhs.e12oi*rhs.v.e2-lhs.e31oi*rhs.v.e3-lhs.e23oi*rhs.t.e123;
    result.t.e2oi = -lhs.e123o*rhs.t.e31i+lhs.e123i*rhs.t.e31o-lhs.e12oi*rhs.v.e1-lhs.e31oi*rhs.t.e123+lhs.e23oi*rhs.v.e3;
    result.t.e3oi = -lhs.e123o*rhs.t.e12i+lhs.e123i*rhs.t.e12o-lhs.e12oi*rhs.t.e123+lhs.e31oi*rhs.v.e1-lhs.e23oi*rhs.v.e2;
    result.q.e123o = lhs.e123o*rhs.s+lhs.e123o*rhs.b.eoi-lhs.e12oi*rhs.b.e3o-lhs.e31oi*rhs.b.e2o-lhs.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.e123i*rhs.s-lhs.e123i*rhs.b.eoi+lhs.e12oi*rhs.b.e3i+lhs.e31oi*rhs.b.e2i+lhs.e23oi*rhs.b.e1i;
    result.q.e23oi = -lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.b.e31-lhs.e31oi*rhs.b.e12+lhs.e23oi*rhs.s;
    result.q.e31oi = -lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.b.e23+lhs.e31oi*rhs.s+lhs.e23oi*rhs.b.e12;
    result.q.e12oi = -lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.s+lhs.e31oi*rhs.b.e23-lhs.e23oi*rhs.b.e31;
    result.p = lhs.e123o*rhs.v.ei-lhs.e123i*rhs.v.eo+lhs.e12oi*rhs.v.e3+lhs.e31oi*rhs.v.e2+lhs.e23oi*rhs.v.e1;
    return result;
}

Multivector outer(const Quadvector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e23oi*rhs.p;
    result.v.e2 = -lhs.e31oi*rhs.p;
    result.v.e3 = -lhs.e12oi*rhs.p;
    result.v.eo = 0.5*lhs.e123i*rhs.p;
    result.v.ei = -lhs.e123i*rhs.p;
    result.b.e23 = lhs.e12oi*rhs.q.e31oi-lhs.e31oi*rhs.q.e12oi;
    result.b.e31 = -lhs.e12oi*rhs.q.e23oi+lhs.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.e31oi*rhs.q.e23oi-lhs.e23oi*rhs.q.e31oi;
    result.b.e1o = -lhs.e123o*rhs.q.e23oi+lhs.e23oi*rhs.q.e123o;
    result.b.e2o = -lhs.e123o*rhs.q.e31oi+lhs.e31oi*rhs.q.e123o;
    result.b.e3o = -lhs.e123o*rhs.q.e12oi+lhs.e12oi*rhs.q.e123o;
    result.b.e1i = lhs.e123i*rhs.q.e23oi-lhs.e23oi*rhs.q.e123i;
    result.b.e2i = lhs.e123i*rhs.q.e31oi-lhs.e31oi*rhs.q.e123i;
    result.b.e3i = lhs.e123i*rhs.q.e12oi-lhs.e12oi*rhs.q.e123i;
    result.b.eoi = lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o;
    result.t.e123 = lhs.e12oi*rhs.t.e3oi+lhs.e31oi*rhs.t.e2oi+lhs.e23oi*rhs.t.e1oi;
    result.t.e23o = -lhs.e123o*rhs.t.e1oi-lhs.e12oi*rhs.t.e31o+lhs.e31oi*rhs.t.e12o;
    result.t.e31o = -lhs.e123o*rhs.t.e2oi+lhs.e12oi*rhs.t.e23o-lhs.e23oi*rhs.t.e12o;
    result.t.e12o = -lhs.e123o*rhs.t.e3oi-lhs.e31oi*rhs.t.e23o+lhs.e23oi*rhs.t.e31o;
    result.t.e23i = lhs.e123i*rhs.t.e1oi+lhs.e12oi*rhs.t.e31i-lhs.e31oi*rhs.t.e12i;
    result.t.e31i = lhs.e123i*rhs.t.e2oi-lhs.e12oi*rhs.t.e23i+lhs.e23oi*rhs.t.e12i;
    result.t.e12i = lhs.e123i*rhs.t.e3oi+lhs.e31oi*rhs.t.e23i-lhs.e23oi*rhs.t.e31i;
    result.t.e1oi = -lhs.e123o*rhs.t.e23i+lhs.e123i*rhs.t.e23o-lhs.e23oi*rhs.t.e123;
    result.t.e2oi = -lhs.e123o*rhs.t.e31i+lhs.e123i*rhs.t.e31o-lhs.e31oi*rhs.t.e123;
    result.t.e3oi = -lhs.e123o*rhs.t.e12i+lhs.e123i*rhs.t.e12o-lhs.e12oi*rhs.t.e123;
    result.q.e123o = lhs.e123o*rhs.s+lhs.e123o*rhs.b.eoi-lhs.e12oi*rhs.b.e3o-lhs.e31oi*rhs.b.e2o-lhs.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.e123i*rhs.s-lhs.e123i*rhs.b.eoi+lhs.e12oi*rhs.b.e3i+lhs.e31oi*rhs.b.e2i+lhs.e23oi*rhs.b.e1i;
    result.q.e23oi = -lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e12oi*rhs.b.e31-lhs.e31oi*rhs.b.e12+lhs.e23oi*rhs.s;
    result.q.e31oi = -lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o-lhs.e12oi*rhs.b.e23+lhs.e31oi*rhs.s+lhs.e23oi*rhs.b.e12;
    result.q.e12oi = -lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.s+lhs.e31oi*rhs.b.e23-lhs.e23oi*rhs.b.e31;
    result.p = lhs.e123o*rhs.v.ei-lhs.e123i*rhs.v.eo+lhs.e12oi*rhs.v.e3+lhs.e31oi*rhs.v.e2+lhs.e23oi*rhs.v.e1;
    return result;
}

Multivector inner(const Quadvector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e123o*rhs.q.e123i-lhs.e123i*rhs.q.e123o-lhs.e12oi*rhs.q.e12oi-lhs.e31oi*rhs.q.e31oi-lhs.e23oi*rhs.q.e23oi;
    result.v.e1 = lhs.e123o*rhs.t.e23i+lhs.e123i*rhs.t.e23o+lhs.e12oi*rhs.t.e2oi-lhs.e31oi*rhs.t.e3oi-lhs.e23oi*rhs.p;
    result.v.e2 = lhs.e123o*rhs.t.e31i+lhs.e123i*rhs.t.e31o-lhs.e12oi*rhs.t.e1oi-lhs.e31oi*rhs.p+lhs.e23oi*rhs.t.e3oi;
    result.v.e3 = lhs.e123o*rhs.t.e12i+lhs.e123i*rhs.t.e12o-lhs.e12oi*rhs.p+lhs.e31oi*rhs.t.e1oi-lhs.e23oi*rhs.t.e2oi;
    result.v.eo = -0.5*lhs.e123i*rhs.t.e123+0.5*lhs.e123i*rhs.p+0.5*lhs.e12oi*rhs.t.e12i+0.5*lhs.e31oi*rhs.t.e31i+0.5*lhs.e23oi*rhs.t.e23i;
    result.v.ei = lhs.e123i*rhs.t.e123-lhs.e123i*rhs.p-lhs.e12oi*rhs.t.e12i-lhs.e31oi*rhs.t.e31i-lhs.e23oi*rhs.t.e23i;
    result.b.e23 = lhs.e123o*rhs.b.e1i+lhs.e123i*rhs.b.e1o+lhs.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.e123o*rhs.b.e2i+lhs.e123i*rhs.b.e2o+lhs.e31oi*rhs.b.eoi;
    result.b.e12 = lhs.e123o*rhs.b.e3i+lhs.e123i*rhs.b.e3o+lhs.e12oi*rhs.b.eoi;
    result.b.e1o = -lhs.e123o*rhs.b.e23-lhs.e12oi*rhs.b.e2o+lhs.e31oi*rhs.b.e3o;
    result.b.e2o = -lhs.e123o*rhs.b.e31+lhs.e12oi*rhs.b.e1o-lhs.e23oi*rhs.b.e3o;
    result.b.e3o = -lhs.e123o*rhs.b.e12-lhs.e31oi*rhs.b.e1o+lhs.e23oi*rhs.b.e2o;
    result.b.e1i = -lhs.e123i*rhs.b.e23+lhs.e12oi*rhs.b.e2i-lhs.e31oi*rhs.b.e3i;
    result.b.e2i = -lhs.e123i*rhs.b.e31-lhs.e12oi*rhs.b.e1i+lhs.e23oi*rhs.b.e3i;
    result.b.e3i = -lhs.e123i*rhs.b.e12+lhs.e31oi*rhs.b.e1i-lhs.e23oi*rhs.b.e2i;
    result.b.eoi = -lhs.e12oi*rhs.b.e12-lhs.e31oi*rhs.b.e31-lhs.e23oi*rhs.b.e23;
    result.t.e123 = -lhs.e123o*rhs.v.ei-lhs.e123i*rhs.v.eo;
    result.t.e23o = -lhs.e123o*rhs.v.e1-lhs.e23oi*rhs.v.eo;
    result.t.e31o = -lhs.e123o*rhs.v.e2-lhs.e31oi*rhs.v.eo;
    result.t.e12o = -lhs.e123o*rhs.v.e3-lhs.e12oi*rhs.v.eo;
    result.t.e23i = -lhs.e123i*rhs.v.e1+lhs.e23oi*rhs.v.ei;
    result.t.e31i = -lhs.e123i*rhs.v.e2+lhs.e31oi*rhs.v.ei;
    result.t.e12i = -lhs.e123i*rhs.v.e3+lhs.e12oi*rhs.v.ei;
    result.t.e1oi = lhs.e12oi*rhs.v.e2-lhs.e31oi*rhs.v.e3;
    result.t.e2oi = -lhs.e12oi*rhs.v.e1+lhs.e23oi*rhs.v.e3;
    result.t.e3oi = lhs.e31oi*rhs.v.e1-lhs.e23oi*rhs.v.e2;
    result.q.e123o = lhs.e123o*rhs.s;
    result.q.e123i = lhs.e123i*rhs.s;
    result.q.e23oi = lhs.e23oi*rhs.s;
    result.q.e31oi = lhs.e31oi*rhs.s;
    result.q.e12oi = lhs.e12oi*rhs.s;
    return result;
}

Versor operator*(const Bivector &lhs, const Bivector &rhs)
{
    Versor result;
    result.s = -lhs.e12*rhs.e12-lhs.e31*rhs.e31+lhs.e1o*rhs.e1i+lhs.e1i*rhs.e1o-lhs.e23*rhs.e23+lhs.e2o*rhs.e2i+lhs.e2i*rhs.e2o+lhs.e3o*rhs.e3i+lhs.e3i*rhs.e3o+lhs.eoi*rhs.eoi;
    result.b.e23 = lhs.e12*rhs.e31-lhs.e31*rhs.e12+lhs.e2o*rhs.e3i+lhs.e2i*rhs.e3o-lhs.e3o*rhs.e2i-lhs.e3i*rhs.e2o;
    result.b.e31 = -lhs.e12*rhs.e23-lhs.e1o*rhs.e3i-lhs.e1i*rhs.e3o+lhs.e23*rhs.e12+lhs.e3o*rhs.e1i+lhs.e3i*rhs.e1o;
    result.b.e12 = lhs.e31*rhs.e23+lhs.e1o*rhs.e2i+lhs.e1i*rhs.e2o-lhs.e23*rhs.e31-lhs.e2o*rhs.e1i-lhs.e2i*rhs.e1o;
    result.b.e1o = lhs.e12*rhs.e2o-lhs.e31*rhs.e3o+lhs.e1o*rhs.eoi-lhs.e2o*rhs.e12+lhs.e3o*rhs.e31-lhs.eoi*rhs.e1o;
    result.b.e2o = -lhs.e12*rhs.e1o+lhs.e1o*rhs.e12+lhs.e23*rhs.e3o+lhs.e2o*rhs.eoi-lhs.e3o*rhs.e23-lhs.eoi*rhs.e2o;
    result.b.e3o = lhs.e31*rhs.e1o-lhs.e1o*rhs.e31-lhs.e23*rhs.e2o+lhs.e2o*rhs.e23+lhs.e3o*rhs.eoi-lhs.eoi*rhs.e3o;
    result.b.e1i = lhs.e12*rhs.e2i-lhs.e31*rhs.e3i-lhs.e1i*rhs.eoi-lhs.e2i*rhs.e12+lhs.e3i*rhs.e31+lhs.eoi*rhs.e1i;
    result.b.e2i = -lhs.e12*rhs.e1i+lhs.e1i*rhs.e12+lhs.e23*rhs.e3i-lhs.e2i*rhs.eoi-lhs.e3i*rhs.e23+lhs.eoi*rhs.e2i;
    result.b.e3i = lhs.e31*rhs.e1i-lhs.e1i*rhs.e31-lhs.e23*rhs.e2i+lhs.e2i*rhs.e23-lhs.e3i*rhs.eoi+lhs.eoi*rhs.e3i;
    result.b.eoi = -lhs.e1o*rhs.e1i+lhs.e1i*rhs.e1o-lhs.e2o*rhs.e2i+lhs.e2i*rhs.e2o-lhs.e3o*rhs.e3i+lhs.e3i*rhs.e3o;
    result.q.e123o = lhs.e12*rhs.e3o+lhs.e31*rhs.e2o+lhs.e1o*rhs.e23+lhs.e23*rhs.e1o+lhs.e2o*rhs.e31+lhs.e3o*rhs.e12;
    result.q.e123i = lhs.e12*rhs.e3i+lhs.e31*rhs.e2i+lhs.e1i*rhs.e23+lhs.e23*rhs.e1i+lhs.e2i*rhs.e31+lhs.e3i*rhs.e12;
    result.q.e23oi = lhs.e23*rhs.eoi-lhs.e2o*rhs.e3i+lhs.e2i*rhs.e3o+lhs.e3o*rhs.e2i-lhs.e3i*rhs.e2o+lhs.eoi*rhs.e23;
    result.q.e31oi = lhs.e31*rhs.eoi+lhs.e1o*rhs.e3i-lhs.e1i*rhs.e3o-lhs.e3o*rhs.e1i+lhs.e3i*rhs.e1o+lhs.eoi*rhs.e31;
    result.q.e12oi = lhs.e12*rhs.eoi-lhs.e1o*rhs.e2i+lhs.e1i*rhs.e2o+lhs.e2o*rhs.e1i-lhs.e2i*rhs.e1o+lhs.eoi*rhs.e12;
    return result;
}

Quadvector outer(const Bivector &lhs, const Bivector &rhs)
{
    Quadvector result;
    result.e123o = lhs.e12*rhs.e3o+lhs.e31*rhs.e2o+lhs.e1o*rhs.e23+lhs.e23*rhs.e1o+lhs.e2o*rhs.e31+lhs.e3o*rhs.e12;
    result.e123i = lhs.e12*rhs.e3i+lhs.e31*rhs.e2i+lhs.e1i*rhs.e23+lhs.e23*rhs.e1i+lhs.e2i*rhs.e31+lhs.e3i*rhs.e12;
    result.e23oi = lhs.e23*rhs.eoi-lhs.e2o*rhs.e3i+lhs.e2i*rhs.e3o+lhs.e3o*rhs.e2i-lhs.e3i*rhs.e2o+lhs.eoi*rhs.e23;
    result.e31oi = lhs.e31*rhs.eoi+lhs.e1o*rhs.e3i-lhs.e1i*rhs.e3o-lhs.e3o*rhs.e1i+lhs.e3i*rhs.e1o+lhs.eoi*rhs.e31;
    result.e12oi = lhs.e12*rhs.eoi-lhs.e1o*rhs.e2i+lhs.e1i*rhs.e2o+lhs.e2o*rhs.e1i-lhs.e2i*rhs.e1o+lhs.eoi*rhs.e12;
    return result;
}

double inner(const Bivector &lhs, const Bivector &rhs)
{
    double result;
    result = -lhs.e12*rhs.e12-lhs.e31*rhs.e31+lhs.e1o*rhs.e1i+lhs.e1i*rhs.e1o-lhs.e23*rhs.e23+lhs.e2o*rhs.e2i+lhs.e2i*rhs.e2o+lhs.e3o*rhs.e3i+lhs.e3i*rhs.e3o+lhs.eoi*rhs.eoi;
    return result;
}

Multivector operator*(const Bivector &lhs, const Trivector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e23*rhs.e123+lhs.e2o*rhs.e12i+lhs.e2i*rhs.e12o-lhs.e3o*rhs.e31i-lhs.e3i*rhs.e31o+lhs.eoi*rhs.e1oi;
    result.v.e2 = -lhs.e31*rhs.e123-lhs.e1o*rhs.e12i-lhs.e1i*rhs.e12o+lhs.e3o*rhs.e23i+lhs.e3i*rhs.e23o+lhs.eoi*rhs.e2oi;
    result.v.e3 = -lhs.e12*rhs.e123+lhs.e1o*rhs.e31i+lhs.e1i*rhs.e31o-lhs.e2o*rhs.e23i-lhs.e2i*rhs.e23o+lhs.eoi*rhs.e3oi;
    result.v.eo = 0.5*lhs.e12*rhs.e12i+0.5*lhs.e31*rhs.e31i-0.5*lhs.e1i*rhs.e1oi+0.5*lhs.e23*rhs.e23i-0.5*lhs.e2i*rhs.e2oi-0.5*lhs.e3i*rhs.e3oi;
    result.v.ei = -lhs.e12*rhs.e12i-lhs.e31*rhs.e31i+lhs.e1i*rhs.e1oi-lhs.e23*rhs.e23i+lhs.e2i*rhs.e2oi+lhs.e3i*rhs.e3oi;
    result.t.e123 = -lhs.e1o*rhs.e23i-lhs.e1i*rhs.e23o-lhs.e2o*rhs.e31i-lhs.e2i*rhs.e31o-lhs.e3o*rhs.e12i-lhs.e3i*rhs.e12o;
    result.t.e23o = lhs.e12*rhs.e31o-lhs.e31*rhs.e12o-lhs.e1o*rhs.e123-lhs.e2o*rhs.e3oi+lhs.e3o*rhs.e2oi-lhs.eoi*rhs.e23o;
    result.t.e31o = -lhs.e12*rhs.e23o+lhs.e1o*rhs.e3oi+lhs.e23*rhs.e12o-lhs.e2o*rhs.e123-lhs.e3o*rhs.e1oi-lhs.eoi*rhs.e31o;
    result.t.e12o = lhs.e31*rhs.e23o-lhs.e1o*rhs.e2oi-lhs.e23*rhs.e31o+lhs.e2o*rhs.e1oi-lhs.e3o*rhs.e123-lhs.eoi*rhs.e12o;
    result.t.e23i = lhs.e12*rhs.e31i-lhs.e31*rhs.e12i-lhs.e1i*rhs.e123+lhs.e2i*rhs.e3oi-lhs.e3i*rhs.e2oi+lhs.eoi*rhs.e23i;
    result.t.e31i = -lhs.e12*rhs.e23i-lhs.e1i*rhs.e3oi+lhs.e23*rhs.e12i-lhs.e2i*rhs.e123+lhs.e3i*rhs.e1oi+lhs.eoi*rhs.e31i;
    result.t.e12i = lhs.e31*rhs.e23i+lhs.e1i*rhs.e2oi-lhs.e23*rhs.e31i-lhs.e2i*rhs.e1oi-lhs.e3i*rhs.e123+lhs.eoi*rhs.e12i;
    result.t.e1oi = lhs.e12*rhs.e2oi-lhs.e31*rhs.e3oi-lhs.e2o*rhs.e12i+lhs.e2i*rhs.e12o+lhs.e3o*rhs.e31i-lhs.e3i*rhs.e31o;
    result.t.e2oi = -lhs.e12*rhs.e1oi+lhs.e1o*rhs.e12i-lhs.e1i*rhs.e12o+lhs.e23*rhs.e3oi-lhs.e3o*rhs.e23i+lhs.e3i*rhs.e23o;
    result.t.e3oi = lhs.e31*rhs.e1oi-lhs.e1o*rhs.e31i+lhs.e1i*rhs.e31o-lhs.e23*rhs.e2oi+lhs.e2o*rhs.e23i-lhs.e2i*rhs.e23o;
    result.p = lhs.e12*rhs.e3oi+lhs.e31*rhs.e2oi+lhs.e1o*rhs.e23i-lhs.e1i*rhs.e23o+lhs.e23*rhs.e1oi+lhs.e2o*rhs.e31i-lhs.e2i*rhs.e31o+lhs.e3o*rhs.e12i-lhs.e3i*rhs.e12o+lhs.eoi*rhs.e123;
    return result;
}

Pseudoscalar outer(const Bivector &lhs, const Trivector &rhs)
{
    Pseudoscalar result;
    result.p = lhs.e12*rhs.e3oi+lhs.e31*rhs.e2oi+lhs.e1o*rhs.e23i-lhs.e1i*rhs.e23o+lhs.e23*rhs.e1oi+lhs.e2o*rhs.e31i-lhs.e2i*rhs.e31o+lhs.e3o*rhs.e12i-lhs.e3i*rhs.e12o+lhs.eoi*rhs.e123;
    return result;
}

Vector inner(const Bivector &lhs, const Trivector &rhs)
{
    Vector result;
    result.e1 = -lhs.e23*rhs.e123+lhs.e2o*rhs.e12i+lhs.e2i*rhs.e12o-lhs.e3o*rhs.e31i-lhs.e3i*rhs.e31o+lhs.eoi*rhs.e1oi;
    result.e2 = -lhs.e31*rhs.e123-lhs.e1o*rhs.e12i-lhs.e1i*rhs.e12o+lhs.e3o*rhs.e23i+lhs.e3i*rhs.e23o+lhs.eoi*rhs.e2oi;
    result.e3 = -lhs.e12*rhs.e123+lhs.e1o*rhs.e31i+lhs.e1i*rhs.e31o-lhs.e2o*rhs.e23i-lhs.e2i*rhs.e23o+lhs.eoi*rhs.e3oi;
    result.eo = 0.5*lhs.e12*rhs.e12i+0.5*lhs.e31*rhs.e31i-0.5*lhs.e1i*rhs.e1oi+0.5*lhs.e23*rhs.e23i-0.5*lhs.e2i*rhs.e2oi-0.5*lhs.e3i*rhs.e3oi;
    result.ei = -lhs.e12*rhs.e12i-lhs.e31*rhs.e31i+lhs.e1i*rhs.e1oi-lhs.e23*rhs.e23i+lhs.e2i*rhs.e2oi+lhs.e3i*rhs.e3oi;
    return result;
}

Versor operator*(const Bivector &lhs, const Rotor &rhs)
{
    Versor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31+lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.b.e23+lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o+lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.b.eoi;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e23*rhs.s+lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o-lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s-lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.b.e12+lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23+lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.b.e31-lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o;
    result.b.e1o = lhs.e12*rhs.b.e2o-lhs.e31*rhs.b.e3o+lhs.e1o*rhs.s+lhs.e1o*rhs.b.eoi-lhs.e2o*rhs.b.e12+lhs.e3o*rhs.b.e31-lhs.eoi*rhs.b.e1o;
    result.b.e2o = -lhs.e12*rhs.b.e1o+lhs.e1o*rhs.b.e12+lhs.e23*rhs.b.e3o+lhs.e2o*rhs.s+lhs.e2o*rhs.b.eoi-lhs.e3o*rhs.b.e23-lhs.eoi*rhs.b.e2o;
    result.b.e3o = lhs.e31*rhs.b.e1o-lhs.e1o*rhs.b.e31-lhs.e23*rhs.b.e2o+lhs.e2o*rhs.b.e23+lhs.e3o*rhs.s+lhs.e3o*rhs.b.eoi-lhs.eoi*rhs.b.e3o;
    result.b.e1i = lhs.e12*rhs.b.e2i-lhs.e31*rhs.b.e3i+lhs.e1i*rhs.s-lhs.e1i*rhs.b.eoi-lhs.e2i*rhs.b.e12+lhs.e3i*rhs.b.e31+lhs.eoi*rhs.b.e1i;
    result.b.e2i = -lhs.e12*rhs.b.e1i+lhs.e1i*rhs.b.e12+lhs.e23*rhs.b.e3i+lhs.e2i*rhs.s-lhs.e2i*rhs.b.eoi-lhs.e3i*rhs.b.e23+lhs.eoi*rhs.b.e2i;
    result.b.e3i = lhs.e31*rhs.b.e1i-lhs.e1i*rhs.b.e31-lhs.e23*rhs.b.e2i+lhs.e2i*rhs.b.e23+lhs.e3i*rhs.s-lhs.e3i*rhs.b.eoi+lhs.eoi*rhs.b.e3i;
    result.b.eoi = -lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o-lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.s;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e1o*rhs.b.e23+lhs.e23*rhs.b.e1o+lhs.e2o*rhs.b.e31+lhs.e3o*rhs.b.e12;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e1i*rhs.b.e23+lhs.e23*rhs.b.e1i+lhs.e2i*rhs.b.e31+lhs.e3i*rhs.b.e12;
    result.q.e23oi = lhs.e23*rhs.b.eoi-lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o+lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.b.e23;
    result.q.e31oi = lhs.e31*rhs.b.eoi+lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o-lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.b.e31;
    result.q.e12oi = lhs.e12*rhs.b.eoi-lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o+lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o+lhs.eoi*rhs.b.e12;
    return result;
}

Versor outer(const Bivector &lhs, const Rotor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.b.e1o = lhs.e1o*rhs.s;
    result.b.e2o = lhs.e2o*rhs.s;
    result.b.e3o = lhs.e3o*rhs.s;
    result.b.e1i = lhs.e1i*rhs.s;
    result.b.e2i = lhs.e2i*rhs.s;
    result.b.e3i = lhs.e3i*rhs.s;
    result.b.eoi = lhs.eoi*rhs.s;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e1o*rhs.b.e23+lhs.e23*rhs.b.e1o+lhs.e2o*rhs.b.e31+lhs.e3o*rhs.b.e12;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e1i*rhs.b.e23+lhs.e23*rhs.b.e1i+lhs.e2i*rhs.b.e31+lhs.e3i*rhs.b.e12;
    result.q.e23oi = lhs.e23*rhs.b.eoi-lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o+lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.b.e23;
    result.q.e31oi = lhs.e31*rhs.b.eoi+lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o-lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.b.e31;
    result.q.e12oi = lhs.e12*rhs.b.eoi-lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o+lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o+lhs.eoi*rhs.b.e12;
    return result;
}

Rotor inner(const Bivector &lhs, const Rotor &rhs)
{
    Rotor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31+lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.b.e23+lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o+lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.b.eoi;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.b.e1o = lhs.e1o*rhs.s;
    result.b.e2o = lhs.e2o*rhs.s;
    result.b.e3o = lhs.e3o*rhs.s;
    result.b.e1i = lhs.e1i*rhs.s;
    result.b.e2i = lhs.e2i*rhs.s;
    result.b.e3i = lhs.e3i*rhs.s;
    result.b.eoi = lhs.eoi*rhs.s;
    return result;
}

Versor operator*(const Bivector &lhs, const Versor &rhs)
{
    Versor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31+lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.b.e23+lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o+lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.b.eoi;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.s+lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o-lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.q.e23oi;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s-lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.b.e12+lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o+lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23+lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.b.e31-lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o+lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.e12*rhs.b.e2o-lhs.e31*rhs.b.e3o+lhs.e1o*rhs.s+lhs.e1o*rhs.b.eoi-lhs.e23*rhs.q.e123o-lhs.e2o*rhs.b.e12-lhs.e2o*rhs.q.e12oi+lhs.e3o*rhs.b.e31+lhs.e3o*rhs.q.e31oi-lhs.eoi*rhs.b.e1o;
    result.b.e2o = -lhs.e12*rhs.b.e1o-lhs.e31*rhs.q.e123o+lhs.e1o*rhs.b.e12+lhs.e1o*rhs.q.e12oi+lhs.e23*rhs.b.e3o+lhs.e2o*rhs.s+lhs.e2o*rhs.b.eoi-lhs.e3o*rhs.b.e23-lhs.e3o*rhs.q.e23oi-lhs.eoi*rhs.b.e2o;
    result.b.e3o = -lhs.e12*rhs.q.e123o+lhs.e31*rhs.b.e1o-lhs.e1o*rhs.b.e31-lhs.e1o*rhs.q.e31oi-lhs.e23*rhs.b.e2o+lhs.e2o*rhs.b.e23+lhs.e2o*rhs.q.e23oi+lhs.e3o*rhs.s+lhs.e3o*rhs.b.eoi-lhs.eoi*rhs.b.e3o;
    result.b.e1i = lhs.e12*rhs.b.e2i-lhs.e31*rhs.b.e3i+lhs.e1i*rhs.s-lhs.e1i*rhs.b.eoi-lhs.e23*rhs.q.e123i-lhs.e2i*rhs.b.e12+lhs.e2i*rhs.q.e12oi+lhs.e3i*rhs.b.e31-lhs.e3i*rhs.q.e31oi+lhs.eoi*rhs.b.e1i;
    result.b.e2i = -lhs.e12*rhs.b.e1i-lhs.e31*rhs.q.e123i+lhs.e1i*rhs.b.e12-lhs.e1i*rhs.q.e12oi+lhs.e23*rhs.b.e3i+lhs.e2i*rhs.s-lhs.e2i*rhs.b.eoi-lhs.e3i*rhs.b.e23+lhs.e3i*rhs.q.e23oi+lhs.eoi*rhs.b.e2i;
    result.b.e3i = -lhs.e12*rhs.q.e123i+lhs.e31*rhs.b.e1i-lhs.e1i*rhs.b.e31+lhs.e1i*rhs.q.e31oi-lhs.e23*rhs.b.e2i+lhs.e2i*rhs.b.e23-lhs.e2i*rhs.q.e23oi+lhs.e3i*rhs.s-lhs.e3i*rhs.b.eoi+lhs.eoi*rhs.b.e3i;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.q.e23oi-lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o-lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.s;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e1o*rhs.b.e23+lhs.e1o*rhs.q.e23oi+lhs.e23*rhs.b.e1o+lhs.e2o*rhs.b.e31+lhs.e2o*rhs.q.e31oi+lhs.e3o*rhs.b.e12+lhs.e3o*rhs.q.e12oi-lhs.eoi*rhs.q.e123o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e1i*rhs.b.e23-lhs.e1i*rhs.q.e23oi+lhs.e23*rhs.b.e1i+lhs.e2i*rhs.b.e31-lhs.e2i*rhs.q.e31oi+lhs.e3i*rhs.b.e12-lhs.e3i*rhs.q.e12oi+lhs.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi-lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.b.eoi-lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o+lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.b.e23;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.q.e12oi-lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o-lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.b.e31;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.q.e31oi+lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o-lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.b.e12;
    return result;
}

Versor outer(const Bivector &lhs, const Versor &rhs)
{
    Versor result;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.b.e1o = lhs.e1o*rhs.s;
    result.b.e2o = lhs.e2o*rhs.s;
    result.b.e3o = lhs.e3o*rhs.s;
    result.b.e1i = lhs.e1i*rhs.s;
    result.b.e2i = lhs.e2i*rhs.s;
    result.b.e3i = lhs.e3i*rhs.s;
    result.b.eoi = lhs.eoi*rhs.s;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e1o*rhs.b.e23+lhs.e1o*rhs.q.e23oi+lhs.e23*rhs.b.e1o+lhs.e2o*rhs.b.e31+lhs.e2o*rhs.q.e31oi+lhs.e3o*rhs.b.e12+lhs.e3o*rhs.q.e12oi-lhs.eoi*rhs.q.e123o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e1i*rhs.b.e23-lhs.e1i*rhs.q.e23oi+lhs.e23*rhs.b.e1i+lhs.e2i*rhs.b.e31-lhs.e2i*rhs.q.e31oi+lhs.e3i*rhs.b.e12-lhs.e3i*rhs.q.e12oi+lhs.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi-lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.b.eoi-lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o+lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.b.e23;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.q.e12oi-lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o-lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.b.e31;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.q.e31oi+lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o-lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.b.e12;
    return result;
}

Rotor inner(const Bivector &lhs, const Versor &rhs)
{
    Rotor result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31+lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.b.e23+lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o+lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.b.eoi;
    result.b.e23 = lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.s+lhs.eoi*rhs.q.e23oi;
    result.b.e31 = lhs.e31*rhs.s+lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o+lhs.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.e12*rhs.s+lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.e1o*rhs.s-lhs.e23*rhs.q.e123o-lhs.e2o*rhs.q.e12oi+lhs.e3o*rhs.q.e31oi;
    result.b.e2o = -lhs.e31*rhs.q.e123o+lhs.e1o*rhs.q.e12oi+lhs.e2o*rhs.s-lhs.e3o*rhs.q.e23oi;
    result.b.e3o = -lhs.e12*rhs.q.e123o-lhs.e1o*rhs.q.e31oi+lhs.e2o*rhs.q.e23oi+lhs.e3o*rhs.s;
    result.b.e1i = lhs.e1i*rhs.s-lhs.e23*rhs.q.e123i+lhs.e2i*rhs.q.e12oi-lhs.e3i*rhs.q.e31oi;
    result.b.e2i = -lhs.e31*rhs.q.e123i-lhs.e1i*rhs.q.e12oi+lhs.e2i*rhs.s+lhs.e3i*rhs.q.e23oi;
    result.b.e3i = -lhs.e12*rhs.q.e123i+lhs.e1i*rhs.q.e31oi-lhs.e2i*rhs.q.e23oi+lhs.e3i*rhs.s;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e23*rhs.q.e23oi+lhs.eoi*rhs.s;
    return result;
}

Multivector operator*(const Bivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31+lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.b.e23+lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o+lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.b.eoi;
    result.v.e1 = lhs.e12*rhs.v.e2-lhs.e31*rhs.v.e3-lhs.e1o*rhs.v.ei-lhs.e1i*rhs.v.eo-lhs.e23*rhs.t.e123+lhs.e2o*rhs.t.e12i+lhs.e2i*rhs.t.e12o-lhs.e3o*rhs.t.e31i-lhs.e3i*rhs.t.e31o+lhs.eoi*rhs.t.e1oi;
    result.v.e2 = -lhs.e12*rhs.v.e1-lhs.e31*rhs.t.e123-lhs.e1o*rhs.t.e12i-lhs.e1i*rhs.t.e12o+lhs.e23*rhs.v.e3-lhs.e2o*rhs.v.ei-lhs.e2i*rhs.v.eo+lhs.e3o*rhs.t.e23i+lhs.e3i*rhs.t.e23o+lhs.eoi*rhs.t.e2oi;
    result.v.e3 = -lhs.e12*rhs.t.e123+lhs.e31*rhs.v.e1+lhs.e1o*rhs.t.e31i+lhs.e1i*rhs.t.e31o-lhs.e23*rhs.v.e2-lhs.e2o*rhs.t.e23i-lhs.e2i*rhs.t.e23o-lhs.e3o*rhs.v.ei-lhs.e3i*rhs.v.eo+lhs.eoi*rhs.t.e3oi;
    result.v.eo = 0.5*lhs.e12*rhs.t.e12i+0.5*lhs.e31*rhs.t.e31i+0.5*lhs.e1i*rhs.v.e1-0.5*lhs.e1i*rhs.t.e1oi+0.5*lhs.e23*rhs.t.e23i+0.5*lhs.e2i*rhs.v.e2-0.5*lhs.e2i*rhs.t.e2oi+0.5*lhs.e3i*rhs.v.e3-0.5*lhs.e3i*rhs.t.e3oi-0.5*lhs.eoi*rhs.v.ei;
    result.v.ei = -lhs.e12*rhs.t.e12i-lhs.e31*rhs.t.e31i-lhs.e1i*rhs.v.e1+lhs.e1i*rhs.t.e1oi-lhs.e23*rhs.t.e23i-lhs.e2i*rhs.v.e2+lhs.e2i*rhs.t.e2oi-lhs.e3i*rhs.v.e3+lhs.e3i*rhs.t.e3oi+lhs.eoi*rhs.v.ei;
    result.b.e23 = lhs.e12*rhs.b.e31-lhs.e31*rhs.b.e12+lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.s+lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o-lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.q.e23oi;
    result.b.e31 = -lhs.e12*rhs.b.e23+lhs.e31*rhs.s-lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.b.e12+lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o+lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.e12*rhs.s+lhs.e31*rhs.b.e23+lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.b.e31-lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o+lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.e12*rhs.b.e2o-lhs.e31*rhs.b.e3o+lhs.e1o*rhs.s+lhs.e1o*rhs.b.eoi-lhs.e23*rhs.q.e123o-lhs.e2o*rhs.b.e12-lhs.e2o*rhs.q.e12oi+lhs.e3o*rhs.b.e31+lhs.e3o*rhs.q.e31oi-lhs.eoi*rhs.b.e1o;
    result.b.e2o = -lhs.e12*rhs.b.e1o-lhs.e31*rhs.q.e123o+lhs.e1o*rhs.b.e12+lhs.e1o*rhs.q.e12oi+lhs.e23*rhs.b.e3o+lhs.e2o*rhs.s+lhs.e2o*rhs.b.eoi-lhs.e3o*rhs.b.e23-lhs.e3o*rhs.q.e23oi-lhs.eoi*rhs.b.e2o;
    result.b.e3o = -lhs.e12*rhs.q.e123o+lhs.e31*rhs.b.e1o-lhs.e1o*rhs.b.e31-lhs.e1o*rhs.q.e31oi-lhs.e23*rhs.b.e2o+lhs.e2o*rhs.b.e23+lhs.e2o*rhs.q.e23oi+lhs.e3o*rhs.s+lhs.e3o*rhs.b.eoi-lhs.eoi*rhs.b.e3o;
    result.b.e1i = lhs.e12*rhs.b.e2i-lhs.e31*rhs.b.e3i+lhs.e1i*rhs.s-lhs.e1i*rhs.b.eoi-lhs.e23*rhs.q.e123i-lhs.e2i*rhs.b.e12+lhs.e2i*rhs.q.e12oi+lhs.e3i*rhs.b.e31-lhs.e3i*rhs.q.e31oi+lhs.eoi*rhs.b.e1i;
    result.b.e2i = -lhs.e12*rhs.b.e1i-lhs.e31*rhs.q.e123i+lhs.e1i*rhs.b.e12-lhs.e1i*rhs.q.e12oi+lhs.e23*rhs.b.e3i+lhs.e2i*rhs.s-lhs.e2i*rhs.b.eoi-lhs.e3i*rhs.b.e23+lhs.e3i*rhs.q.e23oi+lhs.eoi*rhs.b.e2i;
    result.b.e3i = -lhs.e12*rhs.q.e123i+lhs.e31*rhs.b.e1i-lhs.e1i*rhs.b.e31+lhs.e1i*rhs.q.e31oi-lhs.e23*rhs.b.e2i+lhs.e2i*rhs.b.e23-lhs.e2i*rhs.q.e23oi+lhs.e3i*rhs.s-lhs.e3i*rhs.b.eoi+lhs.eoi*rhs.b.e3i;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.q.e23oi-lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o-lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.s;
    result.t.e123 = lhs.e12*rhs.v.e3+lhs.e31*rhs.v.e2-lhs.e1o*rhs.t.e23i-lhs.e1i*rhs.t.e23o+lhs.e23*rhs.v.e1-lhs.e2o*rhs.t.e31i-lhs.e2i*rhs.t.e31o-lhs.e3o*rhs.t.e12i-lhs.e3i*rhs.t.e12o+lhs.eoi*rhs.p;
    result.t.e23o = lhs.e12*rhs.t.e31o-lhs.e31*rhs.t.e12o-lhs.e1o*rhs.t.e123-lhs.e1o*rhs.p+lhs.e23*rhs.v.eo-lhs.e2o*rhs.v.e3-lhs.e2o*rhs.t.e3oi+lhs.e3o*rhs.v.e2+lhs.e3o*rhs.t.e2oi-lhs.eoi*rhs.t.e23o;
    result.t.e31o = -lhs.e12*rhs.t.e23o+lhs.e31*rhs.v.eo+lhs.e1o*rhs.v.e3+lhs.e1o*rhs.t.e3oi+lhs.e23*rhs.t.e12o-lhs.e2o*rhs.t.e123-lhs.e2o*rhs.p-lhs.e3o*rhs.v.e1-lhs.e3o*rhs.t.e1oi-lhs.eoi*rhs.t.e31o;
    result.t.e12o = lhs.e12*rhs.v.eo+lhs.e31*rhs.t.e23o-lhs.e1o*rhs.v.e2-lhs.e1o*rhs.t.e2oi-lhs.e23*rhs.t.e31o+lhs.e2o*rhs.v.e1+lhs.e2o*rhs.t.e1oi-lhs.e3o*rhs.t.e123-lhs.e3o*rhs.p-lhs.eoi*rhs.t.e12o;
    result.t.e23i = lhs.e12*rhs.t.e31i-lhs.e31*rhs.t.e12i-lhs.e1i*rhs.t.e123+lhs.e1i*rhs.p+lhs.e23*rhs.v.ei-lhs.e2i*rhs.v.e3+lhs.e2i*rhs.t.e3oi+lhs.e3i*rhs.v.e2-lhs.e3i*rhs.t.e2oi+lhs.eoi*rhs.t.e23i;
    result.t.e31i = -lhs.e12*rhs.t.e23i+lhs.e31*rhs.v.ei+lhs.e1i*rhs.v.e3-lhs.e1i*rhs.t.e3oi+lhs.e23*rhs.t.e12i-lhs.e2i*rhs.t.e123+lhs.e2i*rhs.p-lhs.e3i*rhs.v.e1+lhs.e3i*rhs.t.e1oi+lhs.eoi*rhs.t.e31i;
    result.t.e12i = lhs.e12*rhs.v.ei+lhs.e31*rhs.t.e23i-lhs.e1i*rhs.v.e2+lhs.e1i*rhs.t.e2oi-lhs.e23*rhs.t.e31i+lhs.e2i*rhs.v.e1-lhs.e2i*rhs.t.e1oi-lhs.e3i*rhs.t.e123+lhs.e3i*rhs.p+lhs.eoi*rhs.t.e12i;
    result.t.e1oi = lhs.e12*rhs.t.e2oi-lhs.e31*rhs.t.e3oi+lhs.e1o*rhs.v.ei-lhs.e1i*rhs.v.eo-lhs.e23*rhs.p-lhs.e2o*rhs.t.e12i+lhs.e2i*rhs.t.e12o+lhs.e3o*rhs.t.e31i-lhs.e3i*rhs.t.e31o+lhs.eoi*rhs.v.e1;
    result.t.e2oi = -lhs.e12*rhs.t.e1oi-lhs.e31*rhs.p+lhs.e1o*rhs.t.e12i-lhs.e1i*rhs.t.e12o+lhs.e23*rhs.t.e3oi+lhs.e2o*rhs.v.ei-lhs.e2i*rhs.v.eo-lhs.e3o*rhs.t.e23i+lhs.e3i*rhs.t.e23o+lhs.eoi*rhs.v.e2;
    result.t.e3oi = -lhs.e12*rhs.p+lhs.e31*rhs.t.e1oi-lhs.e1o*rhs.t.e31i+lhs.e1i*rhs.t.e31o-lhs.e23*rhs.t.e2oi+lhs.e2o*rhs.t.e23i-lhs.e2i*rhs.t.e23o+lhs.e3o*rhs.v.ei-lhs.e3i*rhs.v.eo+lhs.eoi*rhs.v.e3;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e1o*rhs.b.e23+lhs.e1o*rhs.q.e23oi+lhs.e23*rhs.b.e1o+lhs.e2o*rhs.b.e31+lhs.e2o*rhs.q.e31oi+lhs.e3o*rhs.b.e12+lhs.e3o*rhs.q.e12oi-lhs.eoi*rhs.q.e123o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e1i*rhs.b.e23-lhs.e1i*rhs.q.e23oi+lhs.e23*rhs.b.e1i+lhs.e2i*rhs.b.e31-lhs.e2i*rhs.q.e31oi+lhs.e3i*rhs.b.e12-lhs.e3i*rhs.q.e12oi+lhs.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi-lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.b.eoi-lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o+lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.b.e23;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.q.e12oi-lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o-lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.b.e31;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.q.e31oi+lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o-lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.b.e12;
    result.p = lhs.e12*rhs.t.e3oi+lhs.e31*rhs.t.e2oi+lhs.e1o*rhs.t.e23i-lhs.e1i*rhs.t.e23o+lhs.e23*rhs.t.e1oi+lhs.e2o*rhs.t.e31i-lhs.e2i*rhs.t.e31o+lhs.e3o*rhs.t.e12i-lhs.e3i*rhs.t.e12o+lhs.eoi*rhs.t.e123;
    return result;
}

Multivector outer(const Bivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.b.e23 = lhs.e23*rhs.s;
    result.b.e31 = lhs.e31*rhs.s;
    result.b.e12 = lhs.e12*rhs.s;
    result.b.e1o = lhs.e1o*rhs.s;
    result.b.e2o = lhs.e2o*rhs.s;
    result.b.e3o = lhs.e3o*rhs.s;
    result.b.e1i = lhs.e1i*rhs.s;
    result.b.e2i = lhs.e2i*rhs.s;
    result.b.e3i = lhs.e3i*rhs.s;
    result.b.eoi = lhs.eoi*rhs.s;
    result.t.e123 = lhs.e12*rhs.v.e3+lhs.e31*rhs.v.e2+lhs.e23*rhs.v.e1+lhs.eoi*rhs.p;
    result.t.e23o = -lhs.e1o*rhs.p+lhs.e23*rhs.v.eo-lhs.e2o*rhs.v.e3+lhs.e3o*rhs.v.e2;
    result.t.e31o = lhs.e31*rhs.v.eo+lhs.e1o*rhs.v.e3-lhs.e2o*rhs.p-lhs.e3o*rhs.v.e1;
    result.t.e12o = lhs.e12*rhs.v.eo-lhs.e1o*rhs.v.e2+lhs.e2o*rhs.v.e1-lhs.e3o*rhs.p;
    result.t.e23i = lhs.e1i*rhs.p+lhs.e23*rhs.v.ei-lhs.e2i*rhs.v.e3+lhs.e3i*rhs.v.e2;
    result.t.e31i = lhs.e31*rhs.v.ei+lhs.e1i*rhs.v.e3+lhs.e2i*rhs.p-lhs.e3i*rhs.v.e1;
    result.t.e12i = lhs.e12*rhs.v.ei-lhs.e1i*rhs.v.e2+lhs.e2i*rhs.v.e1+lhs.e3i*rhs.p;
    result.t.e1oi = lhs.e1o*rhs.v.ei-lhs.e1i*rhs.v.eo-lhs.e23*rhs.p+lhs.eoi*rhs.v.e1;
    result.t.e2oi = -lhs.e31*rhs.p+lhs.e2o*rhs.v.ei-lhs.e2i*rhs.v.eo+lhs.eoi*rhs.v.e2;
    result.t.e3oi = -lhs.e12*rhs.p+lhs.e3o*rhs.v.ei-lhs.e3i*rhs.v.eo+lhs.eoi*rhs.v.e3;
    result.q.e123o = lhs.e12*rhs.b.e3o+lhs.e31*rhs.b.e2o+lhs.e1o*rhs.b.e23+lhs.e1o*rhs.q.e23oi+lhs.e23*rhs.b.e1o+lhs.e2o*rhs.b.e31+lhs.e2o*rhs.q.e31oi+lhs.e3o*rhs.b.e12+lhs.e3o*rhs.q.e12oi-lhs.eoi*rhs.q.e123o;
    result.q.e123i = lhs.e12*rhs.b.e3i+lhs.e31*rhs.b.e2i+lhs.e1i*rhs.b.e23-lhs.e1i*rhs.q.e23oi+lhs.e23*rhs.b.e1i+lhs.e2i*rhs.b.e31-lhs.e2i*rhs.q.e31oi+lhs.e3i*rhs.b.e12-lhs.e3i*rhs.q.e12oi+lhs.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.e12*rhs.q.e31oi-lhs.e31*rhs.q.e12oi-lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.b.eoi-lhs.e2o*rhs.b.e3i+lhs.e2i*rhs.b.e3o+lhs.e3o*rhs.b.e2i-lhs.e3i*rhs.b.e2o+lhs.eoi*rhs.b.e23;
    result.q.e31oi = -lhs.e12*rhs.q.e23oi+lhs.e31*rhs.b.eoi+lhs.e1o*rhs.b.e3i-lhs.e1i*rhs.b.e3o+lhs.e23*rhs.q.e12oi-lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o-lhs.e3o*rhs.b.e1i+lhs.e3i*rhs.b.e1o+lhs.eoi*rhs.b.e31;
    result.q.e12oi = lhs.e12*rhs.b.eoi+lhs.e31*rhs.q.e23oi-lhs.e1o*rhs.b.e2i+lhs.e1i*rhs.b.e2o-lhs.e23*rhs.q.e31oi+lhs.e2o*rhs.b.e1i-lhs.e2i*rhs.b.e1o-lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.b.e12;
    result.p = lhs.e12*rhs.t.e3oi+lhs.e31*rhs.t.e2oi+lhs.e1o*rhs.t.e23i-lhs.e1i*rhs.t.e23o+lhs.e23*rhs.t.e1oi+lhs.e2o*rhs.t.e31i-lhs.e2i*rhs.t.e31o+lhs.e3o*rhs.t.e12i-lhs.e3i*rhs.t.e12o+lhs.eoi*rhs.t.e123;
    return result;
}

Multivector inner(const Bivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e12*rhs.b.e12-lhs.e31*rhs.b.e31+lhs.e1o*rhs.b.e1i+lhs.e1i*rhs.b.e1o-lhs.e23*rhs.b.e23+lhs.e2o*rhs.b.e2i+lhs.e2i*rhs.b.e2o+lhs.e3o*rhs.b.e3i+lhs.e3i*rhs.b.e3o+lhs.eoi*rhs.b.eoi;
    result.v.e1 = lhs.e12*rhs.v.e2-lhs.e31*rhs.v.e3-lhs.e1o*rhs.v.ei-lhs.e1i*rhs.v.eo-lhs.e23*rhs.t.e123+lhs.e2o*rhs.t.e12i+lhs.e2i*rhs.t.e12o-lhs.e3o*rhs.t.e31i-lhs.e3i*rhs.t.e31o+lhs.eoi*rhs.t.e1oi;
    result.v.e2 = -lhs.e12*rhs.v.e1-lhs.e31*rhs.t.e123-lhs.e1o*rhs.t.e12i-lhs.e1i*rhs.t.e12o+lhs.e23*rhs.v.e3-lhs.e2o*rhs.v.ei-lhs.e2i*rhs.v.eo+lhs.e3o*rhs.t.e23i+lhs.e3i*rhs.t.e23o+lhs.eoi*rhs.t.e2oi;
    result.v.e3 = -lhs.e12*rhs.t.e123+lhs.e31*rhs.v.e1+lhs.e1o*rhs.t.e31i+lhs.e1i*rhs.t.e31o-lhs.e23*rhs.v.e2-lhs.e2o*rhs.t.e23i-lhs.e2i*rhs.t.e23o-lhs.e3o*rhs.v.ei-lhs.e3i*rhs.v.eo+lhs.eoi*rhs.t.e3oi;
    result.v.eo = 0.5*lhs.e12*rhs.t.e12i+0.5*lhs.e31*rhs.t.e31i+0.5*lhs.e1i*rhs.v.e1-0.5*lhs.e1i*rhs.t.e1oi+0.5*lhs.e23*rhs.t.e23i+0.5*lhs.e2i*rhs.v.e2-0.5*lhs.e2i*rhs.t.e2oi+0.5*lhs.e3i*rhs.v.e3-0.5*lhs.e3i*rhs.t.e3oi-0.5*lhs.eoi*rhs.v.ei;
    result.v.ei = -lhs.e12*rhs.t.e12i-lhs.e31*rhs.t.e31i-lhs.e1i*rhs.v.e1+lhs.e1i*rhs.t.e1oi-lhs.e23*rhs.t.e23i-lhs.e2i*rhs.v.e2+lhs.e2i*rhs.t.e2oi-lhs.e3i*rhs.v.e3+lhs.e3i*rhs.t.e3oi+lhs.eoi*rhs.v.ei;
    result.b.e23 = lhs.e1o*rhs.q.e123i+lhs.e1i*rhs.q.e123o+lhs.e23*rhs.s+lhs.eoi*rhs.q.e23oi;
    result.b.e31 = lhs.e31*rhs.s+lhs.e2o*rhs.q.e123i+lhs.e2i*rhs.q.e123o+lhs.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.e12*rhs.s+lhs.e3o*rhs.q.e123i+lhs.e3i*rhs.q.e123o+lhs.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.e1o*rhs.s-lhs.e23*rhs.q.e123o-lhs.e2o*rhs.q.e12oi+lhs.e3o*rhs.q.e31oi;
    result.b.e2o = -lhs.e31*rhs.q.e123o+lhs.e1o*rhs.q.e12oi+lhs.e2o*rhs.s-lhs.e3o*rhs.q.e23oi;
    result.b.e3o = -lhs.e12*rhs.q.e123o-lhs.e1o*rhs.q.e31oi+lhs.e2o*rhs.q.e23oi+lhs.e3o*rhs.s;
    result.b.e1i = lhs.e1i*rhs.s-lhs.e23*rhs.q.e123i+lhs.e2i*rhs.q.e12oi-lhs.e3i*rhs.q.e31oi;
    result.b.e2i = -lhs.e31*rhs.q.e123i-lhs.e1i*rhs.q.e12oi+lhs.e2i*rhs.s+lhs.e3i*rhs.q.e23oi;
    result.b.e3i = -lhs.e12*rhs.q.e123i+lhs.e1i*rhs.q.e31oi-lhs.e2i*rhs.q.e23oi+lhs.e3i*rhs.s;
    result.b.eoi = -lhs.e12*rhs.q.e12oi-lhs.e31*rhs.q.e31oi-lhs.e23*rhs.q.e23oi+lhs.eoi*rhs.s;
    result.t.e123 = lhs.eoi*rhs.p;
    result.t.e23o = -lhs.e1o*rhs.p;
    result.t.e31o = -lhs.e2o*rhs.p;
    result.t.e12o = -lhs.e3o*rhs.p;
    result.t.e23i = lhs.e1i*rhs.p;
    result.t.e31i = lhs.e2i*rhs.p;
    result.t.e12i = lhs.e3i*rhs.p;
    result.t.e1oi = -lhs.e23*rhs.p;
    result.t.e2oi = -lhs.e31*rhs.p;
    result.t.e3oi = -lhs.e12*rhs.p;
    return result;
}

Versor operator*(const Trivector &lhs, const Trivector &rhs)
{
    Versor result;
    result.s = -lhs.e123*rhs.e123+lhs.e12o*rhs.e12i+lhs.e12i*rhs.e12o+lhs.e31o*rhs.e31i+lhs.e31i*rhs.e31o+lhs.e1oi*rhs.e1oi+lhs.e23o*rhs.e23i+lhs.e23i*rhs.e23o+lhs.e2oi*rhs.e2oi+lhs.e3oi*rhs.e3oi;
    result.b.e23 = -lhs.e12o*rhs.e31i-lhs.e12i*rhs.e31o+lhs.e31o*rhs.e12i+lhs.e31i*rhs.e12o+lhs.e2oi*rhs.e3oi-lhs.e3oi*rhs.e2oi;
    result.b.e31 = lhs.e12o*rhs.e23i+lhs.e12i*rhs.e23o-lhs.e1oi*rhs.e3oi-lhs.e23o*rhs.e12i-lhs.e23i*rhs.e12o+lhs.e3oi*rhs.e1oi;
    result.b.e12 = -lhs.e31o*rhs.e23i-lhs.e31i*rhs.e23o+lhs.e1oi*rhs.e2oi+lhs.e23o*rhs.e31i+lhs.e23i*rhs.e31o-lhs.e2oi*rhs.e1oi;
    result.b.e1o = -lhs.e123*rhs.e23o-lhs.e12o*rhs.e2oi+lhs.e31o*rhs.e3oi+lhs.e23o*rhs.e123+lhs.e2oi*rhs.e12o-lhs.e3oi*rhs.e31o;
    result.b.e2o = -lhs.e123*rhs.e31o+lhs.e12o*rhs.e1oi+lhs.e31o*rhs.e123-lhs.e1oi*rhs.e12o-lhs.e23o*rhs.e3oi+lhs.e3oi*rhs.e23o;
    result.b.e3o = -lhs.e123*rhs.e12o+lhs.e12o*rhs.e123-lhs.e31o*rhs.e1oi+lhs.e1oi*rhs.e31o+lhs.e23o*rhs.e2oi-lhs.e2oi*rhs.e23o;
    result.b.e1i = -lhs.e123*rhs.e23i+lhs.e12i*rhs.e2oi-lhs.e31i*rhs.e3oi+lhs.e23i*rhs.e123-lhs.e2oi*rhs.e12i+lhs.e3oi*rhs.e31i;
    result.b.e2i = -lhs.e123*rhs.e31i-lhs.e12i*rhs.e1oi+lhs.e31i*rhs.e123+lhs.e1oi*rhs.e12i+lhs.e23i*rhs.e3oi-lhs.e3oi*rhs.e23i;
    result.b.e3i = -lhs.e123*rhs.e12i+lhs.e12i*rhs.e123+lhs.e31i*rhs.e1oi-lhs.e1oi*rhs.e31i-lhs.e23i*rhs.e2oi+lhs.e2oi*rhs.e23i;
    result.b.eoi = -lhs.e12o*rhs.e12i+lhs.e12i*rhs.e12o-lhs.e31o*rhs.e31i+lhs.e31i*rhs.e31o-lhs.e23o*rhs.e23i+lhs.e23i*rhs.e23o;
    result.q.e123o = -lhs.e12o*rhs.e3oi-lhs.e31o*rhs.e2oi-lhs.e1oi*rhs.e23o-lhs.e23o*rhs.e1oi-lhs.e2oi*rhs.e31o-lhs.e3oi*rhs.e12o;
    result.q.e123i = lhs.e12i*rhs.e3oi+lhs.e31i*rhs.e2oi+lhs.e1oi*rhs.e23i+lhs.e23i*rhs.e1oi+lhs.e2oi*rhs.e31i+lhs.e3oi*rhs.e12i;
    result.q.e23oi = lhs.e123*rhs.e1oi+lhs.e12o*rhs.e31i-lhs.e12i*rhs.e31o-lhs.e31o*rhs.e12i+lhs.e31i*rhs.e12o+lhs.e1oi*rhs.e123;
    result.q.e31oi = lhs.e123*rhs.e2oi-lhs.e12o*rhs.e23i+lhs.e12i*rhs.e23o+lhs.e23o*rhs.e12i-lhs.e23i*rhs.e12o+lhs.e2oi*rhs.e123;
    result.q.e12oi = lhs.e123*rhs.e3oi+lhs.e31o*rhs.e23i-lhs.e31i*rhs.e23o-lhs.e23o*rhs.e31i+lhs.e23i*rhs.e31o+lhs.e3oi*rhs.e123;
    return result;
}

Quadvector outer(const Trivector &lhs, const Trivector &rhs)
{
    Quadvector result;
    result.e123o = -lhs.e12o*rhs.e3oi-lhs.e31o*rhs.e2oi-lhs.e1oi*rhs.e23o-lhs.e23o*rhs.e1oi-lhs.e2oi*rhs.e31o-lhs.e3oi*rhs.e12o;
    result.e123i = lhs.e12i*rhs.e3oi+lhs.e31i*rhs.e2oi+lhs.e1oi*rhs.e23i+lhs.e23i*rhs.e1oi+lhs.e2oi*rhs.e31i+lhs.e3oi*rhs.e12i;
    result.e23oi = lhs.e123*rhs.e1oi+lhs.e12o*rhs.e31i-lhs.e12i*rhs.e31o-lhs.e31o*rhs.e12i+lhs.e31i*rhs.e12o+lhs.e1oi*rhs.e123;
    result.e31oi = lhs.e123*rhs.e2oi-lhs.e12o*rhs.e23i+lhs.e12i*rhs.e23o+lhs.e23o*rhs.e12i-lhs.e23i*rhs.e12o+lhs.e2oi*rhs.e123;
    result.e12oi = lhs.e123*rhs.e3oi+lhs.e31o*rhs.e23i-lhs.e31i*rhs.e23o-lhs.e23o*rhs.e31i+lhs.e23i*rhs.e31o+lhs.e3oi*rhs.e123;
    return result;
}

double inner(const Trivector &lhs, const Trivector &rhs)
{
    double result;
    result = -lhs.e123*rhs.e123+lhs.e12o*rhs.e12i+lhs.e12i*rhs.e12o+lhs.e31o*rhs.e31i+lhs.e31i*rhs.e31o+lhs.e1oi*rhs.e1oi+lhs.e23o*rhs.e23i+lhs.e23i*rhs.e23o+lhs.e2oi*rhs.e2oi+lhs.e3oi*rhs.e3oi;
    return result;
}

Multivector operator*(const Trivector &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e123*rhs.b.e23+lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o-lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.b.eoi;
    result.v.e2 = -lhs.e123*rhs.b.e31-lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o+lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.b.eoi;
    result.v.e3 = -lhs.e123*rhs.b.e12+lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e3oi*rhs.b.eoi;
    result.v.eo = 0.5*lhs.e12i*rhs.b.e12+0.5*lhs.e31i*rhs.b.e31-0.5*lhs.e1oi*rhs.b.e1i+0.5*lhs.e23i*rhs.b.e23-0.5*lhs.e2oi*rhs.b.e2i-0.5*lhs.e3oi*rhs.b.e3i;
    result.v.ei = -lhs.e12i*rhs.b.e12-lhs.e31i*rhs.b.e31+lhs.e1oi*rhs.b.e1i-lhs.e23i*rhs.b.e23+lhs.e2oi*rhs.b.e2i+lhs.e3oi*rhs.b.e3i;
    result.t.e123 = lhs.e123*rhs.s+lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o+lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o;
    result.t.e23o = lhs.e123*rhs.b.e1o+lhs.e12o*rhs.b.e31-lhs.e31o*rhs.b.e12+lhs.e23o*rhs.s+lhs.e23o*rhs.b.eoi-lhs.e2oi*rhs.b.e3o+lhs.e3oi*rhs.b.e2o;
    result.t.e31o = lhs.e123*rhs.b.e2o-lhs.e12o*rhs.b.e23+lhs.e31o*rhs.s+lhs.e31o*rhs.b.eoi+lhs.e1oi*rhs.b.e3o+lhs.e23o*rhs.b.e12-lhs.e3oi*rhs.b.e1o;
    result.t.e12o = lhs.e123*rhs.b.e3o+lhs.e12o*rhs.s+lhs.e12o*rhs.b.eoi+lhs.e31o*rhs.b.e23-lhs.e1oi*rhs.b.e2o-lhs.e23o*rhs.b.e31+lhs.e2oi*rhs.b.e1o;
    result.t.e23i = lhs.e123*rhs.b.e1i+lhs.e12i*rhs.b.e31-lhs.e31i*rhs.b.e12+lhs.e23i*rhs.s-lhs.e23i*rhs.b.eoi+lhs.e2oi*rhs.b.e3i-lhs.e3oi*rhs.b.e2i;
    result.t.e31i = lhs.e123*rhs.b.e2i-lhs.e12i*rhs.b.e23+lhs.e31i*rhs.s-lhs.e31i*rhs.b.eoi-lhs.e1oi*rhs.b.e3i+lhs.e23i*rhs.b.e12+lhs.e3oi*rhs.b.e1i;
    result.t.e12i = lhs.e123*rhs.b.e3i+lhs.e12i*rhs.s-lhs.e12i*rhs.b.eoi+lhs.e31i*rhs.b.e23+lhs.e1oi*rhs.b.e2i-lhs.e23i*rhs.b.e31-lhs.e2oi*rhs.b.e1i;
    result.t.e1oi = -lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o+lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.s-lhs.e2oi*rhs.b.e12+lhs.e3oi*rhs.b.e31;
    result.t.e2oi = lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o+lhs.e1oi*rhs.b.e12-lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.s-lhs.e3oi*rhs.b.e23;
    result.t.e3oi = -lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.b.e31+lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.b.e23+lhs.e3oi*rhs.s;
    result.p = lhs.e123*rhs.b.eoi-lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o-lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.b.e23-lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.b.e31+lhs.e3oi*rhs.b.e12;
    return result;
}

Multivector outer(const Trivector &lhs, const Rotor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.e123*rhs.s;
    result.t.e23o = lhs.e23o*rhs.s;
    result.t.e31o = lhs.e31o*rhs.s;
    result.t.e12o = lhs.e12o*rhs.s;
    result.t.e23i = lhs.e23i*rhs.s;
    result.t.e31i = lhs.e31i*rhs.s;
    result.t.e12i = lhs.e12i*rhs.s;
    result.t.e1oi = lhs.e1oi*rhs.s;
    result.t.e2oi = lhs.e2oi*rhs.s;
    result.t.e3oi = lhs.e3oi*rhs.s;
    result.p = lhs.e123*rhs.b.eoi-lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o-lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.b.e23-lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.b.e31+lhs.e3oi*rhs.b.e12;
    return result;
}

Multivector inner(const Trivector &lhs, const Rotor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e123*rhs.b.e23+lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o-lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.b.eoi;
    result.v.e2 = -lhs.e123*rhs.b.e31-lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o+lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.b.eoi;
    result.v.e3 = -lhs.e123*rhs.b.e12+lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e3oi*rhs.b.eoi;
    result.v.eo = 0.5*lhs.e12i*rhs.b.e12+0.5*lhs.e31i*rhs.b.e31-0.5*lhs.e1oi*rhs.b.e1i+0.5*lhs.e23i*rhs.b.e23-0.5*lhs.e2oi*rhs.b.e2i-0.5*lhs.e3oi*rhs.b.e3i;
    result.v.ei = -lhs.e12i*rhs.b.e12-lhs.e31i*rhs.b.e31+lhs.e1oi*rhs.b.e1i-lhs.e23i*rhs.b.e23+lhs.e2oi*rhs.b.e2i+lhs.e3oi*rhs.b.e3i;
    result.t.e123 = lhs.e123*rhs.s;
    result.t.e23o = lhs.e23o*rhs.s;
    result.t.e31o = lhs.e31o*rhs.s;
    result.t.e12o = lhs.e12o*rhs.s;
    result.t.e23i = lhs.e23i*rhs.s;
    result.t.e31i = lhs.e31i*rhs.s;
    result.t.e12i = lhs.e12i*rhs.s;
    result.t.e1oi = lhs.e1oi*rhs.s;
    result.t.e2oi = lhs.e2oi*rhs.s;
    result.t.e3oi = lhs.e3oi*rhs.s;
    return result;
}

Multivector operator*(const Trivector &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e123*rhs.b.e23+lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o-lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.b.eoi-lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o-lhs.e2oi*rhs.q.e12oi+lhs.e3oi*rhs.q.e31oi;
    result.v.e2 = -lhs.e123*rhs.b.e31-lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o-lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e1oi*rhs.q.e12oi+lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.b.eoi-lhs.e3oi*rhs.q.e23oi;
    result.v.e3 = -lhs.e123*rhs.b.e12-lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o+lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.q.e31oi-lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.q.e23oi+lhs.e3oi*rhs.b.eoi;
    result.v.eo = 0.5*lhs.e123*rhs.q.e123i+0.5*lhs.e12i*rhs.b.e12-0.5*lhs.e12i*rhs.q.e12oi+0.5*lhs.e31i*rhs.b.e31-0.5*lhs.e31i*rhs.q.e31oi-0.5*lhs.e1oi*rhs.b.e1i+0.5*lhs.e23i*rhs.b.e23-0.5*lhs.e23i*rhs.q.e23oi-0.5*lhs.e2oi*rhs.b.e2i-0.5*lhs.e3oi*rhs.b.e3i;
    result.v.ei = -lhs.e123*rhs.q.e123i-lhs.e12i*rhs.b.e12+lhs.e12i*rhs.q.e12oi-lhs.e31i*rhs.b.e31+lhs.e31i*rhs.q.e31oi+lhs.e1oi*rhs.b.e1i-lhs.e23i*rhs.b.e23+lhs.e23i*rhs.q.e23oi+lhs.e2oi*rhs.b.e2i+lhs.e3oi*rhs.b.e3i;
    result.t.e123 = lhs.e123*rhs.s+lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o+lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.q.e23oi+lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.q.e31oi+lhs.e3oi*rhs.q.e12oi;
    result.t.e23o = lhs.e123*rhs.b.e1o+lhs.e12o*rhs.b.e31+lhs.e12o*rhs.q.e31oi-lhs.e31o*rhs.b.e12-lhs.e31o*rhs.q.e12oi-lhs.e1oi*rhs.q.e123o+lhs.e23o*rhs.s+lhs.e23o*rhs.b.eoi-lhs.e2oi*rhs.b.e3o+lhs.e3oi*rhs.b.e2o;
    result.t.e31o = lhs.e123*rhs.b.e2o-lhs.e12o*rhs.b.e23-lhs.e12o*rhs.q.e23oi+lhs.e31o*rhs.s+lhs.e31o*rhs.b.eoi+lhs.e1oi*rhs.b.e3o+lhs.e23o*rhs.b.e12+lhs.e23o*rhs.q.e12oi-lhs.e2oi*rhs.q.e123o-lhs.e3oi*rhs.b.e1o;
    result.t.e12o = lhs.e123*rhs.b.e3o+lhs.e12o*rhs.s+lhs.e12o*rhs.b.eoi+lhs.e31o*rhs.b.e23+lhs.e31o*rhs.q.e23oi-lhs.e1oi*rhs.b.e2o-lhs.e23o*rhs.b.e31-lhs.e23o*rhs.q.e31oi+lhs.e2oi*rhs.b.e1o-lhs.e3oi*rhs.q.e123o;
    result.t.e23i = lhs.e123*rhs.b.e1i+lhs.e12i*rhs.b.e31-lhs.e12i*rhs.q.e31oi-lhs.e31i*rhs.b.e12+lhs.e31i*rhs.q.e12oi+lhs.e1oi*rhs.q.e123i+lhs.e23i*rhs.s-lhs.e23i*rhs.b.eoi+lhs.e2oi*rhs.b.e3i-lhs.e3oi*rhs.b.e2i;
    result.t.e31i = lhs.e123*rhs.b.e2i-lhs.e12i*rhs.b.e23+lhs.e12i*rhs.q.e23oi+lhs.e31i*rhs.s-lhs.e31i*rhs.b.eoi-lhs.e1oi*rhs.b.e3i+lhs.e23i*rhs.b.e12-lhs.e23i*rhs.q.e12oi+lhs.e2oi*rhs.q.e123i+lhs.e3oi*rhs.b.e1i;
    result.t.e12i = lhs.e123*rhs.b.e3i+lhs.e12i*rhs.s-lhs.e12i*rhs.b.eoi+lhs.e31i*rhs.b.e23-lhs.e31i*rhs.q.e23oi+lhs.e1oi*rhs.b.e2i-lhs.e23i*rhs.b.e31+lhs.e23i*rhs.q.e31oi-lhs.e2oi*rhs.b.e1i+lhs.e3oi*rhs.q.e123i;
    result.t.e1oi = -lhs.e123*rhs.q.e23oi-lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o+lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.s+lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o-lhs.e2oi*rhs.b.e12+lhs.e3oi*rhs.b.e31;
    result.t.e2oi = -lhs.e123*rhs.q.e31oi+lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o+lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e1oi*rhs.b.e12-lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.s-lhs.e3oi*rhs.b.e23;
    result.t.e3oi = -lhs.e123*rhs.q.e12oi+lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o-lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.b.e31+lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.b.e23+lhs.e3oi*rhs.s;
    result.p = lhs.e123*rhs.b.eoi-lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o-lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.b.e23-lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.b.e31+lhs.e3oi*rhs.b.e12;
    return result;
}

Multivector outer(const Trivector &lhs, const Versor &rhs)
{
    Multivector result;
    result.t.e123 = lhs.e123*rhs.s+lhs.e1oi*rhs.q.e23oi+lhs.e2oi*rhs.q.e31oi+lhs.e3oi*rhs.q.e12oi;
    result.t.e23o = lhs.e12o*rhs.q.e31oi-lhs.e31o*rhs.q.e12oi-lhs.e1oi*rhs.q.e123o+lhs.e23o*rhs.s;
    result.t.e31o = -lhs.e12o*rhs.q.e23oi+lhs.e31o*rhs.s+lhs.e23o*rhs.q.e12oi-lhs.e2oi*rhs.q.e123o;
    result.t.e12o = lhs.e12o*rhs.s+lhs.e31o*rhs.q.e23oi-lhs.e23o*rhs.q.e31oi-lhs.e3oi*rhs.q.e123o;
    result.t.e23i = -lhs.e12i*rhs.q.e31oi+lhs.e31i*rhs.q.e12oi+lhs.e1oi*rhs.q.e123i+lhs.e23i*rhs.s;
    result.t.e31i = lhs.e12i*rhs.q.e23oi+lhs.e31i*rhs.s-lhs.e23i*rhs.q.e12oi+lhs.e2oi*rhs.q.e123i;
    result.t.e12i = lhs.e12i*rhs.s-lhs.e31i*rhs.q.e23oi+lhs.e23i*rhs.q.e31oi+lhs.e3oi*rhs.q.e123i;
    result.t.e1oi = -lhs.e123*rhs.q.e23oi+lhs.e1oi*rhs.s+lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o;
    result.t.e2oi = -lhs.e123*rhs.q.e31oi+lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e2oi*rhs.s;
    result.t.e3oi = -lhs.e123*rhs.q.e12oi+lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o+lhs.e3oi*rhs.s;
    result.p = lhs.e123*rhs.b.eoi-lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o-lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.b.e23-lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.b.e31+lhs.e3oi*rhs.b.e12;
    return result;
}

Multivector inner(const Trivector &lhs, const Versor &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e123*rhs.b.e23+lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o-lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.b.eoi-lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o-lhs.e2oi*rhs.q.e12oi+lhs.e3oi*rhs.q.e31oi;
    result.v.e2 = -lhs.e123*rhs.b.e31-lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o-lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e1oi*rhs.q.e12oi+lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.b.eoi-lhs.e3oi*rhs.q.e23oi;
    result.v.e3 = -lhs.e123*rhs.b.e12-lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o+lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.q.e31oi-lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.q.e23oi+lhs.e3oi*rhs.b.eoi;
    result.v.eo = 0.5*lhs.e123*rhs.q.e123i+0.5*lhs.e12i*rhs.b.e12-0.5*lhs.e12i*rhs.q.e12oi+0.5*lhs.e31i*rhs.b.e31-0.5*lhs.e31i*rhs.q.e31oi-0.5*lhs.e1oi*rhs.b.e1i+0.5*lhs.e23i*rhs.b.e23-0.5*lhs.e23i*rhs.q.e23oi-0.5*lhs.e2oi*rhs.b.e2i-0.5*lhs.e3oi*rhs.b.e3i;
    result.v.ei = -lhs.e123*rhs.q.e123i-lhs.e12i*rhs.b.e12+lhs.e12i*rhs.q.e12oi-lhs.e31i*rhs.b.e31+lhs.e31i*rhs.q.e31oi+lhs.e1oi*rhs.b.e1i-lhs.e23i*rhs.b.e23+lhs.e23i*rhs.q.e23oi+lhs.e2oi*rhs.b.e2i+lhs.e3oi*rhs.b.e3i;
    result.t.e123 = lhs.e123*rhs.s;
    result.t.e23o = lhs.e23o*rhs.s;
    result.t.e31o = lhs.e31o*rhs.s;
    result.t.e12o = lhs.e12o*rhs.s;
    result.t.e23i = lhs.e23i*rhs.s;
    result.t.e31i = lhs.e31i*rhs.s;
    result.t.e12i = lhs.e12i*rhs.s;
    result.t.e1oi = lhs.e1oi*rhs.s;
    result.t.e2oi = lhs.e2oi*rhs.s;
    result.t.e3oi = lhs.e3oi*rhs.s;
    return result;
}

Multivector operator*(const Trivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e123*rhs.t.e123+lhs.e12o*rhs.t.e12i+lhs.e12i*rhs.t.e12o+lhs.e31o*rhs.t.e31i+lhs.e31i*rhs.t.e31o+lhs.e1oi*rhs.t.e1oi+lhs.e23o*rhs.t.e23i+lhs.e23i*rhs.t.e23o+lhs.e2oi*rhs.t.e2oi+lhs.e3oi*rhs.t.e3oi;
    result.v.e1 = -lhs.e123*rhs.b.e23+lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o-lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.b.eoi-lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o-lhs.e2oi*rhs.q.e12oi+lhs.e3oi*rhs.q.e31oi;
    result.v.e2 = -lhs.e123*rhs.b.e31-lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o-lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e1oi*rhs.q.e12oi+lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.b.eoi-lhs.e3oi*rhs.q.e23oi;
    result.v.e3 = -lhs.e123*rhs.b.e12-lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o+lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.q.e31oi-lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.q.e23oi+lhs.e3oi*rhs.b.eoi;
    result.v.eo = 0.5*lhs.e123*rhs.q.e123i+0.5*lhs.e12i*rhs.b.e12-0.5*lhs.e12i*rhs.q.e12oi+0.5*lhs.e31i*rhs.b.e31-0.5*lhs.e31i*rhs.q.e31oi-0.5*lhs.e1oi*rhs.b.e1i+0.5*lhs.e23i*rhs.b.e23-0.5*lhs.e23i*rhs.q.e23oi-0.5*lhs.e2oi*rhs.b.e2i-0.5*lhs.e3oi*rhs.b.e3i;
    result.v.ei = -lhs.e123*rhs.q.e123i-lhs.e12i*rhs.b.e12+lhs.e12i*rhs.q.e12oi-lhs.e31i*rhs.b.e31+lhs.e31i*rhs.q.e31oi+lhs.e1oi*rhs.b.e1i-lhs.e23i*rhs.b.e23+lhs.e23i*rhs.q.e23oi+lhs.e2oi*rhs.b.e2i+lhs.e3oi*rhs.b.e3i;
    result.b.e23 = lhs.e123*rhs.v.e1-lhs.e12o*rhs.t.e31i-lhs.e12i*rhs.t.e31o+lhs.e31o*rhs.t.e12i+lhs.e31i*rhs.t.e12o+lhs.e1oi*rhs.p-lhs.e23o*rhs.v.ei-lhs.e23i*rhs.v.eo+lhs.e2oi*rhs.t.e3oi-lhs.e3oi*rhs.t.e2oi;
    result.b.e31 = lhs.e123*rhs.v.e2+lhs.e12o*rhs.t.e23i+lhs.e12i*rhs.t.e23o-lhs.e31o*rhs.v.ei-lhs.e31i*rhs.v.eo-lhs.e1oi*rhs.t.e3oi-lhs.e23o*rhs.t.e12i-lhs.e23i*rhs.t.e12o+lhs.e2oi*rhs.p+lhs.e3oi*rhs.t.e1oi;
    result.b.e12 = lhs.e123*rhs.v.e3-lhs.e12o*rhs.v.ei-lhs.e12i*rhs.v.eo-lhs.e31o*rhs.t.e23i-lhs.e31i*rhs.t.e23o+lhs.e1oi*rhs.t.e2oi+lhs.e23o*rhs.t.e31i+lhs.e23i*rhs.t.e31o-lhs.e2oi*rhs.t.e1oi+lhs.e3oi*rhs.p;
    result.b.e1o = -lhs.e123*rhs.t.e23o-lhs.e12o*rhs.v.e2-lhs.e12o*rhs.t.e2oi+lhs.e31o*rhs.v.e3+lhs.e31o*rhs.t.e3oi-lhs.e1oi*rhs.v.eo+lhs.e23o*rhs.t.e123+lhs.e23o*rhs.p+lhs.e2oi*rhs.t.e12o-lhs.e3oi*rhs.t.e31o;
    result.b.e2o = -lhs.e123*rhs.t.e31o+lhs.e12o*rhs.v.e1+lhs.e12o*rhs.t.e1oi+lhs.e31o*rhs.t.e123+lhs.e31o*rhs.p-lhs.e1oi*rhs.t.e12o-lhs.e23o*rhs.v.e3-lhs.e23o*rhs.t.e3oi-lhs.e2oi*rhs.v.eo+lhs.e3oi*rhs.t.e23o;
    result.b.e3o = -lhs.e123*rhs.t.e12o+lhs.e12o*rhs.t.e123+lhs.e12o*rhs.p-lhs.e31o*rhs.v.e1-lhs.e31o*rhs.t.e1oi+lhs.e1oi*rhs.t.e31o+lhs.e23o*rhs.v.e2+lhs.e23o*rhs.t.e2oi-lhs.e2oi*rhs.t.e23o-lhs.e3oi*rhs.v.eo;
    result.b.e1i = -lhs.e123*rhs.t.e23i-lhs.e12i*rhs.v.e2+lhs.e12i*rhs.t.e2oi+lhs.e31i*rhs.v.e3-lhs.e31i*rhs.t.e3oi+lhs.e1oi*rhs.v.ei+lhs.e23i*rhs.t.e123-lhs.e23i*rhs.p-lhs.e2oi*rhs.t.e12i+lhs.e3oi*rhs.t.e31i;
    result.b.e2i = -lhs.e123*rhs.t.e31i+lhs.e12i*rhs.v.e1-lhs.e12i*rhs.t.e1oi+lhs.e31i*rhs.t.e123-lhs.e31i*rhs.p+lhs.e1oi*rhs.t.e12i-lhs.e23i*rhs.v.e3+lhs.e23i*rhs.t.e3oi+lhs.e2oi*rhs.v.ei-lhs.e3oi*rhs.t.e23i;
    result.b.e3i = -lhs.e123*rhs.t.e12i+lhs.e12i*rhs.t.e123-lhs.e12i*rhs.p-lhs.e31i*rhs.v.e1+lhs.e31i*rhs.t.e1oi-lhs.e1oi*rhs.t.e31i+lhs.e23i*rhs.v.e2-lhs.e23i*rhs.t.e2oi+lhs.e2oi*rhs.t.e23i+lhs.e3oi*rhs.v.ei;
    result.b.eoi = -lhs.e123*rhs.p-lhs.e12o*rhs.t.e12i+lhs.e12i*rhs.t.e12o-lhs.e31o*rhs.t.e31i+lhs.e31i*rhs.t.e31o+lhs.e1oi*rhs.v.e1-lhs.e23o*rhs.t.e23i+lhs.e23i*rhs.t.e23o+lhs.e2oi*rhs.v.e2+lhs.e3oi*rhs.v.e3;
    result.t.e123 = lhs.e123*rhs.s+lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o+lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.q.e23oi+lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.q.e31oi+lhs.e3oi*rhs.q.e12oi;
    result.t.e23o = lhs.e123*rhs.b.e1o+lhs.e12o*rhs.b.e31+lhs.e12o*rhs.q.e31oi-lhs.e31o*rhs.b.e12-lhs.e31o*rhs.q.e12oi-lhs.e1oi*rhs.q.e123o+lhs.e23o*rhs.s+lhs.e23o*rhs.b.eoi-lhs.e2oi*rhs.b.e3o+lhs.e3oi*rhs.b.e2o;
    result.t.e31o = lhs.e123*rhs.b.e2o-lhs.e12o*rhs.b.e23-lhs.e12o*rhs.q.e23oi+lhs.e31o*rhs.s+lhs.e31o*rhs.b.eoi+lhs.e1oi*rhs.b.e3o+lhs.e23o*rhs.b.e12+lhs.e23o*rhs.q.e12oi-lhs.e2oi*rhs.q.e123o-lhs.e3oi*rhs.b.e1o;
    result.t.e12o = lhs.e123*rhs.b.e3o+lhs.e12o*rhs.s+lhs.e12o*rhs.b.eoi+lhs.e31o*rhs.b.e23+lhs.e31o*rhs.q.e23oi-lhs.e1oi*rhs.b.e2o-lhs.e23o*rhs.b.e31-lhs.e23o*rhs.q.e31oi+lhs.e2oi*rhs.b.e1o-lhs.e3oi*rhs.q.e123o;
    result.t.e23i = lhs.e123*rhs.b.e1i+lhs.e12i*rhs.b.e31-lhs.e12i*rhs.q.e31oi-lhs.e31i*rhs.b.e12+lhs.e31i*rhs.q.e12oi+lhs.e1oi*rhs.q.e123i+lhs.e23i*rhs.s-lhs.e23i*rhs.b.eoi+lhs.e2oi*rhs.b.e3i-lhs.e3oi*rhs.b.e2i;
    result.t.e31i = lhs.e123*rhs.b.e2i-lhs.e12i*rhs.b.e23+lhs.e12i*rhs.q.e23oi+lhs.e31i*rhs.s-lhs.e31i*rhs.b.eoi-lhs.e1oi*rhs.b.e3i+lhs.e23i*rhs.b.e12-lhs.e23i*rhs.q.e12oi+lhs.e2oi*rhs.q.e123i+lhs.e3oi*rhs.b.e1i;
    result.t.e12i = lhs.e123*rhs.b.e3i+lhs.e12i*rhs.s-lhs.e12i*rhs.b.eoi+lhs.e31i*rhs.b.e23-lhs.e31i*rhs.q.e23oi+lhs.e1oi*rhs.b.e2i-lhs.e23i*rhs.b.e31+lhs.e23i*rhs.q.e31oi-lhs.e2oi*rhs.b.e1i+lhs.e3oi*rhs.q.e123i;
    result.t.e1oi = -lhs.e123*rhs.q.e23oi-lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o+lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.s+lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o-lhs.e2oi*rhs.b.e12+lhs.e3oi*rhs.b.e31;
    result.t.e2oi = -lhs.e123*rhs.q.e31oi+lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o+lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e1oi*rhs.b.e12-lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.s-lhs.e3oi*rhs.b.e23;
    result.t.e3oi = -lhs.e123*rhs.q.e12oi+lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o-lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.b.e31+lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.b.e23+lhs.e3oi*rhs.s;
    result.q.e123o = lhs.e123*rhs.v.eo-lhs.e12o*rhs.v.e3-lhs.e12o*rhs.t.e3oi-lhs.e31o*rhs.v.e2-lhs.e31o*rhs.t.e2oi-lhs.e1oi*rhs.t.e23o-lhs.e23o*rhs.v.e1-lhs.e23o*rhs.t.e1oi-lhs.e2oi*rhs.t.e31o-lhs.e3oi*rhs.t.e12o;
    result.q.e123i = lhs.e123*rhs.v.ei-lhs.e12i*rhs.v.e3+lhs.e12i*rhs.t.e3oi-lhs.e31i*rhs.v.e2+lhs.e31i*rhs.t.e2oi+lhs.e1oi*rhs.t.e23i-lhs.e23i*rhs.v.e1+lhs.e23i*rhs.t.e1oi+lhs.e2oi*rhs.t.e31i+lhs.e3oi*rhs.t.e12i;
    result.q.e23oi = lhs.e123*rhs.t.e1oi+lhs.e12o*rhs.t.e31i-lhs.e12i*rhs.t.e31o-lhs.e31o*rhs.t.e12i+lhs.e31i*rhs.t.e12o+lhs.e1oi*rhs.t.e123+lhs.e23o*rhs.v.ei-lhs.e23i*rhs.v.eo+lhs.e2oi*rhs.v.e3-lhs.e3oi*rhs.v.e2;
    result.q.e31oi = lhs.e123*rhs.t.e2oi-lhs.e12o*rhs.t.e23i+lhs.e12i*rhs.t.e23o+lhs.e31o*rhs.v.ei-lhs.e31i*rhs.v.eo-lhs.e1oi*rhs.v.e3+lhs.e23o*rhs.t.e12i-lhs.e23i*rhs.t.e12o+lhs.e2oi*rhs.t.e123+lhs.e3oi*rhs.v.e1;
    result.q.e12oi = lhs.e123*rhs.t.e3oi+lhs.e12o*rhs.v.ei-lhs.e12i*rhs.v.eo+lhs.e31o*rhs.t.e23i-lhs.e31i*rhs.t.e23o+lhs.e1oi*rhs.v.e2-lhs.e23o*rhs.t.e31i+lhs.e23i*rhs.t.e31o-lhs.e2oi*rhs.v.e1+lhs.e3oi*rhs.t.e123;
    result.p = lhs.e123*rhs.b.eoi-lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o-lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.b.e23-lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.b.e31+lhs.e3oi*rhs.b.e12;
    return result;
}

Multivector outer(const Trivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.b.e23 = lhs.e1oi*rhs.p;
    result.b.e31 = lhs.e2oi*rhs.p;
    result.b.e12 = lhs.e3oi*rhs.p;
    result.b.e1o = lhs.e23o*rhs.p;
    result.b.e2o = lhs.e31o*rhs.p;
    result.b.e3o = lhs.e12o*rhs.p;
    result.b.e1i = -lhs.e23i*rhs.p;
    result.b.e2i = -lhs.e31i*rhs.p;
    result.b.e3i = -lhs.e12i*rhs.p;
    result.b.eoi = -lhs.e123*rhs.p;
    result.t.e123 = lhs.e123*rhs.s+lhs.e1oi*rhs.q.e23oi+lhs.e2oi*rhs.q.e31oi+lhs.e3oi*rhs.q.e12oi;
    result.t.e23o = lhs.e12o*rhs.q.e31oi-lhs.e31o*rhs.q.e12oi-lhs.e1oi*rhs.q.e123o+lhs.e23o*rhs.s;
    result.t.e31o = -lhs.e12o*rhs.q.e23oi+lhs.e31o*rhs.s+lhs.e23o*rhs.q.e12oi-lhs.e2oi*rhs.q.e123o;
    result.t.e12o = lhs.e12o*rhs.s+lhs.e31o*rhs.q.e23oi-lhs.e23o*rhs.q.e31oi-lhs.e3oi*rhs.q.e123o;
    result.t.e23i = -lhs.e12i*rhs.q.e31oi+lhs.e31i*rhs.q.e12oi+lhs.e1oi*rhs.q.e123i+lhs.e23i*rhs.s;
    result.t.e31i = lhs.e12i*rhs.q.e23oi+lhs.e31i*rhs.s-lhs.e23i*rhs.q.e12oi+lhs.e2oi*rhs.q.e123i;
    result.t.e12i = lhs.e12i*rhs.s-lhs.e31i*rhs.q.e23oi+lhs.e23i*rhs.q.e31oi+lhs.e3oi*rhs.q.e123i;
    result.t.e1oi = -lhs.e123*rhs.q.e23oi+lhs.e1oi*rhs.s+lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o;
    result.t.e2oi = -lhs.e123*rhs.q.e31oi+lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e2oi*rhs.s;
    result.t.e3oi = -lhs.e123*rhs.q.e12oi+lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o+lhs.e3oi*rhs.s;
    result.q.e123o = lhs.e123*rhs.v.eo-lhs.e12o*rhs.v.e3-lhs.e12o*rhs.t.e3oi-lhs.e31o*rhs.v.e2-lhs.e31o*rhs.t.e2oi-lhs.e1oi*rhs.t.e23o-lhs.e23o*rhs.v.e1-lhs.e23o*rhs.t.e1oi-lhs.e2oi*rhs.t.e31o-lhs.e3oi*rhs.t.e12o;
    result.q.e123i = lhs.e123*rhs.v.ei-lhs.e12i*rhs.v.e3+lhs.e12i*rhs.t.e3oi-lhs.e31i*rhs.v.e2+lhs.e31i*rhs.t.e2oi+lhs.e1oi*rhs.t.e23i-lhs.e23i*rhs.v.e1+lhs.e23i*rhs.t.e1oi+lhs.e2oi*rhs.t.e31i+lhs.e3oi*rhs.t.e12i;
    result.q.e23oi = lhs.e123*rhs.t.e1oi+lhs.e12o*rhs.t.e31i-lhs.e12i*rhs.t.e31o-lhs.e31o*rhs.t.e12i+lhs.e31i*rhs.t.e12o+lhs.e1oi*rhs.t.e123+lhs.e23o*rhs.v.ei-lhs.e23i*rhs.v.eo+lhs.e2oi*rhs.v.e3-lhs.e3oi*rhs.v.e2;
    result.q.e31oi = lhs.e123*rhs.t.e2oi-lhs.e12o*rhs.t.e23i+lhs.e12i*rhs.t.e23o+lhs.e31o*rhs.v.ei-lhs.e31i*rhs.v.eo-lhs.e1oi*rhs.v.e3+lhs.e23o*rhs.t.e12i-lhs.e23i*rhs.t.e12o+lhs.e2oi*rhs.t.e123+lhs.e3oi*rhs.v.e1;
    result.q.e12oi = lhs.e123*rhs.t.e3oi+lhs.e12o*rhs.v.ei-lhs.e12i*rhs.v.eo+lhs.e31o*rhs.t.e23i-lhs.e31i*rhs.t.e23o+lhs.e1oi*rhs.v.e2-lhs.e23o*rhs.t.e31i+lhs.e23i*rhs.t.e31o-lhs.e2oi*rhs.v.e1+lhs.e3oi*rhs.t.e123;
    result.p = lhs.e123*rhs.b.eoi-lhs.e12o*rhs.b.e3i+lhs.e12i*rhs.b.e3o-lhs.e31o*rhs.b.e2i+lhs.e31i*rhs.b.e2o+lhs.e1oi*rhs.b.e23-lhs.e23o*rhs.b.e1i+lhs.e23i*rhs.b.e1o+lhs.e2oi*rhs.b.e31+lhs.e3oi*rhs.b.e12;
    return result;
}

Multivector inner(const Trivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = -lhs.e123*rhs.t.e123+lhs.e12o*rhs.t.e12i+lhs.e12i*rhs.t.e12o+lhs.e31o*rhs.t.e31i+lhs.e31i*rhs.t.e31o+lhs.e1oi*rhs.t.e1oi+lhs.e23o*rhs.t.e23i+lhs.e23i*rhs.t.e23o+lhs.e2oi*rhs.t.e2oi+lhs.e3oi*rhs.t.e3oi;
    result.v.e1 = -lhs.e123*rhs.b.e23+lhs.e12o*rhs.b.e2i+lhs.e12i*rhs.b.e2o-lhs.e31o*rhs.b.e3i-lhs.e31i*rhs.b.e3o+lhs.e1oi*rhs.b.eoi-lhs.e23o*rhs.q.e123i-lhs.e23i*rhs.q.e123o-lhs.e2oi*rhs.q.e12oi+lhs.e3oi*rhs.q.e31oi;
    result.v.e2 = -lhs.e123*rhs.b.e31-lhs.e12o*rhs.b.e1i-lhs.e12i*rhs.b.e1o-lhs.e31o*rhs.q.e123i-lhs.e31i*rhs.q.e123o+lhs.e1oi*rhs.q.e12oi+lhs.e23o*rhs.b.e3i+lhs.e23i*rhs.b.e3o+lhs.e2oi*rhs.b.eoi-lhs.e3oi*rhs.q.e23oi;
    result.v.e3 = -lhs.e123*rhs.b.e12-lhs.e12o*rhs.q.e123i-lhs.e12i*rhs.q.e123o+lhs.e31o*rhs.b.e1i+lhs.e31i*rhs.b.e1o-lhs.e1oi*rhs.q.e31oi-lhs.e23o*rhs.b.e2i-lhs.e23i*rhs.b.e2o+lhs.e2oi*rhs.q.e23oi+lhs.e3oi*rhs.b.eoi;
    result.v.eo = 0.5*lhs.e123*rhs.q.e123i+0.5*lhs.e12i*rhs.b.e12-0.5*lhs.e12i*rhs.q.e12oi+0.5*lhs.e31i*rhs.b.e31-0.5*lhs.e31i*rhs.q.e31oi-0.5*lhs.e1oi*rhs.b.e1i+0.5*lhs.e23i*rhs.b.e23-0.5*lhs.e23i*rhs.q.e23oi-0.5*lhs.e2oi*rhs.b.e2i-0.5*lhs.e3oi*rhs.b.e3i;
    result.v.ei = -lhs.e123*rhs.q.e123i-lhs.e12i*rhs.b.e12+lhs.e12i*rhs.q.e12oi-lhs.e31i*rhs.b.e31+lhs.e31i*rhs.q.e31oi+lhs.e1oi*rhs.b.e1i-lhs.e23i*rhs.b.e23+lhs.e23i*rhs.q.e23oi+lhs.e2oi*rhs.b.e2i+lhs.e3oi*rhs.b.e3i;
    result.b.e23 = lhs.e123*rhs.v.e1+lhs.e1oi*rhs.p-lhs.e23o*rhs.v.ei-lhs.e23i*rhs.v.eo;
    result.b.e31 = lhs.e123*rhs.v.e2-lhs.e31o*rhs.v.ei-lhs.e31i*rhs.v.eo+lhs.e2oi*rhs.p;
    result.b.e12 = lhs.e123*rhs.v.e3-lhs.e12o*rhs.v.ei-lhs.e12i*rhs.v.eo+lhs.e3oi*rhs.p;
    result.b.e1o = -lhs.e12o*rhs.v.e2+lhs.e31o*rhs.v.e3-lhs.e1oi*rhs.v.eo+lhs.e23o*rhs.p;
    result.b.e2o = lhs.e12o*rhs.v.e1+lhs.e31o*rhs.p-lhs.e23o*rhs.v.e3-lhs.e2oi*rhs.v.eo;
    result.b.e3o = lhs.e12o*rhs.p-lhs.e31o*rhs.v.e1+lhs.e23o*rhs.v.e2-lhs.e3oi*rhs.v.eo;
    result.b.e1i = -lhs.e12i*rhs.v.e2+lhs.e31i*rhs.v.e3+lhs.e1oi*rhs.v.ei-lhs.e23i*rhs.p;
    result.b.e2i = lhs.e12i*rhs.v.e1-lhs.e31i*rhs.p-lhs.e23i*rhs.v.e3+lhs.e2oi*rhs.v.ei;
    result.b.e3i = -lhs.e12i*rhs.p-lhs.e31i*rhs.v.e1+lhs.e23i*rhs.v.e2+lhs.e3oi*rhs.v.ei;
    result.b.eoi = -lhs.e123*rhs.p+lhs.e1oi*rhs.v.e1+lhs.e2oi*rhs.v.e2+lhs.e3oi*rhs.v.e3;
    result.t.e123 = lhs.e123*rhs.s;
    result.t.e23o = lhs.e23o*rhs.s;
    result.t.e31o = lhs.e31o*rhs.s;
    result.t.e12o = lhs.e12o*rhs.s;
    result.t.e23i = lhs.e23i*rhs.s;
    result.t.e31i = lhs.e31i*rhs.s;
    result.t.e12i = lhs.e12i*rhs.s;
    result.t.e1oi = lhs.e1oi*rhs.s;
    result.t.e2oi = lhs.e2oi*rhs.s;
    result.t.e3oi = lhs.e3oi*rhs.s;
    return result;
}

Versor operator*(const Rotor &lhs, const Rotor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e23*rhs.s+lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o-lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s-lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.b.e12+lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23+lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.b.e31-lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o+lhs.b.e1o*rhs.s+lhs.b.e1o*rhs.b.eoi-lhs.b.e2o*rhs.b.e12+lhs.b.e3o*rhs.b.e31-lhs.b.eoi*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o+lhs.b.e1o*rhs.b.e12+lhs.b.e23*rhs.b.e3o+lhs.b.e2o*rhs.s+lhs.b.e2o*rhs.b.eoi-lhs.b.e3o*rhs.b.e23-lhs.b.eoi*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e31*rhs.b.e1o-lhs.b.e1o*rhs.b.e31-lhs.b.e23*rhs.b.e2o+lhs.b.e2o*rhs.b.e23+lhs.b.e3o*rhs.s+lhs.b.e3o*rhs.b.eoi-lhs.b.eoi*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i+lhs.b.e1i*rhs.s-lhs.b.e1i*rhs.b.eoi-lhs.b.e2i*rhs.b.e12+lhs.b.e3i*rhs.b.e31+lhs.b.eoi*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i+lhs.b.e1i*rhs.b.e12+lhs.b.e23*rhs.b.e3i+lhs.b.e2i*rhs.s-lhs.b.e2i*rhs.b.eoi-lhs.b.e3i*rhs.b.e23+lhs.b.eoi*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e31*rhs.b.e1i-lhs.b.e1i*rhs.b.e31-lhs.b.e23*rhs.b.e2i+lhs.b.e2i*rhs.b.e23+lhs.b.e3i*rhs.s-lhs.b.e3i*rhs.b.eoi+lhs.b.eoi*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o-lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.s;
    result.q.e123o = lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e3o*rhs.b.e12;
    result.q.e123i = lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31+lhs.b.e3i*rhs.b.e12;
    result.q.e23oi = lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = lhs.b.e12*rhs.b.eoi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.eoi*rhs.b.e12;
    return result;
}

Versor outer(const Rotor &lhs, const Rotor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.b.e2o*rhs.s;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e3o*rhs.s;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.b.e2i*rhs.s;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e3i*rhs.s;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.b.eoi*rhs.s;
    result.q.e123o = lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e3o*rhs.b.e12;
    result.q.e123i = lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31+lhs.b.e3i*rhs.b.e12;
    result.q.e23oi = lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = lhs.b.e12*rhs.b.eoi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.eoi*rhs.b.e12;
    return result;
}

Rotor inner(const Rotor &lhs, const Rotor &rhs)
{
    Rotor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.b.e2o*rhs.s;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e3o*rhs.s;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.b.e2i*rhs.s;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e3i*rhs.s;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.b.eoi*rhs.s;
    return result;
}

Versor operator*(const Rotor &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o-lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.q.e23oi;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s-lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.b.e12+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23+lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.b.e31-lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o+lhs.b.e1o*rhs.s+lhs.b.e1o*rhs.b.eoi-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.b.e12-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.b.e31+lhs.b.e3o*rhs.q.e31oi-lhs.b.eoi*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.b.e12+lhs.b.e1o*rhs.q.e12oi+lhs.b.e23*rhs.b.e3o+lhs.b.e2o*rhs.s+lhs.b.e2o*rhs.b.eoi-lhs.b.e3o*rhs.b.e23-lhs.b.e3o*rhs.q.e23oi-lhs.b.eoi*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e1o*rhs.b.e31-lhs.b.e1o*rhs.q.e31oi-lhs.b.e23*rhs.b.e2o+lhs.b.e2o*rhs.b.e23+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s+lhs.b.e3o*rhs.b.eoi-lhs.b.eoi*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i+lhs.b.e1i*rhs.s-lhs.b.e1i*rhs.b.eoi-lhs.b.e23*rhs.q.e123i-lhs.b.e2i*rhs.b.e12+lhs.b.e2i*rhs.q.e12oi+lhs.b.e3i*rhs.b.e31-lhs.b.e3i*rhs.q.e31oi+lhs.b.eoi*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e1i*rhs.b.e12-lhs.b.e1i*rhs.q.e12oi+lhs.b.e23*rhs.b.e3i+lhs.b.e2i*rhs.s-lhs.b.e2i*rhs.b.eoi-lhs.b.e3i*rhs.b.e23+lhs.b.e3i*rhs.q.e23oi+lhs.b.eoi*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e1i*rhs.b.e31+lhs.b.e1i*rhs.q.e31oi-lhs.b.e23*rhs.b.e2i+lhs.b.e2i*rhs.b.e23-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.b.e3i*rhs.b.eoi+lhs.b.eoi*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.q.e23oi-lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o-lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.s;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12;
    return result;
}

Versor outer(const Rotor &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.b.e2o*rhs.s;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e3o*rhs.s;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.b.e2i*rhs.s;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e3i*rhs.s;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.b.eoi*rhs.s;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12;
    return result;
}

Versor inner(const Rotor &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.eoi*rhs.q.e23oi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.q.e31oi;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.q.e12oi+lhs.b.e2o*rhs.s-lhs.b.e3o*rhs.q.e23oi;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o-lhs.b.e1o*rhs.q.e31oi+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s-lhs.b.e23*rhs.q.e123i+lhs.b.e2i*rhs.q.e12oi-lhs.b.e3i*rhs.q.e31oi;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e31*rhs.q.e123i-lhs.b.e1i*rhs.q.e12oi+lhs.b.e2i*rhs.s+lhs.b.e3i*rhs.q.e23oi;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e1i*rhs.q.e31oi-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi+lhs.b.eoi*rhs.s;
    result.q.e123o = lhs.s*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi;
    result.q.e31oi = lhs.s*rhs.q.e31oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi;
    return result;
}

Multivector operator*(const Rotor &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.t.e123+lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o-lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.t.e1oi;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123-lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.v.e3-lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.t.e2oi;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1+lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.v.e2-lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o-lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.t.e3oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e1i*rhs.v.e1-0.5*lhs.b.e1i*rhs.t.e1oi+0.5*lhs.b.e23*rhs.t.e23i+0.5*lhs.b.e2i*rhs.v.e2-0.5*lhs.b.e2i*rhs.t.e2oi+0.5*lhs.b.e3i*rhs.v.e3-0.5*lhs.b.e3i*rhs.t.e3oi-0.5*lhs.b.eoi*rhs.v.ei;
    result.v.ei = lhs.s*rhs.v.ei-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e1i*rhs.v.e1+lhs.b.e1i*rhs.t.e1oi-lhs.b.e23*rhs.t.e23i-lhs.b.e2i*rhs.v.e2+lhs.b.e2i*rhs.t.e2oi-lhs.b.e3i*rhs.v.e3+lhs.b.e3i*rhs.t.e3oi+lhs.b.eoi*rhs.v.ei;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o-lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.q.e23oi;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s-lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.b.e12+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23+lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.b.e31-lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o+lhs.b.e1o*rhs.s+lhs.b.e1o*rhs.b.eoi-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.b.e12-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.b.e31+lhs.b.e3o*rhs.q.e31oi-lhs.b.eoi*rhs.b.e1o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.b.e12+lhs.b.e1o*rhs.q.e12oi+lhs.b.e23*rhs.b.e3o+lhs.b.e2o*rhs.s+lhs.b.e2o*rhs.b.eoi-lhs.b.e3o*rhs.b.e23-lhs.b.e3o*rhs.q.e23oi-lhs.b.eoi*rhs.b.e2o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e1o*rhs.b.e31-lhs.b.e1o*rhs.q.e31oi-lhs.b.e23*rhs.b.e2o+lhs.b.e2o*rhs.b.e23+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s+lhs.b.e3o*rhs.b.eoi-lhs.b.eoi*rhs.b.e3o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i+lhs.b.e1i*rhs.s-lhs.b.e1i*rhs.b.eoi-lhs.b.e23*rhs.q.e123i-lhs.b.e2i*rhs.b.e12+lhs.b.e2i*rhs.q.e12oi+lhs.b.e3i*rhs.b.e31-lhs.b.e3i*rhs.q.e31oi+lhs.b.eoi*rhs.b.e1i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e1i*rhs.b.e12-lhs.b.e1i*rhs.q.e12oi+lhs.b.e23*rhs.b.e3i+lhs.b.e2i*rhs.s-lhs.b.e2i*rhs.b.eoi-lhs.b.e3i*rhs.b.e23+lhs.b.e3i*rhs.q.e23oi+lhs.b.eoi*rhs.b.e2i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e1i*rhs.b.e31+lhs.b.e1i*rhs.q.e31oi-lhs.b.e23*rhs.b.e2i+lhs.b.e2i*rhs.b.e23-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.b.e3i*rhs.b.eoi+lhs.b.eoi*rhs.b.e3i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.q.e23oi-lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o-lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.s;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2-lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.v.e1-lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o-lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.p;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.b.e12*rhs.t.e31o-lhs.b.e31*rhs.t.e12o-lhs.b.e1o*rhs.t.e123-lhs.b.e1o*rhs.p+lhs.b.e23*rhs.v.eo-lhs.b.e2o*rhs.v.e3-lhs.b.e2o*rhs.t.e3oi+lhs.b.e3o*rhs.v.e2+lhs.b.e3o*rhs.t.e2oi-lhs.b.eoi*rhs.t.e23o;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.b.e12*rhs.t.e23o+lhs.b.e31*rhs.v.eo+lhs.b.e1o*rhs.v.e3+lhs.b.e1o*rhs.t.e3oi+lhs.b.e23*rhs.t.e12o-lhs.b.e2o*rhs.t.e123-lhs.b.e2o*rhs.p-lhs.b.e3o*rhs.v.e1-lhs.b.e3o*rhs.t.e1oi-lhs.b.eoi*rhs.t.e31o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.b.e12*rhs.v.eo+lhs.b.e31*rhs.t.e23o-lhs.b.e1o*rhs.v.e2-lhs.b.e1o*rhs.t.e2oi-lhs.b.e23*rhs.t.e31o+lhs.b.e2o*rhs.v.e1+lhs.b.e2o*rhs.t.e1oi-lhs.b.e3o*rhs.t.e123-lhs.b.e3o*rhs.p-lhs.b.eoi*rhs.t.e12o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e12*rhs.t.e31i-lhs.b.e31*rhs.t.e12i-lhs.b.e1i*rhs.t.e123+lhs.b.e1i*rhs.p+lhs.b.e23*rhs.v.ei-lhs.b.e2i*rhs.v.e3+lhs.b.e2i*rhs.t.e3oi+lhs.b.e3i*rhs.v.e2-lhs.b.e3i*rhs.t.e2oi+lhs.b.eoi*rhs.t.e23i;
    result.t.e31i = lhs.s*rhs.t.e31i-lhs.b.e12*rhs.t.e23i+lhs.b.e31*rhs.v.ei+lhs.b.e1i*rhs.v.e3-lhs.b.e1i*rhs.t.e3oi+lhs.b.e23*rhs.t.e12i-lhs.b.e2i*rhs.t.e123+lhs.b.e2i*rhs.p-lhs.b.e3i*rhs.v.e1+lhs.b.e3i*rhs.t.e1oi+lhs.b.eoi*rhs.t.e31i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e12*rhs.v.ei+lhs.b.e31*rhs.t.e23i-lhs.b.e1i*rhs.v.e2+lhs.b.e1i*rhs.t.e2oi-lhs.b.e23*rhs.t.e31i+lhs.b.e2i*rhs.v.e1-lhs.b.e2i*rhs.t.e1oi-lhs.b.e3i*rhs.t.e123+lhs.b.e3i*rhs.p+lhs.b.eoi*rhs.t.e12i;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.b.e12*rhs.t.e2oi-lhs.b.e31*rhs.t.e3oi+lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.p-lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o+lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.v.e1;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e12*rhs.t.e1oi-lhs.b.e31*rhs.p+lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.t.e3oi+lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo-lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.v.e2;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p+lhs.b.e31*rhs.t.e1oi-lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.t.e2oi+lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o+lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.v.e3;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12;
    result.p = lhs.s*rhs.p+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.t.e1oi+lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o+lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.t.e123;
    return result;
}

Multivector outer(const Rotor &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s;
    result.v.e1 = lhs.s*rhs.v.e1;
    result.v.e2 = lhs.s*rhs.v.e2;
    result.v.e3 = lhs.s*rhs.v.e3;
    result.v.eo = -0.5*lhs.s*rhs.v.ei;
    result.v.ei = lhs.s*rhs.v.ei;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.b.e2o*rhs.s;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e3o*rhs.s;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.b.e2i*rhs.s;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e3i*rhs.s;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.b.eoi*rhs.s;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2+lhs.b.e23*rhs.v.e1+lhs.b.eoi*rhs.p;
    result.t.e23o = lhs.s*rhs.t.e23o-lhs.b.e1o*rhs.p+lhs.b.e23*rhs.v.eo-lhs.b.e2o*rhs.v.e3+lhs.b.e3o*rhs.v.e2;
    result.t.e31o = lhs.s*rhs.t.e31o+lhs.b.e31*rhs.v.eo+lhs.b.e1o*rhs.v.e3-lhs.b.e2o*rhs.p-lhs.b.e3o*rhs.v.e1;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.b.e12*rhs.v.eo-lhs.b.e1o*rhs.v.e2+lhs.b.e2o*rhs.v.e1-lhs.b.e3o*rhs.p;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e1i*rhs.p+lhs.b.e23*rhs.v.ei-lhs.b.e2i*rhs.v.e3+lhs.b.e3i*rhs.v.e2;
    result.t.e31i = lhs.s*rhs.t.e31i+lhs.b.e31*rhs.v.ei+lhs.b.e1i*rhs.v.e3+lhs.b.e2i*rhs.p-lhs.b.e3i*rhs.v.e1;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e12*rhs.v.ei-lhs.b.e1i*rhs.v.e2+lhs.b.e2i*rhs.v.e1+lhs.b.e3i*rhs.p;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.p+lhs.b.eoi*rhs.v.e1;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e31*rhs.p+lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.eoi*rhs.v.e2;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p+lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.v.e3;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12;
    result.p = lhs.s*rhs.p+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.t.e1oi+lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o+lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.t.e123;
    return result;
}

Multivector inner(const Rotor &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.t.e123+lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o-lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.t.e1oi;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123-lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.v.e3-lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.t.e2oi;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1+lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.v.e2-lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o-lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.t.e3oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e1i*rhs.v.e1-0.5*lhs.b.e1i*rhs.t.e1oi+0.5*lhs.b.e23*rhs.t.e23i+0.5*lhs.b.e2i*rhs.v.e2-0.5*lhs.b.e2i*rhs.t.e2oi+0.5*lhs.b.e3i*rhs.v.e3-0.5*lhs.b.e3i*rhs.t.e3oi-0.5*lhs.b.eoi*rhs.v.ei;
    result.v.ei = lhs.s*rhs.v.ei-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e1i*rhs.v.e1+lhs.b.e1i*rhs.t.e1oi-lhs.b.e23*rhs.t.e23i-lhs.b.e2i*rhs.v.e2+lhs.b.e2i*rhs.t.e2oi-lhs.b.e3i*rhs.v.e3+lhs.b.e3i*rhs.t.e3oi+lhs.b.eoi*rhs.v.ei;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.eoi*rhs.q.e23oi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.eoi*rhs.q.e31oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.q.e31oi;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.q.e12oi+lhs.b.e2o*rhs.s-lhs.b.e3o*rhs.q.e23oi;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o-lhs.b.e1o*rhs.q.e31oi+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s-lhs.b.e23*rhs.q.e123i+lhs.b.e2i*rhs.q.e12oi-lhs.b.e3i*rhs.q.e31oi;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e31*rhs.q.e123i-lhs.b.e1i*rhs.q.e12oi+lhs.b.e2i*rhs.s+lhs.b.e3i*rhs.q.e23oi;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e1i*rhs.q.e31oi-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi+lhs.b.eoi*rhs.s;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.eoi*rhs.p;
    result.t.e23o = lhs.s*rhs.t.e23o-lhs.b.e1o*rhs.p;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.b.e2o*rhs.p;
    result.t.e12o = lhs.s*rhs.t.e12o-lhs.b.e3o*rhs.p;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e1i*rhs.p;
    result.t.e31i = lhs.s*rhs.t.e31i+lhs.b.e2i*rhs.p;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e3i*rhs.p;
    result.t.e1oi = lhs.s*rhs.t.e1oi-lhs.b.e23*rhs.p;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e31*rhs.p;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p;
    result.q.e123o = lhs.s*rhs.q.e123o;
    result.q.e123i = lhs.s*rhs.q.e123i;
    result.q.e23oi = lhs.s*rhs.q.e23oi;
    result.q.e31oi = lhs.s*rhs.q.e31oi;
    result.q.e12oi = lhs.s*rhs.q.e12oi;
    result.p = lhs.s*rhs.p;
    return result;
}

Versor operator*(const Versor &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi-lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.q.e12oi-lhs.q.e31oi*rhs.q.e31oi-lhs.q.e23oi*rhs.q.e23oi;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o-lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.q.e23oi+lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e12oi+lhs.q.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s-lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.b.e12+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.q.e31oi+lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.q.e23oi+lhs.q.e31oi*rhs.b.eoi+lhs.q.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23+lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.b.e31-lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi+lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.b.eoi+lhs.q.e31oi*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e31oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o+lhs.b.e1o*rhs.s+lhs.b.e1o*rhs.b.eoi-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.b.e12-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.b.e31+lhs.b.e3o*rhs.q.e31oi-lhs.b.eoi*rhs.b.e1o-lhs.q.e123o*rhs.b.e23-lhs.q.e123o*rhs.q.e23oi-lhs.q.e12oi*rhs.b.e2o+lhs.q.e31oi*rhs.b.e3o+lhs.q.e23oi*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.b.e12+lhs.b.e1o*rhs.q.e12oi+lhs.b.e23*rhs.b.e3o+lhs.b.e2o*rhs.s+lhs.b.e2o*rhs.b.eoi-lhs.b.e3o*rhs.b.e23-lhs.b.e3o*rhs.q.e23oi-lhs.b.eoi*rhs.b.e2o-lhs.q.e123o*rhs.b.e31-lhs.q.e123o*rhs.q.e31oi+lhs.q.e12oi*rhs.b.e1o+lhs.q.e31oi*rhs.q.e123o-lhs.q.e23oi*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e1o*rhs.b.e31-lhs.b.e1o*rhs.q.e31oi-lhs.b.e23*rhs.b.e2o+lhs.b.e2o*rhs.b.e23+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s+lhs.b.e3o*rhs.b.eoi-lhs.b.eoi*rhs.b.e3o-lhs.q.e123o*rhs.b.e12-lhs.q.e123o*rhs.q.e12oi+lhs.q.e12oi*rhs.q.e123o-lhs.q.e31oi*rhs.b.e1o+lhs.q.e23oi*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i+lhs.b.e1i*rhs.s-lhs.b.e1i*rhs.b.eoi-lhs.b.e23*rhs.q.e123i-lhs.b.e2i*rhs.b.e12+lhs.b.e2i*rhs.q.e12oi+lhs.b.e3i*rhs.b.e31-lhs.b.e3i*rhs.q.e31oi+lhs.b.eoi*rhs.b.e1i-lhs.q.e123i*rhs.b.e23+lhs.q.e123i*rhs.q.e23oi+lhs.q.e12oi*rhs.b.e2i-lhs.q.e31oi*rhs.b.e3i-lhs.q.e23oi*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e1i*rhs.b.e12-lhs.b.e1i*rhs.q.e12oi+lhs.b.e23*rhs.b.e3i+lhs.b.e2i*rhs.s-lhs.b.e2i*rhs.b.eoi-lhs.b.e3i*rhs.b.e23+lhs.b.e3i*rhs.q.e23oi+lhs.b.eoi*rhs.b.e2i-lhs.q.e123i*rhs.b.e31+lhs.q.e123i*rhs.q.e31oi-lhs.q.e12oi*rhs.b.e1i-lhs.q.e31oi*rhs.q.e123i+lhs.q.e23oi*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e1i*rhs.b.e31+lhs.b.e1i*rhs.q.e31oi-lhs.b.e23*rhs.b.e2i+lhs.b.e2i*rhs.b.e23-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.b.e3i*rhs.b.eoi+lhs.b.eoi*rhs.b.e3i-lhs.q.e123i*rhs.b.e12+lhs.q.e123i*rhs.q.e12oi-lhs.q.e12oi*rhs.q.e123i+lhs.q.e31oi*rhs.b.e1i-lhs.q.e23oi*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.q.e23oi-lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o-lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.s+lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.b.e12-lhs.q.e31oi*rhs.b.e31-lhs.q.e23oi*rhs.b.e23;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o+lhs.q.e123o*rhs.s+lhs.q.e123o*rhs.b.eoi-lhs.q.e12oi*rhs.b.e3o-lhs.q.e31oi*rhs.b.e2o-lhs.q.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i+lhs.q.e123i*rhs.s-lhs.q.e123i*rhs.b.eoi+lhs.q.e12oi*rhs.b.e3i+lhs.q.e31oi*rhs.b.e2i+lhs.q.e23oi*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23-lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.b.e31-lhs.q.e31oi*rhs.b.e12+lhs.q.e23oi*rhs.s;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31-lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.b.e23+lhs.q.e31oi*rhs.s+lhs.q.e23oi*rhs.b.e12;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12-lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.s+lhs.q.e31oi*rhs.b.e23-lhs.q.e23oi*rhs.b.e31;
    return result;
}

Versor outer(const Versor &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s+lhs.q.e12oi*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e12oi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s-lhs.q.e12oi*rhs.q.e23oi+lhs.q.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.q.e31oi*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e31oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s-lhs.q.e123o*rhs.q.e23oi+lhs.q.e23oi*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.b.e2o*rhs.s-lhs.q.e123o*rhs.q.e31oi+lhs.q.e31oi*rhs.q.e123o;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e3o*rhs.s-lhs.q.e123o*rhs.q.e12oi+lhs.q.e12oi*rhs.q.e123o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s+lhs.q.e123i*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.b.e2i*rhs.s+lhs.q.e123i*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e123i;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e3i*rhs.s+lhs.q.e123i*rhs.q.e12oi-lhs.q.e12oi*rhs.q.e123i;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.b.eoi*rhs.s+lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o+lhs.q.e123o*rhs.s+lhs.q.e123o*rhs.b.eoi-lhs.q.e12oi*rhs.b.e3o-lhs.q.e31oi*rhs.b.e2o-lhs.q.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i+lhs.q.e123i*rhs.s-lhs.q.e123i*rhs.b.eoi+lhs.q.e12oi*rhs.b.e3i+lhs.q.e31oi*rhs.b.e2i+lhs.q.e23oi*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23-lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.b.e31-lhs.q.e31oi*rhs.b.e12+lhs.q.e23oi*rhs.s;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31-lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.b.e23+lhs.q.e31oi*rhs.s+lhs.q.e23oi*rhs.b.e12;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12-lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.s+lhs.q.e31oi*rhs.b.e23-lhs.q.e23oi*rhs.b.e31;
    return result;
}

Versor inner(const Versor &lhs, const Versor &rhs)
{
    Versor result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi-lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.q.e12oi-lhs.q.e31oi*rhs.q.e31oi-lhs.q.e23oi*rhs.q.e23oi;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.eoi*rhs.q.e23oi+lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.eoi*rhs.q.e31oi+lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o+lhs.q.e31oi*rhs.b.eoi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi+lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.b.eoi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.q.e31oi-lhs.q.e123o*rhs.b.e23-lhs.q.e12oi*rhs.b.e2o+lhs.q.e31oi*rhs.b.e3o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.q.e12oi+lhs.b.e2o*rhs.s-lhs.b.e3o*rhs.q.e23oi-lhs.q.e123o*rhs.b.e31+lhs.q.e12oi*rhs.b.e1o-lhs.q.e23oi*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o-lhs.b.e1o*rhs.q.e31oi+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s-lhs.q.e123o*rhs.b.e12-lhs.q.e31oi*rhs.b.e1o+lhs.q.e23oi*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s-lhs.b.e23*rhs.q.e123i+lhs.b.e2i*rhs.q.e12oi-lhs.b.e3i*rhs.q.e31oi-lhs.q.e123i*rhs.b.e23+lhs.q.e12oi*rhs.b.e2i-lhs.q.e31oi*rhs.b.e3i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e31*rhs.q.e123i-lhs.b.e1i*rhs.q.e12oi+lhs.b.e2i*rhs.s+lhs.b.e3i*rhs.q.e23oi-lhs.q.e123i*rhs.b.e31-lhs.q.e12oi*rhs.b.e1i+lhs.q.e23oi*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e1i*rhs.q.e31oi-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.q.e123i*rhs.b.e12+lhs.q.e31oi*rhs.b.e1i-lhs.q.e23oi*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi+lhs.b.eoi*rhs.s-lhs.q.e12oi*rhs.b.e12-lhs.q.e31oi*rhs.b.e31-lhs.q.e23oi*rhs.b.e23;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.q.e123o*rhs.s;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.q.e123i*rhs.s;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.q.e23oi*rhs.s;
    result.q.e31oi = lhs.s*rhs.q.e31oi+lhs.q.e31oi*rhs.s;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.q.e12oi*rhs.s;
    return result;
}

Multivector operator*(const Versor &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi-lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.q.e12oi-lhs.q.e31oi*rhs.q.e31oi-lhs.q.e23oi*rhs.q.e23oi;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.t.e123+lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o-lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.t.e1oi+lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o+lhs.q.e12oi*rhs.t.e2oi-lhs.q.e31oi*rhs.t.e3oi-lhs.q.e23oi*rhs.p;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123-lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.v.e3-lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.t.e2oi+lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e12oi*rhs.t.e1oi-lhs.q.e31oi*rhs.p+lhs.q.e23oi*rhs.t.e3oi;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1+lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.v.e2-lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o-lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.t.e3oi+lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.p+lhs.q.e31oi*rhs.t.e1oi-lhs.q.e23oi*rhs.t.e2oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e1i*rhs.v.e1-0.5*lhs.b.e1i*rhs.t.e1oi+0.5*lhs.b.e23*rhs.t.e23i+0.5*lhs.b.e2i*rhs.v.e2-0.5*lhs.b.e2i*rhs.t.e2oi+0.5*lhs.b.e3i*rhs.v.e3-0.5*lhs.b.e3i*rhs.t.e3oi-0.5*lhs.b.eoi*rhs.v.ei-0.5*lhs.q.e123i*rhs.t.e123+0.5*lhs.q.e123i*rhs.p+0.5*lhs.q.e12oi*rhs.t.e12i+0.5*lhs.q.e31oi*rhs.t.e31i+0.5*lhs.q.e23oi*rhs.t.e23i;
    result.v.ei = lhs.s*rhs.v.ei-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e1i*rhs.v.e1+lhs.b.e1i*rhs.t.e1oi-lhs.b.e23*rhs.t.e23i-lhs.b.e2i*rhs.v.e2+lhs.b.e2i*rhs.t.e2oi-lhs.b.e3i*rhs.v.e3+lhs.b.e3i*rhs.t.e3oi+lhs.b.eoi*rhs.v.ei+lhs.q.e123i*rhs.t.e123-lhs.q.e123i*rhs.p-lhs.q.e12oi*rhs.t.e12i-lhs.q.e31oi*rhs.t.e31i-lhs.q.e23oi*rhs.t.e23i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o-lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.q.e23oi+lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e12oi+lhs.q.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s-lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.b.e12+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.q.e31oi+lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.q.e23oi+lhs.q.e31oi*rhs.b.eoi+lhs.q.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23+lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.b.e31-lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi+lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.b.eoi+lhs.q.e31oi*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e31oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o+lhs.b.e1o*rhs.s+lhs.b.e1o*rhs.b.eoi-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.b.e12-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.b.e31+lhs.b.e3o*rhs.q.e31oi-lhs.b.eoi*rhs.b.e1o-lhs.q.e123o*rhs.b.e23-lhs.q.e123o*rhs.q.e23oi-lhs.q.e12oi*rhs.b.e2o+lhs.q.e31oi*rhs.b.e3o+lhs.q.e23oi*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.b.e12+lhs.b.e1o*rhs.q.e12oi+lhs.b.e23*rhs.b.e3o+lhs.b.e2o*rhs.s+lhs.b.e2o*rhs.b.eoi-lhs.b.e3o*rhs.b.e23-lhs.b.e3o*rhs.q.e23oi-lhs.b.eoi*rhs.b.e2o-lhs.q.e123o*rhs.b.e31-lhs.q.e123o*rhs.q.e31oi+lhs.q.e12oi*rhs.b.e1o+lhs.q.e31oi*rhs.q.e123o-lhs.q.e23oi*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e1o*rhs.b.e31-lhs.b.e1o*rhs.q.e31oi-lhs.b.e23*rhs.b.e2o+lhs.b.e2o*rhs.b.e23+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s+lhs.b.e3o*rhs.b.eoi-lhs.b.eoi*rhs.b.e3o-lhs.q.e123o*rhs.b.e12-lhs.q.e123o*rhs.q.e12oi+lhs.q.e12oi*rhs.q.e123o-lhs.q.e31oi*rhs.b.e1o+lhs.q.e23oi*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i+lhs.b.e1i*rhs.s-lhs.b.e1i*rhs.b.eoi-lhs.b.e23*rhs.q.e123i-lhs.b.e2i*rhs.b.e12+lhs.b.e2i*rhs.q.e12oi+lhs.b.e3i*rhs.b.e31-lhs.b.e3i*rhs.q.e31oi+lhs.b.eoi*rhs.b.e1i-lhs.q.e123i*rhs.b.e23+lhs.q.e123i*rhs.q.e23oi+lhs.q.e12oi*rhs.b.e2i-lhs.q.e31oi*rhs.b.e3i-lhs.q.e23oi*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e1i*rhs.b.e12-lhs.b.e1i*rhs.q.e12oi+lhs.b.e23*rhs.b.e3i+lhs.b.e2i*rhs.s-lhs.b.e2i*rhs.b.eoi-lhs.b.e3i*rhs.b.e23+lhs.b.e3i*rhs.q.e23oi+lhs.b.eoi*rhs.b.e2i-lhs.q.e123i*rhs.b.e31+lhs.q.e123i*rhs.q.e31oi-lhs.q.e12oi*rhs.b.e1i-lhs.q.e31oi*rhs.q.e123i+lhs.q.e23oi*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e1i*rhs.b.e31+lhs.b.e1i*rhs.q.e31oi-lhs.b.e23*rhs.b.e2i+lhs.b.e2i*rhs.b.e23-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.b.e3i*rhs.b.eoi+lhs.b.eoi*rhs.b.e3i-lhs.q.e123i*rhs.b.e12+lhs.q.e123i*rhs.q.e12oi-lhs.q.e12oi*rhs.q.e123i+lhs.q.e31oi*rhs.b.e1i-lhs.q.e23oi*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.q.e23oi-lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o-lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.s+lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.b.e12-lhs.q.e31oi*rhs.b.e31-lhs.q.e23oi*rhs.b.e23;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2-lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.v.e1-lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o-lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.p-lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.q.e12oi*rhs.t.e3oi+lhs.q.e31oi*rhs.t.e2oi+lhs.q.e23oi*rhs.t.e1oi;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.b.e12*rhs.t.e31o-lhs.b.e31*rhs.t.e12o-lhs.b.e1o*rhs.t.e123-lhs.b.e1o*rhs.p+lhs.b.e23*rhs.v.eo-lhs.b.e2o*rhs.v.e3-lhs.b.e2o*rhs.t.e3oi+lhs.b.e3o*rhs.v.e2+lhs.b.e3o*rhs.t.e2oi-lhs.b.eoi*rhs.t.e23o-lhs.q.e123o*rhs.v.e1-lhs.q.e123o*rhs.t.e1oi-lhs.q.e12oi*rhs.t.e31o+lhs.q.e31oi*rhs.t.e12o-lhs.q.e23oi*rhs.v.eo;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.b.e12*rhs.t.e23o+lhs.b.e31*rhs.v.eo+lhs.b.e1o*rhs.v.e3+lhs.b.e1o*rhs.t.e3oi+lhs.b.e23*rhs.t.e12o-lhs.b.e2o*rhs.t.e123-lhs.b.e2o*rhs.p-lhs.b.e3o*rhs.v.e1-lhs.b.e3o*rhs.t.e1oi-lhs.b.eoi*rhs.t.e31o-lhs.q.e123o*rhs.v.e2-lhs.q.e123o*rhs.t.e2oi+lhs.q.e12oi*rhs.t.e23o-lhs.q.e31oi*rhs.v.eo-lhs.q.e23oi*rhs.t.e12o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.b.e12*rhs.v.eo+lhs.b.e31*rhs.t.e23o-lhs.b.e1o*rhs.v.e2-lhs.b.e1o*rhs.t.e2oi-lhs.b.e23*rhs.t.e31o+lhs.b.e2o*rhs.v.e1+lhs.b.e2o*rhs.t.e1oi-lhs.b.e3o*rhs.t.e123-lhs.b.e3o*rhs.p-lhs.b.eoi*rhs.t.e12o-lhs.q.e123o*rhs.v.e3-lhs.q.e123o*rhs.t.e3oi-lhs.q.e12oi*rhs.v.eo-lhs.q.e31oi*rhs.t.e23o+lhs.q.e23oi*rhs.t.e31o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e12*rhs.t.e31i-lhs.b.e31*rhs.t.e12i-lhs.b.e1i*rhs.t.e123+lhs.b.e1i*rhs.p+lhs.b.e23*rhs.v.ei-lhs.b.e2i*rhs.v.e3+lhs.b.e2i*rhs.t.e3oi+lhs.b.e3i*rhs.v.e2-lhs.b.e3i*rhs.t.e2oi+lhs.b.eoi*rhs.t.e23i-lhs.q.e123i*rhs.v.e1+lhs.q.e123i*rhs.t.e1oi+lhs.q.e12oi*rhs.t.e31i-lhs.q.e31oi*rhs.t.e12i+lhs.q.e23oi*rhs.v.ei;
    result.t.e31i = lhs.s*rhs.t.e31i-lhs.b.e12*rhs.t.e23i+lhs.b.e31*rhs.v.ei+lhs.b.e1i*rhs.v.e3-lhs.b.e1i*rhs.t.e3oi+lhs.b.e23*rhs.t.e12i-lhs.b.e2i*rhs.t.e123+lhs.b.e2i*rhs.p-lhs.b.e3i*rhs.v.e1+lhs.b.e3i*rhs.t.e1oi+lhs.b.eoi*rhs.t.e31i-lhs.q.e123i*rhs.v.e2+lhs.q.e123i*rhs.t.e2oi-lhs.q.e12oi*rhs.t.e23i+lhs.q.e31oi*rhs.v.ei+lhs.q.e23oi*rhs.t.e12i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e12*rhs.v.ei+lhs.b.e31*rhs.t.e23i-lhs.b.e1i*rhs.v.e2+lhs.b.e1i*rhs.t.e2oi-lhs.b.e23*rhs.t.e31i+lhs.b.e2i*rhs.v.e1-lhs.b.e2i*rhs.t.e1oi-lhs.b.e3i*rhs.t.e123+lhs.b.e3i*rhs.p+lhs.b.eoi*rhs.t.e12i-lhs.q.e123i*rhs.v.e3+lhs.q.e123i*rhs.t.e3oi+lhs.q.e12oi*rhs.v.ei+lhs.q.e31oi*rhs.t.e23i-lhs.q.e23oi*rhs.t.e31i;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.b.e12*rhs.t.e2oi-lhs.b.e31*rhs.t.e3oi+lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.p-lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o+lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.v.e1-lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o+lhs.q.e12oi*rhs.v.e2-lhs.q.e31oi*rhs.v.e3-lhs.q.e23oi*rhs.t.e123;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e12*rhs.t.e1oi-lhs.b.e31*rhs.p+lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.t.e3oi+lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo-lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.v.e2-lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e12oi*rhs.v.e1-lhs.q.e31oi*rhs.t.e123+lhs.q.e23oi*rhs.v.e3;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p+lhs.b.e31*rhs.t.e1oi-lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.t.e2oi+lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o+lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.v.e3-lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.t.e123+lhs.q.e31oi*rhs.v.e1-lhs.q.e23oi*rhs.v.e2;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o+lhs.q.e123o*rhs.s+lhs.q.e123o*rhs.b.eoi-lhs.q.e12oi*rhs.b.e3o-lhs.q.e31oi*rhs.b.e2o-lhs.q.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i+lhs.q.e123i*rhs.s-lhs.q.e123i*rhs.b.eoi+lhs.q.e12oi*rhs.b.e3i+lhs.q.e31oi*rhs.b.e2i+lhs.q.e23oi*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23-lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.b.e31-lhs.q.e31oi*rhs.b.e12+lhs.q.e23oi*rhs.s;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31-lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.b.e23+lhs.q.e31oi*rhs.s+lhs.q.e23oi*rhs.b.e12;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12-lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.s+lhs.q.e31oi*rhs.b.e23-lhs.q.e23oi*rhs.b.e31;
    result.p = lhs.s*rhs.p+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.t.e1oi+lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o+lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.t.e123+lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.q.e12oi*rhs.v.e3+lhs.q.e31oi*rhs.v.e2+lhs.q.e23oi*rhs.v.e1;
    return result;
}

Multivector outer(const Versor &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s;
    result.v.e1 = lhs.s*rhs.v.e1-lhs.q.e23oi*rhs.p;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.q.e31oi*rhs.p;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.q.e12oi*rhs.p;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.q.e123i*rhs.p;
    result.v.ei = lhs.s*rhs.v.ei-lhs.q.e123i*rhs.p;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e23*rhs.s+lhs.q.e12oi*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e12oi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s-lhs.q.e12oi*rhs.q.e23oi+lhs.q.e23oi*rhs.q.e12oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.q.e31oi*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e31oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s-lhs.q.e123o*rhs.q.e23oi+lhs.q.e23oi*rhs.q.e123o;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.b.e2o*rhs.s-lhs.q.e123o*rhs.q.e31oi+lhs.q.e31oi*rhs.q.e123o;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.b.e3o*rhs.s-lhs.q.e123o*rhs.q.e12oi+lhs.q.e12oi*rhs.q.e123o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s+lhs.q.e123i*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e123i;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.b.e2i*rhs.s+lhs.q.e123i*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e123i;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.b.e3i*rhs.s+lhs.q.e123i*rhs.q.e12oi-lhs.q.e12oi*rhs.q.e123i;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.b.eoi*rhs.s+lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2+lhs.b.e23*rhs.v.e1+lhs.b.eoi*rhs.p+lhs.q.e12oi*rhs.t.e3oi+lhs.q.e31oi*rhs.t.e2oi+lhs.q.e23oi*rhs.t.e1oi;
    result.t.e23o = lhs.s*rhs.t.e23o-lhs.b.e1o*rhs.p+lhs.b.e23*rhs.v.eo-lhs.b.e2o*rhs.v.e3+lhs.b.e3o*rhs.v.e2-lhs.q.e123o*rhs.t.e1oi-lhs.q.e12oi*rhs.t.e31o+lhs.q.e31oi*rhs.t.e12o;
    result.t.e31o = lhs.s*rhs.t.e31o+lhs.b.e31*rhs.v.eo+lhs.b.e1o*rhs.v.e3-lhs.b.e2o*rhs.p-lhs.b.e3o*rhs.v.e1-lhs.q.e123o*rhs.t.e2oi+lhs.q.e12oi*rhs.t.e23o-lhs.q.e23oi*rhs.t.e12o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.b.e12*rhs.v.eo-lhs.b.e1o*rhs.v.e2+lhs.b.e2o*rhs.v.e1-lhs.b.e3o*rhs.p-lhs.q.e123o*rhs.t.e3oi-lhs.q.e31oi*rhs.t.e23o+lhs.q.e23oi*rhs.t.e31o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e1i*rhs.p+lhs.b.e23*rhs.v.ei-lhs.b.e2i*rhs.v.e3+lhs.b.e3i*rhs.v.e2+lhs.q.e123i*rhs.t.e1oi+lhs.q.e12oi*rhs.t.e31i-lhs.q.e31oi*rhs.t.e12i;
    result.t.e31i = lhs.s*rhs.t.e31i+lhs.b.e31*rhs.v.ei+lhs.b.e1i*rhs.v.e3+lhs.b.e2i*rhs.p-lhs.b.e3i*rhs.v.e1+lhs.q.e123i*rhs.t.e2oi-lhs.q.e12oi*rhs.t.e23i+lhs.q.e23oi*rhs.t.e12i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e12*rhs.v.ei-lhs.b.e1i*rhs.v.e2+lhs.b.e2i*rhs.v.e1+lhs.b.e3i*rhs.p+lhs.q.e123i*rhs.t.e3oi+lhs.q.e31oi*rhs.t.e23i-lhs.q.e23oi*rhs.t.e31i;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.p+lhs.b.eoi*rhs.v.e1-lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o-lhs.q.e23oi*rhs.t.e123;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e31*rhs.p+lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.eoi*rhs.v.e2-lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e31oi*rhs.t.e123;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p+lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.v.e3-lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.t.e123;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o+lhs.q.e123o*rhs.s+lhs.q.e123o*rhs.b.eoi-lhs.q.e12oi*rhs.b.e3o-lhs.q.e31oi*rhs.b.e2o-lhs.q.e23oi*rhs.b.e1o;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i+lhs.q.e123i*rhs.s-lhs.q.e123i*rhs.b.eoi+lhs.q.e12oi*rhs.b.e3i+lhs.q.e31oi*rhs.b.e2i+lhs.q.e23oi*rhs.b.e1i;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23-lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.b.e31-lhs.q.e31oi*rhs.b.e12+lhs.q.e23oi*rhs.s;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31-lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.b.e23+lhs.q.e31oi*rhs.s+lhs.q.e23oi*rhs.b.e12;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12-lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.s+lhs.q.e31oi*rhs.b.e23-lhs.q.e23oi*rhs.b.e31;
    result.p = lhs.s*rhs.p+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.t.e1oi+lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o+lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.t.e123+lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.q.e12oi*rhs.v.e3+lhs.q.e31oi*rhs.v.e2+lhs.q.e23oi*rhs.v.e1;
    return result;
}

Multivector inner(const Versor &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi-lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.q.e12oi-lhs.q.e31oi*rhs.q.e31oi-lhs.q.e23oi*rhs.q.e23oi;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.t.e123+lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o-lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.t.e1oi+lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o+lhs.q.e12oi*rhs.t.e2oi-lhs.q.e31oi*rhs.t.e3oi-lhs.q.e23oi*rhs.p;
    result.v.e2 = lhs.s*rhs.v.e2-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123-lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.v.e3-lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.t.e2oi+lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e12oi*rhs.t.e1oi-lhs.q.e31oi*rhs.p+lhs.q.e23oi*rhs.t.e3oi;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1+lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.v.e2-lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o-lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.t.e3oi+lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.p+lhs.q.e31oi*rhs.t.e1oi-lhs.q.e23oi*rhs.t.e2oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e1i*rhs.v.e1-0.5*lhs.b.e1i*rhs.t.e1oi+0.5*lhs.b.e23*rhs.t.e23i+0.5*lhs.b.e2i*rhs.v.e2-0.5*lhs.b.e2i*rhs.t.e2oi+0.5*lhs.b.e3i*rhs.v.e3-0.5*lhs.b.e3i*rhs.t.e3oi-0.5*lhs.b.eoi*rhs.v.ei-0.5*lhs.q.e123i*rhs.t.e123+0.5*lhs.q.e123i*rhs.p+0.5*lhs.q.e12oi*rhs.t.e12i+0.5*lhs.q.e31oi*rhs.t.e31i+0.5*lhs.q.e23oi*rhs.t.e23i;
    result.v.ei = lhs.s*rhs.v.ei-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e1i*rhs.v.e1+lhs.b.e1i*rhs.t.e1oi-lhs.b.e23*rhs.t.e23i-lhs.b.e2i*rhs.v.e2+lhs.b.e2i*rhs.t.e2oi-lhs.b.e3i*rhs.v.e3+lhs.b.e3i*rhs.t.e3oi+lhs.b.eoi*rhs.v.ei+lhs.q.e123i*rhs.t.e123-lhs.q.e123i*rhs.p-lhs.q.e12oi*rhs.t.e12i-lhs.q.e31oi*rhs.t.e31i-lhs.q.e23oi*rhs.t.e23i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.eoi*rhs.q.e23oi+lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e23oi*rhs.b.eoi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.b.e31*rhs.s+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.eoi*rhs.q.e31oi+lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o+lhs.q.e31oi*rhs.b.eoi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.b.e12*rhs.s+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi+lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.b.eoi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.b.e1o*rhs.s-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.q.e31oi-lhs.q.e123o*rhs.b.e23-lhs.q.e12oi*rhs.b.e2o+lhs.q.e31oi*rhs.b.e3o;
    result.b.e2o = lhs.s*rhs.b.e2o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.q.e12oi+lhs.b.e2o*rhs.s-lhs.b.e3o*rhs.q.e23oi-lhs.q.e123o*rhs.b.e31+lhs.q.e12oi*rhs.b.e1o-lhs.q.e23oi*rhs.b.e3o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.b.e12*rhs.q.e123o-lhs.b.e1o*rhs.q.e31oi+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s-lhs.q.e123o*rhs.b.e12-lhs.q.e31oi*rhs.b.e1o+lhs.q.e23oi*rhs.b.e2o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.b.e1i*rhs.s-lhs.b.e23*rhs.q.e123i+lhs.b.e2i*rhs.q.e12oi-lhs.b.e3i*rhs.q.e31oi-lhs.q.e123i*rhs.b.e23+lhs.q.e12oi*rhs.b.e2i-lhs.q.e31oi*rhs.b.e3i;
    result.b.e2i = lhs.s*rhs.b.e2i-lhs.b.e31*rhs.q.e123i-lhs.b.e1i*rhs.q.e12oi+lhs.b.e2i*rhs.s+lhs.b.e3i*rhs.q.e23oi-lhs.q.e123i*rhs.b.e31-lhs.q.e12oi*rhs.b.e1i+lhs.q.e23oi*rhs.b.e3i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.b.e12*rhs.q.e123i+lhs.b.e1i*rhs.q.e31oi-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.q.e123i*rhs.b.e12+lhs.q.e31oi*rhs.b.e1i-lhs.q.e23oi*rhs.b.e2i;
    result.b.eoi = lhs.s*rhs.b.eoi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi+lhs.b.eoi*rhs.s-lhs.q.e12oi*rhs.b.e12-lhs.q.e31oi*rhs.b.e31-lhs.q.e23oi*rhs.b.e23;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.b.eoi*rhs.p-lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo;
    result.t.e23o = lhs.s*rhs.t.e23o-lhs.b.e1o*rhs.p-lhs.q.e123o*rhs.v.e1-lhs.q.e23oi*rhs.v.eo;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.b.e2o*rhs.p-lhs.q.e123o*rhs.v.e2-lhs.q.e31oi*rhs.v.eo;
    result.t.e12o = lhs.s*rhs.t.e12o-lhs.b.e3o*rhs.p-lhs.q.e123o*rhs.v.e3-lhs.q.e12oi*rhs.v.eo;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.b.e1i*rhs.p-lhs.q.e123i*rhs.v.e1+lhs.q.e23oi*rhs.v.ei;
    result.t.e31i = lhs.s*rhs.t.e31i+lhs.b.e2i*rhs.p-lhs.q.e123i*rhs.v.e2+lhs.q.e31oi*rhs.v.ei;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.b.e3i*rhs.p-lhs.q.e123i*rhs.v.e3+lhs.q.e12oi*rhs.v.ei;
    result.t.e1oi = lhs.s*rhs.t.e1oi-lhs.b.e23*rhs.p+lhs.q.e12oi*rhs.v.e2-lhs.q.e31oi*rhs.v.e3;
    result.t.e2oi = lhs.s*rhs.t.e2oi-lhs.b.e31*rhs.p-lhs.q.e12oi*rhs.v.e1+lhs.q.e23oi*rhs.v.e3;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.b.e12*rhs.p+lhs.q.e31oi*rhs.v.e1-lhs.q.e23oi*rhs.v.e2;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.q.e123o*rhs.s;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.q.e123i*rhs.s;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.q.e23oi*rhs.s;
    result.q.e31oi = lhs.s*rhs.q.e31oi+lhs.q.e31oi*rhs.s;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.q.e12oi*rhs.s;
    result.p = lhs.s*rhs.p;
    return result;
}

Multivector operator*(const Multivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s+lhs.v.e1*rhs.v.e1+lhs.v.e2*rhs.v.e2+lhs.v.e3*rhs.v.e3-lhs.v.eo*rhs.v.ei-lhs.v.ei*rhs.v.eo-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi-lhs.t.e123*rhs.t.e123+lhs.t.e12o*rhs.t.e12i+lhs.t.e12i*rhs.t.e12o+lhs.t.e31o*rhs.t.e31i+lhs.t.e31i*rhs.t.e31o+lhs.t.e1oi*rhs.t.e1oi+lhs.t.e23o*rhs.t.e23i+lhs.t.e23i*rhs.t.e23o+lhs.t.e2oi*rhs.t.e2oi+lhs.t.e3oi*rhs.t.e3oi-lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.q.e12oi-lhs.q.e31oi*rhs.q.e31oi-lhs.q.e23oi*rhs.q.e23oi-lhs.p*rhs.p;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.v.e1*rhs.s-lhs.v.e2*rhs.b.e12+lhs.v.e3*rhs.b.e31+lhs.v.eo*rhs.b.e1i+lhs.v.ei*rhs.b.e1o+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.t.e123+lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o-lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.t.e1oi-lhs.t.e123*rhs.b.e23+lhs.t.e12o*rhs.b.e2i+lhs.t.e12i*rhs.b.e2o-lhs.t.e31o*rhs.b.e3i-lhs.t.e31i*rhs.b.e3o+lhs.t.e1oi*rhs.b.eoi-lhs.t.e23o*rhs.q.e123i-lhs.t.e23i*rhs.q.e123o-lhs.t.e2oi*rhs.q.e12oi+lhs.t.e3oi*rhs.q.e31oi+lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o+lhs.q.e12oi*rhs.t.e2oi-lhs.q.e31oi*rhs.t.e3oi-lhs.q.e23oi*rhs.p-lhs.p*rhs.q.e23oi;
    result.v.e2 = lhs.s*rhs.v.e2+lhs.v.e1*rhs.b.e12+lhs.v.e2*rhs.s-lhs.v.e3*rhs.b.e23+lhs.v.eo*rhs.b.e2i+lhs.v.ei*rhs.b.e2o-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123-lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.v.e3-lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.t.e2oi-lhs.t.e123*rhs.b.e31-lhs.t.e12o*rhs.b.e1i-lhs.t.e12i*rhs.b.e1o-lhs.t.e31o*rhs.q.e123i-lhs.t.e31i*rhs.q.e123o+lhs.t.e1oi*rhs.q.e12oi+lhs.t.e23o*rhs.b.e3i+lhs.t.e23i*rhs.b.e3o+lhs.t.e2oi*rhs.b.eoi-lhs.t.e3oi*rhs.q.e23oi+lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e12oi*rhs.t.e1oi-lhs.q.e31oi*rhs.p+lhs.q.e23oi*rhs.t.e3oi-lhs.p*rhs.q.e31oi;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.v.e1*rhs.b.e31+lhs.v.e2*rhs.b.e23+lhs.v.e3*rhs.s+lhs.v.eo*rhs.b.e3i+lhs.v.ei*rhs.b.e3o-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1+lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.v.e2-lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o-lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.t.e3oi-lhs.t.e123*rhs.b.e12-lhs.t.e12o*rhs.q.e123i-lhs.t.e12i*rhs.q.e123o+lhs.t.e31o*rhs.b.e1i+lhs.t.e31i*rhs.b.e1o-lhs.t.e1oi*rhs.q.e31oi-lhs.t.e23o*rhs.b.e2i-lhs.t.e23i*rhs.b.e2o+lhs.t.e2oi*rhs.q.e23oi+lhs.t.e3oi*rhs.b.eoi+lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.p+lhs.q.e31oi*rhs.t.e1oi-lhs.q.e23oi*rhs.t.e2oi-lhs.p*rhs.q.e12oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei-0.5*lhs.v.e1*rhs.b.e1i-0.5*lhs.v.e2*rhs.b.e2i-0.5*lhs.v.e3*rhs.b.e3i-0.5*lhs.v.ei*rhs.s+0.5*lhs.v.ei*rhs.b.eoi+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e1i*rhs.v.e1-0.5*lhs.b.e1i*rhs.t.e1oi+0.5*lhs.b.e23*rhs.t.e23i+0.5*lhs.b.e2i*rhs.v.e2-0.5*lhs.b.e2i*rhs.t.e2oi+0.5*lhs.b.e3i*rhs.v.e3-0.5*lhs.b.e3i*rhs.t.e3oi-0.5*lhs.b.eoi*rhs.v.ei+0.5*lhs.t.e123*rhs.q.e123i+0.5*lhs.t.e12i*rhs.b.e12-0.5*lhs.t.e12i*rhs.q.e12oi+0.5*lhs.t.e31i*rhs.b.e31-0.5*lhs.t.e31i*rhs.q.e31oi-0.5*lhs.t.e1oi*rhs.b.e1i+0.5*lhs.t.e23i*rhs.b.e23-0.5*lhs.t.e23i*rhs.q.e23oi-0.5*lhs.t.e2oi*rhs.b.e2i-0.5*lhs.t.e3oi*rhs.b.e3i-0.5*lhs.q.e123i*rhs.t.e123+0.5*lhs.q.e123i*rhs.p+0.5*lhs.q.e12oi*rhs.t.e12i+0.5*lhs.q.e31oi*rhs.t.e31i+0.5*lhs.q.e23oi*rhs.t.e23i+0.5*lhs.p*rhs.q.e123i;
    result.v.ei = lhs.s*rhs.v.ei+lhs.v.e1*rhs.b.e1i+lhs.v.e2*rhs.b.e2i+lhs.v.e3*rhs.b.e3i+lhs.v.ei*rhs.s-lhs.v.ei*rhs.b.eoi-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e1i*rhs.v.e1+lhs.b.e1i*rhs.t.e1oi-lhs.b.e23*rhs.t.e23i-lhs.b.e2i*rhs.v.e2+lhs.b.e2i*rhs.t.e2oi-lhs.b.e3i*rhs.v.e3+lhs.b.e3i*rhs.t.e3oi+lhs.b.eoi*rhs.v.ei-lhs.t.e123*rhs.q.e123i-lhs.t.e12i*rhs.b.e12+lhs.t.e12i*rhs.q.e12oi-lhs.t.e31i*rhs.b.e31+lhs.t.e31i*rhs.q.e31oi+lhs.t.e1oi*rhs.b.e1i-lhs.t.e23i*rhs.b.e23+lhs.t.e23i*rhs.q.e23oi+lhs.t.e2oi*rhs.b.e2i+lhs.t.e3oi*rhs.b.e3i+lhs.q.e123i*rhs.t.e123-lhs.q.e123i*rhs.p-lhs.q.e12oi*rhs.t.e12i-lhs.q.e31oi*rhs.t.e31i-lhs.q.e23oi*rhs.t.e23i-lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.v.e1*rhs.t.e123+lhs.v.e2*rhs.v.e3-lhs.v.e3*rhs.v.e2-lhs.v.eo*rhs.t.e23i-lhs.v.ei*rhs.t.e23o+lhs.b.e12*rhs.b.e31-lhs.b.e31*rhs.b.e12+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o-lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.q.e23oi+lhs.t.e123*rhs.v.e1-lhs.t.e12o*rhs.t.e31i-lhs.t.e12i*rhs.t.e31o+lhs.t.e31o*rhs.t.e12i+lhs.t.e31i*rhs.t.e12o+lhs.t.e1oi*rhs.p-lhs.t.e23o*rhs.v.ei-lhs.t.e23i*rhs.v.eo+lhs.t.e2oi*rhs.t.e3oi-lhs.t.e3oi*rhs.t.e2oi+lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e12oi+lhs.q.e23oi*rhs.b.eoi+lhs.p*rhs.t.e1oi;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.v.e1*rhs.v.e3+lhs.v.e2*rhs.t.e123+lhs.v.e3*rhs.v.e1-lhs.v.eo*rhs.t.e31i-lhs.v.ei*rhs.t.e31o-lhs.b.e12*rhs.b.e23+lhs.b.e31*rhs.s-lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.b.e12+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.q.e31oi+lhs.t.e123*rhs.v.e2+lhs.t.e12o*rhs.t.e23i+lhs.t.e12i*rhs.t.e23o-lhs.t.e31o*rhs.v.ei-lhs.t.e31i*rhs.v.eo-lhs.t.e1oi*rhs.t.e3oi-lhs.t.e23o*rhs.t.e12i-lhs.t.e23i*rhs.t.e12o+lhs.t.e2oi*rhs.p+lhs.t.e3oi*rhs.t.e1oi+lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.q.e23oi+lhs.q.e31oi*rhs.b.eoi+lhs.q.e23oi*rhs.q.e12oi+lhs.p*rhs.t.e2oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.v.e1*rhs.v.e2-lhs.v.e2*rhs.v.e1+lhs.v.e3*rhs.t.e123-lhs.v.eo*rhs.t.e12i-lhs.v.ei*rhs.t.e12o+lhs.b.e12*rhs.s+lhs.b.e31*rhs.b.e23+lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.b.e31-lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi+lhs.t.e123*rhs.v.e3-lhs.t.e12o*rhs.v.ei-lhs.t.e12i*rhs.v.eo-lhs.t.e31o*rhs.t.e23i-lhs.t.e31i*rhs.t.e23o+lhs.t.e1oi*rhs.t.e2oi+lhs.t.e23o*rhs.t.e31i+lhs.t.e23i*rhs.t.e31o-lhs.t.e2oi*rhs.t.e1oi+lhs.t.e3oi*rhs.p+lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.b.eoi+lhs.q.e31oi*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e31oi+lhs.p*rhs.t.e3oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.v.e1*rhs.v.eo-lhs.v.e2*rhs.t.e12o+lhs.v.e3*rhs.t.e31o-lhs.v.eo*rhs.v.e1-lhs.v.eo*rhs.t.e1oi+lhs.b.e12*rhs.b.e2o-lhs.b.e31*rhs.b.e3o+lhs.b.e1o*rhs.s+lhs.b.e1o*rhs.b.eoi-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.b.e12-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.b.e31+lhs.b.e3o*rhs.q.e31oi-lhs.b.eoi*rhs.b.e1o-lhs.t.e123*rhs.t.e23o-lhs.t.e12o*rhs.v.e2-lhs.t.e12o*rhs.t.e2oi+lhs.t.e31o*rhs.v.e3+lhs.t.e31o*rhs.t.e3oi-lhs.t.e1oi*rhs.v.eo+lhs.t.e23o*rhs.t.e123+lhs.t.e23o*rhs.p+lhs.t.e2oi*rhs.t.e12o-lhs.t.e3oi*rhs.t.e31o-lhs.q.e123o*rhs.b.e23-lhs.q.e123o*rhs.q.e23oi-lhs.q.e12oi*rhs.b.e2o+lhs.q.e31oi*rhs.b.e3o+lhs.q.e23oi*rhs.q.e123o+lhs.p*rhs.t.e23o;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.v.e1*rhs.t.e12o+lhs.v.e2*rhs.v.eo-lhs.v.e3*rhs.t.e23o-lhs.v.eo*rhs.v.e2-lhs.v.eo*rhs.t.e2oi-lhs.b.e12*rhs.b.e1o-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.b.e12+lhs.b.e1o*rhs.q.e12oi+lhs.b.e23*rhs.b.e3o+lhs.b.e2o*rhs.s+lhs.b.e2o*rhs.b.eoi-lhs.b.e3o*rhs.b.e23-lhs.b.e3o*rhs.q.e23oi-lhs.b.eoi*rhs.b.e2o-lhs.t.e123*rhs.t.e31o+lhs.t.e12o*rhs.v.e1+lhs.t.e12o*rhs.t.e1oi+lhs.t.e31o*rhs.t.e123+lhs.t.e31o*rhs.p-lhs.t.e1oi*rhs.t.e12o-lhs.t.e23o*rhs.v.e3-lhs.t.e23o*rhs.t.e3oi-lhs.t.e2oi*rhs.v.eo+lhs.t.e3oi*rhs.t.e23o-lhs.q.e123o*rhs.b.e31-lhs.q.e123o*rhs.q.e31oi+lhs.q.e12oi*rhs.b.e1o+lhs.q.e31oi*rhs.q.e123o-lhs.q.e23oi*rhs.b.e3o+lhs.p*rhs.t.e31o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.v.e1*rhs.t.e31o+lhs.v.e2*rhs.t.e23o+lhs.v.e3*rhs.v.eo-lhs.v.eo*rhs.v.e3-lhs.v.eo*rhs.t.e3oi-lhs.b.e12*rhs.q.e123o+lhs.b.e31*rhs.b.e1o-lhs.b.e1o*rhs.b.e31-lhs.b.e1o*rhs.q.e31oi-lhs.b.e23*rhs.b.e2o+lhs.b.e2o*rhs.b.e23+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s+lhs.b.e3o*rhs.b.eoi-lhs.b.eoi*rhs.b.e3o-lhs.t.e123*rhs.t.e12o+lhs.t.e12o*rhs.t.e123+lhs.t.e12o*rhs.p-lhs.t.e31o*rhs.v.e1-lhs.t.e31o*rhs.t.e1oi+lhs.t.e1oi*rhs.t.e31o+lhs.t.e23o*rhs.v.e2+lhs.t.e23o*rhs.t.e2oi-lhs.t.e2oi*rhs.t.e23o-lhs.t.e3oi*rhs.v.eo-lhs.q.e123o*rhs.b.e12-lhs.q.e123o*rhs.q.e12oi+lhs.q.e12oi*rhs.q.e123o-lhs.q.e31oi*rhs.b.e1o+lhs.q.e23oi*rhs.b.e2o+lhs.p*rhs.t.e12o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.v.e1*rhs.v.ei-lhs.v.e2*rhs.t.e12i+lhs.v.e3*rhs.t.e31i-lhs.v.ei*rhs.v.e1+lhs.v.ei*rhs.t.e1oi+lhs.b.e12*rhs.b.e2i-lhs.b.e31*rhs.b.e3i+lhs.b.e1i*rhs.s-lhs.b.e1i*rhs.b.eoi-lhs.b.e23*rhs.q.e123i-lhs.b.e2i*rhs.b.e12+lhs.b.e2i*rhs.q.e12oi+lhs.b.e3i*rhs.b.e31-lhs.b.e3i*rhs.q.e31oi+lhs.b.eoi*rhs.b.e1i-lhs.t.e123*rhs.t.e23i-lhs.t.e12i*rhs.v.e2+lhs.t.e12i*rhs.t.e2oi+lhs.t.e31i*rhs.v.e3-lhs.t.e31i*rhs.t.e3oi+lhs.t.e1oi*rhs.v.ei+lhs.t.e23i*rhs.t.e123-lhs.t.e23i*rhs.p-lhs.t.e2oi*rhs.t.e12i+lhs.t.e3oi*rhs.t.e31i-lhs.q.e123i*rhs.b.e23+lhs.q.e123i*rhs.q.e23oi+lhs.q.e12oi*rhs.b.e2i-lhs.q.e31oi*rhs.b.e3i-lhs.q.e23oi*rhs.q.e123i-lhs.p*rhs.t.e23i;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.v.e1*rhs.t.e12i+lhs.v.e2*rhs.v.ei-lhs.v.e3*rhs.t.e23i-lhs.v.ei*rhs.v.e2+lhs.v.ei*rhs.t.e2oi-lhs.b.e12*rhs.b.e1i-lhs.b.e31*rhs.q.e123i+lhs.b.e1i*rhs.b.e12-lhs.b.e1i*rhs.q.e12oi+lhs.b.e23*rhs.b.e3i+lhs.b.e2i*rhs.s-lhs.b.e2i*rhs.b.eoi-lhs.b.e3i*rhs.b.e23+lhs.b.e3i*rhs.q.e23oi+lhs.b.eoi*rhs.b.e2i-lhs.t.e123*rhs.t.e31i+lhs.t.e12i*rhs.v.e1-lhs.t.e12i*rhs.t.e1oi+lhs.t.e31i*rhs.t.e123-lhs.t.e31i*rhs.p+lhs.t.e1oi*rhs.t.e12i-lhs.t.e23i*rhs.v.e3+lhs.t.e23i*rhs.t.e3oi+lhs.t.e2oi*rhs.v.ei-lhs.t.e3oi*rhs.t.e23i-lhs.q.e123i*rhs.b.e31+lhs.q.e123i*rhs.q.e31oi-lhs.q.e12oi*rhs.b.e1i-lhs.q.e31oi*rhs.q.e123i+lhs.q.e23oi*rhs.b.e3i-lhs.p*rhs.t.e31i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.v.e1*rhs.t.e31i+lhs.v.e2*rhs.t.e23i+lhs.v.e3*rhs.v.ei-lhs.v.ei*rhs.v.e3+lhs.v.ei*rhs.t.e3oi-lhs.b.e12*rhs.q.e123i+lhs.b.e31*rhs.b.e1i-lhs.b.e1i*rhs.b.e31+lhs.b.e1i*rhs.q.e31oi-lhs.b.e23*rhs.b.e2i+lhs.b.e2i*rhs.b.e23-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.b.e3i*rhs.b.eoi+lhs.b.eoi*rhs.b.e3i-lhs.t.e123*rhs.t.e12i+lhs.t.e12i*rhs.t.e123-lhs.t.e12i*rhs.p-lhs.t.e31i*rhs.v.e1+lhs.t.e31i*rhs.t.e1oi-lhs.t.e1oi*rhs.t.e31i+lhs.t.e23i*rhs.v.e2-lhs.t.e23i*rhs.t.e2oi+lhs.t.e2oi*rhs.t.e23i+lhs.t.e3oi*rhs.v.ei-lhs.q.e123i*rhs.b.e12+lhs.q.e123i*rhs.q.e12oi-lhs.q.e12oi*rhs.q.e123i+lhs.q.e31oi*rhs.b.e1i-lhs.q.e23oi*rhs.b.e2i-lhs.p*rhs.t.e12i;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.v.e1*rhs.t.e1oi+lhs.v.e2*rhs.t.e2oi+lhs.v.e3*rhs.t.e3oi+lhs.v.eo*rhs.v.ei-lhs.v.ei*rhs.v.eo-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.q.e23oi-lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o-lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.s-lhs.t.e123*rhs.p-lhs.t.e12o*rhs.t.e12i+lhs.t.e12i*rhs.t.e12o-lhs.t.e31o*rhs.t.e31i+lhs.t.e31i*rhs.t.e31o+lhs.t.e1oi*rhs.v.e1-lhs.t.e23o*rhs.t.e23i+lhs.t.e23i*rhs.t.e23o+lhs.t.e2oi*rhs.v.e2+lhs.t.e3oi*rhs.v.e3+lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.b.e12-lhs.q.e31oi*rhs.b.e31-lhs.q.e23oi*rhs.b.e23-lhs.p*rhs.t.e123;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.v.e1*rhs.b.e23+lhs.v.e2*rhs.b.e31+lhs.v.e3*rhs.b.e12+lhs.v.eo*rhs.q.e123i+lhs.v.ei*rhs.q.e123o+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2-lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.v.e1-lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o-lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.p+lhs.t.e123*rhs.s+lhs.t.e12o*rhs.b.e3i+lhs.t.e12i*rhs.b.e3o+lhs.t.e31o*rhs.b.e2i+lhs.t.e31i*rhs.b.e2o+lhs.t.e1oi*rhs.q.e23oi+lhs.t.e23o*rhs.b.e1i+lhs.t.e23i*rhs.b.e1o+lhs.t.e2oi*rhs.q.e31oi+lhs.t.e3oi*rhs.q.e12oi-lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.q.e12oi*rhs.t.e3oi+lhs.q.e31oi*rhs.t.e2oi+lhs.q.e23oi*rhs.t.e1oi+lhs.p*rhs.b.eoi;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.v.e1*rhs.q.e123o+lhs.v.e2*rhs.b.e3o-lhs.v.e3*rhs.b.e2o+lhs.v.eo*rhs.b.e23+lhs.v.eo*rhs.q.e23oi+lhs.b.e12*rhs.t.e31o-lhs.b.e31*rhs.t.e12o-lhs.b.e1o*rhs.t.e123-lhs.b.e1o*rhs.p+lhs.b.e23*rhs.v.eo-lhs.b.e2o*rhs.v.e3-lhs.b.e2o*rhs.t.e3oi+lhs.b.e3o*rhs.v.e2+lhs.b.e3o*rhs.t.e2oi-lhs.b.eoi*rhs.t.e23o+lhs.t.e123*rhs.b.e1o+lhs.t.e12o*rhs.b.e31+lhs.t.e12o*rhs.q.e31oi-lhs.t.e31o*rhs.b.e12-lhs.t.e31o*rhs.q.e12oi-lhs.t.e1oi*rhs.q.e123o+lhs.t.e23o*rhs.s+lhs.t.e23o*rhs.b.eoi-lhs.t.e2oi*rhs.b.e3o+lhs.t.e3oi*rhs.b.e2o-lhs.q.e123o*rhs.v.e1-lhs.q.e123o*rhs.t.e1oi-lhs.q.e12oi*rhs.t.e31o+lhs.q.e31oi*rhs.t.e12o-lhs.q.e23oi*rhs.v.eo-lhs.p*rhs.b.e1o;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.v.e1*rhs.b.e3o+lhs.v.e2*rhs.q.e123o+lhs.v.e3*rhs.b.e1o+lhs.v.eo*rhs.b.e31+lhs.v.eo*rhs.q.e31oi-lhs.b.e12*rhs.t.e23o+lhs.b.e31*rhs.v.eo+lhs.b.e1o*rhs.v.e3+lhs.b.e1o*rhs.t.e3oi+lhs.b.e23*rhs.t.e12o-lhs.b.e2o*rhs.t.e123-lhs.b.e2o*rhs.p-lhs.b.e3o*rhs.v.e1-lhs.b.e3o*rhs.t.e1oi-lhs.b.eoi*rhs.t.e31o+lhs.t.e123*rhs.b.e2o-lhs.t.e12o*rhs.b.e23-lhs.t.e12o*rhs.q.e23oi+lhs.t.e31o*rhs.s+lhs.t.e31o*rhs.b.eoi+lhs.t.e1oi*rhs.b.e3o+lhs.t.e23o*rhs.b.e12+lhs.t.e23o*rhs.q.e12oi-lhs.t.e2oi*rhs.q.e123o-lhs.t.e3oi*rhs.b.e1o-lhs.q.e123o*rhs.v.e2-lhs.q.e123o*rhs.t.e2oi+lhs.q.e12oi*rhs.t.e23o-lhs.q.e31oi*rhs.v.eo-lhs.q.e23oi*rhs.t.e12o-lhs.p*rhs.b.e2o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.v.e1*rhs.b.e2o-lhs.v.e2*rhs.b.e1o+lhs.v.e3*rhs.q.e123o+lhs.v.eo*rhs.b.e12+lhs.v.eo*rhs.q.e12oi+lhs.b.e12*rhs.v.eo+lhs.b.e31*rhs.t.e23o-lhs.b.e1o*rhs.v.e2-lhs.b.e1o*rhs.t.e2oi-lhs.b.e23*rhs.t.e31o+lhs.b.e2o*rhs.v.e1+lhs.b.e2o*rhs.t.e1oi-lhs.b.e3o*rhs.t.e123-lhs.b.e3o*rhs.p-lhs.b.eoi*rhs.t.e12o+lhs.t.e123*rhs.b.e3o+lhs.t.e12o*rhs.s+lhs.t.e12o*rhs.b.eoi+lhs.t.e31o*rhs.b.e23+lhs.t.e31o*rhs.q.e23oi-lhs.t.e1oi*rhs.b.e2o-lhs.t.e23o*rhs.b.e31-lhs.t.e23o*rhs.q.e31oi+lhs.t.e2oi*rhs.b.e1o-lhs.t.e3oi*rhs.q.e123o-lhs.q.e123o*rhs.v.e3-lhs.q.e123o*rhs.t.e3oi-lhs.q.e12oi*rhs.v.eo-lhs.q.e31oi*rhs.t.e23o+lhs.q.e23oi*rhs.t.e31o-lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.v.e1*rhs.q.e123i+lhs.v.e2*rhs.b.e3i-lhs.v.e3*rhs.b.e2i+lhs.v.ei*rhs.b.e23-lhs.v.ei*rhs.q.e23oi+lhs.b.e12*rhs.t.e31i-lhs.b.e31*rhs.t.e12i-lhs.b.e1i*rhs.t.e123+lhs.b.e1i*rhs.p+lhs.b.e23*rhs.v.ei-lhs.b.e2i*rhs.v.e3+lhs.b.e2i*rhs.t.e3oi+lhs.b.e3i*rhs.v.e2-lhs.b.e3i*rhs.t.e2oi+lhs.b.eoi*rhs.t.e23i+lhs.t.e123*rhs.b.e1i+lhs.t.e12i*rhs.b.e31-lhs.t.e12i*rhs.q.e31oi-lhs.t.e31i*rhs.b.e12+lhs.t.e31i*rhs.q.e12oi+lhs.t.e1oi*rhs.q.e123i+lhs.t.e23i*rhs.s-lhs.t.e23i*rhs.b.eoi+lhs.t.e2oi*rhs.b.e3i-lhs.t.e3oi*rhs.b.e2i-lhs.q.e123i*rhs.v.e1+lhs.q.e123i*rhs.t.e1oi+lhs.q.e12oi*rhs.t.e31i-lhs.q.e31oi*rhs.t.e12i+lhs.q.e23oi*rhs.v.ei+lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.s*rhs.t.e31i-lhs.v.e1*rhs.b.e3i+lhs.v.e2*rhs.q.e123i+lhs.v.e3*rhs.b.e1i+lhs.v.ei*rhs.b.e31-lhs.v.ei*rhs.q.e31oi-lhs.b.e12*rhs.t.e23i+lhs.b.e31*rhs.v.ei+lhs.b.e1i*rhs.v.e3-lhs.b.e1i*rhs.t.e3oi+lhs.b.e23*rhs.t.e12i-lhs.b.e2i*rhs.t.e123+lhs.b.e2i*rhs.p-lhs.b.e3i*rhs.v.e1+lhs.b.e3i*rhs.t.e1oi+lhs.b.eoi*rhs.t.e31i+lhs.t.e123*rhs.b.e2i-lhs.t.e12i*rhs.b.e23+lhs.t.e12i*rhs.q.e23oi+lhs.t.e31i*rhs.s-lhs.t.e31i*rhs.b.eoi-lhs.t.e1oi*rhs.b.e3i+lhs.t.e23i*rhs.b.e12-lhs.t.e23i*rhs.q.e12oi+lhs.t.e2oi*rhs.q.e123i+lhs.t.e3oi*rhs.b.e1i-lhs.q.e123i*rhs.v.e2+lhs.q.e123i*rhs.t.e2oi-lhs.q.e12oi*rhs.t.e23i+lhs.q.e31oi*rhs.v.ei+lhs.q.e23oi*rhs.t.e12i+lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.v.e1*rhs.b.e2i-lhs.v.e2*rhs.b.e1i+lhs.v.e3*rhs.q.e123i+lhs.v.ei*rhs.b.e12-lhs.v.ei*rhs.q.e12oi+lhs.b.e12*rhs.v.ei+lhs.b.e31*rhs.t.e23i-lhs.b.e1i*rhs.v.e2+lhs.b.e1i*rhs.t.e2oi-lhs.b.e23*rhs.t.e31i+lhs.b.e2i*rhs.v.e1-lhs.b.e2i*rhs.t.e1oi-lhs.b.e3i*rhs.t.e123+lhs.b.e3i*rhs.p+lhs.b.eoi*rhs.t.e12i+lhs.t.e123*rhs.b.e3i+lhs.t.e12i*rhs.s-lhs.t.e12i*rhs.b.eoi+lhs.t.e31i*rhs.b.e23-lhs.t.e31i*rhs.q.e23oi+lhs.t.e1oi*rhs.b.e2i-lhs.t.e23i*rhs.b.e31+lhs.t.e23i*rhs.q.e31oi-lhs.t.e2oi*rhs.b.e1i+lhs.t.e3oi*rhs.q.e123i-lhs.q.e123i*rhs.v.e3+lhs.q.e123i*rhs.t.e3oi+lhs.q.e12oi*rhs.v.ei+lhs.q.e31oi*rhs.t.e23i-lhs.q.e23oi*rhs.t.e31i+lhs.p*rhs.b.e3i;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.v.e1*rhs.b.eoi-lhs.v.e2*rhs.q.e12oi+lhs.v.e3*rhs.q.e31oi-lhs.v.eo*rhs.b.e1i+lhs.v.ei*rhs.b.e1o+lhs.b.e12*rhs.t.e2oi-lhs.b.e31*rhs.t.e3oi+lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.p-lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o+lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.v.e1-lhs.t.e123*rhs.q.e23oi-lhs.t.e12o*rhs.b.e2i+lhs.t.e12i*rhs.b.e2o+lhs.t.e31o*rhs.b.e3i-lhs.t.e31i*rhs.b.e3o+lhs.t.e1oi*rhs.s+lhs.t.e23o*rhs.q.e123i-lhs.t.e23i*rhs.q.e123o-lhs.t.e2oi*rhs.b.e12+lhs.t.e3oi*rhs.b.e31-lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o+lhs.q.e12oi*rhs.v.e2-lhs.q.e31oi*rhs.v.e3-lhs.q.e23oi*rhs.t.e123-lhs.p*rhs.b.e23;
    result.t.e2oi = lhs.s*rhs.t.e2oi+lhs.v.e1*rhs.q.e12oi+lhs.v.e2*rhs.b.eoi-lhs.v.e3*rhs.q.e23oi-lhs.v.eo*rhs.b.e2i+lhs.v.ei*rhs.b.e2o-lhs.b.e12*rhs.t.e1oi-lhs.b.e31*rhs.p+lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.t.e3oi+lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo-lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.v.e2-lhs.t.e123*rhs.q.e31oi+lhs.t.e12o*rhs.b.e1i-lhs.t.e12i*rhs.b.e1o+lhs.t.e31o*rhs.q.e123i-lhs.t.e31i*rhs.q.e123o+lhs.t.e1oi*rhs.b.e12-lhs.t.e23o*rhs.b.e3i+lhs.t.e23i*rhs.b.e3o+lhs.t.e2oi*rhs.s-lhs.t.e3oi*rhs.b.e23-lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e12oi*rhs.v.e1-lhs.q.e31oi*rhs.t.e123+lhs.q.e23oi*rhs.v.e3-lhs.p*rhs.b.e31;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.v.e1*rhs.q.e31oi+lhs.v.e2*rhs.q.e23oi+lhs.v.e3*rhs.b.eoi-lhs.v.eo*rhs.b.e3i+lhs.v.ei*rhs.b.e3o-lhs.b.e12*rhs.p+lhs.b.e31*rhs.t.e1oi-lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.t.e2oi+lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o+lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.v.e3-lhs.t.e123*rhs.q.e12oi+lhs.t.e12o*rhs.q.e123i-lhs.t.e12i*rhs.q.e123o-lhs.t.e31o*rhs.b.e1i+lhs.t.e31i*rhs.b.e1o-lhs.t.e1oi*rhs.b.e31+lhs.t.e23o*rhs.b.e2i-lhs.t.e23i*rhs.b.e2o+lhs.t.e2oi*rhs.b.e23+lhs.t.e3oi*rhs.s-lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.t.e123+lhs.q.e31oi*rhs.v.e1-lhs.q.e23oi*rhs.v.e2-lhs.p*rhs.b.e12;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.v.e1*rhs.t.e23o+lhs.v.e2*rhs.t.e31o+lhs.v.e3*rhs.t.e12o-lhs.v.eo*rhs.t.e123-lhs.v.eo*rhs.p+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o+lhs.t.e123*rhs.v.eo-lhs.t.e12o*rhs.v.e3-lhs.t.e12o*rhs.t.e3oi-lhs.t.e31o*rhs.v.e2-lhs.t.e31o*rhs.t.e2oi-lhs.t.e1oi*rhs.t.e23o-lhs.t.e23o*rhs.v.e1-lhs.t.e23o*rhs.t.e1oi-lhs.t.e2oi*rhs.t.e31o-lhs.t.e3oi*rhs.t.e12o+lhs.q.e123o*rhs.s+lhs.q.e123o*rhs.b.eoi-lhs.q.e12oi*rhs.b.e3o-lhs.q.e31oi*rhs.b.e2o-lhs.q.e23oi*rhs.b.e1o-lhs.p*rhs.v.eo;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.v.e1*rhs.t.e23i+lhs.v.e2*rhs.t.e31i+lhs.v.e3*rhs.t.e12i-lhs.v.ei*rhs.t.e123+lhs.v.ei*rhs.p+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i+lhs.t.e123*rhs.v.ei-lhs.t.e12i*rhs.v.e3+lhs.t.e12i*rhs.t.e3oi-lhs.t.e31i*rhs.v.e2+lhs.t.e31i*rhs.t.e2oi+lhs.t.e1oi*rhs.t.e23i-lhs.t.e23i*rhs.v.e1+lhs.t.e23i*rhs.t.e1oi+lhs.t.e2oi*rhs.t.e31i+lhs.t.e3oi*rhs.t.e12i+lhs.q.e123i*rhs.s-lhs.q.e123i*rhs.b.eoi+lhs.q.e12oi*rhs.b.e3i+lhs.q.e31oi*rhs.b.e2i+lhs.q.e23oi*rhs.b.e1i+lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.v.e1*rhs.p+lhs.v.e2*rhs.t.e3oi-lhs.v.e3*rhs.t.e2oi+lhs.v.eo*rhs.t.e23i-lhs.v.ei*rhs.t.e23o+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23+lhs.t.e123*rhs.t.e1oi+lhs.t.e12o*rhs.t.e31i-lhs.t.e12i*rhs.t.e31o-lhs.t.e31o*rhs.t.e12i+lhs.t.e31i*rhs.t.e12o+lhs.t.e1oi*rhs.t.e123+lhs.t.e23o*rhs.v.ei-lhs.t.e23i*rhs.v.eo+lhs.t.e2oi*rhs.v.e3-lhs.t.e3oi*rhs.v.e2-lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.b.e31-lhs.q.e31oi*rhs.b.e12+lhs.q.e23oi*rhs.s+lhs.p*rhs.v.e1;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.v.e1*rhs.t.e3oi+lhs.v.e2*rhs.p+lhs.v.e3*rhs.t.e1oi+lhs.v.eo*rhs.t.e31i-lhs.v.ei*rhs.t.e31o-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31+lhs.t.e123*rhs.t.e2oi-lhs.t.e12o*rhs.t.e23i+lhs.t.e12i*rhs.t.e23o+lhs.t.e31o*rhs.v.ei-lhs.t.e31i*rhs.v.eo-lhs.t.e1oi*rhs.v.e3+lhs.t.e23o*rhs.t.e12i-lhs.t.e23i*rhs.t.e12o+lhs.t.e2oi*rhs.t.e123+lhs.t.e3oi*rhs.v.e1-lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.b.e23+lhs.q.e31oi*rhs.s+lhs.q.e23oi*rhs.b.e12+lhs.p*rhs.v.e2;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.v.e1*rhs.t.e2oi-lhs.v.e2*rhs.t.e1oi+lhs.v.e3*rhs.p+lhs.v.eo*rhs.t.e12i-lhs.v.ei*rhs.t.e12o+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12+lhs.t.e123*rhs.t.e3oi+lhs.t.e12o*rhs.v.ei-lhs.t.e12i*rhs.v.eo+lhs.t.e31o*rhs.t.e23i-lhs.t.e31i*rhs.t.e23o+lhs.t.e1oi*rhs.v.e2-lhs.t.e23o*rhs.t.e31i+lhs.t.e23i*rhs.t.e31o-lhs.t.e2oi*rhs.v.e1+lhs.t.e3oi*rhs.t.e123-lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.s+lhs.q.e31oi*rhs.b.e23-lhs.q.e23oi*rhs.b.e31+lhs.p*rhs.v.e3;
    result.p = lhs.s*rhs.p+lhs.v.e1*rhs.q.e23oi+lhs.v.e2*rhs.q.e31oi+lhs.v.e3*rhs.q.e12oi-lhs.v.eo*rhs.q.e123i+lhs.v.ei*rhs.q.e123o+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.t.e1oi+lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o+lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.t.e123+lhs.t.e123*rhs.b.eoi-lhs.t.e12o*rhs.b.e3i+lhs.t.e12i*rhs.b.e3o-lhs.t.e31o*rhs.b.e2i+lhs.t.e31i*rhs.b.e2o+lhs.t.e1oi*rhs.b.e23-lhs.t.e23o*rhs.b.e1i+lhs.t.e23i*rhs.b.e1o+lhs.t.e2oi*rhs.b.e31+lhs.t.e3oi*rhs.b.e12+lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.q.e12oi*rhs.v.e3+lhs.q.e31oi*rhs.v.e2+lhs.q.e23oi*rhs.v.e1+lhs.p*rhs.s;
    return result;
}

Multivector outer(const Multivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s-lhs.p*rhs.p;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.v.e1*rhs.s-lhs.q.e23oi*rhs.p-lhs.p*rhs.q.e23oi;
    result.v.e2 = lhs.s*rhs.v.e2+lhs.v.e2*rhs.s-lhs.q.e31oi*rhs.p-lhs.p*rhs.q.e31oi;
    result.v.e3 = lhs.s*rhs.v.e3+lhs.v.e3*rhs.s-lhs.q.e12oi*rhs.p-lhs.p*rhs.q.e12oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei-0.5*lhs.v.ei*rhs.s+0.5*lhs.q.e123i*rhs.p+0.5*lhs.p*rhs.q.e123i;
    result.v.ei = lhs.s*rhs.v.ei+lhs.v.ei*rhs.s-lhs.q.e123i*rhs.p-lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.v.e2*rhs.v.e3-lhs.v.e3*rhs.v.e2+lhs.b.e23*rhs.s+lhs.t.e1oi*rhs.p+lhs.q.e12oi*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e12oi+lhs.p*rhs.t.e1oi;
    result.b.e31 = lhs.s*rhs.b.e31-lhs.v.e1*rhs.v.e3+lhs.v.e3*rhs.v.e1+lhs.b.e31*rhs.s+lhs.t.e2oi*rhs.p-lhs.q.e12oi*rhs.q.e23oi+lhs.q.e23oi*rhs.q.e12oi+lhs.p*rhs.t.e2oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.v.e1*rhs.v.e2-lhs.v.e2*rhs.v.e1+lhs.b.e12*rhs.s+lhs.t.e3oi*rhs.p+lhs.q.e31oi*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e31oi+lhs.p*rhs.t.e3oi;
    result.b.e1o = lhs.s*rhs.b.e1o+lhs.v.e1*rhs.v.eo-lhs.v.eo*rhs.v.e1+lhs.b.e1o*rhs.s+lhs.t.e23o*rhs.p-lhs.q.e123o*rhs.q.e23oi+lhs.q.e23oi*rhs.q.e123o+lhs.p*rhs.t.e23o;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.v.e2*rhs.v.eo-lhs.v.eo*rhs.v.e2+lhs.b.e2o*rhs.s+lhs.t.e31o*rhs.p-lhs.q.e123o*rhs.q.e31oi+lhs.q.e31oi*rhs.q.e123o+lhs.p*rhs.t.e31o;
    result.b.e3o = lhs.s*rhs.b.e3o+lhs.v.e3*rhs.v.eo-lhs.v.eo*rhs.v.e3+lhs.b.e3o*rhs.s+lhs.t.e12o*rhs.p-lhs.q.e123o*rhs.q.e12oi+lhs.q.e12oi*rhs.q.e123o+lhs.p*rhs.t.e12o;
    result.b.e1i = lhs.s*rhs.b.e1i+lhs.v.e1*rhs.v.ei-lhs.v.ei*rhs.v.e1+lhs.b.e1i*rhs.s-lhs.t.e23i*rhs.p+lhs.q.e123i*rhs.q.e23oi-lhs.q.e23oi*rhs.q.e123i-lhs.p*rhs.t.e23i;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.v.e2*rhs.v.ei-lhs.v.ei*rhs.v.e2+lhs.b.e2i*rhs.s-lhs.t.e31i*rhs.p+lhs.q.e123i*rhs.q.e31oi-lhs.q.e31oi*rhs.q.e123i-lhs.p*rhs.t.e31i;
    result.b.e3i = lhs.s*rhs.b.e3i+lhs.v.e3*rhs.v.ei-lhs.v.ei*rhs.v.e3+lhs.b.e3i*rhs.s-lhs.t.e12i*rhs.p+lhs.q.e123i*rhs.q.e12oi-lhs.q.e12oi*rhs.q.e123i-lhs.p*rhs.t.e12i;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.v.eo*rhs.v.ei-lhs.v.ei*rhs.v.eo+lhs.b.eoi*rhs.s-lhs.t.e123*rhs.p+lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.p*rhs.t.e123;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.v.e1*rhs.b.e23+lhs.v.e2*rhs.b.e31+lhs.v.e3*rhs.b.e12+lhs.b.e12*rhs.v.e3+lhs.b.e31*rhs.v.e2+lhs.b.e23*rhs.v.e1+lhs.b.eoi*rhs.p+lhs.t.e123*rhs.s+lhs.t.e1oi*rhs.q.e23oi+lhs.t.e2oi*rhs.q.e31oi+lhs.t.e3oi*rhs.q.e12oi+lhs.q.e12oi*rhs.t.e3oi+lhs.q.e31oi*rhs.t.e2oi+lhs.q.e23oi*rhs.t.e1oi+lhs.p*rhs.b.eoi;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.v.e2*rhs.b.e3o-lhs.v.e3*rhs.b.e2o+lhs.v.eo*rhs.b.e23-lhs.b.e1o*rhs.p+lhs.b.e23*rhs.v.eo-lhs.b.e2o*rhs.v.e3+lhs.b.e3o*rhs.v.e2+lhs.t.e12o*rhs.q.e31oi-lhs.t.e31o*rhs.q.e12oi-lhs.t.e1oi*rhs.q.e123o+lhs.t.e23o*rhs.s-lhs.q.e123o*rhs.t.e1oi-lhs.q.e12oi*rhs.t.e31o+lhs.q.e31oi*rhs.t.e12o-lhs.p*rhs.b.e1o;
    result.t.e31o = lhs.s*rhs.t.e31o-lhs.v.e1*rhs.b.e3o+lhs.v.e3*rhs.b.e1o+lhs.v.eo*rhs.b.e31+lhs.b.e31*rhs.v.eo+lhs.b.e1o*rhs.v.e3-lhs.b.e2o*rhs.p-lhs.b.e3o*rhs.v.e1-lhs.t.e12o*rhs.q.e23oi+lhs.t.e31o*rhs.s+lhs.t.e23o*rhs.q.e12oi-lhs.t.e2oi*rhs.q.e123o-lhs.q.e123o*rhs.t.e2oi+lhs.q.e12oi*rhs.t.e23o-lhs.q.e23oi*rhs.t.e12o-lhs.p*rhs.b.e2o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.v.e1*rhs.b.e2o-lhs.v.e2*rhs.b.e1o+lhs.v.eo*rhs.b.e12+lhs.b.e12*rhs.v.eo-lhs.b.e1o*rhs.v.e2+lhs.b.e2o*rhs.v.e1-lhs.b.e3o*rhs.p+lhs.t.e12o*rhs.s+lhs.t.e31o*rhs.q.e23oi-lhs.t.e23o*rhs.q.e31oi-lhs.t.e3oi*rhs.q.e123o-lhs.q.e123o*rhs.t.e3oi-lhs.q.e31oi*rhs.t.e23o+lhs.q.e23oi*rhs.t.e31o-lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.v.e2*rhs.b.e3i-lhs.v.e3*rhs.b.e2i+lhs.v.ei*rhs.b.e23+lhs.b.e1i*rhs.p+lhs.b.e23*rhs.v.ei-lhs.b.e2i*rhs.v.e3+lhs.b.e3i*rhs.v.e2-lhs.t.e12i*rhs.q.e31oi+lhs.t.e31i*rhs.q.e12oi+lhs.t.e1oi*rhs.q.e123i+lhs.t.e23i*rhs.s+lhs.q.e123i*rhs.t.e1oi+lhs.q.e12oi*rhs.t.e31i-lhs.q.e31oi*rhs.t.e12i+lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.s*rhs.t.e31i-lhs.v.e1*rhs.b.e3i+lhs.v.e3*rhs.b.e1i+lhs.v.ei*rhs.b.e31+lhs.b.e31*rhs.v.ei+lhs.b.e1i*rhs.v.e3+lhs.b.e2i*rhs.p-lhs.b.e3i*rhs.v.e1+lhs.t.e12i*rhs.q.e23oi+lhs.t.e31i*rhs.s-lhs.t.e23i*rhs.q.e12oi+lhs.t.e2oi*rhs.q.e123i+lhs.q.e123i*rhs.t.e2oi-lhs.q.e12oi*rhs.t.e23i+lhs.q.e23oi*rhs.t.e12i+lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.v.e1*rhs.b.e2i-lhs.v.e2*rhs.b.e1i+lhs.v.ei*rhs.b.e12+lhs.b.e12*rhs.v.ei-lhs.b.e1i*rhs.v.e2+lhs.b.e2i*rhs.v.e1+lhs.b.e3i*rhs.p+lhs.t.e12i*rhs.s-lhs.t.e31i*rhs.q.e23oi+lhs.t.e23i*rhs.q.e31oi+lhs.t.e3oi*rhs.q.e123i+lhs.q.e123i*rhs.t.e3oi+lhs.q.e31oi*rhs.t.e23i-lhs.q.e23oi*rhs.t.e31i+lhs.p*rhs.b.e3i;
    result.t.e1oi = lhs.s*rhs.t.e1oi+lhs.v.e1*rhs.b.eoi-lhs.v.eo*rhs.b.e1i+lhs.v.ei*rhs.b.e1o+lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.p+lhs.b.eoi*rhs.v.e1-lhs.t.e123*rhs.q.e23oi+lhs.t.e1oi*rhs.s+lhs.t.e23o*rhs.q.e123i-lhs.t.e23i*rhs.q.e123o-lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o-lhs.q.e23oi*rhs.t.e123-lhs.p*rhs.b.e23;
    result.t.e2oi = lhs.s*rhs.t.e2oi+lhs.v.e2*rhs.b.eoi-lhs.v.eo*rhs.b.e2i+lhs.v.ei*rhs.b.e2o-lhs.b.e31*rhs.p+lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.eoi*rhs.v.e2-lhs.t.e123*rhs.q.e31oi+lhs.t.e31o*rhs.q.e123i-lhs.t.e31i*rhs.q.e123o+lhs.t.e2oi*rhs.s-lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e31oi*rhs.t.e123-lhs.p*rhs.b.e31;
    result.t.e3oi = lhs.s*rhs.t.e3oi+lhs.v.e3*rhs.b.eoi-lhs.v.eo*rhs.b.e3i+lhs.v.ei*rhs.b.e3o-lhs.b.e12*rhs.p+lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.v.e3-lhs.t.e123*rhs.q.e12oi+lhs.t.e12o*rhs.q.e123i-lhs.t.e12i*rhs.q.e123o+lhs.t.e3oi*rhs.s-lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.t.e123-lhs.p*rhs.b.e12;
    result.q.e123o = lhs.s*rhs.q.e123o+lhs.v.e1*rhs.t.e23o+lhs.v.e2*rhs.t.e31o+lhs.v.e3*rhs.t.e12o-lhs.v.eo*rhs.t.e123-lhs.v.eo*rhs.p+lhs.b.e12*rhs.b.e3o+lhs.b.e31*rhs.b.e2o+lhs.b.e1o*rhs.b.e23+lhs.b.e1o*rhs.q.e23oi+lhs.b.e23*rhs.b.e1o+lhs.b.e2o*rhs.b.e31+lhs.b.e2o*rhs.q.e31oi+lhs.b.e3o*rhs.b.e12+lhs.b.e3o*rhs.q.e12oi-lhs.b.eoi*rhs.q.e123o+lhs.t.e123*rhs.v.eo-lhs.t.e12o*rhs.v.e3-lhs.t.e12o*rhs.t.e3oi-lhs.t.e31o*rhs.v.e2-lhs.t.e31o*rhs.t.e2oi-lhs.t.e1oi*rhs.t.e23o-lhs.t.e23o*rhs.v.e1-lhs.t.e23o*rhs.t.e1oi-lhs.t.e2oi*rhs.t.e31o-lhs.t.e3oi*rhs.t.e12o+lhs.q.e123o*rhs.s+lhs.q.e123o*rhs.b.eoi-lhs.q.e12oi*rhs.b.e3o-lhs.q.e31oi*rhs.b.e2o-lhs.q.e23oi*rhs.b.e1o-lhs.p*rhs.v.eo;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.v.e1*rhs.t.e23i+lhs.v.e2*rhs.t.e31i+lhs.v.e3*rhs.t.e12i-lhs.v.ei*rhs.t.e123+lhs.v.ei*rhs.p+lhs.b.e12*rhs.b.e3i+lhs.b.e31*rhs.b.e2i+lhs.b.e1i*rhs.b.e23-lhs.b.e1i*rhs.q.e23oi+lhs.b.e23*rhs.b.e1i+lhs.b.e2i*rhs.b.e31-lhs.b.e2i*rhs.q.e31oi+lhs.b.e3i*rhs.b.e12-lhs.b.e3i*rhs.q.e12oi+lhs.b.eoi*rhs.q.e123i+lhs.t.e123*rhs.v.ei-lhs.t.e12i*rhs.v.e3+lhs.t.e12i*rhs.t.e3oi-lhs.t.e31i*rhs.v.e2+lhs.t.e31i*rhs.t.e2oi+lhs.t.e1oi*rhs.t.e23i-lhs.t.e23i*rhs.v.e1+lhs.t.e23i*rhs.t.e1oi+lhs.t.e2oi*rhs.t.e31i+lhs.t.e3oi*rhs.t.e12i+lhs.q.e123i*rhs.s-lhs.q.e123i*rhs.b.eoi+lhs.q.e12oi*rhs.b.e3i+lhs.q.e31oi*rhs.b.e2i+lhs.q.e23oi*rhs.b.e1i+lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.v.e1*rhs.p+lhs.v.e2*rhs.t.e3oi-lhs.v.e3*rhs.t.e2oi+lhs.v.eo*rhs.t.e23i-lhs.v.ei*rhs.t.e23o+lhs.b.e12*rhs.q.e31oi-lhs.b.e31*rhs.q.e12oi-lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.b.eoi-lhs.b.e2o*rhs.b.e3i+lhs.b.e2i*rhs.b.e3o+lhs.b.e3o*rhs.b.e2i-lhs.b.e3i*rhs.b.e2o+lhs.b.eoi*rhs.b.e23+lhs.t.e123*rhs.t.e1oi+lhs.t.e12o*rhs.t.e31i-lhs.t.e12i*rhs.t.e31o-lhs.t.e31o*rhs.t.e12i+lhs.t.e31i*rhs.t.e12o+lhs.t.e1oi*rhs.t.e123+lhs.t.e23o*rhs.v.ei-lhs.t.e23i*rhs.v.eo+lhs.t.e2oi*rhs.v.e3-lhs.t.e3oi*rhs.v.e2-lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e12oi*rhs.b.e31-lhs.q.e31oi*rhs.b.e12+lhs.q.e23oi*rhs.s+lhs.p*rhs.v.e1;
    result.q.e31oi = lhs.s*rhs.q.e31oi-lhs.v.e1*rhs.t.e3oi+lhs.v.e2*rhs.p+lhs.v.e3*rhs.t.e1oi+lhs.v.eo*rhs.t.e31i-lhs.v.ei*rhs.t.e31o-lhs.b.e12*rhs.q.e23oi+lhs.b.e31*rhs.b.eoi+lhs.b.e1o*rhs.b.e3i-lhs.b.e1i*rhs.b.e3o+lhs.b.e23*rhs.q.e12oi-lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o-lhs.b.e3o*rhs.b.e1i+lhs.b.e3i*rhs.b.e1o+lhs.b.eoi*rhs.b.e31+lhs.t.e123*rhs.t.e2oi-lhs.t.e12o*rhs.t.e23i+lhs.t.e12i*rhs.t.e23o+lhs.t.e31o*rhs.v.ei-lhs.t.e31i*rhs.v.eo-lhs.t.e1oi*rhs.v.e3+lhs.t.e23o*rhs.t.e12i-lhs.t.e23i*rhs.t.e12o+lhs.t.e2oi*rhs.t.e123+lhs.t.e3oi*rhs.v.e1-lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o-lhs.q.e12oi*rhs.b.e23+lhs.q.e31oi*rhs.s+lhs.q.e23oi*rhs.b.e12+lhs.p*rhs.v.e2;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.v.e1*rhs.t.e2oi-lhs.v.e2*rhs.t.e1oi+lhs.v.e3*rhs.p+lhs.v.eo*rhs.t.e12i-lhs.v.ei*rhs.t.e12o+lhs.b.e12*rhs.b.eoi+lhs.b.e31*rhs.q.e23oi-lhs.b.e1o*rhs.b.e2i+lhs.b.e1i*rhs.b.e2o-lhs.b.e23*rhs.q.e31oi+lhs.b.e2o*rhs.b.e1i-lhs.b.e2i*rhs.b.e1o-lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.b.e12+lhs.t.e123*rhs.t.e3oi+lhs.t.e12o*rhs.v.ei-lhs.t.e12i*rhs.v.eo+lhs.t.e31o*rhs.t.e23i-lhs.t.e31i*rhs.t.e23o+lhs.t.e1oi*rhs.v.e2-lhs.t.e23o*rhs.t.e31i+lhs.t.e23i*rhs.t.e31o-lhs.t.e2oi*rhs.v.e1+lhs.t.e3oi*rhs.t.e123-lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.s+lhs.q.e31oi*rhs.b.e23-lhs.q.e23oi*rhs.b.e31+lhs.p*rhs.v.e3;
    result.p = lhs.s*rhs.p+lhs.v.e1*rhs.q.e23oi+lhs.v.e2*rhs.q.e31oi+lhs.v.e3*rhs.q.e12oi-lhs.v.eo*rhs.q.e123i+lhs.v.ei*rhs.q.e123o+lhs.b.e12*rhs.t.e3oi+lhs.b.e31*rhs.t.e2oi+lhs.b.e1o*rhs.t.e23i-lhs.b.e1i*rhs.t.e23o+lhs.b.e23*rhs.t.e1oi+lhs.b.e2o*rhs.t.e31i-lhs.b.e2i*rhs.t.e31o+lhs.b.e3o*rhs.t.e12i-lhs.b.e3i*rhs.t.e12o+lhs.b.eoi*rhs.t.e123+lhs.t.e123*rhs.b.eoi-lhs.t.e12o*rhs.b.e3i+lhs.t.e12i*rhs.b.e3o-lhs.t.e31o*rhs.b.e2i+lhs.t.e31i*rhs.b.e2o+lhs.t.e1oi*rhs.b.e23-lhs.t.e23o*rhs.b.e1i+lhs.t.e23i*rhs.b.e1o+lhs.t.e2oi*rhs.b.e31+lhs.t.e3oi*rhs.b.e12+lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.q.e12oi*rhs.v.e3+lhs.q.e31oi*rhs.v.e2+lhs.q.e23oi*rhs.v.e1+lhs.p*rhs.s;
    return result;
}

Multivector inner(const Multivector &lhs, const Multivector &rhs)
{
    Multivector result;
    result.s = lhs.s*rhs.s+lhs.v.e1*rhs.v.e1+lhs.v.e2*rhs.v.e2+lhs.v.e3*rhs.v.e3-lhs.v.eo*rhs.v.ei-lhs.v.ei*rhs.v.eo-lhs.b.e12*rhs.b.e12-lhs.b.e31*rhs.b.e31+lhs.b.e1o*rhs.b.e1i+lhs.b.e1i*rhs.b.e1o-lhs.b.e23*rhs.b.e23+lhs.b.e2o*rhs.b.e2i+lhs.b.e2i*rhs.b.e2o+lhs.b.e3o*rhs.b.e3i+lhs.b.e3i*rhs.b.e3o+lhs.b.eoi*rhs.b.eoi-lhs.t.e123*rhs.t.e123+lhs.t.e12o*rhs.t.e12i+lhs.t.e12i*rhs.t.e12o+lhs.t.e31o*rhs.t.e31i+lhs.t.e31i*rhs.t.e31o+lhs.t.e1oi*rhs.t.e1oi+lhs.t.e23o*rhs.t.e23i+lhs.t.e23i*rhs.t.e23o+lhs.t.e2oi*rhs.t.e2oi+lhs.t.e3oi*rhs.t.e3oi-lhs.q.e123o*rhs.q.e123i-lhs.q.e123i*rhs.q.e123o-lhs.q.e12oi*rhs.q.e12oi-lhs.q.e31oi*rhs.q.e31oi-lhs.q.e23oi*rhs.q.e23oi-lhs.p*rhs.p;
    result.v.e1 = lhs.s*rhs.v.e1+lhs.v.e1*rhs.s-lhs.v.e2*rhs.b.e12+lhs.v.e3*rhs.b.e31+lhs.v.eo*rhs.b.e1i+lhs.v.ei*rhs.b.e1o+lhs.b.e12*rhs.v.e2-lhs.b.e31*rhs.v.e3-lhs.b.e1o*rhs.v.ei-lhs.b.e1i*rhs.v.eo-lhs.b.e23*rhs.t.e123+lhs.b.e2o*rhs.t.e12i+lhs.b.e2i*rhs.t.e12o-lhs.b.e3o*rhs.t.e31i-lhs.b.e3i*rhs.t.e31o+lhs.b.eoi*rhs.t.e1oi-lhs.t.e123*rhs.b.e23+lhs.t.e12o*rhs.b.e2i+lhs.t.e12i*rhs.b.e2o-lhs.t.e31o*rhs.b.e3i-lhs.t.e31i*rhs.b.e3o+lhs.t.e1oi*rhs.b.eoi-lhs.t.e23o*rhs.q.e123i-lhs.t.e23i*rhs.q.e123o-lhs.t.e2oi*rhs.q.e12oi+lhs.t.e3oi*rhs.q.e31oi+lhs.q.e123o*rhs.t.e23i+lhs.q.e123i*rhs.t.e23o+lhs.q.e12oi*rhs.t.e2oi-lhs.q.e31oi*rhs.t.e3oi-lhs.q.e23oi*rhs.p-lhs.p*rhs.q.e23oi;
    result.v.e2 = lhs.s*rhs.v.e2+lhs.v.e1*rhs.b.e12+lhs.v.e2*rhs.s-lhs.v.e3*rhs.b.e23+lhs.v.eo*rhs.b.e2i+lhs.v.ei*rhs.b.e2o-lhs.b.e12*rhs.v.e1-lhs.b.e31*rhs.t.e123-lhs.b.e1o*rhs.t.e12i-lhs.b.e1i*rhs.t.e12o+lhs.b.e23*rhs.v.e3-lhs.b.e2o*rhs.v.ei-lhs.b.e2i*rhs.v.eo+lhs.b.e3o*rhs.t.e23i+lhs.b.e3i*rhs.t.e23o+lhs.b.eoi*rhs.t.e2oi-lhs.t.e123*rhs.b.e31-lhs.t.e12o*rhs.b.e1i-lhs.t.e12i*rhs.b.e1o-lhs.t.e31o*rhs.q.e123i-lhs.t.e31i*rhs.q.e123o+lhs.t.e1oi*rhs.q.e12oi+lhs.t.e23o*rhs.b.e3i+lhs.t.e23i*rhs.b.e3o+lhs.t.e2oi*rhs.b.eoi-lhs.t.e3oi*rhs.q.e23oi+lhs.q.e123o*rhs.t.e31i+lhs.q.e123i*rhs.t.e31o-lhs.q.e12oi*rhs.t.e1oi-lhs.q.e31oi*rhs.p+lhs.q.e23oi*rhs.t.e3oi-lhs.p*rhs.q.e31oi;
    result.v.e3 = lhs.s*rhs.v.e3-lhs.v.e1*rhs.b.e31+lhs.v.e2*rhs.b.e23+lhs.v.e3*rhs.s+lhs.v.eo*rhs.b.e3i+lhs.v.ei*rhs.b.e3o-lhs.b.e12*rhs.t.e123+lhs.b.e31*rhs.v.e1+lhs.b.e1o*rhs.t.e31i+lhs.b.e1i*rhs.t.e31o-lhs.b.e23*rhs.v.e2-lhs.b.e2o*rhs.t.e23i-lhs.b.e2i*rhs.t.e23o-lhs.b.e3o*rhs.v.ei-lhs.b.e3i*rhs.v.eo+lhs.b.eoi*rhs.t.e3oi-lhs.t.e123*rhs.b.e12-lhs.t.e12o*rhs.q.e123i-lhs.t.e12i*rhs.q.e123o+lhs.t.e31o*rhs.b.e1i+lhs.t.e31i*rhs.b.e1o-lhs.t.e1oi*rhs.q.e31oi-lhs.t.e23o*rhs.b.e2i-lhs.t.e23i*rhs.b.e2o+lhs.t.e2oi*rhs.q.e23oi+lhs.t.e3oi*rhs.b.eoi+lhs.q.e123o*rhs.t.e12i+lhs.q.e123i*rhs.t.e12o-lhs.q.e12oi*rhs.p+lhs.q.e31oi*rhs.t.e1oi-lhs.q.e23oi*rhs.t.e2oi-lhs.p*rhs.q.e12oi;
    result.v.eo = -0.5*lhs.s*rhs.v.ei-0.5*lhs.v.e1*rhs.b.e1i-0.5*lhs.v.e2*rhs.b.e2i-0.5*lhs.v.e3*rhs.b.e3i-0.5*lhs.v.ei*rhs.s+0.5*lhs.v.ei*rhs.b.eoi+0.5*lhs.b.e12*rhs.t.e12i+0.5*lhs.b.e31*rhs.t.e31i+0.5*lhs.b.e1i*rhs.v.e1-0.5*lhs.b.e1i*rhs.t.e1oi+0.5*lhs.b.e23*rhs.t.e23i+0.5*lhs.b.e2i*rhs.v.e2-0.5*lhs.b.e2i*rhs.t.e2oi+0.5*lhs.b.e3i*rhs.v.e3-0.5*lhs.b.e3i*rhs.t.e3oi-0.5*lhs.b.eoi*rhs.v.ei+0.5*lhs.t.e123*rhs.q.e123i+0.5*lhs.t.e12i*rhs.b.e12-0.5*lhs.t.e12i*rhs.q.e12oi+0.5*lhs.t.e31i*rhs.b.e31-0.5*lhs.t.e31i*rhs.q.e31oi-0.5*lhs.t.e1oi*rhs.b.e1i+0.5*lhs.t.e23i*rhs.b.e23-0.5*lhs.t.e23i*rhs.q.e23oi-0.5*lhs.t.e2oi*rhs.b.e2i-0.5*lhs.t.e3oi*rhs.b.e3i-0.5*lhs.q.e123i*rhs.t.e123+0.5*lhs.q.e123i*rhs.p+0.5*lhs.q.e12oi*rhs.t.e12i+0.5*lhs.q.e31oi*rhs.t.e31i+0.5*lhs.q.e23oi*rhs.t.e23i+0.5*lhs.p*rhs.q.e123i;
    result.v.ei = lhs.s*rhs.v.ei+lhs.v.e1*rhs.b.e1i+lhs.v.e2*rhs.b.e2i+lhs.v.e3*rhs.b.e3i+lhs.v.ei*rhs.s-lhs.v.ei*rhs.b.eoi-lhs.b.e12*rhs.t.e12i-lhs.b.e31*rhs.t.e31i-lhs.b.e1i*rhs.v.e1+lhs.b.e1i*rhs.t.e1oi-lhs.b.e23*rhs.t.e23i-lhs.b.e2i*rhs.v.e2+lhs.b.e2i*rhs.t.e2oi-lhs.b.e3i*rhs.v.e3+lhs.b.e3i*rhs.t.e3oi+lhs.b.eoi*rhs.v.ei-lhs.t.e123*rhs.q.e123i-lhs.t.e12i*rhs.b.e12+lhs.t.e12i*rhs.q.e12oi-lhs.t.e31i*rhs.b.e31+lhs.t.e31i*rhs.q.e31oi+lhs.t.e1oi*rhs.b.e1i-lhs.t.e23i*rhs.b.e23+lhs.t.e23i*rhs.q.e23oi+lhs.t.e2oi*rhs.b.e2i+lhs.t.e3oi*rhs.b.e3i+lhs.q.e123i*rhs.t.e123-lhs.q.e123i*rhs.p-lhs.q.e12oi*rhs.t.e12i-lhs.q.e31oi*rhs.t.e31i-lhs.q.e23oi*rhs.t.e23i-lhs.p*rhs.q.e123i;
    result.b.e23 = lhs.s*rhs.b.e23+lhs.v.e1*rhs.t.e123-lhs.v.eo*rhs.t.e23i-lhs.v.ei*rhs.t.e23o+lhs.b.e1o*rhs.q.e123i+lhs.b.e1i*rhs.q.e123o+lhs.b.e23*rhs.s+lhs.b.eoi*rhs.q.e23oi+lhs.t.e123*rhs.v.e1+lhs.t.e1oi*rhs.p-lhs.t.e23o*rhs.v.ei-lhs.t.e23i*rhs.v.eo+lhs.q.e123o*rhs.b.e1i+lhs.q.e123i*rhs.b.e1o+lhs.q.e23oi*rhs.b.eoi+lhs.p*rhs.t.e1oi;
    result.b.e31 = lhs.s*rhs.b.e31+lhs.v.e2*rhs.t.e123-lhs.v.eo*rhs.t.e31i-lhs.v.ei*rhs.t.e31o+lhs.b.e31*rhs.s+lhs.b.e2o*rhs.q.e123i+lhs.b.e2i*rhs.q.e123o+lhs.b.eoi*rhs.q.e31oi+lhs.t.e123*rhs.v.e2-lhs.t.e31o*rhs.v.ei-lhs.t.e31i*rhs.v.eo+lhs.t.e2oi*rhs.p+lhs.q.e123o*rhs.b.e2i+lhs.q.e123i*rhs.b.e2o+lhs.q.e31oi*rhs.b.eoi+lhs.p*rhs.t.e2oi;
    result.b.e12 = lhs.s*rhs.b.e12+lhs.v.e3*rhs.t.e123-lhs.v.eo*rhs.t.e12i-lhs.v.ei*rhs.t.e12o+lhs.b.e12*rhs.s+lhs.b.e3o*rhs.q.e123i+lhs.b.e3i*rhs.q.e123o+lhs.b.eoi*rhs.q.e12oi+lhs.t.e123*rhs.v.e3-lhs.t.e12o*rhs.v.ei-lhs.t.e12i*rhs.v.eo+lhs.t.e3oi*rhs.p+lhs.q.e123o*rhs.b.e3i+lhs.q.e123i*rhs.b.e3o+lhs.q.e12oi*rhs.b.eoi+lhs.p*rhs.t.e3oi;
    result.b.e1o = lhs.s*rhs.b.e1o-lhs.v.e2*rhs.t.e12o+lhs.v.e3*rhs.t.e31o-lhs.v.eo*rhs.t.e1oi+lhs.b.e1o*rhs.s-lhs.b.e23*rhs.q.e123o-lhs.b.e2o*rhs.q.e12oi+lhs.b.e3o*rhs.q.e31oi-lhs.t.e12o*rhs.v.e2+lhs.t.e31o*rhs.v.e3-lhs.t.e1oi*rhs.v.eo+lhs.t.e23o*rhs.p-lhs.q.e123o*rhs.b.e23-lhs.q.e12oi*rhs.b.e2o+lhs.q.e31oi*rhs.b.e3o+lhs.p*rhs.t.e23o;
    result.b.e2o = lhs.s*rhs.b.e2o+lhs.v.e1*rhs.t.e12o-lhs.v.e3*rhs.t.e23o-lhs.v.eo*rhs.t.e2oi-lhs.b.e31*rhs.q.e123o+lhs.b.e1o*rhs.q.e12oi+lhs.b.e2o*rhs.s-lhs.b.e3o*rhs.q.e23oi+lhs.t.e12o*rhs.v.e1+lhs.t.e31o*rhs.p-lhs.t.e23o*rhs.v.e3-lhs.t.e2oi*rhs.v.eo-lhs.q.e123o*rhs.b.e31+lhs.q.e12oi*rhs.b.e1o-lhs.q.e23oi*rhs.b.e3o+lhs.p*rhs.t.e31o;
    result.b.e3o = lhs.s*rhs.b.e3o-lhs.v.e1*rhs.t.e31o+lhs.v.e2*rhs.t.e23o-lhs.v.eo*rhs.t.e3oi-lhs.b.e12*rhs.q.e123o-lhs.b.e1o*rhs.q.e31oi+lhs.b.e2o*rhs.q.e23oi+lhs.b.e3o*rhs.s+lhs.t.e12o*rhs.p-lhs.t.e31o*rhs.v.e1+lhs.t.e23o*rhs.v.e2-lhs.t.e3oi*rhs.v.eo-lhs.q.e123o*rhs.b.e12-lhs.q.e31oi*rhs.b.e1o+lhs.q.e23oi*rhs.b.e2o+lhs.p*rhs.t.e12o;
    result.b.e1i = lhs.s*rhs.b.e1i-lhs.v.e2*rhs.t.e12i+lhs.v.e3*rhs.t.e31i+lhs.v.ei*rhs.t.e1oi+lhs.b.e1i*rhs.s-lhs.b.e23*rhs.q.e123i+lhs.b.e2i*rhs.q.e12oi-lhs.b.e3i*rhs.q.e31oi-lhs.t.e12i*rhs.v.e2+lhs.t.e31i*rhs.v.e3+lhs.t.e1oi*rhs.v.ei-lhs.t.e23i*rhs.p-lhs.q.e123i*rhs.b.e23+lhs.q.e12oi*rhs.b.e2i-lhs.q.e31oi*rhs.b.e3i-lhs.p*rhs.t.e23i;
    result.b.e2i = lhs.s*rhs.b.e2i+lhs.v.e1*rhs.t.e12i-lhs.v.e3*rhs.t.e23i+lhs.v.ei*rhs.t.e2oi-lhs.b.e31*rhs.q.e123i-lhs.b.e1i*rhs.q.e12oi+lhs.b.e2i*rhs.s+lhs.b.e3i*rhs.q.e23oi+lhs.t.e12i*rhs.v.e1-lhs.t.e31i*rhs.p-lhs.t.e23i*rhs.v.e3+lhs.t.e2oi*rhs.v.ei-lhs.q.e123i*rhs.b.e31-lhs.q.e12oi*rhs.b.e1i+lhs.q.e23oi*rhs.b.e3i-lhs.p*rhs.t.e31i;
    result.b.e3i = lhs.s*rhs.b.e3i-lhs.v.e1*rhs.t.e31i+lhs.v.e2*rhs.t.e23i+lhs.v.ei*rhs.t.e3oi-lhs.b.e12*rhs.q.e123i+lhs.b.e1i*rhs.q.e31oi-lhs.b.e2i*rhs.q.e23oi+lhs.b.e3i*rhs.s-lhs.t.e12i*rhs.p-lhs.t.e31i*rhs.v.e1+lhs.t.e23i*rhs.v.e2+lhs.t.e3oi*rhs.v.ei-lhs.q.e123i*rhs.b.e12+lhs.q.e31oi*rhs.b.e1i-lhs.q.e23oi*rhs.b.e2i-lhs.p*rhs.t.e12i;
    result.b.eoi = lhs.s*rhs.b.eoi+lhs.v.e1*rhs.t.e1oi+lhs.v.e2*rhs.t.e2oi+lhs.v.e3*rhs.t.e3oi-lhs.b.e12*rhs.q.e12oi-lhs.b.e31*rhs.q.e31oi-lhs.b.e23*rhs.q.e23oi+lhs.b.eoi*rhs.s-lhs.t.e123*rhs.p+lhs.t.e1oi*rhs.v.e1+lhs.t.e2oi*rhs.v.e2+lhs.t.e3oi*rhs.v.e3-lhs.q.e12oi*rhs.b.e12-lhs.q.e31oi*rhs.b.e31-lhs.q.e23oi*rhs.b.e23-lhs.p*rhs.t.e123;
    result.t.e123 = lhs.s*rhs.t.e123+lhs.v.eo*rhs.q.e123i+lhs.v.ei*rhs.q.e123o+lhs.b.eoi*rhs.p+lhs.t.e123*rhs.s-lhs.q.e123o*rhs.v.ei-lhs.q.e123i*rhs.v.eo+lhs.p*rhs.b.eoi;
    result.t.e23o = lhs.s*rhs.t.e23o+lhs.v.e1*rhs.q.e123o+lhs.v.eo*rhs.q.e23oi-lhs.b.e1o*rhs.p+lhs.t.e23o*rhs.s-lhs.q.e123o*rhs.v.e1-lhs.q.e23oi*rhs.v.eo-lhs.p*rhs.b.e1o;
    result.t.e31o = lhs.s*rhs.t.e31o+lhs.v.e2*rhs.q.e123o+lhs.v.eo*rhs.q.e31oi-lhs.b.e2o*rhs.p+lhs.t.e31o*rhs.s-lhs.q.e123o*rhs.v.e2-lhs.q.e31oi*rhs.v.eo-lhs.p*rhs.b.e2o;
    result.t.e12o = lhs.s*rhs.t.e12o+lhs.v.e3*rhs.q.e123o+lhs.v.eo*rhs.q.e12oi-lhs.b.e3o*rhs.p+lhs.t.e12o*rhs.s-lhs.q.e123o*rhs.v.e3-lhs.q.e12oi*rhs.v.eo-lhs.p*rhs.b.e3o;
    result.t.e23i = lhs.s*rhs.t.e23i+lhs.v.e1*rhs.q.e123i-lhs.v.ei*rhs.q.e23oi+lhs.b.e1i*rhs.p+lhs.t.e23i*rhs.s-lhs.q.e123i*rhs.v.e1+lhs.q.e23oi*rhs.v.ei+lhs.p*rhs.b.e1i;
    result.t.e31i = lhs.s*rhs.t.e31i+lhs.v.e2*rhs.q.e123i-lhs.v.ei*rhs.q.e31oi+lhs.b.e2i*rhs.p+lhs.t.e31i*rhs.s-lhs.q.e123i*rhs.v.e2+lhs.q.e31oi*rhs.v.ei+lhs.p*rhs.b.e2i;
    result.t.e12i = lhs.s*rhs.t.e12i+lhs.v.e3*rhs.q.e123i-lhs.v.ei*rhs.q.e12oi+lhs.b.e3i*rhs.p+lhs.t.e12i*rhs.s-lhs.q.e123i*rhs.v.e3+lhs.q.e12oi*rhs.v.ei+lhs.p*rhs.b.e3i;
    result.t.e1oi = lhs.s*rhs.t.e1oi-lhs.v.e2*rhs.q.e12oi+lhs.v.e3*rhs.q.e31oi-lhs.b.e23*rhs.p+lhs.t.e1oi*rhs.s+lhs.q.e12oi*rhs.v.e2-lhs.q.e31oi*rhs.v.e3-lhs.p*rhs.b.e23;
    result.t.e2oi = lhs.s*rhs.t.e2oi+lhs.v.e1*rhs.q.e12oi-lhs.v.e3*rhs.q.e23oi-lhs.b.e31*rhs.p+lhs.t.e2oi*rhs.s-lhs.q.e12oi*rhs.v.e1+lhs.q.e23oi*rhs.v.e3-lhs.p*rhs.b.e31;
    result.t.e3oi = lhs.s*rhs.t.e3oi-lhs.v.e1*rhs.q.e31oi+lhs.v.e2*rhs.q.e23oi-lhs.b.e12*rhs.p+lhs.t.e3oi*rhs.s+lhs.q.e31oi*rhs.v.e1-lhs.q.e23oi*rhs.v.e2-lhs.p*rhs.b.e12;
    result.q.e123o = lhs.s*rhs.q.e123o-lhs.v.eo*rhs.p+lhs.q.e123o*rhs.s-lhs.p*rhs.v.eo;
    result.q.e123i = lhs.s*rhs.q.e123i+lhs.v.ei*rhs.p+lhs.q.e123i*rhs.s+lhs.p*rhs.v.ei;
    result.q.e23oi = lhs.s*rhs.q.e23oi+lhs.v.e1*rhs.p+lhs.q.e23oi*rhs.s+lhs.p*rhs.v.e1;
    result.q.e31oi = lhs.s*rhs.q.e31oi+lhs.v.e2*rhs.p+lhs.q.e31oi*rhs.s+lhs.p*rhs.v.e2;
    result.q.e12oi = lhs.s*rhs.q.e12oi+lhs.v.e3*rhs.p+lhs.q.e12oi*rhs.s+lhs.p*rhs.v.e3;
    result.p = lhs.s*rhs.p+lhs.p*rhs.s;
    return result;
}

std::ostream& operator<<(std::ostream& outs, const Pseudoscalar &x) {
    outs << "p="<<x.p<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Pseudoscalar3 &x) {
    outs << "p="<<x.p<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Vector3 &x) {
    outs << "e1="<<x.e1<<" "<<"e2="<<x.e2<<" "<<"e3="<<x.e3<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Bivector3 &x) {
    outs << "e23="<<x.e23<<" "<<"e31="<<x.e31<<" "<<"e12="<<x.e12<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Rotor3 &x) {
    outs << "s="<<x.s<<" "<<"b.e23="<<x.b.e23<<" "<<"b.e31="<<x.b.e31<<" "<<"b.e12="<<x.b.e12<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Vector &x) {
    outs << "e1="<<x.e1<<" "<<"e2="<<x.e2<<" "<<"e3="<<x.e3<<" "<<std::endl<<"eo="<<x.eo<<" "<<"ei="<<x.ei<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Quadvector &x) {
    outs << "e123o="<<x.e123o<<" "<<"e123i="<<x.e123i<<" "<<std::endl<<"e23oi="<<x.e23oi<<" "<<"e31oi="<<x.e31oi<<" "<<"e12oi="<<x.e12oi<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Bivector &x) {
    outs << "e23="<<x.e23<<" "<<"e31="<<x.e31<<" "<<"e12="<<x.e12<<" "<<std::endl<<"e1o="<<x.e1o<<" "<<"e2o="<<x.e2o<<" "<<"e3o="<<x.e3o<<" "<<std::endl<<"e1i="<<x.e1i<<" "<<"e2i="<<x.e2i<<" "<<"e3i="<<x.e3i<<" "<<std::endl<<"eoi="<<x.eoi<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Trivector &x) {
    outs << "e123="<<x.e123<<" "<<std::endl<<"e23o="<<x.e23o<<" "<<"e31o="<<x.e31o<<" "<<"e12o="<<x.e12o<<" "<<std::endl<<"e23i="<<x.e23i<<" "<<"e31i="<<x.e31i<<" "<<"e12i="<<x.e12i<<" "<<std::endl<<"e1oi="<<x.e1oi<<" "<<"e2oi="<<x.e2oi<<" "<<"e3oi="<<x.e3oi<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Rotor &x) {
    outs << "s="<<x.s<<" "<<std::endl<<"b.e23="<<x.b.e23<<" "<<"b.e31="<<x.b.e31<<" "<<"b.e12="<<x.b.e12<<" "<<std::endl<<"b.e1o="<<x.b.e1o<<" "<<"b.e2o="<<x.b.e2o<<" "<<"b.e3o="<<x.b.e3o<<" "<<std::endl<<"b.e1i="<<x.b.e1i<<" "<<"b.e2i="<<x.b.e2i<<" "<<"b.e3i="<<x.b.e3i<<" "<<std::endl<<"b.eoi="<<x.b.eoi<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Versor &x) {
    outs << "s="<<x.s<<" "<<std::endl<<"b.e23="<<x.b.e23<<" "<<"b.e31="<<x.b.e31<<" "<<"b.e12="<<x.b.e12<<" "<<std::endl<<"b.e1o="<<x.b.e1o<<" "<<"b.e2o="<<x.b.e2o<<" "<<"b.e3o="<<x.b.e3o<<" "<<std::endl<<"b.e1i="<<x.b.e1i<<" "<<"b.e2i="<<x.b.e2i<<" "<<"b.e3i="<<x.b.e3i<<" "<<std::endl<<"b.eoi="<<x.b.eoi<<" "<<std::endl<<"q.e123o="<<x.q.e123o<<" "<<"q.e123i="<<x.q.e123i<<" "<<std::endl<<"q.e23oi="<<x.q.e23oi<<" "<<"q.e31oi="<<x.q.e31oi<<" "<<"q.e12oi="<<x.q.e12oi<<" ";
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Multivector &x) {
    outs << "s="<<x.s<<" "<<std::endl<<"v.e1="<<x.v.e1<<" "<<"v.e2="<<x.v.e2<<" "<<"v.e3="<<x.v.e3<<" "<<std::endl<<"v.eo="<<x.v.eo<<" "<<"v.ei="<<x.v.ei<<" "<<"b.e23="<<x.b.e23<<" "<<"b.e31="<<x.b.e31<<" "<<"b.e12="<<x.b.e12<<" "<<std::endl<<"b.e1o="<<x.b.e1o<<" "<<"b.e2o="<<x.b.e2o<<" "<<"b.e3o="<<x.b.e3o<<" "<<std::endl<<"b.e1i="<<x.b.e1i<<" "<<"b.e2i="<<x.b.e2i<<" "<<"b.e3i="<<x.b.e3i<<" "<<std::endl<<"b.eoi="<<x.b.eoi<<" "<<std::endl<<"t.e123="<<x.t.e123<<" "<<std::endl<<"t.e23o="<<x.t.e23o<<" "<<"t.e31o="<<x.t.e31o<<" "<<"t.e12o="<<x.t.e12o<<" "<<"t.e23i="<<x.t.e23i<<" "<<"t.e31i="<<x.t.e31i<<" "<<"t.e12i="<<x.t.e12i<<" "<<std::endl<<"t.e1oi="<<x.t.e1oi<<" "<<"t.e2oi="<<x.t.e2oi<<" "<<"t.e3oi="<<x.t.e3oi<<" "<<std::endl<<"q.e123o="<<x.q.e123o<<" "<<"q.e123i="<<x.q.e123i<<" "<<std::endl<<"q.e23oi="<<x.q.e23oi<<" "<<"q.e31oi="<<x.q.e31oi<<" "<<"q.e12oi="<<x.q.e12oi<<" "<<std::endl<<"p="<<x.p<<" ";
    return outs;
}

} // namespace cga
