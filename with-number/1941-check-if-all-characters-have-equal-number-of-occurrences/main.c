#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1941. 检查是否所有字符出现次数相同 - 给你一个字符串 s ，如果 s 是一个 好  字符串，请你返回 true ，否则请返回 false 。
// 如果 s 中出现过的 所有 字符的出现次数 相同 ，那么我们称字符串 s 是 好 字符串。
//  
// 示例 1：
// 输入：s = "abacbc"
// 输出：true
// 解释：s 中出现过的字符为 'a'，'b' 和 'c' 。s 中所有字符均出现 2 次。
// 示例 2：
// 输入：s = "aaabb"
// 输出：false
// 解释：s 中出现过的字符为 'a' 和 'b' 。
// 'a' 出现了 3 次，'b' 出现了 2 次，两者出现次数不同。
//  
// 提示：
//  * 1 <= s.length <= 1000
//  * s 只包含小写英文字母。

// #v1
bool areOccurrencesEqual(char* s) {
  int t[26] = {0}, i, c = *s - 'a';

  while (*s) {
    ++t[*s - 'a'];
    ++s;
  }

  for (i = 0; i < 26; i++) {
    if (t[i] && t[i] != t[c]) return false;
  }

  return true;
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
  if (areOccurrencesEqual(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
