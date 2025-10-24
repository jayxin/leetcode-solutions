#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1081. 不同字符的最小子序列 - 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同 字符，且只包含一次。
//  
// 示例 1：
// 输入：s = "bcabc"
// 输出："abc"
// 示例 2：
// 输入：s = "cbacdcbc"
// 输出："acdb"
//  
// 提示：
//  * 1 <= s.length <= 1000
//  * s 由小写英文字母组成
//  
// 注意：该题与 316 https://leetcode.cn/problems/remove-duplicate-letters/ [https://leetcode.cn/problems/remove-duplicate-letters/] 相同

// #v1
char* smallestSubsequence(char* s) {
  int cnts[26] = {0}, idx, len = 0, top = -1;
  char *p = s, *stack, visited[26] = {0};

  // 统计字符出现频率和字符串长度
  while (*p) {
    cnts[*p - 'a']++;
    ++len;
    ++p;
  }

  // allocate
  stack = (char *)malloc(sizeof(char) * (len + 1));

  p = s;
  while (*p) {
    idx = *p - 'a';

    if (!visited[idx]) {
      while (top >= 0 && stack[top] > *p) { // 栈顶字符 > 当前字符
        if (cnts[stack[top] - 'a'] > 0) { // 字符串后面还有字符和 stack[top] 一样
          // un-mark
          visited[stack[top] - 'a'] = 0;
          // pop
          --top;
        } else { // 字符串后面没有和 stack[top] 一样的字符, 不能弹栈
          break;
        }
      }

      // mark
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
  printf("%s\n", smallestSubsequence(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
