#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * node_swap_code - Code used in a listint_t doubly-linked list to swap them.
 * @h: Used to point to the head of the doubly-linked list.
 * @n1: Used to pointer to the first node to swap in the double-linked list.
 * @n2: Used to point to the second node to swap in the double-linked list.
 */
void node_swap_code(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of data indexes
 *
 * @list: Used to point to the head of a doubly-linked list of data indexes.
 *
 * Description: Prints the list after each successful data index swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			node_swap_code(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
