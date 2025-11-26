#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2435. 矩阵中和能被 K 整除的路径 - 给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。你从起点 (0, 0) 出发，每一步只能往 下 或者往 右 ，你想要到达终点 (m - 1, n - 1) 。
// 请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 109 + 7 取余 的结果。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2022/08/13/image-20220813183124-1.png]
// 输入：grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
// 输出：2
// 解释：有两条路径满足路径上元素的和能被 k 整除。
// 第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3 整除。
// 第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被 3 整除。
// 示例 2：
// [https://assets.leetcode.com/uploads/2022/08/17/image-20220817112930-3.png]
// 输入：grid = [[0,0]], k = 5
// 输出：1
// 解释：红色标注的路径和为 0 + 0 = 0 ，能被 5 整除。
// 示例 3：
// [https://assets.leetcode.com/uploads/2022/08/12/image-20220812224605-3.png]
// 输入：grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
// 输出：10
// 解释：每个数字都能被 1 整除，所以每一条路径的和都能被 k 整除。
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 5 * 104
//  * 1 <= m * n <= 5 * 104
//  * 0 <= grid[i][j] <= 100
//  * 1 <= k <= 50

// #v1
#define MOD 1000000007

int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k) {
  int m = gridSize, n = *gridColSize;
  // dp[i][j][l] 表示到达 grid[i-1][j-1] 处且 (路径上数字和 % k) 的结果为 l 的路径数目
  int dp[m+1][n+1][k];

  // dp[1][1][0...(k-1)] 单独初始化
  for (int l = 0; l < k; l++) dp[1][1][l] = 0;
  // 表示到达 grid[0][0] 且路径上数字和 % k 的结果为 grid[0][0] % k 的路径数目为 1
  dp[1][1][grid[0][0] % k] = 1;

  // dp[2...m][1][0...(k-1)] 初始化
  for (int i = 2; i <= m; i++) {
    int r = grid[i-1][0] % k;
    for (int l = 0; l < k; l++) {
      // (t + r) % k == l
      int t = (l - r + k) % k;
      dp[i][1][l] = dp[i-1][1][t];
    }
  }

  // dp[1][2...n][0...(k-1)] 初始化
  for (int j = 2; j <= n; j++) {
    int r = grid[0][j-1] % k;
    for (int l = 0; l < k; l++) {
      // (t + r) % k == l
      int t = (l - r + k) % k;
      dp[1][j][l] = dp[1][j-1][t];
    }
  }

  for (int i = 2; i <= m; i++) {
    for (int j = 2; j <= n; j++) {
      int r = grid[i-1][j-1] % k;

      for (int l = 0; l < k; l++) {
        // (t + r) % k == l
        int t = (l - r + k) % k;
        //printf("(%d, %d) => %d\n", t, r, l);
        dp[i][j][l] = (dp[i-1][j][t] + dp[i][j-1][t]) % MOD;
      }
    }
  }

  return dp[m][n][0];
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
  int n, m, k, **a;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  scanf("%d", &k);
  printf("%d\n", numberOfPaths(a, m, &n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
