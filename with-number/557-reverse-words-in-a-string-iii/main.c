#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 557. 反转字符串中的单词 III - 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//  
// 示例 1：
// 输入：s = "Let's take LeetCode contest"
// 输出："s'teL ekat edoCteeL tsetnoc"
// 示例 2:
// 输入： s = "Mr Ding"
// 输出："rM gniD"
//  
// 提示：
//  * 1 <= s.length <= 5 * 104
//  * s 包含可打印的 ASCII 字符。
//  * s 不包含任何开头或结尾空格。
//  * s 里 至少 有一个词。
//  * s 中的所有单词都用一个空格隔开。

// #v1
void reverse(char *s, char *e) {
  char c;

  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;

    ++s;
    --e;
  }
}

char* reverseWords(char* s) {
  char *p, *q;

  p = q = s;
  while (*q) {
    if (*q == ' ') {
      reverse(p, q-1);
      p = q + 1;
    } else if (*(q + 1) == '\0') { // last word
      reverse(p, q);
    }

    ++q;
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
  char s[100];
  read_line(s, 98, stdin);
  printf("%s\n", reverseWords(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
