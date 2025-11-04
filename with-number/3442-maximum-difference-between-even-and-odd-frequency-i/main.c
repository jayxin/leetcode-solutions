#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3442. 奇偶频次间的最大差值 I - 给你一个由小写英文字母组成的字符串 s。
// 请你找出字符串中两个字符 a1 和 a2 的出现频次之间的 最大 差值 diff = freq(a1) - freq(a2)，这两个字符需要满足：
//  * a1 在字符串中出现 奇数次 。
//  * a2 在字符串中出现 偶数次 。
// 返回 最大 差值。
//  
// 示例 1：
// 输入：s = "aaaaabbc"
// 输出：3
// 解释：
//  * 字符 'a' 出现 奇数次 ，次数为 5 ；字符 'b' 出现 偶数次 ， 次数为 2 。
//  * 最大差值为 5 - 2 = 3 。
// 示例 2：
// 输入：s = "abcabcab"
// 输出：1
// 解释：
//  * 字符 'a' 出现 奇数次 ，次数为 3 ；字符 'c' 出现 偶数次 ， 次数为 2 。
//  * 最大差值为 3 - 2 = 1 。
//  
// 提示：
//  * 3 <= s.length <= 100
//  * s 仅由小写英文字母组成。
//  * s 至少由一个出现奇数次的字符和一个出现偶数次的字符组成。

// #v1
int maxDifference(char* s) {
  int c[26] = {0}, maxOdd = 1, minEven = 22222;

  while (*s) {
    ++c[*s - 'a'];
    ++s;
  }

  for (int i = 0; i < 26; i++) {
    if (c[i]) {
      if (c[i] & 1) {
        if (c[i] > maxOdd) maxOdd = c[i];
      } else {
        if (c[i] < minEven) minEven = c[i];
      }
    }
  }

  return maxOdd - minEven;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%d\n", maxDifference(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
