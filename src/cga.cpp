#include "cga.h"

namespace cga {

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << v.e1 << ", " << v.e2 << ", " << v.e3 << std::endl;
    os << v.no << ", " << v.ni;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Bivector &b)
{
    os << b.e12 << ", " << b.e23 << ", " << b.e31 << std::endl;
    os << b.e1no << ", " << b.e2no << ", " << b.e3no << std::endl;
    os << b.e1ni << ", " << b.e2ni << ", " << b.e3ni << std::endl;
    os << b.E;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Rotor &r)
{
    os << r.scalar << std::endl;
    os << r.bivector;
    return os;
}


} // namespace cga
