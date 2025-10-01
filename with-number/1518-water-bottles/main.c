#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1518. 换水问 题 - 超市正在促销，你可以用 numExchange 个空水瓶从超市兑换一瓶水。最开始，你一共 购入了 numBottles 瓶水。
// 如果喝掉了水瓶中的水，那么水瓶就会变成空的。
// 给你两个整数 numBottles 和 numExchange ，返回你 最多 可以喝到多少瓶水。
//  
// 示例 1：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/sample_1_1875.png]
// 输入：numBottles = 9, numExchange = 3
// 输出：13
// 解释：你可以用 3 个空瓶兑换 1 瓶水。
// 所以最多能喝到 9 + 3 + 1 = 13 瓶水。
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/sample_2_1875.png]
// 输入：numBottles = 15, numExchange = 4
// 输出：19
// 解释：你可以用 4 个空瓶兑换 1 瓶水。
// 所以最多能喝到 15 + 3 + 1 = 19 瓶水。
//  
//  
// 提示：
//  * 1 &lt;= numBottles &lt;= 100
//  * 2 &lt;= numExchange &lt;= 100

// #v1
int numWaterBottles(int numBottles, int numExchange) {
  int ret = 0, q, r;

  while (numBottles >= numExchange) {
    q = numBottles / numExchange;
    r = numBottles % numExchange;

    ret += numBottles - r;
    numBottles = q + r;
  }

  ret += numBottles;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n, m;
  scanf("%d%d", &m, &n);
  printf("%d\n", numWaterBottles(m, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
