#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1160. 拼写单 词 - 给定一个字符串数组 words 和一个字符串 chars。
// 如果字符串可以由 chars 中的字符组成（每个字符在 每个 words 中只能使用一次），则认为它是好的。
// 返回 words 中所有好的字符串的长度之和。
//  
// 示例 1：
// 输入：words = ["cat","bt","hat","tree"], chars = "atach"
// 输出：6
// 解释：
// 可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
// 示例 2：
// 输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// 输出：10
// 解释：
// 可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
//  
// 提示：
//  * 1 <= words.length <= 1000
//  * 1 <= words[i].length, chars.length <= 100
//  * words[i] 和 chars 中都仅包含小写英文字母

// #v1
int countCharacters(char** words, int wordsSize, char* chars) {
  int c0[26] = {0}, c1[26], ret = 0;

  while (*chars) {
    ++c0[*chars - 'a'];
    ++chars;
  }

  for (int i = 0; i < wordsSize; i++) {
    memset(c1, 0, sizeof(c1));

    int len = 0;
    char *s = words[i], f = 1;

    while (*s) {
      ++c1[*s - 'a'];
      ++len;
      ++s;
    }

    for (int j = 0; j < 26; j++) {
      if (c1[j] && c1[j] > c0[j]) {
        f = 0;
        break;
      }
    }

    if (f) ret += len;
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
  char **words, s[100];
  int n;

  scanf("%d\n", &n);
  words = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  read_line(s, 98, stdin);

  printf("%d\n", countCharacters(words, n, s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
