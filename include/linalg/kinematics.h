#ifndef LINALG_KINEMATICS
#define LINALG_KINEMATICS

#include <Eigen/Dense>

struct Pose {
    Eigen::Vector3d position;
    Eigen::Quaterniond orientation;
    Eigen::Matrix4d transform;
};

#endif
