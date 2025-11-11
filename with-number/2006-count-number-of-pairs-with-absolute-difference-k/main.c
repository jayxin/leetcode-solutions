#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2006. 差的绝对值为 K 的数对数目 - 给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。
// |x| 的值定义为：
//  * 如果 x >= 0 ，那么值为 x 。
//  * 如果 x < 0 ，那么值为 -x 。
//  
// 示例 1：
// 输入：nums = [1,2,2,1], k = 1
// 输出：4
// 解释：差的绝对值为 1 的数对为：
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// 示例 2：
// 输入：nums = [1,3], k = 3
// 输出：0
// 解释：没有任何数对差的绝对值为 3 。
// 示例 3：
// 输入：nums = [3,2,1,5,4], k = 2
// 输出：3
// 解释：差的绝对值为 2 的数对为：
// - [3,2,1,5,4]
// - [3,2,1,5,4]
// - [3,2,1,5,4]
//  
// 提示：
//  * 1 <= nums.length <= 200
//  * 1 <= nums[i] <= 100
//  * 1 <= k <= 99

// #v1
int abs(int x) { return x >= 0 ? x : -x; }

int countKDifference(int* nums, int numsSize, int k) {
  int c = 0;

  for (int i = 0; i < numsSize; i++) {
    for (int j = i+1; j < numsSize; j++) {
      if (abs(nums[i]-nums[j]) == k) ++c;
    }
  }

  return c;
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
  printf("%d\n", countKDifference(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
