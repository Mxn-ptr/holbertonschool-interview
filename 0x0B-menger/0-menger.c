#include "menger.h"

/**
 * create_matrix - Create the matrix with the size
 * @size: size of the matrix
 *
 * Return: matrix
*/
char **create_matrix(int size)
{
	int i, j;
	char **matrix = malloc(size * sizeof(char *));

	for (i = 0; i < size; i++)
	{
		matrix[i] = malloc(size * sizeof(char));
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = '#';
		}
	}
	return (matrix);
}

/**
 * print_matrix - print the matrix
 * @matrix: matrix to print
 * @size: size of the matrix
*/
void print_matrix(char **matrix, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}

/**
 * recursion_menger - make hole for menger sponge
 * @matrix: matrix to transform
 * @size: size of the matrix
 * @new_size: new_size by level
*/
void recursion_menger(char **matrix, int size, int new_size)
{
	int i, j;

	if (new_size < 1)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((i / new_size) % 3 == 1 && (j / new_size) % 3 == 1)
				matrix[i][j] = ' ';
		}
	}
	recursion_menger(matrix, size, new_size / 3);
}

/**
 * free_matrix - free the matrix
 * @matrix: matrix to free
 * @size: size of the matrix
*/
void free_matrix(char **matrix, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

/**
 * menger - main function
 * @level: level of the menger sponge
*/
void menger(int level)
{
	int size = pow(3, level);
	char **matrix;
	int new_size = size / 3;

	matrix = create_matrix(size);
	recursion_menger(matrix, size, new_size);
	print_matrix(matrix, size);
	free_matrix(matrix, size);
}
