#include "sandpiles.h"

/**
 * sum - sums two sandpiles
 * @grid1: sandpile, 3x3 matrix
 * @grid2: second sandpile, which will be 0 at then end
 */
static void sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;

}

/**
 * is_stable - checks if snadpile is stable
 * @grid: sandpile, 3x3 matrix
 * Return: 1 if stable, 0 otherwise
*/
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - Prints the grid
 * @grid: sandpile, 3x3 matrix
 * Return: 1 if stable, 0 otherwise
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
 * topple - Topples sandpile
 * @grid1: First main sandpile
 * @grid2: Second sandpile
 */
static void topple(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid2[i - 1][j]++;
				if (i + 1 < 3)
					grid2[i + 1][j]++;

				if (j - 1 >= 0)
					grid2[i][j - 1]++;
				if (j + 1 < 3)
					grid2[i][j + 1]++;
			}
}

/**
 * sandpiles_sum - Sums and topples two sandpiles
 * @grid1: First main sandpile
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1, grid2);
		sum(grid1, grid2);
	}
}
