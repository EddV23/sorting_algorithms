#include "sort.h"

void quick_sort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                    order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
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
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		/*quick_sort_recursive(array, pivot + 1, high, size);*/
		quick_sort_recursive(array, pivot, high, size);
	}
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: The array to be partitioned
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in @array
 * Return: The pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int a = low - 1;
	int b = high + 1;
	int i, j;

	for (i = a, j = b; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	return (i);

	/*
	 *for (j = low; j <= high - 1; j++)
	 *{
	 *	if (array[j] < pivot)
	 *	{
	 *		i++;
	 *		swap(&array[i], &array[j]);
	 *		if (i != j)
	 *			print_array(array, size);
	 *	}
	 *}
	 *
	 *swap(&array[i + 1], &array[high]);
	 *if (i + 1 != high)
	 *	print_array(array, size);
	 *
	 *return (i + 1);
	 */
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
