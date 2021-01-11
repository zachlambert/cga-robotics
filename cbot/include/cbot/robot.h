#ifndef COMMON_ROBOT_H
#define COMMON_ROBOT_H

#include <string>
#include <unordered_map>

// Define some simple structs for return types.
// Each implementation uses its own objects for reprsenting these quantities,
// but will return the same objects for consistency.
// Chosen the same representations as those used by ros msgs

struct JointState {
    double pos;
    double vel;
    double acc;
    double torque;
};

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
    // Given the joint positions, determine the end effector pose
    virtual Pose fk_pose(const std::unordered_map<std::string, JointState> &joints)=0;
    // Given the joint positions and velocities, determine the end effector twist
    virtual Twist fk_twist(const std::unordered_map<std::string, JointState> &joints)=0;

    // INVERSE KINEMATICS:
    // Given the desired pose, set the joint positions
    virtual void ik_pose(const Pose &pose, std::unordered_map<std::string, JointState> &joints)=0;
    // Given the desired twist and current joint positions, set the joint velocities
    virtual void ik_twist(const Twist &twist, std::unordered_map<std::string, JointState> &joints)=0;

    // FORCE CONTROL
    // Given a desired end effector wrench, what are the required joint torques
    virtual void force_control(const Twist &twist, std::unordered_map<std::string, JointState> &joints)=0;

    // --- Dynamics functions below are placeholders, if there is time to look at ---

    // FORWARD DYNAMICS:
    // Given the end effector wrench, joint positions, velocities and torques,
    // what are the resultant joint accelerations.
    // virtual void fd(const Wrench &wrench, const std::unordered_map<std::string, JointState> &joints)=0;

    // INVERSE DYNAMICS:
    // Given the desired joint accelerations, and current joint positions, velocities and ee wrench,
    // what are the required joint torques.
    // virtual void id(const Wrench &wrench, std::unordered_map<std::string, JointState> &joints)=0;
};

#endif
