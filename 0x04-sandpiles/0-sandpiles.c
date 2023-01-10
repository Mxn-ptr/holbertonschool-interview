#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_grids - add grind2 to grind1
 * @grid1: first grid
 * @grid2: second grid
*/
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * is_stable - looks if a grid is stable or not
 * @grid: grid to look
 * Return: 1 if stable 0 otherwise
*/
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int gridx[3][3];

	add_grids(grid1, grid2);


	while (!is_stable(grid1))
	{
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				gridx[i][j] = 0;
			}
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;

					if (i - 1 >= 0)
						gridx[i - 1][j] += 1;
					if (j + 1 < 3)
						gridx[i][j + 1] += 1;
					if (i + 1 < 3)
						gridx[i + 1][j] += 1;
					if (j - 1 >= 0)
						gridx[i][j - 1] += 1;
				}
			}
		}
		add_grids(grid1, gridx);
	}

}
