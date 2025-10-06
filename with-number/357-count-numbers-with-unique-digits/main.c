#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 357. 统计各位数字都不同的数字个数 - 给你一个整数 n
// ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n 。
//  
// 示例 1：
// 输入：n = 2
// 输出：91
// 解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围 内的所有数字。
// 示例 2：
// 输入：n = 0
// 输出：1
//  
// 提示：
//  * 0 <= n <= 8

// #v1
int countNumbersWithUniqueDigits(int n) {
  int c = 1, digits, f, t, product;

  for (int i = 1; i <= n; i++) {
    // product 是 i 个数位不同的数字个数
    product = 1;
    // t 表示某个数位有几种选择
    t = 9;
    // digits 代表有多少个数位
    digits = i;
    // f 是标志位
    f = 1;

    while (digits--) {
      product *= t;

      // > 9 的数字, 9 需要乘 2 次
      if (f && t == 9) {
        f = 0;
        continue;
      }

      --t;
    }

    c += product;
  }

  return c;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", countNumbersWithUniqueDigits(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
