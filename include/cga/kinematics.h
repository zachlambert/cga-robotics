#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <string>
#include <unordered_map>
#include <vector>

#include "gen/cga.h"
#include "cga/geometry.h"
#include "cga/transform.h"

namespace cga {

struct Inertia {
    double ixx, iyy, izz, ixy, ixz, iyz;
    Vector3 origin;
    Bivector3 orientation;
};

struct Link {
    std::string name;
    // Inertia inertia; - Omit for now
};

// For now, only use revolute joints
struct Joint {
    std::string parent;
    std::string child;
    Rotor translation; // Transformation to next frame origin
    Rotor rotation;
    Bivector3 axis; // Axis of rotation for joint
};

class Chain {
public:
    void set_root(const Link &link) { root = link; }
    void add_segment(const Joint &joint, const Link &link)
    {
        segments.push_back({joint, link});
    }
private:
    Link root;
    struct Segment {
        Joint joint;
        Link link;
    };
    std::vector<Segment> segments;
};

class Tree {
public:
    void add_link(const std::string &name, const Link &link)
    {
        links.insert(std::make_pair(name, link));
    }
    void add_joint(const std::string &name, const Joint &joint)
    {
        joints.insert(std::make_pair(name, joint));
    }
    Chain get_chain(std::string start, std::string end)
    {
        Chain chain;
        // TODO
        return chain;
    }
private:
    std::unordered_map<std::string, Link> links;
    std::unordered_map<std::string, Joint> joints;
};

} // namespace cga

#endif
