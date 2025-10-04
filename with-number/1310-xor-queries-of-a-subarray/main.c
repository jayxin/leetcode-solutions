#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1310.  子数组异或查询 - 有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。
// 对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。
// 并返回一个包含给定查询 queries 所有结果的数组。
//  
// 示例 1：
// 输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
// 输出：[2,7,14,8]
// 解释：
// 数组中元素的二进制表示形式是：
// 1 = 0001
// 3 = 0011
// 4 = 0100
// 8 = 1000
// 查询的 XOR 值为：
// [0,1] = 1 xor 3 = 2
// [1,2] = 3 xor 4 = 7
// [0,3] = 1 xor 3 xor 4 xor 8 = 14
// [3,3] = 8
// 示例 2：
// 输入：arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
// 输出：[8,0,4,4]
//  
// 提示：
//  * 1 <= arr.length <= 3 * 10^4
//  * 1 <= arr[i] <= 10^9
//  * 1 <= queries.length <= 3 * 10^4
//  * queries[i].length == 2
//  * 0 <= queries[i][0] <= queries[i][1] < arr.length

// #v1
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  int xorVals[arrSize], i, *ret, l, r;

  *returnSize = queriesSize;
  ret = (int *)malloc(sizeof(int) * queriesSize);

  xorVals[0] = arr[0];
  for (i = 1; i < arrSize; i++) {
    xorVals[i] = xorVals[i - 1] ^ arr[i];
  }

  for (i = 0; i < queriesSize; i++) {
    l = queries[i][0], r = queries[i][1];
    if (!l) ret[i] = xorVals[r];
    else ret[i] = xorVals[r] ^ xorVals[l-1];
  }

  return ret;
}
// #v1

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

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
  int n, *a, *ret, s, **q, qsize, qc = 2;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &qsize);
  q = read_2d_arr(qsize, 2);
  ret = xorQueries(a, n, q, qsize, &qc, &s);
  print_1d_arr(ret, s);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
