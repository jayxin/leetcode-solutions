#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2520. 统计能整除数字的位数 - 给你一个整数 num ，返回 num 中能整除 num 的数位的数目。
// 如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。
//  
// 示例 1：
// 输入：num = 7
// 输出：1
// 解释：7 被自己整除，因此答案是 1 。
// 示例 2：
// 输入：num = 121
// 输出：2
// 解释：121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
// 示例 3：
// 输入：num = 1248
// 输出：4
// 解释：1248 可以被它每一位上的数字整除，因此答案是 4 。
//  
// 提示：
//  * 1 <= num <= 109
//  * num 的数位中不含 0

// #v1
int countDigits(int num) {
  // edge case
  if (num <= 9) return 1;

  int c = 0, x = num;

  while (x) {
    if (num % (x % 10) == 0) ++c;
    x /= 10;
  }

  return c;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", countDigits(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
