#include <iostream>
#include <vector>

#include "cga.h"
#include "transform.h"

int main()
{
    std::cout.precision(3);

    cga::Vector3 a = {1, 0, 0};
    auto R = cga::make_rotation(M_PI/2, {0, 0, 1});

    // Rotate 90 deg about z -> {0, 1, 0}
    // Rotate 90 deg about x -> {0, 0, 1}
    a = transform_vector(a, R);
    std::cout << "a = " << a << std::endl;

    // Transform back
    R = reverse(R);
    a = transform_vector(a, R);
    std::cout << "a = " << a << std::endl;
}
