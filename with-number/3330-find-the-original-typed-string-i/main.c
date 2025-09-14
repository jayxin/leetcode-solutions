#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3330. 找到初始输入字符串 I - Alice 正在她的电脑上输入一个字符串。但是她打字技术比 较笨拙，她 可能 在一个按键上按太久，导致一个字符被输入 多次 。
// 尽管 Alice 尽可能集中注意力，她仍然可能会犯错 至多 一次。
// 给你一个字符串 word ，它表示 最终 显示在 Alice 显示屏上的结果。
// 请你返回 Alice 一开始可能想要输入字符串的总方案数。
//  
// 示例 1：
// 输入：word = "abbcccc"
// 输出：5
// 解释：
// 可能的字符串包括："abbcccc" ，"abbccc" ，"abbcc" ，"abbc" 和 "abcccc" 。
// 示例 2：
// 输入：word = "abcd"
// 输出：1
// 解释：
// 唯一可能的字符串是 "abcd" 。
// 示例 3：
// 输入：word = "aaaa"
// 输出：4
//  
// 提示：
//  * 1 <= word.length <= 100
//  * word 只包含小写英文字母。

// #v1
int possibleStringCount(char* word) {
  ++word;

  if (*word == '\0') return 1;

  int ret = 1, cnt = 0; // 至少一种

  while (*word) {
    if (*word == *(word - 1)) {
      ++cnt;
    } else {
      ret += cnt;
      cnt = 0;
    }

    ++word;
  }
  ret += cnt;

  return ret;
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
  printf("%d\n", possibleStringCount(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
