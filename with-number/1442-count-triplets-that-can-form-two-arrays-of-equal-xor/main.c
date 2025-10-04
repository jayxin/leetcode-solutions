#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1442. 形成两个异或相等数组的三元组数目 - 给你一个整数数组 arr 。
// 现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。
// a 和 b 定义如下：
//  * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
//  * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// 注意：^ 表示 按位异或 操作。
// 请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
//  
// 示例 1：
// 输入：arr = [2,3,1,6,7]
// 输出：4
// 解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
// 示例 2：
// 输入：arr = [1,1,1,1,1]
// 输出：10
// 示例 3：
// 输入：arr = [2,3]
// 输出：0
// 示例 4：
// 输入：arr = [1,3,5,7,9]
// 输出：3
// 示例 5：
// 输入：arr = [7,11,12,9,5,2,7,17,22]
// 输出：8
//  
// 提示：
//  * 1 <= arr.length <= 300
//  * 1 <= arr[i] <= 10^8
// We are searching for sub-array of length ≥ 2 and we need to split it to 2
// non-empty arrays so that the xor of the first array is equal to the xor of
// the second array. This is equivalent to searching for sub-array with xor = 0.
// Keep the prefix xor of arr in another array, check the xor of all sub-arrays
// in O(n^2), if the xor of sub-array of length x is 0 add x-1 to the answer.

// #v1
// 从 arr 中选出一个子数组, 此数组的异或结果为0, 则有(子数组长度-1)种
// 将子数组分成两个非空数组的方法, 结果加上 (子数组长度-1)
int countTriplets(int* arr, int arrSize) {
  int xorVals[arrSize], i, ret = 0, j;

  xorVals[0] = arr[0];
  for (i = 1; i < arrSize; i++) xorVals[i] = xorVals[i-1] ^ arr[i];

  for (i = 0; i < arrSize; i++) {
    for (j = i + 1; j < arrSize; j++) {
      if (i && !(xorVals[j] ^ xorVals[i-1])) ret += j - i;
      else if (!i && !xorVals[j]) ret += j;
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
  printf("%d\n", countTriplets(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
