#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面试题 08.04. 幂集 - 幂集。编写一种方法，返回某集合的所有子集。集合中 不包含重复的元素。
// 说明：解集不能包含重复的子集。
// 示例：
//  输入：nums = [1,2,3]
//  输出：
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// #v1
int getBits(int x, int *a, int len) {
  int oneCnt = 0, l = 0;

  memset(a, 0, sizeof(int) * len);

  while (x) {
    a[l] = x & 1;
    if (a[l]) ++oneCnt;
    ++l;
    x >>= 1;
  }

  return oneCnt;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int len = 1 << numsSize, **ret, i, j, k, l, arr[numsSize], *cols;

  ret = (int **)malloc(sizeof(int *) * len);
  cols = (int *)malloc(sizeof(int) * len);
  *returnSize = len;
  *returnColumnSizes = cols;

  ret[0] = NULL;
  cols[0] = 0;

  for (i = 1; i < len; i++) {
    l = getBits(i, arr, numsSize);
    ret[i] = (int *)malloc(sizeof(int) * l);
    cols[i] = l;
    for (j = 0, k = 0; j < numsSize; j++) {
      if (arr[j]) ret[i][k++] = nums[j];
    }
  }

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
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
  int n, *a, **ret, s, *c;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = subsets(a, n, &s, &c);
  print_2d_arr(ret, s, c);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
