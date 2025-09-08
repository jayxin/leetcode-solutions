#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 3195. 包含所有 1 的最小矩形面积 I - 给你一个二维 二进制 数组 grid。请你找出一个边在水平方向和竖直方向上、面积 最小 的矩形，并且满足 grid 中所有的 1 都在矩形的内部。
// 返回这个矩形可能的 最小 面积。
//  
// 示例 1：
// 输入： grid = [[0,1,0],[1,0,1]]
// 输出： 6
// 解释：
// [https://assets.leetcode.com/uploads/2024/05/08/examplerect0.png]
// 这个最小矩形的高度为 2，宽度为 3，因此面积为 2 * 3 = 6。
// 示例 2：
// 输入： grid = [[0,0],[1,0]]
// 输出： 1
// 解释：
// [https://assets.leetcode.com/uploads/2024/05/08/examplerect1.png]
// 这个最小矩形的高度和宽度都是 1，因此面积为 1 * 1 = 1。
//  
// 提示：
//  * 1 <= grid.length, grid[i].length <= 1000
//  * grid[i][j] 是 0 或 1。
//  * 输入保证 grid 中至少有一个 1 。

//// #v1
//// 分别找到水平方向和垂直方向 1 的最小和最大坐标
//// 朴素方法
//int minimumArea(int** grid, int gridSize, int* gridColSize) {
  //int minRowCoordinate = gridSize,
      //maxRowCoordinate = -1,
      //minColCoordinate = *gridColSize,
      //maxColCoordinate = -1,
      //ret;
  //for (int i = 0; i < gridSize; i++) {
    //for (int j = 0; j < *gridColSize; j++) {
      //if (grid[i][j]) {
        //if (minRowCoordinate == gridSize) {
          //minRowCoordinate = i;
          //break;
        //}
      //}
    //}
  //}
  //for (int i = gridSize - 1; i >= 0; i--) {
    //for (int j = 0; j < *gridColSize; j++) {
      //if (grid[i][j]) {
        //if (maxRowCoordinate < 0) {
          //maxRowCoordinate = i;
          //break;
        //}
      //}
    //}
  //}
  //for (int j = 0; j < *gridColSize; j++) {
    //for (int i = 0; i < gridSize; i++) {
      //if (grid[i][j]) {
        //if (minColCoordinate == *gridColSize) {
          //minColCoordinate = j;
          //break;
        //}
      //}
    //}
  //}
  //for (int j = *gridColSize - 1; j >= 0; j--) {
    //for (int i = 0; i < gridSize; i++) {
      //if (grid[i][j]) {
        //if (maxColCoordinate == -1) {
          //maxColCoordinate = j;
          //break;
        //}
      //}
    //}
  //}
  //ret = (maxRowCoordinate - minRowCoordinate + 1) * (maxColCoordinate - minColCoordinate + 1);
  //return ret;
//}
//// #v1

// #v2
// 分别找到水平方向和垂直方向 1 的最小和最大坐标
int minimumArea(int** grid, int gridSize, int* gridColSize) {
  int m = gridSize, n = *gridColSize, i, j;
  int minRowCoordinate = m,
      maxRowCoordinate = -1,
      minColCoordinate = n,
      maxColCoordinate = -1;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (grid[i][j]) {
        minRowCoordinate = i;
        break;
      }
    }
    if (minRowCoordinate != m) break;
  }
  for (i = m - 1; i >= minRowCoordinate; i--) {
    for (j = 0; j < n; j++) {
      if (grid[i][j]) {
        maxRowCoordinate = i;
        break;
      }
    }
    if (maxRowCoordinate != -1) break;
  }
  for (j = 0; j < n; j++) {
    for (i = 0; i < m; i++) {
      if (grid[i][j]) {
        minColCoordinate = j;
        break;
      }
    }
    if (minColCoordinate != n) break;
  }
  for (j = n - 1; j >= minColCoordinate; j--) {
    for (i = 0; i < m; i++) {
      if (grid[i][j]) {
        maxColCoordinate = j;
        break;
      }
    }
    if (maxColCoordinate != -1) break;
  }
  return ((maxRowCoordinate - minRowCoordinate + 1) * (maxColCoordinate - minColCoordinate + 1));
}
// #v2

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
  int r, c;
  scanf("%d%d", &r, &c);
  int **a = read_2d_arr(r, c);
  printf("%d\n", minimumArea(a, r, &c));
  free_2d_arr(a, r);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
