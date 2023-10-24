#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - merge two subarrays
 * @array: array to sort
 * @low: starting index of first subarray
 * @count: number of elements to sort
 * @dir: sort direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int low, size_t count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;
		int i, j;

		printf("Merging [%lu/%lu] (%s):\n", count, count, dir ? "UP" : "DOWN");
		print_array(array + low, count);

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int tmp = array[i];

				array[i] = array[i + k];
				array[i + k] = tmp;
				printf("Result [2/%lu] (%s):\n", count, dir ? "UP" : "DOWN");
				print_array(array + i, 2);
			}
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort - sort an array of integers in ascending order using the
 *                Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int i, j;

	if (size < 2)
		return;

	for (i = 2; i <= size; i *= 2)
	{
		for (j = 0; j < size; j += i)
		{
			int dir = (j / i) % 2 == 0;

			bitonic_merge(array, j, i, dir);
		}
	}
}
