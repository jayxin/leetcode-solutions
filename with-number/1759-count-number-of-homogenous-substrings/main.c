#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1759. 统计同质子字符串的数目 - 给你一个字符串 s ，返回 s 中 同质子字符串 的数目 。由于答案可能很大，只需返回对 109 + 7 取余 后的结果。
// 同质字符串 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同质字符串。
// 子字符串 是字符串中的一个连续字符序列。
//  
// 示例 1：
// 输入：s = "abbcccaa"
// 输出：13
// 解释：同质子字符串如下所列：
// "a"   出现 3 次。
// "aa"  出现 1 次。
// "b"   出现 2 次。
// "bb"  出现 1 次。
// "c"   出现 3 次。
// "cc"  出现 2 次。
// "ccc" 出现 1 次。
// 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13
// 示例 2：
// 输入：s = "xy"
// 输出：2
// 解释：同质子字符串是 "x" 和 "y" 。
// 示例 3：
// 输入：s = "zzzzz"
// 输出：15
//  
// 提示：
//  * 1 <= s.length <= 105
//  * s 由小写字符串组成。

// #v1
#define MOD 1000000007

int countHomogenous(char* s) {
  int ret = 0, set = 0, c = 0;

  while (*s) {
    int pos = *s++ & 0x1f;

    if (!((set >> pos) & 1)) {
      ret = (c*(c+1LL)/2 + ret) % MOD;

      // reset
      c = 1;
      set = 1 << pos;
    } else {
      ++c;
    }
  }

  ret = (c*(c+1LL)/2 + ret) % MOD;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%d\n", countHomogenous(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
