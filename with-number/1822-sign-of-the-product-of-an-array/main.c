#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1822. 数组元素积的符号 - 已知函数 signFunc(x) 将会根据 x 的正负返回特定值：
//  * 如果 x 是正数，返回 1 。
//  * 如果 x 是负数，返回 -1 。
//  * 如果 x 是等于 0 ，返回 0 。
// 给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。
// 返回 signFunc(product) 。
//  
// 示例 1：
// 输入：nums = [-1,-2,-3,-4,3,2,1]
// 输出：1
// 解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1
// 示例 2：
// 输入：nums = [1,5,0,2,-3]
// 输出：0
// 解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0
// 示例 3：
// 输入：nums = [-1,1,-1,1,-1]
// 输出：-1
// 解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 1000
//  * -100 &lt;= nums[i] &lt;= 100

// #v1
int arraySign(int* nums, int numsSize) {
  int s = 1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] < 0) {
      s = -s;
    } else if (!nums[i]) {
      return 0;
    }
  }

  return s;
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
  printf("%d\n", arraySign(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
