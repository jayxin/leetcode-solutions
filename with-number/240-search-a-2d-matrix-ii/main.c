#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 240. 搜索二维矩阵 II - 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//  * 每行的元素从左到右升序排列。
//  * 每列的元素从上到下升序排列。
//  
// 示例 1：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/searchgrid2.jpg]
// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// 输出：true
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/searchgrid.jpg]
// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// 输出：false
//  
// 提示：
//  * m == matrix.length
//  * n == matrix[i].length
//  * 1 <= n, m <= 300
//  * -109 <= matrix[i][j] <= 109
//  * 每行的所有元素从左到右升序排列
//  * 每列的所有元素从上到下升序排列
//  * -109 <= target <= 109

// #v1
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
  int l, r, m, t, end = *matrixColSize - 1;

  for (int i = 0; i < matrixSize; i++) {
    if (target >= matrix[i][0] && target <= matrix[i][end]) {
      l = 0, r = end;

      while (l < r) {
        m = (l + r) >> 1;

        if (matrix[i][m] == target) {
          return true;
        } else if (matrix[i][m] < target) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      if (matrix[i][l] == target) return true;
    }
  }

  return false;
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
  int n, m, t, **a;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  scanf("%d", &t);
  if (searchMatrix(a, m, &n, t))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
