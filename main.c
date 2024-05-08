#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark_utils.h"
#include "print_utils.h"

int main(const int argc, char** argv) {
    // Argument handling
    if(argc == 2 && !strcmp(argv[1], "help")) {
        print_help();
        return 0;
    }
    if(argc != 5) {
        puts("[ERROR] Command usage: \"sort [min] [max] [step] [type]\". For more info use \"sort help\"");
        return 1;
    }
    const unsigned int min = atoi(argv[1]), max = atoi(argv[2]), step = atoi(argv[3]), type = atoi(argv[4]);
    srand(time(NULL));

    for(int l=min; l<=max; l += step) {

    }
    return 0;
}
