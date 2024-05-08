//
// Created by iulian on 5/8/24.
//

#include "csv_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_header(FILE* f) {
    fprintf(f, "Length,Time\n");
}

void write_row(FILE *f, const unsigned int length, const double time) {
    fprintf(f, "%u,%f\n", length, time);
}

FILE* create_csv(char* algo, const int min, const int max, const int type) {
    char* typestring = malloc(20);
    switch(type) {
        case 1:
            strcpy(typestring, "Random(Big)");
            break;
        case 2:
            strcpy(typestring, "Ascending");
            break;
        case 3:
            strcpy(typestring, "Descending");
            break;
        case 4:
            strcpy(typestring, "Random(10%)");
            break;
        case 5:
            strcpy(typestring, "Random(Small)");
            break;
        default:
            break;;
    }
    char* filename = malloc(128);
    sprintf(filename, "./results/%s_%s_%d_%d.csv", algo, typestring, min, max);
    FILE* f = fopen(filename, "w");
    free(typestring);
    free(filename);
    return f;
}