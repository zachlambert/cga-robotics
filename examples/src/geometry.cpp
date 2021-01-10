#include <iostream>
#include <vector>

#include "cga.h"
#include "geometry.h"
#include "transform.h"

int main()
{
    auto x = cga::make_plane(cga::Vector3(1, 0, 0), 1);
    std::cout << x << std::endl;
    std::cout << cga::describe(x) << std::endl;

    auto R = cga::make_rotation(M_PI/2, {0, 0, 1});
    x = cga::transform_vector(x, R);
    std::cout << x << std::endl;
    std::cout << cga::describe(x) << std::endl;
}
