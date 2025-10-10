#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3147. 从魔法师身上吸取的最大能量 - 在神秘的地牢中，n 个魔法师站成一排。每个 魔法师都拥有一个属性，这个属性可以给你提供能量。有些魔法师可能会给你负能量，即从 你身上吸取能量。
// 你被施加了一种诅咒，当你从魔法师 i 处吸收能量后，你将被立即传送到魔法师 (i + k)  处。这一过程将重复进行，直到你到达一个不存在 (i + k) 的魔法师为止。
// 换句话说，你将选择一个起点，然后以 k 为间隔跳跃，直到到达魔法师序列的末端，在过程中吸收所有的能量。
// 给定一个数组 energy 和一个整数k，返回你能获得的 最大 能量。
//  
// 示例 1：
// 输入： energy = [5,2,-10,-5,1], k = 3
// 输出： 3
// 解释：可以从魔法师 1 开始，吸收能量 2 + 1 = 3。
// 示例 2：
// 输入： energy = [-2,-3,-1], k = 2
// 输出： -1
// 解释：可以从魔法师 2 开始，吸收能量 -1。
//  
// 提示：
//  * 1 <= energy.length <= 105
//  * -1000 <= energy[i] <= 1000
//  * 1 <= k <= energy.length - 1

//// #v1
//// 动态规划
//int maximumEnergy(int* energy, int energySize, int k) {
  //// dp[i] 表示从 energy[i] 开始吸收的能量
  //// dp[i] = dp[i + k] + energy[i]
  //int dp[energySize], end = energySize - 1, ret;
//
  //ret = dp[end] = energy[end];
//
  //for (int i = end - 1; i >= 0; i--) {
    //dp[i] = energy[i];
//
    //if (i + k <= end) dp[i] += dp[i + k];
    //if (dp[i] > ret) ret = dp[i];
  //}
//
  //return ret;
//}
//// #v1

// #v2
// 动态规划
int maximumEnergy(int* energy, int energySize, int k) {
  int end = energySize - 1, ret, i, t;

  ret = energy[end];
  t = end - k;

  for (i = end - 1; i > t; i--) {
    if (energy[i] > ret) ret = energy[i];
  }

  for (i = t; i >= 0; i--) {
    energy[i] += energy[i + k];
    if (energy[i] > ret) ret = energy[i];
  }

  return ret;
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
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", maximumEnergy(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
