# Sorting Algorithms in C

This repository was created as part of an assignment from the West University of Timisoara.

It contains all the code used to benchmark the most common sorting algorithms in C.

# Usage

Basic usage example:

```bash
sort [min] [max] [step] [type] [passes] [ignoreslow]
```

The lists sorted will start at `min` lements and increase by `step`, reaching but not exceeding `max`.


The value of `type` should be one of the following:
- `1`: Random
- `2`: Ascending
- `3`: Descending
- `4`: Almost ascending (10% random)
- `5`: Small random (<1000)

The value of `passes` should be a positive integer, representing the number of times each list is sorted before computing the average.


The value of `ignoreslow` should be `0` or `1`, representing whether to ignore slow algorithms (BubbleSort, SelectionSort, InsertionSort) in the output.