#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3083. 字符串及其反转中是否存在同一子字符串 - 给你一个字符串 s ，请你判断字符串 s 是否存在一个长度为 2 的子字符串，在 s 反转后的字符串中也出现。
// 如果存在这样的子字符串，返回 true；如果不存在，返回 false 。
//  
// 示例 1：
// 输入：s = "leetcode"
// 输出：true
// 解释：子字符串 "ee" 的长度为 2，它也出现在 reverse(s) == "edocteel" 中。
// 示例 2：
// 输入：s = "abcba"
// 输出：true
// 解释：所有长度为 2 的子字符串 "ab"、"bc"、"cb"、"ba" 也都出现在 reverse(s) == "abcba" 中。
// 示例 3：
// 输入：s = "abcd"
// 输出：false
// 解释：字符串 s 中不存在满足「在其反转后的字符串中也出现」且长度为 2 的子字符串。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * 字符串 s 仅由小写英文字母组成。

// #v1
bool isSubstringPresent(char* s) {
  int n = strlen(s);
  char t[n+1];

  sprintf(t, "%s", s);
  for (int i = 0; i < n/2; i++) {
    char tmp = t[i];
    t[i] = t[n-i-1];
    t[n-i-1] = tmp;
  }

  while (*s) {
    for (int i = 0; i < n-1; i++) {
      if (s[0] == t[i] && s[1] == t[i+1]) return true;
    }
    ++s;
  }

  return false;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  if (isSubstringPresent(s))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
