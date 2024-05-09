//
// Created by iulian on 5/9/24.
//

#include "merge_sort.h"

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int* data, int* aux, const int l, const int r) {
    int i, j, k, m;
    if(r > l) {
        m = (r+l) / 2;
        MergeSort(data, aux, l, m);
        MergeSort(data, aux, m+1, r);
        for(i=m+1; i>l; i--) {
            aux[i-1] = data[i-1];
        }
        for(j=m; j<r; j++) {
            aux[r+m-j] = data[j+1];
        }
        for(k=l; k<=r; k++) {
            data[k] = (aux[i] < aux[j]) ? aux[i++] : aux[j--];
        }
    }
}

void MergeSort_Wrapper(int* data, const unsigned int length) {
    int* aux = malloc(length * sizeof(int));
    if(aux == NULL) {
        puts("[ERROR] Cannot allocate auxiliary memory for MergeSort.");
        exit(1);
    }
    MergeSort(data, aux, 0, length-1);
    free(aux);
}