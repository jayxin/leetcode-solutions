#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2235. 两整 数相加 - 给你两个整数 num1 和 num2，返回这两个整数的和。
//  
// 示例 1：
// 输入：num1 = 12, num2 = 5
// 输出：17
// 解释：num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
// 示例 2：
// 输入：num1 = -10, num2 = 4
// 输出：-6
// 解释：num1 + num2 = -6 ，因此返回 -6 。
//  
// 提示：
//  * -100 &lt;= num1, num2 &lt;= 100

// #v1
int sum(int num1, int num2) {
  return num1 + num2;
}
// #v1

int main(int argc, char *argv[])
{
  int n1, n2;
  scanf("%d%d", &n1, &n2);
  printf("%d\n", sum(n1, n2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
