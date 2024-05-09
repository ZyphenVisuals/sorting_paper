//
// Created by iulian on 5/9/24.
//

#include "quick_sort.h"

int Partition(int* data, const int low, const int high) {
    const int pivot_item = data[low];
    int left = low;
    int right = high;
    while(left<right) {
        while(data[left]<=pivot_item) {
            left++;
        }
        while(data[right] > pivot_item) {
            right--;
        }
        if(left<right) {
            int temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
    }
    data[low] = data[right];
    data[right] = pivot_item;
    return right;
}

void QuickSort(int* data, const int low, const int high) {
    if(high > low) {
        const int pivot = Partition(data, low, high);
        QuickSort(data, low, pivot-1);
        QuickSort(data, pivot+1, high);
    }
}

void QuickSortWrapper(int* data, const unsigned int length) {
    QuickSort(data, 0, length-1);
}