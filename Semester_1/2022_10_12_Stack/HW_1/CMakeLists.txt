cmake_minimum_required(VERSION 3.5)

project(2022_10_12_HW_1)

add_executable(
    2022_10_12_HW_1
    ../../../structs/Stack/Stack.c
    ../../../structs/Stack/Stack.h
    calculate.h
    calculate.c
    main.c
)

add_executable(
    2022_10_12_HW_1_test
    ../../../structs/Stack/Stack.c
    ../../../structs/Stack/Stack.h
    calculate.h
    calculate.c
    test.c
)
