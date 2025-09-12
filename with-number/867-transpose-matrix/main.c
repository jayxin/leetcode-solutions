#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 867. 转置矩阵 - 给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。
// 矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
// [https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png]
//  
// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[1,4,7],[2,5,8],[3,6,9]]
// 示例 2：
// 输入：matrix = [[1,2,3],[4,5,6]]
// 输出：[[1,4],[2,5],[3,6]]
//  
// 提示：
//  * m == matrix.length
//  * n == matrix[i].length
//  * 1 <= m, n <= 1000
//  * 1 <= m * n <= 105
//  * -10^9 <= matrix[i][j] <= 10^9

// #v1
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
  int m = matrixSize, n = *matrixColSize, i, j;
  *returnSize = n;

  int **ret = (int **)malloc(sizeof(int *) * n);
  *returnColumnSizes = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    ret[i] = (int *)malloc(sizeof(int) * m);
    (*returnColumnSizes)[i] = m;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      ret[i][j] = matrix[j][i];
    }
  }

  return ret;
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

void print_2d_arr(int **arr, int rows, int *cols) {
  if (!arr || rows <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols[i]; j++) {
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
  int m, n, **a, **ret, rows, *cols;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  ret = transpose(a, m, &n, &rows, &cols);
  print_2d_arr(ret, rows, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
