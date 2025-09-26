#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 908. 最小差 值 I - 给你一个整数数组 nums，和一个整数 k 。
// 在一个操作中，您可以选择 0 &lt;= i &lt; nums.length 的任何索引 i 。将 nums[i] 改 为 nums[i] + x ，其中 x 是一个范围为 [-k, k] 的任意整数。对于每个索引 i ，最多 只能 应用 一次 此操作。
// nums 的 分数 是 nums 中最大和最小元素的差值。 
// 在对  nums 中的每个索引最多应用一次上述操作后，返回 nums 的最低 分数 。
//  
// 示例 1：
// 输入：nums = [1], k = 0
// 输出：0
// 解释：分数是 max(nums) - min(nums) = 1 - 1 = 0。
// 示例 2：
// 输入：nums = [0,10], k = 2
// 输出：6
// 解释：将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6。
// 示例 3：
// 输入：nums = [1,3,6], k = 3
// 输出：0
// 解释：将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 104
//  * 0 &lt;= nums[i] &lt;= 104
//  * 0 &lt;= k &lt;= 104

// #v1
int smallestRangeI(int* nums, int numsSize, int k) {
  if (numsSize == 1) return 0;

  int max = nums[0], min = nums[0], t, i;

  // 寻找数组中的最大值和最小值
  for (i = 1; i < numsSize; i++) {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];
  }

  t = max - min;

  // 最值相等
  if (min == max || !k) return t;

  // k 翻倍
  k <<= 1;

  if (k > t) return 0;

  return t - k;
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
  printf("%d\n", smallestRangeI(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
