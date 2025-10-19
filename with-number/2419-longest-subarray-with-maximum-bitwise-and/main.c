#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2419. 按位与最大的最长子数组 - 给你一个长度为 n 的整数数组 nums 。
// 考虑 nums 中进行 按位与（bitwise AND）运算得到的值 最大 的 非空 子数组。
//  * 换句话说，令 k 是 nums 任意 子数组执行按位与运算所能得到的最大值。那么，只需要考虑那些执行一次按位与运算后等于 k 的子数组。
// 返回满足要求的 最长 子数组的长度。
// 数组的按位与就是对数组中的所有数字进行按位与运算。
// 子数组 是数组中的一个连续元素序列。
//  
// 示例 1：
// 输入：nums = [1,2,3,3,2,2]
// 输出：2
// 解释：
// 子数组按位与运算的最大值是 3 。
// 能得到此结果的最长子数组是 [3,3]，所以返回 2 。
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：1
// 解释：
// 子数组按位与运算的最大值是 4 。
// 能得到此结果的最长子数组是 [4]，所以返回 1 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 106
// Notice that the bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
// What does that tell us about the nature of the subarray that we should choose?

// #v1
int longestSubarray(int* nums, int numsSize) {
  int maxVal = nums[0], ret = 0, i, c;

  // find max value
  // nums 的任何子数组的元素按位与不会超过 nums 中元素的最大值
  for (i = 1; i < numsSize; i++) {
    if (maxVal < nums[i]) maxVal = nums[i];
  }

  // 寻找最大值连续出现的最多次数
  for (i = 0; i < numsSize; i++) {
    c = 0;
    while (i < numsSize && nums[i] == maxVal) {
      ++c;
      ++i;
    }
    if (c > ret) ret = c;
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
  printf("%d\n", longestSubarray(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
