#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 748. 最短补 全词 - 给你一个字符串 licensePlate 和一个字符串数组 words ，请你找出 words 中的  最短补全词 。
// 补全词 是一个包含 licensePlate 中所有字母的单词。忽略 licensePlate 中的 数字和空 格 。不区分大小写。如果某个字母在 licensePlate 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。
// 例如：licensePlate = "aBc 12c"，那么它的补全词应当包含字母 'a'、'b' （忽略大写）和两个 'c' 。可能的 补全词 有 "abccdef"、"caaacab" 以及 "cbca" 。
// 请返回 words 中的 最短补全词 。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 words 中 第一个 出现的那个。
//  
// 示例 1：
// 输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
// 输出："steps"
// 解释：最短补全词应该包括 "s"、"p"、"s"（忽略大小写 ） 以及 "t"。
// "step" 包含 "t"、"p"，但只包含一个 "s"， 所以它不符合条件。
// "steps" 包含 "t"、"p" 和两个 "s"。
// "stripe" 缺一个 "s"。
// "stepple" 缺一个 "s"。
// 因此，"steps" 是唯一一个包含所有字母的单词，也是本例的答案。
// 示例 2：
// 输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
// 输出："pest"
// 解释：licensePlate 只包含字母 "s" 。所有的单词都包含字母 "s" ，其中 "pest"、"stew"、和 "show" 三者最短。答案是 "pest" ，因为它是三个单词中在 words 里最靠前的那个。
//  
// 提示：
//  * 1 <= licensePlate.length <= 7
//  * licensePlate 由数字、大小写字母或空格 ' ' 组成
//  * 1 <= words.length <= 1000
//  * 1 <= words[i].length <= 15
//  * words[i] 由小写英文字母组成

// #v1
char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
  int set0 = 0, set1, c0[26] = {0}, c1[26], retLen = 0x7fffffff;
  char *ret = NULL;

  while (*licensePlate) {
    if (*licensePlate & 0x40) { // letter
      // to lower
      char c = *licensePlate | 0x20;

      // add to set
      set0 |= 1 << (c & 0x1f);
      // count
      ++c0[c - 'a'];
    }

    // forward
    ++licensePlate;
  }

  for (int i = 0; i < wordsSize; i++) {
    memset(c1, 0, sizeof(c1));
    set1 = 0;

    int len = 0;
    char *s = words[i], f = 1;

    while (*s) {
      // add to set
      set1 |= 1 << (*s & 0x1f);
      // count
      ++c1[*s - 'a'];
      // forward
      ++len;
      ++s;
    }

    if ((set0 & set1) != set0) continue;

    for (int j = 0; j < 26; j++) {
      if (c1[j] && c0[j] > c1[j]) {
        f = 0;
        break;
      }
    }

    if (f && (!ret || len < retLen)) {
      ret = words[i];
      retLen = len;
    }
  }

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
  char **words, s[100];
  scanf("%d\n", &n);
  words = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  read_line(s, 98, stdin);

  printf("%s\n", shortestCompletingWord(s, words, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
