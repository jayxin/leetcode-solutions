#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2287. 重排字符形成目标字符串 - 给你两个下标从 0 开始的字符串 s 和 target 。你可 以从 s 取出一些字符并将其重排，得到若干新的字符串。
// 从 s 中取出字符并重新排列，返回可以形成 target 的 最大 副本数。
//  
// 示例 1：
// 输入：s = "ilovecodingonleetcode", target = "code"
// 输出：2
// 解释：
// 对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
// 对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
// 形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
// 可以形成最多 2 个 "code" 的副本，所以返回 2 。
// 示例 2：
// 输入：s = "abcba", target = "abc"
// 输出：1
// 解释：
// 选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。
// 可以形成最多 1 个 "abc" 的副本，所以返回 1 。
// 注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下 标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。
// 示例 3：
// 输入：s = "abbaccaddaeea", target = "aaaaa"
// 输出：1
// 解释：
// 选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
// 可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * 1 <= target.length <= 10
//  * s 和 target 由小写英文字母组成
//  
// 注意：本题与 1189. “气球” 的最大数量 [https://leetcode.cn/problems/maximum-number-of-balloons/] 相同。

// #v1
int rearrangeCharacters(char* s, char* target) {
  int c1[26] = {0}, c2[26] = {0}, min = 0x7fffffff;

  while (*s) {
    ++c1[*s - 'a'];
    ++s;
  }

  while (*target) {
    ++c2[*target - 'a'];
    ++target;
  }

  for (int i = 0; i < 26; i++) {
    if (c2[i]) {
      if (!c1[i] || c1[i] < c2[i]) return 0;
      int t = c1[i] / c2[i];
      if (t < min) min = t;
    }
  }

  return min;
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
  printf("%d\n", rearrangeCharacters(s1, s2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
