#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 338. 比特位 计数 - 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
//  
// 示例 1：
// 输入：n = 2
// 输出：[0,1,1]
// 解释：
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 示例 2：
// 输入：n = 5
// 输出：[0,1,1,2,1,2]
// 解释：
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
//  
// 提示：
//  * 0 <= n <= 10^5
//  
// 进阶：
//  * 很容易就能实现时间复杂度为 O(n log n) 的解决方案，你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？
//  * 你能不使用任何内置函数解决此问题吗？（如，C++ 中的 __builtin_popcount ）

// #v1
int* countBits(int n, int* returnSize) {
  int x, *ret, cnt;

  // init
  ret = (int *)malloc(sizeof(int) * (n + 1));
  *returnSize = n + 1;

  for (int i = 0; i <= n; i++) {
    x = i;
    cnt = 0;

    while (x > 0) {
      x -= x & (-x);
      ++cnt;
    }

    ret[i] = cnt;
  }

  return ret;
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
  int n, *ret, s;
  scanf("%d", &n);
  ret = countBits(n, &s);
  print_1d_arr(ret, s);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
