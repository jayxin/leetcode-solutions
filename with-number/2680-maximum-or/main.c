#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2680. 最大或 值 - 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k 。每一次操作中， 你可以选择一个数并将它乘 2 。
// 你最多可以进行 k 次操作，请你返回 nums[0] | nums[1] | ... | nums[n - 1] 的最大值 。
// a | b 表示两个整数 a 和 b 的 按位或 运算。
//  
// 示例 1：
// 输入：nums = [12,9], k = 1
// 输出：30
// 解释：如果我们对下标为 1 的元素进行操作，新的数组为 [12,18] 。此时得到最优答案为 12 和 18 的按位或运算的结果，也就是 30 。
// 示例 2：
// 输入：nums = [8,1,2], k = 2
// 输出：35
// 解释：如果我们对下标 0 处的元素进行操作，得到新数组 [32,1,2] 。此时得到最优答案为 32|1|2 = 35 。
//  
// 提示：
//  * 1 <= nums.length <= 10^5
//  * 1 <= nums[i] <= 10^9
//  * 1 <= k <= 15
// The optimal solution should apply all the k operations on a single number.
// Calculate the prefix or and the suffix or and perform k operations over each
// element, and maximize the answer.

// #v1
// 前缀或和, 后缀或和
long long maximumOr(int* nums, int numsSize, int k) {
  if (numsSize == 1) return (int64_t)nums[0] << k;

  int prefix[numsSize], suffix[numsSize], i, end = numsSize - 1, j;
  int64_t t, ret;

  // 计算前缀或和、后缀或和
  prefix[0] = nums[0];
  suffix[end] = nums[end];
  for (i = 1; i < numsSize; i++) {
    prefix[i] = prefix[i-1] | nums[i];

    j = end - i;
    suffix[j] = suffix[j+1] | nums[j];
  }

  // first element
  ret = ((int64_t)nums[0] << k) | suffix[1];

  // nums[1...numsSize-2]
  for (i = 1; i < end; i++) {
    t = ((int64_t)nums[i] << k) | prefix[i-1] | suffix[i+1];

    // update max
    if (t > ret) ret = t;
  }

  // num[numsSize-1]
  if (end-1 >= 0) {
    t = ((int64_t)nums[end] << k) | prefix[end-1];

    // update max
    if (t > ret) ret = t;
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
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%lld\n", maximumOr(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
