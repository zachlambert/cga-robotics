#include <iostream>

#include "objects.h"

int main()
{
    cga::Point a = cga::make_point(3, 2, 5);
    cga::CPoint A = cga::up(a);
    
    cga::Point b = cga::make_point(2, 2, 5);
    cga::CPoint B = cga::up(b);

    // Expect dot product of A and B to give -0.5 *
    // squared euclidean distance between points.
    // (If using normalised points)
    std::cout << inner(A, B) << std::endl;
}
