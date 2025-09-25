#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// LCR 008. 长度最小的子数组 - 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//  
// 示例 1：
// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 示例 2：
// 输入：target = 4, nums = [1,4,4]
// 输出：1
// 示例 3：
// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
// 输出：0
//  
// 提示：
//  * 1 &lt;= target &lt;= 109
//  * 1 &lt;= nums.length &lt;= 105
//  * 1 &lt;= nums[i] &lt;= 105
//  
// 进阶：
//  * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的 解法。
//  
// 注意：本题与主站 209 题相同：https://leetcode-cn.com/problems/minimum-size-subarray-sum/ [https://leetcode-cn.com/problems/minimum-size-subarray-sum/]

// #v1
#define min(a, b) (a < b ? a : b)

int minSubArrayLen(int target, int *nums, int numsSize) {
  // prefix sum
  // sum[1..numsSize] -> nums[0..numsSize]
  int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
  sum[0] = 0;
  sum[1] = nums[0];
  for (int i = 2; i <= numsSize; ++i) {
    sum[i] = sum[i - 1] + nums[i - 1];
  }

  if (sum[numsSize] < target) {
    free(sum);
    return 0;
  }

  int r = numsSize - 1, l = r;
  int ret = numsSize;

  while (r >= 0 && l >= 0) {
    if (sum[r + 1] - sum[l] >= target) {
      ret = min(ret, r - l + 1);
      r--;
    } else {
      l--;
    }
  }

  free(sum);

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
  int n, *a, t;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &t);
  printf("%d\n", minSubArrayLen(t, a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
