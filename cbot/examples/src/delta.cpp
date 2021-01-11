#include "cbot/delta.h"
#include <iostream>

// namespace cbot { using namespace linalg_impl; }
namespace cbot { using namespace cga_impl; }

int main()
{
    cbot::Delta::Config config;
    cbot::Delta delta(config);
    cbot::Pose pose;
    std::vector<std::string> joint_names = {
        "theta_1", "theta_2", "theta_3"
    };
    std::vector<double> joint_positions = {
        0.8, 0.8, 0.8
    };

    if (delta.fk_pose(joint_names, joint_positions, pose)) {
        for (std::size_t i = 0; i < joint_names.size(); i++) {
            std::cout << joint_names[i] << "=" << joint_positions[i];
            if (i != joint_names.size() - 1) {
                std::cout << std::endl;
            }
        }
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
        std::cerr << "No solution found." << std::endl;
    }

    return 0;
}
