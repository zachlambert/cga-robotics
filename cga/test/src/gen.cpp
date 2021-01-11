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
    cga::Vector a(1, 2, 3, 4, 5);
    cga::Vector b(5, 4, 3, 2, 1);
    auto c = a*b;
}
