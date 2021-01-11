cmake_minimum_required(VERSION 3.0)
project(
    "CGA Robotics Library"
    VERSION 0.1.0
    DESCRIPTION "CGA Robotics Library"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(cga)
add_subdirectory(cbot)
