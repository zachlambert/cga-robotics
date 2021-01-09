#include <iostream>
#include <vector>

#include "cga.h"
#include "geometry.h"
#include "transform.h"

int main()
{
    std::cout.precision(3);

    cga::Vector3 a = {1/std::sqrt(2), 1/std::sqrt(2), 0};
    auto R1 = cga::make_rotation(M_PI/2, {0, 0, 1});
    auto R2 = cga::make_rotation(M_PI/2, {1/std::sqrt(2), -1/std::sqrt(2), 0});
    cga::Rotor3 R = R2*R1;

    auto b = cga::Vector3(rotate_vector(a, R));
    std::cout << b << std::endl;
}
