#include <iostream>
#include <vector>

#include "cga.h"
#include "geometry.h"

struct P {
    double x;
    double y;
    double z;
};

struct Q {
    double x[3];
};

int main()
{
    std::cout.precision(3);

    cga::Vector3 a = {1/std::sqrt(2), 1/std::sqrt(2), 0};
    auto R1 = cga::make_rotation(M_PI/2, {0, 0, 1});
    auto R2 = cga::make_rotation(M_PI/2, {1/std::sqrt(2), -1/std::sqrt(2), 0});
    cga::Rotor3 R = R2*R1;

    auto b = rotate(a, R);
    std::cout << b << std::endl;
}
