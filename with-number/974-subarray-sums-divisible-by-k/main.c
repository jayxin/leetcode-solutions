#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 974. 和可被 K 整除的子数组 - 给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的非空 子数组 的数目。
// 子数组 是数组中 连续 的部分。
//  
// 示例 1：
// 输入：nums = [4,5,0,-2,-3,1], k = 5
// 输出：7
// 解释：
// 有 7 个子数组满足其元素之和可被 k = 5 整除：
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// 示例 2:
// 输入: nums = [5], k = 9
// 输出: 0
//  
// 提示:
//  * 1 <= nums.length <= 3 * 104
//  * -104 <= nums[i] <= 104
//  * 2 <= k <= 104

// #v1
// prefix sum, count, hash table, math, remainder
// arithmetic, 同余
int subarraysDivByK(int* nums, int numsSize, int k) {
  int prefixSum[numsSize+1], ret = 0;
  // 将 nums 中的元素根据 (mod k) 得到的余数分为 k 类
  // ht 存储对应类别元素的个数, 余数范围 [0, k-1]
  int ht[k];
  int i, r;

  // init
  memset(ht, 0, sizeof(ht));

  // prefix sum
  // nums[0] + nums[1] + ... + nums[i] == prefixSum[i+1]
  prefixSum[0] = 0;
  for (i = 0; i < numsSize; i++) {
    prefixSum[i+1] = prefixSum[i] + nums[i];
  }

  // k * x = prefixSum[j+1]-prefixSum[i]
  // a = q*b + r
  // prefixSum[j+1] = k*x + prefixSum[i]
  for (i = 1; i <= numsSize; i++) {
    // compute remainder
    r = (prefixSum[i] % k + k) % k;
    // add to result
    ret += ht[r];
    // update counter
    ++ht[r];
  }

  // add prefixSum % k == 0
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
  int n, k, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", subarraysDivByK(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
