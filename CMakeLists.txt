cmake_minimum_required(VERSION 3.28)
project(sorting_paper C)

set(CMAKE_C_STANDARD 23)

add_executable(sorting_paper main.c
        print_utils.c
        print_utils.h
        benchmark_utils.c
        benchmark_utils.h
        algorithms/bubble_sort.cpp
        algorithms/bubble_sort.h)
