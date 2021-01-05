cmake_minimum_required(VERSION 3.0)
project(
    "CGA Library"
    VERSION 0.1.0
    DESCRIPTION "CGA library"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SRC
    src/cga.cpp
)
add_library(cga STATIC ${SRC})
target_include_directories(cga
    PUBLIC include
)

add_subdirectory(examples)
