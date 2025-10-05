#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1588. 所有奇数长度子数组的和 - 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。
// 子数组 定义为原数组中的一个连续子序列。
// 请你返回 arr 中 所有奇数长度子数组的和 。
//  
// 示例 1：
// 输入：arr = [1,4,2,5,3]
// 输出：58
// 解释：所有奇数长度子数组和它们的和为：
// [1] = 1
// [4] = 4
// [2] = 2
// [5] = 5
// [3] = 3
// [1,4,2] = 7
// [4,2,5] = 11
// [2,5,3] = 10
// [1,4,2,5,3] = 15
// 我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
// 示例 2：
// 输入：arr = [1,2]
// 输出：3
// 解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
// 示例 3：
// 输入：arr = [10,11,12]
// 输出：66
//  
// 提示：
//  * 1 <= arr.length <= 100
//  * 1 <= arr[i] <= 1000
//  
// 进阶：
// 你可以设计一个 O(n) 时间复杂度的算法解决此问题吗？

// #v1
// prefix sum
int sumOddLengthSubarrays(int* arr, int arrSize) {
  int i, j, sum[arrSize], ret = 0;;

  sum[0] = arr[0];
  for (i = 1; i < arrSize; i++) sum[i] = sum[i-1] + arr[i];

  for (i = 0; i < arrSize; i++) {
    for (j = i; j < arrSize; j++) {
      if ((j - i + 1 ) & 1) {
        if (i) ret += sum[j] - sum[i-1];
        else ret += sum[j];
      }
    }
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
  printf("%d\n", sumOddLengthSubarrays(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
