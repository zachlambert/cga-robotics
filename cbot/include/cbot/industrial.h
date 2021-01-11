#ifndef COMMON_INDUSTRIAL_H
#define COMMON_INDUSTRIAL_H

#include "cbot/robot.h"

// A 6 DoF industrial manipulator
// The geometry is chosen such that the three last joints share a common point,
// allowing for a closed-form solution

class IndustrialBase: Robot {
public:
    struct Structure {
        double base_length, lower_length, upper_length, tool_length;
        std::string joint_names[6];
    };
    IndustrialBase(Structure structure): structure(structure) {}
private:
    Structure structure;
};

#endif
