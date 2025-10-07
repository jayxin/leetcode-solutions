#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 462. 最小操作次数使数组元素相等 II - 给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最小操作数。
// 在一次操作中，你可以使数组中的一个元素加 1 或者减 1 。
// 测试用例经过设计以使答案在 32 位 整数范围内。
//  
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：2
// 解释：
// 只需要两次操作（每次操作指南使一个元素加 1 或减 1）：
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
// 示例 2：
// 输入：nums = [1,10,2,9]
// 输出：16
//  
// 提示：
//  * n == nums.length
//  * 1 &lt;= nums.length &lt;= 105
//  * -109 &lt;= nums[i] &lt;= 109

// #v1
// sort
// 寻找中位数
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

#define abs(x) ((x) >= 0 ? (x) : (-x))

int minMoves2(int* nums, int numsSize) {
  int ret = 0, m, i, t;

  qsort(nums, numsSize, sizeof(int), cmp);

  m = nums[numsSize >> 1];

  for (i = 0; i < numsSize; i++) {
    t = nums[i] - m;
    ret += abs(t);
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", minMoves2(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
