#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1784. 检查二进制字符串字段 - 给你一个二进制字符串 s ，该字符串 不含前导零 。
// 如果 s 包含 零个或一个由连续的 '1' 组成的字段 ，返回 true 。否则，返回 false 。
//  
// 示例 1：
// 输入：s = "1001"
// 输出：false
// 解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
// 示例 2：
// 输入：s = "110"
// 输出：true
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 100
//  * s[i] 为 '0' 或 '1'
//  * s[0] 为 '1'

// #v1
bool checkOnesSegment(char* s) {
  int cnt = 0;
  char *p = s;
  bool f = false;

  while (*p) {
    if (*p == '1') {
      f = true;
    } else {
      if (f) {
        f = false;
        ++cnt;
      }
    }
    ++p;
  }

  if (f) ++cnt;

  return cnt == 0 || cnt == 1;
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
  char s[100];
  read_line(s, 99, stdin);
  if (checkOnesSegment(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
