#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2425. 所有数对的异或和 - 给你两个下标从 0 开始的数组 nums1 和 nums2 ，两个数组都只包含非负整数。请你求出另外一个数组 nums3 ，包含 nums1 和 nums2 中 所有数对 的异或和（nums1 中每个整数都跟 nums2 中每个整数 恰好 匹配一次）。
// 请你返回 nums3 中所有整数的 异或和 。
//  
// 示例 1：
// 输入：nums1 = [2,1,3], nums2 = [10,2,5,0]
// 输出：13
// 解释：
// 一个可能的 nums3 数组是 [8,0,7,2,11,3,4,1,9,1,6,3] 。
// 所有这些数字的异或和是 13 ，所以我们返回 13 。
// 示例 2：
// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：0
// 解释：
// 所有数对异或和的结果分别为 nums1[0] ^ nums2[0] ，nums1[0] ^ nums2[1] ，nums1[1] ^ nums2[0] 和 nums1[1] ^ nums2[1] 。
// 所以，一个可能的 nums3 数组是 [2,5,1,6] 。
// 2 ^ 5 ^ 1 ^ 6 = 0 ，所以我们返回 0 。
//  
// 提示：
//  * 1 <= nums1.length, nums2.length <= 10^5
//  * 0 <= nums1[i], nums2[j] <= 10^9

// #v1
int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  // 数组长度均为偶数
  if (!(nums1Size & 1) && !(nums2Size & 1)) return 0;

  int xorVal1 = 0, xorVal2 = 0, i;

  for (i = 0; i < nums1Size; i++) xorVal1 ^= nums1[i];
  for (i = 0; i < nums2Size; i++) xorVal2 ^= nums2[i];

  // nums1 长度为偶数, nums2 长度为奇数
  if (!(nums1Size & 1)) return xorVal1;
  // nums2 长度为偶数, nums1 长度为奇数
  if (!(nums2Size & 1)) return xorVal2;

  // 数组长度均为奇数
  return xorVal1 ^ xorVal2;
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
  int n1, n2, *a1, *a2;
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &n2);
  a2 = read_1d_arr(n2);
  printf("%d\n", xorAllNums(a1, n1, a2, n2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
