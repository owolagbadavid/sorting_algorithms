#include "sort.h"
#include <stdio.h>

/**
 * heapify - heapifies an array
 * @array: array to heapify
 * @size: size of the array
 * @i: index to heapify from
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i, left = 2 * i + 1, right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}
