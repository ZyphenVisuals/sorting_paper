cmake_minimum_required(VERSION 3.28)
project(sorting_paper C)

set(CMAKE_C_STANDARD 23)

add_executable(sorting_paper main.c
        print_utils.c
        print_utils.h
        benchmark_utils.c
        benchmark_utils.h
        algorithms/bubble_sort.c
        algorithms/bubble_sort.h
        csv_utils.c
        csv_utils.h
        algorithms/selection_sort.c
        algorithms/selection_sort.h
        algorithms/insertion_sort.c
        algorithms/insertion_sort.h
        algorithms/merge_sort.c
        algorithms/merge_sort.h
        algorithms/quick_sort.c
        algorithms/quick_sort.h)
