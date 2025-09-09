#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 476. 数字的 补数 - 对整数的二进制表示取反（0 变 1 ，1 变 0）后，再转换为十进制表示，可以得到 这个整数的补数。
//  * 例如，整数 5 的二进制表示是 &quot;101&quot; ，取反后得到 &quot;010&quot; ，再 转回十进制表示得到补数 2 。
// 给你一个整数 num ，输出它的补数。
//  
// 示例 1：
// 输入：num = 5
// 输出：2
// 解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
// 示例 2：
// 输入：num = 1
// 输出：0
// 解释：1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
//  
// 提示：
//  * 1 &lt;= num &lt; 231
//  
// 注意：本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ [https://leetcode-cn.com/problems/complement-of-base-10-integer/] 相同

//// #v1
//int countBits(int n) {
  //int cnt = 0;
  //while (n) {
    //cnt++;
    //n >>= 1;
  //}
  //return cnt;
//}
//
//int findComplement(int num) {
  //int bits = countBits(num),
      //a = ((1 << (bits - 1)) - 1) | (1 << (bits-1));
  //return (a & (~num));
//}
//// #v1

// #v2
int countBits(int n) {
  int cnt = 0;
  while (n) {
    cnt++;
    n >>= 1;
  }
  return cnt;
}

int findComplement(int num) {
  int bits = countBits(num) - 1,
      a = ((1 << bits) - 1) | (1 << bits);
  return (a & (~num));
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", findComplement(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
