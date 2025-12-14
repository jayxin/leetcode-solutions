#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2643. 一最 多的行 - 给你一个大小为 m x n 的二进制矩阵 mat ，请你找出包含最多 1 的行的下标（ 从 0 开始）以及这一行中 1 的数目。
// 如果有多行包含最多的 1 ，只需要选择 行下标最小 的那一行。
// 返回一个由行下标和该行中 1 的数量组成的数组。
//  
// 示例 1：
// 输入：mat = [[0,1],[1,0]]
// 输出：[0,1]
// 解释：两行中 1 的数量相同。所以返回下标最小的行，下标为 0 。该行 1 的数量为 1 。 所以，答案为 [0,1] 。
// 示例 2：
// 输入：mat = [[0,0,0],[0,1,1]]
// 输出：[1,2]
// 解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。
// 示例 3：
// 输入：mat = [[0,0],[1,1],[0,0]]
// 输出：[1,2]
// 解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。
//  
// 提示：
//  * m == mat.length 
//  * n == mat[i].length 
//  * 1 <= m, n <= 100 
//  * mat[i][j] 为 0 或 1

// #v1
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
  *returnSize = 2;

  int *ret = (int *)malloc(sizeof(int) * 2);

  ret[0] = ret[1] = 0;

  for (int i = 0; i < matSize; i++) {
    int c = 0;

    for (int j = 0; j < *matColSize; j++) {
      if (mat[i][j]) ++c;
    }

    if (c > ret[1]) {
      ret[0] = i;
      ret[1] = c;
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

int main(int argc, char *argv[])
{
  int n, m, **a, returnSize, *ret;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  ret = rowAndMaximumOnes(a, m, &n, &returnSize);
  printf("%d %d\n", ret[0], ret[1]);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
