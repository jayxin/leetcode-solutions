#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 91. 解码方法 - 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
// "1" -> 'A'
// "2" -> 'B'
// ...
// "25" -> 'Y'
// "26" -> 'Z'
// 然而，在 解码 已编码的消息时，你意识到有许多不同的方式来解码，因为有些编码被包含 在其它编码当中（"2" 和 "5" 与 "25"）。
// 例如，"11106" 可以映射为：
//  * "AAJF" ，将消息分组为 (1, 1, 10, 6)
//  * "KJF" ，将消息分组为 (11, 10, 6)
//  * 消息不能分组为  (1, 11, 06) ，因为 "06" 不是一个合法编码（只有 "6" 是合法的）。
// 注意，可能存在无法解码的字符串。
// 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。如果没有合法的方式解码整个字符串，返回 0。
// 题目数据保证答案肯定是一个 32 位 的整数。
//  
// 示例 1：
// 输入：s = "12"
// 输出：2
// 解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
// 示例 2：
// 输入：s = "226"
// 输出：3
// 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
// 示例 3：
// 输入：s = "06"
// 输出：0
// 解释："06" 无法映射到 "F" ，因为存在前导零（"6" 和 "06" 并不等价）。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * s 只包含数字，并且可能包含前导零。

//// #v1
//// 递归
//// 超时
//int _numDecodings(char* s, char *e) {
  //if (!s) { // empty string
    //return 0;
  //}
//
  //char c = *s;
//
  //// string end, decode succes
  //if (s >= e || c == '\0') {
    //return 1;
  //}
//
  //// c: '0'
  //if (c == '0') {
    //return 0;
  //}
//
  //// c: '3' - '9'
  //if (c > '2' && c <= '9') {
    //return _numDecodings(s + 1, e);
  //} else if (c == '1') {
    //int i1 = _numDecodings(s + 1, e);
    //int i2 = 0;
    //if (s + 2 <= e) {
      //i2 = _numDecodings(s + 2, e);
    //}
    //return i1 + i2;
  //}
//
  //// c: '2'
  //char next = *(s + 1);
  //if (next == '\0') { // string end
    //return 1;
  //}
  //if (next > '6') {
    //return _numDecodings(s + 1, e);
  //}
  //return _numDecodings(s + 1, e) + _numDecodings(s + 2, e);
//}
//
//int numDecodings(char* s) {
  //char *e = s + strlen(s);
  //return _numDecodings(s, e);
//}
//// #v1

// #v2
// 动态规划
int numDecodings(char* s) {
  if (!s) return 0;
  if (*s == '0') return 0;

  int len = strlen(s), i;
  char c, pre;
  int cur_cnt = 0, pre_cnt = 0, ppre_cnt = 0;

  pre_cnt = 1;
  for (i = 1; i < len; i++) {
    c = s[i];
    pre = s[i - 1];

    if (c == '0') { // c: '0'
      if (pre == '1' || pre == '2') {
        if (i - 2 >= 0) {
          cur_cnt = ppre_cnt;
        } else {
          cur_cnt = 1;
        }
      } else {
        cur_cnt = 0;
      }
    } else if (c >= '1' && c <= '6') { // c: '1' - '6'
      if (pre == '1' || pre == '2') {
        if (i - 2 >= 0) {
          cur_cnt = ppre_cnt + pre_cnt;
        } else {
          cur_cnt = 2;
        }
      } else {
        cur_cnt = pre_cnt;
      }
    } else { // c: '7' - '9'
      if (pre == '1') {
        if (i - 2 >= 0) {
          cur_cnt = ppre_cnt + pre_cnt;
        } else {
          cur_cnt = 2;
        }
      } else {
        cur_cnt = pre_cnt;
      }
    }
    ppre_cnt = pre_cnt;
    pre_cnt = cur_cnt;
  }
  return pre_cnt;
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
  char str[1000];
  read_line(str, 100, stdin);
  printf("%d\n", numDecodings(str));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
