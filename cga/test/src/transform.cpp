#include "gtest/gtest.h"
#include "cga/transform.h"
#include "cga/geometry.h"

TEST(transform, rotation)
{
    cga::Vector3 a(1, 0, 0);

    // Rotate 90 deg about z -> {0, 1, 0}
    auto R0 = cga::make_rotation(M_PI/2, cga::make_axis(0, 0, 1));
    ASSERT_EQ((R0*a).v, cga::Vector3(1/std::sqrt(2), 1/std::sqrt(2), 0));
    auto a2 = (R0*a*cga::reverse(R0)).v;
    ASSERT_EQ(a2, cga::Vector3(0, 1, 0));

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
    auto R = R2*R1;
    a = transform_vector(a, R);
    ASSERT_EQ(a, cga::Vector3(0.5, 0.5, 1/std::sqrt(2)));

    // Transform back
    R = reverse(R);
    a = transform_vector(a, R);
    ASSERT_EQ(a, cga::Vector3(1, 0, 0));
}

TEST(transform, extract_components)
{
    auto V1 = cga::make_translation(0, 1, 1);
    auto V2 = cga::make_rotation(M_PI/2, cga::make_axis(0, 0, 1));
    auto V3 = cga::make_translation(1, 0, 0);
    auto V = cga::Versor(V1);

    cga::Vector3 p;
    cga::Rotor3 R;
    cga::extract_components(V, R, p);
    ASSERT_EQ(p, cga::Vector3(0, 1, 1));
    ASSERT_EQ(R, cga::make_rotation(0, cga::make_axis(0, 0, 1)));
}
