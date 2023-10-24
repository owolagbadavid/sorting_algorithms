#include "sort.h"

/**
 * merge_sort - sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	mergeSortRecursion(arr, array, 0, size);
	free(arr);
}

/**
 * mergeSortRecursion - recursive function that merge sorts an array
 * @temp: copy array
 * @array: array to merge sort
 * @left: index of the left element
 * @right: index of the right element
 */
void mergeSortRecursion(int *temp, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		mergeSortRecursion(temp, array, left, middle);
		mergeSortRecursion(temp, array, middle, right);
		mergeSubarray(temp, array, left, middle, right);
	}
}

/**
 * mergeSubarray - merges subarrays
 * @temp: copy array
 * @array: array to merge
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void mergeSubarray(int *temp, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}

	while (i < middle)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = temp[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
