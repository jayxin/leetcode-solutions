#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1309. 解码字母到整数映射 - 给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：
//  * 字符（'a' - 'i'）分别用（'1' - '9'）表示。
//  * 字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
// 返回映射之后形成的新字符串。
// 题目数据保证映射始终唯一。
//  
// 示例 1：
// 输入：s = "10#11#12"
// 输出："jkab"
// 解释："j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
// 示例 2：
// 输入：s = "1326#"
// 输出："acz"
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 1000
//  * s[i] 只包含数字（'0'-'9'）和 '#' 字符。
//  * s 是映射始终存在的有效字符串。

// #v1
// 从后往前遍历字符串
char* freqAlphabets(char* s) {
  char map[27], *ret, *p = s, *e, c;
  int i, len = 0, retLen = 0;

  while (*p) {
    ++p;
    ++len;
  }

  // init
  for (i = 1; i <= 26; i++) {
    map[i] = 'a' + i - 1;
  }
  ret = (char *)malloc(sizeof(char) * (len + 1));

  p = s + len - 1;
  while (p >= s) {
    if (*p == '#') {
      i = (*(p - 2) - '0') * 10 + (*(p - 1) - '0');
      p -= 3;
    } else {
      i = *p - '0';
      --p;
    }

    ret[retLen++] = map[i];
  }

  ret[retLen] = '\0';

  p = ret;
  e = ret + retLen - 1;
  while (p < e) {
    c = *p;
    *p = *e;
    *e = c;
    ++p;
    --e;
  }

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
  char s[51];
  read_line(s, 50, stdin);
  printf("%s\n", freqAlphabets(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
