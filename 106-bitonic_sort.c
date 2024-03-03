#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void inter_swap(int *a, int *b);
void bitonic_merge_code(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_sequence(int *array, size_t size,
size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge_code - Code used to sort a bitonic
 * sequence inside an array holding data indexes.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 * @start: The starting index in the sequence of
 * the array holding the data indexes to be sorted.
 * @seq: The size of the sequence to sort which
 * holds the array containing the data indexes.
 * @flow: The direction to sort the array holding the data indexes in.
 */
void bitonic_merge_code(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				inter_swap(array + i, array + i + jump);
		}
		bitonic_merge_code(array, size, start, jump, flow);
		bitonic_merge_code(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sequence - Code used to convert an array
 * holding data indexes into a bitonic sequence.
 * @array: An array holding the data indexes to be converted.
 * @size: The size of the array holding the data indexes to be converted.
 * @start: The starting array of data index of a
 * block of the building used in bitonic sequence.
 * @seq: The array data index size of a block of
 * the building used in bitonic sequence.
 * @flow: The direction to sort the array of
 * data index using the bitonic sequence block in.
 */
void bitonic_sequence(int *array, size_t size,
size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, cut, UP);
		bitonic_sequence(array, size, start + cut, cut, DOWN);
		bitonic_merge_code(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array holding the data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 *
 * Description: Used to prints the array holding
 * the data indexes after each successful swap.
 * Only works for the size = 2^k where k >= 0
 * (eg. the size is equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
