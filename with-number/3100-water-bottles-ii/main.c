#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3100. 换水问题 II - 给你两个整数 numBottles 和 numExchange 。
// numBottles 代表你最初拥有的满水瓶数量。在一次操作中，你可以执行以下操作之一：
//  * 喝掉任意数量的满水瓶，使它们变成空水瓶。
//  * 用 numExchange 个空水瓶交换一个满水瓶。然后，将 numExchange 的值增加 1 。
// 注意，你不能使用相同的 numExchange 值交换多批空水瓶。例如，如果 numBottles == 3  并且 numExchange == 1 ，则不能用 3 个空水瓶交换成 3 个满水瓶。
// 返回你 最多 可以喝到多少瓶水。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2024/01/28/exampleone1.png]
// 输入：numBottles = 13, numExchange = 6
// 输出：15
// 解释：上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶 数量。
// 示例 2：
// [https://assets.leetcode.com/uploads/2024/01/28/example231.png]
// 输入：numBottles = 10, numExchange = 3
// 输出：13
// 解释：上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶 数量。
//  
// 提示：
//  * 1 &lt;= numBottles &lt;= 100
//  * 1 &lt;= numExchange &lt;= 100

// #v1
int maxBottlesDrunk(int numBottles, int numExchange) {
  int ret = 0, emptyBottles = 0;

  // 满水瓶非零 或者 空水瓶可以继续交换
  while (numBottles || emptyBottles >= numExchange) {
    if (emptyBottles >= numExchange) {
      emptyBottles -= numExchange;
      ++numBottles;
      ++numExchange;
    } else {
      ret += numBottles;
      emptyBottles += numBottles;
      numBottles = 0;
    }
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n, m;
  scanf("%d%d", &m, &n);
  printf("%d\n", maxBottlesDrunk(m, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
