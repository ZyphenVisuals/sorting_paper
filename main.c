#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark_utils.h"
#include "csv_utils.h"
#include "print_utils.h"
#include "algorithms/bubble_sort.h"

int main(const int argc, char** argv) {
    // Argument handling
    if(argc == 2 && !strcmp(argv[1], "help")) {
        print_help();
        return 0;
    }
    if(argc != 6) {
        puts("[ERROR] Command usage: \"sort [min] [max] [step] [type] [passes]\". For more info use \"sort help\"");
        return 1;
    }
    const unsigned int min = atoi(argv[1]), max = atoi(argv[2]), step = atoi(argv[3]), type = atoi(argv[4]), passes = atoi(argv[5]);
    if(type < 1 || type > 5) {
        puts("[ERROR] Invalid type. See \"sort help\"");
        return 1;
    }
    srand(time(NULL));

    // set up files
    FILE* f_bubble = create_csv("BubbleSort", min, max, type);
    write_header(f_bubble);
    FILE* f_bubble_qe = create_csv("BubbleSort(QuickExit)", min, max, type);
    write_header(f_bubble_qe);

    // run tests
    for(int l=min; l<=max; l += step) {
        printf("Sorting %d elements:\n", l);

        double t = runner(BubbleSort, l, type, passes);
        write_row(f_bubble, l, t);

        t = runner(BubbleSort_QuickExit, l, type, passes);
        write_row(f_bubble_qe, l, t);

        puts("");
    }

    // close files
    fclose(f_bubble);
    fclose(f_bubble_qe);

    return 0;
}
