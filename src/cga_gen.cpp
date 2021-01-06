#include "cga_gen.h"

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

Quadvector operator*(const Vector &lhs, const Pseudoscalar &rhs)
{
    Quadvector result;
    result.e123o = -lhs.eo*rhs.p;
    result.e123i = lhs.ei*rhs.p;
    result.e23oi = lhs.e1*rhs.p;
    result.e31oi = lhs.e2*rhs.p;
    result.e12oi = lhs.e3*rhs.p;
    return result;
}

Quadvector outer(const Vector &lhs, const Pseudoscalar &rhs)
{
    Quadvector result;
    result.e123o = -lhs.eo*rhs.p;
    result.e123i = lhs.ei*rhs.p;
    result.e23oi = lhs.e1*rhs.p;
    result.e31oi = lhs.e2*rhs.p;
    result.e12oi = lhs.e3*rhs.p;
    return result;
}

Quadvector inner(const Vector &lhs, const Pseudoscalar &rhs)
{
    Quadvector result;
    result.e123o = -lhs.eo*rhs.p;
    result.e123i = lhs.ei*rhs.p;
    result.e23oi = lhs.e1*rhs.p;
    result.e31oi = lhs.e2*rhs.p;
    result.e12oi = lhs.e3*rhs.p;
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

Versor operator*(const Bivector &lhs, const Quadvector &rhs)
{
    Versor result;
    result.b.e23 = lhs.e1o*rhs.e123i+lhs.e1i*rhs.e123o+lhs.eoi*rhs.e23oi;
    result.b.e31 = lhs.e2o*rhs.e123i+lhs.e2i*rhs.e123o+lhs.eoi*rhs.e31oi;
    result.b.e12 = lhs.e3o*rhs.e123i+lhs.e3i*rhs.e123o+lhs.eoi*rhs.e12oi;
    result.b.e1o = -lhs.e23*rhs.e123o-lhs.e2o*rhs.e12oi+lhs.e3o*rhs.e31oi;
    result.b.e2o = -lhs.e31*rhs.e123o+lhs.e1o*rhs.e12oi-lhs.e3o*rhs.e23oi;
    result.b.e3o = -lhs.e12*rhs.e123o-lhs.e1o*rhs.e31oi+lhs.e2o*rhs.e23oi;
    result.b.e1i = -lhs.e23*rhs.e123i+lhs.e2i*rhs.e12oi-lhs.e3i*rhs.e31oi;
    result.b.e2i = -lhs.e31*rhs.e123i-lhs.e1i*rhs.e12oi+lhs.e3i*rhs.e23oi;
    result.b.e3i = -lhs.e12*rhs.e123i+lhs.e1i*rhs.e31oi-lhs.e2i*rhs.e23oi;
    result.b.eoi = -lhs.e12*rhs.e12oi-lhs.e31*rhs.e31oi-lhs.e23*rhs.e23oi;
    result.q.e123o = lhs.e1o*rhs.e23oi+lhs.e2o*rhs.e31oi+lhs.e3o*rhs.e12oi-lhs.eoi*rhs.e123o;
    result.q.e123i = -lhs.e1i*rhs.e23oi-lhs.e2i*rhs.e31oi-lhs.e3i*rhs.e12oi+lhs.eoi*rhs.e123i;
    result.q.e23oi = lhs.e12*rhs.e31oi-lhs.e31*rhs.e12oi-lhs.e1o*rhs.e123i+lhs.e1i*rhs.e123o;
    result.q.e31oi = -lhs.e12*rhs.e23oi+lhs.e23*rhs.e12oi-lhs.e2o*rhs.e123i+lhs.e2i*rhs.e123o;
    result.q.e12oi = lhs.e31*rhs.e23oi-lhs.e23*rhs.e31oi-lhs.e3o*rhs.e123i+lhs.e3i*rhs.e123o;
    return result;
}

Quadvector outer(const Bivector &lhs, const Quadvector &rhs)
{
    Quadvector result;
    result.e123o = lhs.e1o*rhs.e23oi+lhs.e2o*rhs.e31oi+lhs.e3o*rhs.e12oi-lhs.eoi*rhs.e123o;
    result.e123i = -lhs.e1i*rhs.e23oi-lhs.e2i*rhs.e31oi-lhs.e3i*rhs.e12oi+lhs.eoi*rhs.e123i;
    result.e23oi = lhs.e12*rhs.e31oi-lhs.e31*rhs.e12oi-lhs.e1o*rhs.e123i+lhs.e1i*rhs.e123o;
    result.e31oi = -lhs.e12*rhs.e23oi+lhs.e23*rhs.e12oi-lhs.e2o*rhs.e123i+lhs.e2i*rhs.e123o;
    result.e12oi = lhs.e31*rhs.e23oi-lhs.e23*rhs.e31oi-lhs.e3o*rhs.e123i+lhs.e3i*rhs.e123o;
    return result;
}

Bivector inner(const Bivector &lhs, const Quadvector &rhs)
{
    Bivector result;
    result.e23 = lhs.e1o*rhs.e123i+lhs.e1i*rhs.e123o+lhs.eoi*rhs.e23oi;
    result.e31 = lhs.e2o*rhs.e123i+lhs.e2i*rhs.e123o+lhs.eoi*rhs.e31oi;
    result.e12 = lhs.e3o*rhs.e123i+lhs.e3i*rhs.e123o+lhs.eoi*rhs.e12oi;
    result.e1o = -lhs.e23*rhs.e123o-lhs.e2o*rhs.e12oi+lhs.e3o*rhs.e31oi;
    result.e2o = -lhs.e31*rhs.e123o+lhs.e1o*rhs.e12oi-lhs.e3o*rhs.e23oi;
    result.e3o = -lhs.e12*rhs.e123o-lhs.e1o*rhs.e31oi+lhs.e2o*rhs.e23oi;
    result.e1i = -lhs.e23*rhs.e123i+lhs.e2i*rhs.e12oi-lhs.e3i*rhs.e31oi;
    result.e2i = -lhs.e31*rhs.e123i-lhs.e1i*rhs.e12oi+lhs.e3i*rhs.e23oi;
    result.e3i = -lhs.e12*rhs.e123i+lhs.e1i*rhs.e31oi-lhs.e2i*rhs.e23oi;
    result.eoi = -lhs.e12*rhs.e12oi-lhs.e31*rhs.e31oi-lhs.e23*rhs.e23oi;
    return result;
}

Trivector operator*(const Bivector &lhs, const Pseudoscalar &rhs)
{
    Trivector result;
    result.e123 = lhs.eoi*rhs.p;
    result.e23o = -lhs.e1o*rhs.p;
    result.e31o = -lhs.e2o*rhs.p;
    result.e12o = -lhs.e3o*rhs.p;
    result.e23i = lhs.e1i*rhs.p;
    result.e31i = lhs.e2i*rhs.p;
    result.e12i = lhs.e3i*rhs.p;
    result.e1oi = -lhs.e23*rhs.p;
    result.e2oi = -lhs.e31*rhs.p;
    result.e3oi = -lhs.e12*rhs.p;
    return result;
}

Trivector outer(const Bivector &lhs, const Pseudoscalar &rhs)
{
    Trivector result;
    result.e123 = lhs.eoi*rhs.p;
    result.e23o = -lhs.e1o*rhs.p;
    result.e31o = -lhs.e2o*rhs.p;
    result.e12o = -lhs.e3o*rhs.p;
    result.e23i = lhs.e1i*rhs.p;
    result.e31i = lhs.e2i*rhs.p;
    result.e12i = lhs.e3i*rhs.p;
    result.e1oi = -lhs.e23*rhs.p;
    result.e2oi = -lhs.e31*rhs.p;
    result.e3oi = -lhs.e12*rhs.p;
    return result;
}

Trivector inner(const Bivector &lhs, const Pseudoscalar &rhs)
{
    Trivector result;
    result.e123 = lhs.eoi*rhs.p;
    result.e23o = -lhs.e1o*rhs.p;
    result.e31o = -lhs.e2o*rhs.p;
    result.e12o = -lhs.e3o*rhs.p;
    result.e23i = lhs.e1i*rhs.p;
    result.e31i = lhs.e2i*rhs.p;
    result.e12i = lhs.e3i*rhs.p;
    result.e1oi = -lhs.e23*rhs.p;
    result.e2oi = -lhs.e31*rhs.p;
    result.e3oi = -lhs.e12*rhs.p;
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

Multivector operator*(const Trivector &lhs, const Quadvector &rhs)
{
    Multivector result;
    result.v.e1 = -lhs.e23o*rhs.e123i-lhs.e23i*rhs.e123o-lhs.e2oi*rhs.e12oi+lhs.e3oi*rhs.e31oi;
    result.v.e2 = -lhs.e31o*rhs.e123i-lhs.e31i*rhs.e123o+lhs.e1oi*rhs.e12oi-lhs.e3oi*rhs.e23oi;
    result.v.e3 = -lhs.e12o*rhs.e123i-lhs.e12i*rhs.e123o-lhs.e1oi*rhs.e31oi+lhs.e2oi*rhs.e23oi;
    result.v.eo = 0.5*lhs.e123*rhs.e123i-0.5*lhs.e12i*rhs.e12oi-0.5*lhs.e31i*rhs.e31oi-0.5*lhs.e23i*rhs.e23oi;
    result.v.ei = -lhs.e123*rhs.e123i+lhs.e12i*rhs.e12oi+lhs.e31i*rhs.e31oi+lhs.e23i*rhs.e23oi;
    result.t.e123 = lhs.e1oi*rhs.e23oi+lhs.e2oi*rhs.e31oi+lhs.e3oi*rhs.e12oi;
    result.t.e23o = lhs.e12o*rhs.e31oi-lhs.e31o*rhs.e12oi-lhs.e1oi*rhs.e123o;
    result.t.e31o = -lhs.e12o*rhs.e23oi+lhs.e23o*rhs.e12oi-lhs.e2oi*rhs.e123o;
    result.t.e12o = lhs.e31o*rhs.e23oi-lhs.e23o*rhs.e31oi-lhs.e3oi*rhs.e123o;
    result.t.e23i = -lhs.e12i*rhs.e31oi+lhs.e31i*rhs.e12oi+lhs.e1oi*rhs.e123i;
    result.t.e31i = lhs.e12i*rhs.e23oi-lhs.e23i*rhs.e12oi+lhs.e2oi*rhs.e123i;
    result.t.e12i = -lhs.e31i*rhs.e23oi+lhs.e23i*rhs.e31oi+lhs.e3oi*rhs.e123i;
    result.t.e1oi = -lhs.e123*rhs.e23oi+lhs.e23o*rhs.e123i-lhs.e23i*rhs.e123o;
    result.t.e2oi = -lhs.e123*rhs.e31oi+lhs.e31o*rhs.e123i-lhs.e31i*rhs.e123o;
    result.t.e3oi = -lhs.e123*rhs.e12oi+lhs.e12o*rhs.e123i-lhs.e12i*rhs.e123o;
    return result;
}

Trivector outer(const Trivector &lhs, const Quadvector &rhs)
{
    Trivector result;
    result.e123 = lhs.e1oi*rhs.e23oi+lhs.e2oi*rhs.e31oi+lhs.e3oi*rhs.e12oi;
    result.e23o = lhs.e12o*rhs.e31oi-lhs.e31o*rhs.e12oi-lhs.e1oi*rhs.e123o;
    result.e31o = -lhs.e12o*rhs.e23oi+lhs.e23o*rhs.e12oi-lhs.e2oi*rhs.e123o;
    result.e12o = lhs.e31o*rhs.e23oi-lhs.e23o*rhs.e31oi-lhs.e3oi*rhs.e123o;
    result.e23i = -lhs.e12i*rhs.e31oi+lhs.e31i*rhs.e12oi+lhs.e1oi*rhs.e123i;
    result.e31i = lhs.e12i*rhs.e23oi-lhs.e23i*rhs.e12oi+lhs.e2oi*rhs.e123i;
    result.e12i = -lhs.e31i*rhs.e23oi+lhs.e23i*rhs.e31oi+lhs.e3oi*rhs.e123i;
    result.e1oi = -lhs.e123*rhs.e23oi+lhs.e23o*rhs.e123i-lhs.e23i*rhs.e123o;
    result.e2oi = -lhs.e123*rhs.e31oi+lhs.e31o*rhs.e123i-lhs.e31i*rhs.e123o;
    result.e3oi = -lhs.e123*rhs.e12oi+lhs.e12o*rhs.e123i-lhs.e12i*rhs.e123o;
    return result;
}

Vector inner(const Trivector &lhs, const Quadvector &rhs)
{
    Vector result;
    result.e1 = -lhs.e23o*rhs.e123i-lhs.e23i*rhs.e123o-lhs.e2oi*rhs.e12oi+lhs.e3oi*rhs.e31oi;
    result.e2 = -lhs.e31o*rhs.e123i-lhs.e31i*rhs.e123o+lhs.e1oi*rhs.e12oi-lhs.e3oi*rhs.e23oi;
    result.e3 = -lhs.e12o*rhs.e123i-lhs.e12i*rhs.e123o-lhs.e1oi*rhs.e31oi+lhs.e2oi*rhs.e23oi;
    result.eo = 0.5*lhs.e123*rhs.e123i-0.5*lhs.e12i*rhs.e12oi-0.5*lhs.e31i*rhs.e31oi-0.5*lhs.e23i*rhs.e23oi;
    result.ei = -lhs.e123*rhs.e123i+lhs.e12i*rhs.e12oi+lhs.e31i*rhs.e31oi+lhs.e23i*rhs.e23oi;
    return result;
}

Bivector operator*(const Trivector &lhs, const Pseudoscalar &rhs)
{
    Bivector result;
    result.e23 = lhs.e1oi*rhs.p;
    result.e31 = lhs.e2oi*rhs.p;
    result.e12 = lhs.e3oi*rhs.p;
    result.e1o = lhs.e23o*rhs.p;
    result.e2o = lhs.e31o*rhs.p;
    result.e3o = lhs.e12o*rhs.p;
    result.e1i = -lhs.e23i*rhs.p;
    result.e2i = -lhs.e31i*rhs.p;
    result.e3i = -lhs.e12i*rhs.p;
    result.eoi = -lhs.e123*rhs.p;
    return result;
}

Bivector outer(const Trivector &lhs, const Pseudoscalar &rhs)
{
    Bivector result;
    result.e23 = lhs.e1oi*rhs.p;
    result.e31 = lhs.e2oi*rhs.p;
    result.e12 = lhs.e3oi*rhs.p;
    result.e1o = lhs.e23o*rhs.p;
    result.e2o = lhs.e31o*rhs.p;
    result.e3o = lhs.e12o*rhs.p;
    result.e1i = -lhs.e23i*rhs.p;
    result.e2i = -lhs.e31i*rhs.p;
    result.e3i = -lhs.e12i*rhs.p;
    result.eoi = -lhs.e123*rhs.p;
    return result;
}

Bivector inner(const Trivector &lhs, const Pseudoscalar &rhs)
{
    Bivector result;
    result.e23 = lhs.e1oi*rhs.p;
    result.e31 = lhs.e2oi*rhs.p;
    result.e12 = lhs.e3oi*rhs.p;
    result.e1o = lhs.e23o*rhs.p;
    result.e2o = lhs.e31o*rhs.p;
    result.e3o = lhs.e12o*rhs.p;
    result.e1i = -lhs.e23i*rhs.p;
    result.e2i = -lhs.e31i*rhs.p;
    result.e3i = -lhs.e12i*rhs.p;
    result.eoi = -lhs.e123*rhs.p;
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

Vector operator*(const Quadvector &lhs, const Pseudoscalar &rhs)
{
    Vector result;
    result.e1 = -lhs.e23oi*rhs.p;
    result.e2 = -lhs.e31oi*rhs.p;
    result.e3 = -lhs.e12oi*rhs.p;
    result.eo = 0.5*lhs.e123i*rhs.p;
    result.ei = -lhs.e123i*rhs.p;
    return result;
}

Vector outer(const Quadvector &lhs, const Pseudoscalar &rhs)
{
    Vector result;
    result.e1 = -lhs.e23oi*rhs.p;
    result.e2 = -lhs.e31oi*rhs.p;
    result.e3 = -lhs.e12oi*rhs.p;
    result.eo = 0.5*lhs.e123i*rhs.p;
    result.ei = -lhs.e123i*rhs.p;
    return result;
}

Vector inner(const Quadvector &lhs, const Pseudoscalar &rhs)
{
    Vector result;
    result.e1 = -lhs.e23oi*rhs.p;
    result.e2 = -lhs.e31oi*rhs.p;
    result.e3 = -lhs.e12oi*rhs.p;
    result.eo = 0.5*lhs.e123i*rhs.p;
    result.ei = -lhs.e123i*rhs.p;
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

std::ostream& operator<<(std::ostream& outs, const Vector &x) {
    outs << x.e1 << x.e2 << x.e3 << std::endl << x.eo << x.ei;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Bivector &x) {
    outs << x.e23 << x.e31 << x.e12 << std::endl << x.e1o << x.e2o << x.e3o << std::endl << x.e1i << x.e2i << x.e3i << std::endl << x.eoi;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Trivector &x) {
    outs << x.e123 << std::endl << x.e23o << x.e31o << x.e12o << std::endl << x.e23i << x.e31i << x.e12i << std::endl << x.e1oi << x.e2oi << x.e3oi;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Quadvector &x) {
    outs << x.e123o << x.e123i << std::endl << x.e23oi << x.e31oi << x.e12oi;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Pseudoscalar &x) {
    outs << x.p;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Rotor &x) {
    outs << x.s << std::endl << x.b.e23 << x.b.e31 << x.b.e12 << std::endl << x.b.e1o << x.b.e2o << x.b.e3o << std::endl << x.b.e1i << x.b.e2i << x.b.e3i << std::endl << x.b.eoi;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Versor &x) {
    outs << x.s << std::endl << x.b.e23 << x.b.e31 << x.b.e12 << std::endl << x.b.e1o << x.b.e2o << x.b.e3o << std::endl << x.b.e1i << x.b.e2i << x.b.e3i << std::endl << x.b.eoi << std::endl << x.q.e123o << x.q.e123i << std::endl << x.q.e23oi << x.q.e31oi << x.q.e12oi;
    return outs;
}
std::ostream& operator<<(std::ostream& outs, const Multivector &x) {
    outs << x.s << std::endl << x.v.e1 << x.v.e2 << x.v.e3 << std::endl << x.v.eo << x.v.ei << x.b.e23 << x.b.e31 << x.b.e12 << std::endl << x.b.e1o << x.b.e2o << x.b.e3o << std::endl << x.b.e1i << x.b.e2i << x.b.e3i << std::endl << x.b.eoi << std::endl << x.t.e123 << std::endl << x.t.e23o << x.t.e31o << x.t.e12o << x.t.e23i << x.t.e31i << x.t.e12i << std::endl << x.t.e1oi << x.t.e2oi << x.t.e3oi << std::endl << x.q.e123o << x.q.e123i << std::endl << x.q.e23oi << x.q.e31oi << x.q.e12oi << std::endl << x.p;
    return outs;
}
