#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3146. 两个字符串的排列差 - 给你两个字符串 s 和 t，每个字符串中的字符都不重复，且 t  是 s 的一个排列。
// 排列差 定义为 s 和 t 中每个字符在两个字符串中位置的绝对差值之和。
// 返回 s 和 t 之间的 排列差 。
//  
// 示例 1：
// 输入：s = "abc", t = "bac"
// 输出：2
// 解释：
// 对于 s = "abc" 和 t = "bac"，排列差是：
//  * "a" 在 s 中的位置与在 t 中的位置之差的绝对值。
//  * "b" 在 s 中的位置与在 t 中的位置之差的绝对值。
//  * "c" 在 s 中的位置与在 t 中的位置之差的绝对值。
// 即，s 和 t 的排列差等于 |0 - 1| + |1 - 0| + |2 - 2| = 2。
// 示例 2：
// 输入：s = "abcde", t = "edbac"
// 输出：12
// 解释： s 和 t 的排列差等于 |0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12。
//  
// 提示：
//  * 1 <= s.length <= 26
//  * 每个字符在 s 中最多出现一次。
//  * t 是 s 的一个排列。
//  * s 仅由小写英文字母组成。

// #v1
int abs(int x) { return x >= 0 ? x : -x; }

int findPermutationDifference(char* s, char* t) {
  char ht[26];
  int i, ret = 0;

  i = 0;
  while (*s) {
    ht[*s - 'a'] = i;
    ++i;
    ++s;
  }

  i = 0;
  while (*t) {
    ret += abs(ht[*t - 'a'] - i);

    ++i;
    ++t;
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
  char s[50], t[50];
  read_line(s, 48, stdin);
  read_line(t, 48, stdin);
  printf("%d\n", findPermutationDifference(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
