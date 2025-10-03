#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2657. 找到两个数组的前缀公共数组 - 给你两个下标从 0 开始长度为 n 的整数排列 A 和 B 。
// A 和 B 的 前缀公共数组 定义为数组 C ，其中 C[i] 是数组 A 和 B 到下标为 i 之前公共元素的数目。
// 请你返回 A 和 B 的 前缀公共数组 。
// 如果一个长度为 n 的数组包含 1 到 n 的元素恰好一次，我们称这个数组是一个长度为 n  的 排列 。
//  
// 示例 1：
// 输入：A = [1,3,2,4], B = [3,1,2,4]
// 输出：[0,2,3,4]
// 解释：i = 0：没有公共元素，所以 C[0] = 0 。
// i = 1：1 和 3 是两个数组的前缀公共元素，所以 C[1] = 2 。
// i = 2：1，2 和 3 是两个数组的前缀公共元素，所以 C[2] = 3 。
// i = 3：1，2，3 和 4 是两个数组的前缀公共元素，所以 C[3] = 4 。
// 示例 2：
// 输入：A = [2,3,1], B = [3,1,2]
// 输出：[0,1,3]
// 解释：i = 0：没有公共元素，所以 C[0] = 0 。
// i = 1：只有 3 是公共元素，所以 C[1] = 1 。
// i = 2：1，2 和 3 是两个数组的前缀公共元素，所以 C[2] = 3 。
//  
// 提示：
//  * 1 &lt;= A.length == B.length == n &lt;= 50
//  * 1 &lt;= A[i], B[i] &lt;= n
//  * 题目保证 A 和 B 两个数组都是 n 个元素的排列。

// #v1
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
  *returnSize = ASize;
  char ta[51] = {0}, tb[51] = {0};
  int *ret = (int *)malloc(sizeof(int) * ASize), i;

  // init
  if (A[0] == B[0]) {
    ret[0] = 1;
  } else {
    ret[0] = 0;
  }
  ta[A[0]] = tb[B[0]] = 1;

  for (i = 1; i < ASize; i++) {
    ret[i] = ret[i-1];

    if (A[i] == B[i]) ++ret[i];
    if (tb[A[i]]) ++ret[i];
    if (ta[B[i]]) ++ret[i];

    ta[A[i]] = tb[B[i]] = 1;
  }

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

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
  int n, *a, *b, m, *ret, s;
  scanf("%d", &m);
  a = read_1d_arr(m);
  scanf("%d", &n);
  b = read_1d_arr(n);
  ret = findThePrefixCommonArray(a, m, b, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
