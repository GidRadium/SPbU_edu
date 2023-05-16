cmake_minimum_required(VERSION 3.5)

project(GameOfLife)

add_executable(
    test
    GameOfLife.h
    GameOfLife.c
    test.c
)

add_executable(
    main
    GameOfLife.h
    GameOfLife.c
    main.c
)
