#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int maxi(int *array, int size);
void radix_counting_sorting(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * maxi - Used to get the maximum value in an array holding data indexes.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding data indexes to be sorted.
 *
 * Return: The maximum data indexes being held in the array.
 */
int maxi(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sorting - Sort the significant digits
 * of an array holding data indexes
 *                       in ascending order using the counting sort algorithm.
 * @array: An array holding data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 * @sig: The significant digit to sort on for
 * the array holding the data indexes.
 * @buff: A buffer to store the sorted array holding the data indexes.
 */
void radix_counting_sorting(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array holding the data indexes in ascending
 *              order using the radix sort algorithm.
 * @array: An array hoding the data indexes to be sorted.
 * @size: The size of the array holding the data indexes to be sorted.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array of data indexes after
 * each significant digit increase is successful.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = maxi(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sorting(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
