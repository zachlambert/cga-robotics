# CGA Robotics

This library consists of two parts:
- A cga library, that provides classes and operations for using conformal geometric algebra to represent geometry and perform transformations.
- A cbot library, which uses this cga library to implement the forward and inverse kinematics for a number of types of robot.

## cga

The cga library uses a code generator to generate code defining the cga objects and the fundamental operations between them. Other code in the library makes
use of this to perform certain operations and interpret the results.

By using a code generator, the types of objects and operations used can easily be changed depending on what is needed. This allows for more specialised and efficient
code than if using a more general purpose cga library.

## cbot

To evaluate the benefits and drawbacks of using cga for kinematics compared to conventional methods, the cbot library does operations both with standard methods
using linear algebra and with conformal geometric algebra. These are separated into the linalg and cga subdirectories. By swapping the included header file from
`cbot/linalg/delta.h` to `cbot/cga/delta.h` for example, the code is unchanged, only the implementation changes. Because both subdirectories implement objects with
the same names, only one implementation can be used at a time.

The planned types of robot are:
- Delta robot: A parallel robot with a nice geometric solution for the forward kinematics, which is nicely solved by conformal geometric algebra using intersection
operations.
- Industrial robot: A six degree of freedom manipulator, where the final three joints share a common point, allowing for a closed-form inverse kinematics solution.
- Serial robot: A generic serial robot, where forward kinematics is simple, but inverse kinematics requires numerical methods.

For each robot, the desired operations are:
- Forward kinematics: Given the set of joint positions, determine the end effector pose.
- Forward instantaneous kinematics: Given the set of joint positions and velocities, determine the end effector twist.
- Inverse kinematics: Given a desired end effector pose, determine the required joint positions.
- Inverse instantaneous kinematics: Given a desired end effector twist and current joint positions, determine the required joint velocities.
- Force control: Given a targe end effector wrench, determine the required joint torques.

Placeholder functions are also listed for forward and inverse dynamics, but the focus at the moment is on kinematics only, and will only look at dynamics
if there is time.

## ROS integration

A wrapper library is provided for using this library with ROS, given [here](https://github.com/zachlambert/cga-robotics-ros).
