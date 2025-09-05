#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 746. 使用最小花费爬楼梯 - 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向 上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
// 请你计算并返回达到楼梯顶部的最低花费。
//  
// 示例 1：
// 输入：cost = [10,15,20]
// 输出：15
// 解释：你将从下标为 1 的台阶开始。
// - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
// 总花费为 15 。
// 示例 2：
// 输入：cost = [1,100,1,1,1,100,1,1,100,1]
// 输出：6
// 解释：你将从下标为 0 的台阶开始。
// - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
// - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
// - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
// 总花费为 6 。
//  
// 提示：
//  * 2 &lt;= cost.length &lt;= 1000
//  * 0 &lt;= cost[i] &lt;= 999

// #v1
#define min(a, b) (a > b ? b : a)

int minCostClimbingStairs(int* cost, int costSize) {
  if (costSize == 2) return min(cost[0], cost[1]);
  int pprev = cost[0], prev = cost[1], cur;
  for (int i = 2; i < costSize; i++) {
    cur = min(prev, pprev) + cost[i];
    pprev = prev;
    prev = cur;
  }
  if (costSize > 2) {
    cur = min(prev, pprev);
    prev = cur;
  }
  return prev;
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
  int *a;
  a = read_1d_arr(n);
  printf("%d\n", minCostClimbingStairs(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
