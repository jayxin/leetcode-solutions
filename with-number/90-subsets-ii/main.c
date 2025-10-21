#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 90. 子集 II - 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//  
// 示例 1：
// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]
//  
// 提示：
//  * 1 <= nums.length <= 10
//  * -10 <= nums[i] <= 10

// #v1
int **ret, retLen, *c, *a, n, *tmp;

void gen(int pos, int tLen) {
  // edge case
  if (pos == n) {
    // tLen == 0
    if (!tLen) {
      ret[retLen] = NULL;
      c[retLen++] = 0;
      return ;
    }

    // check if exists
    for (int i = 0; i < retLen; i++) {
      if (c[i] != tLen) continue;

      int f = 0;
      for (int j = 0; j < tLen; j++) {
        if (tmp[j] != ret[i][j]) {
          f = 1;
          break;
        }
      }

      // 已经存在
      if (!f) return ;
    }

    // add to result
    ret[retLen] = (int *)malloc(sizeof(int) * tLen);
    for (int i = 0; i < tLen; i++) ret[retLen][i] = tmp[i];
    c[retLen++] = tLen;
    return ;
  }

  // recursion

  // 不加入集合
  gen(pos+1, tLen);
  // 加入集合
  tmp[tLen++] = a[pos++];
  gen(pos, tLen);
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  // sort
  qsort(nums, numsSize, sizeof(int), cmp);

  int t[numsSize];

  // init
  a = nums;
  n = numsSize;
  retLen = 0;
  ret = (int **)malloc(sizeof(int *) * (1<<numsSize));
  c = (int *)malloc(sizeof(int) * (1<<numsSize));
  *returnColumnSizes = c;
  tmp = t;

  // compute
  gen(0, 0);

  *returnSize = retLen;

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
  int n, *a, **ret, s, *cols;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = subsetsWithDup(a, n, &s, &cols);
  print_2d_arr(ret, s, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
