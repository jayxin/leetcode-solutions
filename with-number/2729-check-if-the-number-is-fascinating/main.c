#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2729. 判断一个数是否迷人 - 给你一个三位数整数 n 。
// 如果经过以下修改得到的数字 恰好 包含数字 1 到 9 各一次且不包含任何 0 ，那么我们称数字 n 是 迷人的 ：
//  * 将 n 与数字 2 * n 和 3 * n 连接 。
// 如果 n 是迷人的，返回 true，否则返回 false 。
// 连接 两个数字表示把它们首尾相接连在一起。比方说 121 和 371 连接得到 121371 。
//  
// 示例 1：
// 输入：n = 192
// 输出：true
// 解释：我们将数字 n = 192 ，2 * n = 384 和 3 * n = 576 连接，得到 192384576 。这个数字包含 1 到 9 恰好各一次。
// 示例 2：
// 输入：n = 100
// 输出：false
// 解释：我们将数字 n = 100 ，2 * n = 200 和 3 * n = 300 连接，得到 100200300 。这个数字不符合上述条件。
//  
// 提示：
//  * 100 <= n <= 999

// #v1
bool isFascinating(int n) {
  int tmp = n;
  char table[10];
  for (int i = 0; i < 10; i++) {
    table[i] = 0;
  }
  while (tmp) {
    if (table[tmp % 10]) {
      return false;
    } else {
      table[tmp % 10] = 1;
    }
    tmp /= 10;
  }
  if (table[0]) {
    return false;
  }
  int n2 = n * 2;
  while (n2) {
    if (table[n2 % 10]) {
      return false;
    } else {
      table[n2 % 10] = 1;
    }
    n2 /= 10;
  }
  if (table[0]) {
    return false;
  }
  int n3 = n * 3;
  while (n3) {
    if (table[n3 % 10]) {
      return false;
    } else {
      table[n3 % 10] = 1;
    }
    n3 /= 10;
  }
  if (table[0]) {
    return false;
  }
  return true;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (isFascinating(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
