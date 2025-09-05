#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 441. 排列硬币 - 你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
// 给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/04/09/arrangecoins1-grid.jpg]
// 输入：n = 5
// 输出：2
// 解释：因为第三行不完整，所以返回 2 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/04/09/arrangecoins2-grid.jpg]
// 输入：n = 8
// 输出：3
// 解释：因为第四行不完整，所以返回 3 。
//  
// 提示：
//  * 1 <= n <= 231 - 1

//// #v1
//int arrangeCoins(int n) {
  //int i = 0;
  //long sum = 0;
  //while (sum <= n) {
    //i++;
    //sum += i;
  //}
  //return i - 1;
//}
//// #v1

// #v2
// binary search
int arrangeCoins(int n) {
  int64_t l = 1, r = n, m;
  int64_t sum;
  while (l < r) {
    m = l + (r - l) / 2;
    sum = (1 + m) * m / 2;
    if (sum < n) {
      l = m + 1;
    } else if (sum > n) {
      r = m - 1;
    } else {
      return m;
    }
  }
  sum = (1 + m) * m / 2;
  if (sum > n) --l;
  return l;
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", arrangeCoins(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
