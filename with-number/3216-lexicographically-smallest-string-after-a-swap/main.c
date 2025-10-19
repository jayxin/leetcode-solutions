#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3216. 交换后字典序最小的字符串 - 给你一个仅由数字组成的字符串 s，在最多交换一 次 相邻 且具有相同 奇偶性 的数字后，返回可以得到的字典序最小的字符串。
// 如果两个数字都是奇数或都是偶数，则它们具有相同的奇偶性。例如，5 和 9、2 和 4 奇偶性相同，而 6 和 9 奇偶性不同。
//  
// 示例 1：
// 输入： s = "45320"
// 输出： "43520"
// 解释：
// s[1] == '5' 和 s[2] == '3' 都具有相同的奇偶性，交换它们可以得到字典序最小的字符串。
// 示例 2：
// 输入： s = "001"
// 输出： "001"
// 解释：
// 无需进行交换，因为 s 已经是字典序最小的。
//  
// 提示：
//  * 2 <= s.length <= 100
//  * s 仅由数字组成。

// #v1
char* getSmallestString(char* s) {
  int n = strlen(s), m = n - 1;
  char *ret = (char *)malloc(sizeof(char) * (n + 1)), p[n+1], a, b, c;

  // init
  sprintf(ret, "%s", s);

  // compute
  for (int i = 0; i < m; i++) {
    sprintf(p, "%s", s);

    a = (p[i] - '0') & 1;
    b = (p[i+1] - '0') & 1;

    if (a == b && p[i] > p[i+1]) {
      // swap
      c = p[i];
      p[i] = p[i+1];
      p[i+1] = c;

      // compare
      if (strcmp(p, ret) < 0) sprintf(ret, "%s", p);
    }
  }

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
  read_line(s, 98, stdin);
  printf("%s\n", getSmallestString(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
