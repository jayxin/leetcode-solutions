#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 500. 键盘行 - 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
// 请注意，字符串 不区分大小写，相同字母的大小写形式都被视为在同一行。
// 美式键盘 中：
//  * 第一行由字符 "qwertyuiop" 组成。
//  * 第二行由字符 "asdfghjkl" 组成。
//  * 第三行由字符 "zxcvbnm" 组成。
// American keyboard [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png]
//  
// 示例 1：
// 输入：words = ["Hello","Alaska","Dad","Peace"]
// 输出：["Alaska","Dad"]
// 解释：
// 由于不区分大小写，"a" 和 "A" 都在美式键盘的第二行。
// 示例 2：
// 输入：words = ["omk"]
// 输出：[]
// 示例 3：
// 输入：words = ["adsdf","sfd"]
// 输出：["adsdf","sfd"]
//  
// 提示：
//  * 1 <= words.length <= 20
//  * 1 <= words[i].length <= 100
//  * words[i] 由英文字母（小写和大写字母）组成

// #v1
char** findWords(char** words, int wordsSize, int* returnSize) {
  char **ret = (char **)malloc(sizeof(char *) * wordsSize),
       tab[26], c, *p,
       *row0 = "qwertyuiop", *row1 = "asdfghjkl", *row2 = "zxcvbnm";
  int retLen = 0, i, r;
  bool sameRow = true;

  p = row0;
  while (*p) {
    tab[*p - 'a'] = 0;
    ++p;
  }

  p = row1;
  while (*p) {
    tab[*p - 'a'] = 1;
    ++p;
  }

  p = row2;
  while (*p) {
    tab[*p - 'a'] = 2;
    ++p;
  }

  for (i = 0; i < wordsSize; i++) {
    p = words[i];
    c =(*p) | 0x20;
    r = tab[c - 'a'];
    sameRow = true;
    while (*p) {
      c =(*p) | 0x20;

      if (tab[c - 'a'] != r) {
        sameRow = false;
        break;
      }

      ++p;
    }

    if (sameRow) ret[retLen++] = words[i];
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
  char **a, **ret;
  int n, i, s;
  scanf("%d\n", &n);
  a = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) {
    a[i] = (char *)malloc(sizeof(char) * 51);
    read_line(a[i], 50, stdin);
  }
  ret = findWords(a, n, &s);
  for (i = 0; i < s; i++) {
    printf("%s\n", ret[i]);
  }
  if (!s) putchar('\n');
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
