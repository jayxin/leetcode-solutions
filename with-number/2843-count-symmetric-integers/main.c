#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2843. 统计对称整数的数目 - 给你两个正整数 low 和 high 。
// 对于一个由 2 * n 位数字组成的整数 x ，如果其前 n 位数字之和与后 n 位数字之和相等 ，则认为这个数字是一个对称整数。
// 返回在 [low, high] 范围内的 对称整数的数目 。
//  
// 示例 1：
// 输入：low = 1, high = 100
// 输出：9
// 解释：在 1 到 100 范围内共有 9 个对称整数：11、22、33、44、55、66、77、88 和 99  。
// 示例 2：
// 输入：low = 1200, high = 1230
// 输出：4
// 解释：在 1200 到 1230 范围内共有 4 个对称整数：1203、1212、1221 和 1230 。
//  
// 提示：
//  * 1 <= low <= high <= 104

// #v1
int countSymmetricIntegers(int low, int high) {
  int cnt = 0, len, j, a, b, tmp, h;
  char arr[6];

  for (int i = low; i <= high; i++) {
    len = 0;
    tmp = i;

    while (tmp) {
      arr[len++] = tmp % 10;
      tmp /= 10;
    }
    if (len & 1) {
      i += 10 - arr[0];
      continue;
    }

    a = b = 0;
    h = len >> 1;

    for (j = 0; j < h; j++) a += arr[j];
    for (j = h; j < len; j++) b += arr[j];

    if (a == b) ++cnt;
  }

  return cnt;
}
// #v1

int main(int argc, char *argv[])
{
  int m, n;
  scanf("%d%d", &m, &n);
  printf("%d\n", countSymmetricIntegers(m, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
