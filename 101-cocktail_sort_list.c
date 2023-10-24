#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL, *tmp = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	start = *list;
	end = NULL;
	do {
		swapped = 0;
		for (current = start; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		end = current;
		for (current = end->prev; current != start->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
		}
		start = current->next;
	} while (swapped);
}
