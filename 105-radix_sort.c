#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *arr;
	int max, exp;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return;

	max = array[0];
	for (exp = 0; exp < (int)size; exp++)
	{
		if (array[exp] > max)
			max = array[exp];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		int i, count[10] = {0};

		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			arr[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = arr[i];

		print_array(array, size);
	}

	free(arr);
}
