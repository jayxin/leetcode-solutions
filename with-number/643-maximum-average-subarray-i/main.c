#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 643. 子数组最大平均数 I - 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
// 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
// 任何误差小于 10-5 的答案都将被视为正确答案。
//  
// 示例 1：
// 输入：nums = [1,12,-5,-6,50,3], k = 4
// 输出：12.75
// 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
// 示例 2：
// 输入：nums = [5], k = 1
// 输出：5.00000
//  
// 提示：
//  * n == nums.length
//  * 1 &lt;= k &lt;= n &lt;= 105
//  * -104 &lt;= nums[i] &lt;= 104

// #v1
double findMaxAverage(int* nums, int numsSize, int k) {
  double ret, t = 0;
  int i, l, r;
  for (i = 0; i < k; i++) {
    t += nums[i];
  }
  ret = t;

  l = 1;
  r = k;
  while (r < numsSize) {
    t = t - nums[l-1] + nums[r];
    if (ret < t) ret = t;
    ++l;
    ++r;
  }

  return ret / k;
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
  int n, k, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%.2lf\n", findMaxAverage(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
