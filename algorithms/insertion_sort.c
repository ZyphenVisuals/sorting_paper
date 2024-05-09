//
// Created by iulian on 5/9/24.
//

#include "insertion_sort.h"

void InsertionSort(int* data, const unsigned int length) {
    int i,j,v;
    for(i=0;i<length;i++) {
        v = data[i];
        j=i;
        while(data[j-1] > v && j >= 1) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = v;
    }
}