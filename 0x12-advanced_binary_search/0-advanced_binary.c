#include "search_algos.h"

/**
 * print_array - print the array
 * @array: array
 * @start: start to print
 * @end: end of to print
*/
void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");

	for (i = start; i < end; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);
}

/**
 * advanced_binary_recurs - search with recursion
 * @array: array to search in
 * @start: index to start
 * @end: index to end
 * @value: value to found
 *
 * Return: index of value or -1
*/
int advanced_binary_recurs(int *array, int start, int end, int value)
{
	int middle = (end - start) / 2 + start;

	print_array(array, start, end);

	if (start == end)
		return (-1);
	if (array[middle] == value && array[middle - 1] != value)
		return (middle);

	if (array[middle] >= value)
	{
		return (advanced_binary_recurs(array, start, middle, value));
	}
	if (array[middle] <= value)
	{
		return (advanced_binary_recurs(array, middle + 1, end, value));
	}
	return (-1);
}

/**
 * advanced_binary - search with recursion
 * @array: array to search in
 * @size: size of the array
 * @value: value to found
 *
 * Return: index of value or -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	return (advanced_binary_recurs(array, 0, size - 1, value));
}
