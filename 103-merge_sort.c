#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge_subarray(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sort a subarray holding data indexes.
 * @subarr: A subarray of an array holding data indexes to sort.
 * @buff: A buffer to store the sorted
 * subarray holding the array of data indexes.
 * @front: The front index of the array holding the data or subarray.
 * @mid: The middle index of the array holding the data or subarray.
 * @back: The back index of the array holding the data or subarray.
 */
void merge_subarray(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array holding data indexes to sort.
 * @buff: A buffer to store the sorted result of the data indexes sorted.
 * @front: The front index of the subarray
 * holding the data indexes in the array.
 * @back: The back index of the subarray holding the data indexes in the array.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarray(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array holding data indexes in ascending
 *              order using the merge sort algorithm.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 *
 * Description: Implements the top-down merge
 * sort algorithm of the data indexes.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
