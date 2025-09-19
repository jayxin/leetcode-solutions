#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 264. 丑数 II - 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
// 丑数 就是质因子只包含 2、3 和 5 的正整数。
//  
// 示例 1：
// 输入：n = 10
// 输出：12
// 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
// 示例 2：
// 输入：n = 1
// 输出：1
// 解释：1 通常被视为丑数。
//  
// 提示：
//  * 1 &lt;= n &lt;= 1690

// #v1
// 动态规划
#define min(a, b) ((a) <= (b) ? (a) : (b))

int nthUglyNumber(int n) {
  int dp[n+1], idx1 = 1, idx2 = 1, idx3 = 1, v1, v2, v3;

  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    v1 = dp[idx1] * 2;
    v2 = dp[idx2] * 3;
    v3 = dp[idx3] * 5;
    dp[i] = min(v1, min(v2, v3));
    if (dp[i] == v1) ++idx1;
    if (dp[i] == v2) ++idx2;
    if (dp[i] == v3) ++idx3;
  }

  return dp[n];
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", nthUglyNumber(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
