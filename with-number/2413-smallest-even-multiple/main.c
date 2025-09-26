#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2413. 最小 偶倍数 - 给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。
//  
// 示例 1：
// 输入：n = 5
// 输出：10
// 解释：5 和 2 的最小公倍数是 10 。
// 示例 2：
// 输入：n = 6
// 输出：6
// 解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
//  
// 提示：
//  * 1 &lt;= n &lt;= 150

// #v1
int smallestEvenMultiple(int n) {
  if (n & 1) return n << 1;
  return n;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", smallestEvenMultiple(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
