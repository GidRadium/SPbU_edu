cmake_minimum_required(VERSION 3.5)

project(2022_10_12_HW_2)

add_executable(
    2022_10_12_HW_2
    ../../../structs/Stack/Stack.c
    ../../../structs/Stack/Stack.h
    bracketSequence.h
    bracketSequence.c
    main.c
)

add_executable(
    2022_10_12_HW_2_test
    ../../../structs/Stack/Stack.c
    ../../../structs/Stack/Stack.h
    bracketSequence.h
    bracketSequence.c
    test.c
)
