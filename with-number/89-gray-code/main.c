#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 89. 格雷编码 - n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
//  * 每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
//  * 第一个整数是 0
//  * 一个整数在序列中出现 不超过一次
//  * 每对 相邻 整数的二进制表示 恰好一位不同 ，且
//  * 第一个 和 最后一个 整数的二进制表示 恰好一位不同
// 给你一个整数 n ，返回任一有效的 n 位格雷码序列 。
//  
// 示例 1：
// 输入：n = 2
// 输出：[0,1,3,2]
// 解释：
// [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
// - 00 和 01 有一位不同
// - 01 和 11 有一位不同
// - 11 和 10 有一位不同
// - 10 和 00 有一位不同
// [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
// - 00 和 10 有一位不同
// - 10 和 11 有一位不同
// - 11 和 01 有一位不同
// - 01 和 00 有一位不同
// 示例 2：
// 输入：n = 1
// 输出：[0,1]
//  
// 提示：
//  * 1 <= n <= 16

//// #v1
//int mypow(int x, int n) {
  //int r = 1;
  //long xx = x;
  //while (n) {
    //if (n & 1) r *= xx;
    //xx *= xx;
    //n >>= 1;
  //}
  //return r;
//}
//
//void toBin(int n, int bit) {
  //int a[10], l = 0;
  //while (n) {
    //a[l++] = n % 2;
    //n /= 2;
  //}
  //for (int i = 0; i < bit - l; i++) {
    //putchar('0');
  //}
  //for (int i = l-1; i >= 0; i--) {
    //printf("%d", a[i]);
  //}
  //putchar('\n');
//}
//
//int *a, aLen, bLen, nn, size;
//char *b;
//
//void _grayCode(int val) {
  //// goal achieved
  //if (aLen == size) return ;
//
  //b[val] = 1; // mark value as selected
  //a[aLen++] = val; // push
//
  //int v, i;
//
  //// enumerate
  //for (i = 0; i < nn; i++) {
    //if ((val >> i) & 1) { // the bit is 1, set 0
      //v = val & (~(1 << i));
    //} else { // the bit is 0, set 1
      //v = val | (1 << i);
    //}
//
    //// if selected, next loop
    //if (b[v]) continue;
//
    //// select and go on
    //_grayCode(v);
  //}
//}
//
//int* grayCode(int n, int* returnSize) {
  //// allocate
  //nn = n;
  //*returnSize = mypow(2, n);
  //size = *returnSize;
  //a = (int *)malloc(sizeof(int) * (*returnSize)); aLen = 0;
  //b = (char *)malloc(sizeof(char) * (*returnSize)); bLen = 0;
//
  //// init
  //memset(b, 0, sizeof(char) * size);
//
  //// compute
  //_grayCode(0);
//
  //return a;
//}
//// #v1

//// #v2
//// backtrack
//int *a, aLen, bLen, nn, size;
//char *b;
//
//void _grayCode(int val) {
  //// goal achieved
  //if (aLen == size) return ;
//
  //b[val] = 1; // mark value as selected
  //a[aLen++] = val; // push
//
  //int v, i;
//
  //// enumerate
  //for (i = 0; i < nn; i++) {
    //if ((val >> i) & 1) { // the bit is 1, set 0
      //v = val & (~(1 << i));
    //} else { // the bit is 0, set 1
      //v = val | (1 << i);
    //}
//
    //// if selected, next loop
    //if (b[v]) continue;
//
    //// select and go on
    //_grayCode(v);
  //}
//}
//
//int* grayCode(int n, int* returnSize) {
  //// allocate
  //nn = n;
  //*returnSize = 1 << n;
  //size = *returnSize;
  //a = (int *)malloc(sizeof(int) * (*returnSize)); aLen = 0;
  //b = (char *)malloc(sizeof(char) * (*returnSize)); bLen = 0;
//
  //// init
  //memset(b, 0, sizeof(char) * size);
//
  //// compute
  //_grayCode(0);
//
  //return a;
//}
//// #v2

// #v3
// formula
int* grayCode(int n, int* returnSize) {
  // allocate
  *returnSize = 1 << n;
  int *a = (int *)malloc(sizeof(int) * (*returnSize)), i;

  // compute
  for (i = 0; i < *returnSize; i++) {
    a[i] = i ^ (i >> 1);
  }

  return a;
}
// #v3

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *ret, s;
  scanf("%d", &n);
  ret = grayCode(n, &s);
  print_1d_arr(ret, s);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
