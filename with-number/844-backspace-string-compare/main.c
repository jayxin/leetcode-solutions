#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 844. 比较含退格的字符串 - 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器 后，如果两者相等，返回 true 。# 代表退格字符。
// 注意：如果对空文本输入退格字符，文本继续为空。
//  
// 示例 1：
// 输入：s = "ab#c", t = "ad#c"
// 输出：true
// 解释：s 和 t 都会变成 "ac"。
// 示例 2：
// 输入：s = "ab##", t = "c#d#"
// 输出：true
// 解释：s 和 t 都会变成 ""。
// 示例 3：
// 输入：s = "a#c", t = "b"
// 输出：false
// 解释：s 会变成 "c"，但 t 仍然是 "b"。
//  
// 提示：
//  * 1 <= s.length, t.length <= 200
//  * s 和 t 只含有小写字母以及字符 '#'
//  
// 进阶：
//  * 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？

// #v1
bool backspaceCompare(char* s, char* t) {
  char *p1, *p2, *top1, *top2;

  p1 = top1 = s;
  while (*p1) {
    if (*p1 != '#') {
      *top1 = *p1;
      ++top1;
    } else if (top1 > s) {
      --top1;
    }

    ++p1;
  }
  *top1 = '\0';

  p2 = top2 = t;
  while (*p2) {
    if (*p2 != '#') {
      *top2 = *p2;
      ++top2;
    } else if (top2 > t) {
      --top2;
    }

    ++p2;
  }
  *top2 = '\0';

  p1 = s;
  p2 = t;
  while (*p1 && *p2) {
    if (*p1 != *p2) return false;
    ++p1;
    ++p2;
  }

  return *p1 == '\0' && *p2 == '\0';
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
  char s[100], t[100];
  read_line(s, 98, stdin);
  read_line(t, 98, stdin);
  if (backspaceCompare(s, t))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
