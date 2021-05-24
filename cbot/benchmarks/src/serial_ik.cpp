#include "cbot/serial.h"
#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include <Eigen/Dense>

Eigen::Quaterniond make_quaternion(int x, int y, int z, double angle)
{
    Eigen::Quaterniond q;
    q.w() = std::cos(angle/2);
    q.x() = x*std::sin(angle/2);
    q.y() = y*std::sin(angle/2);
    q.z() = z*std::sin(angle/2);
    return q;
}

void set_random_position(cbot::Serial &serial)
{
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(0, 1);
    static auto sample = std::bind(distribution, generator);

    cbot::Pose pose;
    pose.position.x = 0.3*sample();
    pose.position.y = -0.1 + 0.2*sample();
    pose.position.z = 0.1 + 0.2*sample();

    auto qz = make_quaternion(0,0,1, -M_PI/3 + (2*M_PI/3)*sample());
    auto qy = make_quaternion(0,1,0, -M_PI/3 + (2*M_PI/3)*sample());
    auto qx= make_quaternion(1,0,0, -M_PI/2 + M_PI*sample());
    auto q = qz*qy*qx;
    pose.orientation.w = q.w();
    pose.orientation.x = q.x();
    pose.orientation.y = q.y();
    pose.orientation.z = q.z();

    serial.set_pose(pose);
}

int main()
{
    cbot::Serial::Dimensions dim;
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0, 0, 0));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0, 0, -M_PI/2, -M_PI/2));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.2, 0, 0));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.1, 0, 0, 0, false));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.02, 0, 0));
    dim.dh_parameters.push_back(
        cbot::Serial::DHParameter(0.01, 0, 0, 0, false));

    cbot::Serial::JointNames joint_names;
    joint_names.push_back("theta_1");
    joint_names.push_back("theta_2");
    joint_names.push_back("theta_3");
    joint_names.push_back("theta_4");
    joint_names.push_back("theta_5");
    joint_names.push_back("theta_6");

    cbot::Serial serial(dim, joint_names);

    typedef std::chrono::high_resolution_clock clock_t;
    typedef std::chrono::duration<double, std::ratio<1>> second_t;
    second_t elapsed;
    std::chrono::time_point<clock_t> start;

    constexpr std::size_t N = 1e3;
    std::size_t i = 0;
    while (i < N) {
        set_random_position(serial);
        start = clock_t::now();
        bool success = serial.update_joint_positions();
        elapsed = (clock_t::now() - start);
        if (success) {
            std::cout << elapsed.count()*1e6 << std::endl; // To us
            i++;
        }
    }

    return 0;
}
