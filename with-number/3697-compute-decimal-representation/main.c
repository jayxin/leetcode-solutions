#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3697.  计算十进制表示 - 给你一个 正整数 n。
// 如果一个正整数可以表示为 1 到 9 的单个数字和 10 的非负整数次幂的乘积，则称这个整 数是一个 10 进制分量。例如，500、30 和 7 是 10 进制分量 ，而 537、102 和 11 则不 是。
// 请将 n 表示为若干 仅由 10 进制分量组成的和，且使用的 10 进制分量个数 最少 。
// 返回一个包含这些 10 进制分量 的数组，并按分量大小 降序 排列。
//  
// 示例 1：
// 输入：n = 537
// 输出：[500,30,7]
// 解释：
// 我们可以将 537 表示为500 + 30 + 7。无法用少于 3 个 10 进制分量表示 537。
// 示例 2：
// 输入：n = 102
// 输出：[100,2]
// 解释：
// 我们可以将 102 表示为100 + 2。102 不是一个 10 进制分量，因此需要 2 个 10 进制分量。
// 示例 3：
// 输入：n = 6
// 输出：[6]
// 解释：
// 6 是一个 10 进制分量。
//  
// 提示：
//  * 1 <= n <= 109

// #v1
int* decimalRepresentation(int n, int* returnSize) {
  int *ret, retLen = 0, r, t, h;
  int64_t weight = 1LL;

  ret = (int *)malloc(sizeof(int) * 12);

  while (n) {
    r = n % 10;
    if (r) ret[retLen++] = r * weight;

    weight *= 10LL;
    n /= 10;
  }

  // reverse
  h = retLen >> 1;
  for (int i = 0; i < h; i++) {
    t = ret[i];
    ret[i] = ret[retLen - i - 1];
    ret[retLen - i - 1] = t;
  }

  *returnSize = retLen;

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
  ret = decimalRepresentation(n, &s);
  print_1d_arr(ret, s);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
