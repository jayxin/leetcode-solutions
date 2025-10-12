#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 714. 买卖股票的最佳时机含手续费 - 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票， 在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手 续费。
//  
// 示例 1：
// 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
// 输出：8
// 解释：能够达到的最大利润:
// 在此处买入 prices[0] = 1
// 在此处卖出 prices[3] = 8
// 在此处买入 prices[4] = 4
// 在此处卖出 prices[5] = 9
// 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
// 示例 2：
// 输入：prices = [1,3,7,5,10,3], fee = 3
// 输出：6
//  
// 提示：
//  * 1 <= prices.length <= 5 * 104
//  * 1 <= prices[i] < 5 * 104
//  * 0 <= fee < 5 * 104

// #v1
#define max(a, b) ((a) >= (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize, int fee) {
  // dp[i][0] 表示第 i 天交易后手里没有股票的最大利润
  // dp[i][1] 表示第 i 天交易后手里持有 1 支股票的最大利润
  int dp[pricesSize][2];

  // init
  dp[0][0] = 0;
  dp[0][1] = -prices[0];

  for (int i = 1; i < pricesSize; i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
  }

  return dp[pricesSize - 1][0];
}
// #v1

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
  int n, *a, f;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &f);
  printf("%d\n", maxProfit(a, n, f));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
