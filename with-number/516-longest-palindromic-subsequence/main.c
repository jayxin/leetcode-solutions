#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 516. 最 长回文子序列 - 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一 个序列。
//  
// 示例 1：
// 输入：s = "bbbab"
// 输出：4
// 解释：一个可能的最长回文子序列为 "bbbb" 。
// 示例 2：
// 输入：s = "cbbd"
// 输出：2
// 解释：一个可能的最长回文子序列为 "bb" 。
//  
// 提示：
//  * 1 <= s.length <= 1000
//  * s 仅由小写英文字母组成

//// #v1
//int max(int a, int b) { return a >= b ? a : b; }
//
//int longestPalindromeSubseq(char* s) {
  //int n = strlen(s);
  //int dp[n][n];
//
  //if (n == 1) return 1;
//
  //for (int i = 0; i < n; i++) {
    //dp[i][i] = 1;
//
    //for (int j = i-1; j >= 0; j--) { // 从后往前遍历
      //if (j+1 == i) {
        //dp[j][i] = (s[i] == s[j]) ? 2 : 1;
      //} else {
        //if (s[i] == s[j]) dp[j][i] = max(dp[j+1][i], dp[j+1][i-1] + 2);
        //else dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
      //}
    //}
  //}
//
  //return dp[0][n-1];
//}
//// #v1

//// #v2
//int max(int a, int b) { return a >= b ? a : b; }
//
//int longestPalindromeSubseq(char* s) {
  //int n = strlen(s);
  //// dp[j][i] 表示 s[j...i] 的最长回文子序列的长度
  //int dp[n][n];
//
  //// edge case
  ////if (n == 1) return 1;
//
  //// init, edge case
  //dp[0][0] = 1;
//
  //for (int i = 1; i < n; i++) {
    //// init
    //dp[i][i] = 1;
    //dp[i-1][i] = (s[i] == s[i-1]) ? 2 : 1;
//
    //for (int j = i-2; j >= 0; j--) { // 从后往前遍历
      ////if (s[i] == s[j]) dp[j][i] = max(dp[j+1][i], dp[j+1][i-1] + 2);
      ////else dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
//
      ////dp[j][i] = dp[j+1][i];
      ////if (s[i] == s[j]) dp[j][i] = max(dp[j][i], dp[j+1][i-1]+2);
      ////else dp[j][i] = max(dp[j][i], dp[j][i-1]);
//
      //if (s[i] == s[j]) dp[j][i] = dp[j+1][i-1]+2;
      //else dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
    //}
  //}
//
  //return dp[0][n-1];
//}
//// #v2

// #v3
// 反转后求二者的最长公共子序列
int max(int a, int b) { return a >= b ? a : b; }

int longestCommonSubsequence(char *s1, char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);
  // dp[j] 表示 s1[0..i] 和 s2[0..j-1] 的 LCS
  int dp[l2+1];

  memset(dp, 0, sizeof(int) * (l2+1));

  for (int i = 1; i <= l1; ++i) {
    // LCS[i-1][j-1]
    int prev = dp[0];

    for (int j = 1; j <= l2; ++j) {
      int tmp = dp[j];

      if (s1[i-1] == s2[j-1]) {
        dp[j] = 1 + prev;
      } else {
        // LCS[i-1][j] LCS[i-1][j-1] LCS[i][j-1]
        // dp[j] 未计算前为 LCS[i-1][j]
        // dp[j-1] 表示 max(LCS[i-1][j-1], LCS[i][j-1])
        dp[j] = max(dp[j-1], dp[j]);
      }

      prev = tmp;
    }
  }

  return dp[l2];
}

int longestPalindromeSubseq(char* s) {
  int n = strlen(s);
  char reversedStr[n+1], *p, *q;

  sprintf(reversedStr, "%s", s);

  p = reversedStr;
  q = reversedStr + n - 1;
  while (p < q) {
    char c = *p;
    *p = *q;
    *q = c;
    ++p;
    --q;
  }

  return longestCommonSubsequence(s, reversedStr);
}
// #v3

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", &s);
  printf("%d\n", longestPalindromeSubseq(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
