#include "cbot/delta.h"
#include <chrono>
#include <iostream>
#include <functional>
#include <random>

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

    // Uses a default seed, so all tests will be
    // given the same data
    std::default_random_engine gen(0);
    std::uniform_real_distribution<double> dist(0, 1);
    auto sample = std::bind(dist, gen);

    typedef std::chrono::high_resolution_clock clock_t;
    typedef std::chrono::duration<double, std::ratio<1>> second_t;
    std::chrono::time_point<clock_t> t_start;

    constexpr std::size_t N = 1000000;

    cbot::Pose pose;
    cbot::Delta::Joints joints_pos;
    cbot::Delta::JointsDep joints_dep_pos;

    double fk_time = 0;
    double ik_time = 0;
    for (std::size_t i = 0; i < N; i++) {
        joints_pos.theta[0] = -1 + 2*sample();
        joints_pos.theta[1] = -1 + 2*sample();
        joints_pos.theta[2] = -1 + 2*sample();

        t_start = clock_t::now();
        delta.fk_pose(joints_pos, joints_dep_pos, pose);
        fk_time += std::chrono::duration_cast<second_t>(clock_t::now() - t_start).count();

        pose.position.x = -0.2 + 0.4*sample();
        pose.position.y = -0.2 + 0.4*sample();
        pose.position.z = -0.2 + 0.3*sample();

        t_start = clock_t::now();
        delta.ik_pose(pose, joints_pos);
        ik_time += std::chrono::duration_cast<second_t>(clock_t::now() - t_start).count();
    }
    std::cout << "Mean FK time = " << (fk_time / N) * 1e6 << " us" << std::endl;
    std::cout << "Mean IK time = " << (ik_time / N) * 1e6 << " us" << std::endl;

    return 0;
}
