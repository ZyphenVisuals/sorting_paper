//
// Created by iulian on 5/8/24.
//

#include "print_utils.h"

#include <stdio.h>

void print_help() {
    puts("Command usage:");
    puts("sort [min] [max] [step] [type]\n");
    puts("The lists sorted will start at [min] elements and increase by [step], reaching but not exceeding [max].\n");
    puts("The value of [type] should be one of the following:\n 1: Random\n 2: Ascending\n 3: Descending\n 4: Almost ascending (10% random)\n 5: Small random (<1000)");
}
