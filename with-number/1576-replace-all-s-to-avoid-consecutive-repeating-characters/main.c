#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1576.  替换所有的问号 - 给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你 将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。
// 注意：你 不能 修改非 '?' 字符。
// 题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。
// 在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中 任何一个。可以证明，在给定的约束条件下，答案总是存在的。
//  
// 示例 1：
// 输入：s = "?zs"
// 输出："azs"
// 解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题 目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重 复的两个 'z' 。
// 示例 2：
// 输入：s = "ubv?w"
// 输出："ubvaw"
// 解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合 题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * s 仅包含小写英文字母和 '?' 字符

// #v1
char* modifyString(char* s) {
  int n = strlen(s);
  char *p = s, prev = 0, next, c;

  while (*p) {
    if (*p == '?') {
      next = *(p + 1);

      for (int i = 0; i < 26; i++) {
        c = i + 'a';
        if (c != prev && c != next) break;
      }

      *p = c;
    }

    prev = *p;
    ++p;
  }

  return s;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%s\n", modifyString(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
