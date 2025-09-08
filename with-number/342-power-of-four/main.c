#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 342. 4的幂 - 给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
// 整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4^x
//  
// 示例 1：
// 输入：n = 16
// 输出：true
// 示例 2：
// 输入：n = 5
// 输出：false
// 示例 3：
// 输入：n = 1
// 输出：true
//  
// 提示：
//  * -2^31 <= n <= 2^31 - 1
//  
// 进阶：你能不使用循环或者递归来完成本题吗？

//// #v1
//bool isPowerOfFour(int n) {
  //if (n <= 0) return false;
  //if (n == 1) return true;
  //if ((n & 1) || (n & (n-1))) return false;
  //for (int i = 2; i <= 30; i+=2) {
    //if (n == (1<<i)) return true;
  //}
  //return false;
//}
//// #v1

//// #v2
//bool isPowerOfFour(int n) {
  //if (n <= 0) return false;
  //if (n == 1) return true;
  //if ((n & 1) || (n & (n-1))) return false;
  //int bits = 0;
  //while (n) {
    //bits++;
    //n >>= 1;
  //}
  //return (bits & 1);
//}
//// #v2

//// #v3
//bool isPowerOfFour(int n) {
  //return (n > 0 && (n & (n-1)) == 0 && n % 3 == 1);
//}
//// #v3

// #v4
bool isPowerOfFour(int n) {
  return (n > 0 && (n & (n-1)) == 0 && (n & 0xaaaaaaaa) == 0);
}
// #v4

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (isPowerOfFour(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
