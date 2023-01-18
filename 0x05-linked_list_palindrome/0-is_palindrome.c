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
 * check_palindrome - check recursively if a list is a palindrome
 * @node: node to check
 * @k: index to the node to check with node
 * Return: 1 if same, 0 if not
*/
int check_palindrome(listint_t *node, int k)
{
	listint_t *check;
	int i;
	int is_palindrome = 1;

	check = node;
	if (is_palindrome == 1 && k > 0)
	{
		for (i = 0; i < k; i++)
			check = check->next;
		if (node->n == check->n)
		{
			is_palindrome = check_palindrome(node->next, (k - 2));
		}
		else
			is_palindrome = 0;
	}
	return (is_palindrome);
}

/**
 * is_palindrome - checks if a listint_t list is a palindrome
 * @head : double pointer to the head of the list
 * Return: 1 if palindrome, 0 if not
*/
int is_palindrome(listint_t **head)
{
	size_t len = 0;

	if (*head == NULL || head == NULL)
		return (1);

	len = listint_len(*head);
	return (check_palindrome(*head, (len - 1)));
}
