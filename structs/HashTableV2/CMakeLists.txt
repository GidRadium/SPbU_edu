cmake_minimum_required(VERSION 3.5)

project(HashTable)

add_executable(
    test
    HashTable.h
    HashTable.c
    test.c
)

add_executable(
    main
    HashTable.h
    HashTable.c
    main.c
)
