#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2575. 找出字符串的可整除数组 - 给你一个下标从 0 开始的字符串 word ，长度为 n ， 由从 0 到 9 的数字组成。另给你一个正整数 m 。
// word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：
//  * 如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
//  * 否则，div[i] = 0
// 返回 word 的可整除数组。
//  
// 示例 1：
// 输入：word = "998244353", m = 3
// 输出：[1,1,0,0,0,1,1,0,0]
// 解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。
// 示例 2：
// 输入：word = "1010", m = 10
// 输出：[0,1,0,1]
// 解释：仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。
//  
// 提示：
//  * 1 <= n <= 105
//  * word.length == n
//  * word 由数字 0 到 9 组成
//  * 1 <= m <= 109

// #v1
// math
// (a+b) % m == (a % m + b % m) % m
int* divisibilityArray(char* word, int m, int* returnSize) {
  int n = strlen(word);
  int *ret = calloc(n, sizeof(int)), r = 0;

  for (int i = 0; i < n; i++) {
    r = (10LL * r + (word[i] & 0x0f)) % m;
    ret[i] = !r;
  }

  *returnSize = n;

  return ret;
}
// #v1

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int m, *ret, returnSize;
  char s[100];
  scanf("%d\n", &m);
  scanf("%s", s);
  ret = divisibilityArray(s, m, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
