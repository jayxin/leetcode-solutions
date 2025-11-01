#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2839. 判断通过操作能否让字符串相等 I - 给你两个字符串 s1 和 s2 ，两个字 符串的长度都为 4 ，且只包含 小写 英文字母。
// 你可以对两个字符串中的 任意一个 执行以下操作 任意 次：
//  * 选择两个下标 i 和 j 且满足 j - i = 2 ，然后 交换 这个字符串中两个下标对应的字 符。
// 如果你可以让字符串 s1 和 s2 相等，那么返回 true ，否则返回 false 。
//  
// 示例 1：
// 输入：s1 = "abcd", s2 = "cdab"
// 输出：true
// 解释： 我们可以对 s1 执行以下操作：
// - 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbad" 。
// - 选择下标 i = 1 ，j = 3 ，得到字符串 s1 = "cdab" = s2 。
// 示例 2：
// 输入：s1 = "abcd", s2 = "dacb"
// 输出：false
// 解释：无法让两个字符串相等。
//  
// 提示：
//  * s1.length == s2.length == 4
//  * s1 和 s2 只包含小写英文字母。

//// #v1
//void swap(char *a, int i, int j) {
  //char tmp = a[i];
  //a[i] = a[j];
  //a[j] = tmp;
//}
//
//bool canBeEqual(char* s1, char* s2) {
  //int i, j;
//
  //i = 0, j = i + 2;
  //if (s1[i] != s2[i] || s1[j] != s2[j]) {
    //swap(s1, i, j);
  //}
  //if (s1[i] != s2[i] || s1[j] != s2[j]) return false;
//
  //i = 1, j = i + 2;
  //if (s1[i] != s2[i] || s1[j] != s2[j]) {
    //swap(s1, i, j);
  //}
  //if (s1[i] != s2[i] || s1[j] != s2[j]) return false;
//
  //return true;
//}
//// #v1

// #v2
void swap(char *a, int i, int j) {
  char tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

bool canBeEqual(char* s1, char* s2) {
  int i, j;

  for (i = 0; i <= 1; i++) {
    j = i + 2;
    if (s1[i] != s2[i] || s1[j] != s2[j]) swap(s1, i, j);
    if (s1[i] != s2[i] || s1[j] != s2[j]) return false;
  }

  return true;
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
  char s1[10], s2[10];
  read_line(s1, 98, stdin);
  read_line(s2, 98, stdin);
  if (canBeEqual(s1, s2)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
