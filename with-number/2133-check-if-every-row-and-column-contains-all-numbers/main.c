#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2133. 检查是否每一行每一列都包含全部整数 - 对一个大小为 n x n 的矩阵而言，如果其每一行和每一列都包含从 1 到 n 的 全部 整数（含 1 和 n），则认为该矩阵是一个 有效 矩阵。
// 给你一个大小为 n x n 的整数矩阵 matrix ，请你判断矩阵是否为一个有效矩阵：如果是，返回 true ；否则，返回 false 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/12/21/example1drawio.png]
// 输入：matrix = [[1,2,3],[3,1,2],[2,3,1]]
// 输出：true
// 解释：在此例中，n = 3 ，每一行和每一列都包含数字 1、2、3 。
// 因此，返回 true 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/12/21/example2drawio.png]
// 输入：matrix = [[1,1,1],[1,2,3],[1,2,3]]
// 输出：false
// 解释：在此例中，n = 3 ，但第一行和第一列不包含数字 2 和 3 。
// 因此，返回 false 。
//  
// 提示：
//  * n == matrix.length == matrix[i].length
//  * 1 <= n <= 100
//  * 1 <= matrix[i][j] <= n

// #v1
typedef unsigned char u_char;

#define IS_BIT_SET(a, i, j) ((a)[(i)] & (1<<(j)))
#define SET_BIT(a, i, j) \
  do { \
    (a)[(i)] |= 1 << (j); \
  } while(0)

bool checkValid(int** matrix, int matrixSize, int* matrixColSize) {
  int n = matrixSize, bitMapSize = (n>>3) + 1, i, j, k;
  u_char bitMap[bitMapSize];

  for (i = 0; i < n; i++) {
    for (k = 0; k < bitMapSize; k++) bitMap[k] = 0;

    for (j = 0; j < n; j++) {
      int byteIdx = matrix[i][j] >> 3, bitIdx = matrix[i][j] & 7;

      if (IS_BIT_SET(bitMap, byteIdx, bitIdx)) return false;
      SET_BIT(bitMap, byteIdx, bitIdx);
    }
  }

  for (j = 0; j < n; j++) {
    for (k = 0; k < bitMapSize; k++) bitMap[k] = 0;

    for (int i = 0; i < n; i++) {
      // /8 %8
      int byteIdx = matrix[i][j] >> 3, bitIdx = matrix[i][j] & 7;

      if (IS_BIT_SET(bitMap, byteIdx, bitIdx)) return false;
      SET_BIT(bitMap, byteIdx, bitIdx);
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
  int **a, n;
  scanf("%d", &n);
  a = read_2d_arr(n, n);
  if (checkValid(a, n, &n))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
