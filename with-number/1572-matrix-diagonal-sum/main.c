#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1572. 矩阵对角线元素的和 - 给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
// 请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
//  
// 示例  1：
// [https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png]
// 输入：mat = [[1,2,3],
//             [4,5,6],
//             [7,8,9]]
// 输出：25
// 解释：对角线的和为：1 + 5 + 9 + 3 + 7 = 25
// 请注意，元素 mat[1][1] = 5 只会被计算一次。
// 示例  2：
// 输入：mat = [[1,1,1,1],
//             [1,1,1,1],
//             [1,1,1,1],
//             [1,1,1,1]]
// 输出：8
// 示例 3：
// 输入：mat = [[5]]
// 输出：5
//  
// 提示：
//  * n == mat.length == mat[i].length
//  * 1 &lt;= n &lt;= 100
//  * 1 &lt;= mat[i][j] &lt;= 100

// #v1
int diagonalSum(int** mat, int matSize, int* matColSize) {
  int sum = 0, t;
  for (int i = 0; i < matSize; i++) {
    sum += mat[i][i];
    t = matSize - i - 1;
    if (i != t) sum += mat[i][t];
  }
  return sum;
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
  printf("%d\n", diagonalSum(a, n, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
