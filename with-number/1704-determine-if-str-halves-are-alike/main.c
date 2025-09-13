#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1704. 判断字符串的两半是否相似 - 给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。
// 两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s 可能同时含有大写和小写字母。
// 如果 a 和 b 相似，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：s = "book"
// 输出：true
// 解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
// 示例 2：
// 输入：s = "textbook"
// 输出：false
// 解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
// 注意，元音 o 在 b 中出现两次，记为 2 个。
//  
// 提示：
//  * 2 &lt;= s.length &lt;= 1000
//  * s.length 是偶数
//  * s 由 大写和小写 字母组成

// #v1
int64_t std, v;

// 判断字母 c 是否为元音字母
bool isVowel(char c) {
  v = 0LL;
  v |= 1LL << (c & 0x3f);
  return (v & std);
}

bool halvesAreAlike(char* s) {
  int a = 0, b = 0, len = 0, i;
  char *p, vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  // init std
  for (i = 0; i < 10; i++) {
    std |= 1LL << (vowels[i] & 0x3f);
  }

  p = s;
  while (*p) {
    if (isVowel(*p)) ++b;
    ++len;
    ++p;
  }

  p = s;
  i = 0;
  len >>= 1;
  while (i < len) {
    if (isVowel(*p)) ++a;
    ++i;
    ++p;
  }

  b = b - a;

  return a == b;
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
  if (halvesAreAlike(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
