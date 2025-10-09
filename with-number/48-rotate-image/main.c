#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 48. 旋转图像 - 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
// 你必须在 原地 [https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95] 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg]
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg]
// 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
//  
// 提示：
//  * n == matrix.length == matrix[i].length
//  * 1 &lt;= n &lt;= 20
//  * -1000 &lt;= matrix[i][j] &lt;= 1000

// #v1
// transpose the matrix and reverse each line
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
  int m = matrixSize, n = *matrixColSize;
  int t, *a, h = n >> 1;

  // transpose the matrix
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < n; j++) {
      t = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = t;
    }
  }

  // reverse each line
  for (int i = 0; i < m; i++) {
    a = matrix[i];

    for (int j = 0; j < h; j++) {
      t = a[j];
      a[j] = a[n - j - 1];
      a[n - j - 1] = t;
    }
  }
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
  int m, n, **a;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  rotate(a, m, &n);
  print_2d_arr(a, m, n);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
