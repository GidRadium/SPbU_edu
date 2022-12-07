cmake_minimum_required(VERSION 3.5)

project(Set)

add_executable(
    test
    DynamicArray.h
    DynamicArray.c
    "Set.h"
    "Set.c"
    test.c
)
