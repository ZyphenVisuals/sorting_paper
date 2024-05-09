//
// Created by iulian on 5/9/24.
//

#include "merge_sort.h"

#include <stdio.h>
#include <stdlib.h>

void Merge(int* data, int* aux, int left, int mid, int right) {
    const int left_end = mid-1;
    int temp_pos = left;
    const int size = right - left + 1;

    while((left <= left_end) && (mid <= right)) {
        if(data[left] <= data[mid]) {
            aux[temp_pos] = data[left];
            temp_pos = temp_pos + 1;
            left = left + 1;
        }
        else {
            aux[temp_pos] = data[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }

    while(left <= left_end) {
        aux[temp_pos] = data[left];
        left = left + 1;
        temp_pos = temp_pos + 1;
    }
    while(mid <= right) {
        aux[temp_pos] = data[mid];
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    for(int i=0; i<=size; i++) {
        data[right] = aux[right];
        right = right - 1;
    }
}

void MergeSort(int* data, int* aux, const int left, const int right) {
    if(right > left) {
        const int mid = (right+left) / 2;
        MergeSort(data, aux, left, mid);
        MergeSort(data, aux, mid+1, right);
        Merge(data, aux, left, mid+1, right);
    }
}

void MergeSortWrapper(int* data, const unsigned int length) {
    int* aux = malloc(length * sizeof(int));
    if(aux == NULL) {
        puts("[ERROR] Cannot allocate auxiliary memory for MergeSort.");
        exit(1);
    }
    MergeSort(data, aux, 0, length-1);
    free(aux);
}