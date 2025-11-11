#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2455. 可被三整除的偶数的平均值 - 给你一个由正整数组成的整数数组 nums ，返回其 中可被 3 整除的所有偶数的平均值。
// 注意：n 个元素的平均值等于 n 个元素 求和 再除以 n ，结果 向下取整 到最接近的整数 。
//  
// 示例 1：
// 输入：nums = [1,3,6,10,12,15]
// 输出：9
// 解释：6 和 12 是可以被 3 整除的偶数。(6 + 12) / 2 = 9 。
// 示例 2：
// 输入：nums = [1,2,4,7,10]
// 输出：0
// 解释：不存在满足题目要求的整数，所以返回 0 。
//  
// 提示：
//  * 1 <= nums.length <= 1000
//  * 1 <= nums[i] <= 1000

// #v1
int averageValue(int* nums, int numsSize) {
  int sum = 0, c = 0;

  for (int i = 0; i < numsSize; i++) {
    if ((nums[i] & 1) || nums[i] % 3) continue;
    sum += nums[i];
    ++c;
  }

  if (!c) return 0;

  return sum / c;
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
  printf("%d\n", averageValue(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
