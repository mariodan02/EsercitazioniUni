cmake_minimum_required(VERSION 3.23)
project(ese0927 C)

# set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -lm")

add_executable(ese0927 main.c backend.h)