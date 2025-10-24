#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 63. 不同路径 II - 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]） 。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移 动一步。
// 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障 碍物的方格。
// 返回机器人能够到达右下角的不同路径数量。
// 测试用例保证答案小于等于 2 * 109。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg]
// 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：2
// 解释：3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -&gt; 向右 -&gt; 向下 -&gt; 向下
// 2. 向下 -&gt; 向下 -&gt; 向右 -&gt; 向右
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg]
// 输入：obstacleGrid = [[0,1],[0,0]]
// 输出：1
//  
// 提示：
//  * m == obstacleGrid.length
//  * n == obstacleGrid[i].length
//  * 1 <= m, n <= 100
//  * obstacleGrid[i][j] 为 0 或 1

// #v1
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
  // NOTE: edge case
  if (obstacleGrid[0][0]) return 0;

  // edge case
  if (obstacleGridSize == 1 || *obstacleGridColSize == 1) {
    for (int i = 0; i < obstacleGridSize; i++) {
      for (int j = 0; j < *obstacleGridColSize; j++) {
        if (obstacleGrid[i][j]) return 0;
      }
    }

    return 1;
  }

  int m = obstacleGridSize, n = *obstacleGridColSize;
  int dp[m][n], i, j;

  // init
  dp[0][0] = 1;
  for (i = 1; i < m; i++) {
    dp[i][0] = 0;
    if (!obstacleGrid[i][0]) dp[i][0] = dp[i-1][0];
  }
  for (j = 1; j < n; j++) {
    dp[0][j] = 0;
    if (!obstacleGrid[0][j]) dp[0][j] = dp[0][j-1];
  }

  // compute
  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      dp[i][j] = 0;

      if (!obstacleGrid[i][j]) {
        if (i-1 >= 0) dp[i][j] += dp[i-1][j];
        if (j-1 >= 0) dp[i][j] += dp[i][j-1];
      }
    }
  }

  return dp[m-1][n-1];
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
  printf("%d\n", uniquePathsWithObstacles(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
