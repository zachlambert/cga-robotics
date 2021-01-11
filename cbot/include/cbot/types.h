#ifndef CBOT_TYPES_H
#define CBOT_TYPES_H

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

} // namespace cbot

#endif
