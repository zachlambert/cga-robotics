
#include "gtest/gtest.h"
#include "cga/transform.h"

constexpr double ABS_ERROR = 1e-12;

TEST(transform, rotation)
{
    cga::Vector3 a = {1, 0, 0};
    // Rotate 90 deg about z -> {0, 1, 0}
    auto R = cga::make_rotation(M_PI/2, cga::make_axis(0, 0, 1));
    a = transform_vector(a, R);
    ASSERT_NEAR(a.e1, 0, ABS_ERROR);
    ASSERT_NEAR(a.e2, 1, ABS_ERROR);
    ASSERT_NEAR(a.e3, 0, ABS_ERROR);

    // Transform back
    R = reverse(R);
    a = transform_vector(a, R);
    ASSERT_NEAR(a.e1, 1, ABS_ERROR);
    ASSERT_NEAR(a.e2, 0, ABS_ERROR);
    ASSERT_NEAR(a.e3, 0, ABS_ERROR);
}
