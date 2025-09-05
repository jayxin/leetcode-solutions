#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 121. 买卖股票的最佳时机 - 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给 定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计 一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//
// 示例 1：
// 输入：[7,1,5,3,6,4]
// 输出：5
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出， 最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 示例 2：
// 输入：prices = [7,6,4,3,1]
// 输出：0
// 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
//  
// 提示：
//  * 1 <= prices.length <= 105
//  * 0 <= prices[i] <= 104

// #v1
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

int maxProfit(int* prices, int pricesSize) {
  if (pricesSize <= 1) return 0;
  int ret = 0, i, buy_val = prices[0];
  for (i = 1; i < pricesSize; i++) {
    ret = max(ret, prices[i] - buy_val);
    buy_val = min(buy_val, prices[i]);
  }
  return ret;
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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  printf("%d\n", maxProfit(arr, n));
  free_1d_arr(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
