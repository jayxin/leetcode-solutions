#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 869. 重新排序得到 2 的幂 - 给定正整数 n ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。
// 如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。
//  
// 示例 1：
// 输入：n = 1
// 输出：true
// 示例 2：
// 输入：n = 10
// 输出：false
//  
// 提示：
//  * 1 &lt;= n &lt;= 10^9

// #v1
bool reorderedPowerOf2(int n) {
  int j, i, tmp;
  char ndigits[10] = {0};
  bool f;

  // 分解 n
  tmp = n;
  while (tmp) {
    ndigits[tmp % 10] += 1;
    tmp /= 10;
  }

  // 分解 2 的幂, 通过比较各位数字是否相同来判断是否能重新组合得到 2 的幂
  for (i = 0; i < 31; i++) {
    char digits1[10] = {0};
    f = true;

    tmp = 1 << i;
    if (tmp == n) return true;

    while (tmp) {
      digits1[tmp % 10] += 1;
      tmp /= 10;
    }

    for (j = 0; j < 10; ++j) {
      if (digits1[j] != ndigits[j]) {
        f = false;
        break;
      }
    }

    if (f) return true;
  }

  return false;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (reorderedPowerOf2(n))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
