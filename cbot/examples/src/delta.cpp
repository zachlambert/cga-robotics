#include "cbot/delta.h"
#include <iostream>

namespace cbot { using namespace linalg_impl; }

int main()
{
    cbot::Delta::Structure structure;
    cbot::Delta delta(structure);
    std::unordered_map<std::string, cbot::JointState> joints;
    cbot::Pose pose = delta.fk_pose(joints);

    std::cout << "Pos = (";
    std::cout<<pose.position.x<<", ";
    std::cout<<pose.position.y<<", ";
    std::cout<<pose.position.z<<")"<<std::endl;
    std::cout << "Orient = (";
    std::cout<<pose.orientation.w<<", ";
    std::cout<<pose.orientation.x<<", ";
    std::cout<<pose.orientation.y<<", ";
    std::cout<<pose.orientation.z<<")"<<std::endl;

    return 0;
}
