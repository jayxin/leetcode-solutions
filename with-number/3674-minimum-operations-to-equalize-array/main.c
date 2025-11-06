#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3674. 数组元素相等的最小操作次数 - 给你一个长度为 n 的整数数组 nums。
// 在一次操作中，可以选择任意子数组 nums[l...r] （0 <= l <= r < n），并将该子数组中的每个元素 替换 为所有元素的 按位与（bitwise AND）结果。
// 返回使数组 nums 中所有元素相等所需的最小操作次数。
// 子数组 是数组中连续的、非空的元素序列。
//  
// 示例 1：
// 输入： nums = [1,2]
// 输出： 1
// 解释：
// 选择 nums[0...1]：(1 AND 2) = 0，因此数组变为 [0, 0]，所有元素在一次操作后相等。
// 示例 2：
// 输入： nums = [5,5,5]
// 输出： 0
// 解释：
// nums 本身是 [5, 5, 5]，所有元素已经相等，因此不需要任何操作。
//  
// 提示：
//  * 1 <= n == nums.length <= 100
//  * 1 <= nums[i] <= 105

// #v1
int minOperations(int* nums, int numsSize) {
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] != nums[0]) return 1;
  }

  return 0;
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
  printf("%d\n", minOperations(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
