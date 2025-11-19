#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1695. 删除子数组的最大得分 - 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。
// 返回 只删除一个 子数组可获得的 最大得分 。
// 如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它 就是 a 的一个子数组。
//  
// 示例 1：
// 输入：nums = [4,2,4,5,6]
// 输出：17
// 解释：最优子数组是 [2,4,5,6]
// 示例 2：
// 输入：nums = [5,2,1,2,5,2,1,2,5]
// 输出：8
// 解释：最优子数组是 [5,2,1] 或 [1,2,5]
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 104

// #v1
// sliding window, hash table
int maximumUniqueSubarray(int* nums, int numsSize) {
  // hash table
  char ht[10001] = {0};
  int maxSum, sum, l, r;

  // init
  maxSum = sum = 0;
  l = r = 0;

  while (r < numsSize) {
    if (ht[nums[r]]) { // nums[r] has occurred
      if (sum > maxSum) maxSum = sum;

      // move left pointer
      while (nums[l] != nums[r]) {
        ht[nums[l]] = 0;
        sum -= nums[l];
        ++l;
      }
      sum -= nums[l];
      ++l;
    }

    sum += nums[r];
    ht[nums[r]] = 1;

    // move right pointer
    ++r;
  }

  if (sum > maxSum) maxSum = sum;

  return maxSum;
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
  printf("%d\n", maximumUniqueSubarray(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
