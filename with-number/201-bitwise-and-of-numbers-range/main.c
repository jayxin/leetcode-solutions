#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 201. 数 字范围按位与 - 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
//  
// 示例 1：
// 输入：left = 5, right = 7
// 输出：4
// 示例 2：
// 输入：left = 0, right = 0
// 输出：0
// 示例 3：
// 输入：left = 1, right = 2147483647
// 输出：0
//  
// 提示：
//  * 0 <= left <= right <= 2^31 - 1

// #v1
int rangeBitwiseAnd(int left, int right) {
  int ret = left, tmp = left;
  int i = 0, p, q;

  while (tmp) {
    if (tmp & 1) {
      p = 1<<i;

      q = right & (~(p-1));
      q &= ~p;

      // unset bit if condition is satisfied
      if (q >= left && q <= right) ret &= ~p;
    }

    // forward
    i++;
    tmp >>= 1;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int l, r;
  scanf("%d%d", &l, &r);
  printf("%d\n", rangeBitwiseAnd(l, r));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
