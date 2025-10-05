#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 79. 单词搜索 - 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中 ，返回 true ；否则，返回 false 。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相 邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/11/04/word2.jpg]
// 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCCED"
// 输出：true
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg]
// 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "SEE"
// 输出：true
// 示例 3：
// [https://assets.leetcode.com/uploads/2020/10/15/word3.jpg]
// 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCB"
// 输出：false
//  
// 提示：
//  * m == board.length
//  * n = board[i].length
//  * 1 &lt;= m, n &lt;= 6
//  * 1 &lt;= word.length &lt;= 15
//  * board 和 word 仅由大小写英文字母组成
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？

// #v1
char **isVisited, **a;
int m, n;

#define isValidRange(i, j) (i >= 0 && i < m && j >= 0 && j < n)

bool _exist(int i, int j, char *w) {
  isVisited[i][j] = 1;

  ++w;
  int x, y = j;
  char nextChar = *w;

  if (nextChar == '\0') return true;

  // down
  x = i + 1;
  if (isValidRange(x, y) && !isVisited[x][y]) {
    if (nextChar == a[x][y] && _exist(x, y, w)) return true;
  }

  // up
  x = i - 1;
  if (isValidRange(x, y) && !isVisited[x][y]) {
    if (nextChar == a[x][y] && _exist(x, y, w)) return true;
  }

  // left
  x = i;
  y = j - 1;
  if (isValidRange(x, y) && !isVisited[x][y]) {
    if (nextChar == a[x][y] && _exist(x, y, w)) return true;
  }

  // right
  y = j + 1;
  if (isValidRange(x, y) && !isVisited[x][y]) {
    if (nextChar == a[x][y] && _exist(x, y, w)) return true;
  }

  isVisited[i][j] = 0;

  return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
  //if (!board || !word || *word == '\0') return false;

  a = board;
  m = boardSize, n = *boardColSize;

  int i, j, l = sizeof(char) * n;
  char **v = (char **)malloc(sizeof(char *) * m), c = *word;

  isVisited = v;
  for (i = 0; i < m; i++) {
    v[i] = (char *)malloc(l);
    memset(v[i], 0, l);
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (c == board[i][j] && _exist(i, j, word)) return true;
    }
  }

  return false;
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

// read 2d array
char** read_2d_arr(int rows, int cols) {
  int i, j;
  char **ret = (char **)malloc(sizeof(char *) * rows);
  for (i = 0; i < rows; i++) ret[i] = (char *)malloc(sizeof(char) * cols);

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      ret[i][j] = getchar();
    }
    getchar();
  }

  return ret;
}

int main(int argc, char *argv[])
{
  int m, n;
  char **b, w[50];
  read_line(w, 49, stdin);
  scanf("%d%d\n", &m, &n);
  b = read_2d_arr(m, n);
  if (exist(b, m, &n, w)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
