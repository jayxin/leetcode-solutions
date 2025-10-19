#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1404. 将二进制表示减到 1 的步骤数 - 给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：
//  * 如果当前数字为偶数，则将其除以 2 。
//  * 如果当前数字为奇数，则将其加上 1 。
// 题目保证你总是可以按上述规则将测试用例变为 1 。
//  
// 示例 1：
// 输入：s = "1101"
// 输出：6
// 解释："1101" 表示十进制数 13 。
// Step 1) 13 是奇数，加 1 得到 14 
// Step 2) 14 是偶数，除 2 得到 7
// Step 3) 7  是奇数，加 1 得到 8
// Step 4) 8  是偶数，除 2 得到 4 
// Step 5) 4  是偶数，除 2 得到 2 
// Step 6) 2  是偶数，除 2 得到 1 
// 示例 2：
// 输入：s = "10"
// 输出：1
// 解释："10" 表示十进制数 2 。
// Step 1) 2 是偶数，除 2 得到 1
// 示例 3：
// 输入：s = "1"
// 输出：0
//  
// 提示：
//  * 1 <= s.length <= 500
//  * s 由字符 '0' 或 '1' 组成。
//  * s[0] == '1'

// #v1
int plusOne(char *s, int len) {
  int carry, a, end = len - 1;

  // 加 1
  s[end] = '0';
  carry = 1;

  for (int i = end - 1; i >= 0; i--) {
    a = s[i] - '0' + carry;
    s[i] = '0' + a % 2;
    carry = a / 2;
  }

  if (carry) {
    for (int i = end; i >= 0; i--) s[i+1] = s[i];

    // 新增 1 位
    s[0] = '1';

    // string end
    s[len + 1] = '\0';
    // update length
    ++len;
  }

  return len;
}

int numSteps(char* s) {
  int n = strlen(s), pLen = n, cnt = 0;
  char p[2*n+1];

  sprintf(p, "%s", s);

  while (pLen != 1) {
    if (p[pLen-1] == '0') { // 偶数
      p[--pLen] = '\0';
    } else { // 奇数
      pLen = plusOne(p, pLen);
    }

    ++cnt;
  }

  return cnt;
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
  printf("%d\n", numSteps(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
