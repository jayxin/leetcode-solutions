#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// #v1
int max(int a, int b) { return (a > b ? a : b); }

int** alloc_2d_arr(int rows, int cols) {
  int **ret = (int **)malloc(sizeof(int *) * rows);
  size_t s = sizeof(int);
  for (int i = 0; i < rows; ++i) {
    ret[i] = (int *)malloc(s * cols);
    memset(ret[i], 0, s * cols);
  }
  return ret;
}

void free_2d_arr(int **arr, int rows) {
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
}

int longestCommonSubsequence(char *text1, char *text2) {
  int l1 = strlen(text1), l2 = strlen(text2), ret = 0;
  int **table = alloc_2d_arr(l1 + 1, l2 + 1);
  for (int i = 1; i <= l1; ++i) {
    for (int j = 1; j <= l2; ++j) {
      if (*(text1 + i - 1) == *(text2 + j - 1)) {
        table[i][j] = 1 + table[i - 1][j - 1];
      } else {
        table[i][j] = max(table[i - 1][j - 1], table[i][j]);
        table[i][j] = max(table[i][j - 1], table[i][j]);
        table[i][j] = max(table[i - 1][j], table[i][j]);
      }
      ret = max(ret, table[i][j]);
    }
  }

  free_2d_arr(table, l1 + 1);

  return ret;
}
// #v1
*/

//// #v2
//int max(int a, int b) { return (a > b ? a : b); }
//
//int longestCommonSubsequence(char *text1, char *text2) {
  //int l1 = strlen(text1), l2 = strlen(text2), ret = 0;
  //int *table = (int *)malloc(sizeof(int) * (l2 + 1));
  //int *new_table = (int *)malloc(sizeof(int) * (l2 + 1));
  //memset(table, 0, sizeof(int) * (l2 + 1));
  //memset(new_table, 0, sizeof(int) * (l2 + 1));
  //int current;
//
  //for (int i = 1; i <= l1; ++i) {
    //for (int j = 1; j <= l2; ++j) {
      //current = 0;
      //if (*(text1 + i - 1) == *(text2 + j - 1)) {
        //current = 1 + table[j - 1];
      //} else {
        //current = max(table[j - 1], current);
        //current = max(table[j], current);
        //current = max(new_table[j - 1], current);
      //}
      //ret = max(ret, current);
      //new_table[j] = current;
    //}
    //int *tmp = table;
    //table = new_table;
    //new_table = tmp;
  //}
  //free(table);
  //free(new_table);
//
  //return ret;
//}
//// #v2

//// #v3
//#define max(a, b) (a > b ? a : b)
//
//int longestCommonSubsequence(char *text1, char *text2) {
  //int l1 = strlen(text1), l2 = strlen(text2), ret = 0;
  //int *table = (int *)malloc(sizeof(int) * (l2 + 1));
  //memset(table, 0, sizeof(int) * (l2 + 1));
  //int current, prev;
//
  //for (int i = 1; i <= l1; ++i) {
    //// 存放本轮的值, iff table[i][j-1]
    //prev = 0;
//
    //for (int j = 1; j <= l2; ++j) {
      //// iff table[i][j]
      //current = 0;
//
      //if (*(text1 + i - 1) == *(text2 + j - 1)) { // 字符相等
        //current = 1 + table[j - 1];
      //} else { // 字符不等
        //current = max(table[j - 1], current); // table[i-1][j-1]
        //current = max(table[j], current); // table[i-1][j]
        //current = max(prev, current); // table[i][j-1]
      //}
//
      //// 更新最大值
      //ret = max(ret, current);
//
      //// 使用本轮的值更新表
      //table[j - 1] = prev;
      //prev = current;
    //}
    //// 使用本轮的值更新表, 这里更新最后一个元素!
    //table[l2] = prev;
  //}
//
  //free(table);
//
  //return ret;
//}
//// #v3

// #v4
#define max(a, b) (a > b ? a : b)

// In this approach, the space complexity is further optimized by using a single
// DP array, where:
// dp[j] represents the value of dp[i-1][j] (previous row's value) before
// updating. During the computation, dp[j] is updated to represent the current
// row value dp[i][j]
// Now the recurrance relations become:
//   - If the characters s1[i-1] and s2[j-1] match, dp[j] = 1+ prev. Here, prev
//   is a temporary variable storing the diagonal value (dp[i-1][j-1]).
//   - If the characters don't match, dp[j] = max(dp[j-1], dp[j]). Here dp[j]
//   represents the value of dp[i-1][j] before updating and dp[j-1] represents
//   the value of dp[i][j-1].
int longestCommonSubsequence(char *text1, char *text2) {
  int l1 = strlen(text1), l2 = strlen(text2), ret, prev;

  // dp[j] 表示 s1[0..i] 和 s2[0..j] 的 LCS
  int *dp = (int *)malloc(sizeof(int) * (l2 + 1));
  memset(dp, 0, sizeof(int) * (l2 + 1));

  for (int i = 1; i <= l1; ++i) {
    // LCS[i-1][j-1]
    prev = dp[0];
    for (int j = 1; j <= l2; ++j) {
      int tmp = dp[j];

      if (*(text1 + i - 1) == *(text2 + j - 1)) {
        dp[j] = 1 + prev;
      } else {
        // LCS[i-1][j] LCS[i-1][j-1] LCS[i][j-1]
        // dp[j-1] 表示 max(LCS[i-1][j-1], LCS[i][j-1])
        dp[j] = max(dp[j - 1], dp[j]);
      }

      prev = tmp;
    }
  }

  ret = dp[l2];

  free(dp);

  return ret;
}
// #v4

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
  char s1[24] = { '\0' }, s2[24] = { '\0' };

  read_line(s1, 21, stdin);
  read_line(s2, 21, stdin);
  printf("%d\n", longestCommonSubsequence(s1, s2));

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
