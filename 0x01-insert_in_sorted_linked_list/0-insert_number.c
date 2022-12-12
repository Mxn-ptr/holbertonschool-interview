#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the address of the head of the list
 * @number: number to insert
 * Return: adress of the new element, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *tmp = *head;

	if (head == NULL || *head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	while (tmp->next && tmp->next->n < number)
		tmp = tmp->next;

	if (tmp == *head)
	{
		new->next = tmp;
		*head = new;
	} else
	{
		new->next = tmp->next;
		tmp->next = new;
	}
	return (new);
}
