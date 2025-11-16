#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2177. 找到和为给定整数的三个连续整数 - 给你一个整数 num ，请你返回三个连续的整数，它们的 和 为 num 。如果 num 无法被表示成三个连续整数的和，请你返回一个 空 数组。
//  
// 示例 1：
// 输入：num = 33
// 输出：[10,11,12]
// 解释：33 可以表示为 10 + 11 + 12 = 33 。
// 10, 11, 12 是 3 个连续整数，所以返回 [10, 11, 12] 。
// 示例 2：
// 输入：num = 4
// 输出：[]
// 解释：没有办法将 4 表示成 3 个连续整数的和。
//  
// 提示：
//  * 0 <= num <= 1015

// #v1
long long* sumOfThree(long long num, int* returnSize) {
  if (num % 3) {
    *returnSize = 0;
    return NULL;
  }

  long long *ret = (long long *)malloc(sizeof(long long) * 3);

  ret[1] = num / 3;
  ret[0] = ret[1] - 1;
  ret[2] = ret[1] + 1;

  *returnSize = 3;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  long long n, *a;
  int s;
  scanf("%lld", &n);
  a = sumOfThree(n, &s);
  if (!s) {
    printf("\n");
    return EXIT_SUCCESS;
  }
  printf("%lld %lld %lld\n", a[0], a[1], a[2]);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
