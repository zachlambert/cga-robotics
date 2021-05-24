#include "cbot/serial.h"
#include <iostream>
#include <chrono>
#include <random>
#include <functional>

void set_random_joint_positions(cbot::Serial &serial)
{
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(0, 1);
    static auto sample = std::bind(distribution, generator);

    auto joint_names = serial.get_independent_joint_names();
    for (std::size_t i = 0; i < joint_names.size(); i++) {
        double pos = -M_PI/2 + M_PI*sample();
        serial.set_joint_position(joint_names[i], pos);
    }
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

    constexpr std::size_t N = 1e5;
    std::size_t i = 0;
    while (i < N) {
        set_random_joint_positions(serial);
        start = clock_t::now();
        bool success = serial.update_pose();
        elapsed = (clock_t::now() - start);
        if (success) {
            std::cout << elapsed.count()*1e6 << std::endl; // To us
            i++;
        }
    }

    return 0;
}
