#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2578. 最小 和分割 - 给你一个正整数 num ，请你将它分割成两个非负整数 num1 和 num2 ，满足：
//  * num1 和 num2 直接连起来，得到 num 各数位的一个排列。
//    * 换句话说，num1 和 num2 中所有数字出现的次数之和等于 num 中所有数字出现的次数。
//  * num1 和 num2 可以包含前导 0 。
// 请你返回 num1 和 num2 可以得到的和的 最小 值。
// 注意：
//  * num 保证没有前导 0 。
//  * num1 和 num2 中数位顺序可以与 num 中数位顺序不同。
//  
// 示例 1：
// 输入：num = 4325
// 输出：59
// 解释：我们可以将 4325 分割成 num1 = 24 和 num2 = 35 ，和为 59 ，59 是最小和。
// 示例 2：
// 输入：num = 687
// 输出：75
// 解释：我们可以将 687 分割成 num1 = 68 和 num2 = 7 ，和为最优值 75 。
//  
// 提示：
//  * 10 &lt;= num &lt;= 109

// #v1
int intCmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int splitNum(int num) {
  int *arr = (int *)malloc(sizeof(int) * 11);
  int i = 0, j = 1, len = 0, x = num, num1 = 0, num2 = 0;
  while (x) {
    arr[len++] = x % 10;
    x /= 10;
  }
  qsort(arr, len, sizeof(int), intCmp);
  while (i < len || j < len) {
    if (i < len) {
      num1 = num1 * 10 + arr[i];
    }
    if (j < len) {
      num2 = num2 * 10 + arr[j];
    }
    i += 2;
    j += 2;
  }
  free(arr);
  return num1 + num2;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", splitNum(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
