# Sorting Algorithms Project

This project implements various sorting algorithms in C.

## Table of Contents

- [Introduction](#introduction)
- [Sorting Algorithms](#sorting-algorithms)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)
- [Build and Run](#build-and-run)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project provides C implementations of sorting algorithms, including:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Counting Sort

## Sorting Algorithms

1. **Bubble Sort**: Simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

2. **Selection Sort**: In-place comparison-based sorting algorithm. It divides the input list into two parts: a sorted sublist and an unsorted sublist.

3. **Insertion Sort**: Builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms.

4. **Merge Sort**: Divide-and-conquer algorithm that divides the unsorted list into `n` sublists, each containing one element, and then repeatedly merges sublists to produce new sorted sublists.

5. **Quick Sort**: Efficient, in-place, comparison-based sorting algorithm. It works by partitioning an array into two smaller sub-arrays and then recursively sorting the sub-arrays.

6. **Counting Sort**: Non-comparative sorting algorithm that sorts elements based on their count occurrences in the input.


## Usage

To use the sorting algorithms, include the necessary header file in your C program and call the appropriate function.

Example:
```c
#include "sort.h"

int main(void) {
    int array[] = {4, 2, 7, 1, 9, 5};
        size_t size = sizeof(array) / sizeof(array[0]);

    // Call the sorting function
        bubble_sort(array, size);

    // Print the sorted array
        print_array(array, size);

    return 0;
}
```


## File Descriptions

 - sort.h: Header file containing function prototypes and necessary includes.
 - bubble_sort.c: Implementation of the Bubble Sort algorithm.
 - selection_sort.c: Implementation of the Selection Sort algorithm.
 - insertion_sort.c: Implementation of the Insertion Sort algorithm.
 - merge_sort.c: Implementation of the Merge Sort algorithm.
 - quick_sort.c: Implementation of the Quick Sort algorithm.
 - counting_sort.c: Implementation of the Counting Sort algorithm.
 - print_array.c: Function to print an array.


## Contributing

Contributions are welcome! If you find any issues or improvements, feel free to create a pull request.


## License

This project is licensed under the MIT License.