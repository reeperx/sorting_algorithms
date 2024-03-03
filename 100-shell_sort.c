#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * inter_swap - Used to swap two data indexes in an array.
 * @a: Points to the first data index to be swapped.
 * @b: Points to the second data index to be swapped.
 */
void inter_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort data indexes held in an array in ascending
 *              order using the shell sort algorithm.
 * @array: An array holding data indexes.
 * @size: The size of the array holding the data indexes.
 *
 * Description: Uses the Knuth interval sequence to sort the data indexes.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				inter_swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
