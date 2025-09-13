#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2414. 最长的字母序连续子字符串的长度 - 字母序连续字符串 是由字母表中连续字母组成的字符串。换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意 子字符串都是 字母序连续字符串 。
//  * 例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。
// 给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。
//  
// 示例 1：
// 输入：s = "abacaba"
// 输出：2
// 解释：共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
// "ab" 是最长的字母序连续子字符串。
// 示例 2：
// 输入：s = "abcde"
// 输出：5
// 解释："abcde" 是最长的字母序连续子字符串。
//  
// 提示：
//  * 1 <= s.length <= 105
//  * s 由小写英文字母组成

// #v1
int longestContinuousSubstring(char* s) {
  int ret, cnt = 1;
  char *p = s;
  ++p;
  ret = cnt;

  while (*p) {
    if (ret == 26) return 26;
    if (*(p - 1) == (*p) - 1) {
      ++cnt;
    } else {
      if (ret < cnt) ret = cnt;
      cnt = 1;
    }
    ++p;
  }

  if (ret < cnt) ret = cnt;

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
  printf("%d\n", longestContinuousSubstring(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
