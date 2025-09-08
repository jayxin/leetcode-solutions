#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1295. 统计位数为偶数的数字 - 给你一个整数数组 nums，请你返回其中包含 偶数 个数位的数字的个数。
//  
// 示例 1：
// 输入：nums = [12,345,2,6,7896]
// 输出：2
// 解释：
// 12 是 2 位数字（位数为偶数） 
// 345 是 3 位数字（位数为奇数）  
// 2 是 1 位数字（位数为奇数） 
// 6 是 1 位数字 位数为奇数） 
// 7896 是 4 位数字（位数为偶数）  
// 因此只有 12 和 7896 是位数为偶数的数字
// 示例 2：
// 输入：nums = [555,901,482,1771]
// 输出：1
// 解释：
// 只有 1771 是位数为偶数的数字。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 500
//  * 1 &lt;= nums[i] &lt;= 105

// #v1
int countDigits(int x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

int findNumbers(int* nums, int numsSize) {
  int ret = 0;
  for (int i = 0; i < numsSize; i++) {
    if (countDigits(nums[i]) & 1)
      continue;
    ret++;
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
  printf("%d\n", findNumbers(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
