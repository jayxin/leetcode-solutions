#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2428.  沙漏的最大总和 - 给你一个大小为 m x n 的整数矩阵 grid 。
// 按以下形式将矩阵的一部分定义为一个 沙漏 ：
// [https://assets.leetcode.com/uploads/2022/08/21/img.jpg]
// 返回沙漏中元素的 最大 总和。
// 注意：沙漏无法旋转且必须整个包含在矩阵中。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2022/08/21/1.jpg]
// 输入：grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
// 输出：30
// 解释：上图中的单元格表示元素总和最大的沙漏：6 + 2 + 1 + 2 + 9 + 2 + 8 = 30 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2022/08/21/2.jpg]
// 输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：35
// 解释：上图中的单元格表示元素总和最大的沙漏：1 + 2 + 3 + 5 + 7 + 8 + 9 = 35 。
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 3 <= m, n <= 150
//  * 0 <= grid[i][j] <= 106

// #v1
int maxSum(int** grid, int gridSize, int* gridColSize) {
  int ret = 0;

  for (int i = 0; i < gridSize-2; i++) {
    for (int j = 0; j < *gridColSize-2; j++) {
      int tmp = grid[i][j] + grid[i][j+1] + grid[i][j+2] +
        grid[i+1][j+1] +
        grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
      if (tmp > ret) ret = tmp;
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
  int **a, r, c;
  scanf("%d%d", &r, &c);
  a = read_2d_arr(r, c);
  printf("%d\n", maxSum(a, r, &c));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
