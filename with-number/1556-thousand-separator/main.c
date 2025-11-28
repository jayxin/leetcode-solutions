#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1556. 千位 分隔数 - 给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔 符，并将结果以字符串格式返回。
//  
// 示例 1：
// 输入：n = 987
// 输出："987"
// 示例 2：
// 输入：n = 1234
// 输出："1.234"
// 示例 3：
// 输入：n = 123456789
// 输出："123.456.789"
// 示例 4：
// 输入：n = 0
// 输出："0"
//  
// 提示：
//  * 0 <= n < 2^31

// #v1
char* thousandSeparator(int n) {
  if (!n) return "0";

  int len, x, retLen;
  char *ret;

  // compute length
  len = 0;
  x = n;
  while (x) {
    ++len;
    x /= 10;
  }

  // allocate
  ret = (char *)malloc(sizeof(char) * (len << 1));
  retLen = 0;

  // build string
  int c = 0;
  x = n;
  while (x) {
    ret[retLen++] = x % 10 + '0';
    x /= 10;
    ++c;

    if (c == 3 && x) {
      ret[retLen++] = '.';
      c = 0;
    }
  }

  // string end
  ret[retLen] = '\0';

  // reverse string
  char *s = ret, *e = ret + retLen-1, tmp;
  while (s < e) {
    tmp = *s;
    *s = *e;
    *e = tmp;
    ++s;
    --e;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", thousandSeparator(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
