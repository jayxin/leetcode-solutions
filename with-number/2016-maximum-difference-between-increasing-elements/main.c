#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2016. 增量元素之间的最大差值 - 给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。
// 返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。
//  
// 示例 1：
// 输入：nums = [7,1,5,4]
// 输出：4
// 解释：
// 最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
// 注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
// 示例 2：
// 输入：nums = [9,4,3,2]
// 输出：-1
// 解释：
// 不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
// 示例 3：
// 输入：nums = [1,5,2,10]
// 输出：9
// 解释：
// 最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
//  
// 提示：
//  * n == nums.length
//  * 2 <= n <= 1000
//  * 1 <= nums[i] <= 109

// #v1
int maximumDifference(int* nums, int numsSize) {
  int minVal = nums[0], maxDiff = 0, d;

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > minVal) {
      d = nums[i] - minVal;
      if (d > maxDiff) maxDiff = d;
    } else {
      minVal = nums[i];
    }
  }

  // edge case
  if (maxDiff == 0) return -1;

  return maxDiff;
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
  printf("%d\n", maximumDifference(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
