#ifndef COMMON_ROBOT_H
#define COMMON_ROBOT_H

#include <string>
#include <vector>
#include <unordered_map>

// Define some simple structs for return types.
// Each implementation uses its own objects for reprsenting these quantities,
// but will return the same objects for consistency.
// Chosen the same representations as those used by ros msgs

namespace cbot {

struct Pose {
    struct {
        double x, y, z;
    } position;
    struct {
        double x, y, z, w;
    } orientation;
};

struct Twist {
    struct {
        double x, y, z;
    } linear;
    struct {
        double x, y, z;
    } angular;
};

struct Wrench {
    struct {
        double x, y, z;
    } force;
    struct {
        double x, y, z;
    } torque;
};

struct Inertia {
    double mass;
    struct {
        double ixx, iyy, izz;
        double ixy, ixz, iyz;
    } inertial;
    Pose pose;
};

// Virtual base class Robot defines the interface we require for different
// types of robot.

class Robot {
public:
    // FORWARD KINEMATICS:
    virtual bool fk_pose(
        const std::vector<std::string> &joint_names,
        std::vector<double> &joint_positions, // Allow setting dependent joints
        Pose &pose)=0;
    virtual bool fk_twist(
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        const std::vector<double> &joint_velocities,
        Twist &twist)=0;

    // INVERSE KINEMATICS:
    virtual bool ik_pose(
        const Pose &pose,
        const std::vector<std::string> &joint_names,
        std::vector<double> &joints_positions)=0;
    virtual bool ik_twist(
        const Twist &twist,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joints_positions,
        std::vector<double> &joints_velocities)=0;

    // FORCE CONTROL
    virtual bool force_control(
        const Twist &twist,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        std::vector<double> &joint_torques)=0;

    // --- Dynamics functions below are placeholders, if there is time to look at ---

    // FORWARD DYNAMICS:
    // Given the end effector wrench, joint positions, velocities and torques,
    // what are the resultant joint accelerations.
    virtual bool fd(
        const Wrench &wrench,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        const std::vector<double> &joint_velocities,
        std::vector<std::string> &joint_accelerations) { return false; }

    // INVERSE DYNAMICS:
    // Given the desired joint accelerations, and current joint positions, velocities and ee wrench,
    // what are the required joint torques.
    virtual bool id(
        const Wrench &wrench,
        const std::vector<std::string> &joint_positions,
        const std::vector<std::string> &joint_velocities,
        const std::vector<std::string> &joint_accelerations,
        std::vector<std::string> &joint_torques) { return false; }
};

} // namespace cbot

#endif
