#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 405. 数字转换为十六进制数 - 给定一个整数，编写一个算法将这个数转换为十六进制数。对 于负整数，我们通常使用 补码运算 [https://baike.baidu.com/item/%E8%A1%A5%E7%A0%81/6854613?fr=aladdin] 方法。
// 答案字符串中的所有字母都应该是小写字符，并且除了 0 本身之外，答案中不应该有任何前置零。
// 注意: 不允许使用任何由库提供的将数字直接转换或格式化为十六进制的方法来解决这个问 题。
//  
// 示例 1：
// 输入：num = 26
// 输出："1a"
// 示例 2：
// 输入：num = -1
// 输出："ffffffff"
//  
// 提示：
//  * -2^31 &lt;= num &lt;= 2^31 - 1

// #v1
int char2Int(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  return c - 'a' + 10;
}

char* toHex(int num) {
  char t[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
  char t1[16] = {'f', 'e', 'd', 'c', 'b', 'a', '9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
  char *ret = (char *)malloc(sizeof(char) * 10), *s, *e, c;
  int retLen = 0, i;
  int64_t n = num;

  if (num < 0) {
    n = -n;
  } else if (num == 0) {
    ret[0] = '0';
    ret[1] = '\0';
    return ret;
  }

  while (n) {
    ret[retLen++] = t[n % 16];
    n /= 16;
  }

  // string end
  ret[retLen] = '\0';

  // 取反
  if (num < 0) {
    // 补 0
    while (retLen < 8) ret[retLen++] = '0';

    // string end
    ret[retLen] = '\0';

    // 取反
    for (i = 0; i < retLen; i++) {
      ret[i] = t1[char2Int(ret[i])];
    }
  }

  s = ret;
  e = ret + retLen - 1;

  // reverse string
  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;
    ++s;
    --e;
  }

  // + 1
  if (num < 0) {
    int carray = 1, v;

    for (i = 7; i >= 0; i--) {
      v = char2Int(ret[i]) + carray;
      carray = v / 16;
      v %= 16;
      ret[i] = t[v];
    }
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", toHex(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
