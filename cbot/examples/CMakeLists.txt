function(add_example name)
    add_executable(${name}
        src/${name}.cpp
    )
    target_link_libraries(${name} cbot)
endfunction()

add_example(delta)
# add_example(delta_benchmark)

add_example(serial)
