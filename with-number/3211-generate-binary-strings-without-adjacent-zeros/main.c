#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3211. 生成不含相邻零的二进制字符串 - 给你一个正整数 n。
// 如果一个二进制字符串 x 的所有长度为 2 的子字符串中包含 至少 一个 "1"， 则称 x 是一个 有效 字符串。
// 返回所有长度为 n 的 有效 字符串，可以以任意顺序排列。
//  
// 示例 1：
// 输入： n = 3
// 输出： ["010","011","101","110","111"]
// 解释：
// 长度为 3 的有效字符串有："010"、"011"、"101"、"110" 和 "111"。
// 示例 2：
// 输入： n = 1
// 输出： ["0","1"]
// 解释：
// 长度为 1 的有效字符串有："0" 和 "1"。
//  
// 提示：
//  * 1 <= n <= 18

// #v1
char *t, **ret;
int retLen, nn, bytes;

void gen(int len) {
  if (len == nn) {
    ret[retLen] = (char *)malloc(bytes);
    sprintf(ret[retLen], "%s", t);
    ++retLen;
    return ;
  }

  if (!len || t[len-1] == '1') {
    t[len] = '0';
    gen(len+1);
  }

  t[len] = '1';
  gen(len+1);
}

char** validStrings(int n, int* returnSize) {
  char tmp[n+1];

  retLen = 0;
  nn = n;
  ret = (char **)malloc(sizeof(char *) * (1<<n));
  t = tmp;
  t[n] = '\0';
  bytes = sizeof(tmp);

  gen(0);
  *returnSize = retLen;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n, s;
  char **ret;
  scanf("%d", &n);
  ret = validStrings(n, &s);
  for (int i = 0; i < s; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
