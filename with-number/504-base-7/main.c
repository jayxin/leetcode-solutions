#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 504. 七进制数 - 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
//  
// 示例 1:
// 输入: num = 100
// 输出: &quot;202&quot;
// 示例 2:
// 输入: num = -7
// 输出: &quot;-10&quot;
//  
// 提示：
//  * -107 &lt;= num &lt;= 107

// #v1
char* convertToBase7(int num) {
  char *ret = (char *)malloc(sizeof(char) * 13);
  char c, *s, *e;
  int len = 0, sign;
  if (!num) {
    ret[0] = '0';
    ret[1] = '\0';
    return ret;
  }

  // fill array
  sign = (num >= 0) ? 1 : -1;
  if (sign < 0) {
    num = -num;
    ret[len++] = '-';
  }
  while (num) {
    ret[len++] = num % 7 + '0';
    num /= 7;
  }
  ret[len] = '\0';

  // reverse string
  if (sign == 1) { // positive
    s = ret;
    e = ret + len - 1;
  } else { // negative
    s = ret + 1;
    e = ret + len - 1;
  }
  while (s < e) {
    // swap
    c = *s;
    *s = *e;
    *e = c;

    s++;
    e--;
  }
  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", convertToBase7(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
