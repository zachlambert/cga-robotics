
# Need this for some reason
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC" )

add_library(cga STATIC
    src/cga.cpp
)
target_include_directories(cga
    PUBLIC include
)

set(INSTALL_GTEST OFF)
add_subdirectory(lib/googletest)
add_subdirectory(test)
