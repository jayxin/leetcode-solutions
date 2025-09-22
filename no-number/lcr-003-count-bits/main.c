#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// LCR 003. 比特位计数 - 给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1  的个数，并输出一个数组。
//  
// 示例 1:
// 输入: n = 2
// 输出: [0,1,1]
// 解释:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 示例 2:
// 输入: n = 5
// 输出: [0,1,1,2,1,2]
// 解释:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
//  
// 说明 :
//  * 0 <= n <= 105
//  
// 进阶:
//  * 给出时间复杂度为 O(n*sizeof(integer)) 的解答非常容易。但你可以在线性时间 O(n) 内用一趟扫描做到吗？
//  * 要求算法的空间复杂度为 O(n) 。
//  * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount ）来执行此操作。
//  
// 注意：本题与主站 338 题相同：https://leetcode-cn.com/problems/counting-bits/ [https://leetcode-cn.com/problems/counting-bits/]

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
