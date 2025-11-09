#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 72. 编辑距离 - 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
// 你可以对一个单词进行如下三种操作：
//  * 插入一个字符
//  * 删除一个字符
//  * 替换一个字符
//  
// 示例 1：
// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
// 示例 2：
// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')
//  
// 提示：
//  * 0 <= word1.length, word2.length <= 500
//  * word1 和 word2 由小写英文字母组成

//// #v1
//// 基础模型
//#define min(a, b) ((a) <= (b) ? (a) : (b))
//
//int minDistance(char* word1, char* word2) {
  //if (*word1 == '\0') return strlen(word2);
  //if (*word2 == '\0') return strlen(word1);
//
  //if (*word1 == *word2) return minDistance(word1+1, word2+1);
//
  //// replace
  //int v1 = minDistance(word1+1, word2+1) + 1;
  //// delete
  //int v2 = minDistance(word1+1, word2) + 1;
  //// insert
  //int v3 = minDistance(word1, word2+1) + 1;
//
  //return min(v1, min(v2, v3));
//}
//// #v1

//// #v2
//// 动态规划, 记忆化搜索
//#define min(a, b) ((a) <= (b) ? (a) : (b))
//
//char *s1, *s2;
//int l1, l2, **tab;
//
//int f(int i, int j) {
  ////if (i == l1) return l2 - j;
  ////if (j == l2) return l1 - i;
//
  //if (tab[i][j] >= 0) return tab[i][j];
//
  //if (s1[i] == s2[j]) { // equal, do nothing
    //tab[i][j] = f(i+1, j+1);
    //return tab[i][j];
  //}
//
  //// replace
  //int v1 = f(i+1, j+1) + 1;
  //// delete
  //int v2 = f(i+1, j) + 1;
  //// insert
  //int v3 = f(i, j+1) + 1;
//
  //tab[i][j] = min(v1, min(v2, v3));
//
  //return tab[i][j];
//}
//
//int minDistance(char* word1, char* word2) {
  //s1 = word1;
  //s2 = word2;
  //l1 = strlen(s1);
  //l2 = strlen(s2);
//
  //int *t[l1+1];
//
  //// allocate
  //for (int i = 0; i <= l1; i++) {
    //t[i] = calloc(l2+1, sizeof(int));
    //memset(t[i], 0xff, sizeof(int) * (l2+1));
  //}
//
  //// init
  //t[l1][l2] = 0;
  //for (int i = 0; i < l1; i++) {
    //t[i][l2] = l1 - i;
  //}
  //for (int j = 0; j < l2; j++) {
    //t[l1][j] = l2 - j;
  //}
//
  //tab = t;
//
  //return f(0, 0);
//}
//// #v2

// #v3
// 动态规划, 递推
//#define min(a, b) ((a) <= (b) ? (a) : (b))
int min(int a, int b) {
  return a <= b ? a : b;
}

int minDistance(char* word1, char* word2) {
  int l1 = strlen(word1), l2 = strlen(word2);
  // dp[i][j] 表示 word1[0...(i-1)] 和 word2[0...(j-1)] 的编辑距离
  int dp[l1+1][l2+1], i, j;

  // init
  dp[0][0] = 0;
  for (i = 1; i <= l1; i++) dp[i][0] = i;
  for (j = 1; j <= l2; j++) dp[0][j] = j;

  // compute
  for (i = 0; i < l1; i++) {
    for (j = 0; j < l2; j++) {
      if (word1[i] == word2[j]) { // equal, do nothing
        dp[i+1][j+1] = dp[i][j];
      } else {
        dp[i+1][j+1] = min(dp[i][j]+1, dp[i][j+1]+1);
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
      }
    }
  }

  return dp[l1][l2];
}
// #v3

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
  printf("%d\n", minDistance(s1, s2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
