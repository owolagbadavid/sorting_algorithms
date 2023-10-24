#include "sort.h"

#include "sort.h"

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - recursive function for bitonic sort
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @dir: ascending or descending
 * @size: size of the array
 */
void bitonic_recursion(int *array, int l, int r, int dir, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, dir);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - sort using bitonic merge
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @dir: ascending or descending
 */
void bitonic_merge(int *array, int l, int r, int dir)
{
	int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (dir == (array[i] > array[i + mid]))
			{
				tmp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = tmp;
			}
		}
		bitonic_merge(array, l, step, dir);
		bitonic_merge(array, step + 1, r, dir);
	}

}
