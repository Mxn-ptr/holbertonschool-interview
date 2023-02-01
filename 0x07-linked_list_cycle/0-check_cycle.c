#include "lists.h"

/**
 * check_cycle - check if a single linked list has a cycle or not
 * @list: pointer to the head of the list
 * 
 * Return: 1 if is true, 0 otherwise
*/
int check_cycle(listint_t *list)
{
	listint_t *new;

	if (list == NULL || list->next == NULL)
		return (0);

	list = list->next;
	new = list->next->next;

	while (list && new && new->next)
	{	
		if (list == new->next)
			return (1);
		list = list->next;
		new = new->next->next;
	}
	return (0);
}
