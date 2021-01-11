find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(cbot SHARED
    src/linalg/delta.cpp
    src/cga/delta.cpp
)
target_include_directories(cbot
    PUBLIC include# PRIVATE src
)
target_link_libraries(cbot
    PRIVATE cga Eigen3::Eigen
)

# add_subdirectory(examples)

install(TARGETS cbot DESTINATION lib)
install(DIRECTORY include/cbot DESTINATION include)
install(FILES CbotConfig.cmake DESTINATION lib/cmake/Cbot)

