#include <iostream>
#include "kinematics.h"

int main()
{
    cga::Link root;
    root.name = "root";

    cga::Link ee;
    ee.name = "ee";

    cga::Joint joint;
    joint.translation = cga::make_translation(1, 0, 0);
    joint.rotation = cga::make_rotation(0, cga::make_axis(0, 0, 0));

    cga::Chain chain;
    chain.set_root(root);
    chain.add_segment(joint, ee);
}
