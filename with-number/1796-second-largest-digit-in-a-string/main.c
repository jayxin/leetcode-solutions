#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 1796. 字符串中第二大的数字 - 给你一个混合字符串 s ，请你返回 s 中 第二大 的数字， 如果不存在第二大的数字，请你返回 -1 。
// 混合字符串 由小写英文字母和数字组成。
//  
// 示例 1：
// 输入：s = "dfa12321afd"
// 输出：2
// 解释：出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
// 示例 2：
// 输入：s = "abc1111"
// 输出：-1
// 解释：出现在 s 中的数字只包含 [1] 。没有第二大的数字。
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 500
//  * s 只包含小写英文字母和（或）数字。

// #v1
int secondHighest(char* s) {
  char t[10] = {0};
  int c = 0;

  while (*s) {
    if (isdigit(*s)) t[*s - '0'] = 1;
    ++s;
  }

  for (int i = 9; i >= 0; i--) {
    if (t[i]) {
      ++c;
      if (c == 2) return i;
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
  char s[100];
  read_line(s, 99, stdin);
  printf("%d\n", secondHighest(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
