find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_compile_options(-std=c++11)

add_library(cbot SHARED
    src/linalg_impl/delta.cpp
    src/cga_impl/delta.cpp
)
target_include_directories(cbot
    PUBLIC include# PRIVATE src
)
target_link_libraries(cbot
    PRIVATE cga Eigen3::Eigen
)

add_subdirectory(examples)

install(TARGETS cbot EXPORT cbot-export DESTINATION lib)
install(DIRECTORY include/cbot DESTINATION include/cbot)
install(FILES cbotConfig.cmake DESTINATION lib/cmake/cbot)
