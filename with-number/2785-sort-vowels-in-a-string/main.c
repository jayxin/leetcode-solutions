#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2785. 将字符串中的元音字母排序 - 给你一个下标从 0 开始的字符串 s ，将 s 中的元素重新 排列 得到新的字符串 t ，它满足：
//  * 所有辅音字母都在原来的位置上。更正式的，如果满足 0 <= i < s.length 的下 标 i 处的 s[i] 是个辅音字母，那么 t[i] = s[i] 。
//  * 元音字母都必须以他们的 ASCII 值按 非递减 顺序排列。更正式的，对于满足 0 <= i < j < s.length 的下标 i 和 j  ，如果 s[i] 和 s[j] 都是元音字母，那么 t[i] 的 ASCII 值不能大于 t[j] 的 ASCII 值。
// 请你返回结果字母串。
// 元音字母为 'a' ，'e' ，'i' ，'o' 和 'u' ，它们可能是小写字母也可能是大写字母，辅音字母是除了这 5 个字母以外的所 有字母。
//  
// 示例 1：
// 输入：s = "lEetcOde"
// 输出："lEOtcede"
// 解释：'E' ，'O' 和 'e' 是 s 中的元音字母，'l' ，'t' ，'c' 和 'd' 是所有的辅音。将元音字母按 照 ASCII 值排序，辅音字母留在原地。
// 示例 2：
// 输入：s = "lYmpH"
// 输出："lYmpH"
// 解释：s 中没有元音字母（s 中都为辅音字母），所以我们返回 "lYmpH" 。
//  
// 提示：
//  * 1 <= s.length <= 10^5
//  * s 只包含英语字母表中的 大写 和 小写 字母。

// #v1
char* sortVowels(char* s) {
  char tab[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}, *p = s;
  int cnts[10] = {0}, i;

  while (*p) {
    for (i = 0; i < 10; i++) {
      if (*p == tab[i]) {
        ++cnts[i];
        *p = '*';
        break;
      }
    }
    p++;
  }

  p = s;
  for (i = 0; i < 10; i++) {
    while (cnts[i]) {
      if (*p == '*') {
        *p = tab[i];
        cnts[i]--;
      }
      p++;
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
  char s[100];
  read_line(s, 99, stdin);
  printf("%s\n", sortVowels(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
