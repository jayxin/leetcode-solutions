#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3142. 判断矩阵是否满足条件 - 给你一个大小为 m x n 的二维矩阵 grid 。你需要判断每一个格子 grid[i][j] 是否满足：
//  * 如果它下面的格子存在，那么它需要等于它下面的格子，也就是 grid[i][j] == grid[i + 1][j] 。
//  * 如果它右边的格子存在，那么它需要不等于它右边的格子，也就是 grid[i][j] != grid[i][j + 1] 。
// 如果 所有 格子都满足以上条件，那么返回 true ，否则返回 false 。
//  
// 示例 1：
// 输入：grid = [[1,0,2],[1,0,2]]
// 输出：true
// 解释：
// [https://assets.leetcode.com/uploads/2024/04/15/examplechanged.png]
// 网格图中所有格子都符合条件。
// 示例 2：
// 输入：grid = [[1,1,1],[0,0,0]]
// 输出：false
// 解释：
// [https://assets.leetcode.com/uploads/2024/03/27/example21.png]
// 同一行中的格子值都相等。
// 示例 3：
// 输入：grid = [[1],[2],[3]]
// 输出：false
// 解释：
// [https://assets.leetcode.com/uploads/2024/03/31/changed.png]
// 同一列中的格子值不相等。
//  
// 提示：
//  * 1 &lt;= n, m &lt;= 10
//  * 0 &lt;= grid[i][j] &lt;= 9

// #v1
bool satisfiesConditions(int** grid, int gridSize, int* gridColSize) {
  int i, j, m1 = gridSize - 1, n1 = *gridColSize - 1;

  for (i = 0; i < m1; i++) {
    for (j = 0; j < n1; j++) {
      if (grid[i][j] != grid[i+1][j] || grid[i][j] == grid[i][j+1]) return false;
    }
  }

  // 最后一行
  for (j = 0; j < n1; j++) {
    if (grid[m1][j] == grid[m1][j+1]) return false;
  }

  // 最后一列
  for (i = 0; i < m1; i++) {
    if (grid[i][n1] != grid[i+1][n1]) return false;
  }

  return true;
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
  int n, m, **a;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  if (satisfiesConditions(a, m, &n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
