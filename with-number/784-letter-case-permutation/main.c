#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 784.  字母大小写全排列 - 给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。
// 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
//  
// 示例 1：
// 输入：s = "a1b2"
// 输出：["a1b2", "a1B2", "A1b2", "A1B2"]
// 示例 2:
// 输入: s = "3z4"
// 输出: ["3z4","3Z4"]
//  
// 提示:
//  * 1 <= s.length <= 12
//  * s 由小写英文字母、大写英文字母和数字组成

// #v1
int len, retLen;
char **ret;

void generate(char *s, char *t, int l) {
  if (*s == '\0') {
    strcpy(ret[retLen], t);
    retLen++;
    return ;
  }

  if (isdigit(*s)) {
    t[l++] = *s++;
    generate(s, t, l);
  } else {
    t[l] = *s;
    generate(s + 1, t, l + 1);

    if (islower(*s)) t[l] = toupper(*s);
    else t[l] = tolower(*s);
    generate(s + 1, t, l + 1);
  }
}

char** letterCasePermutation(char* s, int* returnSize) {
  int alphaCnt, n;
  char *p, *t;

  p = s;
  len = alphaCnt = 0;
  while (*p) {
    if (isalpha(*p)) ++alphaCnt;
    ++len;
    ++p;
  }
  n = 1 << alphaCnt;
  *returnSize = n;

  t = (char *)malloc(sizeof(char) * (len + 1));
  t[len] = '\0';
  ret = (char **)malloc(sizeof(char *) * n);
  retLen = 0;
  for (int i = 0; i < n; i++) {
    ret[i] = (char *)malloc(sizeof(char) * (len + 1));
  }

  generate(s, t, 0);

  free(t);

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
  char s[100], **ret;
  int n;
  read_line(s, 99, stdin);
  ret = letterCasePermutation(s, &n);
  for (int i = 0; i < n; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
