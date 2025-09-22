#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LCR 002. 二进制求和 - 给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式 输出。
// 输入为 非空 字符串且只包含数字 1 和 0。
//  
// 示例 1：
// 输入: a = "11", b = "10"
// 输出: "101"
// 示例 2：
// 输入: a = "1010", b = "1011"
// 输出: "10101"
//  
// 提示：
//  * 每个字符串仅由字符 '0' 或 '1' 组成。
//  * 1 &lt;= a.length, b.length &lt;= 10^4
//  * 字符串如果不是 "0" ，就都不含前导零。
// 注意：本题与主站 67 题相同：https://leetcode-cn.com/problems/add-binary/ [https://leetcode-cn.com/problems/add-binary/]

// #v1
#define max(a, b) (a > b ? a : b)

char* addBinary(char *a, char *b) {
  int alen = strlen(a),
      blen = strlen(b),
      retlen = 0;
  char *as = a, *ap = a + alen - 1,
       *bs = b, *bp = b + blen - 1;
  char *ret = (char *)malloc(sizeof(char) * (max(alen, blen) + 2));
  int carray = 0, result = 0;

  while (ap >= as && bp >= bs) {
    result = *ap + *bp - '0' - '0' + carray;
    carray = result / 2;
    result %= 2;

    if (result) {
      ret[retlen++] = '1';
    } else {
      ret[retlen++] = '0';
    }

    ap--;
    bp--;
  }

  while (ap >= as) {
    result = *ap - '0' + carray;
    carray = result / 2;
    result %= 2;

    if (result) {
      ret[retlen++] = '1';
    } else {
      ret[retlen++] = '0';
    }

    ap--;
  }

  while (bp >= bs) {
    result = *bp - '0' + carray;
    carray = result / 2;
    result %= 2;

    if (result) {
      ret[retlen++] = '1';
    } else {
      ret[retlen++] = '0';
    }

    bp--;
  }

  if (carray) {
    ret[retlen++] = '1';
  }

  ret[retlen] = '\0';

  for (int i = 0; i < retlen / 2; ++i) {
    char tmp = ret[i];
    ret[i] = ret[retlen - i - 1];
    ret[retlen - i - 1] = tmp;
  }

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
  int n;
  char a[1000], b[1000];
  read_line(a, 1000, stdin);
  read_line(b, 1000, stdin);
  printf("%s\n", addBinary(a, b));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
