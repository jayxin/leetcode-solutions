#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3110. 字 符串的分数 - 给你一个字符串 s 。一个字符串的 分数 定义为相邻字符 ASCII 码差值绝对值的和。
// 请你返回 s 的 分数 。
//  
// 示例 1：
// 输入：s = &quot;hello&quot;
// 输出：13
// 解释：
// s 中字符的 ASCII 码分别为：'h' = 104 ，'e' = 101 ，'l' = 108 ，'o' = 111 。所以 s 的分数为 |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13 。
// 示例 2：
// 输入：s = &quot;zaz&quot;
// 输出：50
// 解释：
// s 中字符的 ASCII 码分别为：'z' = 122 ，'a' = 97 。所以 s 的分数为 |122 - 97| + |97 - 122| = 25 + 25 = 50 。
//  
// 提示：
//  * 2 &lt;= s.length &lt;= 100
//  * s 只包含小写英文字母。

// #v1
int abs(int x) { return x >= 0 ? x : -x; }

int scoreOfString(char* s) {
  char c = *s++;
  int ret = 0;

  while (*s) {
    ret += abs(*s - c);
    c = *s;
    ++s;
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
  char s[100];
  read_line(s, 98, stdin);
  printf("%d\n", scoreOfString(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
