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
        "theta_1", "theta_2", "theta_3", "alpha_1", "alpha_2", "alpha_3",
        "beta_1", "beta_2", "beta_3", "gamma_1", "gamma_2", "gamma_3"
    };
    std::vector<double> joint_positions(joint_names.size());
    joint_positions[0] = 0.8;
    joint_positions[1] = 0.8;
    joint_positions[2] = 0.8;

    if (delta.fk_pose(joint_names, joint_positions, pose)) {
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
