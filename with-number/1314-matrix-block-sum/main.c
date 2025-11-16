#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1314. 矩阵 区域和 - 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中 每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和： 
//  * i - k <= r <= i + k,
//  * j - k <= c <= j + k 且
//  * (r, c) 在矩阵内。
//  
// 示例 1：
// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// 输出：[[12,21,16],[27,45,33],[24,39,28]]
// 示例 2：
// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// 输出：[[45,45,45],[45,45,45],[45,45,45]]
//  
// 提示：
//  * m == mat.length
//  * n == mat[i].length
//  * 1 <= m, n, k <= 100
//  * 1 <= mat[i][j] <= 100

// #v1
// 2d prefix sum, matrix, inclusion-exclusion principle
int min(int a, int b) { return a <= b ? a : b; }
int max(int a, int b) { return a >= b ? a : b; }

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {
  int m = matSize, n = *matColSize;
  int **ret = malloc(m * sizeof(int *));
  int prefixSum[m+1][n+1];

  *returnSize = m;
  *returnColumnSizes = malloc(m * sizeof(int));
  for (int i = 0; i < m; i++) {
    ret[i] = malloc(n * sizeof(int));
    (*returnColumnSizes)[i] = n;
  }

  // compute 2d prefix sum
  // init, first row
  prefixSum[0][0] = 0;
  for (int j = 0; j < n; j++) {
    prefixSum[0][j+1] = 0;
  }
  prefixSum[1][0] = 0;
  for (int j = 0; j < n; j++) {
    prefixSum[1][j+1] = prefixSum[1][j] + mat[0][j];
  }
  // compute
  for (int i = 1; i < m; i++) {
    prefixSum[i+1][0] = 0;

    for (int j = 0; j < n; j++) {
      prefixSum[i+1][j+1] = prefixSum[i][j+1] + prefixSum[i+1][j] -
        prefixSum[i][j] + mat[i][j];
    }
  }

  // [i-k][j-k]
  // + [i+k][j+k]
  // - [i-k-1][j+k]
  // - [i+k][j-k-1]
  // + [i-k-1][j-k-1]
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // prefixSum[i+k+1][j+k+1] - prefixSum[i-k][j+k+1] - prefixSum[i+k+1][j-k] + prefixSum[i-k][j-k]
      int a = min(i+k+1, m), b = min(j+k+1, n),
          c = max(i-k, 0), d = max(j-k, 0);
      ret[i][j] = prefixSum[a][b] - prefixSum[c][b] - prefixSum[a][d] +
        prefixSum[c][d];
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
  int **mat, matSize, matColSize, k, **ret, returnSize, *returnColumnSizes;
  scanf("%d%d", &matSize, &matColSize);
  mat = read_2d_arr(matSize, matColSize);
  scanf("%d", &k);
  ret = matrixBlockSum(mat, matSize, &matColSize, k, &returnSize,
      &returnColumnSizes);
  print_2d_arr(ret, returnSize, returnColumnSizes);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
