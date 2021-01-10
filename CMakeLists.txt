cmake_minimum_required(VERSION 3.0)
project(
    "CGA Robotics Library"
    VERSION 0.1.0
    DESCRIPTION "CGA Robotics Library"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# 1. Build the cga library

add_library(cga STATIC
    src/cga/cga.cpp
)
target_include_directories(cga
    PUBLIC include/cga
)

# 2. Build the cbot library

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(cbot STATIC
    src/cbot/linalg/delta.cpp
    src/cbot/cga/delta.cpp
)
target_include_directories(cbot
    PUBLIC include/cbot
)
target_link_libraries(cbot
    PRIVATE cga Eigen3::Eigen
)

# 3. Build the examples

add_subdirectory(examples)
