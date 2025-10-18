#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 371. 两整数 之和 - 给你两个整数 a 和 b ，不使用 运算符 + 和 -  ，计算并返回两整数之和。
//  
// 示例 1：
// 输入：a = 1, b = 2
// 输出：3
// 示例 2：
// 输入：a = 2, b = 3
// 输出：5
//  
// 提示：
//  * -1000 &lt;= a, b &lt;= 1000

// #v1
int getSum(int a, int b) {
  int ret = 0, carry = 0, i = 0, p, q, r;

  while (i <= 31) {
    p = (a >> i) & 1;
    q = (b >> i) & 1;
    r = p ^ q ^ carry;

    // 确定进位
    // p, q, carry 中 >= 2 个 1 则 carry == 1
    if (carry) {
      if (p || q) carry = 1;
      else carry = 0;
    } else {
      if (p && q) carry = 1;
      else carry = 0;
    }

    ret |= (int64_t)r << i;

    ++i;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", getSum(a, b));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
