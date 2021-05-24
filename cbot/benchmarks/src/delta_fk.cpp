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

    auto independent_joints = delta.get_independent_joint_names();

    delta.set_joint_position("theta_1", 0.5);
    delta.set_joint_position("theta_2", 0.7);
    delta.set_joint_position("theta_3", -0.1);

    std::cout << "Forward kinematics for pose" << std::endl;
    if (delta.update_pose()) {
        std::cout << delta.get_pose() << std::endl;
    } else {
        std::cerr << "Failed to update pose." << std::endl;
    }

    std::cout << "Inverse kinematics for joint positions" << std::endl;
    cbot::Pose pose;
    pose.position.x = -0.022;
    pose.position.y = -0.087;
    pose.position.z = -0.2195;
    delta.set_pose(pose);
    if (delta.update_joint_positions()) {
        for (const std::string &name: independent_joints) {
            std::cout << name << " = " << delta.get_joint_position(name) << std::endl;
        }
    } else {
        std::cerr << "Failed to update joint positions." << std::endl;
    }

    std::cout << "Inverse kinematics for joint trajectory" << std::endl;
    cbot::Pose goal;
    goal.position.x = 0.2;
    goal.position.y = 0.1;
    goal.position.z = -0.3;
    cbot::TrajectoryConstraints constraints;
    constraints.max_joint_speed = 2;
    delta.set_trajectory_constraints(constraints);
    delta.calculate_trajectory(goal);

    auto trajectory = delta.get_trajectory();
    for (std::size_t i = 0; i < trajectory.points.size(); i++) {
        std::cout << trajectory.points[i].time << ": (";
        for (std::size_t j = 0; j < trajectory.names.size(); j++) {
            std::cout << trajectory.points[i].positions[j];
            if (j != trajectory.names.size() - 1) std::cout << ", ";
        }
        std::cout << ")" << std::endl;
    }

    return 0;
}