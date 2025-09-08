#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1317. 将整数转换为两个无零整数的和 - 「无零整数」是十进制表示中 不含任何 0 的正整数。
// 给你一个整数 n，请你返回一个 由两个整数组成的列表 [a, b]，满足：
//  * a 和 b 都是无零整数
//  * a + b = n
// 题目数据保证至少有一个有效的解决方案。
// 如果存在多个有效解决方案，你可以返回其中任意一个。
//  
// 示例 1：
// 输入：n = 2
// 输出：[1,1]
// 解释：a = 1, b = 1。a + b = n 并且 a 和 b 的十进制表示形式都不包含任何 0。
// 示例 2：
// 输入：n = 11
// 输出：[2,9]
// 示例 3：
// 输入：n = 10000
// 输出：[1,9999]
// 示例 4：
// 输入：n = 69
// 输出：[1,68]
// 示例 5：
// 输入：n = 1010
// 输出：[11,999]
//  
// 提示：
//  * 2 <= n <= 10^4

// #v1
bool check(int n) {
  while (n) {
    if (n % 10 == 0) return false;
    n /= 10;
  }
  return true;
}
int* getNoZeroIntegers(int n, int* returnSize) {
  *returnSize = 2;
  int *ret = (int *)malloc(sizeof(int) * 2);
  for (int i = 1; i <= 1001; i++) {
    if (check(i) && check(n - i)) {
      ret[0] = i;
      ret[1] = n - i;
      break;
    }
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
  int n, *a, s;
  scanf("%d", &n);
  a = getNoZeroIntegers(n, &s);
  print_1d_arr(a, s);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
