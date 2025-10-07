#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3513. 不同 XOR 三元组的数目 I - 给你一个长度为 n 的整数数组 nums，其中 nums 是 范围 [1, n] 内所有数的 排列 。
// XOR 三元组 定义为三个元素的异或值 nums[i] XOR nums[j] XOR nums[k]，其中 i &lt;= j &lt;= k。
// 返回所有可能三元组 (i, j, k) 中 不同 的 XOR 值的数量。
// 排列 是一个集合中所有元素的重新排列。
//  
// 示例 1：
// 输入： nums = [1,2]
// 输出： 2
// 解释：
// 所有可能的 XOR 三元组值为：
//  * (0, 0, 0) → 1 XOR 1 XOR 1 = 1
//  * (0, 0, 1) → 1 XOR 1 XOR 2 = 2
//  * (0, 1, 1) → 1 XOR 2 XOR 2 = 1
//  * (1, 1, 1) → 2 XOR 2 XOR 2 = 2
// 不同的 XOR 值为 {1, 2}，因此输出为 2。
// 示例 2：
// 输入： nums = [3,1,2]
// 输出： 4
// 解释：
// 可能的 XOR 三元组值包括：
//  * (0, 0, 0) → 3 XOR 3 XOR 3 = 3
//  * (0, 0, 1) → 3 XOR 3 XOR 1 = 1
//  * (0, 0, 2) → 3 XOR 3 XOR 2 = 2
//  * (0, 1, 2) → 3 XOR 1 XOR 2 = 0
// 不同的 XOR 值为 {0, 1, 2, 3}，因此输出为 4。
//  
// 提示：
//  * 1 &lt;= n == nums.length &lt;= 105
//  * 1 &lt;= nums[i] &lt;= n
//  * nums 是从 1 到 n 的整数的一个排列。
// What is the maximum and minimum value we can obtain using the given numbers?
// Can we generate all numbers within that range?
// For n >= 3 we can obtain all numbers in [0, 2^(msb(n) + 1) - 1], where msb(n)
// is the index of the most significant bit in n’s binary representation (i.e.,
// the highest power of 2 less than or equal to n). Handle the case when n <= 2
// separately.

// #v1
int countBits(int x) {
  int c = 0;
  while (x) {
    ++c;
    x >>= 1;
  }
  return c;
}

int uniqueXorTriplets(int* nums, int numsSize) {
  if (numsSize <= 2) return numsSize;
  return 1 << countBits(numsSize);
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
  printf("%d\n", uniqueXorTriplets(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
