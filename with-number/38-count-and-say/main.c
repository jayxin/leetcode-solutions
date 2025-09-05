#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 38. 外观数列
// 「外观数列」是一个数位字符串序列，由递归公式定义：
//
//     countAndSay(1) = "1"
//     countAndSay(n) 是 countAndSay(n-1) 的行程长度编码。
//
//
// 行程长度编码（RLE）是一种字符串压缩方法，
// 其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数
// （运行长度）和字符的串联。
// 例如，要压缩字符串 "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11" 替换。因此压缩后字符串变为 "23321511"。
//
// 给定一个整数 n ，返回 外观数列 的第 n 个元素。

//// #v1
//int* get_digit(int n, int *returnSize) {
  //int *arr = (int *)malloc(sizeof(int) * 10);
  //int len = 0;
  //while (n) {
    //arr[len++] = n % 10;
    //n /= 10;
  //}
  //*returnSize = len;
  //return arr;
//}
//
//char* rle_encoding(char *str) {
  //int len = strlen(str), ret_len = 0, cnt = 0;
  //char *s = str, *e = str + len,
       //*ret = (char *)malloc(sizeof(char) * 2 * len + 1);
  //char c = *s;
//
  //while (s < e) {
    //if (c != *s) {
      //int digits_len = 0;
      //int *digits = get_digit(cnt, &digits_len);
      //for (int i = digits_len - 1; i >= 0; --i) {
        //ret[ret_len++] = '0' + digits[i];
      //}
      //free(digits);
//
      //ret[ret_len++] = c;
//
      //cnt = 1;
      //c = *s;
    //} else {
      //cnt++;
    //}
    //s++;
  //}
//
  //// last part
  //int digits_len = 0;
  //int *digits = get_digit(cnt, &digits_len);
  //for (int i = digits_len - 1; i >= 0; --i) {
    //ret[ret_len++] = '0' + digits[i];
  //}
  //free(digits);
  //ret[ret_len++] = c;
//
  //// string end
  //ret[ret_len] = '\0';
  //return ret;
//}
//
//char* countAndSay(int n) {
  //if (n == 1) {
    //char *ret = (char *)malloc(sizeof(char) * 2);
    //ret[0] = '1';
    //ret[1] = '\0';
    //return ret;
  //}
//
  //return rle_encoding(countAndSay(n - 1));
//}
//// #v1

// #v2
int *arr;
int* get_digit(int n, int *returnSize) {
  int len = 0;
  while (n) {
    arr[len++] = n % 10;
    n /= 10;
  }
  *returnSize = len;
  return arr;
}

char* rle_encoding(char *str) {
  int len = strlen(str), ret_len = 0, cnt = 0;
  char *s = str, *e = str + len,
       *ret = (char *)malloc(sizeof(char) * 2 * len + 1);
  char c = *s;

  while (s < e) {
    if (c != *s) {
      int digits_len = 0;
      int *digits = get_digit(cnt, &digits_len);
      for (int i = digits_len - 1; i >= 0; --i) {
        ret[ret_len++] = '0' + digits[i];
      }

      ret[ret_len++] = c;

      cnt = 1;
      c = *s;
    } else {
      cnt++;
    }
    s++;
  }

  // last part
  int digits_len = 0;
  int *digits = get_digit(cnt, &digits_len);
  for (int i = digits_len - 1; i >= 0; --i) {
    ret[ret_len++] = '0' + digits[i];
  }
  ret[ret_len++] = c;

  // string end
  ret[ret_len] = '\0';
  return ret;
}

char* countAndSay(int n) {
  char *ret = (char *)malloc(sizeof(char) * 2);
  ret[0] = '1';
  ret[1] = '\0';

  if (n == 1) {
    return ret;
  }
  char *str;
  arr = (int *)malloc(sizeof(int) * 10);

  while (--n) {
    str = rle_encoding(ret);
    free(ret);
    ret = str;
  }

  return ret;
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", countAndSay(n));

  //printf("%s\n", rle_encoding("21"));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
