#include <iostream>

#include "cga/cga.h"

int main()
{
    cga::Vector3 a = {3, 2, 5};
    std::cout << a << std::endl;

    cga::Vector b = {1, 2, 3, 4, 5};
    std::cout << b << std::endl;

    auto c = a*b;
    std::cout << c << std::endl;

    cga::Vector a2 = a;
    std::cout << a2 << std::endl;

    cga::Multivector d = outer(a, b) * a2;
    std::cout << d << std::endl;
    std::cout << d.v << std::endl;
}
