#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1905. 统计 子岛屿 - 给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。 任何矩阵以外的区域都视为水域。
// 如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿  。
// 请你返回 grid2 中 子岛屿 的 数目 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/06/10/test1.png]
// 输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// 输出：3
// 解释：如上图所示，左边为 grid1 ，右边为 grid2 。
// grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png]
// 输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// 输出：2
// 解释：如上图所示，左边为 grid1 ，右边为 grid2 。
// grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
//  
// 提示：
//  * m == grid1.length == grid2.length
//  * n == grid1[i].length == grid2[i].length
//  * 1 <= m, n <= 500
//  * grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。

// #v1
int **a0, **a1, m, n;
char **v;

bool isSubland(int i, int j) {
  v[i][j] = 1;

  if (a1[i][j] == 0) return true;

  bool f1, f2, f3, f4;

  f1 = f2 = f3 = f4 = true;

  // down
  if (i+1 < m && !v[i+1][j]) f1 = isSubland(i+1, j);
  // right
  if (j+1 < n && !v[i][j+1]) f2 = isSubland(i, j+1);
  // up
  if (i-1 >= 0 && !v[i-1][j]) f3 = isSubland(i-1, j);
  // left
  if (j-1 >= 0 && !v[i][j-1]) f4 = isSubland(i, j-1);

  return a0[i][j] == a1[i][j] && f1 && f2 && f3 && f4;
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
  a0 = grid1, a1 = grid2;
  m = grid1Size, n = *grid1ColSize;

  char *visited[m];
  int ret = 0;
  int i, j;

  for (i = 0; i < m; i++) {
    visited[i] = calloc(n, sizeof(char));
    memset(visited[i], 0, sizeof(char)*n);
  }
  v = visited;

  for (i = 0; i < m; i++) {
    for (j = 0; j <  n; j++) {
      if (a1[i][j] && !v[i][j] && isSubland(i, j)) ++ret;
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
  int **a0, **a1, m0, n0, m1, n1;
  scanf("%d%d", &m0, &n0);
  a0 = read_2d_arr(m0, n0);
  scanf("%d%d", &m1, &n1);
  a1 = read_2d_arr(m1, n1);
  printf("%d\n", countSubIslands(a0, m0, &n0, a1, m1, &n1));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
