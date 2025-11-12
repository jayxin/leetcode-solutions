#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1254. 统计封闭岛屿的数目 - 二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。
// 请返回 封闭岛屿 的数目。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png]
// 输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// 输出：2
// 解释：
// 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/07/sample_4_1610.png]
// 输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// 输出：1
// 示例 3：
// 输入：grid = [[1,1,1,1,1,1,1],
//              [1,0,0,0,0,0,1],
//              [1,0,1,1,1,0,1],
//              [1,0,1,0,1,0,1],
//              [1,0,1,1,1,0,1],
//              [1,0,0,0,0,0,1],
//              [1,1,1,1,1,1,1]]
// 输出：2
//  
// 提示：
//  * 1 <= grid.length, grid[0].length <= 100
//  * 0 <= grid[i][j] <=1

// #v1
int m, n, **a;
char **v;

bool dfs(int i, int j) {
  v[i][j] = 1;

  if (a[i][j] == 1) return true;
  if (i == m-1 || !i || j == n-1 || !j) return false;

  bool f1, f2, f3, f4;

  f1 = f2 = f3 = f4 = true;

  // down
  if (i+1 < m && !v[i+1][j]) f1 = dfs(i+1, j);
  // right
  if (j+1 < n && !v[i][j+1]) f2 = dfs(i, j+1);
  // up
  if (i-1 >= 0 && !v[i-1][j]) f3 = dfs(i-1, j);
  // left
  if (j-1 >= 0 && !v[i][j-1]) f4 = dfs(i, j-1);

  return f1 && f2 && f3 && f4;
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
  a = grid, m = gridSize, n = *gridColSize;

  char *visited[m];
  int i, j, ret = 0;

  for (i = 0; i < m; i++) {
    visited[i] = calloc(n, sizeof(char));
    memset(visited[i], 0, sizeof(char)*n);
  }
  v = visited;

  for (i = 1; i < m-1; i++) {
    for (j = 1; j <  n-1; j++) {
      if (a[i][j] == 0 && !v[i][j] && dfs(i, j)) ++ret;
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
  printf("%d\n", closedIsland(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
