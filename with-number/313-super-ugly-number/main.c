#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 313. 超级丑数 - 超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。
// 给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。
// 题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。
//  
// 示例 1：
// 输入：n = 12, primes = [2,7,13,19]
// 输出：32
// 解释：给定长度为 4 的质数数组 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
// 示例 2：
// 输入：n = 1, primes = [2,3,5]
// 输出：1
// 解释：1 不含质因数，因此它的所有质因数都在质数数组 primes = [2,3,5] 中。
//  
// 提示：
//  * 1 <= n <= 105
//  * 1 <= primes.length <= 100
//  * 2 <= primes[i] <= 1000
//  * 题目数据 保证 primes[i] 是一个质数
//  * primes 中的所有值都 互不相同 ，且按 递增顺序 排列

// #v1
#define INF 0x7fffffff

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
  int a[n], len = 0, idx[primesSize];
  int minVal, minIdx, t, i, prev;

  // init
  memset(idx, 0, sizeof(idx));
  a[len++] = 1;

  // compute
  while (len < n) {
    minVal = INF;
    prev = a[len - 1];

    for (i = 0; i < primesSize; i++) {
      // avoid overflow
      t = (int64_t)primes[i] * a[idx[i]];

      if (t > 0 && t < minVal) {
        if (prev == t) { // avoid duplication
          // avoid overflow
          t = (int64_t)primes[i] * a[++idx[i]];
          if (t <= 0 || t > minVal) continue;
        }

        minVal = t;
        minIdx = i;
      }
    }

    a[len++] = minVal;
    ++idx[minIdx];
  }

  return a[n-1];
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
  int n, len, *a;
  scanf("%d", &n);
  scanf("%d", &len);
  a = read_1d_arr(len);
  printf("%d\n", nthSuperUglyNumber(n, a, len));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
