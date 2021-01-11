#include "gtest/gtest.h"
#include "cga/cga.h"

TEST(gen, geometric_product)
{
    cga::Vector a(1, 2, 3, 4, 5);
    cga::Vector b(5, 4, 3, 2, 1);
    auto c = a*b;

    double s_expect = a.e1*b.e1 + a.e2*b.e2 + a.e3*b.e3 - a.eo*b.ei - a.ei*b.eo;
    ASSERT_EQ(c.s, s_expect);
}

TEST(gen, outer_product)
{
    cga::Vector3 a(5, 1, 3);
    cga::Vector3 b(4, 2, -8);
    auto c = outer(a, b);

    cga::Bivector3 expect;
    expect.e31 = 3*4 - 5*-8;
    expect.e23 = 1*-8 - 3*2;
    expect.e12 = 5*2 - 1*4;

    ASSERT_EQ(c, expect);
}
