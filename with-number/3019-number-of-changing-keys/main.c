#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3019.  按键变更的次数 - 给你一个下标从 0 开始的字符串 s ，该字符串由用户输入。按键变更的定义是：使用与上次使用的按键不同的键。例如 s = "ab" 表示按键变更一次， 而 s = "bBBb" 不存在按键变更。
// 返回用户输入过程中按键变更的次数。
// 注意：shift 或 caps lock 等修饰键不计入按键变更，也就是说，如果用户先输入字母 'a' 然后输入字母 'A' ，不算作按键变更。
//  
// 示例 1：
// 输入：s = "aAbBcC"
// 输出：2
// 解释：
// 从 s[0] = 'a' 到 s[1] = 'A'，不存在按键变更，因为不计入 caps lock 或 shift 。
// 从 s[1] = 'A' 到 s[2] = 'b'，按键变更。
// 从 s[2] = 'b' 到 s[3] = 'B'，不存在按键变更，因为不计入 caps lock 或 shift 。
// 从 s[3] = 'B' 到 s[4] = 'c'，按键变更。
// 从 s[4] = 'c' 到 s[5] = 'C'，不存在按键变更，因为不计入 caps lock 或 shift 。
// 示例 2：
// 输入：s = "AaAaAaaA"
// 输出：0
// 解释： 不存在按键变更，因为这个过程中只按下字母 'a' 和 'A' ，不需要进行按键变更。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * s 仅由英文大写字母和小写字母组成。

//// #v1
//int countKeyChanges(char* s) {
  //char c = *s++;
  //int cnt = 0;
//
  //// to upper if c is lower case
  //if (c & 0x20) c &= ~0x20;
//
  //while (*s) {
    //if (*s & 0x20) { // lower case
      //// to upper
      //*s &= ~0x20;
    //}
//
    //if (*s != c) {
      //// update counter
      //++cnt;
      //// update previous char
      //c = *s;
    //}
//
    //++s;
  //}
//
//
  //return cnt;
//}
//// #v1

// #v2
int countKeyChanges(char* s) {
  char c = *s++;
  int cnt = 0;

  // to lower
  c |= 0x20;

  while (*s) {
    // to lower
    *s |= 0x20;

    if (*s != c) {
      // update counter
      ++cnt;
      // update previous char
      c = *s;
    }

    ++s;
  }


  return cnt;
}
// #v2

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
  printf("%d\n", countKeyChanges(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
