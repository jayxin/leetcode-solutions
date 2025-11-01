#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1961. 检查字符串是否为数组前缀 - 给你一个字符串 s 和一个字符串数组 words ，请 你判断 s 是否为 words 的 前缀字符串 。
// 字符串 s 要成为 words 的 前缀字符串 ，需要满足：s 可以由 words 中的前 k（k 为 正 数 ）个字符串按顺序相连得到，且 k 不超过 words.length 。
// 如果 s 是 words 的 前缀字符串 ，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：s = "iloveleetcode", words = ["i","love","leetcode","apples"]
// 输出：true
// 解释：
// s 可以由 "i"、"love" 和 "leetcode" 相连得到。
// 示例 2：
// 输入：s = "iloveleetcode", words = ["apples","i","love","leetcode"]
// 输出：false
// 解释：
// 数组的前缀相连无法得到 s 。
//  
// 提示：
//  * 1 <= words.length <= 100
//  * 1 <= words[i].length <= 20
//  * 1 <= s.length <= 1000
//  * words[i] 和 s 仅由小写英文字母组成

// #v1
bool isPrefixString(char* s, char** words, int wordsSize) {
  char *p = s, *q;
  int i = 0;

  while (i < wordsSize) {
    q = words[i];

    while (*p && *q) {
      if (*p != *q) return false;
      ++q;
      ++p;
    }

    if (*p == '\0') break;

    ++i;
  }

  return *p == '\0' && *q == '\0';
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
  int n;
  char **words, s[100];
  scanf("%d\n", &n);
  words = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  read_line(s, 98, stdin);
  if (isPrefixString(s, words, n))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
