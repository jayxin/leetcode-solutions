#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1209. 删除字符串中的所有相邻重复项 II - 给你一个字符串 s，「k 倍重复项 删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左 侧和右侧连在一起。
// 你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。
// 在执行完所有删除操作后，返回最终得到的字符串。
// 本题答案保证唯一。
//  
// 示例 1：
// 输入：s = "abcd", k = 2
// 输出："abcd"
// 解释：没有要删除的内容。
// 示例 2：
// 输入：s = "deeedbbcccbdaa", k = 3
// 输出："aa"
// 解释：
// 先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
// 再删除 "bbb"，得到 "dddaa"
// 最后删除 "ddd"，得到 "aa"
// 示例 3：
// 输入：s = "pbbcggttciiippooaais", k = 2
// 输出："ps"
//  
// 提示：
//  * 1 <= s.length <= 10^5
//  * 2 <= k <= 10^4
//  * s 中只含有小写英文字母。

// #v1
char* removeDuplicates(char* s, int k) {
  int n = strlen(s), top = -1, c = 0;
  char *stack = calloc(1 + n, sizeof(char)), *p = s;

  while (*p) {
    if (top >= 0) {
      // update counter
      c = (stack[top] == *p) ? c + 1 : 1;

      // push
      stack[++top] = *p;

      if (c == k) {
        // pop
        top -= k;

        int t = top;

        // update counter
        c = 0;
        while (t >= 0 && stack[top] == stack[t]) {
          --t;
          ++c;
        }
      }
    } else {
      // push
      stack[++top] = *p;
      // update counter
      c = 1;
    }

    // forward
    ++p;
  }

  // string end
  stack[++top] = '\0';

  return stack;
}
// #v1

int main(int argc, char *argv[])
{
  int k;
  char s[100];
  scanf("%d\n", &k);
  scanf("%s", s);
  printf("%s\n", removeDuplicates(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
