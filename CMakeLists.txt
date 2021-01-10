cmake_minimum_required(VERSION 3.0)
project(
    "CGA Robotics Library"
    VERSION 0.1.0
    DESCRIPTION "CGA Robotics Library"
    LANGUAGES CXX
)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SRC
    src/gen/cga.cpp
    src/cga/delta.cpp
    src/linalg/delta.cpp
)
add_library(cga_robotics STATIC ${SRC})
target_include_directories(cga_robotics
    PUBLIC include
)
target_link_libraries(cga_robotics
    PRIVATE Eigen3::Eigen
)

add_subdirectory(examples)
