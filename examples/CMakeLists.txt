function(add_example name)
    add_executable(${name}
        src/${name}.cpp
    )
    target_link_libraries(${name} cga)
endfunction()

add_example(conformal)
add_example(chain)
