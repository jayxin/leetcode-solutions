#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1790. 仅执行一次字符串交换能否使两个字符串相等 - 给你长度相等 的两个字符串 s1 和 s2 。一次 字符串交换 操作的步骤如下：选出某个字符串中的两个下 标（不必不同），并交换这两个下标所对应的字符。
// 如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true  ；否则，返回 false 。
//  
// 示例 1：
// 输入：s1 = "bank", s2 = "kanb"
// 输出：true
// 解释：例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
// 示例 2：
// 输入：s1 = "attack", s2 = "defend"
// 输出：false
// 解释：一次字符串交换无法使两个字符串相等
// 示例 3：
// 输入：s1 = "kelb", s2 = "kelb"
// 输出：true
// 解释：两个字符串已经相等，所以不需要进行字符串交换
// 示例 4：
// 输入：s1 = "abcd", s2 = "dcba"
// 输出：false
//  
// 提示：
//  * 1 <= s1.length, s2.length <= 100
//  * s1.length == s2.length
//  * s1 和 s2 仅由小写英文字母组成

// #v1
bool areAlmostEqual(char* s1, char* s2) {
  int notEqualCnt = 0, set1 = 0, set2 = 0;

  while (*s1) {
    if (*s1 != *s2) {
      set1 |= 1 << (*s1 & 0x1f);
      set2 |= 1 << (*s2 & 0x1f);
      ++notEqualCnt;
    }

    ++s1;
    ++s2;
  }

  if (notEqualCnt && notEqualCnt != 2) return false;

  return set1 == set2;
}
// #v1

int main(int argc, char *argv[])
{
  char s1[100], s2[100];
  scanf("%s\n", s1);
  scanf("%s\n", s2);
  if (areAlmostEqual(s1, s2)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
