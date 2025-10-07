#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 122. 买卖股票的最佳时机 II - 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。然而，你可以在 同一天 多次买卖该股票，但要确保你持有的股票不超过一股。
// 返回 你能获得的 最大 利润 。
//  
// 示例 1：
// 输入：prices = [7,1,5,3,6,4]
// 输出：7
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出,  这笔交易所能获得利润 = 5 - 1 = 4。
// 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出,  这笔交易所能获得利润 = 6 - 3 = 3。
// 最大总利润为 4 + 3 = 7 。
// 示例 2：
// 输入：prices = [1,2,3,4,5]
// 输出：4
// 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
// 最大总利润为 4 。
// 示例 3：
// 输入：prices = [7,6,4,3,1]
// 输出：0
// 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润 为 0。
//  
// 提示：
//  * 1 &lt;= prices.length &lt;= 3 * 104
//  * 0 &lt;= prices[i] &lt;= 104

//// #v1
//// 超时
//// 不完全动态规划
//int max(int a, int b) { return a >= b ? a : b; }
//
//int maxProfit(int* prices, int pricesSize) {
  //int dp[pricesSize], i, j;
//
  //dp[0] = 0;
  //for (i = 1; i < pricesSize; i++) {
    //// 不进行交易
    //dp[i] = dp[i-1];
//
    //// 进行交易
    //for (j = 0; j < i; j++) {
      //if (j) dp[i] = max(dp[i], prices[i] - prices[j] + dp[j-1]);
      //else dp[i] = max(dp[i], prices[i] - prices[0]);
    //}
  //}
//
  //return dp[pricesSize - 1];
//}
//// #v1

// #v2
int max(int a, int b) { return a >= b ? a : b; }

int maxProfit(int* prices, int pricesSize) {
  int dp[pricesSize], i, j, cur, t;

  // init
  dp[0] = 0;
  // cur 记录可以用来交易(买入)的价格的索引
  cur = 0;

  for (i = 1; i < pricesSize; i++) {
    // 不进行交易
    dp[i] = dp[i-1];

    // 进行交易
    // 在 cur 买入, 在 i 卖出
    t = prices[i] - prices[cur];
    if (cur) t += dp[cur-1];

    dp[i] = max(t, dp[i]);

    // 没有发生交易(卖出), 更新 cur
    if (dp[i] == dp[i-1]) cur = i;
  }

  return dp[pricesSize - 1];
}
// #v2

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", maxProfit(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
