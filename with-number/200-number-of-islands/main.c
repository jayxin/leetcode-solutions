#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 200. 岛屿数量 - 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计 算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
//  
// 示例 1：
// 输入：grid = [
//   ['1','1','1','1','0'],
//   ['1','1','0','1','0'],
//   ['1','1','0','0','0'],
//   ['0','0','0','0','0']
// ]
// 输出：1
// 示例 2：
// 输入：grid = [
//   ['1','1','0','0','0'],
//   ['1','1','0','0','0'],
//   ['0','0','1','0','0'],
//   ['0','0','0','1','1']
// ]
// 输出：3
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 300
//  * grid[i][j] 的值为 '0' 或 '1'

// #v1
// dfs
char **a, **v;
int m, n, *up, *right;

#define isValidRange(i, j) (i >= 0 && i < m && j >= 0 && j < n)

void dfs(int i, int j) {
  if (v[i][j]) return ;

  v[i][j] = 1;

  int x, y;

  for (int k = 0; k < 4; k++) {
    x = i + up[k], y = j + right[k];

    if (isValidRange(x, y) && a[x][y] == '1') {
      a[x][y] = '0';
      dfs(x, y);
    }
  }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
  m = gridSize, n = *gridColSize;

  char **visited = (char **)malloc(sizeof(char *) * m);
  size_t bytes = sizeof(char) * n;
  int i, j, cnt = 0;
  int upArr[4] = {1, -1, 0, 0}, rightArr[4] = {0, 0, 1, -1};

  // allocate
  for (i = 0; i < m; i++) {
    visited[i] = (char *)malloc(bytes);
    memset(visited[i], 0, bytes);
  }

  // init
  v = visited;
  a = grid;
  up = upArr;
  right = rightArr;

  // compute
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (grid[i][j] == '1') {
        grid[i][j] = '0';
        ++cnt;
        dfs(i, j);
      }
    }
  }

  // free memory
  for (i = 0; i < m; i++) free(visited[i]);
  free(visited);
  a = v = NULL;

  return cnt;
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
  int n, m;
  char **g;
  scanf("%d %d\n", &m, &n);
  g = (char **)malloc(sizeof(char *) * m);
  for (int i = 0; i < m; i++) {
    g[i] = (char *)malloc(sizeof(char) * (n + 3));
    read_line(g[i], n + 2, stdin);
  }
  printf("%d\n", numIslands(g, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
