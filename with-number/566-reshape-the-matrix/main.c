#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 566. 重塑矩阵 - 在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一 个大小不同（r x c）的新矩阵，但保留其原始数据。
// 给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的 重构的矩阵的行数和列数。
// 重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
// 如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg]
// 输入：mat = [[1,2],[3,4]], r = 1, c = 4
// 输出：[[1,2,3,4]]
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg]
// 输入：mat = [[1,2],[3,4]], r = 2, c = 4
// 输出：[[1,2],[3,4]]
//  
// 提示：
//  * m == mat.length
//  * n == mat[i].length
//  * 1 <= m, n <= 100
//  * -1000 <= mat[i][j] <= 1000
//  * 1 <= r, c <= 300
// Do you know how 2d matrix is stored in 1d memory? Try to map 2-dimensions
// into one.
// M[i][j]=M[n*i+j] , where n is the number of cols. This is the one way of
// converting 2-d indices into one 1-d index. Now, how will you convert 1-d
// index into 2-d indices?
// Try to use division and modulus to convert 1-d index into 2-d indices.
// M[i] => M[i/n][i%n] Will it result in right mapping? Take some example and
// check this formula.

// #v1
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
  int m = matSize, n = *matColSize;

  if (m * n != r * c) {
    *returnSize = m;
    *returnColumnSizes = calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
      (*returnColumnSizes)[i] = n;
    }
    return mat;
  }

  *returnSize = r;
  *returnColumnSizes = calloc(r, sizeof(int));
  int **ret = calloc(r, sizeof(int *));

  for (int i = 0; i < r; i++) {
    ret[i] = calloc(c, sizeof(int));
    (*returnColumnSizes)[i] = c;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int t = i * n + j;
      ret[t/c][t%c] = mat[i][j];
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
  int m, n, r, c, **ret, **a, s, *cols;
  scanf("%d%d", &r, &c);
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  ret = matrixReshape(a, m, &n, r, c, &s, &cols);
  print_2d_arr(ret, s, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
