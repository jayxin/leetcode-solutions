#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2527. 查询数组异或美丽值 - 给你一个下标从 0 开始的整数数组 nums 。
// 三个下标 i ，j 和 k 的 有效值 定义为 ((nums[i] | nums[j]) & nums[k]) 。
// 一个数组的 异或美丽值 是数组中所有满足 0 <= i, j, k < n  的三元组 (i, j, k) 的 有效值 的异或结果。
// 请你返回 nums 的异或美丽值。
// 注意：
//  * val1 | val2 是 val1 和 val2 的按位或。
//  * val1 & val2 是 val1 和 val2 的按位与。
//  
// 示例 1：
// 输入：nums = [1,4]
// 输出：5
// 解释：
// 三元组和它们对应的有效值如下：
// - (0,0,0) 有效值为 ((1 | 1) & 1) = 1
// - (0,0,1) 有效值为 ((1 | 1) & 4) = 0
// - (0,1,0) 有效值为 ((1 | 4) & 1) = 1
// - (0,1,1) 有效值为 ((1 | 4) & 4) = 4
// - (1,0,0) 有效值为 ((4 | 1) & 1) = 1
// - (1,0,1) 有效值为 ((4 | 1) & 4) = 4
// - (1,1,0) 有效值为 ((4 | 4) & 1) = 0
// - (1,1,1) 有效值为 ((4 | 4) & 4) = 4
// 数组的异或美丽值为所有有效值的按位异或 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5 。
// 示例 2：
// 输入：nums = [15,45,20,2,34,35,5,44,32,30]
// 输出：34
// 解释：数组的异或美丽值为 34 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109

// #v1
int xorBeauty(int* nums, int numsSize) {
  int ret = nums[0];
  for (int i = 1; i < numsSize; i++) {
    ret ^= nums[i];
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
  printf("%d\n", xorBeauty(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
