#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 695. 岛 屿的最大面积 - 给你一个大小为 m x n 的二进制矩阵 grid 。
// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
// 岛屿的面积是岛上值为 1 的单元格的数目。
// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg]
// 输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 输出：6
// 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
// 示例 2：
// 输入：grid = [[0,0,0,0,0,0,0,0]]
// 输出：0
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 50
//  * grid[i][j] 为 0 或 1

// #v1
int m, n, **a, **v;

struct Direction {
  int down, right;
};

#define isValidRange(i, j) (i >= 0 && i < m && j >= 0 && j < n)

int dfs(int i, int j) {
  a[i][j] = 0;
  v[i][j] = 1;

  int ret = 1, x, y;
  struct Direction d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  for (int k = 0; k < 4; k++) {
    x = i + d[k].down;
    y = j + d[k].right;
    if (isValidRange(x, y) && !v[x][y] && a[x][y])
      ret += dfs(x, y);
  }

  return ret;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
  a = grid;
  m = gridSize, n = *gridColSize;
  int *visited[gridSize], ret = 0, candidate;

  for (int i = 0; i < m; i++) {
    visited[i] = (int *)malloc(sizeof(int) * n);
    memset(visited[i], 0, sizeof(int) * n);
  }
  v = visited;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j]) {
        candidate = dfs(i, j);
        if (candidate > ret) ret = candidate;
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
  int m, n, **a;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  printf("%d\n", maxAreaOfIsland(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
