#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3750. 最少反转次数得到翻转二进制字符串 - 给你一个 正 整数 n。
// 令 s 为 n 的 二进制表示（不含前导零）。
// 二进制字符串 s 的 反转 是指将 s 中的字符按相反顺序排列得到的字符串。
// 你可以翻转 s 中的任意一位（将 0 → 1 或 1 → 0）。每次翻转 仅 影响一位。
// 请返回使 s 等于其原始形式的反转所需的 最少 翻转次数。
//  
// 示例 1：
// 输入： n = 7
// 输出： 0
// 解释：
// 7 的二进制表示为 "111"。其反转也是 "111"，两者相同。因此，不 需要翻转。
// 示例 2：
// 输入： n = 10
// 输出： 4
// 解释：
// 10 的二进制表示为 "1010"。其反转为 "0101"。必须翻转所有四位才能使它们相等。因此，所需的最少翻转次数为 4。
//  
// 提示：
//  * 1 <= n <= 109

// #v1
int minimumFlips(int n) {
  int x = n, t = 0, c = 0;

  // reverse n in binary representation
  while (x) {
    t = (t << 1) + (x & 1);
    x >>= 1;
  }

  while (n || t) {
    if ((n & 1) != (t & 1)) ++c;

    n >>= 1;
    t >>= 1;
  }

  return c;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", minimumFlips(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
