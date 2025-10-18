#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 343. 整数拆分 - 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k &gt;= 2 ），并使这些整数的乘积最大化。
// 返回 你可以获得的最大乘积 。
//  
// 示例 1:
// 输入: n = 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。
// 示例 2:
// 输入: n = 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//  
// 提示:
//  * 2 <= n <= 58

// #v1
int integerBreak(int n) {
  int dp[60];

  dp[2] = 1;
  dp[3] = 2;
  dp[4] = 4;
  dp[5] = 6;
  dp[6] = 9;

  for (int i = 7; i <= n; i++) {
    dp[i] = dp[i-3] * 3;
  }

  return dp[n];
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", integerBreak(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
