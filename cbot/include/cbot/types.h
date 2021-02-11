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
};

std::ostream& operator<<(std::ostream& outs, const Pose &pose);
std::ostream& operator<<(std::ostream& outs, const Twist &twist);
std::ostream& operator<<(std::ostream& outs, const Joint &joint);

} // namespace cbot

#endif
