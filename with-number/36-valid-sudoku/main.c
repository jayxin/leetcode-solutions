#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 36. 有效的数独
// 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//
//     数字 1-9 在每一行只能出现一次。
//     数字 1-9 在每一列只能出现一次。
//     数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

// 注意：
//
//     一个有效的数独（部分已被填充）不一定是可解的。
//     只需要根据以上规则，验证已经填入的数字是否有效即可。
//     空白格用 '.' 表示。

//  board.length == 9
//  board[i].length == 9
//  board[i][j] 是一位数字（1-9）或者 '.'

// #v1
bool checkLine(char *s, char *e) {
  char table[10], c;
  memset(table, 0, 10 * sizeof(char));
  while (s <= e) {
    c = *s;
    if (isdigit(c)) {
      if (table[c - '0']) {
        return false;
      }
      table[c - '0'] = 1;
    }
    s++;
  }
  return true;
}

bool checkColumn(char **board, int p, int q) {
  char table[10], c;
  int i;
  memset(table, 0, 10 * sizeof(char));
  for (i = p; i < p + 9; i++) {
    c = board[i][q];
    if (isdigit(c)) {
      if (table[c - '0']) {
        return false;
      }
      table[c - '0'] = 1;
    }
  }
  return true;
}

bool check3X3(char **board, int p, int q) {
  char table[10], c;
  int i, j;
  memset(table, 0, 10 * sizeof(char));
  for (i = p; i < p + 3; i++) {
    for (j = q; j < q + 3; j++) {
      c = board[i][j];
      if (isdigit(c)) {
        if (table[c - '0']) {
          return false;
        }
        table[c - '0'] = 1;
      }
    }
  }
  return true;
}

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
  int i, j;
  // check line
  for (i = 0; i < boardSize; i++) {
    if (!checkLine(&board[i][0], &board[i][boardSize - 1])) {
      return false;
    }
  }
  // check column
  for (i = 0; i < *boardColSize; i++) {
    if (!checkColumn(board, 0, i)) {
      return false;
    }
  }
  // check 3x3
  for (i = 0; i < boardSize; i += 3) {
    for (j = 0; j < *boardColSize; j += 3) {
      if (!check3X3(board, i, j)) {
        return false;
      }
    }
  }
  return true;
}
// #v1

int main(int argc, char *argv[])
{
  int rows = 9, cols = 9;
  char c;
  char **p = (char **)malloc(sizeof(char *) * 9);
  for (int i = 0; i < 9; i++) {
    p[i] = (char *)malloc(sizeof(char) * 9);
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      c = getchar();
      if (c == '\n') {
        j--;
        continue;
      }
      p[i][j] = c;
    }
  }
  printf("%d\n", isValidSudoku(p, rows, &cols));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
