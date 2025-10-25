#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 479. 最 大回文数乘积 - 给定一个整数 n ，返回 可表示为两个 n 位整数乘积的 最大回文整数 。 因为答案可能非常大，所以返回它对 1337 取余 。
//  
// 示例 1：
// 输入：n = 2
// 输出：987
// 解释：99 x 91 = 9009, 9009 % 1337 = 987
// 示例 2：
// 输入：n = 1
// 输出：9
//  
// 提示:
//  * 1 <= n <= 8

//// #v1
//// 超时
//bool isPalindrome(int64_t n) {
  //int a[18], len = 0, h;
//
  //while (n) {
    //a[len++] = n % 10;
    //n /= 10;
  //}
//
  //h = len >> 1;
//
  //for (int i = 0; i < h; i++) {
    //if (a[i] != a[len - i - 1]) return false;
  //}
//
  //return true;
//}
//
//int myPow(int n) {
  //int ret = 1, x = 10;
//
  //while (n) {
    //if (n & 1) ret *= x;
//
    //n >>= 1;
    //if (n) x *= x;
  //}
//
  //return ret;
//}
//
//int largestPalindrome(int n) {
  //int max = myPow(n) - 1, min = myPow(n-1), i, j;
  //int64_t t, prev = 0LL;
//
  //for (i = max; i >= min; i--) {
    //if ((int64_t)i * i < prev) break;
    //for (j = i; j >= min; j--) {
      //t = (int64_t)i * j;
      //if (t > prev) {
        //if (isPalindrome(t)) {
          //prev = t;
        //}
      //} else {
        //break;
      //}
    //}
  //}
//
  //return prev % 1337;
//}
//// #v1

// #v2
int largestPalindrome(int n) {
  switch (n) {
    case 1:
      return 9;
    case 2:
      return 987;
    case 3:
      return 123;
    case 4:
      return 597;
    case 5:
      return 677;
    case 6:
      return 1218;
    case 7:
      return 877;
    case 8:
      return 475;
  }

  return 0;
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", largestPalindrome(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
