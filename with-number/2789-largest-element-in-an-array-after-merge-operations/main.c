#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2789. 合并后数组中的最大元素 - 给你一个下标从 0 开始、由正整数组成的数组 nums 。
// 你可以在数组上执行下述操作 任意 次：
//  * 选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1]  的下标 i 。将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
// 返回你可以从最终数组中获得的 最大 元素的值。
//  
// 示例 1：
// 输入：nums = [2,3,7,9,3]
// 输出：21
// 解释：我们可以在数组上执行下述操作：
// - 选中 i = 0 ，得到数组 nums = [5,7,9,3] 。
// - 选中 i = 1 ，得到数组 nums = [5,16,3] 。
// - 选中 i = 0 ，得到数组 nums = [21,3] 。
// 最终数组中的最大元素是 21 。可以证明我们无法获得更大的元素。
// 示例 2：
// 输入：nums = [5,3,3]
// 输出：11
// 解释：我们可以在数组上执行下述操作：
// - 选中 i = 1 ，得到数组 nums = [5,6] 。
// - 选中 i = 0 ，得到数组 nums = [11] 。
// 最终数组中只有一个元素，即 11 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 106
// 1. Start from the end of the array and keep merging elements together until
// it is no longer possible.
// 2. The answer will be the resulting element from the last merge operation.

// #v1
long long maxArrayValue(int* nums, int numsSize) {
  long long cur = nums[numsSize-1], ret = cur;

  for (int i = numsSize-2; i >= 0; i--) {
    if (cur >= nums[i]) cur = cur + nums[i];
    else cur = nums[i];

    if (cur > ret) ret = cur;
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
  printf("%lld\n", maxArrayValue(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
