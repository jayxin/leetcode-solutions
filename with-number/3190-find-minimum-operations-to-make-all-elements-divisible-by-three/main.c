#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3190. 使所有元素都可以被 3 整除的最少操作数 - 给你一个整数数组 nums 。一次操作中，你可以将 nums 中的 任意 一个元素增加或者减少 1 。
// 请你返回将 nums 中所有元素都可以被 3 整除的 最少 操作次数。
//  
// 示例 1：
// 输入：nums = [1,2,3,4]
// 输出：3
// 解释：
// 通过以下 3 个操作，数组中的所有元素都可以被 3 整除：
//  * 将 1 减少 1 。
//  * 将 2 增加 1 。
//  * 将 4 减少 1 。
// 示例 2：
// 输入：nums = [3,6,9]
// 输出：0
//  
// 提示：
//  * 1 <= nums.length <= 50
//  * 1 <= nums[i] <= 50
// 1. If x % 3 != 0 we can always increment or decrement x such that we only
// need 1 operation.
// 2. Add min(nums[i] % 3, 3 - (num[i] % 3)) to the count of operations.

// #v1
//int min(int a, int b) { return a <= b ? a : b; }

int minimumOperations(int* nums, int numsSize) {
  int ret = 0;

  for (int i = 0; i < numsSize; i++) {
    //ret += min(nums[i] % 3, 3 - (nums[i] % 3));
    ret += nums[i] % 3 ? 1 : 0;
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
  printf("%d\n", minimumOperations(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
