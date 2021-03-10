#ifndef CGA_CONSTANTS_H
#define CGA_CONSTANTS_H

#include "cga/cga.h"

namespace cga {

// Useful basis vectors
static Vector3 e1(1, 0, 0);
static Vector3 e2(0, 1, 0);
static Vector3 e3(0, 0, 1);
static Vector eo(0, 0, 0, 1, 0);
static Vector ei(0, 0, 0, 0, 1);

// Pseudoscalars
static Pseudoscalar3 I3(1);
static Pseudoscalar I5(1);

} // namespace cga

#endif
