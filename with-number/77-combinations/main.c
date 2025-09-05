#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 77. 组合 - 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// 你可以按 任何顺序 返回答案。
//  
// 示例 1：
// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// 示例 2：
// 输入：n = 1, k = 1
// 输出：[[1]]
//  
// 提示：
//  * 1 <= n <= 20
//  * 1 <= k <= n

// #v1
int **ret, *tmp;
int retLen, kk, nn;

void _combine(int cur, int tmpLen) {
  if (tmpLen == kk) {
    ret[retLen] = (int *)malloc(sizeof(int) * kk);
    for (int i = 0; i < tmpLen; i++) {
      ret[retLen][i] = tmp[i];
    }
    retLen++;
    return ; // 回溯
  }
  if (cur > nn || nn - cur + 1 < kk - tmpLen) {
    return ;
  }

  // 选择
  tmp[tmpLen] = cur;
  _combine(cur + 1, tmpLen + 1);
  // 不选
  _combine(cur + 1, tmpLen);
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
  int i, a[21], size;
  nn = n;
  kk = k;
  if (n > 15) {
    size = 190000;
  } else {
    size = 1000;
  }
  ret = (int **)malloc(sizeof(int *) * size);
  retLen = 0;
  tmp = a;

  _combine(1, 0);

  *returnSize = retLen;
  *returnColumnSizes = (int *)malloc(sizeof(int) * retLen);
  for (i = 0; i < retLen; i++) {
    (*returnColumnSizes)[i] = k;
  }
  return ret;
}
// #v1

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
  int n, k, retSize, *retColSize;
  scanf("%d%d", &n, &k);
  int **ret = combine(n, k, &retSize, &retColSize);
  print_2d_arr(ret, retSize, k);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
