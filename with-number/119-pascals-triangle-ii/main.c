#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 119. 杨辉三角 II - 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
// [https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif]
//  
// 示例 1:
// 输入: rowIndex = 3
// 输出: [1,3,3,1]
// 示例 2:
// 输入: rowIndex = 0
// 输出: [1]
// 示例 3:
// 输入: rowIndex = 1
// 输出: [1,1]
//  
// 提示:
//  * 0 <= rowIndex <= 33
//  
// 进阶：
// 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？

// #v1
int* getRow(int rowIndex, int* returnSize) {
  *returnSize = rowIndex + 1;
  size_t s = (rowIndex + 1 >= 2 ? rowIndex + 1 : 3);
  int *ret = (int *)malloc(sizeof(int) * s), arr[s], *new,
      *old, *t, i, j;

  ret[0] = ret[1] = 1;
  if (!rowIndex || rowIndex == 1) return ret;

  // init
  old = ret;
  new = arr;
  for (i = 2; i <= rowIndex; i++) {
    // init
    new[0] = new[i] = 1;

    for (j = 1; j < i; j++) new[j] = old[j-1] + old[j];

    // swap
    t = old;
    old = new;
    new = t;
  }

  if (old != ret) {
    for (i = 0; i <= rowIndex; i++) ret[i] = arr[i];
  }

  return ret;
}
// #v1

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

int main(int argc, char *argv[])
{
  int n, *ret, s;
  scanf("%d", &n);
  ret = getRow(n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
