#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2255. 统计是给定字符串前缀的字符串数目 - 给你一个字符串数组 words 和一个字符串 s ，其中 words[i] 和 s 只包含 小写英文字母 。
// 请你返回 words 中是字符串 s 前缀 的 字符串数目 。
// 一个字符串的 前缀 是出现在字符串开头的子字符串。子字符串 是一个字符串中的连续一段字符序列。
//  
// 示例 1：
// 输入：words = ["a","b","c","ab","bc","abc"], s = "abc"
// 输出：3
// 解释：
// words 中是 s = "abc" 前缀的字符串为：
// "a" ，"ab" 和 "abc" 。
// 所以 words 中是字符串 s 前缀的字符串数目为 3 。
// 示例 2：
// 输入：words = ["a","a"], s = "aa"
// 输出：2
// 解释：
// 两个字符串都是 s 的前缀。
// 注意，相同的字符串可能在 words 中出现多次，它们应该被计数多次。
//  
// 提示：
//  * 1 <= words.length <= 1000
//  * 1 <= words[i].length, s.length <= 10
//  * words[i] 和 s 只 包含小写英文字母。

// #v1
int countPrefixes(char** words, int wordsSize, char* s) {
  int cnt = 0;
  char *p, *q;

  for (int i = 0; i < wordsSize; i++) {
    p = words[i];
    q = s;

    while (*q && *p) {
      if (*q != *p) break;

      ++p;
      ++q;
    }

    if (*p == '\0') ++cnt;
  }

  return cnt;
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
  printf("%d\n", countPrefixes(words, n, s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
