#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

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


	simple_sand_sum(grid1, grid2);
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
					make_topple(grid1, i, j);
					flag = 1;
				}
			}
		}
		/* if (flag == 1) */
		/* { */
		/* 	printf("=\n"); */
		/* 	print_grid(grid1); */
		/* } */
	} while (flag);
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
	grid[i][j] -= 4;
	/*printf("mod grid[%d][%d]: %d\n", i, j, grid[i][j]);*/
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
