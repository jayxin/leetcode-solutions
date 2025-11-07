#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 541. 反转字符串 II - 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//  * 如果剩余字符少于 k 个，则将剩余字符全部反转。
//  * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//  
// 示例 1：
// 输入：s = "abcdefg", k = 2
// 输出："bacdfeg"
// 示例 2：
// 输入：s = "abcd", k = 2
// 输出："bacd"
//  
// 提示：
//  * 1 <= s.length <= 104
//  * s 仅由小写英文组成
//  * 1 <= k <= 104

//// #v1
//void reverse(char *s, char *e) {
  //char c;
  //while (s < e) {
    //c = *s;
    //*s = *e;
    //*e = c;
//
    //++s;
    //--e;
  //}
//}
//
//char* reverseStr(char* s, int k) {
  //int k2 = k<<1, c = 0;
  //char *p = s, *q = s;
//
  //while (*q) {
    //++c;
//
    //if (c == k2) {
      //reverse(p, p+k-1);
//
      //// update
      //p = q + 1;
      //c = 0;
    //} else if (*(q+1) == '\0') { // string end
      //if (c < k) reverse(p, q);
      //else reverse(p, p+k-1);
    //}
//
    //// forward
    //++q;
  //}
//
  //return s;
//}
//// #v1

// #v2
#define min(a, b) ((a) <= (b) ? (a) : (b))

void reverse(char *s, char *e) {
  char c;
  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;

    ++s;
    --e;
  }
}

char* reverseStr(char* s, int k) {
  int k2 = k<<1, c = 0, t;
  char *p = s, *q = s;

  while (*q) {
    ++c;

    if (c == k2 || *(q+1) == '\0') {
      t = min(c-1, k-1);

      reverse(p, p+t);

      // update
      p = q + 1;
      c = 0;
    }

    // forward
    ++q;
  }

  return s;
}
// #v2

int main(int argc, char *argv[])
{
  int k;
  char s[100];
  scanf("%d\n", &k);
  scanf("%s", s);
  printf("%s\n", reverseStr(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
