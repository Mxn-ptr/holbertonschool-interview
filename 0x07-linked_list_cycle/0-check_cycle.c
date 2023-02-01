#include "lists.h"

/**
 * check_cycle - check if a single linked list has a cycle or not
 * @list: pointer to the head of the list
 * 
 * Return: 1 if is true, 0 otherwise
*/
int check_cycle(listint_t *list)
{
	listint_t *turtle;
	listint_t *rabbit;

	if (list == NULL || list->next == NULL)
		return (0);

	turtle = list->next;
	rabbit = list->next->next;

	while (turtle && rabbit && rabbit->next)
	{	
		if (turtle == rabbit->next)
			return (1);
		turtle = turtle->next;
		rabbit = rabbit->next->next;
	}
	return (0);
}
