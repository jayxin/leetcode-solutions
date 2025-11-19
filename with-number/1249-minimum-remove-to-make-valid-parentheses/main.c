#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1249.  移除无效的括号 - 给你一个由 '('、')' 和小写字母组成的字符串 s。
// 你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位 置的括号)，使得剩下的「括号字符串」有效。
// 请返回任意一个合法字符串。
// 有效「括号字符串」应当符合以下 任意一条 要求：
//  * 空字符串或只包含小写字母的字符串
//  * 可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
//  * 可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
//  
// 示例 1：
// 输入：s = "lee(t(c)o)de)"
// 输出："lee(t(c)o)de"
// 解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
// 示例 2：
// 输入：s = "a)b(c)d"
// 输出："ab(c)d"
// 示例 3：
// 输入：s = "))(("
// 输出：""
// 解释：空字符串也是有效的
//  
// 提示：
//  * 1 <= s.length <= 105
//  * s[i] 可能是 '('、')' 或英文小写字母
// 1. Each prefix of a balanced parentheses has a number of open parentheses
// greater or equal than closed parentheses, similar idea with each suffix.
// 2. Check the array from left to right, remove characters that do not meet the
// property mentioned above, same idea in backward way.

// #v1
// count, stack
char* minRemoveToMakeValid(char* s) {
  // left_cnt 左括号的数量, right_cnt 右括号的数量, matched_cnt 匹配的括号数量
  int n = strlen(s), left_cnt, right_cnt, matched_cnt, retLen;
  char *ret = malloc(sizeof(char) * (n+1)), *p;

  left_cnt = right_cnt = matched_cnt = 0;
  p = s;
  while (*p) {
    switch (*p++) {
      case '(':
        ++left_cnt;
        break;
      case ')':
        if (left_cnt >= right_cnt+1) { // 匹配条件
          ++matched_cnt; // 新增可匹配的括号对
          ++right_cnt;
        }
        break;
    }
  }

  retLen = 0;
  left_cnt = right_cnt = 0;
  p = s;
  while (*p) {
    switch (*p) {
      case '(':
        if (left_cnt+1 <= matched_cnt) { // 只保留必要的左括号
          ret[retLen++] = *p;
          ++left_cnt;
        }
        break;
      case ')':
        // 只保留必要的右括号且右括号满足和左括号的匹配
        if (right_cnt+1 <= matched_cnt && left_cnt >= right_cnt+1) {
          ret[retLen++] = *p;
          ++right_cnt;
        }
        break;
      default:
        // 非括号字符
        ret[retLen++] = *p;
    }
    ++p;
  }

  // string end
  ret[retLen] = '\0';

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%s\n", minRemoveToMakeValid(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
