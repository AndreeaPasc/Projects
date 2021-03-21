cmake_minimum_required(VERSION 3.14)
project(P2 C)

set(CMAKE_C_STANDARD 99)

add_executable(P2 main.c line.h word.h line.c word.c)