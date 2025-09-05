#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 28. 找出字符串中第一个匹配项的下标 - 给你两个字符串 haystack 和 needle ， 请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
//  
// 示例 1：
// 输入：haystack = "sadbutsad", needle = "sad"
// 输出：0
// 解释："sad" 在下标 0 和 6 处匹配。
// 第一个匹配项的下标是 0 ，所以返回 0 。
// 示例 2：
// 输入：haystack = "leetcode", needle = "leeto"
// 输出：-1
// 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
//  
// 提示：
//  * 1 <= haystack.length, needle.length <= 104
//  * haystack 和 needle 仅由小写英文字符组成

// #v1
int strStr(char* haystack, char* needle) {
  int l1 = strlen(haystack), l2 = strlen(needle), i;
  if (l1 < l2) return -1;
  for (i = 0; i < l1 - l2 + 1; i++) {
    if (haystack[i] == needle[0] && haystack[i + l2 - 1] == needle[l2 - 1]) {
      if (!memcmp(haystack + i, needle, l2)) {
        return i;
      }
    }
  }
  return -1;
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
  char str1[100], str2[100];
  read_line(str1, 99, stdin);
  read_line(str2, 99, stdin);
  printf("%d\n", strStr(str1, str2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
