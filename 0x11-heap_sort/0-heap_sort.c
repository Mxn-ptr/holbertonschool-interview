#include "sort.h"

/**
 * swap - Swap two elements of the array
 * @array: array to swaped
 * @first: first index
 * @second: second index
*/
void swap(int *array, int first, int second)
{
	int tmp = array[first];

	array[first] = array[second];
	array[second] = tmp;
}

/**
 * heapify - Make a heap from the array
 * @array: array
 * @n: size of the array
 * @i: index of root
 * @size: size of the array
*/
void heapify(int *array, int n, int i, size_t size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[max])
		max = left;

	if (right < n && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(array, i, max);
		print_array(array, size);
		heapify(array, n, max, size);
	}
}

/**
 * heap_sort - Sort an array using heap sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
