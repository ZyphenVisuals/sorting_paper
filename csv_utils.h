//
// Created by iulian on 5/8/24.
//

#ifndef CSV_UTILS_H
#define CSV_UTILS_H
#include <stdio.h>

/**
 * Writes the header of the .csv file.
 * @param f File pointer to write to
 */
void write_header(FILE* f);

/**
 * Writes a row in the .csv file, containing the length and time.
 * @param f File pointer to write to
 * @param length Length of array sorted
 * @param time Time taken
 */
void write_row(FILE *f, const unsigned int length, const double time);

/**
 * Creates a new file for the current running test and algorithm.
 * @param algo Name of the algorithm
 * @param min Minimum of the tested range
 * @param max Maximum of the tested range
 * @param type Type of test ran
 * @return Pointer to the newly created file
 */
FILE* create_csv(char* algo, const int min, const int max, const int type);

#endif //CSV_UTILS_H
