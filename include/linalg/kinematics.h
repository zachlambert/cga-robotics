#ifndef CGA_KINEMATICS
#define CGA_KINEMATICS

#include <string>

namespace linalg {

class Joint {

};

class Tree {
    void add_link(const std::string &name);
    void add_joint(const std::string &name, const Joint &joint);
};

}; // namespace cga_robotics

#endif
