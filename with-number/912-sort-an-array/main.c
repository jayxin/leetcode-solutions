#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 912. 排序数组 - 给你一个整数数组 nums，请你将该数组升序排列。
// 你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
//  
// 示例 1：
// 输入：nums = [5,2,3,1]
// 输出：[1,2,3,5]
// 解释：数组排序后，某些数字的位置没有改变（例如，2 和 3），而其他数字的位置发生了 改变（例如，1 和 5）。
// 示例 2：
// 输入：nums = [5,1,1,2,0,0]
// 输出：[0,0,1,1,2,5]
// 解释：请注意，nums 的值不一定唯一。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 5 * 104
//  * -5 * 104 &lt;= nums[i] &lt;= 5 * 104

// #v1
// 归并排序
int *tmp;

void merge(int *a, int m, int *b, int n) {
  int i = 0, j = 0, tmpLen = 0, *tt;

  while (i < m && j < n) {
    if (a[i] < b[j]) {
      tmp[tmpLen++] = a[i++];
    } else {
      tmp[tmpLen++] = b[j++];
    }
  }

  while (i < m) {
    tmp[tmpLen++] = a[i++];
  }

  while (j < n) {
    tmp[tmpLen++] = b[j++];
  }

  for (i = 0; i < m; i++) {
    a[i] = tmp[i];
  }

  tt = tmp + m;
  for (i = 0; i < n; i++) {
    b[i] = tt[i];
  }
}

void mergeSort(int *a, int n) {
  if (n <= 1) return ;

  int m = n >> 1, *l = a, *r = a + m, lLen = m, rLen = n - m;

  mergeSort(l, lLen);
  mergeSort(r, rLen);
  merge(l, lLen, r, rLen);
}

bool check(int *a, int n) {
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i-1]) return false;
  }
  return true;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;

  int t[numsSize];

  if (check(nums, numsSize)) return nums;

  //tmp = (int *)malloc(sizeof(int) * numsSize);
  tmp = t;

  mergeSort(nums, numsSize);
  return nums;
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

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = sortArray(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
