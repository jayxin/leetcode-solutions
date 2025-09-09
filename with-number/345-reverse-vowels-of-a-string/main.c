#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 345. 反转字符串中的元音字母 - 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
//  
// 示例 1：
// 输入：s = "IceCreAm"
// 输出："AceCreIm"
// 解释：
// s 中的元音是 ['I', 'e', 'e', 'A']。反转这些元音，s 变为 "AceCreIm".
// 示例 2：
// 输入：s = "leetcode"
// 输出："leotcede"
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 3 * 105
//  * s 由 可打印的 ASCII 字符组成

// #v1
bool isVowel(char c) {
  c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char* reverseVowels(char* s) {
  int len = strlen(s);
  if (len == 1) return s;

  char *l  = s, *r = s + len - 1, c;
  while (l < r) {
    // find vowel from left direction
    while (l < r && !isVowel(*l)) {
      l++;
    }

    // find vowel from right direction
    while (l < r && !isVowel(*r)) {
      r--;
    }

    if (l < r) {
      // swap
      c = *l;
      *l = *r;
      *r = c;

      l++;
      r--;
    }
  }
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
  char s[200];
  read_line(s, 199, stdin);
  printf("%s\n", reverseVowels(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
