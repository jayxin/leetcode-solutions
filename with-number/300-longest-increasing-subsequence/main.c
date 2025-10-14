#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 300. 最 长递增子序列 - 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
//  
// 示例 1：
// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 示例 2：
// 输入：nums = [0,1,0,3,2,3]
// 输出：4
// 示例 3：
// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1
//  
// 提示：
//  * 1 <= nums.length <= 2500
//  * -10^4 <= nums[i] <= 10^4
//  
// 进阶：
//  * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?

// #v1
int lengthOfLIS(int* nums, int numsSize) {
  // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
  int dp[numsSize], i, j, ret, t;

  // init
  dp[0] = ret = 1;

  // compute
  for (i = 1; i < numsSize; i++) {
    dp[i] = 1;

    for (j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        t = dp[j] + 1;
        if (t > dp[i]) dp[i] = t;
      }
    }

    if (dp[i] > ret) ret = dp[i];
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
  printf("%d\n", lengthOfLIS(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
