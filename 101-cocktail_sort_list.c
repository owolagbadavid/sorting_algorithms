#include "sort.h"

/**
 * list_length - function returns length of list
 * @head: head of list
 *
 * Return: length
 */
size_t list_length(listint_t *head)
{
	size_t len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

/**
 * swap_nodes - function swaps nodes at pointer p with the following node
 * @head: head of list
 * @node: pointer to node
 */
void swap_nodes(listint_t **head, listint_t **node)
{
	listint_t *prev_node, *current_node, *next_node, *next_next_node;

	prev_node = (*node)->prev;
	current_node = *node;
	next_node = (*node)->next;
	next_next_node = (*node)->next->next;

	current_node->next = next_next_node;
	if (next_next_node)
		next_next_node->prev = current_node;
	next_node->next = current_node;
	next_node->prev = prev_node;
	if (prev_node)
		prev_node->next = next_node;
	else
		*head = next_node;
	current_node->prev = next_node;
	*node = next_node;
}

/**
 *  cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || list_length(*list) < 2)
		return;
	p = *list;
	while (!sorted)
	{
		sorted = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorted = 0;
				swap_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorted)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorted = 0;
				p = p->prev;
				swap_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
