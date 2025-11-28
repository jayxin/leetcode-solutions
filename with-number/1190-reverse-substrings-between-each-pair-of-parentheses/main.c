#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1190. 反转每对括号间的子串 - 给出一个字符串 s（仅含有小写英文字母和括号）。
// 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
// 注意，您的结果中 不应 包含任何括号。
//  
// 示例 1：
// 输入：s = "(abcd)"
// 输出："dcba"
// 示例 2：
// 输入：s = "(u(love)i)"
// 输出："iloveu"
// 解释：先反转子字符串 "love" ，然后反转整个字符串。
// 示例 3：
// 输入：s = "(ed(et(oc))el)"
// 输出："leetcode"
// 解释：先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字 符串。
//  
// 提示：
//  * 1 <= s.length <= 2000
//  * s 中只有小写英文字母和括号
//  * 题目测试用例确保所有括号都是成对出现的

// #v1
// reverse [*s...*e]
void reverse(char *s, char *e) {
  char c;
  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;
    ++s;
    --e;
  }
}

char* reverseParentheses(char* s) {
  int n, *idx, idxLen, top;
  char *p, *stack;

  // compute length of s
  n = 0;
  p = s;
  while (*p) {
    ++n;
    ++p;
  }

  // allocate
  stack = (char *)malloc(sizeof(char) * (n + 1));
  idx = (int *)malloc(sizeof(int) * n);
  idxLen = 0;

  p = s;
  top = -1;
  while (*p) {
    if (*p == '(') {
      // record start index of substring
      idx[idxLen++] = top + 1;
    } else if (*p == ')') {
      // reverse substring
      --idxLen;
      reverse(stack + idx[idxLen], stack + top);
    } else {
      // push
      stack[++top] = *p;
    }

    ++p;
  }

  // string end
  stack[++top] = '\0';

  free(idx);

  return stack;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%s\n", reverseParentheses(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
