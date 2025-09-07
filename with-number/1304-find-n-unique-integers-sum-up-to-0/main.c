#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1304. 和为零的 N 个不同整数 - 给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。
//  
// 示例 1：
// 输入：n = 5
// 输出：[-7,-1,1,3,4]
// 解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
// 示例 2：
// 输入：n = 3
// 输出：[-1,0,1]
// 示例 3：
// 输入：n = 1
// 输出：[0]
//  
// 提示：
//  * 1 &lt;= n &lt;= 1000

// #v1
int* sumZero(int n, int* returnSize) {
  int *a = (int *)malloc(sizeof(int) * n), len = 0;
  *returnSize = n;
  int positive = 1, negative = -1;

  while (len < n - 1) {
    a[len++] = positive;
    positive++;
    a[len++] = negative;
    negative--;
  }

  if (n & 1) {
    a[len++] = 0;
  }

  return a;
}
// #v1

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
  int n, retSize;
  scanf("%d", &n);
  int *a = sumZero(n, &retSize);
  print_1d_arr(a, n);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
