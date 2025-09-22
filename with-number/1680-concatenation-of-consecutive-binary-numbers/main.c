#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1680. 连接连续二进制数字 - 给你一个整数 n ，请你将 1 到 n 的二进制表示连接起来，并返回连接结果对应的 十进制 数字对 10^9 + 7 取余的结果。
//  
// 示例 1：
// 输入：n = 1
// 输出：1
// 解释：二进制的 "1" 对应着十进制的 1 。
// 示例 2：
// 输入：n = 3
// 输出：27
// 解释：二进制下，1，2 和 3 分别对应 "1" ，"10" 和 "11" 。
// 将它们依次连接，我们得到 "11011" ，对应着十进制的 27 。
// 示例 3：
// 输入：n = 12
// 输出：505379714
// 解释：连接结果为 "1101110010111011110001001101010111100" 。
// 对应的十进制数字为 118505380540 。
// 对 109 + 7 取余后，结果为 505379714 。
//  
// 提示：
//  * 1 &lt;= n &lt;= 105
// Express the nth number value in a recursion formula and think about how we
// can do a fast evaluation.

//// #v1
//// 递归, 回溯, 位运算
//int mod, *t;
//
//int countBits(int n) {
  //int cnt = 0;
  //while (n) {
    //++cnt;
    //n >>= 1;
  //}
  //return cnt;
//}
//
////int64_t myPow(int x, int n) {
////  int64_t ret = 1, xx = x;
////  while (n) {
////    if (n & 1) ret = ret * xx;
////    xx = xx * xx;
////    n >>= 1;
////  }
////  return ret;
////}
//
//int f(int n) {
  //if (n == 1) return 1;
//
  //if (t[n] >= 0) return t[n];
//
  //int n1 = f(n-1), bits = countBits(n) % 31, ret;
  //ret = (int64_t)n1 * ((1 << bits) % mod) % mod + n;
  //ret %= mod;
//
  //// record
  //t[n] = ret;
//
  //return ret;
//}
//
//// (x + y) % z == (x % z + y % z) % z
//// (x * y) % z == ((x % z) * (y % z)) % z
//int concatenatedBinary(int n) {
  //int tab[n+1];
//
  //// init
  //mod = 1000000007;
//
  //memset(tab, 0xff, sizeof(int) * (n + 1));
  //t = tab;
//
  //return f(n);
//}
//// #v1

//// #v2
//// 递推
//int countBits(int n) {
  //int cnt = 0;
  //while (n) {
    //++cnt;
    //n >>= 1;
  //}
  //return cnt;
//}
//
//// (x + y) % z == (x % z + y % z) % z
//// (x * y) % z == ((x % z) * (y % z)) % z
//int concatenatedBinary(int n) {
  //int tab[n+1], mod = 1000000007, bits;
//
  //// init
  //tab[1] = 1;
//
  //for (int i = 2; i <= n; i++) {
    //bits = countBits(i) % 31;
    //tab[i] = (int64_t)tab[i-1] * ((1 << bits) % mod) % mod + i;
  //}
//
  //return tab[n];
//}
//// #v2

// #v3
// 递推, 空间优化
int countBits(int n) {
  int cnt = 0;
  while (n) {
    ++cnt;
    n >>= 1;
  }
  return cnt;
}

// (x + y) % z == (x % z + y % z) % z
// (x * y) % z == ((x % z) * (y % z)) % z
int concatenatedBinary(int n) {
  int mod = 1000000007, bits;
  int64_t prev, cur;

  // init
  prev = cur = 1LL;

  for (int i = 2; i <= n; i++) {
    bits = countBits(i);
    //cur = (int64_t)prev * ((1 << bits) % mod) % mod + i;
    cur = (prev << bits) % mod + i;
    prev = cur;
  }

  return prev;
}
// #v3

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", concatenatedBinary(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
