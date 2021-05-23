#ifndef CBOT_TYPES_H
#define CBOT_TYPES_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace cbot {

// Allow different robots to use their own objects for
// representing joint states.

struct Pose {
    struct {
        double x, y, z;
    } position;
    struct {
        double x, y, z, w;
    } orientation;
    Pose(): position{0, 0, 0}, orientation{0, 0, 0, 1} {}
};

struct Twist {
    struct {
        double x, y, z;
    } linear;
    struct {
        double x, y, z;
    } angular;
    Twist(): linear{0, 0, 0}, angular{0, 0, 0} {}
};

struct Wrench {
    struct {
        double x, y, z;
    } force;
    struct {
        double x, y, z;
    } torque;
    Wrench(): force{0, 0, 0}, torque{0, 0, 0} {}
};

struct Inertia {
    double mass;
    struct {
        double ixx, iyy, izz;
        double ixy, ixz, iyz;
    } inertial;
    Pose pose;
    Inertia(): mass{0}, inertial{0, 0, 0, 0, 0, 0}, pose() {}
};

struct Joint {
    double position;
    double velocity;
    bool dependent;
    Joint(bool dependent=false): dependent(dependent) {}
};
typedef std::map<std::string, Joint> Joints;

struct JointTrajectoryPoint {
    std::vector<double> positions;
    double time;
};

struct JointTrajectory {
    std::vector<std::string> names;
    std::vector<JointTrajectoryPoint> points;
};

struct TrajectoryConstraints {
    double max_linear_speed;
    double max_angular_speed;
    double max_joint_speed;
    TrajectoryConstraints(): max_linear_speed(0.5), max_angular_speed(3), max_joint_speed(3) {}
};

std::ostream& operator<<(std::ostream& outs, const Pose &pose);
std::ostream& operator<<(std::ostream& outs, const Twist &twist);
std::ostream& operator<<(std::ostream& outs, const Joint &joint);


class Robot {
public:
    virtual ~Robot() {};

    // Functions for updating the robot state (pose, twist, joints) such
    // that they are consistent. Either with FK (setting pose and twist
    // to be consistent with joints) or with IK (setting joints to be
    // consistent with pose and twist).
    virtual bool update_pose()=0; // Set pose with FK
    virtual bool update_twist()=0; // Set twist with FK
    virtual bool update_joint_positions()=0; // Set joint positions with IK
    virtual bool update_joint_velocities()=0; // Set joint velocities with IK
    virtual bool update_dependent_joints()=0;

    // Primarily just update private members.
    // However, can also invalidate calculations done (by impl), meaning
    // they are recalculated when required by an update function
    virtual void set_pose(const Pose &pose)=0;
    virtual void set_twist(const Twist &twist)=0;
    virtual void set_joint_position(const std::string &name, double value)=0;
    virtual void set_joint_velocity(const std::string &name, double value)=0;

    virtual const Pose &get_pose()const=0;
    virtual const Twist &get_twist()const=0;
    virtual const double &get_joint_position(const std::string &name)const=0;
    virtual const double &get_joint_velocity(const std::string &name)const=0;

    // Check if the current state is valid
    typedef bool (*constraint_t)(const Joints &joints);
    virtual bool is_valid(constraint_t constraint=nullptr)=0;

    virtual void set_trajectory_constraints(const TrajectoryConstraints &constraints)=0;
    virtual bool calculate_trajectory(const Pose &goal)=0;
    virtual const JointTrajectory &get_trajectory()const=0;

    virtual const std::vector<std::string> get_independent_joint_names()const=0;
    virtual const std::vector<std::string> get_dependent_joint_names()const=0;
    virtual bool is_parallel()const=0;
};

} // namespace cbot

#endif
