#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2588. 统计美丽子数组数目 - 给你一个下标从 0 开始的整数数组nums 。每次操作中，你可以 ：
//  * 选择两个满足 0 <= i, j < nums.length 的不同下标 i 和 j 。
//  * 选择一个非负整数 k ，满足 nums[i] 和 nums[j] 在二进制下的第 k 位（下标编号从 0 开始）是 1 。
//  * 将 nums[i] 和 nums[j] 都减去 2k 。
// 如果一个子数组内执行上述操作若干次（包括 0 次）后，该子数组可以变成一个全为 0 的 数组，那么我们称它是一个 美丽 的子数组。
// 请你返回数组 nums 中 美丽子数组 的数目。
// 子数组是一个数组中一段连续 非空 的元素序列。
// 注意：所有元素最初都是 0 的子数组被认为是美丽的，因为不需要进行任何操作。
//  
// 示例 1：
// 输入：nums = [4,3,1,2,4]
// 输出：2
// 解释：nums 中有 2 个美丽子数组：[4,3,1,2,4] 和 [4,3,1,2,4] 。
// - 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
//   - 选择 [3, 1, 2] 和 k = 1 。将 2 个数字都减去 21 ，子数组变成 [1, 1, 0] 。
//   - 选择 [1, 1, 0] 和 k = 0 。将 2 个数字都减去 20 ，子数组变成 [0, 0, 0] 。
// - 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
//   - 选择 [4, 3, 1, 2, 4] 和 k = 2 。将 2 个数字都减去 22 ，子数组变成 [0, 3, 1, 2, 0] 。
//   - 选择 [0, 3, 1, 2, 0] 和 k = 0 。将 2 个数字都减去 20 ，子数组变成 [0, 2, 0, 2, 0] 。
//   - 选择 [0, 2, 0, 2, 0] 和 k = 1 。将 2 个数字都减去 21 ，子数组变成 [0, 0, 0, 0, 0] 。
// 示例 2：
// 输入：nums = [1,10,4]
// 输出：0
// 解释：nums 中没有任何美丽子数组。
//  
// 提示：
//  * 1 <= nums.length <= 10^5
//  * 0 <= nums[i] <= 10^6
// 1. A subarray is beautiful if its xor is equal to zero.
// 2. Compute the prefix xor for every index, then the xor of subarray [left,
// right] is equal to zero if prefix_xor[left] ^ perfix_xor[right] == 0
// 3. Iterate from left to right and maintain a hash table to count the number of
// indices equal to the current prefix xor.

// #v1
// prefix sum, hash table, count
// Time: O(n)

// 子数组是美丽子数组 IFF 子数组的所有元素的异或值为 0
long long beautifulSubarrays(int* nums, int numsSize) {
  long long ret = 0LL;
  // 1048575 是可能的最大异或值
  // 即将 10^6 的二进制表示每一位置 1
  int prefixXorSum[numsSize+1], ht[1048576] = {0};

  // 计算前缀异或和
  // nums[0]^nums[1]^...^nums[i] == prefixXorSum[i+1]
  // nums[i]^...^nums[j] == prefixXorSum[j+1]^prefixXorSum[i]
  prefixXorSum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    prefixXorSum[i+1] = prefixXorSum[i] ^ nums[i];
  }

  // 遍历每个前缀异或和
  for (int i = 0; i < numsSize; i++) {
    // 将 prefixXorSum[1...i] 中异或前缀和与 prefixXorSum[i+1] 相等的数量计入结果
    // 比如 prefixXorSum[j] == prefixXorSum[i+1], 1 <= j <= i
    // 则 prefixXorSum[j]^prefixXorSum[i+1] == 0 就是子数组 nums[j...i] 中的元素异或的结果
    ret += ht[prefixXorSum[i+1]];

    // 计数当前前缀异或和
    ++ht[prefixXorSum[i+1]];
  }

  // prefixXorSum[i] 本身为 0 的子数组
  // 即 nums[0...i] 的异或值为 0
  ret += ht[0];

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
  printf("%lld\n", beautifulSubarrays(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
