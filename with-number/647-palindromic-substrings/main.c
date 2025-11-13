#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 647. 回文子串 - 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
// 回文字符串 是正着读和倒过来读一样的字符串。
// 子字符串 是字符串中的由连续字符组成的一个序列。
//  
// 示例 1：
// 输入：s = "abc"
// 输出：3
// 解释：三个回文子串: "a", "b", "c"
// 示例 2：
// 输入：s = "aaa"
// 输出：6
// 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
//  
// 提示：
//  * 1 <= s.length <= 1000
//  * s 由小写英文字母组成

//// #v1
//int countSubstrings(char* s) {
  //int n = strlen(s);
  //// dp[j][i] 表示 s[j-1...i-1] 是否为回文子串
  //int dp[n+1][n+1], ret = n;
//
  //for (int i = 1; i <= n; i++) {
    //dp[i][i] = 1;
//
    //for (int j = 1; j < i; j++) {
      //dp[j][i] = 0;
//
      //if (s[i-1] == s[j-1]) {
        //if (j+1 == i || dp[j+1][i-1]) {
          //dp[j][i] = 1;
          //++ret;
        //}
      //}
    //}
  //}
//
  //return ret;
//}
//// #v1

//// #v2
//int countSubstrings(char* s) {
  //int n = strlen(s), ret = n;
  //// dp[j][i] 表示 s[j...i] 是否为回文子串
  //char dp[n][n];
//
  //for (int i = 0; i < n; i++) {
    //dp[i][i] = 1;
//
    //for (int j = 0; j < i; j++) {
      //dp[j][i] = 0;
//
      //if (s[i] == s[j]) {
        //if (j+1 == i || dp[j+1][i-1]) {
          //dp[j][i] = 1;
          //++ret;
        //}
      //}
    //}
  //}
//
  //return ret;
//}
//// #v2

// #v3
int countSubstrings(char* s) {
  int n = strlen(s), ret = n;
  // dp[j][i] 表示 s[j...i] 是否为回文子串
  char dp[n][n];

  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;

    // 检查 s[j...i] 是否为回文串
    // s[j...i] 为回文串当且仅当 s[j] == s[i] && s[j+1...i-1] 是回文串
    for (int j = 0; j < i; j++) {
      dp[j][i] = 0;

      if (s[i] == s[j] && (j+1 == i || dp[j+1][i-1])) {
        dp[j][i] = 1;
        ++ret;
      }
    }
  }

  return ret;
}
// #v3

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%d\n", countSubstrings(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
