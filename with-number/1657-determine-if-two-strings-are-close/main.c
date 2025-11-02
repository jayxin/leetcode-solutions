#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1657. 确定两个字符串是否接近 - 如果可以使用以下操作从一个字符串得到另一个字符串 ，则认为两个字符串 接近 ：
//  * 操作 1：交换任意两个 现有 字符。
//    * 例如，abcde -> aecdb
//  * 操作 2：将一个 现有 字符的每次出现转换为另一个 现有 字符，并对另一个字符执行相同的操作。
//    * 例如，aacabb -> bbcbaa（所有 a 转化为 b ，而所有的 b 转换为 a ）
// 你可以根据需要对任意一个字符串多次使用这两种操作。
// 给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true ；否则， 返回 false 。
//  
// 示例 1：
// 输入：word1 = "abc", word2 = "bca"
// 输出：true
// 解释：2 次操作从 word1 获得 word2 。
// 执行操作 1："abc" -> "acb"
// 执行操作 1："acb" -> "bca"
// 示例 2：
// 输入：word1 = "a", word2 = "aa"
// 输出：false
// 解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
// 示例 3：
// 输入：word1 = "cabbba", word2 = "abbccc"
// 输出：true
// 解释：3 次操作从 word1 获得 word2 。
// 执行操作 1："cabbba" -> "caabbb"
// 执行操作 2："caabbb" -> "baaccc"
// 执行操作 2："baaccc" -> "abbccc"
// 提示：
//  * 1 <= word1.length, word2.length <= 105
//  * word1 和 word2 仅包含小写英文字母

// #v1
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool closeStrings(char* word1, char* word2) {
  int set1 = 0, set2 = 0, c1[26] = {0}, c2[26] = {0}, a1[26], a2[26], a1Len = 0,
      a2Len = 0;
  char *s;

  s = word1;
  while (*s) {
    set1 |= 1 << (*s & 0x1f);
    ++c1[*s - 'a'];
    ++s;
  }

  s = word2;
  while (*s) {
    set2 |= 1 << (*s & 0x1f);
    ++c2[*s - 'a'];
    ++s;
  }

  if (set1 != set2) return false;

  for (int i = 0; i < 26; i++) {
    if (c1[i]) a1[a1Len++] = c1[i];
  }

  for (int i = 0; i < 26; i++) {
    if (c2[i]) a2[a2Len++] = c2[i];
  }

  if (a1Len != a2Len) return false;

  qsort(a1, a1Len, sizeof(int), cmp);
  qsort(a2, a2Len, sizeof(int), cmp);

  for (int i = 0; i < a1Len; i++) {
    if (a1[i] != a2[i]) return false;
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
  char s[100], t[100];
  read_line(s, 98, stdin);
  read_line(t, 98, stdin);

  if (closeStrings(s, t))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
