#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 402. 移掉 K 位数字 - 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
//  
// 示例 1 ：
// 输入：num = &quot;1432219&quot;, k = 3
// 输出：&quot;1219&quot;
// 解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
// 示例 2 ：
// 输入：num = &quot;10200&quot;, k = 1
// 输出：&quot;200&quot;
// 解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
// 示例 3 ：
// 输入：num = &quot;10&quot;, k = 2
// 输出：&quot;0&quot;
// 解释：从原数字移除所有的数字，剩余为空就是 0 。
//  
// 提示：
//  * 1 &lt;= k &lt;= num.length &lt;= 105
//  * num 仅由若干位数字（0 - 9）组成
//  * 除了 0 本身之外，num 不含任何前导零

// #v1
char* removeKdigits(char* num, int k) {
  int n = strlen(num), top = -1;
  char *stack = calloc(n+1, sizeof(char));

  while (*num) {
    while (top >= 0 && k && *num < stack[top]) { // pop 的条件
      --k;
      // pop
      --top;
    }

    // push
    stack[++top] = *num;

    // forward
    ++num;
  }

  while (k > 0) { // 可能数字是单调递增的, 那么上面就一直 push 而没有 pop, e.g. 12345
    --k;
    // pop
    --top;
  }

  // empty stack
  if (top == -1) stack[++top] = '0';

  // string end
  stack[++top] = '\0';

  // remove leading zeroes
  int i = 0;
  while (i < top && stack[i] == '0') ++i;
  if (i == top) stack[1] = '\0';
  else {
    int j = 0;

    while (i < top) {
      stack[j++] = stack[i];
      i++;
    }

    // string end
    stack[j] = '\0';
  }

  return stack;
}
// #v1

int main(int argc, char *argv[])
{
  int k;
  char s[100];
  scanf("%d\n", &k);
  scanf("%s", s);
  printf("%s\n", removeKdigits(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
