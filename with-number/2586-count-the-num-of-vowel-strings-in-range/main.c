#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2586. 统计范围内的元音字符串数 - 给你一个下标从 0 开始的字符串数组 words 和两 个整数：left 和 right 。
// 如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中 元音字母是 'a'、'e'、'i'、'o'、'u' 。
// 返回 words[i] 是元音字符串的数目，其中 i 在闭区间 [left, right] 内。
//  
// 示例 1：
// 输入：words = ["are","amy","u"], left = 0, right = 2
// 输出：2
// 解释：
// - "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
// - "amy" 不是元音字符串，因为它没有以元音字母结尾。
// - "u" 是一个元音字符串，因为它以 'u' 开头并以 'u'  结尾。
// 在上述范围中的元音字符串数目为 2 。
// 示例 2：
// 输入：words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
// 输出：3
// 解释：
// - "aeo" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
// - "mu" 不是元音字符串，因为它没有以元音字母开头。
// - "ooo" 是一个元音字符串，因为它以 'o' 开头并以 'o' 结尾。
// - "artro" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
// 在上述范围中的元音字符串数目为 3 。
//  
// 提示：
//  * 1 <= words.length <= 1000
//  * 1 <= words[i].length <= 10
//  * words[i] 仅由小写英文字母组成
//  * 0 <= left <= right < words.length

// #v1
bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int vowelStrings(char** words, int wordsSize, int left, int right) {
  char *p;
  int ret = 0;

  for (int i = left; i <= right; i++) {
    p = words[i];

    if (!isVowel(*p)) continue;

    while (*p) ++p;
    --p;

    if (isVowel(*p)) ++ret;
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
  int n, l, r;
  char **s = (char **)malloc(sizeof(char *) * 50);
  for (int i = 0; i < 50; i++) {
    s[i] = (char *)malloc(sizeof(char) * 100);
  }
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    read_line(s[i], 99, stdin);
  }
  scanf("%d%d", &l, &r);
  printf("%d\n", vowelStrings(s, n, l, r));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
