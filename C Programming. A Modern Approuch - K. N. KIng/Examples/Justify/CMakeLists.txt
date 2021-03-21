cmake_minimum_required(VERSION 3.14)
project(Justify C)

set(CMAKE_C_STANDARD 99)

add_executable(Justify main.c word.h line.h word.c line.c)