#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3210. 找出加密后的字符串 - 给你一个字符串 s 和一个整数 k。请你使用以下算法加密字符串：
//  * 对于字符串 s 中的每个字符 c，用字符串中 c 后面的第 k 个字符替换 c（以循环方式 ）。
// 返回加密后的字符串。
//  
// 示例 1：
// 输入： s = "dart", k = 3
// 输出： "tdar"
// 解释：
//  * 对于 i = 0，'d' 后面的第 3 个字符是 't'。
//  * 对于 i = 1，'a' 后面的第 3 个字符是 'd'。
//  * 对于 i = 2，'r' 后面的第 3 个字符是 'a'。
//  * 对于 i = 3，'t' 后面的第 3 个字符是 'r'。
// 示例 2：
// 输入： s = "aaa", k = 1
// 输出： "aaa"
// 解释：
// 由于所有字符都相同，加密后的字符串也将相同。
//  
// 提示：
//  * 1 <= s.length <= 100
//  * 1 <= k <= 104
//  * s 仅由小写英文字母组成。

// #v1
char* getEncryptedString(char* s, int k) {
  int n = strlen(s);
  char *ret = calloc(n+1, sizeof(char));

  ret[n] = '\0';

  for (int i = 0; i < n; i++) {
    ret[i] = s[(i + k) % n];
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int k;
  char s[100];
  scanf("%s", s);
  scanf("%s", &k);
  printf("%s\n", getEncryptedString(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
