#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面试 题 05.06. 整数转换 - 整数转换。编写一个函数，确定需要改变几个位才能将整数 A 转成 整数 B。
// 示例 1：
//  输入：A = 29 （或者 0b11101）, B = 15（或者 0b01111）
//  输出：2
// 示例 2：
//  输入：A = 1，B = 2
//  输出：2
// 提示:
//  1. A，B范围在[-2147483648, 2147483647]之间

// #v1
int convertInteger(int A, int B) {
  int c = 0, i = 0;

  while (A || B) {
    if ((A & 1) != (B & 1)) ++c;
    A >>= 1;
    B >>= 1;
    i++;
    if (i >= 32) break;
  }

  return c;
}
// #v1

int main(int argc, char *argv[])
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", convertInteger(a, b));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
