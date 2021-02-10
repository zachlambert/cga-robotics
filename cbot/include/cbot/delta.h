#ifndef COMMON_DELTA_H
#define COMMON_DELTA_H

#include <vector>
#include <string>
#include <memory>
#include "cbot/types.h"

namespace cbot {

class Delta {
public:
    struct Config {
        double r_base, r_ee; // Base and end effector radius
        double l_upper, l_lower; // Upper and lower length
        std::vector<std::string> theta;
        std::vector<std::string> alpha;
        std::vector<std::string> beta;
        std::vector<std::string> gamma;
    };

    Delta(Config config);
    ~Delta();
    Delta(Delta&&);
    Delta& operator=(Delta&&);

    // Functions for updating the robot state (pose, twist, joints) such
    // that they are consistent. Either with FK (setting pose and twist
    // to be consistent with joints) or with IK (setting joints to be
    // consistent with pose and twist).
    bool update_pose(); // Set pose with FK
    bool update_twist(); // Set twist with FK
    bool update_joint_positions(); // Set joint positions with IK
    bool update_joint_velocities(); // Set joint velocities with IK
    bool update_dependent_joints();

    bool calculate_trajectory(const Pose &goal, double time, JointTrajectory &trajectory);

    // Primarily just update private members.
    // However, can also invalidate calculations done (by impl), meaning
    // they are recalculated when required by an update function
    void set_pose(const Pose &pose);
    void set_twist(const Twist &twist);
    void set_joint_position(const std::string &name, double value);
    void set_joint_velocity(const std::string &name, double value);

    const Pose &get_pose()const{ return pose; }
    const Twist &get_twist()const{ return twist; }
    const Joints &get_joints()const{ return joints; }

private:
    Pose pose;
    Twist twist;
    Joints joints;

    class Impl;
    std::unique_ptr<Impl> pimpl;
};

} // namespace cbot

#endif
