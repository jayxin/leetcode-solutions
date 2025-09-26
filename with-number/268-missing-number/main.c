#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 268. 丢失的 数字 - 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现 在数组中的那个数。
//  
// 示例 1：
// 输入：nums = [3,0,1]
// 输出：2
// 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
// 示例 2：
// 输入：nums = [0,1]
// 输出：2
// 解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
// 示例 3：
// 输入：nums = [9,6,4,2,3,5,7,0,1]
// 输出：8
// 解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
// 提示：
//  * n == nums.length
//  * 1 &lt;= n &lt;= 104
//  * 0 &lt;= nums[i] &lt;= n
//  * nums 中的所有数字都 独一无二
//  
// 进阶：你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?

// #v1
int missingNumber(int* nums, int numsSize) {
  int ret = 0, i;

  for (i = 1; i <= numsSize; i++) ret ^= i;
  for (i = 0; i < numsSize; i++) ret ^= nums[i];

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
  printf("%d\n", missingNumber(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
