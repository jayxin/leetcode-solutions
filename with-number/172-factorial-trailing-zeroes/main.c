#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 172. 阶乘后 的零 - 给定一个整数 n ，返回 n! 结果中尾随零的数量。
// 提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
//  
// 示例 1：
// 输入：n = 3
// 输出：0
// 解释：3! = 6 ，不含尾随 0
// 示例 2：
// 输入：n = 5
// 输出：1
// 解释：5! = 120 ，有一个尾随 0
// 示例 3：
// 输入：n = 0
// 输出：0
//  
// 提示：
//  * 0 &lt;= n &lt;= 104
//  
// 进阶：你可以设计并实现对数时间复杂度的算法来解决此问题吗？

//// #v1
//// n! = a * 10^b, a 不能被 10 整除, 即为求 b = ?
//// n! = 2^x * 3^y * 5^z, 2 * 5 = 10
//// b = min(x, z), 因为 1 - n 中可以被2整除的数出现的次数比 5 多
//// 所以 b = z
//int trailingZeroes(int n) {
  //int i, times = 1, ret = 0, t;
//
  //for (i = 1; i <= n; i++) {
    //t = i;
//
    //while (t % 5 == 0) {
      //ret++;
      //t /= 5;
    //}
  //}
//
  //return ret;
//}
//// #v1

//// #v2
//// n! = a * 10^b, a 不能被 10 整除, 即为求 b = ?
//// n! = 2^x * 3^y * 5^z, 2 * 5 = 10
//// b = min(x, z), 因为 1 - n 中可以被2整除的数出现的次数比 5 多
//// 所以 b = z
//int trailingZeroes(int n) {
  //int i, ret = 0, t;
//
  //for (i = 5; i <= n; i += 5) {
    //t = i;
//
    //while (t % 5 == 0) {
      //ret++;
      //t /= 5;
    //}
  //}
//
  //return ret;
//}
//// #v2

// #v3
// n! = a * 10^b, a 不能被 10 整除, 即为求 b = ?
// n! = 2^x * 3^y * 5^z, 2 * 5 = 10
// b = min(x, z), 因为 1 - n 中可以被2整除的数出现的次数比 5 多
// 所以 b = z
// n/5 + n/25 + n/125 + ...
int trailingZeroes(int n) {
  int ret = 0, t = n;
  long d = 5;

  while (t / d) {
    ret += t / d;
    d *= 5;
  }

  return ret;
}
// #v3

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", trailingZeroes(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
