//
// Created by rotar on 5/10/2024.
//

#include "radix_sort.h"

#include <stdlib.h>

void CountingSortWithExponent(int* data, const unsigned int length, const int exp) {
    // initialize a frequency vector with enough space
    int count[10] = {0};

    // count the frequency of each element
    for(int i = 0; i < length; i++) {
        count[(data[i]/exp)%10]++;
    }

    // make a running sum
    for(int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    // create a output array to store the sorted elements
    int* output = malloc(length * sizeof(int));
    for(int i = length-1; i >= 0; i--) {
        output[count[(data[i]/exp)%10]-1] = data[i];
        count[(data[i]/exp)%10]--;
    }

    // copy the sorted elements back to the original array
    for(int i = 0; i < length; i++) {
        data[i] = output[i];
    }

    free(output);
}

void RadixSort(int* data, const unsigned int length) {
    // find maximum element in the array
    int max = data[0];
    for(int i = 1; i < length; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }

    // sort the array by each digit
    for(int exp = 1; max/exp > 0; exp *= 10) {
        CountingSortWithExponent(data, length, exp);
    }
}