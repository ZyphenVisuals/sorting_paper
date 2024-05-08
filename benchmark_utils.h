//
// Created by iulian on 5/8/24.
//

#ifndef BENCHMARK_UTILS_H
#define BENCHMARK_UTILS_H

/**
 * 
 * @param length Length of the array to generate
 * @param type Type of data generation. See help
 * @return Pointer to an array of integers
 */
int *data_generator(const unsigned int length, const unsigned short int type);

/**
 * 
 * @param sort Pointer to the sorting function to be used
 * @param length Length of the array to be sorted
 * @param type Type of array to generate
 * @param passes Number of passes for computing the average
 * @return Time execution took, in seconds
 */
double runner(void (*sort)(int* data, unsigned short int length), const unsigned short int length, const unsigned short int type, const unsigned short int passes);

#endif //BENCHMARK_UTILS_H
