//
// Created by iulian on 5/8/24.
//

#include "print_utils.h"

#include <stdio.h>

void print_help() {
    puts("Command usage:");
    puts("sort [min] [max] [step] [type] [passes] [ignoreslow]\n");
    puts("The lists sorted will start at [min] elements and increase by [step], reaching but not exceeding [max].\n");
    puts("The value of [type] should be one of the following:\n 1: Random\n 2: Ascending\n 3: Descending\n 4: Almost ascending (10% random)\n 5: Small random (<1000)");
    puts("The value of [passes] should be a positive integer, representing the number of times each list is sorted before computing the average.");
    puts("The value of [ignoreslow] should be 0 or 1, representing whether to ignore slow algorithms (BubbleSort, SelectionSort, InsertionSort) in the output.");
}
