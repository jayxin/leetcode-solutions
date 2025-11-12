#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1020. 飞地 的数量 - 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg]
// 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// 输出：3
// 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg]
// 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// 输出：0
// 解释：所有 1 都在边界上或可以到达边界。
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 500
//  * grid[i][j] 的值为 0 或 1

// #v1
int m, n, **a;
char **v;

bool check(int i, int j, int *oneCnt) {
  if (a[i][j] == 0) return false;

  if (i == m-1 || !i || j == n-1 || !j) return true;

  v[i][j] = 1;
  *oneCnt += 1;

  bool f1, f2, f3, f4;

  f1 = f2 = f3 = f4 = false;

  // down
  if (i+1 < m && !v[i+1][j]) f1 = check(i+1, j, oneCnt);
  // right
  if (j+1 < n && !v[i][j+1]) f2 = check(i, j+1, oneCnt);
  // up
  if (i-1 >= 0 && !v[i-1][j]) f3 = check(i-1, j, oneCnt);
  // left
  if (j-1 >= 0 && !v[i][j-1]) f4 = check(i, j-1, oneCnt);

  return f1 || f2 || f3 || f4;
}

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
  a = grid, m = gridSize, n = *gridColSize;

  char *visited[m];
  int i, j, ret = 0;

  for (i = 0; i < m; i++) {
    visited[i] = calloc(n, sizeof(char));
    memset(visited[i], 0, sizeof(char)*n);
  }
  v = visited;

  int c;
  for (i = 1; i < m-1; i++) {
    for (j = 1; j <  n-1; j++) {
      if (a[i][j] && !v[i][j]) {
         c = 0;
         if (!check(i, j, &c)) ret += c;
      }
    }
  }

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
  int **a, m, n;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  printf("%d\n", numEnclaves(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
