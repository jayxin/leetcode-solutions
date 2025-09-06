#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 709. 转 换成小写字母 - 给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返 回新的字符串。
//  
// 示例 1：
// 输入：s = "Hello"
// 输出："hello"
// 示例 2：
// 输入：s = "here"
// 输出："here"
// 示例 3：
// 输入：s = "LOVELY"
// 输出："lovely"
//  
// 提示：
//  * 1 <= s.length <= 100
//  * s 由 ASCII 字符集中的可打印字符组成

// #v1
char* toLowerCase(char* s) {
  char *p = s;
  while (*p) {
    if (*p >= 'A' && *p <= 'Z')
      *p |= 0x20;

    p++;
  }
  return s;
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
  char s[200];
  read_line(s, 199, stdin);
  printf("%s\n", toLowerCase(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
