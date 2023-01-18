#include "lists.h"

/**
 * check_palindrome - check recursively if a list is a palindrome
 * @node: node to check
 * @k: index to the node to check with node
 * Return: 1 if same, 0 if not
*/
int check_palindrome(listint_t **node, listint_t *next)
{
	int is_palindrome = 1;

	if (next == NULL)
		return (1);

	is_palindrome = check_palindrome(node, next->next);
	
	if (is_palindrome == 0)
		return (0);

	is_palindrome = ((*node)->n == next->n);

	(*node) = (*node)->next;

	return (is_palindrome);
}

/**
 * is_palindrome - checks if a listint_t list is a palindrome
 * @head : double pointer to the head of the list
 * Return: 1 if palindrome, 0 if not
*/
int is_palindrome(listint_t **head)
{
	if (*head == NULL || head == NULL)
		return (1);
	return (check_palindrome(head, *head));
}
