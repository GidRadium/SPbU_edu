cmake_minimum_required(VERSION 3.5)

project(KR_2_task_1)

add_executable(
    test
    Deque.h
    Deque.c
    polyChecker.h
    polyChecker.c
    test.c
)

add_executable(
    main
    Deque.h
    Deque.c
    polyChecker.h
    polyChecker.c
    main.c
)
