#ifndef COMMON_DELTA_H
#define COMMON_DELTA_H

#include <memory>
#include "cbot/types.h"

namespace cbot {

class DeltaBase {
public:
    struct Config {
        // Base and end effector radius
        double r_base, r_ee;
        // Uppwer and lower length
        double l_upper, l_lower;
    };
    struct Joints {
        double theta[3];
    };
    struct JointsDep {
        double alpha[3];
        double beta[3];
        double gamma[3];
    };

    virtual bool fk_pose(
        const Joints &joints_pos,
        JointsDep *joints_dep_pos,
        Pose &pose)=0;
    virtual bool fk_twist(
        const Joints &joints_pos,
        const Joints &joints_vel,
        Twist &twist)=0;
    virtual bool ik_pose(
        const Pose &pose,
        Joints &joints_pos)=0;
    virtual bool ik_twist(
        const Twist &twist,
        const Joints &joints_pos,
        Joints &joints_vel)=0;
};

namespace cga_impl {
class Delta: public DeltaBase {
public:
    Delta(Config config);
    ~Delta();
    Delta(Delta&&);
    Delta& operator=(Delta&&);

    bool fk_pose(
        const Joints &joints_pos,
        JointsDep *joints_dep_pos,
        Pose &pose);
    bool fk_twist(
        const Joints &joints_pos,
        const Joints &joints_vel,
        Twist &twist);
    bool ik_pose(
        const Pose &pose,
        Joints &joints_pos);
    bool ik_twist(
        const Twist &twist,
        const Joints &joints_pos,
        Joints &joints_vel);

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

    bool fk_pose(
        const Joints &joints_pos,
        JointsDep *joints_dep_pos,
        Pose &pose);
    bool fk_twist(
        const Joints &joints_pos,
        const Joints &joints_vel,
        Twist &twist);
    bool ik_pose(
        const Pose &pose,
        Joints &joints_pos);
    bool ik_twist(
        const Twist &twist,
        const Joints &joints_pos,
        Joints &joints_vel);

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};
} // namespace linalg_impl

} // namespace cbot

#endif
