#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2283. 判断一个数的数字计数是否等于数位的值 - 给你一个下标从 0 开始长度为 n 的字符串 num ，它只包含数字。
// 如果对于 每个 0 &lt;= i &lt; n 的下标 i ，都满足数位 i 在 num 中出现了 num[i]次，那么请你返回 true ，否则返回 false 。
//  
// 示例 1：
// 输入：num = "1210"
// 输出：true
// 解释：
// num[0] = '1' 。数字 0 在 num 中出现了一次。
// num[1] = '2' 。数字 1 在 num 中出现了两次。
// num[2] = '1' 。数字 2 在 num 中出现了一次。
// num[3] = '0' 。数字 3 在 num 中出现了零次。
// "1210" 满足题目要求条件，所以返回 true 。
// 示例 2：
// 输入：num = "030"
// 输出：false
// 解释：
// num[0] = '0' 。数字 0 应该出现 0 次，但是在 num 中出现了两次。
// num[1] = '3' 。数字 1 应该出现 3 次，但是在 num 中出现了零次。
// num[2] = '0' 。数字 2 在 num 中出现了 0 次。
// 下标 0 和 1 都违反了题目要求，所以返回 false 。
//  
// 提示：
//  * n == num.length
//  * 1 &lt;= n &lt;= 10
//  * num 只包含数字。

// #v1
bool digitCount(char* num) {
  char t[10] = {0}, *s;
  int i = 0;

  s = num;
  while (*s) ++t[*s++ - '0'];

  while(*num) {
    if ((*num++)-'0' != t[i++]) return false;
  }

  return true;
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
  read_line(s, 98, stdin);
  if (digitCount(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
