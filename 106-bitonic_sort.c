#include "sort.h"

void swap(int *a, int *b);

/**
 * bitonic_merge - Merge subarrays in bitonic sequence.
 * @array: Array to be sorted.
 * @low: Starting index of the subarray.
 * @count: Number of elements to be merged.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
	size_t step, i, j;

	if (count > 1)
	{
		step = count / 2;

		for (i = low; i < low + step; i++)
		{
			j = i + step;

			if ((dir && array[i] > array[j]) ||
			    (!dir && array[i] < array[j]))
			{
				swap(array + i, array + i + step);
			}
		}

		bitonic_merge(array, size, low, step, dir);
		bitonic_merge(array, size, low + step, step, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort.
 * @array: Array to be sorted.
 * @low: Starting index of the subarray.
 * @size: Number of elements in the subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t size, int dir)
{
	size_t step;

	if (size > 1)
	{
		step = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", size, size + low,
		       dir ? "UP" : "DOWN");
		print_array(array + low, size);

		/* Ascending order */
		bitonic_sort_recursive(array, low, step, 1);

		/* Descending order */
		bitonic_sort_recursive(array, low + step, step, 0);

		bitonic_merge(array, size, low, size, dir);

		printf("Result [%lu/%lu] (%s):\n", size, size + low,
		       dir ? "UP" : "DOWN");
		print_array(array + low, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                 using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * swap - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
