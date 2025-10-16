#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 3602. 十六进制和三十六进制转化 - 给你一个整数 n。
// 返回 n^2 的 十六进制表示 和 n^3 的 三十六进制表示 拼接成的字符串。
// 十六进制 数定义为使用数字 0 – 9 和大写字母 A - F 表示 0 到 15 的值。
// 三十六进制 数定义为使用数字 0 – 9 和大写字母 A - Z 表示 0 到 35 的值。
//  
// 示例 1：
// 输入：n = 13
// 输出： "A91P1"
// 解释：
//  * n2 = 13 * 13 = 169。在十六进制中，它转换为 (10 * 16) + 9 = 169，对应于 "A9"。
//  * n3 = 13 * 13 * 13 = 2197。在三十六进制中，它转换为 (1 * 362) + (25 * 36) + 1 = 2197，对应于 "1P1"。
//  * 连接两个结果得到 "A9" + "1P1" = "A91P1"。
// 示例 2：
// 输入：n = 36
// 输出："5101000"
// 解释：
//  * n2 = 36 * 36 = 1296。在十六进制中，它转换为 (5 * 162) + (1 * 16) + 0 = 1296， 对应于 "510"。
//  * n3 = 36 * 36 * 36 = 46656。在三十六进制中，它转换为 (1 * 363) + (0 * 362) + (0 * 36) + 0 = 46656，对应于 "1000"。
//  * 连接两个结果得到 "510" + "1000" = "5101000"。
//  
// 提示:
//  * 1 &lt;= n &lt;= 1000

// #v1
void reverse(char **s, int l) {
  char *p = *s, *q = p + l - 1, c;

  while (p < q) {
    c = *p;
    *p = *q;
    *q = c;
    ++p;
    --q;
  }
}

char* concatHex36(int n) {
  int n2 = n * n, n3 = n2 * n, i, len1, len2;
  char hexadecimalMap[16], hexatrigesimalMap[36], a1[30], a2[30],
       *ret, *s1 = a1, *s2 = a2;

  // init
  for (i = 0; i < 10; i++) {
    hexadecimalMap[i] = i + '0';
    hexatrigesimalMap[i] = i + '0';
  }

  for (i = 10; i < 16; i++) {
    hexadecimalMap[i] = i + 'A' - 10;
  }

  for (i = 10; i < 36; i++) {
    hexatrigesimalMap[i] = i + 'A' - 10;
  }

  len1 = len2 = 0;

  // compute n2
  while (n2) {
    s1[len1++] = hexadecimalMap[n2 % 16];
    n2 /= 16;
  }
  s1[len1] = '\0';
  reverse(&s1, len1);

  // compute n3
  while (n3) {
    s2[len2++] = hexatrigesimalMap[n3 % 36];
    n3 /= 36;
  }
  s2[len2] = '\0';
  reverse(&s2, len2);

  // concatenate
  ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

  for (i = 0; i < len1; i++) {
    ret[i] = s1[i];
  }

  for (i = 0; i < len2; i++) {
    ret[i+len1] = s2[i];
  }

  ret[len1 + len2] = '\0';

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", concatHex36(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
