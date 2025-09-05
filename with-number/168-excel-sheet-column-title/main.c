#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 168. Excel 表列名称
// 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
//
// 例如：
//
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...
// 1 <= columnNumber <= 2^31 - 1

// #v1
char* convertToTitle(int columnNumber) {
  char *ret = (char *)malloc(sizeof(char) * 10);
  char c;
  int len = 0, r;
  while (columnNumber) {
    r = columnNumber % 26;
    if (r == 0) {
      r = 26;
      columnNumber--; // notice!
    }
    ret[len++] = 'A' + r - 1;
    columnNumber /= 26;
  }
  ret[len] = '\0';
  for (int i = 0; i <  len / 2; i++) {
    c = ret[i];
    ret[i] = ret[len - i - 1];
    ret[len - i - 1] = c;
  }
  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", convertToTitle(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
