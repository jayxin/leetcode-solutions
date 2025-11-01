#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1002. 查 找共用字符 - 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
//  
// 示例 1：
// 输入：words = ["bella","label","roller"]
// 输出：["e","l","l"]
// 示例 2：
// 输入：words = ["cool","lock","cook"]
// 输出：["c","o"]
//  
// 提示：
//  * 1 <= words.length <= 100
//  * 1 <= words[i].length <= 100
//  * words[i] 由小写英文字母组成

// #v1
#define MAX_LEN 101
#define LIMIT 0x7fffffff
#define ALPHA_SIZE 26

char** commonChars(char** words, int wordsSize, int* returnSize) {
  char cnts[ALPHA_SIZE], tmp[ALPHA_SIZE], **ret;
  int i, j, retLen = 0, minLen = LIMIT;

  // init
  for (i = 0; i < ALPHA_SIZE; i++) cnts[i] = MAX_LEN;

  // count
  for (i = 0; i < wordsSize; i++) {
    char *s = words[i];
    int len = 0;

    memset(tmp, 0, sizeof(tmp));

    while (*s) {
      ++tmp[*s++ - 'a'];
      ++len;
    }

    for (j = 0; j < ALPHA_SIZE; j++) {
      if (tmp[j] < cnts[j]) cnts[j] = tmp[j];
    }

    // 记录 words[i] 的最小长度, 用于分配返回值的空间
    if (len < minLen) minLen = len;
  }

  // allocate
  ret = calloc(minLen, sizeof(char *));
  for (i = 0; i < minLen; i++) {
    ret[i] = calloc(2, sizeof(char));
    ret[i][1] = '\0';
  }

  for (i = 0; i < ALPHA_SIZE; i++) {
    for (j = 0; j < cnts[i]; j++) {
      ret[retLen++][0] = i + 'a';
    }
  }

  *returnSize = retLen;

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
  int n, s;
  char **words, **ret;
  scanf("%d\n", &n);
  words = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  ret = commonChars(words, n, &s);
  for (int i = 0; i < s; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
