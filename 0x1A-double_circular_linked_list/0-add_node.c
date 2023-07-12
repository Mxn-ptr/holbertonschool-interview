#include "list.h"

/**
 * add_node_end - Add a node at the end of a circular list linked
 * @list: pointer to the head of the list
 * @str: string to add
 *
 * Return: pointer to the new node or NULL if fail
*/
List *add_node_end(List **list, char *str)
{
	List *new;
	char *cpy = strdup(str);

	if (cpy == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = cpy;

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		(*list) = new;
	}
	else
	{
		new->next = (*list);
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (new);
}

/**
 * add_node_begin - Add a node at the start of a circular list linked
 * @list: pointer to the head of the list
 * @str: string to add
 *
 * Return: pointer to the new node or NULL if fail
*/
List *add_node_begin(List **list, char *str)
{
	List *new;
	char *cpy = strdup(str);

	if (cpy == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = cpy;

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		(*list) = new;
	}
	else
	{
		new->next = (*list);
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		(*list) = new;
	}
	return (new);
}
