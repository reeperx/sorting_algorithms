#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void inter_swap(int *a, int *b);
int hoare_partition_code(int *array, size_t size, int left, int right);
void hoare_sorting(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition_code - Code used to order a
 * subset of an array holding data indexes
 *                   according to the hoare partition scheme.
 * @array: The array holding data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 * @left: The starting array of data index of the subset to order.
 * @right: The ending array of data index of the subset to order.
 *
 * Return: The final partition array of data indexes.
 *
 * Description: Uses the last data index of the partition as the pivot point.
 * Prints the array holding the data index after
 * each swap of two data indexes is successful.
 */
int hoare_partition_code(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			inter_swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sorting - Code used to sort the data
 * indexes using the quicksort algorithm through recursion.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding data indexes to be sorted.
 * @left: The starting index of the array
 * holding data index partition to order.
 * @right: The ending index of the array holding data index partition to order.
 *
 * Description: Uses the Hoare partition scheme
 * to sort the array holding the data index.
 */
void hoare_sorting(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition_code(array, size, left, right);
		hoare_sorting(array, size, left, part - 1);
		hoare_sorting(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array holding data indexes in ascending
 *                    order using the quicksort algorithm method.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding data indexes to be sorted.
 *
 * Description: Uses the Hoare partition scheme to
 * sort the array holding the data index.
 * Prints the array holding the data index after
 * each successful swap of two data indexes.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sorting(array, size, 0, size - 1);
}
