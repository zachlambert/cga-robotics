#ifndef COMMON_DELTA_H
#define COMMON_DELTA_H

#include <memory>
#include "cbot/robot.h"

namespace cbot {

class DeltaBase: public Robot {
public:
    struct Config {
        struct {
            double base_radius, ee_radius;
            double upper_length, lower_length;
        } dim;
        struct {
            std::string theta_names[3];
            std::string alpha_names[3];
            std::string beta_names[3];
            std::string gamma_names[3];
        } joints;
    };
    DeltaBase(Config config): config(config) {}

protected:
    Config config;
};

namespace cga_impl {
class Delta: public DeltaBase {
public:
    Delta(Config config);
    ~Delta();
    Delta(Delta&&);
    Delta& operator=(Delta&&);

    virtual bool fk_pose(
        std::vector<std::string> &joint_names,
        std::vector<double> &joint_positions,
        Pose &pose);
    virtual bool fk_twist(
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        const std::vector<double> &joint_velocities,
        Twist &twist);
    virtual bool ik_pose(
        const Pose &pose,
        const std::vector<std::string> &joint_names,
        std::vector<double> &joints_positions);
    virtual bool ik_twist(
        const Twist &twist,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joints_positions,
        std::vector<double> &joints_velocities);
    virtual bool force_control(
        const Twist &twist,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        std::vector<double> &joint_torques);

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};

} // namespace cga_impl

namespace linalg_impl {
class Delta: public DeltaBase {
public:
    Delta(Config config);
    ~Delta();
    Delta(Delta&&);
    Delta& operator=(Delta&&);

    virtual bool fk_pose(
        std::vector<std::string> &joint_names,
        std::vector<double> &joint_positions,
        Pose &pose);
    virtual bool fk_twist(
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        const std::vector<double> &joint_velocities,
        Twist &twist);
    virtual bool ik_pose(
        const Pose &pose,
        const std::vector<std::string> &joint_names,
        std::vector<double> &joints_positions);
    virtual bool ik_twist(
        const Twist &twist,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joints_positions,
        std::vector<double> &joints_velocities);
    virtual bool force_control(
        const Twist &twist,
        const std::vector<std::string> &joint_names,
        const std::vector<double> &joint_positions,
        std::vector<double> &joint_torques);

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};
} // namespace linalg_impl

} // namespace cbot

#endif
