#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2239. 找到最接近 0 的数字 - 给你一个长度为 n 的整数数组 nums ，请你返回 nums 中最  接近 0 的数字。如果有多个答案，请你返回它们中的 最大值 。
//  
// 示例 1：
// 输入：nums = [-4,-2,1,4,8]
// 输出：1
// 解释：
// -4 到 0 的距离为 |-4| = 4 。
// -2 到 0 的距离为 |-2| = 2 。
// 1 到 0 的距离为 |1| = 1 。
// 4 到 0 的距离为 |4| = 4 。
// 8 到 0 的距离为 |8| = 8 。
// 所以，数组中距离 0 最近的数字为 1 。
// 示例 2：
// 输入：nums = [2,-1,1]
// 输出：1
// 解释：1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。
//  
// 提示：
//  * 1 <= n <= 1000
//  * -105 <= nums[i] <= 105

// #v1
int findClosestNumber(int* nums, int numsSize) {
  int ret = nums[0], retAbs = ret >= 0 ? ret : -ret;

  for (int i = 1; i < numsSize; i++) {
    int abs = nums[i] >= 0 ? nums[i] : -nums[i];

    if (abs < retAbs) {
      ret = nums[i];
      retAbs = abs;
    } else if (abs == retAbs && nums[i] > ret) {
      ret = nums[i];
    }
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
  printf("%d\n", findClosestNumber(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
