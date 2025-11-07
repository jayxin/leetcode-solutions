#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 583. 两个字符串的删除操作 - 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
// 每步 可以删除任意一个字符串中的一个字符。
//  
// 示例 1：
// 输入: word1 = "sea", word2 = "eat"
// 输出: 2
// 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变 为 "ea"
// 示例  2:
// 输入：word1 = "leetcode", word2 = "etco"
// 输出：4
//  
// 提示：
//  * 1 <= word1.length, word2.length <= 500
//  * word1 和 word2 只包含小写英文字母

//// #v1
//// 超时
//int min(int a, int b) { return a <= b ? a : b; }
//int minDistance(char* word1, char* word2) {
  //if (*word1 == '\0') return strlen(word2);
  //if (*word2 == '\0') return strlen(word1);
//
  //if (*word1 == *word2) return minDistance(word1+1, word2+1);
//
  //return 1 + min(minDistance(word1+1, word2), minDistance(word1, word2+1));
//}
//// #v1

//// #v2
//// 动态规划, 记忆化搜索
//int min(int a, int b) { return a <= b ? a : b; }
//
//char *w1, *w2;
//int l1, l2, **t;
//
//int f(int i, int j) {
  //if (i == l1) return l2 - j;
  //if (j == l2) return l1 - i;
//
  //if (t[i][j] >= 0) return t[i][j];
//
  //if (*(w1+i) == *(w2+j)) t[i][j] = f(i+1, j+1);
  //else t[i][j] = 1 + min(f(i+1, j), f(i, j+1));
//
  //return t[i][j];
//}
//
//int minDistance(char* word1, char* word2) {
  //l1 = strlen(word1);
  //l2 = strlen(word2);
//
  //int *tab[l1];
//
  //for (int i = 0; i < l1; i++) {
    //tab[i] = calloc(l2, sizeof(int));
    //memset(tab[i], 0xff, sizeof(int) * l2);
  //}
//
  //t = tab;
  //w1 = word1;
  //w2 = word2;
//
  //return f(0, 0);
//}
//// #v2

// #v3
// 动态规划, 递推
#define min(a, b) ((a) <= (b) ? (a) : (b))

int minDistance(char* word1, char* word2) {
  int l1 = strlen(word1), l2 = strlen(word2);
  // dp[i][j] 表示 word1 长度为 i, word2 长度为 j 时最小删除数
  int dp[l1+1][l2+1], i, j;

  // init
  for (i = 0; i <= l1; i++) dp[i][0] = i;
  for (j = 0; j <= l2; j++) dp[0][j] = j;

  // compute
  for (i = 1; i <= l1; i++) {
    for (j = 1; j <= l2; j++) {
      if (*(word1+i-1) == *(word2+j-1)) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
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
  char s[100], t[100];
  read_line(s, 98, stdin);
  read_line(t, 98, stdin);
  printf("%d\n", minDistance(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
