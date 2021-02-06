#include "cbot/delta.h"
#include <iostream>

// namespace cbot { using namespace linalg_impl; }
namespace cbot { using namespace cga_impl; }

int main()
{
    cbot::Delta::Config config;
    config.r_base = 0.15;
    config.r_ee = 0.05;
    config.l_upper = 0.3;
    config.l_lower = 0.4;

    cbot::Delta delta(config);
    cbot::Pose pose;

    cbot::Delta::Joints joints_pos;
    joints_pos.theta[0] = 0.8;
    joints_pos.theta[1] = 0.4;
    joints_pos.theta[2] = 1.1;

    cbot::Delta::JointsDep joints_dep_pos;

    if (delta.fk_pose(joints_pos, &joints_dep_pos, pose)) {
        std::cout << "Pos = (";
        std::cout<<pose.position.x<<", ";
        std::cout<<pose.position.y<<", ";
        std::cout<<pose.position.z<<")"<<std::endl;
        std::cout << "Orient = (";
        std::cout<<pose.orientation.w<<", ";
        std::cout<<pose.orientation.x<<", ";
        std::cout<<pose.orientation.y<<", ";
        std::cout<<pose.orientation.z<<")"<<std::endl;
    } else {
        std::cerr << "No FK solution found." << std::endl;
    }

    pose.position.x = 0.05;
    pose.position.y = 0.1;
    pose.position.z = -0.3;
    if (delta.ik_pose(pose, joints_pos)) {
        for (int i = 0; i < 3; i++) {
            std::cout << "Theta " << (i+1) << " = ";
            std::cout << joints_pos.theta[i] << std::endl;;
        }
    } else {
        std::cerr << "No IK solution found." << std::endl;
    }

    return 0;
}
