#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2317. 操作后的最大异或和 - 给你一个下标从 0 开始的整数数组 nums 。一次操作中，选择  任意 非负整数 x 和一个下标 i ，更新 nums[i] 为 nums[i] AND (nums[i] XOR x) 。
// 注意，AND 是逐位与运算，XOR 是逐位异或运算。
// 请你执行 任意次 更新操作，并返回 nums 中所有元素 最大 逐位异或和。
//  
// 示例 1：
// 输入：nums = [3,2,4,6]
// 输出：7
// 解释：选择 x = 4 和 i = 3 进行操作，num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2 。
// 现在，nums = [3, 2, 4, 2] 且所有元素逐位异或得到 3 XOR 2 XOR 4 XOR 2 = 7 。
// 可知 7 是能得到的最大逐位异或和。
// 注意，其他操作可能也能得到逐位异或和 7 。
// 示例 2：
// 输入：nums = [1,2,3,9,2]
// 输出：11
// 解释：执行 0 次操作。
// 所有元素的逐位异或和为 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11 。
// 可知 11 是能得到的最大逐位异或和。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 0 <= nums[i] <= 108

// #v1
// 位运算
// 只要有 1 出现的位结果中对应的位就是 1
// 若对于数组中的每个元素, 某个位都为 0, 则结果中对应的位为 0
int maximumXOR(int* nums, int numsSize) {
  int ret = 0;

  for (int i = 0; i < numsSize; i++) {
    ret |= nums[i];
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
  printf("%d\n", maximumXOR(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
