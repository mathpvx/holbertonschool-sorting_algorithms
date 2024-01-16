#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sorts a double linked list with insertion sort
 * @list: the list of integers to sort
 */
void insertion_sort_list(listint_t **list)
{
	/** DEclarer deux variables de type node */
	listint_t *temp, *current;
	
	/** On s'zrrete si pas de node ou un seul*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	/** Parcourt la linked list à partir du deuxième élément jusqu'au dernier */
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		printf("FOR\n");
		/** initialiser temp à current */
		temp = current;

		/** tant que temp a un previous et que la valeur de temp est inférieure à son previous */
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/** START SWAP */
			/** pointeur de previous vers temp pointe maintenant next de temp */
			temp->prev->next = temp->next;
			
			/** Si temp a un next **/
			if (temp->next != NULL)
				/** Previous de next pointe maintenant vers previous de temp */
				temp->next->prev = temp->prev;
			
			/** next de temp pointe maintenant vers le previous de temp */
			temp->next = temp->prev;
			/** previous de temp pointe maintenant vers previous de previous*/
			temp->prev = temp->prev->prev;
			
			/** si temp a toujours un previous*/
			if (temp->prev != NULL)
				/** next de previous = temp*/
				temp->prev->next = temp;
			else
				/** temp est le premier listint_A */
				*list = temp;
			/** si temp a toujours un next */
			if (temp->next != NULL)
				/** previous de next pointe maintenant vers temp */
				temp->next->prev = temp;
			/** Print linkedlist a chaque swap */
			print_list(*list);

			/** END SWAP */
		}
	}
}
