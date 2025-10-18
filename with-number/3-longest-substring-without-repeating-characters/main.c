#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3.  无重复字符的最长子串 - 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
//  
// 示例 1:
// 输入: s = "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
// 示例 2:
// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:
// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串 。
//  
// 提示：
//  * 0 <= s.length <= 5 * 104
//  * s 由英文字母、数字、符号和空格组成

// #v1
short int ht[258];

void add(char c) {
  int idx = (int)c;
  ht[idx] = 1;
}

void del(char c) {
  int idx = (int)c;
  ht[idx] = 0;
}

int is_occurred(char c) {
  int idx = (int)c;
  return ht[idx];
}

int lengthOfLongestSubstring(char *s) {
  if (!s || *s == '\0') return 0;

  int ret = 0, len = strlen(s), sub_len = 0;
  char *l = s, *e = s + len - 1, *r = l;

  while (l <= e) {
    if (r < l) {
      r = l;
      memset(ht, 0, 258 * sizeof(short int));
      sub_len = 0;
    }

    while (r <= e) {
      if (is_occurred(*r))
        break;

      add(*r);
      sub_len++;
      r++;
    }

    // update
    if (sub_len > ret) {
      ret = sub_len;
    }

    del(*l);
    sub_len--;
    l++;
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
  read_line(s, 98, stdin);
  printf("%d\n", lengthOfLongestSubstring(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
