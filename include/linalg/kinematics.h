#ifndef LINALG_KINEMATICS
#define LINALG_KINEMATICS

#include <Eigen/Dense>

namespace linalg {

struct Pose {
    Eigen::Vector3d position;
    Eigen::Quaterniond orientation;
    Eigen::Matrix4d transform;
};

}; // namespace cga_robotics

#endif
