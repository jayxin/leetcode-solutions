#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2160. 拆分数位后四位数字的最小和 - 给你一个四位 正 整数 num 。请你使用 num 中的 数位 ，将 num 拆成两个新的整数 new1 和 new2 。new1 和 new2 中可以有 前导 0 ，且 num 中 所有 数位都必须使用。
//  * 比方说，给你 num = 2932 ，你拥有的数位包括：两个 2 ，一个 9 和一个 3 。一些可能的 [new1, new2] 数对为 [22, 93]，[23, 92]，[223, 9] 和 [2, 329] 。
// 请你返回可以得到的 new1 和 new2 的 最小 和。
//  
// 示例 1：
// 输入：num = 2932
// 输出：52
// 解释：可行的 [new1, new2] 数对为 [29, 23] ，[223, 9] 等等。
// 最小和为数对 [29, 23] 的和：29 + 23 = 52 。
// 示例 2：
// 输入：num = 4009
// 输出：13
// 解释：可行的 [new1, new2] 数对为 [0, 49] ，[490, 0] 等等。
// 最小和为数对 [4, 9] 的和：4 + 9 = 13 。
//  
// 提示：
//  * 1000 <= num <= 9999
// 1. Notice that the most optimal way to obtain the minimum possible sum using
// 4 digits is by summing up two 2-digit numbers.
// 2. We can use the two smallest digits out of the four as the digits found in
// the tens place respectively.
// 3. Similarly, we use the final 2 larger digits as the digits found in the
// ones place.

// #v1
// sort, greedy method
int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int minimumSum(int num) {
  int arr[4], len = 0, ret = 0;

  while (num) {
    arr[len++] = num % 10;
    num /= 10;
  }

  qsort(arr, 4, sizeof(int), cmp);

  ret += (arr[0] + arr[1]) * 10 + arr[2] + arr[3];

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", minimumSum(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
