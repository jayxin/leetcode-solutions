#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3158. 求出出现两次数字的 XOR 值 - 给你一个数组 nums ，数组中的数字 要么 出现 一次，要么 出现两次。
// 请你返回数组中所有出现两次数字的按位 XOR 值，如果没有数字出现过两次，返回 0 。
//  
// 示例 1：
// 输入：nums = [1,2,1,3]
// 输出：1
// 解释：
// nums 中唯一出现过两次的数字是 1 。
// 示例 2：
// 输入：nums = [1,2,3]
// 输出：0
// 解释：
// nums 中没有数字出现两次。
// 示例 3：
// 输入：nums = [1,2,2,1]
// 输出：3
// 解释：
// 数字 1 和 2 出现过两次。1 XOR 2 == 3 。
//  
// 提示：
//  * 1 <= nums.length <= 50
//  * 1 <= nums[i] <= 50
//  * nums 中每个数字要么出现过一次，要么出现过两次。

// #v1
int duplicateNumbersXOR(int* nums, int numsSize) {
  char cnts[51] = {0};
  int ret = 0;

  for (int i = 0; i < numsSize; i++) {
    ++cnts[nums[i]];
    if (cnts[nums[i]] == 2) ret ^= nums[i];
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
  printf("%d\n", duplicateNumbersXOR(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
