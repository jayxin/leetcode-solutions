#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2390. 从字符串中移除星号 - 给你一个包含若干星号 * 的字符串 s 。
// 在一步操作中，你可以：
//  * 选中 s 中的一个星号。
//  * 移除星号 左侧 最近的那个 非星号 字符，并移除该星号自身。
// 返回移除 所有 星号之后的字符串。
// 注意：
//  * 生成的输入保证总是可以执行题面中描述的操作。
//  * 可以证明结果字符串是唯一的。
//  
// 示例 1：
// 输入：s = "leet**cod*e"
// 输出："lecoe"
// 解释：从左到右执行移除操作：
// - 距离第 1 个星号最近的字符是 "leet**cod*e" 中的 't' ，s 变为 "lee*cod*e" 。
// - 距离第 2 个星号最近的字符是 "lee*cod*e" 中的 'e' ，s 变为 "lecod*e" 。
// - 距离第 3 个星号最近的字符是 "lecod*e" 中的 'd' ，s 变为 "lecoe" 。
// 不存在其他星号，返回 "lecoe" 。
// 示例 2：
// 输入：s = "erase*****"
// 输出：""
// 解释：整个字符串都会被移除，所以返回空字符串。
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 105
//  * s 由小写英文字母和星号 * 组成
//  * s 可以执行上述操作

// #v1
char* removeStars(char* s) {
  char *h = s, *p = s;

  while (*p) {
    if (*p == '*') {
      --h;
    } else {
      *h = *p;
      ++h;
    }

    ++p;
  }

  *h = '\0';

  return s;
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
  printf("%s\n", removeStars(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
