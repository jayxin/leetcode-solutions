#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1155. 掷骰子等于目标和的方法数 - 这里有 n 个一样的骰子，每个骰子上都有 k 个面 ，分别标号为 1 到 k 。
// 给定三个整数 n、k 和 target，请返回投掷骰子的所有可能得到的结果（共有 kn 种方式），使得骰子面朝上的数字总和等于 target。
// 由于答案可能很大，你需要对 109 + 7 取模。
//  
// 示例 1：
// 输入：n = 1, k = 6, target = 3
// 输出：1
// 解释：你掷了一个有 6 个面的骰子。
// 得到总和为 3 的结果的方式只有一种。
// 示例 2：
// 输入：n = 2, k = 6, target = 7
// 输出：6
// 解释：你掷了两个骰子，每个骰子有 6 个面。
// 有 6 种方式得到总和为 7 的结果: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1。
// 示例 3：
// 输入：n = 30, k = 30, target = 500
// 输出：222616187
// 解释：返回的结果必须对 109 + 7 取模。
//  
// 提示：
//  * 1 <= n, k <= 30
//  * 1 <= target <= 1000

// #v1
// 动态规划, 记忆化搜索, 自顶向下

#define MIN(a, b) ((a) >= (b) ? (b) : (a))
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MOD 1000000007

int **t, kk;

int f(int n, int target) {
  if (t[n][target] >= 0) return t[n][target];

  int ret = 0, b = MIN(kk, target), q;

  --n;

  for (int i = 1; i <= b; i++) {
    q = target - i;

    if (t[n][q] >= 0)
      ret = ((int64_t)ret + t[n][q]) % MOD;
    else
      ret = ((int64_t)ret + f(n, q)) % MOD;
  }

  // record
  t[n+1][target] = ret;

  return ret;
}

int numRollsToTarget(int n, int k, int target) {
  int i, q, b = n + 1;

  // allocate
  t = (int **)malloc(sizeof(int *) * b);
  q = MAX(k+1, target+1);
  for (i = 0; i < b; i++) {
    t[i] = (int *)malloc(sizeof(int) * q);
    memset(t[i], 0xff, sizeof(int) * q);
  }

  // init
  for (i = 1; i <= k; i++) t[1][i] = 1;
  for (i = k+1; i <= target; i++) t[1][i] = 0;
  kk = k;

  return f(n, target);
}
// #v1

int main(int argc, char *argv[])
{
  int n, k, t;
  scanf("%d%d%d", &n, &k, &t);
  printf("%d\n", numRollsToTarget(n, k, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
