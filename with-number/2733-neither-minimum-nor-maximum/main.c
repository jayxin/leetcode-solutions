#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2733. 既不是最小值也不是最大值 - 给你一个整数数组 nums ，数组由 不同正整数 组 成，请你找出并返回数组中 任一 既不是 最小值 也不是 最大值 的数字，如果不存在这样 的数字，返回 -1 。
// 返回所选整数。
//  
// 示例 1：
// 输入：nums = [3,2,1,4]
// 输出：2
// 解释：在这个示例中，最小值是 1 ，最大值是 4 。因此，2 或 3 都是有效答案。
// 示例 2：
// 输入：nums = [1,2]
// 输出：-1
// 解释：由于不存在既不是最大值也不是最小值的数字，我们无法选出满足题目给定条件的数 字。因此，不存在答案，返回 -1 。
// 示例 3：
// 输入：nums = [2,1,3]
// 输出：2
// 解释：2 既不是最小值，也不是最大值，这个示例只有这一个有效答案。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= nums[i] <= 100
//  * nums 中的所有数字互不相同

//// #v1
//int cmp(const void *a, const void *b) {
  //return *(const int *)a - *(const int *)b;
//}
//
//int findNonMinOrMax(int* nums, int numsSize) {
  //if (numsSize <= 2) return -1;
//
  //qsort(nums, numsSize, sizeof(int), cmp);
//
  //if (nums[0] == nums[numsSize-1]) return -1;
//
  //return nums[1];
//}
//// #v1

// #v2
int findNonMinOrMax(int* nums, int numsSize) {
  if (numsSize <= 2) return -1;

  int minVal, maxVal;

  minVal = maxVal = nums[0];
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > maxVal) maxVal = nums[i];
    if (nums[i] < minVal) minVal = nums[i];
  }

  if (maxVal == minVal) return -1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != maxVal && nums[i] != minVal) return nums[i];
  }

  return -1;
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", findNonMinOrMax(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
