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

	new = list;

	while (new->next)
	{	
		new = new->next;
		if (*(&new) == *(&list))
		{
			return (1);
		}
		
	}
	return (0);
}
