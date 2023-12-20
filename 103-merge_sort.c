#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void cocktail_swap(int *array, size_t first, size_t second);
void cocktail_merge(int *array, int *buff, size_t front, size_t mid,
		    size_t back);
void cocktail_sort_recursive(int *array, int *buff, size_t front, size_t back);
void cocktail_sort(int *array, size_t size);

/**
 * cocktail_swap - Swap two elements in an array.
 * @array: The array containing the elements to swap.
 * @first: The index of the first element.
 * @second: The index of the second element.
 */
void cocktail_swap(int *array, size_t first, size_t second)
{
	int temp = array[first];

	array[first] = array[second];
	array[second] = temp;
}

/**
 * cocktail_merge - Merge two subarrays of an array.
 * @array: The array containing the subarrays to merge.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void cocktail_merge(int *array, int *buff, size_t front, size_t mid,
		    size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + front, mid - front);

	printf("[right]: ");
	print_array(array + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		buff[k++] = array[i];
	for (; j < back; j++)
		buff[k++] = array[j];
	for (i = front, k = 0; i < back; i++)
		array[i] = buff[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
 * cocktail_sort_recursive - Implement the merge sort algorithm
 *                           through recursion.
 * @array: The array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the array.
 * @back: The back index of the array.
 */
void cocktail_sort_recursive(int *array, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		cocktail_sort_recursive(array, buff, front, mid);
		cocktail_sort_recursive(array, buff, mid, back);
		cocktail_merge(array, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *                 order using the cocktail sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down cocktail sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	cocktail_sort_recursive(array, buff, 0, size);

	free(buff);
}
