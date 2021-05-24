#ifndef CBOT_DELTA_H
#define CBOT_DELTA_H

#include <vector>
#include <string>
#include <memory>
#include "cbot/cbot.h"

namespace cbot {

class Delta: public Robot {
public:
    struct Dimensions {
        double r_base, r_ee; // Base and end effector radius
        double l_upper, l_lower; // Upper and lower length
        double gripper_offset;
    };
    struct JointNames {
        std::vector<std::string> theta;
        std::vector<std::string> alpha;
        std::vector<std::string> beta;
        std::vector<std::string> gamma;
        std::string theta_4; // For orientation of gripper
    };

    Delta(const Dimensions &dim, const JointNames &joint_names);
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

    // Primarily just update private members.
    // However, can also invalidate calculations done (by impl), meaning
    // they are recalculated when required by an update function
    void set_pose(const Pose &pose);
    void set_twist(const Twist &twist);
    void set_joint_position(const std::string &name, double value);
    void set_joint_velocity(const std::string &name, double value);

    const Pose &get_pose()const;
    const Twist &get_twist()const;
    const double &get_joint_position(const std::string &name)const;
    const double &get_joint_velocity(const std::string &name)const;

    bool is_valid(constraint_t constraint=nullptr);

    void set_trajectory_constraints(const TrajectoryConstraints &constraints);
    bool calculate_trajectory(const Pose &goal);
    const JointTrajectory &get_trajectory()const;

    const std::vector<std::string> get_independent_joint_names()const;
    const std::vector<std::string> get_dependent_joint_names()const;
    bool is_parallel()const{ return true; }

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl; // Pointer to implementation
};

} // namespace cbot

#endif
