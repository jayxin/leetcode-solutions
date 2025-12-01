#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 424. 替换后的最长重复字符 - 给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任 一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
// 在执行上述操作后，返回 包含相同字母的最长子字符串的长度。
//  
// 示例 1：
// 输入：s = "ABAB", k = 2
// 输出：4
// 解释：用两个'A'替换为两个'B',反之亦然。
// 示例 2：
// 输入：s = "AABABBA", k = 1
// 输出：4
// 解释：
// 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
// 子串 "BBBB" 有最长重复字母, 答案为 4。
// 可能存在其他的方法来得到同样的结果。
//  
// 提示：
//  * 1 <= s.length <= 105
//  * s 仅由大写英文字母组成
//  * 0 <= k <= s.length

// #v1
// hash table, count, sliding window
int characterReplacement(char* s, int k) {
  int l, r, n, cnts[26] = {0}, len, ret, set;
  char *p;

  n = 0;
  p = s;
  while (*p) {
    ++n;
    ++p;
  }

  // init
  // 滑动窗口的左右边界(s 的索引)
  l = 0, r = 1;
  ret = len = 1;
  cnts[s[0]-'A'] = 1;
  set |= 1 << (s[0] - 'A');

  // 滑动窗口内的字符应该和 s[l] 相同
  // 滑动窗口内和 s[i] 不同的字符不超过 k 个, i \in [l, r]
  while (r < n) {
    int pos = s[r] - 'A';
    // 计数增加
    ++cnts[pos];
    // 滑动窗口长度增加
    ++len;
    // add to set
    set |= 1 << pos;

    char f = 0;
    int x = set, idx = 0, t;
    while (x) {
      if (x & 1) {
        t = len - cnts[idx];
        if (t <= k) {
          f = 1;
          break;
        }
      }

      ++idx;
      x >>= 1;
    }

    if (!f) {
      // s[l] 移出窗口
      pos = s[l] - 'A';
      --cnts[pos];
      if (cnts[pos] == 0) set &= ~(1 << pos);
      ++l;
      --len;
    }

    if (len > ret) ret = len;

    // 扩展滑动窗口的右边界
    ++r;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int k;
  char s[100];
  scanf("%s", s);
  scanf("%d", &k);
  printf("%d\n", characterReplacement(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
