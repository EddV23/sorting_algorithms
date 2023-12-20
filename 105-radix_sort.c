#include "sort.h"

void counting_sort_radix(int *array, size_t size, int exp, int *buf);
int get_max(int *array, size_t size);

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *buf;

	if (!array || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp, buf);
		print_array(array, size);
	}

	free(buf);
}

/**
 * counting_sort_radix - Sorts an array of integers using
 *                       Counting sort for Radix sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit's place value
 * @buf: The buffer that stores the sorted array
 */
void counting_sort_radix(int *array, size_t size, int exp, int *buf)
{
	int *output;
	int i, count[10] = {0};

	output = malloc(size * sizeof(int));

	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		buf[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = buf[i];
}

/**
 * get_max - Finds the maximum value in an array
 * @array: The array to be processed
 * @size: Number of elements in @array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
