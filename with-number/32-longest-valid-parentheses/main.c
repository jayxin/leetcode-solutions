#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//// #v1
//// 通过将匹配的 () 替换为 -, 统计 '-' 的长度
//#define max(a, b) (a > b ? a : b)
//
//int longestValidParentheses(char *s) {
  //int len = strlen(s),
      //top = -1,
      //ret = 0;
  //char *l = s, *r = s + strlen(s);
  //int *stack = (int *)malloc(sizeof(int) * len);
//
  //while (l < r) {
    //if (*l == '(') {
      //stack[++top] = l - s;
    //} else if (*l == ')') {
      //if (top == -1) {
        //l++;
        //continue;
      //}
      //*l = '-';
      //*(s + stack[top--]) = '-';
    //}
//
    //l++;
  //}
//
  //free(stack);
//
  //l = s;
  //int cnt = 0;
  //while (l < r) {
    //if (*l == '-') {
      //cnt++;
    //} else {
      //ret = max(ret, cnt);
      //cnt = 0;
    //}
    //l++;
  //}
//
  //ret = max(ret, cnt);
//
  //return ret;
//}
//// #v1

// #v2
// 动态规划
#define max(a, b) (a > b ? a : b)

int longestValidParentheses(char *s) {
  if (!s) return 0;

  int ret = 0, len = strlen(s);
  if (len == 0) {
    return 0;
  }

  // dp[i] 表示以第 i 个字符结尾的最长有效括号子串的长度
  int *dp = (int *)malloc(sizeof(int) * len);
  memset(dp, 0, sizeof(int) * len);

  for (int i = 1; i < len; i++) {
    if (s[i] == ')') {
      if (s[i-1] == '(') { // 前一个字符是 '(', 形成有效括号
        dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
      } else if (i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') { // 前一个字符是 ')', 需检查更前面的位置
        dp[i] = dp[i-1] + \
                ((i-dp[i-1] >= 2) ? dp[i-dp[i-1]-2] : 0) + \
                2;
      }

      ret = max(ret, dp[i]); // update max value
    }
  }

  free(dp);

  return ret;
}
// #v2

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
  char str[500];
  read_line(str, 400, stdin);
  printf("%d\n", longestValidParentheses(str));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
