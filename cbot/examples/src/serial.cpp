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

    // Test trivial IK solution (ie: starts at correct solution)

    serial.set_joint_position(joints[0], 0);
    serial.set_joint_position(joints[1], 0);
    serial.set_joint_position(joints[2], 0);
    serial.set_joint_position(joints[0], 0);
    serial.set_joint_position(joints[1], 0);
    serial.set_joint_position(joints[2], 0);

    serial.update_pose();
    cbot::Pose pose = serial.get_pose();
    serial.set_pose(pose);
    std::cout << "Inverse kinematics for pose" << std::endl;
    if (serial.update_joint_positions()) {
        for (const std::string &name: joints) {
            std::cout << name << " = " << serial.get_joint_position(name) << std::endl;
        }
    } else {
        std::cerr << "Failed to update joint positions" << std::endl;
    }

    pose.position.x = 0.1;
    pose.position.z = 0.05;
    serial.set_pose(pose);
    std::cout << "Inverse kinematics for pose (again)" << std::endl;
    if (serial.update_joint_positions()) {
        for (const std::string &name: joints) {
            std::cout << name << " = " << serial.get_joint_position(name) << std::endl;
        }
    } else {
        std::cerr << "Failed to update joint positions" << std::endl;
    }

    return 0;
}
