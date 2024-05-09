#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark_utils.h"
#include "csv_utils.h"
#include "print_utils.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/insertion_sort.h"
#include "algorithms/merge_sort.h"
#include "algorithms/selection_sort.h"

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
    FILE* f_selection = create_csv("SelectionSort",min,max,type);
    write_header(f_selection);
    FILE* f_insert = create_csv("InsertionSort", min, max, type);
    write_header(f_insert);
    FILE* f_merge = create_csv("MergeSort", min, max, type);
    write_header(f_merge);

    // run tests
    for(int l=min; l<=max; l += step) {
        printf("Sorting %d elements:\n", l);

        puts("BubbleSort");
        double t = runner(BubbleSort, l, type, passes);
        write_row(f_bubble, l, t);

        puts("BubbleSort(QuickExit)");
        t = runner(BubbleSort_QuickExit, l, type, passes);
        write_row(f_bubble_qe, l, t);

        puts("SelectionSort");
        t = runner(SelectionSort, l, type, passes);
        write_row(f_selection, l, t);

        puts("InsertionSort");
        t = runner(InsertionSort, l, type, passes);
        write_row(f_insert, l, t);

        puts("MergeSort");
        t = runner(MergeSortWrapper, l, type, passes);
        write_row(f_merge, l, t);

        puts("");
    }

    // close files
    fclose(f_bubble);
    fclose(f_bubble_qe);
    fclose(f_selection);
    fclose(f_insert);
    fclose(f_merge);

    return 0;
}
