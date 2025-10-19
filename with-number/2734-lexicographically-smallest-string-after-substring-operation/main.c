#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2734. 执行子串操作后的字典序最小字符串 - 给你一个仅由小写英文字母组成 的字符串 s 。在一步操作中，你可以完成以下行为：
//  * 选择 s 的任一非空子字符串，可能是整个字符串，接着将字符串中的每一个字符替换为 英文字母表中的前一个字符。例如，'b' 用 'a' 替换，'a' 用 'z' 替换。
// 返回执行上述操作 恰好一次 后可以获得的 字典序最小 的字符串。
// 子字符串 是字符串中的一个连续字符序列。
// 现有长度相同的两个字符串 x 和 字符串 y ，在满足 x[i] != y[i] 的第一个位置 i 上， 如果  x[i] 在字母表中先于 y[i] 出现，则认为字符串 x 比字符串 y 字典序更小 。
//  
// 示例 1：
// 输入：s = "cbabc"
// 输出："baabc"
// 解释：我们选择从下标 0 开始、到下标 1 结束的子字符串执行操作。
// 可以证明最终得到的字符串是字典序最小的。
// 示例 2：
// 输入：s = "acbbc"
// 输出："abaab"
// 解释：我们选择从下标 1 开始、到下标 4 结束的子字符串执行操作。
// 可以证明最终得到的字符串是字典序最小的。
// 示例 3：
// 输入：s = "leetcode"
// 输出："kddsbncd"
// 解释：我们选择整个字符串执行操作。
// 可以证明最终得到的字符串是字典序最小的。
//  
// 提示：
//  * 1 <= s.length <= 3 * 105
//  * s 仅由小写英文字母组成
// When a character is replaced by the one that comes before it on the alphabet,
// it makes the string lexicographically smaller, except for ‘a'.
// Find the leftmost substring that doesn’t contain the character 'a' and change
// all characters in it.

// #v1
char* smallestString(char* s) {
  int n = strlen(s);
  char *ret = (char *)malloc(sizeof(char) * (n + 1)), *p;

  sprintf(ret, "%s", s);

  p = ret;
  // 跳过 'a'
  while (*p && *p == 'a') ++p;

  if (*p == '\0') { // s 中全为 'a'
    *(p - 1) = 'z';
    return ret;
  }

  while (*p) {
    // 遇到 'a' 则停止
    if (*p == 'a') break;

    *p = *p - 1;

    ++p;
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
  char s[100];
  read_line(s, 98, stdin);
  printf("%s\n", smallestString(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
