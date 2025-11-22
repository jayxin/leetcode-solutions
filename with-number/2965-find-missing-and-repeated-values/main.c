#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2965. 找出缺失和重复的数字 - 给你一个下标从 0 开始的二维整数矩阵 grid，大小为 n * n ，其中的值在 [1, n2] 范围内。除了 a 出现 两次，b 缺失 之外，每个整数都 恰好出现一次 。
// 任务是找出重复的数字a 和缺失的数字 b 。
// 返回一个下标从 0 开始、长度为 2 的整数数组 ans ，其中 ans[0] 等于 a ，ans[1] 等于 b 。
//  
// 示例 1：
// 输入：grid = [[1,3],[2,2]]
// 输出：[2,4]
// 解释：数字 2 重复，数字 4 缺失，所以答案是 [2,4] 。
// 示例 2：
// 输入：grid = [[9,1,7],[8,9,2],[3,4,6]]
// 输出：[9,5]
// 解释：数字 9 重复，数字 5 缺失，所以答案是 [9,5] 。
//  
// 提示：
//  * 2 <= n == grid.length == grid[i].length <= 50
//  * 1 <= grid[i][j] <= n * n
//  * 对于所有满足1 <= x <= n * n 的 x ，恰好存在一个 x 与矩阵中的任何成员都不相等。
//  * 对于所有满足1 <= x <= n * n 的 x ，恰好存在一个 x 与矩阵中的两个成员相等。
//  * 除上述的两个之外，对于所有满足1 <= x <= n * n 的 x ，都恰好存在一对 i, j 满足 0 <= i, j <= n - 1 且 grid[i][j] == x 。

// #v1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
  *returnSize = 2;

  char ht[gridSize*gridSize + 1];
  int *ret = (int *)malloc(sizeof(int) * 2);
  int s1 = 0, s2 = 0;

  memset(ht, 0, sizeof(ht));

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if  (ht[grid[i][j]]) ret[0] = grid[i][j];
      ht[grid[i][j]] = 1;
      s1 ^= grid[i][j];
    }
  }

  for (int i = 1; i <= gridSize * gridSize; i++) {
    s2 ^= i;
  }

  ret[1] = s1 ^ s2 ^ ret[0];

  return ret;
}
// #v1

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

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
  int **grid, gridSize, gridColSize, *ret, returnSize;
  scanf("%d%d", &gridSize, &gridColSize);
  grid = read_2d_arr(gridSize, gridColSize);
  ret = findMissingAndRepeatedValues(grid, gridSize, &gridColSize, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
