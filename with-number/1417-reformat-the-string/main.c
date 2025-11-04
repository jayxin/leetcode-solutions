#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1417. 重新格式化字符串 - 给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字 母。
// 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应 该跟着数字，而数字后面应该跟着字母。
// 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。
//  
// 示例 1：
// 输入：s = "a0b1c2"
// 输出："0a1b2c"
// 解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
// 示例 2：
// 输入：s = "leetcode"
// 输出：""
// 解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
// 示例 3：
// 输入：s = "1229857369"
// 输出：""
// 解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
// 示例 4：
// 输入：s = "covid2019"
// 输出："c2o0v1i9d"
// 示例 5：
// 输入：s = "ab123"
// 输出："1a2b3"
//  
// 提示：
//  * 1 <= s.length <= 500
//  * s 仅由小写英文字母和/或数字组成。

// #v1
int abs(int x) { return x >= 0 ? x : -x; }

char* reformat(char* s) {
  int numCnt, letterCnt, len, i, j, k;
  char *ret, *num, *letter, *p;

  // count
  p = s;
  numCnt = letterCnt = 0;
  while (*p) {
    // letter
    if (*p & 0x40) ++letterCnt;
    // number
    else ++numCnt;

    ++p;
  }

  // invalid
  if (abs(letterCnt - numCnt) > 1) return "";

  // allocate
  len = numCnt + letterCnt;
  ret = calloc(len+1, sizeof(char));
  ret[len] = '\0';
  num = calloc(numCnt, sizeof(char));
  letter = calloc(letterCnt, sizeof(char));

  p = s;
  i = j = 0;
  while (*p) {
    if (*p & 0x40) letter[i++] = *p;
    else num[j++] = *p;

    ++p;
  }

  i = j = k = 0;
  if (numCnt >= letterCnt) {
    while (k < len) {
      if (k & 1) ret[k] = letter[i++];
      else ret[k] = num[j++];

      ++k;
    }
  } else {
    while (k < len) {
      if (k & 1) ret[k] = num[i++];
      else ret[k] = letter[j++];

      ++k;
    }
  }

  free(num);
  free(letter);

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
  read_line(s, 98, stdin);
  printf("%s\n", reformat(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
