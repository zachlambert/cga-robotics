#include "gtest/gtest.h"
#include "cga/geometry.h"

TEST(gen, point)
{
    cga::Vector3 x(1, 2, 3);
    auto X = cga::make_point({1, 2, 3});
    auto result = cga::describe(X);
    ASSERT_EQ(result.type, cga::GeometryResult::Type::Point);
    ASSERT_EQ(result.point.position, x);
}

TEST(gen, sphere)
{
    cga::Vector3 pos(5, -12, 0);
    double rad = 2;
    auto Sigma = cga::make_sphere(pos, rad);
    auto result = cga::describe(Sigma);
    ASSERT_EQ(result.type, cga::GeometryResult::Type::Sphere);
    ASSERT_EQ(result.sphere.position, pos);
    ASSERT_EQ(result.sphere.radius, rad);
    ASSERT_EQ(result.sphere.real, true);
}
