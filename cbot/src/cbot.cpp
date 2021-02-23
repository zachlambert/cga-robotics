#include "cbot/cbot.h"

namespace cbot {

std::ostream& operator<<(std::ostream& outs, const Pose &pose)
{
    outs << "Pos: ";
    outs << pose.position.x << ", ";
    outs << pose.position.y << ", ";
    outs << pose.position.z << std::endl;
    outs << "Orient.: ";
    outs << pose.orientation.w << ", ";
    outs << pose.orientation.x << ", ";
    outs << pose.orientation.y << ", ";
    outs << pose.orientation.z;
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Twist &twist)
{
    outs << "Linear: ";
    outs << twist.linear.x << ", ";
    outs << twist.linear.y << ", ";
    outs << twist.linear.z << std::endl;
    outs << "Angular: ";
    outs << twist.angular.x << ", ";
    outs << twist.angular.y << ", ";
    outs << twist.angular.z;
    return outs;
}

std::ostream& operator<<(std::ostream& outs, const Joint &joint)
{
    outs << "Pos: " << joint.position << ", ";
    outs << "Vel: " << joint.velocity;
    if (joint.dependent) {
        outs << " [dep.]";
    }
    return outs;
}

} // namespace cbot
