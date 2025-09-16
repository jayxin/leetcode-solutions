#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1137. 第 N 个泰波那契数 - 泰波那契序列 Tn 定义如下： 
// T0 = 0, T1 = 1, T2 = 1, 且在 n &gt;= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
// 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
//  
// 示例 1：
// 输入：n = 4
// 输出：4
// 解释：
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// 示例 2：
// 输入：n = 25
// 输出：1389537
//  
// 提示：
//  * 0 &lt;= n &lt;= 37
//  * 答案保证是一个 32 位整数，即 answer &lt;= 2^31 - 1。

// #v1
int tribonacci(int n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;

  int t0 = 0, t1 = 1, t2 = 1, t3;

  for (int i = 3; i <= n; i++) {
    t3 = t0 + t1 + t2;
    t0 = t1;
    t1 = t2;
    t2 = t3;
  }

  return t3;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", tribonacci(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
