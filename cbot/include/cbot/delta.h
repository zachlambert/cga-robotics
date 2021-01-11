#ifndef COMMON_DELTA_H
#define COMMON_DELTA_H

#include <memory>
#include "cbot/robot.h"

class DeltaBase: public Robot {
public:
    struct Structure {
        double base_radius, ee_radius;
        double upper_length, lower_length;
        std::string theta_names[3];
        std::string alpha_names[3];
        std::string beta_names[3];
        std::string gamma_names[3];
    };
    DeltaBase(Structure structure): structure(structure) {}

protected:
    Structure structure;
};

namespace cga_impl {
class Delta: public DeltaBase {
public:
    Delta(Structure structure);
    ~Delta();
    Delta(Delta&&);
    Delta& operator=(Delta&&);

    Pose fk_pose(const std::unordered_map<std::string, JointState> &joints);
    Twist fk_twist(const std::unordered_map<std::string, JointState> &joints);
    void ik_pose(const Pose &pose, std::unordered_map<std::string, JointState> &joints);
    void ik_twist(const Twist &twist, std::unordered_map<std::string, JointState> &joints);
    void force_control(const Twist &twist, std::unordered_map<std::string, JointState> &joints);
private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};

} // namespace cga_impl

namespace linalg_impl {
class Delta: public DeltaBase {
public:
    Delta(Structure structure);
    ~Delta();
    Delta(Delta&&);
    Delta& operator=(Delta&&);

    Pose fk_pose(const std::unordered_map<std::string, JointState> &joints);
    Twist fk_twist(const std::unordered_map<std::string, JointState> &joints);
    void ik_pose(const Pose &pose, std::unordered_map<std::string, JointState> &joints);
    void ik_twist(const Twist &twist, std::unordered_map<std::string, JointState> &joints);
    void force_control(const Twist &twist, std::unordered_map<std::string, JointState> &joints);
private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};
} // namespace linalg_impl

#endif
