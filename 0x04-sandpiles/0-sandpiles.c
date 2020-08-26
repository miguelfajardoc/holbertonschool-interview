#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - function that print a grid
 * @grid: the first sandpile
 * Return: none
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * sandpiles_sum - function that computes the sum of two sandpiles 3*3
 * @grid1: the first sandpiles
 * @grid2: the second sandpiles
 * Return: none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int flag = 0;
	int iter_matrix[3][3];

	simple_sand_sum(grid1, grid2);
	copy_matrix(grid1, iter_matrix);
	do {
		flag = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (flag == 0)
					{
						printf("=\n");
						print_grid(grid1);
						flag++;
					}
					make_topple(iter_matrix, i, j);
					flag = 1;
				}
			}
		}
		copy_matrix(iter_matrix, grid1);
	} while (flag);
}

/**
 * copy_matrix - function that copy the data of the first matrix into the
 * second that have 3x3 dimension
 * @matrix1: the first matrix
 * @matrix2: the second matrix
 * Return: none
 */
void copy_matrix(int matrix1[3][3], int matrix2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matrix2[i][j] = matrix1[i][j];
		}
	}
}


/**
 * simple_sand_sum - function that computes the sum of two sandpiles 3*3
 * without topple
 * @grid1: the first sandpiles
 * @grid2: the second sandpiles
 * Return: none
 */
void simple_sand_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * make_topple - function that computes a sand topple
 * @grid: the first sandpiles
 * @i: the row index
 * @j: the column index
 * Return: none
 */
void make_topple(int grid[3][3], int i, int j)
{
	/* printf("mod grid[%d][%d]: %d\n", i, j, grid[i][j]); */
	/* print_grid(grid); */
	grid[i][j] -= 4;

	if (i + 1 < 3)
	{
		/* printf("abajo\n"); */
		grid[i + 1][j]++;
	}
	if (i - 1 >= 0)
	{
		/* //printf("arriba\n"); */
		grid[i - 1][j]++;
	}
	if (j + 1 < 3)
	{
		/* //printf("der\n"); */
		grid[i][j + 1]++;
	}
	if (j - 1 >= 0)
	{
		/* //printf("izq\n"); */
		grid[i][j - 1]++;
	}

}
