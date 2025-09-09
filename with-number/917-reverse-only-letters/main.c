#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 917. 仅仅 反转字母 - 给你一个字符串 s ，根据下述规则反转字符串：
//  * 所有非英文字母保留在原有位置。
//  * 所有英文字母（小写或大写）位置反转。
// 返回反转后的 s 。
//  
// 示例 1：
// 输入：s = "ab-cd"
// 输出："dc-ba"
// 示例 2：
// 输入：s = "a-bC-dEf-ghIj"
// 输出："j-Ih-gfE-dCba"
// 示例 3：
// 输入：s = "Test1ng-Leet=code-Q!"
// 输出："Qedo1ct-eeLg=ntse-T!"
//  
// 提示
//  * 1 &lt;= s.length &lt;= 100
//  * s 仅由 ASCII 值在范围 [33, 122] 的字符组成
//  * s 不含 '\"' 或 '\\'

// #v1
char* reverseOnlyLetters(char* s) {
  int len = strlen(s);
  if (len == 1) return s;

  char *l  = s, *r = s + len - 1, c;
  while (l < r) {
    while (l < r && !isalpha(*l)) {
      l++;
    }

    while (l < r && !isalpha(*r)) {
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
  printf("%s\n", reverseOnlyLetters(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
