#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3370. 仅含置位位的最小整数 - 给你一个正整数 n。
// 返回 大于等于 n 且二进制表示仅包含 置位 位的 最小 整数 x 。
// 置位 位指的是二进制表示中值为 1 的位。
//  
// 示例 1：
// 输入： n = 5
// 输出： 7
// 解释：
// 7 的二进制表示是 "111"。
// 示例 2：
// 输入： n = 10
// 输出： 15
// 解释：
// 15 的二进制表示是 "1111"。
// 示例 3：
// 输入： n = 3
// 输出： 3
// 解释：
// 3 的二进制表示是 "11"。
//  
// 提示：
//  * 1 &lt;= n &lt;= 1000
// Find the strictly greater power of 2, and subtract 1 from it.

// #v1
int smallestNumber(int n) {
  int bitCnt = 0;

  while (n) {
    bitCnt++;
    n >>= 1;
  }

  return (1 << bitCnt) - 1;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", smallestNumber(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
