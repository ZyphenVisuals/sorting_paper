//
// Created by iulian on 5/8/24.
//

#include "bubble_sort.h"

void BubbleSort(int* data, const unsigned int length) {
    for(int pass = length - 1; pass >= 0; pass--) {
        for(int i=0; i <= pass - 1 ; i++) {
            if(data[i] > data[i+1]) {
                const int temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
    }
}

void BubbleSort_QuickExit(int* data, const unsigned int length) {
    int swapped = 1;
    for(int pass = length - 1; pass >= 0 && swapped; pass--) {
        swapped = 0;
        for(int i=0; i <= pass - 1 ; i++) {
            if(data[i] > data[i+1]) {
                const int temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                swapped = 1;
            }
        }
    }
}