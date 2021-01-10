#ifndef COMMON_DELTA_H
#define COMMON_DELTA_H

#include "common/robot.h"

class DeltaBase: Robot {
public:
    struct Structure {
        double base_radius, ee_radius;
        double upper_length, lower_length;
        std::string theta_names[3];
        std::string alpha_names[3];
        std::string beta_names[3];
        std::string gamma_names[3];
    };
    DeltaBase(Structure structure): structure(structure) {}
private:
    Structure structure;
    double joint_state[3];
};

#endif
