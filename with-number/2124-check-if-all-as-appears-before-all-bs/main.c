#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2124. 检查是否所有 A 都在 B 之前 - 给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。如果字符串中 每个 'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：s = "aaabbb"
// 输出：true
// 解释：
// 'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
// 因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
// 示例 2：
// 输入：s = "abab"
// 输出：false
// 解释：
// 存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
// 因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
// 示例 3：
// 输入：s = "bbb"
// 输出：true
// 解释：
// 不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * s[i] 为 'a' 或 'b'

// #v1
bool checkString(char* s) {
  int n = strlen(s), lastAPos = -1, firstBPos = -1, i;
  char *p;

  p = s + n - 1;
  i = 0;
  while (p >= s) {
    if (*p == 'a') {
      lastAPos = n - i - 1;
      break;
    }

    ++i;
    --p;
  }

  p = s;
  i = 0;
  while (*p) {
    if (*p == 'b') {
      firstBPos = i;
      break;
    }

    ++i;
    ++p;
  }

  if (firstBPos == -1 || lastAPos == -1) return true;

  return lastAPos < firstBPos;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  if (checkString(s))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
