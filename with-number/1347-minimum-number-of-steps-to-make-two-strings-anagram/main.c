#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1347. 制造字母异位词的最小步骤数 - 给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。
// 返回使 t 成为 s 的字母异位词的最小步骤数。
// 字母异位词 指字母相同，但排列不同（也可能相同）的字符串。
//  
// 示例 1：
// 输出：s = "bab", t = "aba"
// 输出：1
// 提示：用 'b' 替换 t 中的第一个 'a'，t = "bba" 是 s 的一个字母异位词。
// 示例 2：
// 输出：s = "leetcode", t = "practice"
// 输出：5
// 提示：用合适的字符替换 t 中的 'p', 'r', 'a', 'i' 和 'c'，使 t 变成 s 的字母异位词。
// 示例 3：
// 输出：s = "anagram", t = "mangaar"
// 输出：0
// 提示："anagram" 和 "mangaar" 本身就是一组字母异位词。
// 示例 4：
// 输出：s = "xxyyzz", t = "xxyyzz"
// 输出：0
// 示例 5：
// 输出：s = "friend", t = "family"
// 输出：4
//  
// 提示：
//  * 1 <= s.length <= 50000
//  * s.length == t.length
//  * s 和 t 只包含小写英文字母

// #v1
int minSteps(char* s, char* t) {
  int c0[26] = {0}, c1[26] = {0}, ret = 0;

  while (*s) {
    ++c0[*s - 'a'];
    ++s;
  }

  while (*t) {
    ++c1[*t - 'a'];
    ++t;
  }

  for (int i = 0; i < 26; i++) {
    if (c1[i] < c0[i]) ret += c0[i] - c1[i];
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
  char s[100], t[100];
  read_line(s, 98, stdin);
  read_line(t, 98, stdin);
  printf("%d\n", minSteps(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
