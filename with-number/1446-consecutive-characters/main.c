#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1446. 连续字 符 - 给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串 的长度。
// 请你返回字符串 s 的 能量。
//  
// 示例 1：
// 输入：s = "leetcode"
// 输出：2
// 解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
// 示例 2：
// 输入：s = "abbcccddddeeeeedcba"
// 输出：5
// 解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 500
//  * s 只包含小写英文字母。

// #v1
int maxPower(char* s) {
  if (!s || *s == '\0') return 0;
  int m = 1, cnt = 0;
  char c = *s;
  while (*s) {
    if (c == *s) {
      cnt++;
    } else {
      if (cnt > m) m = cnt;
      cnt = 1;
      c = *s;
    }
    s++;
  }
  if (cnt > m) m = cnt;
  return m;
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
  char str[100];
  read_line(str, 99, stdin);
  printf("%d\n", maxPower(str));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
