#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2595. 奇偶位 数 - 给你一个 正 整数 n 。
// 用 even 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的偶数下标的个数。
// 用 odd 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的奇数下标的个数。
// 请注意，在数字的二进制表示中，位下标的顺序 从右到左。
// 返回整数数组 answer ，其中 answer = [even, odd] 。
//  
// 示例 1：
// 输入：n = 50
// 输出：[1,2]
// 解释：
// 50 的二进制表示是 110010。
// 在下标 1，4，5 对应的值为 1。
// 示例 2：
// 输入：n = 2
// 输出：[0,1]
// 解释：
// 2 的二进制表示是 10。
// 只有下标 1 对应的值为 1。
//  
// 提示：
//  * 1 &lt;= n &lt;= 1000

//// #v1
//int* evenOddBit(int n, int* returnSize) {
  //*returnSize = 2;
  //int *ret = (int *)malloc(sizeof(int) * 2), cnt = 0;
  //ret[0] = ret[1] = 0;
//
  //while (n) {
    //if (n & 1) {
      //if (cnt & 1) ++ret[1];
      //else ++ret[0];
    //}
    //++cnt;
    //n >>= 1;
  //}
//
  //return ret;
//}
//// #v1

// #v2
int* evenOddBit(int n, int* returnSize) {
  *returnSize = 2;
  int *ret = (int *)malloc(sizeof(int) * 2), i = 0;
  ret[0] = ret[1] = 0;

  while (n) {
    ret[i] += n & 1;
    i ^= 1;
    n >>= 1;
  }

  return ret;
}
// #v2

int main(int argc, char *argv[])
{
  int n, *ret, s;
  scanf("%d", &n);
  ret = evenOddBit(n, &s);
  printf("%d %d\n", ret[0], ret[1]);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
