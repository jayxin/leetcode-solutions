#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3042. 统计前后缀下标对 I - 给你一个下标从 0 开始的字符串数组 words 。
// 定义一个 布尔 函数 isPrefixAndSuffix ，它接受两个字符串参数 str1 和 str2 ：
//  * 当 str1 同时是 str2 的前缀（prefix）和后缀（suffix）时，isPrefixAndSuffix(str1, str2) 返回 true，否则返回 false。
// 例如，isPrefixAndSuffix("aba", "ababa") 返回 true，因为 "aba" 既是 "ababa" 的前缀，也是 "ababa" 的后缀，但是 isPrefixAndSuffix("abc", "abcd") 返回 false。
// 以整数形式，返回满足 i < j 且 isPrefixAndSuffix(words[i], words[j]) 为 true 的下标对 (i, j) 的 数量 。
//  
// 示例 1：
// 输入：words = ["a","aba","ababa","aa"]
// 输出：4
// 解释：在本示例中，计数的下标对包括：
// i = 0 且 j = 1 ，因为 isPrefixAndSuffix("a", "aba") 为 true  。
// i = 0 且 j = 2 ，因为 isPrefixAndSuffix("a", "ababa") 为 true 。
// i = 0 且 j = 3 ，因为 isPrefixAndSuffix("a", "aa") 为 true 。
// i = 1 且 j = 2 ，因为 isPrefixAndSuffix("aba", "ababa") 为 true 。
// 因此，答案是 4 。
// 示例 2：
// 输入：words = ["pa","papa","ma","mama"]
// 输出：2
// 解释：在本示例中，计数的下标对包括：
// i = 0 且 j = 1 ，因为 isPrefixAndSuffix("pa", "papa") 为 true 。
// i = 2 且 j = 3 ，因为 isPrefixAndSuffix("ma", "mama") 为 true 。
// 因此，答案是 2 。
// 示例 3：
// 输入：words = ["abab","ab"]
// 输出：0
// 解释：在本示例中，唯一有效的下标对是 i = 0 且 j = 1 ，但是 isPrefixAndSuffix("abab", "ab") 为 false 。
// 因此，答案是 0 。
//  
// 提示：
//  * 1 <= words.length <= 50
//  * 1 <= words[i].length <= 10
//  * words[i] 仅由小写英文字母组成。

// #v1
bool isPrefixAndSuffix(char *s, char *t) {
  int n = strlen(t), m = strlen(s);
  char *p = s, *q = t;

  if (m > n) return false;

  while (*p && *q) {
    if (*p != *q) return false;
    ++p;
    ++q;
  }

  p = s + m - 1;
  q = t + n - 1;
  while (p >= s && q >= t) {
    if (*p != *q) return false;
    --p;
    --q;
  }

  return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
  int cnt = 0;

  for (int i = 0; i < wordsSize; i++) {
    for (int j = i+1; j < wordsSize; j++) {
      if (isPrefixAndSuffix(words[i], words[j])) ++cnt;
    }
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
  char **words;
  scanf("%d\n", &n);
  words = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  printf("%d\n", countPrefixSuffixPairs(words, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
