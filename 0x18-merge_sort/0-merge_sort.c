#include "sort.h"

/**
 * merge - sort and merge the two array
 * @array: array to sort
 * @size: size of the array
 * @middle: middle of the array
 * @copy: copy of the array
*/
void merge(int *array, int size, int middle, int *copy)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);

	for (i = 0, j = middle, k = 0; k < size; k++)
	{
		if (j == size)
		{
			copy[k] = array[i];
			i++;
		}
		else if (i == middle)
		{
			copy[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			copy[k] = array[j];
			j++;
		}
		else
		{
			copy[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = copy[i];
	}
	printf("[Done]: ");
	print_array(copy, size);
}

/**
 * separate - separate the array
 * @array: array to separate
 * @size: size of the array
 * @copy: copy of the array
*/
void separate(int *array, size_t size, int *copy)
{
	int middle = size / 2;

	if (size < 2)
		return;

	separate(array, middle, copy);
	separate(array + middle, size - middle, copy);
	merge(array, size, middle, copy);
}

/**
 * merge_sort - sorts an array of integer in ascending order
 * using the Merge Sort algorithm
 * @array: array to sort
 * @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;

	if (!array || size <= 1)
		return;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	separate(array, size, copy);
	free(copy);
}
