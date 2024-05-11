# Warning

This folder contains the final results used in my paper. The files are safe to remove, however do not remove this folder, it needs to exist in order for the program to have a place to output to.

# Structure

Each file in this folder follows the naming format `[algo]_[type]_[min]_[max]`, where:

- `algo` - Display name of the algorithm
- `type` - Type of test conducted (random, ascending, ...)
- `min`, `max` - Range for the test

Each `.csv` file contains the average time taken to sort a list of elements of size `min` to `max` for a specific algorithm and test type, one size per row.