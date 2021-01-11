#include "gtest/gtest.h"
#include "cga/transform.h"

TEST(transform, rotation)
{
    cga::Vector3 a(1, 0, 0);

    // Rotate 45 deg about z -> {1/sqrt(2), 1/sqrt(2), 0}
    auto R1 = cga::make_rotation(M_PI/4, cga::make_axis(0, 0, 1));
    auto b = transform_vector(a, R1);
    ASSERT_EQ(b, cga::Vector3(1/std::sqrt(2), 1/std::sqrt(2), 0));

    // Rotate 45 deg about (1/sqrt(2), -1/sqrt(2), 0) -> {0.5, 0.5, 1/sqrt(2)}
    auto R2 = cga::make_rotation(
        M_PI/4, cga::make_axis(1/std::sqrt(2), -1/std::sqrt(2), 0)
    );
    auto c = transform_vector(b, R2);
    ASSERT_EQ(c, cga::Vector3(0.5, 0.5, 1/std::sqrt(2)));

    // Combine these
    auto R = R1*R2;
    a = transform_vector(a, R);
    ASSERT_EQ(a, cga::Vector3(0.5, 0.5, 1/std::sqrt(2)));

    // Transform back
    R = reverse(R);
    a = transform_vector(a, R);
    ASSERT_EQ(a, cga::Vector3(1, 0, 0));
}
