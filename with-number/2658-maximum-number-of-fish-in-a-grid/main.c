#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2658. 网格图中鱼的最大数目 - 给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，其中下标在 (r, c) 处的整数表示：
//  * 如果 grid[r][c] = 0 ，那么它是一块 陆地 。
//  * 如果 grid[r][c] > 0 ，那么它是一块 水域 ，且包含 grid[r][c] 条鱼。
// 一位渔夫可以从任意 水域 格子 (r, c) 出发，然后执行以下操作任意次：
//  * 捕捞格子 (r, c) 处所有的鱼，或者
//  * 移动到相邻的 水域 格子。
// 请你返回渔夫最优策略下， 最多 可以捕捞多少条鱼。如果没有水域格子，请你返回 0 。
// 格子 (r, c) 相邻 的格子为 (r, c + 1) ，(r, c - 1) ，(r + 1, c) 和 (r - 1, c) ，前提是相邻格子在网格图内。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2023/03/29/example.png]
// 输入：grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// 输出：7
// 解释：渔夫可以从格子 (1,3) 出发，捕捞 3 条鱼，然后移动到格子 (2,3) ，捕捞 4 条鱼 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2023/03/29/example2.png]
// 输入：grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
// 输出：1
// 解释：渔夫可以从格子 (0,0) 或者 (3,3) ，捕捞 1 条鱼。
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 10
//  * 0 <= grid[i][j] <= 10

// #v1
int **a, m, n;
char **v;

int dfs(int i, int j) {
  v[i][j] = 1;

  int ret = a[i][j];

  // down
  if (i+1 < m && !v[i+1][j] && a[i+1][j]) ret += dfs(i+1, j);
  // right
  if (j+1 < n && !v[i][j+1] && a[i][j+1]) ret += dfs(i, j+1);
  // up
  if (i-1 >= 0 && !v[i-1][j] && a[i-1][j]) ret += dfs(i-1, j);
  // left
  if (j-1 >= 0 && !v[i][j-1] && a[i][j-1]) ret += dfs(i, j-1);

  return ret;
}

int findMaxFish(int** grid, int gridSize, int* gridColSize) {
  m = gridSize, n = *gridColSize;
  a = grid;

  char *visited[m];
  int ret = 0, t, i, j;

  for (i = 0; i < m; i++) {
    visited[i] = calloc(n, sizeof(int));
    memset(visited[i], 0, n*sizeof(int));
  }
  v = visited;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (grid[i][j] && !visited[i][j]) {
        t = dfs(i, j);
        if (t > ret) ret = t;
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
  printf("%d\n", findMaxFish(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
