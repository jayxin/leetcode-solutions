#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3663. 出现频率最低的数字 - 给你一个整数 n，找出在其十进制表示中出现频率 最低 的数字 。如果多个数字的出现频率相同，则选择 最小 的那个数字。
// 以整数形式返回所选的数字。
// 数字 x 的出现频率是指它在 n 的十进制表示中的出现次数。
//  
// 示例 1:
// 输入： n = 1553322
// 输出： 1
// 解释：
// 在 n 中，出现频率最低的数字是 1，它只出现了一次。所有其他数字都出现了两次。
// 示例 2:
// 输入： n = 723344511
// 输出： 2
// 解释：
// 在 n 中，出现频率最低的数字是 7、2 和 5，它们都只出现了一次。
//  
// 提示:
//  * 1 <= n <= 2^31 - 1

// #v1
int getLeastFrequentDigit(int n) {
  int digits[10], ret, t;
  memset(digits, 0, sizeof(int) * 10);
  while (n) {
    digits[n % 10]++;
    n /= 10;
  }
  t = -1;
  for (int i = 0; i < 10; i++) {
    if (digits[i]) {
      if (t < 0) {
        ret = i;
        t = digits[i];
      } else {
        if (digits[i] < t) {
          ret = i;
          t = digits[i];
        }
      }
    }
  }
  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", getLeastFrequentDigit(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
