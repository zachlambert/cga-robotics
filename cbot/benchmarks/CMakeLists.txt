function(add_benchmark name)
    add_executable(${name}
        src/${name}.cpp
    )
    # Temporarily put cga and Eigen3::Eigen here to test
    target_link_libraries(${name} cbot cga Eigen3::Eigen)
endfunction()

add_benchmark(delta_fk)
add_benchmark(delta_ik)
# add_example(serial)
