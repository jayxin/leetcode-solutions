#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2319. 判断矩阵是否是一个 X 矩阵 - 如果一个正方形矩阵满足下述 全部 条件，则称 之为一个 X 矩阵 ：
//  1. 矩阵对角线上的所有元素都 不是 0
//  2. 矩阵中所有其他元素都是 0
// 给你一个大小为 n x n 的二维整数数组 grid ，表示一个正方形矩阵。如果 grid 是一个 X 矩阵 ，返回 true ；否则，返回 false 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2022/05/03/ex1.jpg]
// 输入：grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
// 输出：true
// 解释：矩阵如上图所示。
// X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
// 因此，grid 是一个 X 矩阵。
// 示例 2：
// [https://assets.leetcode.com/uploads/2022/05/03/ex2.jpg]
// 输入：grid = [[5,7,0],[0,3,1],[0,5,0]]
// 输出：false
// 解释：矩阵如上图所示。
// X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
// 因此，grid 不是一个 X 矩阵。
//  
// 提示：
//  * n == grid.length == grid[i].length
//  * 3 <= n <= 100
//  * 0 <= grid[i][j] <= 105

// #v1
bool checkXMatrix(int** grid, int gridSize, int* gridColSize) {
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (i == j || gridSize - i - 1 == j) {
        if (!grid[i][j]) return false;
      } else {
        if (grid[i][j]) return false;
      }
    }
  }

  return true;
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
  int n, **a;
  scanf("%d", &n);
  a = read_2d_arr(n, n);
  if (checkXMatrix(a, n, &n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
