#include "slide_line.h"
#include <stdio.h>

/**
 * merge_left - merge to the left
 * @line: line to merge
 * @size: size of the line
*/
void merge_left(int *line, size_t size)
{
	size_t i = 0, j;

	while (i < size)
	{
		while (line[i] == 0)
			i++;
		j = i;
		i++;
		while (line[i] == 0)
			i++;
		if (line[j] == line[i])
		{
			line[j] *= 2;
			line[i] = 0;
		}
	}
}

/**
 * slide_left - slide to the left
 * @line: line to slide
 * @size: size of the line
*/
void slide_left(int *line, size_t size)
{
	size_t i = 0, j = 0;

	while (i < size)
	{
		i = 0;
		while (line[i] != 0 && i < size)
			i++;
		if (i >= size)
			return;
		j = i;
		while (line[i] == 0 && i < size - 1)
			i++;
		line[j] = line[i];
		line[i] = 0;
		i++;
	}
}

/**
 * merge_right: merge to the right
 * @line: line to merge
 * @size: size of the line
*/
void merge_right(int *line, size_t size)
{
	size_t i = size - 1, j;

	while (i > 0)
	{
		while (line[i] == 0 && i > 0)
			i--;
		j = i;
		if (i > 0)
		{
			i--;
			while (line[i] == 0 && i > 0)
				i--;
			if (line[j] == line[i])
			{
				line[j] *= 2;
				line[i] = 0;
			}
		}
	}
}

/**
 * slide_right - slide to the right
 * @line: line to slide
 * @size: size of the line
*/
void slide_right(int *line, size_t size)
{
	size_t i = 1, j;

	while (i > 0)
	{
		i = size - 1;
		while (line[i] != 0 && i > 0)
			i--;
		if (i <= 0)
			return;
		j = i;
		while (line[i] == 0 && i > 0)
			i--;
		line[j] = line[i];
		line[i] = 0;
	}
}

/**
 * slide_line - 2048 single line function
 * @line: line of the 2048 game
 * @size: size of the line
 * @direction: direction to merge and slide
 *
 * Return: 1 if ok, else 0
*/
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (!line)
		return (0);
	if (size < 2)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		merge_left(line, size);
		slide_left(line, size);
	}

	if (direction == SLIDE_RIGHT)
	{
		merge_right(line, size);
		slide_right(line, size);
	}
	return (1);
}
