#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1979. 找出数组的最大公约数 - 给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。
// 两个数的 最大公约数 是能够被两个数整除的最大正整数。
//  
// 示例 1：
// 输入：nums = [2,5,6,9,10]
// 输出：2
// 解释：
// nums 中最小的数是 2
// nums 中最大的数是 10
// 2 和 10 的最大公约数是 2
// 示例 2：
// 输入：nums = [7,5,6,8,3]
// 输出：1
// 解释：
// nums 中最小的数是 3
// nums 中最大的数是 8
// 3 和 8 的最大公约数是 1
// 示例 3：
// 输入：nums = [3,3]
// 输出：3
// 解释：
// nums 中最小的数是 3
// nums 中最大的数是 3
// 3 和 3 的最大公约数是 3
//  
// 提示：
//  * 2 <= nums.length <= 1000
//  * 1 <= nums[i] <= 1000

// #v1
int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int findGCD(int* nums, int numsSize) {
  int max = -1, min = 1001;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];
  }

  return gcd(max, min);
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
  printf("%d\n", findGCD(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
