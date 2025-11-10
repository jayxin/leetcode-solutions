#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1248. 统计「优美子数组」 - 给你一个整数数组 nums 和一个整数 k。如果某个连续子数组中 恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
// 请返回这个数组中 「优美子数组」 的数目。
//  
// 示例 1：
// 输入：nums = [1,1,2,1,1], k = 3
// 输出：2
// 解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
// 示例 2：
// 输入：nums = [2,4,6], k = 1
// 输出：0
// 解释：数列中不包含任何奇数，所以不存在优美子数组。
// 示例 3：
// 输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// 输出：16
//  
// 提示：
//  * 1 <= nums.length <= 50000
//  * 1 <= nums[i] <= 10^5
//  * 1 <= k <= nums.length
// 1. After replacing each even by zero and every odd by one can we use prefix
// sum to find answer ?
// 2. Can we use two pointers to count number of sub-arrays ?
// 3. Can we store the indices of odd numbers and for each k indices count the
// number of sub-arrays that contains them ?

//// #v1
//// prefix sum, count
//int numberOfSubarrays(int* nums, int numsSize, int k) {
  //int prefixSum[numsSize+1];
  //int ret = 0;
  //int ht[numsSize+1];
//
  //memset(ht, 0, sizeof(ht));
//
  //prefixSum[0] = 0;
  //for (int i = 0; i < numsSize; i++) {
    //prefixSum[i+1] = prefixSum[i] + (nums[i] & 1);
  //}
//
  //for (int i = 0; i <= numsSize; i++) {
    //if (prefixSum[i] >= k) {
      //int d = prefixSum[i] - k;
      //ret += ht[d];
    //}
//
    //++ht[prefixSum[i]];
  //}
//
  //return ret;
//}
//// #v1

// #v2
// 空间优化
// prefix sum, count
int numberOfSubarrays(int* nums, int numsSize, int k) {
  int ret = 0;
  int prefixSum, ht[numsSize+1];

  memset(ht, 0, sizeof(ht));

  // init
  prefixSum = 0;
  ht[0] = 1;

  // compute
  for (int i = 0; i < numsSize; i++) {
    // compute prefix sum
    prefixSum += nums[i] & 1;

    if (prefixSum >= k) {
      //int d = prefixSum - k;
      ret += ht[prefixSum - k];
    }

    // count
    ++ht[prefixSum];
  }

  return ret;
}
// #v2

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
  printf("%d\n", numberOfSubarrays(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
