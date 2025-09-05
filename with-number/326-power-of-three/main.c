#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 326. 3 的幂
// 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
// 整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3^x
//
// -2^31 <= n <= 2^31 - 1

//// #v1
//// iteration solution
//bool isPowerOfThree(int n) {
  //if (n == 0) {
    //return false;
  //}
//
  //while (n != 1) {
    //if (n % 3) {
      //return false;
    //}
    //n /= 3;
  //}
//
  //return true;
//}
//// #v1

//// #v2
//// recursive solution
//bool isPowerOfThree(int n) {
  //if (n == 0) {
    //return false;
  //}
//
  //if (n == 1) {
    //return true;
  //}
//
  //if (n % 3 == 0) {
    //return isPowerOfThree(n / 3);
  //}
//
  //return false;
//}
//// #v2

// #v3
//
bool isPowerOfThree(int n) {
  if ((n & 1) == 0 || n < 0) {
    return false;
  }
}
// #v3

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (isPowerOfThree(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
