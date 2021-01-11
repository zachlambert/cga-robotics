#ifndef COMMON_CHAIN_H
#define COMMON_CHAIN_H

#include <vector>
#include <vector>
#include "cbot/types.h"

// Only allow revolute joints.
// Joint i defines the transform between links (i-1) and i, with the parameters:
// alpha_(i-1), a_(i-1), theta_(i), d_(i)
// Where only theta_i is a variable

namespace cbot {

class Serial {
public:
    struct Segment {
        double alpha, a, d;
    };
    struct Config {
        std::vector<Segment> segments;
    };
    Serial(Config config): config(config) {}

    // TODO

private:
    Config config;
};

}

#endif
