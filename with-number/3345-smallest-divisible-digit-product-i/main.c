#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3345. 最小可整除数位乘积 I - 给你两个整数 n 和 t 。请你返回大于等于 n 的 最小 整数，且该整数的 各数位之积 能被 t 整除。
//  
// 示例 1：
// 输入：n = 10, t = 2
// 输出：10
// 解释：
// 10 的数位乘积为 0 ，可以被 2 整除，所以它是大于等于 10 且满足题目要求的最小整数。
// 示例 2：
// 输入：n = 15, t = 3
// 输出：16
// 解释：
// 16 的数位乘积为 6 ，可以被 3 整除，所以它是大于等于 15 且满足题目要求的最小整数。
//  
// 提示：
//  * 1 <= n <= 100
//  * 1 <= t <= 10

// #v1
int smallestNumber(int n, int t) {
  for (int i = n; i < n+10; i++) {
    int x = i, product = 1;
    while (x) {
      product *= x % 10;
      x /= 10;
    }
    if (product % t == 0) return i;
  }

  return 0;
}
// #v1

int main(int argc, char *argv[])
{
  int n, t;
  scanf("%d%d", &n, &t);
  printf("%d\n", smallestNumber(n, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
