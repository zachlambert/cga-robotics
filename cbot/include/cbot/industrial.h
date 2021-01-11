#ifndef COMMON_INDUSTRIAL_H
#define COMMON_INDUSTRIAL_H

#include "cbot/types.h"

// A 6 DoF industrial manipulator
// The geometry is chosen such that the three last joints share a common point,
// allowing for a closed-form solution

namespace cbot {

class IndustrialBase {
public:
    struct Config {
        // Link lengths
        double base;
        double lower;
        double upper;
        double tool;
    };
    IndustrialBase(Config config): config(config) {}

    // TODO

private:
    Config config;
};

} // namespace cbot

#endif
