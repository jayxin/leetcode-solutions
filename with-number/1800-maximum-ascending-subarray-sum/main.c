#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1800. 最大升序子数组和 - 给你一个正整数组成的数组 nums ，返回 nums 中一个 严格递增子数组 的最大可能元素和。
// 子数组是数组中的一个连续数字序列。
//  
// 示例 1：
// 输入：nums = [10,20,30,5,10,50]
// 输出：65
// 解释：[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
// 示例 2：
// 输入：nums = [10,20,30,40,50]
// 输出：150
// 解释：[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。
// 示例 3：
// 输入：nums = [12,17,15,13,10,11,12]
// 输出：33
// 解释：[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= nums[i] <= 100

// #v1
int maxAscendingSum(int* nums, int numsSize) {
  int i = 1, maxVal = nums[0], t = nums[0];


  while (i < numsSize) {
    if (nums[i] > nums[i-1]) {
      t += nums[i];
    } else {
      if (t > maxVal) maxVal = t;
      t = nums[i];
    }

    ++i;
  }

  if (t > maxVal) maxVal = t;

  return maxVal;
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
  printf("%d\n", maxAscendingSum(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
