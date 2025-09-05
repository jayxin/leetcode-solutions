#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 8. 字符串转换整数 (atoi)
// 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。

// 函数 myAtoi(string s) 的算法如下：
//
//     空格：读入字符串并丢弃无用的前导空格（" "）
//     符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
//     转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
//     舍入：如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
//
// 返回整数作为最终结果。

//  0 <= s.length <= 200
//  s 由英文字母（大写和小写）、数字（0-9）、' '、'+'、'-' 和 '.' 组成

// #v1
int myAtoi(char *s) {
  int ret = 0, len = strlen(s), sign = 0, num;
  char *l = s, *r = s + len;
  const int int_min_10 = -214748364,
            int_max_10 = 214748364,
            int_min = -2147483648,
            int_max = 2147483647;

  // delete space
  while (l < r && *l == ' ') {
    l++;
  }

  // sign
  if (l < r && !sign) {
    if (*l == '-') {
      sign = -1;
      l++;
    } else if (*l == '+') {
      sign = 1;
      l++;
    } else if (isdigit(*l)) {
      sign = 1;
    } else { // non-digit and non-sign
      return 0;
    }
  }

  while (l < r && isdigit(*l)) { // find digit only
    // get digit
    num = *l - '0';

    // before multiply, we should check if we can do it!
    if (sign == 1) { // positive
      // will overflow?
      if ((ret == int_max_10 && num > 7) || (ret > int_max_10)) {
        return int_max;
      }
    } else { // negative
      // will overflow?
      // make sure to change the sign of `ret` when compare
      if ((-ret == int_min_10 && num >= 8) || (-ret < int_min_10)) {
        return int_min;
      }
    }

    ret = ret * 10 + num;
    l++;
  }

  // change sign
  ret *= sign;

  return ret;
}
// #v1

char* read_line(char *buffer, size_t size, FILE *stream) {
  if (fgets(buffer, size, stream) == NULL) {
    return NULL;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return buffer;
}

int main(int argc, char *argv[])
{
  char str[201];
  read_line(str, 200, stdin);
  printf("%d\n", myAtoi(str));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
