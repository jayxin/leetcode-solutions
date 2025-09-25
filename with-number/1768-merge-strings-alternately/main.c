#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1768.  交替合并字符串 - 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加 字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字 符串的末尾。
// 返回 合并后的字符串 。
//  
// 示例 1：
// 输入：word1 = "abc", word2 = "pqr"
// 输出："apbqcr"
// 解释：字符串合并情况如下所示：
// word1：  a   b   c
// word2：    p   q   r
// 合并后：  a p b q c r
// 示例 2：
// 输入：word1 = "ab", word2 = "pqrs"
// 输出："apbqrs"
// 解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
// word1：  a   b
// word2：    p   q   r   s
// 合并后：  a p b q   r   s
// 示例 3：
// 输入：word1 = "abcd", word2 = "pq"
// 输出："apbqcd"
// 解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
// word1：  a   b   c   d
// word2：    p   q
// 合并后：  a p b q c   d
//  
// 提示：
//  * 1 &lt;= word1.length, word2.length &lt;= 100
//  * word1 和 word2 由小写英文字母组成

// #v1
char* mergeAlternately(char* word1, char* word2) {
  char *s, *p1, *p2;
  int l1, l2, l;

  p1 = word1;
  p2 = word2;
  l1 = l2 = l = 0;

  while (*p1) {
    ++p1;
    ++l1;
  }
  while (*p2) {
    ++p2;
    ++l2;
  }

  s = (char *)malloc(sizeof(char) * (l1 + l2 + 1));

  p1 = word1;
  p2 = word2;

  while (*p1 && *p2) {
    s[l++] = *p1;
    s[l++] = *p2;
    ++p1;
    ++p2;
  }

  while (*p1) s[l++] = *p1++;
  while (*p2) s[l++] = *p2++;

  s[l] = '\0';

  return s;
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
  char s1[100], s2[100];
  read_line(s1, 99, stdin);
  read_line(s2, 99, stdin);
  printf("%s\n", mergeAlternately(s1, s2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
