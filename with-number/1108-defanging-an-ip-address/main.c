#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1108. IP 地址无效化 - 给你一个有效的 IPv4 [https://baike.baidu.com/item/IPv4] 地址 address，返回这个 IP 地址的无效化版本。
// 所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
//  
// 示例 1：
// 输入：address = "1.1.1.1"
// 输出："1[.]1[.]1[.]1"
// 示例 2：
// 输入：address = "255.100.50.0"
// 输出："255[.]100[.]50[.]0"
//  
// 提示：
//  * 给出的 address 是一个有效的 IPv4 地址

// #v1
char* defangIPaddr(char* address) {
  int n, retLen;
  char *p, *ret;

  // compute string length
  p = address;
  while (*p) {
    ++n;
    ++p;
  }

  // allocate
  ret = (char *)malloc(sizeof(char) * (n + 7));

  // build return value
  retLen = 0;
  p = address;
  while (*p) {
    ret[retLen++] = *p;

    if (*(p+1) == '.') {
      ret[retLen++] = '[';
    } else if (*p == '.') {
      ret[retLen++] = ']';
    }

    ++p;
  }

  // string end
  ret[retLen] = '\0';

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%s\n", defangIPaddr(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
