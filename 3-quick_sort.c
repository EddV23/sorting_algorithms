#include "sort.h"

void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition - 1, size);
		quick_sort_recursive(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in @array
 * Return: The pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int a, b, *pivot = array + high;

	for (a = b = low; b < high; b++)
	{
		if (array[b] < *pivot)
		{
			if (a < b)
			{
				swap(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *pivot)
	{
		swap(array + a, pivot);
		print_array(array, size);
	}

	return (a);
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
