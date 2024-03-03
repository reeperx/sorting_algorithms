#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void inter_swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * inter_swap - Used to swap two data indexes in an array.
 * @a: The firs data index to swap in the array.
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
 * lomuto_partition - Order a subset of an array of data index according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array holding the data indexes.
 * @size: The size of the array holding the data indexes.
 * @left: Points to the starting data index of the subset to order.
 * @right: Points to the ending data index of the subset to order.
 *
 * Return: The final partition data index to be displayed.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				inter_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		inter_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of holding the data indexes to sort.
 * @size: The size of the array holding the data indexes.
 * @left: Points to the starting index of the array data partition to order.
 * @right: Points to the ending index of the array data partition to order.
 *
 * Description: Uses the Lomuto data partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of data indexes in an ascending order
 *
 * @array: An array of holding the data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 *
 * Description: Uses the Lomuto data partition schem.
 * Prints the array after each successful
 * swap of two data indexes.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
