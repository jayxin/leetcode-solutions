#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2496. 数组中字符串的最大值 - 一个由字母和数字组成的字符串的 值 定义如下：
//  * 如果字符串 只 包含数字，那么值为该字符串在 10 进制下的所表示的数字。
//  * 否则，值为字符串的 长度 。
// 给你一个字符串数组 strs ，每个字符串都只由字母和数字组成，请你返回 strs 中字符串 的 最大值 。
//  
// 示例 1：
// 输入：strs = ["alic3","bob","3","4","00000"]
// 输出：5
// 解释：
// - "alic3" 包含字母和数字，所以值为长度 5 。
// - "bob" 只包含字母，所以值为长度 3 。
// - "3" 只包含数字，所以值为 3 。
// - "4" 只包含数字，所以值为 4 。
// - "00000" 只包含数字，所以值为 0 。
// 所以最大的值为 5 ，是字符串 "alic3" 的值。
// 示例 2：
// 输入：strs = ["1","01","001","0001"]
// 输出：1
// 解释：
// 数组中所有字符串的值都是 1 ，所以我们返回 1 。
//  
// 提示：
//  * 1 <= strs.length <= 100
//  * 1 <= strs[i].length <= 9
//  * strs[i] 只包含小写英文字母和数字。

// #v1
int maximumValue(char** strs, int strsSize) {
  int ret = -1;

  for (int i = 0; i < strsSize; i++) {
    char *s = strs[i], haveAlpha = 0;
    int v = 0, len = 0;

    while (*s) {
      if (*s & 0x40) {
        haveAlpha = 1;
      } else if (!haveAlpha) {
        v = v * 10 + *s - '0';
      }

      ++len;
      ++s;
    }

    if (haveAlpha) {
      if (len > ret) ret = len;
    } else {
      if (v > ret) ret = v;
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
  int n;
  char **s;
  scanf("%d\n", &n);
  s = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    s[i] = calloc(100, sizeof(char));
    read_line(s[i], 98, stdin);
  }
  printf("%d\n", maximumValue(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
