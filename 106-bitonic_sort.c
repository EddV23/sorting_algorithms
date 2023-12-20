#include "sort.h"

void swap(int *a, int *b);

/**
 * bitonic_merge - Merge subarrays in bitonic sequence.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * @low: Starting index of the subarray.
 * @count: Number of elements to be merged.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, char dir)
{
	size_t step, i, j;

	(void)size;

	if (count > 1)
	{
		step = count / 2;

		for (i = low; i < low + step; i++)
		{
			j = i + step;

			if ((dir == 0 && array[i] > array[j]) ||
			    (dir == 1 && array[i] < array[j]))
			{
				swap(array + i, array + j);
			}
		}
	}
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * @low: Starting index of the subarray.
 * @count: Number of elements in the subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low,
			    size_t count, char dir)
{
	size_t step;

	if (size > 1)
	{
		step = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", count, size,
		       dir ? "UP" : "DOWN");
		print_array(array + low, count);

		/* Ascending order */
		bitonic_sort_recursive(array, step, low, step, 1);

		/* Descending order */
		bitonic_sort_recursive(array, step, low + step, step, 0);

		bitonic_merge(array, size, low, count, dir);

		printf("Result [%lu/%lu] (%s):\n", count, size,
		       dir ? "UP" : "DOWN");
		print_array(array + low, count);
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

	bitonic_sort_recursive(array, size, 0, size, 0);
}

/**
 * swap - Swaps two integers
 * @a: The first integer.
 * @b: The second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
