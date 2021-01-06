#include <iostream>

#include "cga.h"

int main()
{
    cga::Vector3 a = {3, 2, 5};
    std::cout << a << std::endl;

    cga::Vector b = {1, 2, 3, 4, 5};
    std::cout << b << std::endl;

    auto c = a*b;
    std::cout << c << std::endl;
}
