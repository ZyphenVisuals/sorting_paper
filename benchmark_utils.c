//
// Created by iulian on 5/8/24.
//

#include "benchmark_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random(int* data, const unsigned int length) {
    for(int i=0; i<length; i++) {
        data[i] = rand() % 100000000;
    }
}

void fill_ascending(int* data, const unsigned int length) {
    for(int i=0; i<length; i++) {
        data[i] = i+1;
    }
}

void fill_descending(int* data, const unsigned int length) {
    for(int i=0; i<length; i++) {
        data[i] = length - i;
    }
}

void fill_10(int* data, const unsigned int length) {
    for(int i=0; i<length; i++) {
        data[i] = i+1;
    }
    // execute a swap for 5% of the elements, affecting 10% of the array
    for(int i=0; i<length/20; i++) {
        const int a = rand() % length;
        const int b = rand() % length;
        const int temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }
}

void fill_rsmall(int* data, const unsigned int length) {
    for(int i=0; i<length; i++) {
        data[i] = rand() % 1000;
    }
}

int *data_generator(const unsigned int length, const unsigned short int type) {
    int* data = malloc(length * sizeof(int));

    if(data == NULL) {
        puts("Memory allocation failed.");
        exit(1);
    }

    switch(type) {
        case 1:
            fill_random(data, length);
            break;
        case 2:
            fill_ascending(data, length);
            break;
        case 3:
            fill_descending(data, length);
            break;
        case 4:
            fill_10(data, length);
            break;
        case 5:
            fill_rsmall(data, length);
        default:
            break;
    }
    return data;
}

unsigned int validate(const int* data, const unsigned int length) {
    for(int i=1; i<length; i++) {
        if(data[i] < data[i-1]) {
            return i;
        }
    }
    return 0;
}

double runner(void (*sort)(int* data, unsigned int length), const unsigned int length, const unsigned short int type, const unsigned short int passes) {
    clock_t total = 0;
    for(int i=0; i<passes; i++) {
        int* data = data_generator(length, type);
        const clock_t start = clock();
        (*sort)(data, length);
        const clock_t end = clock();
        printf("%fs\n", ((double)(end-start)) / CLOCKS_PER_SEC);
        const unsigned int err = validate(data, length);
        if(err) {
            printf("[ERROR] Wrong order.\nOut of order elements around %u:\n", err);
            printf("%d %d %d\n", data[err-1], data[err], data[err+1]);
            exit(1);
        }
        total += end - start;
        free(data);
    }
    return (((double)total / passes)) / CLOCKS_PER_SEC;
}