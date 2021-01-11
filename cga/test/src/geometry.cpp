#include "gtest/gtest.h"
#include "cga/geometry.h"

TEST(gen, geometric_product)
{
    auto X = cga::make_point({1, 2, 3});
    auto x = cga::describe(X);
    ASSERT_EQ(x.type, cga::GeometryResult::Type::Point);
    ASSERT_EQ(x.point.position.e1, 1);
    ASSERT_EQ(x.point.position.e2, 2);
    ASSERT_EQ(x.point.position.e3, 3);
}
