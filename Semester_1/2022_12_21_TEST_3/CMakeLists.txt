cmake_minimum_required(VERSION 3.5)

project(21_12_22_TEST_3)

add_executable(
    test
    checkString.h
    checkString.c
    test.c
)

add_executable(
    main
    checkString.h
    checkString.c
    main.c
)
