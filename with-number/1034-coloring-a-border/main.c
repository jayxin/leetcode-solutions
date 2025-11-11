#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1034. 边界着 色 - 给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color 。网格中的每个值表示该位置处的网格块的颜色。
// 如果两个方块在任意 4 个方向上相邻，则称它们 相邻 。
// 如果两个方块具有相同的颜色且相邻，它们则属于同一个 连通分量 。
// 连通分量的边界 是指连通分量中满足下述条件之一的所有网格块：
//  * 在上、下、左、右任意一个方向上与不属于同一连通分量的网格块相邻
//  * 在网格的边界上（第一行/列或最后一行/列）
// 请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色。
// 并返回最终的网格 grid 。
//  
// 示例 1：
// 输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
// 输出：[[3,3],[3,2]]
// 示例 2：
// 输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
// 输出：[[1,3,3],[2,3,3]]
// 示例 3：
// 输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
// 输出：[[2,2,2],[2,1,2],[2,2,2]]
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 50
//  * 1 <= grid[i][j], color <= 1000
//  * 0 <= row < m
//  * 0 <= col < n

// #v1
int m, n, **a, d, c, **ret;
char **v;

void dfs(int i, int j) {
  v[i][j] = 1;

  if (a[i][j] != d) return ;

  if (i == m-1 || j == n-1 || i == 0 || j == 0 || a[i+1][j] != d || a[i][j+1] !=
      d || a[i-1][j] != d || a[i][j-1] != d)
    ret[i][j] = c;

  // down
  if (i+1 < m && !v[i+1][j]) dfs(i+1, j);
  // right
  if (j+1 < n && !v[i][j+1]) dfs(i, j+1);
  // up
  if (i-1 >= 0 && !v[i-1][j]) dfs(i-1, j);
  // left
  if (j-1 >= 0 && !v[i][j-1]) dfs(i, j-1);
}

int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes) {
  m = gridSize, n = *gridColSize, a = grid;
  c = color, d = a[row][col];

  *returnSize = m;
  *returnColumnSizes = calloc(m, sizeof(int));
  ret = calloc(m, sizeof(int *));

  int i, j;
  char *visited[m];

  for (i = 0; i < m; i++) {
    ret[i] = calloc(n, sizeof(int));
    (*returnColumnSizes)[i] = n;
    visited[i] = calloc(n, sizeof(char));
    memset(visited[i], 0, sizeof(char)*n);

    for (j = 0; j < n; j++) ret[i][j] = a[i][j];
  }
  v = visited;

  dfs(row, col);

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

void print_2d_arr(int **arr, int rows, int *cols) {
  if (!arr || rows <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols[i]; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

int main(int argc, char *argv[])
{
  int **image, imageSize, imageColSize, sr, sc, color, **ret, returnSize, *returnColumnSizes;
  scanf("%d%d", &imageSize, &imageColSize);
  image = read_2d_arr(imageSize, imageColSize);
  scanf("%d%d%d", &sr, &sc, &color);
  ret = colorBorder(image, imageSize, &imageColSize, sr, sc, color, &returnSize,
      &returnColumnSizes);
  print_2d_arr(ret, returnSize, returnColumnSizes);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
