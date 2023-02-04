cmake_minimum_required(VERSION 3.23)
project(c_language)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(c_language
        arraylist.c
        arraylist.h
        main.c
        )
