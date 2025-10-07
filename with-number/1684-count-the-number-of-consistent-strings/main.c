#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1684. 统计一致字符串的数目 - 给你一个由不同字符组成的字符串 allowed 和一个字符串数组 words 。如果一个字符串的每一个字符都在 allowed 中，就称这个字符串是 一致字符串 。
// 请你返回 words 数组中 一致字符串 的数目。
//  
// 示例 1：
// 输入：allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// 输出：2
// 解释：字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
// 示例 2：
// 输入：allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
// 输出：7
// 解释：所有字符串都是一致的。
// 示例 3：
// 输入：allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
// 输出：4
// 解释：字符串 "cc"，"acd"，"ac" 和 "d" 是 一致字符串。
//  
// 提示：
//  * 1 <= words.length <= 104
//  * 1 <= allowed.length <= 26
//  * 1 <= words[i].length <= 10
//  * allowed 中的字符 互不相同 。
//  * words[i] 和 allowed 只包含小写英文字母。

// #v1
int countConsistentStrings(char* allowed, char** words, int wordsSize) {
  int cnt = 0;
  int64_t set = 0LL;
  char *s = allowed;

  while (*s) {
    set |= 1LL << ((*s) & 0x3f);
    ++s;
  }

  for (int i = 0; i < wordsSize; i++) {
    s = words[i];

    while (*s) {
      if (((set >> ((*s) & 0x3f)) & 1) == 0) break;
      ++s;
    }

    if (*s == '\0') ++cnt;
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
  char s[50], **w = NULL;
  read_line(s, 49, stdin);
  scanf("%d\n", &n);
  w = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    w[i] = (char *)malloc(sizeof(char) * 60);
    read_line(w[i], 49, stdin);
  }
  printf("%d\n", countConsistentStrings(s, w, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
