cmake_minimum_required(VERSION 3.5)

project(2022_09_28_HW_3)

add_executable(
    PhoneBook
    PhoneBook.h
    PhoneBook.c
    main.c
)

add_executable(
    test
    PhoneBook.h
    PhoneBook.c
    test.c
)
