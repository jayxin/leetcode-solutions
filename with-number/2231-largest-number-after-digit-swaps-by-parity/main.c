#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2231. 按奇偶性交换后的最大数字 - 给你一个正整数 num 。你可以交换 num 中 奇偶性 相同的任意两位数字（即，都是奇数或者偶数）。
// 返回交换 任意 次之后 num 的 最大 可能值。
//  
// 示例 1：
// 输入：num = 1234
// 输出：3412
// 解释：交换数字 3 和数字 1 ，结果得到 3214 。
// 交换数字 2 和数字 4 ，结果得到 3412 。
// 注意，可能存在其他交换序列，但是可以证明 3412 是最大可能值。
// 注意，不能交换数字 4 和数字 1 ，因为它们奇偶性不同。
// 示例 2：
// 输入：num = 65875
// 输出：87655
// 解释：交换数字 8 和数字 6 ，结果得到 85675 。
// 交换数字 5 和数字 7 ，结果得到 87655 。
// 注意，可能存在其他交换序列，但是可以证明 87655 是最大可能值。
//  
// 提示：
//  * 1 <= num <= 109

// #v1
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int largestInteger(int num) {
  int a[12], aLen = 0;
  int odds[12], oddsLen = 0;
  int evens[12], evensLen = 0;

  while (num) {
    int r = num % 10;

    a[aLen++] = r & 1;
    if (r & 1) odds[oddsLen++] = r;
    else evens[evensLen++] = r;

    num /= 10;
  }

  qsort(odds, oddsLen, sizeof(int), cmp);
  qsort(evens, evensLen, sizeof(int), cmp);

  int p = 0, q = 0;
  for (int i = 0; i < aLen; i++) {
    a[i] = a[i] == 1 ? odds[p++] : evens[q++];
  }

  int ret = 0;
  for (int i = aLen - 1; i >= 0; i--) {
    ret = ret * 10 + a[i];
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", largestInteger(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
