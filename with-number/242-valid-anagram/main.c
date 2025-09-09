#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 242.  有效的字母异位词 - 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母 异位词。
//  
// 示例 1:
// 输入: s = "anagram", t = "nagaram"
// 输出: true
// 示例 2:
// 输入: s = "rat", t = "car"
// 输出: false
//  
// 提示:
//  * 1 &lt;= s.length, t.length &lt;= 5 * 104
//  * s 和 t 仅包含小写字母
//  
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

// #v1
bool isAnagram(char* s, char* t) {
  int st[26], tt[26], i;
  memset(st, 0, sizeof(int) * 26);
  memset(tt, 0, sizeof(int) * 26);
  while (*s) {
    st[*s - 'a']++;
    s++;
  }
  while (*t) {
    tt[*t - 'a']++;
    t++;
  }
  for (i = 0; i < 26; i++) {
    if (st[i] != tt[i]) return false;
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
  char s[100], t[100];
  read_line(s, 99, stdin);
  read_line(t, 99, stdin);
  if (isAnagram(s, t)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
