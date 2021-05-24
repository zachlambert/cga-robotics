find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_compile_options(-std=c++11)

# set(USE_CGA FALSE)

set(SOURCES src/cbot.cpp)
if(USE_CGA)
    list(APPEND SOURCES src/cga_impl/delta.cpp)
    list(APPEND SOURCES src/cga_impl/serial.cpp)
    message(STATUS "Building with CGA")
else()
    list(APPEND SOURCES src/linalg_impl/delta.cpp)
    list(APPEND SOURCES src/linalg_impl/serial.cpp)
    message(STATUS "Building with LINALG")
endif()

add_library(cbot SHARED ${SOURCES})
target_include_directories(cbot
    PUBLIC include# PRIVATE src
)
target_link_libraries(cbot
    PRIVATE cga Eigen3::Eigen
)

add_subdirectory(benchmarks)

install(TARGETS cbot EXPORT cbot-export DESTINATION lib)
install(DIRECTORY include/cbot DESTINATION include/cbot)
install(FILES cbotConfig.cmake DESTINATION lib/cmake/cbot)
