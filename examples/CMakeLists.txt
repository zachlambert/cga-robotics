function(add_example subdir name)
    add_executable(${subdir}_${name}
        src/${subdir}/${name}.cpp
    )
    target_link_libraries(${subdir}_${name} cga)
endfunction()

add_example(cga gen)
add_example(cga geometry)
add_example(cga transform)
# add_example(kinematics)
