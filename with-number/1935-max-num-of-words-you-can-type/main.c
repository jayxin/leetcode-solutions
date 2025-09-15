#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1935. 可以输入的最大单词数 - 键盘出现了一些故障，有些字母键无法正常工作。而键盘上 所有其他键都能够正常工作。
// 给你一个由若干单词组成的字符串 text ，单词间由单个空格组成（不含前导和尾随空格） ；另有一个字符串 brokenLetters ，由所有已损坏的不同字母键组成，返回你可以使用此键盘完全输入的 text 中单词的数目。
//  
// 示例 1：
// 输入：text = "hello world", brokenLetters = "ad"
// 输出：1
// 解释：无法输入 "world" ，因为字母键 'd' 已损坏。
// 示例 2：
// 输入：text = "leet code", brokenLetters = "lt"
// 输出：1
// 解释：无法输入 "leet" ，因为字母键 'l' 和 't' 已损 坏。
// 示例 3：
// 输入：text = "leet code", brokenLetters = "e"
// 输出：0
// 解释：无法输入任何单词，因为字母键 'e' 已损坏。
//  
// 提示：
//  * 1 &lt;= text.length &lt;= 104
//  * 0 &lt;= brokenLetters.length &lt;= 26
//  * text 由若干用单个空格分隔的单词组成，且不含任何前导和尾随空格
//  * 每个单词仅由小写英文字母组成
//  * brokenLetters 由 互不相同 的小写英文字母组成

// #v1
int canBeTypedWords(char* text, char* brokenLetters) {
  int64_t set = 0;
  int ret = 0, st;
  char *p;
  bool f;

  // 遍历损坏的字母, 添加到 bitmap
  p = brokenLetters;
  while (*p) {
    set |= 1LL << ((*p) & 0x3f);
    ++p;
  }

  // 遍历文本
  p = text;
  while (*p) {
    // 跳过空格
    while (*p == ' ') ++p;

    // 处理每个单词
    f = true;
    while (*p != ' ' && *p) { // 匹配完整单词
      if (f) {
        st = (set >> ((*p) & 0x3f)) & 1;
        if (st) f = false;
      }

      ++p;
    }
    // 单词中不存在损坏的字母
    if (f) ++ret;
  }

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
  char s[100], t[100];
  read_line(s, 99, stdin);
  read_line(t, 99, stdin);
  printf("%d\n", canBeTypedWords(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
