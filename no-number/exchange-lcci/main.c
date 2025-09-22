#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面试 题 05.07. 配对交换 - 配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位 0 与位 1 交换，位 2 与位 3 交换，以此类推）。
// 示例 1：
//  输入：num = 2（或者 0b10）
//  输出：1 (或者 0b01)
// 示例 2：
//  输入：num = 3
//  输出：3
// 提示:
//  1. num 的范围在[0, 2^30 - 1]之间，不会发生整数溢出。

// #v1
int exchangeBits(int num) {
  int c = 0x55555555;
  return ((num >> 1) & c) | ((num << 1) & ~c);
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", exchangeBits(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
