#include "lists.h"

/**
 * find_listint_loop - Find if the list has a loop
 * @head: pointer to the head of the list
 *
 * Return: pointer to the start of the loop or NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	slow = head;
	fast = slow;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow && fast)
			{
				if (slow == fast)
					return (slow);
				slow = slow->next;
				fast = fast->next;
			}
		}
	}
	return (NULL);
}
