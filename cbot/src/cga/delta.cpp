#include "cbot/delta.h"

namespace cga {

class Delta::Impl {
public:
    double joint_pos[3];
};

Delta::Delta(Structure structure): DeltaBase(structure), pimpl(new Impl())
{

}

Pose Delta::fk_pose(const std::unordered_map<std::string, JointState> &joints)
{
    Pose pose;
    return pose;
}

Twist Delta::fk_twist(const std::unordered_map<std::string, JointState> &joints)
{
    Twist twist;
    return twist;
}

void Delta::ik_pose(const Pose &pose, std::unordered_map<std::string, JointState> &joints)
{

}

void Delta::ik_twist(const Twist &twist, std::unordered_map<std::string, JointState> &joints)
{

}

void Delta::force_control(const Twist &twist, std::unordered_map<std::string, JointState> &joints)
{

}

} // namespace cga
