#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3349. 检测相邻递增子数组 I - 给你一个由 n 个整数组成的数组 nums 和一个整数 k，请你确定是否存在 两个 相邻 且长度为 k 的 严格递增 子数组。具体来说，需要检查是否存在 从下标 a 和 b (a &lt; b) 开始的 两个 子数组，并满足下述全部条件：
//  * 这两个子数组 nums[a..a + k - 1] 和 nums[b..b + k - 1] 都是 严格递增 的。
//  * 这两个子数组必须是 相邻的，即 b = a + k。
// 如果可以找到这样的 两个 子数组，请返回 true；否则返回 false。
// 子数组 是数组中的一个连续 非空 的元素序列。
//  
// 示例 1：
// 输入：nums = [2,5,7,8,9,2,3,4,3,1], k = 3
// 输出：true
// 解释：
//  * 从下标 2 开始的子数组为 [7, 8, 9]，它是严格递增的。
//  * 从下标 5 开始的子数组为 [2, 3, 4]，它也是严格递增的。
//  * 两个子数组是相邻的，因此结果为 true。
// 示例 2：
// 输入：nums = [1,2,3,4,4,4,4,5,6,7], k = 5
// 输出：false
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 100
//  * 1 &lt;= 2 * k &lt;= nums.length
//  * -1000 &lt;= nums[i] &lt;= 1000

// #v1
// double pointer
bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
  if (k == 1) return true;

  int l = 0, r = 0, l1, r1, end = numsSize - 1;

  while (r < numsSize) {
    if (r - l + 1 == k) { // 找到第一个子数组
      l1 = r1 = r + 1; // 寻找相邻子数组

      while (r1 < numsSize) {
        // 找到第二个子数组
        if (r1 - l1 + 1 == k) return true;

        // 严格递增
        if (r1 != end && nums[r1+1] > nums[r1]) ++r1;
        else break;
      }
    }

    // 严格递增
    if (r != end && nums[r+1] > nums[r]) ++r;
    else {
      ++l;
      r = l;
    }
  }

  return false;
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
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  if (hasIncreasingSubarrays(a, n, k)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
