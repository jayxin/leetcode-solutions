#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1984. 学生分数的最小差值 - 给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表 示第 i 名学生的分数。另给你一个整数 k 。
// 从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。
// 返回可能的 最小差值 。
//  
// 示例 1：
// 输入：nums = [90], k = 1
// 输出：0
// 解释：选出 1 名学生的分数，仅有 1 种方法：
// - [90] 最高分和最低分之间的差值是 90 - 90 = 0
// 可能的最小差值是 0
// 示例 2：
// 输入：nums = [9,4,1,7], k = 2
// 输出：2
// 解释：选出 2 名学生的分数，有 6 种方法：
// - [9,4,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
// - [9,4,1,7] 最高分和最低分之间的差值是 9 - 1 = 8
// - [9,4,1,7] 最高分和最低分之间的差值是 9 - 7 = 2
// - [9,4,1,7] 最高分和最低分之间的差值是 4 - 1 = 3
// - [9,4,1,7] 最高分和最低分之间的差值是 7 - 4 = 3
// - [9,4,1,7] 最高分和最低分之间的差值是 7 - 1 = 6
// 可能的最小差值是 2
//  
// 提示：
//  * 1 <= k <= nums.length <= 1000
//  * 0 <= nums[i] <= 105

// #v1
// sort, sliding window
int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int minimumDifference(int* nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);

  int minDiff = 0x3f3f3f3f, tmp;

  for (int i = 0; i < numsSize-k+1; i++) {
    tmp = nums[i + k - 1] - nums[i];
    if (tmp < minDiff) minDiff = tmp;
  }

  return minDiff;
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
  printf("%d\n", minimumDifference(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
