#include "binary_trees.h"

/**
 * swap - Swap the value of two nodes
 * @first: first node to swap
 * @second: second node to swap
*/
void swap(heap_t *first, heap_t *second)
{
	int tmp = first->n;

	first->n = second->n;
	second->n = tmp;
}


/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * to measure the size
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * find_last_nodes - find the last node
 * @root: pointer to the head of the binary tree
 *
 * Return: pointer to the last node or NULL if fail
*/
heap_t *find_last_nodes(heap_t *root)
{
	int nodes = 0, size = 0;
	heap_t *last_node;

	if (!root || size == 0)
		return (0);

	size = binary_tree_size(root);

	for (nodes = 1; nodes <= size; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_node = root; nodes > 0; nodes >>= 1)
	{
		if (size & nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}

/**
 * heapify - rebuilt the binary max heap
 * @root: double pointer to the root
*/
void heapify(heap_t **root)
{
	heap_t *max = *root;
	heap_t *left = (*root)->left;
	heap_t *right = (*root)->right;

	if (left && left->n > max->n)
		max = left;
	if (right && right->n > max->n)
		max = right;

	if (max != *root)
	{
		swap(*root, max);
		heapify(&max);
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int extracted = (*root)->n;

	if (!root || !(*root))
		return (0);

	last_node = find_last_nodes(*root);
	swap(*root, last_node);

	if (last_node->n == last_node->parent->left->n)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	heapify(root);

	return (extracted);
}
