#include "cbot/delta.h"
#include <iostream>
#include <chrono>
#include <random>
#include <functional>

void set_random_joint_positions(cbot::Delta &delta)
{
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(0, 1);
    static auto sample = std::bind(distribution, generator);

    double theta[3];
    for (int i = 0; i < 3; i++) {
        theta[i] = (-10.0 + sample()*90)*(M_PI/180);
    }
    delta.set_joint_position("theta_1", theta[0]);
    delta.set_joint_position("theta_2", theta[1]);
    delta.set_joint_position("theta_3", theta[2]);
}

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

    typedef std::chrono::high_resolution_clock clock_t;
    typedef std::chrono::duration<double, std::ratio<1>> second_t;
    second_t elapsed;
    std::chrono::time_point<clock_t> start;

    constexpr std::size_t N = 1e5;
    std::size_t i = 0;
    while (i < N) {
        set_random_joint_positions(delta);
        start = clock_t::now();
        bool success = delta.update_pose();
        elapsed = (clock_t::now() - start);
        if (success) {
            std::cout << elapsed.count()*1e6 << std::endl; // To us
            i++;
        }
    }

    return 0;
}
