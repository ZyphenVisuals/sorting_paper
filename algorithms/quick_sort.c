//
// Created by iulian on 5/9/24.
//

#include "quick_sort.h"

#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* data, const int l, const int r) {
    int pivot, i, j, t;
    if(r > l) {
        // pivot is on the right
        pivot = data[r];
        i = l-1;
        j = r;
        for(;;) {
            while(data[++i] < pivot);
            while(data[--j] > pivot);
            if(i >= j) {
                break;
            }
            t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
        t = data[i];
        data[i] = data[r];
        data[r] = t;
        QuickSort(data, l, i-1);
        QuickSort(data, i+1, r);
    }
}

void QuickSort_Random(int* data, const int l, const int r) {
    int pivot, i, j, t;
    if(r > l) {
        // get ranndom pivot
        int random = l + rand() % (r-l);
        // put the pivot on the right
        t = data[random];
        data[random] = data[r];
        data[r] = t;
        // pivot is on the right
        pivot = data[r];
        i = l-1;
        j = r;
        for(;;) {
            while(data[++i] < pivot);
            while(data[--j] > pivot);
            if(i >= j) {
                break;
            }
            t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
        t = data[i];
        data[i] = data[r];
        data[r] = t;
        QuickSort_Random(data, l, i-1);
        QuickSort_Random(data, i+1, r);
    }
}

void QuickSort_MoT(int* data, const int l, const int r) {
    int pivot, i, j, t;
    if(r > l) {
        // find median of three
        int m = l + (r-l) / 2;
        if(data[l] > data[m]) {
            t = data[l];
            data[l] = data[m];
            data[m] = t;
        }
        if(data[l] > data[r]) {
            t = data[l];
            data[l] = data[r];
            data[r] = t;
        }
        if(data[m] > data[r]) {
            t = data[m];
            data[m] = data[r];
            data[r] = t;
        }
        // put the pivot on the right
        t = data[m];
        data[m] = data[r];
        data[r] = t;
        // pivot is on the right
        pivot = data[r];
        i = l-1;
        j = r;
        for(;;) {
            while(data[++i] < pivot);
            while(data[--j] > pivot);
            if(i >= j) {
                break;
            }
            t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
        t = data[i];
        data[i] = data[r];
        data[r] = t;
        QuickSort_MoT(data, l, i-1);
        QuickSort_MoT(data, i+1, r);
    }
}

void QuickSort_Wrapper(int* data, const unsigned int length) {
    QuickSort(data, 0, length-1);
}

void QuickSort_Random_Wrapper(int* data, const unsigned int length) {
    QuickSort_Random(data, 0, length-1);
}

void QuickSort_MoT_Wrapper(int* data, const unsigned int length) {
    QuickSort_MoT(data, 0, length-1);
}