#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1351. 统计有序矩阵中的负数 - 给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还 是按列，都以非严格递减顺序排列。 请你统计并返回 grid 中 负数 的数目。
//  
// 示例 1：
// 输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// 输出：8
// 解释：矩阵中共有 8 个负数。
// 示例 2：
// 输入：grid = [[3,2],[1,0]]
// 输出：0
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 100
//  * -100 <= grid[i][j] <= 100
//  
// 进阶：你可以设计一个时间复杂度为 O(n + m) 的解决方案吗？

// #v1
int countNegatives(int** grid, int gridSize, int* gridColSize) {
  int c = 0;

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < *gridColSize; j++) {
      if (grid[i][j] < 0) ++c;
    }
  }

  return c;
}
// #v1

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n, **a, m;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  printf("%d\n", countNegatives(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
