#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 318.  最大单词长度乘积 - 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返 回 0 。
//  
// 示例 1：
// 输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// 输出：16
// 解释：这两个单词为 "abcw", "xtfn"。
// 示例 2：
// 输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
// 输出：4
// 解释：这两个单词为 "ab", "cd"。
// 示例 3：
// 输入：words = ["a","aa","aaa","aaaa"]
// 输出：0
// 解释：不存在这样的两个单词。
//  
// 提示：
//  * 2 <= words.length <= 1000
//  * 1 <= words[i].length <= 1000
//  * words[i] 仅包含小写字母

// #v1
struct Pair {
  int64_t set;
  int len;
};

int maxProduct(char** words, int wordsSize) {
  struct Pair p[wordsSize];
  int i, j, ret = 0, t;
  char *s;

  for (i = 0; i < wordsSize; i++) {
    s = words[i];
    p[i].len = 0;
    p[i].set = 0LL;
    while (*s) {
      p[i].set |= 1LL << (0x3f & (*s));
      ++p[i].len;
      ++s;
    }
  }

  for (i = 0; i < wordsSize; i++) {
    for (j = i + 1; j < wordsSize; j++) {
      if (!(p[i].set & p[j].set)) {
        t = p[i].len * p[j].len;
        if (t > ret) ret = t;
      }
    }
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
  char **s;
  scanf("%d\n", &n);
  s = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(sizeof(char) * 100);
    read_line(s[i], 99, stdin);
  }
  printf("%d\n", maxProduct(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
