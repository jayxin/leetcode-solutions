#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 507. 完美数 - 对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数 」。
// 给定一个 整数 n， 如果是完美数，返回 true；否则返回 false。
//  
// 示例 1：
// 输入：num = 28
// 输出：true
// 解释：28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, 和 14 是 28 的所有正因子。
// 示例 2：
// 输入：num = 7
// 输出：false
//  
// 提示：
//  * 1 &lt;= num &lt;= 108

// #v1
bool checkPerfectNumber(int num) {
  if (num == 1) return false;
  int sum = 1,
      r = sqrt(num);
  for (int i = 2; i <= r; ++i) {
    int tmp = num % i;
    if (!tmp) {
      int theOther = num / i;
      if (theOther == i)
        sum += i;
      else
        sum += i + theOther;
    }
  }
  if (sum == num) return true;
  return false;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (checkPerfectNumber(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
