#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3427.  变长子数组求和 - 给你一个长度为 n 的整数数组 nums 。对于 每个 下标 i（0 <= i < n），定义对应的子数组 nums[start ... i]（start = max(0, i - nums[i])）。
// 返回为数组中每个下标定义的子数组中所有元素的总和。
// 子数组 是数组中的一个连续、非空 的元素序列。
//  
// 示例 1：
// 输入：nums = [2,3,1]
// 输出：11
// 解释：
// 下标 i 子数组 和 0 nums[0] = [2] 2 1 nums[0 ... 1] = [2, 3] 5 2 nums[1 ... 2] = [3, 1] 4 总和   11
// 总和为 11 。因此，输出 11 。
// 示例 2：
// 输入：nums = [3,1,1,2]
// 输出：13
// 解释：
// 下标 i 子数组 和 0 nums[0] = [3] 3 1 nums[0 ... 1] = [3, 1] 4 2 nums[1 ... 2] = [1, 1] 2 3 nums[1 ... 3] = [1, 1, 2] 4 总和   13
// 总和为 13 。因此，输出为 13 。
//  
// 提示：
//  * 1 <= n == nums.length <= 100
//  * 1 <= nums[i] <= 1000

// #v1
// prefix sum
int subarraySum(int* nums, int numsSize) {
  int sum[numsSize + 1], i, ret = 0, start;

  // prefix sum
  sum[0] = 0;
  for (i = 0; i < numsSize; i++) {
    sum[i+1] = sum[i] + nums[i];
  }

  for (i = 0; i < numsSize; i++) {
    start = i - nums[i];
    if (0 > start) start = 0;

    ret += sum[i + 1] - sum[start];
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
  printf("%d\n", subarraySum(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
