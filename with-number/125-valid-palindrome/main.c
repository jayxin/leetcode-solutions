#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 125. 验证回 文串 - 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
// 字母和数字都属于字母数字字符。
// 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入: s = "A man, a plan, a canal: Panama"
// 输出：true
// 解释："amanaplanacanalpanama" 是回文串。
// 示例 2：
// 输入：s = "race a car"
// 输出：false
// 解释："raceacar" 不是回文串。
// 示例 3：
// 输入：s = " "
// 输出：true
// 解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
// 由于空字符串正着反着读都一样，所以是回文串。
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 2 * 105
//  * s 仅由可打印的 ASCII 字符组成

// #v1
bool isPalindrome(char* s) {
  int len = 0;
  char *p, *q, *e;

  p = s;
  while (*p) {
    ++len;
    ++p;
  }

  p = s;
  q = s + len - 1;
  e = s + len;

  while (p < q) {
    while (p < e && !isalnum(*p)) ++p;
    while (q > s && !isalnum(*q)) --q;

    if (p < q) {
      if (isdigit(*p)) {
        if (*p != *q) return false;
      } else {
        if (tolower(*p) != tolower(*q)) return false;
      }

      ++p;
      --q;
    }
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
  read_line(s, 99, stdin);
  if (isPalindrome(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
