//
// Created by iulian on 5/9/24.
//

#include "selection_sort.h"

void SelectionSort(int* data, const unsigned int length) {
    int i,j,min,temp;
    for(i=0;i<length-1;i++) {
        min = i;
        for(j=i+1;j<length;j++) {
            if(data[j]<data[min]) {
                min = j;
            }
        }
        temp = data[min];
        data[min] = data[i];
        data[i] = temp;
    }
}