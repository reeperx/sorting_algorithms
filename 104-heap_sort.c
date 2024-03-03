#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void inter_swap(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * heapify - Used to turns a binary tree into a complete heap of binary.
 * @array: An array holding data indexes representing a binary tree.
 * @size: The size of the array/tree holding the data indexes.
 * @base: The data index at the base row of the tree/array.
 * @root: The root node of the binary tree/array being checked.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		inter_swap(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Used to sort an array holding data indexes in ascending
 *             order using the heap sort algorithm.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 *
 * Description: Implements the sift-down heap sorting
 * algorithm which prints the array holding
 * the data indexes after each successful swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		inter_swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
