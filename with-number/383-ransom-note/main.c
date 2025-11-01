#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 383. 赎金信 - 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
// 如果可以，返回 true ；否则返回 false 。
// magazine 中的每个字符只能在 ransomNote 中使用一次。
//  
// 示例 1：
// 输入：ransomNote = "a", magazine = "b"
// 输出：false
// 示例 2：
// 输入：ransomNote = "aa", magazine = "ab"
// 输出：false
// 示例 3：
// 输入：ransomNote = "aa", magazine = "aab"
// 输出：true
//  
// 提示：
//  * 1 <= ransomNote.length, magazine.length <= 105
//  * ransomNote 和 magazine 由小写英文字母组成

// #v1
bool canConstruct(char* ransomNote, char* magazine) {
  int c1[26] = {0}, c2[26] = {0};
  char *s;

  s = ransomNote;
  while (*s) {
    ++c1[*s - 'a'];
    ++s;
  }

  s = magazine;
  while (*s) {
    ++c2[*s - 'a'];
    ++s;
  }

  for (int i = 0; i < 26; i++) {
    if (c1[i] && c1[i] > c2[i]) return false;
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
  char s1[100], s2[100];
  read_line(s1, 98, stdin);
  read_line(s2, 98, stdin);
  if (canConstruct(s1, s2)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
