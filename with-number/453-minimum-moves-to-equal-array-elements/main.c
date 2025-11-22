#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 453. 最小操作次数使数组元素相等 - 给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。
//  
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：3
// 解释：
// 只需要3次操作（注意每次操作会增加两个元素的值）：
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// 示例 2：
// 输入：nums = [1,1,1]
// 输出：0
//  
// 提示：
//  * n == nums.length
//  * 1 <= nums.length <= 105
//  * -109 <= nums[i] <= 109
//  * 答案保证符合 32-bit 整数

// #v1
// 假设最小的操作次数为 k, 每次数组的和会增加 n-1
// min 是 nums 中最小的元素
// 则 (sum(nums) + k*(n-1))/n == min + k
// i.e. sum(nums) + (n-1)*k == n*min + n*k
// sum(nums)-n*min == k
int minMoves(int* nums, int numsSize) {
  int k, minVal, sum;

  minVal = sum = nums[0];
  for (int i = 1; i < numsSize; i++) {
    sum += nums[i];
    if (nums[i] < minVal) minVal = nums[i];
  }

  k = sum - numsSize * minVal;

  return k;
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
  printf("%d\n", minMoves(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
