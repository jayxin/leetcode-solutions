#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2942. 查找包含给定字符的单词 - 给你一个下标从 0 开始的字符串数组 words 和一个字 符 x 。
// 请你返回一个 下标数组 ，表示下标在数组中对应的单词包含字符 x 。
// 注意 ，返回的数组可以是 任意 顺序。
//  
// 示例 1：
// 输入：words = ["leet","code"], x = "e"
// 输出：[0,1]
// 解释："e" 在两个单词中都出现了："leet" 和 "code" 。所以我们返回下标 0 和 1 。
// 示例 2：
// 输入：words = ["abc","bcd","aaaa","cbc"], x = "a"
// 输出：[0,2]
// 解释："a" 在 "abc" 和 "aaaa" 中出现了，所以我们返回下标 0 和 2 。
// 示例 3：
// 输入：words = ["abc","bcd","aaaa","cbc"], x = "z"
// 输出：[]
// 解释："z" 没有在任何单词中出现。所以我们返回空数组。
//  
// 提示：
//  * 1 <= words.length <= 50
//  * 1 <= words[i].length <= 50
//  * x 是一个小写英文字母。
//  * words[i] 只包含小写英文字母。

// #v1
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * wordsSize), retLen = 0;
  char *s;

  for (int i = 0; i < wordsSize; i++) {
    s = words[i];

    while (*s) {
      if (*s == x) {
        ret[retLen++] = i;
        break;
      }
      ++s;
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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *ret, retLen;
  char **s, c;
  scanf("%d\n", &n);
  s = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(sizeof(char) * 100);
    read_line(s[i], 98, stdin);
  }
  c = getchar();
  ret = findWordsContaining(s, n, c, &retLen);
  print_1d_arr(ret, retLen);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
