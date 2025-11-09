#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2571. 将整数减少到零需要的最少操作数 - 给你一个正整数 n ，你可以执行下述操作 任意 次：
//  * n 加上或减去 2 的某个 幂
// 返回使 n 等于 0 需要执行的 最少 操作数。
// 如果 x == 2i 且其中 i >= 0 ，则数字 x 是 2 的幂。
//  
// 示例 1：
// 输入：n = 39
// 输出：3
// 解释：我们可以执行下述操作：
// - n 加上 20 = 1 ，得到 n = 40 。
// - n 减去 23 = 8 ，得到 n = 32 。
// - n 减去 25 = 32 ，得到 n = 0 。
// 可以证明使 n 等于 0 需要执行的最少操作数是 3 。
// 示例 2：
// 输入：n = 54
// 输出：3
// 解释：我们可以执行下述操作：
// - n 加上 21 = 2 ，得到 n = 56 。
// - n 加上 23 = 8 ，得到 n = 64 。
// - n 减去 26 = 64 ，得到 n = 0 。
// 使 n 等于 0 需要执行的最少操作数是 3 。
//  
// 提示：
//  * 1 <= n <= 105
// Can we set/unset the bits in binary representation?
// If there are multiple adjacent ones, how can we optimally add and subtract in
// 2 operations such that all ones get unset?
// Bonus: Try to solve the problem with higher constraints: n ≤ 10^18.

// #v1
// bit operation, recursion, 分类讨论

// 7862 1111010110110
// 1. 7864 1111010111000
// 2. 7872 1111011000000
// 3. 7936 1111100000000
// 4. 8192 10000000000000
// 5. 0
int min(int a, int b) { return a <= b ? a : b; }

int minOperations(int n) {
  // edge case, n == 2^x
  if ((n & (n-1)) == 0) return 1;

  int x = n, k = -1, t;
  while (x) {
    ++k;
    if (x & 1) break;
    x >>= 1;
  }
  t = 1<<k;

  // k 是 n 的二进制表示中最低位 1 所在的位置 (从 0 开始)
  // (n >> (k+1)) & 1 的值是 n 的二进制表示中第 k+1 位的值
  // n == .......1100...00
  // 这种表示最优的方法是加上 1<<k 消除连续的 1
  if ((n >> (k+1)) & 1) return 1 + minOperations(n+t);

  // n == .......0100...00
  // 加上 1<<k 或减去 1<<k, 取二者的最小值
  // 即消除第 k 位的 1 或者消除从第 k 位开始连续的 1
  return 1 + min(minOperations(n+t), minOperations(n-t));
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", minOperations(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
