#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * inter_swap - Used to swap two data index in an array.
 * @a: The first data index to swap in the array.
 * @b: The second data index to swap in the array.
 */
void inter_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Used to sort data indexes in ascending order in an array
 *
 * @array: An array holding data indexes.
 * @size: The size of the array holding the data indexes.
 *
 * Description: Prints the array after each successful data index swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			inter_swap(array + i, min);
			print_array(array, size);
		}
	}
}
