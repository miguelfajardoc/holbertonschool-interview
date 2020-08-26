#ifndef SANDPILES
#define SADPILES

/*static void print_grid_sum(int grid1[3][3], int grid2[3][3]);
  static void print_grid(int grid[3][3]);*/
void copy_matrix(int from[3][3], int to[3][3]);
void make_topple(int grid[3][3], int i, int j);
void simple_sand_sum(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
