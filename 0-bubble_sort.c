#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * inter_swap - data in the array to be swapped.
 * @a: First data in the index.
 * @b: Second data in the index .
 */
void inter_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort data in an index in ascending order
 * @array: a container holding the index data
 * @size: size of data being held in the index array
 *
 * Description: After each swapping, the data is printed out.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				inter_swap(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
