#include "search.h"

/**
 * linear_skip - Search into a skip list
 * @head: head of the list
 * @value: value to find
 *
 * Return: node found else NULL
*/
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *current, *previous;

	if (!head)
		return (NULL);

	current = head;

	while (current && current->next && current->n < value)
	{
		previous = current;
		if (!current->express)
		{
			while (current->next)
				current = current->next;
			continue;
		}
		else
			current = current->express;
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			previous->index, current->index);
	while (previous != current->next)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			previous->index, previous->n);
		if (value == previous->n)
			return (previous);
		previous = previous->next;
	}
	return (NULL);
}
