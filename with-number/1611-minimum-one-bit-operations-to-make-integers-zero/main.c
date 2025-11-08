#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1611. 使整数变为 0 的最少操作次数 - 给你一个整数 n，你需要重复执行多次下述 操作将其转换为 0 ：
//  * 翻转 n 的二进制表示中最右侧位（第 0 位）。
//  * 如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的 第 i 位。
// 返回将 n 转换为 0 的最小操作次数。
//  
// 示例 1：
// 输入：n = 3
// 输出：2
// 解释：3 的二进制表示为 "11"
// "11" -> "01" ，执行的是第 2 种操作，因为第 0 位为 1 。
// "01" -> "00" ，执行的是第 1 种操作。
// 示例 2：
// 输入：n = 6
// 输出：4
// 解释：6 的二进制表示为 "110".
// "110" -> "010" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
// "010" -> "011" ，执行的是第 1 种操作。
// "011" -> "001" ，执行的是第 2 种操作，因为第 0 位为 1 。
// "001" -> "000" ，执行的是第 1 种操作。
//  
// 提示：
//  * 0 <= n <= 109

// 44 (101100)
// 010000
// 110000
// 110001
// 110011
// 110010
// 110110
// 110111
// 110101
// 110100
// 111100
// 111101
// 111111
// 111110
// 111010
// 111011
// 111001
// 111000
// 101000
// 101001
// 101011
// 101010 2
// 101110 1
// 101111 2
// 101101 1
// 101100 (44)

// n minOps
// 0 0
// 1 1
// 2 3
// 3 2
//
// 4 7
// 5 6
// 6 4
// 7 5
//
// 8 15 (n=8 是 [8,15] 中需要次数最多的)
// 9 14
// 10 12
// 11 13
// 12 8
// 13 9
// 14 11
// 15 10
//
// 16 31 (n=16 是 [16,31] 中需要次数最多的)
// 17 30
// 18 28
// 19 29
// 20 24
// 21 25
// 22 27
// 23 26
// 24 16
// 25 17
// 26 19
// 27 18
// 28 23
// 29 22
// 30 20
// 31 21

//// #v1
//// 超时
//int minimumOneBitOperations(int n) {
  //// n == 0
  //if (!n) return 0;
  //// n == 2 的幂
  //if ((n & (n-1)) == 0) return (n<<1)-1;
//
  //int t = n, bits = 0;
//
  //// count bits
  //while (t) {
    //t >>= 1;
    //++bits;
  //}
//
  //// 从 2 的幂开始计算
  //t = 1<<bits;
  //int ret = (t<<1)-1;
  //char op = 1;
//
  //while (t != n) {
    //// operation 1
    //if (op) t ^= 1;
    //// operation 2
    //else t ^= (t & (-t)) << 1;
//
    //op = !op;
    //--ret;
  //}
//
  //return ret;
//}
//// #v1

// #v2
// recursion, bit operation
int minimumOneBitOperations(int n) {
  // n == 0
  if (!n) return 0;

  // n == 2^k
  //if ((n & (n-1)) == 0) return (n<<1)-1;

  // most significant bit (from right to left, zero-based index)
  int t = n, msb = -1;

  // find most significant bit of `n`
  while (t) {
    t >>= 1;
    ++msb;
  }

  // remove the most significant bit
  return (1<<(msb+1))-1 - minimumOneBitOperations(n - (1<<msb));
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", minimumOneBitOperations(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
