#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3274. 检查棋盘方格颜色是否相同 - 给你两个字符串 coordinate1 和 coordinate2，代表 8 x 8 国际象棋棋盘上的两个方格的坐标。
// 以下是棋盘的参考图。
// [https://assets.leetcode.com/uploads/2024/07/17/screenshot-2021-02-20-at-22159-pm.png]
// 如果这两个方格颜色相同，返回 true，否则返回 false。
// 坐标总是表示有效的棋盘方格。坐标的格式总是先字母（表示列），再数字（表示行）。
//  
// 示例 1：
// 输入： coordinate1 = "a1", coordinate2 = "c3"
// 输出： true
// 解释：
// 两个方格均为黑色。
// 示例 2：
// 输入： coordinate1 = "a1", coordinate2 = "h3"
// 输出： false
// 解释：
// 方格 "a1" 是黑色，而 "h3" 是白色。
//  
// 提示：
//  * coordinate1.length == coordinate2.length == 2
//  * 'a' <= coordinate1[0], coordinate2[0] <= 'h'
//  * '1' <= coordinate1[1], coordinate2[1] <= '8'

// #v1
bool checkTwoChessboards(char* coordinate1, char* coordinate2) {
  char board[8][9];

  for (int i = 0; i < 8; i++) {
    char t = i & 1;

    for (int j = 1; j <= 8; j++) {
      board[i][j] = t;

      t = !t;
    }
  }

  return board[coordinate1[0] - 'a'][coordinate1[1] - '0'] ==
    board[coordinate2[0] - 'a'][coordinate2[1] - '0'];
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
  char s1[20], s2[20];
  read_line(s1, 18, stdin);
  read_line(s2, 18, stdin);
  if (checkTwoChessboards(s1, s2))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
