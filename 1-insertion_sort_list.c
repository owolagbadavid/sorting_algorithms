#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			prev = current->prev;
			print_list(*list);
		}
		current = next;
	}
}
