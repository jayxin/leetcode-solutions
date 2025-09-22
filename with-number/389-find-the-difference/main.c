#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 389. 找不同 - 给定两个字符串 s 和 t ，它们只包含小写字母。
// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
// 请找出在 t 中被添加的字母。
//  
// 示例 1：
// 输入：s = "abcd", t = "abcde"
// 输出："e"
// 解释：'e' 是那个被添加的字母。
// 示例 2：
// 输入：s = "", t = "y"
// 输出："y"
//  
// 提示：
//  * 0 &lt;= s.length &lt;= 1000
//  * t.length == s.length + 1
//  * s 和 t 只包含小写字母

// #v1
char findTheDifference(char* s, char* t) {
  char c = *t++;

  while (*s) c ^= *s++;
  while (*t) c ^= *t++;

  return c;
}
// #v1

// read one line from stream
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
  char s[100], t[100];
  read_line(s, 99, stdin);
  read_line(t, 99, stdin);
  printf("%c\n", findTheDifference(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
