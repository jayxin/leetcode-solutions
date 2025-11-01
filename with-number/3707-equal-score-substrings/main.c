#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3707. 相等子字符串分数 - 给你一个由小写英文字母组成的字符串 s。
// 一个字符串的 得分 是其字符在字母表中的位置之和，其中 'a' = 1，'b' = 2，...，'z' = 26。
// 请你判断是否存在一个下标 i，使得该字符串可以被拆分成两个 非空子字符串 s[0..i] 和 s[(i + 1)..(n - 1)]，且它们的得分 相等 。
// 如果存在这样的拆分，则返回 true，否则返回 false。
// 一个 子字符串 是字符串中 非空 的连续字符序列。
//  
// 示例 1:
// 输入: s = "adcb"
// 输出: true
// 解释:
// 在下标 i = 1 处拆分：
//  * 左子字符串 = s[0..1] = "ad"，得分 = 1 + 4 = 5
//  * 右子字符串 = s[2..3] = "cb"，得分 = 3 + 2 = 5
// 两个子字符串的得分相等，因此输出为 true。
// 示例 2:
// 输入: s = "bace"
// 输出: false
// 解释:
// 没有拆分能产生相等的得分，因此输出为 false。
//  
// 提示:
//  * 2 <= s.length <= 100
//  * s 由小写英文字母组成。

// #v1
bool scoreBalance(char* s) {
  int n = strlen(s), prefixSum[n+1];

  prefixSum[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = prefixSum[i-1] + s[i-1] - 'a' + 1;
  }

  for (int i = 0; i < n-1; i++) {
    if (prefixSum[i+1] == prefixSum[n] - prefixSum[i+1]) return true;
  }

  return false;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  if (scoreBalance(s))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
