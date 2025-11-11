#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 463. 岛屿的 周长 - 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
// 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其 中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的 正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
//  
// 示例 1：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/island.png]
// 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// 输出：16
// 解释：它的周长是上面图片中的 16 个黄色的边
// 示例 2：
// 输入：grid = [[1]]
// 输出：4
// 示例 3：
// 输入：grid = [[1,0]]
// 输出：4
//  
// 提示：
//  * row == grid.length
//  * col == grid[i].length
//  * 1 <= row, col <= 100
//  * grid[i][j] 为 0 或 1

// #v1
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
  int m = gridSize, n = *gridColSize;
  int ret = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j]) {
        //i+1, j
        if (i+1 >= m || grid[i+1][j] == 0) ++ret;
        //i, j+1
        if (j+1 >= n || grid[i][j+1] == 0) ++ret;
        //i-1, j
        if (i-1 < 0 || grid[i-1][j] == 0) ++ret;
        //i, j-1
        if (j-1 < 0 || grid[i][j-1] == 0) ++ret;
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
  int n, **a, m;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  printf("%d\n", islandPerimeter(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
