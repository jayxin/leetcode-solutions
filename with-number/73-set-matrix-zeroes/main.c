#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 73. 矩阵置零 - 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 [http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95] 算法。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg]
// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg]
// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//  
// 提示：
//  * m == matrix.length
//  * n == matrix[0].length
//  * 1 <= m, n <= 200
//  * -231 <= matrix[i][j] <= 231 - 1
//  
// 进阶：
//  * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//  * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//  * 你能想出一个仅使用常量空间的解决方案吗？

// #v1
// 把需要置 0 的行在行首做标记, 把需要置 0 的列在列首做标记
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
  int i, j, m = matrixSize, n = *matrixColSize;
  char r = 0, c = 0;

  // init 第 1 行和第 1 列特殊处理
  // 检查第 1 列是否存在 0
  for (i = 0; i < m; i++) {
    if (!matrix[i][0]) {
      r = 1;
      break;
    }
  }
  // 检查第 1 行是否存在 0
  for (j = 0; j < n; j++) {
    if (!matrix[0][j]) {
      c = 1;
      break;
    }
  }

  // 做标记
  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      if (!matrix[i][j]) {
        // 行首做标记, 列首做标记
        matrix[i][0] = matrix[0][j] = 0;
      }
    }
  }

  // 先将非首行、非首列元素置 0
  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      if (matrix[i][j]) {
        if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
      }
    }
  }

  // 第 1 列有 0 则将第 1 列置 0
  if (r)
    for (i = 0; i < m; i++) matrix[i][0] = 0;

  // 第 1 行有 0 则将第 1 行置 0
  if (c)
    for (j = 0; j < n; j++) matrix[0][j] = 0;
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

void print_2d_arr(int **arr, int rows, int cols) {
  if (!arr || rows <= 0 || cols <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

int main(int argc, char *argv[])
{
  int n, m, **a;

  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  setZeroes(a, m, &n);
  print_2d_arr(a, m, n);

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
