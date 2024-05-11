#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark_utils.h"
#include "csv_utils.h"
#include "print_utils.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/counting_sort.h"
#include "algorithms/insertion_sort.h"
#include "algorithms/merge_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/radix_sort.h"
#include "algorithms/selection_sort.h"

int main(const int argc, char** argv) {
    // Argument handling
    if(argc == 2 && !strcmp(argv[1], "help")) {
        print_help();
        return 0;
    }
    if(argc != 7) {
        puts("[ERROR] Command usage: \"sort [min] [max] [step] [type] [passes] [ignoreslow]\". For more info use \"sort help\"");
        return 1;
    }
    const unsigned int min = atoi(argv[1]), max = atoi(argv[2]), step = atoi(argv[3]), type = atoi(argv[4]), passes = atoi(argv[5]), ignoreslow = atoi(argv[6]);
    if(type < 1 || type > 5) {
        puts("[ERROR] Invalid type. See \"sort help\"");
        return 1;
    }
    srand(time(NULL));

    // set up files
    FILE* f_bubble = NULL;
    FILE* f_bubble_qe = NULL;
    FILE* f_selection = NULL;
    FILE* f_insert = NULL;
    FILE* f_insert_sentinel = NULL;
    if(!ignoreslow) {
        f_bubble = create_csv("BubbleSort", min, max, type);
        write_header(f_bubble);
        f_bubble_qe = create_csv("BubbleSort(QuickExit)", min, max, type);
        write_header(f_bubble_qe);
        f_selection = create_csv("SelectionSort",min,max,type);
        write_header(f_selection);
        f_insert = create_csv("InsertionSort", min, max, type);
        write_header(f_insert);
        f_insert_sentinel = create_csv("InsertionSort(Sentinel)", min, max, type);
        write_header(f_insert_sentinel);
    }
    FILE* f_merge = create_csv("MergeSort", min, max, type);
    write_header(f_merge);
    FILE* f_quick = create_csv("QuickSort", min, max, type);
    write_header(f_quick);
    FILE* f_quick_random = create_csv("QuickSort(Random)", min, max, type);
    write_header(f_quick_random);
    FILE* f_quick_mot = create_csv("QuickSort(MoT)", min, max, type);
    write_header(f_quick_mot);
    FILE* f_counting = create_csv("CountingSort", min, max, type);
    write_header(f_counting);
    FILE* f_radix = create_csv("RadixSort", min, max, type);
    write_header(f_radix);

    // run tests
    int l = min;
    if(l == 0) {
        l = step;
    };
    for(l; l<=max; l += step) {
        printf("Sorting %d elements:\n", l);

        double t;

        if(!ignoreslow) {
            puts("BubbleSort");
            t = runner(BubbleSort, l, type, passes);
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

            puts("InsertionSort(Sentinel)");
            t = runner(InsertionSort_Sentinel, l, type, passes);
            write_row(f_insert_sentinel, l, t);
        }

        puts("MergeSort");
        t = runner(MergeSort_Wrapper, l, type, passes);
        write_row(f_merge, l, t);

        // note: QuickSort in the worst case scenario is O(n^2). you might want to disable it with other slow algorithms
        puts("QuickSort");
        t = runner(QuickSort_Wrapper, l, type, passes);
        write_row(f_quick, l, t);

        puts("QuickSort(Random)");
        t = runner(QuickSort_Random_Wrapper, l, type, passes);
        write_row(f_quick_random, l, t);

        puts("QuickSort(MoT)");
        t = runner(QuickSort_MoT_Wrapper, l, type, passes);
        write_row(f_quick_mot, l, t);

        puts("CountingSort");
        t = runner(CountingSort, l, type, passes);
        write_row(f_counting, l, t);

        puts("RadixSort");
        t = runner(RadixSort, l, type, passes);
        write_row(f_radix, l, t);

        puts("");
    }

    puts("Testing complete.");

    // close files
    if(!ignoreslow) {
        fclose(f_bubble);
        fclose(f_bubble_qe);
        fclose(f_selection);
        fclose(f_insert);
        fclose(f_insert_sentinel);
    }
    fclose(f_merge);
    fclose(f_quick);
    fclose(f_quick_random);
    fclose(f_quick_mot);
    fclose(f_counting);
    fclose(f_radix);

    return 0;
}
