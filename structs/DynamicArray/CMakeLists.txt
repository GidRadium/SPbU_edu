cmake_minimum_required(VERSION 3.5)

project(DynamicArray)

add_executable(
    test
    DynamicArrayPredefines.h
    DynamicArray.h
    DynamicArray.c
    test.c
)
