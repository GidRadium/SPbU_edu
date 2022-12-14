cmake_minimum_required(VERSION 3.5)

project(task_1)

add_executable(
    test
    getIntStr.h
    getIntStr.c
    test.c
)

add_executable(
    main
    getIntStr.h
    getIntStr.c
    main.c
)
