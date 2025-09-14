#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 744. 寻找比目标字母大的最小字母 - 给你一个字符数组 letters，该数组按非递减顺 序排序，以及一个字符 target。letters 里至少有两个不同的字符。
// 返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的 第一个字符。
//  
// 示例 1：
// 输入: letters = ['c', 'f', 'j']，target = 'a'
// 输出: 'c'
// 解释：letters 中字典上比 'a' 大的最小字符是 'c'。
// 示例 2:
// 输入: letters = ['c','f','j'], target = 'c'
// 输出: 'f'
// 解释：letters 中字典顺序上大于 'c' 的最小字符是 'f'。
// 示例 3:
// 输入: letters = ['x','x','y','y'], target = 'z'
// 输出: 'x'
// 解释：letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。
//  
// 提示：
//  * 2 <= letters.length <= 104
//  * letters[i] 是一个小写字母
//  * letters 按非递减顺序排序
//  * letters 最少包含两个不同的字母
//  * target 是一个小写字母

// #v1
char nextGreatestLetter(char* letters, int lettersSize, char target) {
  char ret = target;
  int l = 0, r = lettersSize - 1, m;

  while (l < r) {
    m = (l + r) >> 1;
    if (letters[m] <= target) {
      l = m + 1;
    } else if (letters[m] > target) {
      ret = letters[m];
      r = m;
    }
  }

  if (letters[l] <= target) ret = letters[0];
  else ret = letters[l];

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
  char s[100], c;
  read_line(s, 99, stdin);
  c = getchar();
  printf("%c\n", nextGreatestLetter(s, strlen(s), c));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
