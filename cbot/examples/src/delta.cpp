#include "cbot/delta.h"
#include <iostream>

int main()
{
    cbot::Delta::Dimensions dim;
    dim.r_base = 0.15;
    dim.r_ee = 0.05;
    dim.l_upper = 0.3;
    dim.l_lower = 0.4;
    
    cbot::Delta::JointNames joint_names;
    joint_names.theta.push_back("theta_1");
    joint_names.theta.push_back("theta_2");
    joint_names.theta.push_back("theta_3");
    joint_names.alpha.push_back("alpha_1");
    joint_names.alpha.push_back("alpha_2");
    joint_names.alpha.push_back("alpha_3");
    joint_names.beta.push_back("beta_1");
    joint_names.beta.push_back("beta_2");
    joint_names.beta.push_back("beta_3");
    joint_names.gamma.push_back("gamma_1");
    joint_names.gamma.push_back("gamma_2");
    joint_names.gamma.push_back("gamma_3");

    cbot::Delta delta(dim, joint_names);

    delta.set_joint_position("theta_1", 0.5);
    delta.set_joint_position("theta_2", 0.5);
    delta.set_joint_position("theta_3", 0.5);

    if (delta.update_pose()) {
        std::cout << delta.get_pose() << std::endl;
    } else {
        std::cerr << "Failed to update pose." << std::endl;
    }

    return 0;
}
