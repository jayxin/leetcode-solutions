#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1413. 逐步求和得到正数的最小值 - 给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
// 你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
// 请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue 。
//  
// 示例 1：
// 输入：nums = [-3,2,-3,4,2]
// 输出：5
// 解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
//                 累加求和
//                 startValue = 4 | startValue = 5 | nums
//                   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
//                   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
//                   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
//                   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
//                   (4 +2 ) = 6  | (5 +2 ) = 7    |   2
// 示例 2：
// 输入：nums = [1,2]
// 输出：1
// 解释：最小的 startValue 需要是正数。
// 示例 3：
// 输入：nums = [1,-2,-3]
// 输出：5
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * -100 <= nums[i] <= 100

// #v1
int minStartValue(int* nums, int numsSize) {
  int prevSum, sum, i, minPrefixSum;

  prevSum = nums[0];
  minPrefixSum = prevSum;
  for (i = 1; i < numsSize; i++) {
    sum = prevSum + nums[i];
    prevSum = sum;
    if (sum < minPrefixSum) minPrefixSum = sum;
  }

  if (minPrefixSum >= 0) return 1;

  return -minPrefixSum + 1;
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
  printf("%d\n", minStartValue(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
