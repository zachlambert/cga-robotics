#include "cbot/serial.h"
#include <iostream>
#include <cmath>

int main()
{
    cbot::Serial::Dimensions dim;
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0, 0, 0));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0, 0, -M_PI/2, -M_PI/2));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.1, 0, 0));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.05, 0, 0, 0, false));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.05, 0, 0));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.03, 0, 0, 0, false));

    cbot::Serial::JointNames joint_names;
    joint_names.push_back("theta_1");
    joint_names.push_back("theta_2");
    joint_names.push_back("theta_3");
    joint_names.push_back("theta_4");
    joint_names.push_back("theta_5");
    joint_names.push_back("theta_6");

    cbot::Serial serial(dim, joint_names);

    auto joints = serial.get_independent_joint_names();

    serial.set_joint_position(joints[0], 0);
    serial.set_joint_position(joints[1], 0);
    serial.set_joint_position(joints[2], 0);

    std::cout << "Forward kinematics for pose" << std::endl;
    if (serial.update_pose()) {
        std::cout << serial.get_pose() << std::endl;
    } else {
        std::cerr << "Failed to update pose." << std::endl;
    }

    std::cout << "Inverse kinematics for pose" << std::endl;

    // Known, non-singular start position
    serial.set_joint_position(joints[0], 0.8);
    serial.set_joint_position(joints[1], 0.8);
    serial.set_joint_position(joints[2], 0.8);
    serial.set_joint_position(joints[3], 0.8);
    serial.set_joint_position(joints[4], 0.8);
    serial.set_joint_position(joints[5], 0.8);
    serial.update_pose();
    cbot::Pose pose = serial.get_pose();

    // Increment position slightly
    pose.position.x += 0.05;
    pose.position.y -= 0.05;
    double angle = 2*std::acos(pose.orientation.w);
    double new_angle = angle+0.5;
    double axis_scaling = std::sin(new_angle)/std::sin(angle);
    pose.orientation.w = std::cos(new_angle/2);
    pose.orientation.x *= axis_scaling;
    pose.orientation.y *= axis_scaling;
    pose.orientation.z *= axis_scaling;
    serial.set_pose(pose);

    if (serial.update_joint_positions()) {
        serial.update_pose();
        std::cout << serial.get_pose() << std::endl;
        for (const std::string &name: joints) {
            std::cout << name << " = " << serial.get_joint_position(name) << std::endl;
        }
    } else {
        std::cerr << "Failed to update joint positions" << std::endl;
    }

    cbot::TrajectoryConstraints constraints;
    constraints.max_linear_speed = 0.1;
    constraints.max_angular_speed = 0.5;
    serial.set_trajectory_constraints(constraints);

    cbot::Pose goal_pose = pose;
    goal_pose.position.x = 0.05;
    goal_pose.position.y = 0.05;
    goal_pose.position.z = 0.04;
    // goal_pose.orientation.w = 1;
    // goal_pose.orientation.x = 0;
    // goal_pose.orientation.y = 0;
    // goal_pose.orientation.z = 0;
    if (serial.calculate_trajectory(goal_pose)) {
        std::cout << "Trajectory calculated" << std::endl;
        auto trajectory = serial.get_trajectory();
        for (auto p: trajectory.points) {
            std::cout << "t="<<p.time<<": ";
            for (std::size_t i = 0; i < p.positions.size(); i++) {
                std::cout << p.positions[i] << ", ";
            }
            std::cout<<std::endl;
        }
        std::cout << "End pose" << std::endl << serial.get_pose() << std::endl;
    } else {
        std::cout << "Trajectory not found" << std::endl;
    }

    return 0;
}
