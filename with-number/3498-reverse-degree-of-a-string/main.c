#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3498.  字符串的反转度 - 给你一个字符串 s，计算其 反转度。
// 反转度的计算方法如下：
//  1. 对于每个字符，将其在 反转 字母表中的位置（'a' = 26, 'b' = 25, ..., 'z' = 1）与其在字符串中的位置（下标从1 开始）相乘。
//  2. 将这些乘积加起来，得到字符串中所有字符的和。
// 返回 反转度。
//  
// 示例 1：
// 输入： s = &quot;abc&quot;
// 输出： 148
// 解释：
// 字母 反转字母表中的位置 字符串中的位置 乘积 'a' 26 1 26 'b' 25 2 50 'c' 24 3 72
// 反转度是 26 + 50 + 72 = 148 。
// 示例 2：
// 输入： s = &quot;zaza&quot;
// 输出： 160
// 解释：
// 字母 反转字母表中的位置 字符串中的位置 乘积 'z' 1 1 1 'a' 26 2 52 'z' 1 3 3 'a' 26 4 104
// 反转度是 1 + 52 + 3 + 104 = 160 。
//  
// 提示：
//  * 1 <= s.length <= 1000
//  * s 仅包含小写字母。

// #v1
int reverseDegree(char* s) {
  int i = 1, ret = 0;

  while (*s) {
    ret += i * (26 - (*s - 'a'));
    ++i;
    ++s;
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
  printf("%d\n", reverseDegree(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
