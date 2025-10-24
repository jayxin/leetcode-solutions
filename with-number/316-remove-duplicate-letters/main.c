#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 316. 去除 重复字母 - 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次 。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
//  
// 示例 1：
// 输入：s = "bcabc"
// 输出："abc"
// 示例 2：
// 输入：s = "cbacdcbc"
// 输出："acdb"
//  
// 提示：
//  * 1 <= s.length <= 104
//  * s 由小写英文字母组成
//  
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters [https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters] 相同

// #v1
// 贪心, 单调栈
char* removeDuplicateLetters(char* s) {
  int cnts[26] = {0}, l = 0, top = -1, idx;
  char visited[26] = {0}, *p, *stack;

  // 计算每个字母出现的频率和字符串长度
  p = s;
  while (*p) {
    ++cnts[*p-'a'];
    ++l;
    ++p;
  }

  stack = (char *)malloc(sizeof(char) * (l + 1));

  p = s;
  while (*p) {
    idx = *p - 'a';
    if (!visited[idx]) {
      while (top != -1 && stack[top] > *p) { // 栈顶字符 > 当前字符
        if (cnts[stack[top] - 'a'] > 0) { // 字符串后面还有和 stack[top] 相同的字符
          // 标记未访问
          visited[stack[top] - 'a'] = 0;
          // pop
          --top;
        } else { // 字符串后面没有和 stack[top] 相同的字符
          break;
        }
      }

      // 标记已访问
      visited[idx] = 1;
      // push
      stack[++top] = *p;
    }

    --cnts[idx];
    ++p;
  }

  // string end
  stack[++top] = '\0';

  return stack;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%s\n", removeDuplicateLetters(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
