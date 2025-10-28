#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1217. 玩筹码 - 有 n 个筹码。第 i 个筹码的位置是 position[i] 。
// 我们需要把所有筹码移到同一个位置。在一步中，我们可以将第 i 个筹码的位置从 position[i] 改变为:
//  * position[i] + 2 或 position[i] - 2 ，此时 cost = 0
//  * position[i] + 1 或 position[i] - 1 ，此时 cost = 1
// 返回将所有筹码移动到同一位置上所需要的 最小代价 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/08/15/chips_e1.jpg]
// 输入：position = [1,2,3]
// 输出：1
// 解释：第一步:将位置3的筹码移动到位置1，成本为0。
// 第二步:将位置2的筹码移动到位置1，成本= 1。
// 总成本是1。
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/08/15/chip_e2.jpg]
// 输入：position = [2,2,2,3,3]
// 输出：2
// 解释：我们可以把位置3的两个筹码移到位置2。每一步的成本为1。总成本= 2。
// 示例 3:
// 输入：position = [1,1000000000]
// 输出：1
//  
// 提示：
//  * 1 <= position.length <= 100
//  * 1 <= position[i] <= 10^9
// The first move keeps the parity of the element as it is.
// The second move changes the parity of the element.
// Since the first move is free, if all the numbers have the same parity, the
// answer would be zero.
// Find the minimum cost to make all the numbers have the same parity.

// #v1
#define min(a, b) ((a) <= (b) ? (a) : (b))
int minCostToMoveChips(int* position, int positionSize) {
  int oddCnt = 0, evenCnt = 0;

  for (int i = 0; i < positionSize; i++) {
    if (position[i] & 1) ++oddCnt;
    else ++evenCnt;
  }

  return min(oddCnt, evenCnt);
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", minCostToMoveChips(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
