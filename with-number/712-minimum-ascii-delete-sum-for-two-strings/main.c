#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 712. 两个字符串的最小ASCII删除和 - 给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
//  
// 示例 1:
// 输入: s1 = "sea", s2 = "eat"
// 输出: 231
// 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总 和。
// 在 "eat" 中删除 "t" 并将 116 加入总和。
// 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
// 示例 2:
// 输入: s1 = "delete", s2 = "leet"
// 输出: 403
// 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
// 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
// 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
// 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
//  
// 提示:
//  * 0 <= s1.length, s2.length <= 1000
//  * s1 和 s2 由小写英文字母组成

//// #v1
//// 超时
//int min(int a, int b) { return a <= b ? a : b; }
//
//int f(char* s1, char* s2) {
  //if (*s1 == '\0') {
    //int ret = 0;
    //while (*s2) {
      //ret += *s2;
      //++s2;
    //}
    //return ret;
  //}
  //if (*s2 == '\0') {
    //int ret = 0;
    //while (*s1) {
      //ret += *s1;
      //++s1;
    //}
    //return ret;
  //}
//
  //// 两个字符相等, 不删除
  //if (*s1 == *s2) return f(s1 + 1, s2 + 1);
//
  //int v1 = f(s1+1, s2) + *s1; // 删除 *s1
  //int v2 = f(s1, s2+1) + *s2; // 删除 *s2
  //int v3 = f(s1+1, s2+1) + *s1 + *s2; // 删除 *s1 和 *s2
  //return min(v1, min(v2, v3));
//}
//
//int minimumDeleteSum(char* s1, char* s2) {
  //return f(s1, s2);
//}
//// #v1

//// #v2
//// 动态规划, 记忆化搜索
//#define min(a, b) ((a) <= (b) ? (a) : (b))
//
//int l1, l2, **t;
//char *w1, *w2;
//
//int f(int i, int j) {
  //if (t[i][j] >= 0) return t[i][j];
//
  //if (i == l1) {
    //int ret = 0;
    //for (int k = j; k < l2; k++) ret += w2[k];
    //t[l1][j] = ret;
    //return ret;
  //}
//
  //if (j == l2) {
    //int ret = 0;
    //for (int k = i; k < l1; k++) ret += w1[k];
    //t[i][l2] = ret;
    //return ret;
  //}
//
  //if (w1[i] == w2[j]) { // 两个字符相等, 不删除
    //t[i][j] = f(i+1, j+1);
  //} else {
    //int v1 = f(i+1, j) + w1[i]; // 删除 w1[i]
    //int v2 = f(i, j+1) + w2[j]; // 删除 w2[j]
//
    //t[i][j] =  min(v1, v2);
  //}
//
  //return t[i][j];
//}
//
//int minimumDeleteSum(char* s1, char* s2) {
  //l1 = strlen(s1);
  //l2 = strlen(s2);
//
  //int *tab[l1+1];
//
  //for (int i = 0; i <= l1; i++) {
    //tab[i] = calloc(l2+1, sizeof(int));
    //memset(tab[i], 0xff, sizeof(int)*(l2+1));
  //}
//
  //t = tab;
  //w1 = s1;
  //w2 = s2;
//
  //return f(0, 0);
//}
//// #v2

// #v3
// 动态规划, 递推
#define min(a, b) ((a) <= (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
  int l1 = strlen(s1), l2 = strlen(s2);
  // dp[i][j] 表示使 s1[0...(i-1)] 和 s2[0...(j-1)] 相等所需删除
  // 字符的 ASCII 值的最小和
  int dp[l1+1][l2+1], i, j;

  // init
  dp[0][0] = 0;
  for (i = 0; i < l1; i++) {
    dp[i+1][0] = dp[i][0] + s1[i];
  }
  for (j = 0; j < l2; j++) {
    dp[0][j+1] = dp[0][j] + s2[j];
  }

  // compute
  for (i = 0; i < l1; i++) {
    for (j = 0; j < l2; j++) {
      if (s1[i] == s2[j]) // 当前字符相等, 不需要删除
        dp[i+1][j+1] = dp[i][j];
      else // 字符不等, 选择删除 s1[i] 或 s2[j]
        dp[i+1][j+1] = min(dp[i][j+1]+s1[i], dp[i+1][j]+s2[j]);
    }
  }

  return dp[l1][l2];
}
// #v2

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
  char s[100], t[100];
  read_line(s, 98, stdin);
  read_line(t, 98, stdin);
  printf("%d\n", minimumDeleteSum(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
