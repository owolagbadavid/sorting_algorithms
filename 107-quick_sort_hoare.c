#include "sort.h"

/**
 * quick_recursion - quick_sort helper
 * @array: array to sort
 * @size: size of array
 * @right: right index
 * @left: left index
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		quick_recursion(array, left, pivot - 1, size);
		quick_recursion(array, pivot + 1, right, size);
	}
}

/**
 * partition - partitioner
 * @array: array to sort
 * @size: size of array
 * @right: right index
 * @left: left index
 * Return: index of pivot
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, pivot = array[right];
	size_t i, j;

	i = left - 1;
	j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * quick_sort_hoare - sorts array using quick sort
 * @array: array to be sorted
 * @size: size of array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}
