#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3619. 总价值可以被 K 整除的岛屿数目 - 给你一个 m x n 的矩阵 grid 和一个正整数 k。一个 岛屿 是由 正 整数（表示陆地）组成的，并且陆地间 四周 连通（水平或垂 直）。
// 一个岛屿的总价值是该岛屿中所有单元格的值之和。
// 返回总价值可以被 k 整除 的岛屿数量。
//  
// 示例 1:
// [https://assets.leetcode.com/uploads/2025/03/06/example1griddrawio-1.png]
// 输入: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
// 输出: 2
// 解释:
// 网格中包含四个岛屿。蓝色高亮显示的岛屿的总价值可以被 5 整除，而红色高亮显示的岛屿则不能。
// 示例 2:
// [https://assets.leetcode.com/uploads/2025/03/06/example2griddrawio.png]
// 输入: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
// 输出: 6
// 解释:
// 网格中包含六个岛屿，每个岛屿的总价值都可以被 3 整除。
//  
// 提示:
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 1000
//  * 1 <= m * n <= 105
//  * 0 <= grid[i][j] <= 106
//  * 1 <= k < = 106

// #v1
int m, n, **a, kk;
char **v;

int dfs(int i, int j) {
  v[i][j] = 1;

  // edge case
  if (!a[i][j]) return 0;

  int ret = a[i][j] % kk;

  // down
  if (i+1 < m && !v[i+1][j]) ret += dfs(i+1, j);
  // right
  if (j+1 < n && !v[i][j+1]) ret += dfs(i, j+1);
  // up
  if (i-1 >= 0 && !v[i-1][j]) ret += dfs(i-1, j);
  // left
  if (j-1 >= 0 && !v[i][j-1]) ret += dfs(i, j-1);

  return ret % kk;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
  a = grid;
  m = gridSize, n = *gridColSize;
  kk = k;

  char *visited[m];
  int ret = 0, i, j;

  // init
  for (i = 0; i < m; i++) {
    visited[i] = calloc(n, sizeof(char));
    memset(visited[i], 0, n*sizeof(char));
  }
  v = visited;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (grid[i][j] && !visited[i][j] && dfs(i, j) == 0) ++ret;
    }
  }

  for (i = 0; i < m; i++) free(visited[i]);

  return ret;
}
// #v1

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int m, n, **a, k;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  scanf("%d", &k);
  printf("%d\n", countIslands(a, m, &n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
