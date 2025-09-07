#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 387. 字符串中的第一个唯一字符 - 给定一个字符串 s ，找到 它的第一个不重复的字符 ，并返回它的索引 。如果不存在，则返回 -1 。
//  
// 示例 1：
// 输入: s = "leetcode"
// 输出: 0
// 示例 2:
// 输入: s = "loveleetcode"
// 输出: 2
// 示例 3:
// 输入: s = "aabb"
// 输出: -1
//  
// 提示:
//  * 1 <= s.length <= 10^5
//  * s 只包含小写字母

// #v1
int firstUniqChar(char* s) {
  if (!s || *s == '\0') return -1;
  int tab[26], idx[26], ret = -1, i, cnt = 0;
  memset(tab, 0, sizeof(int) * 26);
  memset(idx, 0xff, sizeof(int) * 26);
  while (*s) {
    i = *s - 'a';
    tab[i]++;
    if (idx[i] == -1) {
      idx[i] = cnt;
    }
    cnt++;
    s++;
  }
  for (i = 0; i < 26; i++) {
    if (tab[i] == 1) {
      if (ret == -1) {
        ret = idx[i];
      } else {
        ret = (idx[i] < ret ? idx[i] : ret);
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
  char s[100];
  read_line(s, 99, stdin);
  printf("%d\n", firstUniqChar(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
