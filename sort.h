#ifndef __SORT_H__
#define __SORT_H__
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **head, listint_t **node);
size_t list_length(listint_t *head);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void mergeSubarray(int *temp, int *array, size_t left,
		size_t middle, size_t right);
void mergeSortRecursion(int *temp, int *array, size_t left, size_t right);
void heap_sort(int *array, size_t size);
void heapify(int *arr, size_t s, size_t root, size_t n);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, int l, int r, int dir);
void bitonic_recursion(int *array, int l, int r, int dir, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int left, int right, size_t size);
void quick_recursion(int *array, int left, int right, size_t size);

#endif
