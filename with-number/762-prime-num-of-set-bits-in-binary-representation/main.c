#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 762. 二进制表示中质数个计算置位 - 给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。
// 计算置位位数 就是二进制表示中 1 的个数。
//  * 例如， 21 的二进制表示 10101 有 3 个计算置位。
//  
// 示例 1：
// 输入：left = 6, right = 10
// 输出：4
// 解释：
// 6 -> 110 (2 个计算置位，2 是质数)
// 7 -> 111 (3 个计算置位，3 是质数)
// 9 -> 1001 (2 个计算置位，2 是质数)
// 10-> 1010 (2 个计算置位，2 是质数)
// 共计 4 个计算置位为质数的数字。
// 示例 2：
// 输入：left = 10, right = 15
// 输出：5
// 解释：
// 10 -> 1010 (2 个计算置位, 2 是质数)
// 11 -> 1011 (3 个计算置位, 3 是质数)
// 12 -> 1100 (2 个计算置位, 2 是质数)
// 13 -> 1101 (3 个计算置位, 3 是质数)
// 14 -> 1110 (3 个计算置位, 3 是质数)
// 15 -> 1111 (4 个计算置位, 4 不是质数)
// 共计 5 个计算置位为质数的数字。
//  
// 提示：
//  * 1 <= left <= right <= 10^6
//  * 0 <= right - left <= 10^4

// #v1
int countBits(int x) {
  int cnt = 0;

  while (x) {
    x -= x & -x;
    ++cnt;
  }

  return cnt;
}

int countPrimeSetBits(int left, int right) {
  int ret = 0, i, t, l, r, m;
  int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};

  for (i = left; i <= right; i++) {
    t = countBits(i);

    // binary search
    l = 0, r = 7;
    while (l < r) {
      m = (l + r) >> 1;
      if (primes[m] < t) l = m + 1;
      else r = m;
    }

    if (primes[l] == t) ++ret;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int l, r;
  scanf("%d%d", &l, &r);
  printf("%d\n", countPrimeSetBits(l, r));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
