#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3300. 替换为数位和以后的最小元素 - 给你一个整数数组 nums 。
// 请你将 nums 中每一个元素都替换为它的各个数位之 和 。
// 请你返回替换所有元素以后 nums 中的 最小 元素。
//  
// 示例 1：
// 输入：nums = [10,12,13,14]
// 输出：1
// 解释：
// nums 替换后变为 [1, 3, 4, 5] ，最小元素为 1 。
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：1
// 解释：
// nums 替换后变为 [1, 2, 3, 4] ，最小元素为 1 。
// 示例 3：
// 输入：nums = [999,19,199]
// 输出：10
// 解释：
// nums 替换后变为 [27, 10, 19] ，最小元素为 10 。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= nums[i] <= 104

// #v1
int getDigitSum(int x) {
  int sum = 0;

  while (x) {
    sum += x % 10;
    x /= 10;
  }

  return sum;
}

#define INF 0x3f3f3f3f

int minElement(int* nums, int numsSize) {
  int ret = INF, sum;

  for (int i = 0; i < numsSize; i++) {
    sum = getDigitSum(nums[i]);
    if (sum < ret) ret = sum;
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
  printf("%d\n", minElement(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
