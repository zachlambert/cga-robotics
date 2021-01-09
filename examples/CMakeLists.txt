function(add_example name)
    add_executable(${name}
        src/${name}.cpp
    )
    target_link_libraries(${name} cga)
endfunction()

add_example(structs)
add_example(geometry)
# add_example(chain)
