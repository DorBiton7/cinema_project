cmake_minimum_required(VERSION 3.23)
project(cinema C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cinema
        cinema.c
        cinema.h
        main.c)
