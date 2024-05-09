//
// Created by iulian on 5/8/24.
//

#include "bubble_sort.h"

void BubbleSort(int* data, const unsigned int length) {
    int i, j, t;
    for(i = length-1; i >= 0; i--) {
        for(j = 1; j <= i; j++) {
            if(data[j-1] > data[j]) {
                t = data[j-1];
                data[j-1] = data[j];
                data[j] = t;
            }
        }
    }
}

void BubbleSort_QuickExit(int* data, const unsigned int length) {
    char swapped = 1;
    int i, j, t;
    for(i = length-1; i >= 0 && swapped; i--) {
        swapped = 0;
        for(j = 1; j <= i; j++) {
            if(data[j-1] > data[j]) {
                t = data[j-1];
                data[j-1] = data[j];
                data[j] = t;
                swapped = 1;
            }
        }
    }
}