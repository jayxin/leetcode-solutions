#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1380.  矩阵中的幸运数 - 给你一个 m x n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序 返回矩阵中的所有幸运数。
// 幸运数 是指矩阵中满足同时下列两个条件的元素：
//  * 在同一行的所有元素中最小
//  * 在同一列的所有元素中最大
//  
// 示例 1：
// 输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
// 输出：[15]
// 解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
// 示例 2：
// 输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// 输出：[12]
// 解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
// 示例 3：
// 输入：matrix = [[7,8],[1,2]]
// 输出：[7]
// 解释：7 是唯一的幸运数字，因为它是行中的最小值，列中的最大值。
//  
// 提示：
//  * m == mat.length
//  * n == mat[i].length
//  * 1 <= n, m <= 50
//  * 1 <= matrix[i][j] <= 105
//  * 矩阵中的所有元素都是不同的

// #v1
int max(int a, int b) {
  return a >= b ? a : b;
}

int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int m = matrixSize, n = *matrixColSize;
  int rowsMin[m], colsMax[n], *ret, retLen = 0;

  for (int i = 0; i < m; i++) {
    int v = matrix[i][0];
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] < v) v = matrix[i][j];
    }
    rowsMin[i] = v;
  }

  for (int j = 0; j < n; j++) {
    int v = matrix[0][j];
    for (int i = 1; i < m; i++) {
      if (matrix[i][j] > v) v = matrix[i][j];
    }
    colsMax[j] = v;
  }

  ret = malloc(sizeof(int) * max(m, n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == rowsMin[i] && matrix[i][j] == colsMax[j])
        ret[retLen++] = matrix[i][j];
    }
  }

  *returnSize = retLen;

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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int **matrix, matrixSize, matrixColSize, *ret, returnSize;
  scanf("%d%d", &matrixSize, &matrixColSize);
  matrix = read_2d_arr(matrixSize, matrixColSize);
  ret = luckyNumbers(matrix, matrixSize, &matrixColSize, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
