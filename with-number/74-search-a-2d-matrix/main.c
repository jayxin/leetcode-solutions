#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 74. 搜索二 维矩阵 - 给你一个满足下述两条属性的 m x n 整数矩阵：
//  * 每行中的整数从左到右按非严格递增顺序排列。
//  * 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/10/05/mat.jpg]
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 输出：true
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/mat2.jpg]
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// 输出：false
//  
// 提示：
//  * m == matrix.length
//  * n == matrix[i].length
//  * 1 <= m, n <= 100
//  * -104 <= matrix[i][j], target <= 104

// #v1
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
  int l, r, m, t;

  // binary search, find upper bound
  l = 0, r = matrixSize - 1;
  while (l < r) {
    m = (l + r + 1) >> 1;

    if (matrix[m][0] <= target) l = m;
    else r = m - 1;
  }

  t = l;
  if (matrix[t][0] == target) return true;

  // binary search, find target
  l = 0, r = *matrixColSize - 1;
  while (l < r) {
    m = (l + r) >> 1;

    if (matrix[t][m] == target) return true;
    else if (matrix[t][m] < target) l = m + 1;
    else r = m - 1;
  }

  if (matrix[t][l] == target) return true;

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
