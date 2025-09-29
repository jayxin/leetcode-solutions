#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 434.  字符串中的单词数 - 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
// 请注意，你可以假定字符串里不包括任何不可打印的字符。
// 示例:
// 输入: "Hello, my name is John"
// 输出: 5
// 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。

// #v1
int countSegments(char* s) {
  int l = 0, ret = 0;
  bool f = false;

  while (*s) {
    if (*s == ' ') {
      if (f) {
        f = false;
        ++ret;
      }
    } else {
      f = true;
    }

    ++l;
    ++s;
  }

  if (l && f) ++ret;

  return ret;
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
  char s[100];
  read_line(s, 99, stdin);
  printf("%d\n", countSegments(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
