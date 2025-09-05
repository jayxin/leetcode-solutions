#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 279. 完全平 方数 - 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
//  
// 示例 1：
// 输入：n = 12
// 输出：3
// 解释：12 = 4 + 4 + 4
// 示例 2：
// 输入：n = 13
// 输出：2
// 解释：13 = 4 + 9
//  
// 提示：
//  * 1 &lt;= n &lt;= 104

// #v1
#define min(a, b) (a > b ? b : a)

int table[10001];

int _numSquares(int n) {
  int sq = floor(sqrt(n));

  if (sq * sq == n) { // 完全平方数
    table[n] = 1;
  } else {
    int r, t, ret = 1000;
    for (int i = sq; i >= 1; i--) {
      table[i * i] = 1;

      r = n - i * i;
      if (r > 0) {
        if (table[r]) {
          t = table[r];
        } else {
          t = _numSquares(r);
        }
      } else {
        continue;
      }

      ret = min(ret, t + 1);

      if (ret == 2) {
        break;
      }
    }

    table[n] = ret;
  }

  return table[n];
}

int numSquares(int n) {
  memset(table, 0, sizeof(int) * 10001);
  return _numSquares(n);
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", numSquares(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
