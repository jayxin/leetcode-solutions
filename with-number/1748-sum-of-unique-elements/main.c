#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1748. 唯 一元素的和 - 给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
// 请你返回 nums 中唯一元素的 和 。
//  
// 示例 1：
// 输入：nums = [1,2,3,2]
// 输出：4
// 解释：唯一元素为 [1,3] ，和为 4 。
// 示例 2：
// 输入：nums = [1,1,1,1,1]
// 输出：0
// 解释：没有唯一元素，和为 0 。
// 示例 3 ：
// 输入：nums = [1,2,3,4,5]
// 输出：15
// 解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= nums[i] <= 100

// #v1
int sumOfUnique(int* nums, int numsSize) {
  int sum = 0, t[101] = {0}, i;

  // count
  for (i = 0; i < numsSize; i++) ++t[nums[i]];

  for (i = 1; i <= 100; i++) {
    if (t[i] == 1) sum += i;
  }

  return sum;
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
  printf("%d\n", sumOfUnique(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
