//
// Created by iulian on 5/9/24.
//

#include "insertion_sort.h"

void InsertionSort(int* data, const unsigned int length) {
    int i,j,v;
    for(i=1;i<length;i++) {
        v = data[i];
        j=i;
        while(data[j-1] > v && j >= 1) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = v;
    }
}

void InsertionSort_Sentinel(int* data, const unsigned int length) {
    //find the sentinel
    int min = 0;
    for(int i=1;i<length;i++) {
        if(data[i] < data[min]) {
            min = i;
        }
    }
    //swap the sentinel with the first element
    int temp = data[0];
    data[0] = data[min];
    data[min] = temp;
    int i,j,v;
    for(i=1;i<length;i++) {
        v = data[i];
        j=i;
        while(data[j-1] > v) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = v;
    }
}