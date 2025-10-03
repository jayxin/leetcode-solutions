#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LCR 079. 子集 - 给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集 ）。
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//  
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 10
//  * -10 &lt;= nums[i] &lt;= 10
//  * nums 中的所有元素 互不相同
//  
// 注意：本题与主站 78 题相同： https://leetcode-cn.com/problems/subsets/ [https://leetcode-cn.com/problems/subsets/]

// #v1
int **result, *ns, n, *arr;
int resultLen;
int *resultColLen;

void genSubsets(int index, int len) {
  if (index == n) {
    if (len == 0) {
      result[resultLen] = NULL;
      resultColLen[resultLen++] = 0;
      return ;
    }
    int *a = (int *)malloc(sizeof(int) * len);
    for (int i = 0;i < len; i++) {
      a[i] = arr[i];
    }
    result[resultLen] = a;
    resultColLen[resultLen++] = len;
    len = 0;
    return ;
  }

  genSubsets(index + 1, len);

  arr[len++] = ns[index];
  genSubsets(index + 1, len);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 1<<numsSize;
  int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
  *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
  int aa[numsSize];

  ns = nums;
  n = numsSize;
  arr = aa;

  result = ret;
  resultLen = 0;
  resultColLen = *returnColumnSizes;
  memset(aa, 0, sizeof(int) * numsSize);

  genSubsets(0, 0);

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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
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

void free_2d_arr(int **arr, int rows) {
  if (!arr) {
    return;
  }
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
}


int main(int argc, char *argv[])
{
  int n, retSize, *retColSize;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  int **ret = subsets(arr, n, &retSize, &retColSize);
  print_2d_arr(ret, retSize, retColSize);
  free_1d_arr(arr);
  free_2d_arr(ret, retSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
