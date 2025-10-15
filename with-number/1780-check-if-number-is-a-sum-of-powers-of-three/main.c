#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1780. 判断一个数字是否可以表示成三的幂的和 - 给你一个整数 n ，如果你可以将 n 表示成若干个不同的三的幂之和，请你返回 true ，否则请返回 false 。
// 对于一个整数 y ，如果存在整数 x 满足 y == 3x ，我们称这个整数 y 是三的幂。
//  
// 示例 1：
// 输入：n = 12
// 输出：true
// 解释：12 = 3^1 + 3^2
// 示例 2：
// 输入：n = 91
// 输出：true
// 解释：91 = 3^0 + 3^2 + 3^4
// 示例 3：
// 输入：n = 21
// 输出：false
//  
// 提示：
//  * 1 &lt;= n &lt;= 107
// The number can not be represented as a sum of powers of 3 if it's ternary
// presentation has a 2 in it

// #v1
bool checkPowersOfThree(int n) {
  int r;

  while (n) {
    r = n % 3;
    if (r == 2) return false;
    n /= 3;
  }

  return true;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (checkPowersOfThree(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
