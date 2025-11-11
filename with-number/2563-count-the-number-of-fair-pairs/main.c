#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2563. 统计公平数对的数目 - 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个 整数 lower 和 upper ，返回 公平数对的数目 。
// 如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：
//  * 0 <= i < j < n，且
//  * lower <= nums[i] + nums[j] <= upper
//  
// 示例 1：
// 输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
// 输出：6
// 解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
// 示例 2：
// 输入：nums = [1,7,9,2,5], lower = 11, upper = 11
// 输出：1
// 解释：只有单个公平数对：(2,3) 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * nums.length == n
//  * -109 <= nums[i] <= 109
//  * -109 <= lower <= upper <= 109

// #v1
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
  long long ret = 0LL;
  int target, l, r, m, lb, ub;

  qsort(nums, numsSize, sizeof(int), cmp);

  for (int i = 0; i < numsSize; i++) {
    // find lower bound
    target = lower - nums[i];
    l = 0, r = numsSize - 1;
    while (l < r) {
      m = (l + r) >> 1;

      if (nums[m] >= target) r = m;
      else l = m + 1;
    }
    lb = l;
    if (nums[i] + nums[lb] < lower) continue;

    // find upper bound
    target = upper - nums[i];
    l = 0, r = numsSize - 1;
    while (l < r) {
      m = (l + r + 1) >> 1;

      if (nums[m] <= target) l = m;
      else r = m - 1;
    }
    ub = l;
    if (nums[i] + nums[ub] > upper) continue;

    ret += ub - lb + 1;
    // exclude nums[i]
    if (i >= lb && i <= ub) --ret;
  }

  ret /= 2LL;

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
  int *a, n, l, u;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d%d", &l, &u);
  printf("%lld\n", countFairPairs(a, n, l, u));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
