#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2427. 公 因子的数目 - 给你两个正整数 a 和 b ，返回 a 和 b 的 公 因子的数目。
// 如果 x 可以同时整除 a 和 b ，则认为 x 是 a 和 b 的一个 公因子 。
//  
// 示例 1：
// 输入：a = 12, b = 6
// 输出：4
// 解释：12 和 6 的公因子是 1、2、3、6 。
// 示例 2：
// 输入：a = 25, b = 30
// 输出：2
// 解释：25 和 30 的公因子是 1、5 。
//  
// 提示：
//  * 1 &lt;= a, b &lt;= 1000

// #v1
#define min(a, b) ((a) <= (b) ? (a) : (b))
int commonFactors(int a, int b) {
  int m = min(a, b), cnt = 1;

  for (int i = 2; i <= m; i++) {
    if (a % i == 0 && b % i == 0) ++cnt;
  }

  return cnt;
}
// #v1

int main(int argc, char *argv[])
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", commonFactors(a, b));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
