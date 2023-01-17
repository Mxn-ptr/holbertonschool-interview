#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h : pointer to the head of the list
 * Return: number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}

/**
 * is_palindrome - checks if a listint_t list is a palindrome
 * @head : double pointer to the head of the list
 * Return: 1 if palindrome, 0 if not
*/
int is_palindrome(listint_t **head)
{
	listint_t *front, *rear;
	size_t len = 0, i = 0, j;


	if ((*head) == NULL || head == NULL)
		return (1);

	len = listint_len(*head);

	while (i != len / 2)
	{
		front = rear = *head;
		for (j = 0; j < i; j++)
		{
			front = front->next;
		}
		for (j = 0; j < len - (i + 1); j++)
		{
			rear = rear->next;
		}
		if (front->n == rear->n)
			i++;
		else
			return (0);
	}

	return (1);
}
