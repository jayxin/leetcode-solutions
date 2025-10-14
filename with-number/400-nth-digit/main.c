#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 400. 第 N 位数字 - 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。
//  
// 示例 1：
// 输入：n = 3
// 输出：3
// 示例 2：
// 输入：n = 11
// 输出：0
// 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
//  
// 提示：
//  * 1 <= n <= 2^31 - 1

// #v1
// prefix sum, math, binary search
int mypow(int x, int n) {
  int ret = 1;

  while (n) {
    if (n & 1) ret *= x;
    n >>= 1;
    if (n) x *= x;
  }

  return ret;
}

int findNthDigit(int n) {
  // edge case
  if (n <= 9) return n;

  int i, l, r, m, quotient, remainder, t, dest, digits[11], len;
  int64_t arr[10] = {0}, weight = 1LL;

  // arr[i] 表示从 1 位数字到 i 位数字总共可以形成多少个 digit
  // 1 位: 1-9, 形成 9 * 1 个 digit
  // 2 位: 10-99, 形成 90 * 2 个 digit
  // 3 位: 100-999, 形成 900 * 3 个 digit
  // ...
  for (i = 1; i <= 9; i++) {
    arr[i] = arr[i-1] + 9LL * weight * i;
    weight *= 10LL;
  }

  // binary search
  // find lower bound
  l = 0, r = 9;
  while (l < r) {
    m = (l + r + 1) >> 1;
    if (arr[m] <= n) l = m;
    else r = m - 1;
  }

  // n 在 arr 中出现
  if (arr[l] == n) return 9;

  // n 介于 arr 的某两个元素之间
  // arr[l] < n < arr[l+1]
  t = n - arr[l];
  quotient = t / (l + 1);
  remainder = t % (l + 1);
  dest = mypow(10, l) + quotient - 1;

  // 整除
  if (!remainder) return dest % 10;

  // 非整除
  // 分解数字
  t = dest + 1;
  len = 0;
  while (t) {
    digits[len++] = t % 10;
    t /= 10;
  }

  for (i = len - 1; i >= 0; i--) {
    --remainder;
    if (!remainder) return digits[i];
  }

  return 0;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", findNthDigit(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
