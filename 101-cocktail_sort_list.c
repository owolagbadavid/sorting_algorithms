#include "sort.h"

/**
 * swap - swaps two nodes in a doubly linked list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 *                       using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	int swapped = 1;
	listint_t *left_node = *list, *right_node = NULL, *current_node = NULL;

	while (swapped)
	{
		swapped = 0;
		current_node = left_node;

		while (current_node != right_node)
		{
			if (current_node->n > current_node->next->n)
			{
				swap(current_node, current_node->next);
				if (current_node->prev == NULL)
					*list = current_node;
				print_list(*list);
				swapped = 1;
			}
			else
				current_node = current_node->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		right_node = current_node->prev;
		current_node = right_node;

		while (current_node != left_node)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap(current_node, current_node->prev);
				if (current_node->prev == NULL)
					*list = current_node;
				print_list(*list);
				swapped = 1;
			}
			else
				current_node = current_node->prev;
		}

		left_node = left_node->next;
	}
}
