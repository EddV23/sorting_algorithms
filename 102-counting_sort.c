#include "sort.h"

void counting_sort(int *array, size_t size);

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the cumulative counts for the range [0, max].
 */
void counting_sort(int *array, size_t size)
{
	int *sorted, max = 0, i;
	int *count;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (max = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}

	/* Initialize count array with zeros */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Update count array with the frequency of each element */
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	/* Update count array with cumulative counts */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Print the cumulative counts for the range [0, max] */
	for (i = 0; i <= max; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", count[i]);
	}
	printf("\n");

	/* Build the sorted array based on cumulative counts */
	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	/* Free allocated memory */
	free(sorted);
	free(count);
}
