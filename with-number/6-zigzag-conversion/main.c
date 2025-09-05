#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 6. Z 字形变换 - 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
// P   A   H   N
// A P L S I I G
// Y   I   R
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
// 请你实现这个将字符串进行指定行数变换的函数：
// string convert(string s, int numRows);
//  
// 示例 1：
// 输入：s = "PAYPALISHIRING", numRows = 3
// 输出："PAHNAPLSIIGYIR"
// 示例 2：
// 输入：s = "PAYPALISHIRING", numRows = 4
// 输出："PINALSIGYAHRPI"
// 解释：
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// 示例 3：
// 输入：s = "A", numRows = 1
// 输出："A"
//  
// 提示：
//  * 1 <= s.length <= 1000
//  * s 由英文字母（小写和大写）、',' 和 '.' 组成
//  * 1 <= numRows <= 1000

//// #v1
//int get_cols(int len, int numRows) {
  //// 一组的字符个数
  //int group = numRows * 2 - 2;
  //// 一组的字符所占列数
  //int group_col = 1 + numRows - 2;
  //int cols = 0, q, r;
  //// 总组数
  //q = len / group;
  //// 剩余无法形成一组的字符个数
  //r = len % group;
//
  //cols += q * group_col;
  //if (r) { // 字符有剩余
    //cols += 1;
    //if (r > numRows) {
      //cols += r - numRows;
    //}
  //}
  //return cols;
//}
//
//#define DOWN 1
//#define UP -1
//
//char* convert(char *s, int numRows) {
  //int len = strlen(s), i, j, direction;
  //if (len == 1 || numRows == 1) return s;
  //int rows = numRows, cols = get_cols(len, numRows);
  //char *ret = (char *)malloc(sizeof(char) * (len + 1));
  //int retLen = 0;
  //char **tab = (char **)malloc(sizeof(char *) * rows);
  //for (i = 0; i < rows; i++) {
    //tab[i] = (char *)malloc(sizeof(char) * cols);
    //memset(tab[i], 0, sizeof(char) * cols);
  //}
  //char *p = s, *e = s + len;
  //direction = DOWN;
  //i = j = 0;
  //while (p < e) {
    //tab[i][j] = *p;
    //p++;
//
    //if (direction == DOWN) {
      //if (i == rows - 1) {
        //direction = UP;
        //i--;
        //j++;
      //} else {
        //i++;
      //}
    //} else {
      //if (i == 0) {
        //direction = DOWN;
        //i++;
      //} else {
        //i--;
        //j++;
      //}
    //}
  //}
  //for (i = 0; i < rows; i++) {
    //for (j = 0; j < cols; j++) {
      //if (tab[i][j])
        //ret[retLen++] = tab[i][j];
    //}
  //}
  //ret[retLen] = '\0';
//
  //for (i = 0; i < rows; i++) {
    //free(tab[i]);
  //}
  //free(tab);
  //return ret;
//}
//// #v1

// #v2
char* convert(char *s, int numRows) {
  int len = strlen(s);

  if (len == 1 || numRows == 1) return s;

  //int group = numRows * 2 - 2;
  int group = (numRows << 1) - 2;

  char *ret = (char *)malloc(sizeof(char) * (len + 1));
  int retLen = 0, type, i, t1, t2;

  char *p, *e = s + len;

  for (i = 0; i < numRows; i++) {
    p = s + i; // 每行的起点

    type = 1; // 初始化
    //t1 = numRows - i - 1 + numRows - i - 1;
    t1 = (numRows << 1) - (i << 1) - 2;
    t2 = group - t1;

    while (p < e) {
      ret[retLen++] = *p;

      if (i == 0 || i == numRows - 1) { // 首行和末行
        p = p + group;
      } else {
        if (type == 1) {
          p = p + t1;
          type = 2;
        } else {
          p = p + t2;
          type = 1;
        }
      }
    }
  }

  // string end
  ret[retLen] = '\0';
  return ret;
}
// #v2

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
  int n;
  scanf("%d\n", &n);
  char str[1001];
  read_line(str, 1000, stdin);
  printf("%s\n", convert(str, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
