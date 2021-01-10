#ifndef COMMON_CHAIN_H
#define COMMON_CHAIN_H

#include <vector>
#include <unordered_map>
#include "cbot/common/robot.h"

// Only allow revolute joints.
// Joint i defines the transform between links (i-1) and i, with the parameters:
// alpha_(i-1), a_(i-1), theta_(i), d_(i)
// Where only theta_i is a variable

class Chain: Robot {
public:
    struct Joint {
        double alpha, a;
        double theta, d;
    };
    Chain() {};
    void add_joint(const Joint &joint){ joints.push_back(joint); }
private:
    std::vector<Joint> joints;
};

#endif
