#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3309. 连接二进制表示可形成的最大数值 - 给你一个长度为 3 的整数数组 nums 。
// 现以某种顺序 连接 数组 nums 中所有元素的 二进制表示 ，请你返回可以由这种方法形成 的 最大 数值。
// 注意 任何数字的二进制表示 不含 前导零。
//  
// 示例 1:
// 输入: nums = [1,2,3]
// 输出: 30
// 解释:
// 按照顺序 [3, 1, 2] 连接数字的二进制表示，得到结果 "11110"，这是 30 的二进制表示。
// 示例 2:
// 输入: nums = [2,8,16]
// 输出: 1296
// 解释:
// 按照顺序 [2, 8, 16] 连接数字的二进制表述，得到结果 "10100010000"，这是 1296 的二进制表示。
//  
// 提示:
//  * nums.length == 3
//  * 1 &lt;= nums[i] &lt;= 127

// #v1
int m;

int countBits(int n) {
  int cnt = 0;

  while (n) {
    ++cnt;
    n >>= 1;
  }

  return cnt;
}

void swap(int *a, int *b, int i, int j) {
  if (i == j) return ;
  int tmp;

  tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;

  tmp = b[i];
  b[i] = b[j];
  b[j] = tmp;
}

void _maxGoodNumber(int *nums, int *bits, int cur) {
  if (cur == 3) {
    int res = nums[2];
    res += nums[1] << bits[2];
    res += nums[0] << (bits[1] + bits[2]);
    if (res > m) m = res;
    return ;
  }

  for (int i = cur; i < 3; i++) {
    _maxGoodNumber(nums, bits, cur + 1);
    swap(nums, bits, cur, i);
    _maxGoodNumber(nums, bits, cur + 1);
    swap(nums, bits, cur, i);
  }
}

int maxGoodNumber(int* nums, int numsSize) {
  int bits[3], i;
  for (i = 0; i < numsSize; i++) bits[i] = countBits(nums[i]);
  m = -1;
  _maxGoodNumber(nums, bits, 0);
  return m;
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
  printf("%d\n", maxGoodNumber(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
