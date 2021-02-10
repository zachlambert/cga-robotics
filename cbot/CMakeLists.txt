find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_compile_options(-std=c++11)

set(USE_CGA FALSE)

set(SOURCES )
if(USE_CGA)
    list(APPEND SOURCES src/cga_impl/delta.cpp)
else()
    list(APPEND SOURCES src/linalg_impl/delta.cpp)
endif()

add_library(cbot SHARED ${SOURCES})
target_include_directories(cbot
    PUBLIC include# PRIVATE src
)
target_link_libraries(cbot
    PRIVATE cga Eigen3::Eigen
)

# add_subdirectory(examples)

install(TARGETS cbot EXPORT cbot-export DESTINATION lib)
install(DIRECTORY include/cbot DESTINATION include/cbot)
install(FILES cbotConfig.cmake DESTINATION lib/cmake/cbot)
