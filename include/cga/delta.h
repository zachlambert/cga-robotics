#ifndef CGA_DELTA_H
#define CGA_DELTA_H

#include "common/delta.h"
#include "gen/cga.h"

namespace cga {

class Delta: public DeltaBase {
public:
    Delta(Structure structure);

    Pose fk_pose(const std::unordered_map<std::string, JointState> &joints);
    Twist fk_twist(const std::unordered_map<std::string, JointState> &joints);
    void ik_pose(const Pose &pose, std::unordered_map<std::string, JointState> &joints);
    void ik_twist(const Twist &twist, std::unordered_map<std::string, JointState> &joints);
    void force_control(const Twist &twist, std::unordered_map<std::string, JointState> &joints);
};

}

#endif
