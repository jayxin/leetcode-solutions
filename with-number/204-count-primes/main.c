#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// 204. 计数质数 - 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
//  
// 示例 1：
// 输入：n = 10
// 输出：4
// 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 示例 2：
// 输入：n = 0
// 输出：0
// 示例 3：
// 输入：n = 1
// 输出：0
//  
// 提示：
//  * 0 <= n <= 5 * 106

//// #v1
//// 超时
//// 试除法
//bool isPrime(int x) {
  //if (x <= 1) return false;
  //if (!(x & 1) && x != 2) return false;
//
  //int b = sqrt(x), i;
  //for (i = 2; i <= b; i++) {
    //if (x % i == 0) return false;
  //}
//
  //return true;
//}
//
//int countPrimes(int n) {
  //int cnt = 0;
//
  //for (int i = 2; i < n; i++) {
    //if (isPrime(i)) ++cnt;
  //}
//
  //return cnt;
//}
//// #v1

//// #v2
//// 超时
//// 试除法
//bool isPrime(int x) {
  //if (x <= 3)
    //return x > 1;
//
  //if (x % 6 != 1 && x % 6 != 5)
    //return false;
//
  //int i;
  //for (i = 5; i * i <= x; i += 6)
    //if (!(x % i) || !(x % (i + 2)))
      //return false;
  //return true;
//}
//
//int countPrimes(int n){
  //int cnt = 0;
//
  //for (int i = 2; i < n; i++) {
    //if (isPrime(i)) ++cnt;
  //}
//
  //return cnt;
//}
//// #v2

// #v3
// Eratosthenes 筛法
int countPrimes(int n){
  int cnt = 0;
  char v[n + 1];

  // init
  memset(v, 0, sizeof(v));

  // compute
  for (int i = 2; i < n; i++) {
    if (v[i]) continue;

    // i is prime
    ++cnt;

    for (int j = i; j <= n / i; j++) v[i * j] = 1;
  }

  return cnt;
}
// #v3

//// #v4
//// 线性筛法
//int countPrimes(int n){
  //if (n <= 1) return 0;
//
  //int cnt = 0, primes[n>>1], len = 0, t, i, j;
  //int v[n + 1]; // v[i] 是 i 的最小质因子
//
  //// init
  //memset(v, 0, sizeof(v));
//
  //// compute
  //for (i = 2; i < n; i++) {
    //if (!v[i]) { // i is prime
      //v[i] = i;
      //primes[len++] = i;
      //++cnt;
    //}
//
    //t = n / i;
    //for (j = 0; j < len; j++) {
      //// i 有比 prime[j] 更小的质因子或超出 n 的范围
      //if (primes[j] > v[i] || primes[j] > t) break;
//
      //// prime[j] 是合数 i*prime[j] 的最小质因子
      //v[i * primes[j]] = primes[j];
    //}
  //}
//
  //return cnt;
//}
//// #v4

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", countPrimes(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
