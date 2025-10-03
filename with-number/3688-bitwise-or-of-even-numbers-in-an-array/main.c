#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3688. 偶数的按位或运算 - 给你一个整数数组 nums。
// 返回数组中所有 偶数 的按位 或 运算结果。
// 如果 nums 中没有偶数，返回 0。
//  
// 示例 1：
// 输入： nums = [1,2,3,4,5,6]
// 输出： 6
// 解释：
// 偶数为 2、4 和 6。它们的按位或运算结果是 6。
// 示例 2：
// 输入： nums = [7,9,11]
// 输出： 0
// 解释：
// 数组中没有偶数，因此结果为 0。
// 示例 3：
// 输入： nums = [1,8,16]
// 输出： 24
// 解释：
// 偶数为 8 和 16。它们的按位或运算结果是 24。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 100
//  * 1 &lt;= nums[i] &lt;= 100

// #v1
int evenNumberBitwiseORs(int* nums, int numsSize) {
  int ret = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] & 1) continue;
    ret |= nums[i];
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
  printf("%d\n", evenNumberBitwiseORs(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
