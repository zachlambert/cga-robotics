function(add_cga_test name)
    add_executable(test_${name}
        src/${name}.cpp
    )
    target_link_libraries(test_${name} cga gtest gtest_main)
    add_test(${name} test_${name})
endfunction()

add_cga_test(gen)
add_cga_test(geometry)
add_cga_test(transform)
