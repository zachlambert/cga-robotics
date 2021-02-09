#include "cbot/delta.h"
#include <iostream>

namespace cbot { using namespace linalg_impl; }
// namespace cbot { using namespace cga_impl; }

int main()
{
    cbot::Delta::Config config;
    config.r_base = 0.15;
    config.r_ee = 0.05;
    config.l_upper = 0.3;
    config.l_lower = 0.4;

    cbot::Delta delta(config);

    cbot::Delta::Joints joints_pos;
    joints_pos.theta[0] = 0;
    joints_pos.theta[1] = 0;
    joints_pos.theta[2] = 0;

    cbot::Delta::Joints joints_vel;
    joints_vel.theta[0] = 0.2;
    joints_vel.theta[1] = 0.2;
    joints_vel.theta[2] = 0.2;

    cbot::Twist twist;
    delta.fk_twist(joints_pos, joints_vel, twist);

    std::cout << "Linear = (";
    std::cout<<twist.linear.x<<", ";
    std::cout<<twist.linear.y<<", ";
    std::cout<<twist.linear.z<<")" << std::endl;
    std::cout << "Angular = (";
    std::cout<<twist.angular.x<<", ";
    std::cout<<twist.angular.y<<", ";
    std::cout<<twist.angular.z<<")" << std::endl;

    return 0;
}
