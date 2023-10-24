#include "sort.h"

/**
 * merge - Merges two sub-arrays of integers
 *
 * @array: Pointer to the first element of the first sub-array
 * @size: Size of the first sub-array
 * @left: Pointer to the first element of the second sub-array
 * @right_size: Size of the second sub-array
 *
 * Return: void
 */
void merge(int *array, size_t size, int *left, size_t right_size)
{
	int *tmp;
	size_t i = 0, j = 0, k = 0;

	tmp = malloc(sizeof(int) * (size + right_size));
	if (!tmp)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, right_size);
	printf("[right]: ");
	print_array(array, size);

	while (i < size && j < right_size)
	{
		if (array[i] < left[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = left[j++];
	}

	while (i < size)
		tmp[k++] = array[i++];

	while (j < right_size)
		tmp[k++] = left[j++];

	for (i = 0; i < size + right_size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array, size + right_size);

	free(tmp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 *
 * @array: Pointer to the first element of the array to be sorted
 * @size: Size of the array to be sorted
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i = 0;
	int *left;

	if (!array || size < 2)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);

	left = malloc(sizeof(int) * mid);
	if (!left)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	merge(array + mid, size - mid, left, mid);

	free(left);
}
