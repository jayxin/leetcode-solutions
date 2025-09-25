#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1523. 在区间范围内统计奇数数目 - 给你两个非负整数 low 和 high 。请你返回 low  和 high 之间（包括二者）奇数的数目。
//  
// 示例 1：
// 输入：low = 3, high = 7
// 输出：3
// 解释：3 到 7 之间奇数数字为 [3,5,7] 。
// 示例 2：
// 输入：low = 8, high = 10
// 输出：1
// 解释：8 到 10 之间奇数数字为 [9] 。
//  
// 提示：
//  * 0 &lt;= low &lt;= high &lt;= 10^9

// #v1
int countOdds(int low, int high) {
  // 区间长度
  int l = high - low + 1;

  // 区间长度为奇数
  if (l & 1) return (l >> 1) + (high & 1);

  // 区间长度为偶数, 则奇数与偶数数量相同
  return l >> 1;
}
// #v1

int main(int argc, char *argv[])
{
  int l, h;
  scanf("%d%d", &l, &h);
  printf("%d\n", countOdds(l, h));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
