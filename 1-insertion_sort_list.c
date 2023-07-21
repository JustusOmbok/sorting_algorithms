#include "sort.h"
/**
 * insertion_sort_list - a doubly linked list is sorted using insertion sort
 * @list: doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current;
	listint_t *temp;

	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next->prev = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
