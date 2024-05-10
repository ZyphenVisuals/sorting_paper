//
// Created by rotar on 5/10/2024.
//

#include "counting_sort.h"

#include <stdlib.h>

void CountingSort(int* data, const unsigned int length) {
    // find maximum element in the array
    int max = data[0];
    for(int i = 1; i < length; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }
    // initialize a frequency vector with enough space
    int* count = malloc((max+1) * sizeof(int));
    // fill the frequency vector with 0
    for(int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // count the frequency of each element
    for(int i = 0; i < length; i++) {
        count[data[i]]++;
    }

    // make a running sum
    for(int i = 1; i <= max; i++) {
        count[i] += count[i-1];
    }

    // create a output array to store the sorted elements
    int* output = malloc(length * sizeof(int));
    for(int i = length-1; i >= 0; i--) {
        output[count[data[i]]-1] = data[i];
        count[data[i]]--;
    }

    // copy the sorted elements back to the original array
    for(int i = 0; i < length; i++) {
        data[i] = output[i];
    }

    free(output);
    free(count);
}
