#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1219. 黄金矿 工 - 你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
// 为了使收益最大化，矿工需要按以下规则来开采黄金：
//  * 每当矿工进入一个单元，就会收集该单元格中的所有黄金。
//  * 矿工每次可以从当前位置向上下左右四个方向走。
//  * 每个单元格只能被开采（进入）一次。
//  * 不得开采（进入）黄金数目为 0 的单元格。
//  * 矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
//  
// 示例 1：
// 输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
// 输出：24
// 解释：
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// 一种收集最多黄金的路线是：9 -> 8 -> 7。
// 示例 2：
// 输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
// 输出：28
// 解释：
// [[1,0,7],
//  [2,0,6],
//  [3,4,5],
//  [0,3,0],
//  [9,0,20]]
// 一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
//  
// 提示：
//  * 1 <= grid.length, grid[i].length <= 15
//  * 0 <= grid[i][j] <= 100
//  * 最多 25 个单元格中有黄金。

// #v1
int **a, m, n;
char **v;

int dfs(int i, int j) {
  v[i][j] = 1;

  int ret = 0, t, x;

  x = i+1;
  if (x < m) {
    if (!v[x][j] && a[x][j]) {
      t = dfs(x, j);
      if (t > ret) ret = t;
    }
  }

  x = i-1;
  if (x >= 0) {
    if (!v[x][j] && a[x][j]) {
      t = dfs(x, j);
      if (t > ret) ret = t;
    }
  }

  x = j-1;
  if (x >= 0) {
    if (!v[i][x] && a[i][x]) {
      t = dfs(i, x);
      if (t > ret) ret = t;
    }
  }

  x = j+1;
  if (x < n) {
    if (!v[i][x] && a[i][x]) {
      t = dfs(i, x);
      if (t > ret) ret = t;
    }
  }

  v[i][j] = 0;
  ret += a[i][j];

  return ret;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
  a = grid;
  m = gridSize;
  n = *gridColSize;
  int maxGold = 0, tmp, i, j;
  char *visited[m];

  for (i = 0; i < m; i++) {
    visited[i] = (char *)malloc(sizeof(char) * n);
    memset(visited[i], 0, sizeof(char) * n);
  }
  v = (char **)visited;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      if (grid[i][j]) {
        tmp = dfs(i, j);
        if (tmp > maxGold) maxGold = tmp;
      }

  return maxGold;
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
  printf("%d\n", getMaximumGold(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
