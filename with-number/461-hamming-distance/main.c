#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 461. 汉明距离 - 两个整数之间的 汉明距离 [https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB] 指的是这两个数字对应二进制位不同的位置的数目。
// 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
//  
// 示例 1：
// 输入：x = 1, y = 4
// 输出：2
// 解释：
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// 上面的箭头指出了对应二进制位不同的位置。
// 示例 2：
// 输入：x = 3, y = 1
// 输出：1
//  
// 提示：
//  * 0 &lt;= x, y &lt;= 231 - 1
//  
// 注意：本题与 2220. 转换数字的最少位翻转次数 [https://leetcode.cn/problems/minimum-bit-flips-to-convert-number/] 相同。

// #v1
int hammingDistance(int x, int y) {
  int ret = 0;

  while (x || y) {
    if ((x & 1) != (y & 1)) ++ret;
    x >>= 1;
    y >>= 1;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int x, y;
  scanf("%d%d", &x, &y);
  printf("%d\n", hammingDistance(x, y));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
