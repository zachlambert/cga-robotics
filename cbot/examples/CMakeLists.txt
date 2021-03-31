function(add_example name)
    add_executable(${name}
        src/${name}.cpp
    )
    # Temporarily put cga and Eigen3::Eigen here to test
    target_link_libraries(${name} cbot cga Eigen3::Eigen)
endfunction()

add_example(delta)
# add_example(delta_benchmark)

add_example(serial)

add_example(interpolate)
