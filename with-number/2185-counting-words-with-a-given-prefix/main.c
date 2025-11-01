#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2185. 统计包含给定前缀的字符串 - 给你一个字符串数组 words 和一个字符串 pref 。
// 返回 words 中以 pref 作为 前缀 的字符串的数目。
// 字符串 s 的 前缀 就是  s 的任一前导连续字符串。
//  
// 示例 1：
// 输入：words = ["pay","attention","practice","attend"], pref = "at"
// 输出：2
// 解释：以 "at" 作为前缀的字符串有两个，分别是："attention" 和 "attend" 。
// 示例 2：
// 输入：words = ["leetcode","win","loops","success"], pref = "code"
// 输出：0
// 解释：不存在以 "code" 作为前缀的字符串。
//  
// 提示：
//  * 1 <= words.length <= 100
//  * 1 <= words[i].length, pref.length <= 100
//  * words[i] 和 pref 由小写英文字母组成

// #v1
int prefixCount(char** words, int wordsSize, char* pref) {
  int ret = 0;
  char *p, *q;

  for (int i = 0; i < wordsSize; i++) {
    p = words[i];
    q = pref;

    while (*p && *q) {
      if (*p != *q) break;

      ++p;
      ++q;
    }

    if (*q == '\0') ++ret;
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
  int n;
  char **words, s[100];
  scanf("%d\n", &n);
  words = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  read_line(s, 98, stdin);
  printf("%d\n", prefixCount(words, n, s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
