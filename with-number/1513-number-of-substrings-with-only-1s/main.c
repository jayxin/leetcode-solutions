#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1513. 仅含 1 的子串数 - 给你一个二进制字符串 s（仅由 '0' 和 '1' 组 成的字符串）。
// 返回所有字符都为 1 的子字符串的数目。
// 由于答案可能很大，请你将它对 10^9 + 7 取模后返回。
//  
// 示例 1：
// 输入：s = "0110111"
// 输出：9
// 解释：共有 9 个子字符串仅由 '1' 组成
// "1" -> 5 次
// "11" -> 3 次
// "111" -> 1 次
// 示例 2：
// 输入：s = "101"
// 输出：2
// 解释：子字符串 "1" 在 s 中共出现 2 次
// 示例 3：
// 输入：s = "111111"
// 输出：21
// 解释：每个子字符串都仅由 '1' 组成
// 示例 4：
// 输入：s = "000"
// 输出：0
//  
// 提示：
//  * s[i] == '0' 或 s[i] == '1'
//  * 1 <= s.length <= 10^5

// #v1
int numSub(char* s) {
  const int mod = 1000000007;
  int ret = 0, oneCnt = 0, a, b;

  while (*s) {
    if (*s == '0') {
      if (oneCnt & 1) {
        a = ((oneCnt + 1) >> 1) % mod;
        b = oneCnt % mod;
      } else {
        a = (oneCnt + 1) % mod;
        b = (oneCnt >> 1) % mod;
      }
      ret += (int64_t)a * b % mod;

      // reset
      oneCnt = 0;
    } else {
      // count
      ++oneCnt;
    }

    ++s;
  }

  if (oneCnt & 1) {
    a = ((oneCnt + 1) >> 1) % mod;
    b = oneCnt % mod;
  } else {
    a = (oneCnt + 1) % mod;
    b = (oneCnt >> 1) % mod;
  }
  ret += (int64_t)a * b % mod;

  return ret;
}
// #v1

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
  char s[100];
  read_line(s, 99, stdin);
  printf("%d\n", numSub(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
