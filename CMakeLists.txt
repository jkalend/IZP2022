cmake_minimum_required(VERSION 3.23)
project(IZP2022 C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-O3 -Wall -pedantic)

add_executable(t9search t9search.c)
