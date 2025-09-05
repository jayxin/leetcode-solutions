#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 64. 最小路径 和 - 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径， 使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg]
// 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
// 输出：7
// 解释：因为路径 1→3→1→1→1 的总和最小。
// 示例 2：
// 输入：grid = [[1,2,3],[4,5,6]]
// 输出：12
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 <= m, n <= 200
//  * 0 <= grid[i][j] <= 200

//// #v1
//// 动态规划, 使用二维数组存储中间结果
//#define min(a, b) (a > b ? b : a)
//int minPathSum(int** grid, int gridSize, int* gridColSize) {
  //int ret = 0, i, j;
  //int **table = (int **)malloc(sizeof(int *) * gridSize);
//
  //for (i = 0; i < gridSize; i++) {
    //table[i] = (int *)malloc(sizeof(int) * (*gridColSize));
  //}
//
  //// first line
  //table[0][0] = grid[0][0];
  //for (i = 1; i < *gridColSize; i++) {
    //table[0][i] = table[0][i-1] + grid[0][i];
  //}
//
  //for (i = 1; i < gridSize; i++) {
    //table[i][0] = table[i-1][0] + grid[i][0];
//
    //for (j = 1; j < *gridColSize; j++) {
      //table[i][j] = min(table[i-1][j], table[i][j-1]) + grid[i][j];
    //}
  //}
  //ret = table[gridSize - 1][*gridColSize - 1];
//
  //for (i = 0; i < gridSize; i++) {
    //free(table[i]);
  //}
  //free(table);
//
  //return ret;
//}
//// #v1

//// #v2
//// 动态规划, 使用 2 个一维数组存储中间结果
//// 即只存储当前行和上一行的内容
//#define min(a, b) (a > b ? b : a)
//int minPathSum(int** grid, int gridSize, int* gridColSize) {
  //int ret = 0, i, j;
  //int *old_line, *new_line, *tmp;
  //old_line = (int *)malloc(sizeof(int) * (*gridColSize));
  //new_line = (int *)malloc(sizeof(int) * (*gridColSize));
//
  //// first line
  //old_line[0] = grid[0][0];
  //for (i = 1; i < *gridColSize; i++) {
    //old_line[i] = old_line[i-1] + grid[0][i];
  //}
//
  //for (i = 1; i < gridSize; i++) {
    //new_line[0] = old_line[0] + grid[i][0];
//
    //for (j = 1; j < *gridColSize; j++) {
      //new_line[j] = min(old_line[j], new_line[j-1]) + grid[i][j];
    //}
//
    //// swap
    //tmp = old_line;
    //old_line = new_line;
    //new_line = tmp;
  //}
//
  //// result
  //ret = old_line[*gridColSize - 1];
//
  //// free
  //free(old_line);
  //free(new_line);
//
  //return ret;
//}
//// #v2

// #v3
// 动态规划, 使用 1 个一维数组存储中间结果
// 即合并存储当前行和上一行的内容
#define min(a, b) (a > b ? b : a)
int minPathSum(int** grid, int gridSize, int* gridColSize) {
  int ret = 0, i, j;
  int *line;
  line = (int *)malloc(sizeof(int) * (*gridColSize));

  // first line
  line[0] = grid[0][0];
  for (i = 1; i < *gridColSize; i++) {
    line[i] = line[i-1] + grid[0][i];
  }

  for (i = 1; i < gridSize; i++) {
    line[0] = line[0] + grid[i][0];

    for (j = 1; j < *gridColSize; j++) {
      line[j] = min(line[j], line[j-1]) + grid[i][j];
    }
  }

  // result
  ret = line[*gridColSize - 1];

  // free
  free(line);

  return ret;
}
// #v3

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

void print_2d_arr(int **arr, int rows, int cols) {
  if (!arr || rows <= 0 || cols <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

// free 2d array
void free_2d_arr(int **arr, int rows) {
  if (!arr) {
    return;
  }
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int m, n;
  scanf("%d%d", &m, &n);
  int **arr = read_2d_arr(m, n);
  printf("%d\n", minPathSum(arr, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
