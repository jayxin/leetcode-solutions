#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 724. 寻找数组的中心下标 - 给你一个整数数组 nums ，请计算数组的 中心下标 。
// 数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
// 如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
// 如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返 回 -1 。
//  
// 示例 1：
// 输入：nums = [1, 7, 3, 6, 5, 6]
// 输出：3
// 解释：
// 中心下标是 3 。
// 左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
// 右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
// 示例 2：
// 输入：nums = [1, 2, 3]
// 输出：-1
// 解释：
// 数组中不存在满足此条件的中心下标。
// 示例 3：
// 输入：nums = [2, 1, -1]
// 输出：0
// 解释：
// 中心下标是 0 。
// 左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
// 右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
//  
// 提示：
//  * 1 <= nums.length <= 104
//  * -1000 <= nums[i] <= 1000
//  
// 注意：本题与主站 1991 题相同：https://leetcode-cn.com/problems/find-the-middle-index-in-array/ [https://leetcode-cn.com/problems/find-the-middle-index-in-array/]

// #v1
int pivotIndex(int* nums, int numsSize) {
  if (numsSize == 1) return 0;

  int ret = -1, sum[numsSize], i, end = numsSize - 1;
  sum[0] = nums[0];

  // prefix sum
  for (i = 1; i < numsSize; i++) {
    sum[i] = sum[i-1] + nums[i];
  }

  // 下标 0
  if (sum[end] - sum[0] == 0) return 0;

  // 下标 [2, numsSize-2]
  for (i = 1; i < end; i++) {
    if (sum[i - 1] == sum[end] - sum[i]) {
      ret = i;
      break; // 只取最小
    }
  }
  if (ret >= 0) return ret;

  // 下标 numsSize-1
  if (sum[end - 1] == 0) return end;

  return -1;
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
  printf("%d\n", pivotIndex(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
