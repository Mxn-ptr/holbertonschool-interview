#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: poitner to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tr = malloc(sizeof(binary_tree_t));

	if (tr == NULL)
		return (NULL);

	tr->n = value;
	tr->parent = parent;
	tr->left = NULL;
	tr->right = NULL;

	return (tr);
}

/**
 * create_avl_tree - create the avl tree from a sorted array
 * @array: array
 * @start: point to start
 * @end: point to end
 * @parent: parent of the node
 *
 * Return: new node
*/
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{

	avl_t *new;
	size_t mid = (start + end) / 2;

	if (start > end)
		return (NULL);

	new = binary_tree_node(parent, array[mid]);
	new->left = create_avl_tree(array, start, mid - 1, new);
	new->right = create_avl_tree(array, mid + 1, end, new);
	return (new);
}

/**
 * sorted_array_to_avl - basic function to sorted array to avl tree
 * @array: array to used
 * @size: size of the array
 *
 * Return: new node
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	tree = create_avl_tree(array, 0, size - 1, NULL);
	if (!tree)
		return (NULL);
	return (tree);
}
