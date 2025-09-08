#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 520. 检测 大写字母 - 我们定义，在以下情况时，单词的大写用法是正确的：
//  * 全部字母都是大写，比如 "USA" 。
//  * 所有字母都不是大写，比如 "leetcode" 。
//  * 只有首字母大写， 比如 "Google" 。
// 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：word = "USA"
// 输出：true
// 示例 2：
// 输入：word = "FlaG"
// 输出：false
//  
// 提示：
//  * 1 &lt;= word.length &lt;= 100
//  * word 由小写和大写英文字母组成

// #v1
bool detectCapitalUse(char* word) {
  int len = 0, upperCnt = 0, isFirstLetterUpper = 0;
  if (isupper(*word)) {
    upperCnt++;
    isFirstLetterUpper = 1;
  }
  word++;
  len++;
  while (*word) {
    if (isupper(*word)) upperCnt++;
    len++;
    word++;
  }
  if ((upperCnt == len) || (isFirstLetterUpper && upperCnt == 1) || (upperCnt == 0))
    return true;
  return false;
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
  char s[1000];
  read_line(s, 999, stdin);
  if (detectCapitalUse(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
