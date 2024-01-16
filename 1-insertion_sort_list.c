#include "sort.h"
/**
 * insertion_sort_list - sorts a double linked list with insertion sort
 * @list: the list of integers to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;

	while ((*list)->next != NULL)
	{
		while ((*list)->prev != NULL)
		{
			if ((*list)->n < (*list)->prev->n)
			{
				temp = *list;
				temp->n = (*list)->n;
				*list = (*list)->prev;
				(*list)->prev = temp;
				print_list(*list);
			}
			(*list)->prev = (*list)->prev->prev;
		}
		*list = (*list)->next;
	}
}
