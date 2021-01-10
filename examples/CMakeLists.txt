function(add_example library name)
    add_executable(${library}_${name}
        src/${library}/${name}.cpp
    )
    target_link_libraries(${library}_${name} ${library})
endfunction()

add_example(cga gen)
add_example(cga geometry)
add_example(cga transform)
