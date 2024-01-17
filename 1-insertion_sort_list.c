#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list with insertion sort
 * @list: the list of integers to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
			{
				temp->prev->next = temp;
			}
			else
				*list = temp;
			if (temp->next != NULL)
				temp->next->prev = temp;
			print_list(*list);
		}
	}
}
