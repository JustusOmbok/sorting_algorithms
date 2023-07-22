#include "sort.h"
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * swap_nodes - two nodes are swapped
 * @list: doubly linked list head pointer
 * @node1: first node
 * @node2: second node
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

	if (node1->next)
		node1->next->prev = node1;

	if (node2->prev)
		node2->prev->next = node2;
}

/**
 * cocktail_sort_list - doubly linked list is sorted
 * @list: doubly linked list pointer
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		start = *list;
		end = NULL;

		while (start->next != end)
		{
			current = start;
			while (current->next != end)
			{
				if (current->n > current->next->n)
				{
					swap_nodes(list, current, current->next);
					swapped = 1;
					print_list(*list);
				}
				else
					current = current->next;
			}
			end = current;
		}

		if (!swapped)
			break;

		swapped = 0;
		end = current->prev;
		while (end != start)
		{
			current = end;
			while (current != start)
			{
				if (current->n < current->prev->n)
				{
					swap_nodes(list, current->prev, current);
					swapped = 1;
					print_list(*list);
				}
				else
					current = current->prev;
			}
			start = current->next;
		}

	} while (swapped);
}

