#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1662. 检查两个字符串数组是否相等 - 给你两个字符串数组 word1 和 word2 。如果 两个数组表示的字符串相同，返回 true ；否则，返回 false 。
// 数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
//  
// 示例 1：
// 输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
// 输出：true
// 解释：
// word1 表示的字符串为 "ab" + "c" -> "abc"
// word2 表示的字符串为 "a" + "bc" -> "abc"
// 两个字符串相同，返回 true
// 示例 2：
// 输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
// 输出：false
// 示例 3：
// 输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
// 输出：true
//  
// 提示：
//  * 1 <= word1.length, word2.length <= 103
//  * 1 <= word1[i].length, word2[i].length <= 103
//  * 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
//  * word1[i] 和 word2[i] 由小写字母组成

// #v1
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
  char *p, *q, f1, f2;
  int i = 0, j = 0;

  // init
  p = word1[0];
  q = word2[0];
  f1 = f2 = 0;

  while (i < word1Size && j < word2Size) {
    if (f1) {
      p = word1[i];
      f1 = 0;
    }
    if (f2) {
      q = word2[j];
      f2 = 0;
    }

    while (*p && *q) {
      if (*p != *q) return false;
      ++p;
      ++q;
    }

    if (*p == '\0') {
      f1 = 1;
      ++i;
    }
    if (*q == '\0') {
      f2 = 1;
      ++j;
    }
  }

  return i == word1Size && j == word2Size;
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
  int n1, n2;
  char **word1, **word2;
  scanf("%d\n", &n1);
  word1 = calloc(n1, sizeof(char *));
  for (int i = 0; i < n1; i++) {
    word1[i] = calloc(100, sizeof(char));
    read_line(word1[i], 98, stdin);
  }

  scanf("%d\n", &n2);
  word2 = calloc(n2, sizeof(char *));
  for (int i = 0; i < n2; i++) {
    word2[i] = calloc(100, sizeof(char));
    read_line(word2[i], 98, stdin);
  }

  if (arrayStringsAreEqual(word1, n1, word2, n2))
    printf("true\n");
  else
    printf("false\n");

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
