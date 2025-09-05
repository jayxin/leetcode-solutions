#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 14. 最长公 共前缀 - 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
//  
// 示例 1：
// 输入：strs = ["flower","flow","flight"]
// 输出："fl"
// 示例 2：
// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。
//  
// 提示：
//  * 1 <= strs.length <= 200
//  * 0 <= strs[i].length <= 200
//  * strs[i] 如果非空，则仅由小写英文字母组成

// #v1
char* longestCommonPrefix(char** strs, int strsSize) {
  if (!strsSize) return NULL;
  char p, c, *ret, retLen = 0;
  int pos = 0, i;
  ret = (char *)malloc(sizeof(char) * 201);

  while (1) {
    c = strs[0][pos];
    if (c == '\0') break;
    int isEnd = 0;

    for (i = 1; i < strsSize; i++) {
      p = strs[i][pos];
      if (p == '\0' || c != p) {
        isEnd = 1;
        break;
      }
    }

    if (isEnd) {
      break;
    }

    ret[retLen++] = c;
    pos++;
  }

  // string end
  ret[retLen] = '\0';
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
  int n;
  char **strs;
  scanf("%d\n", &n);
  strs = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    strs[i] = (char *)malloc(sizeof(char) * 201);
    read_line(strs[i], 200, stdin);
  }
  printf("%s\n", longestCommonPrefix(strs, n));

  for (int i = 0; i < n; i++) {
    free(strs[i]);
  }
  free(strs);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
