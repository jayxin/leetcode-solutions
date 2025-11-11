#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 733. 图像渲染 - 有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。你也被给予三个整数 sr ,  sc 和 color 。你应该从像素 image[sr][sc] 开始 对图像进行上色 填充 。
// 为了完成 上色工作：
//  1. 从初始像素开始，将其颜色改为 color。
//  2. 对初始坐标的 上下左右四个方向上 相邻且与初始像素的原始颜色同色的像素点执行相 同操作。
//  3. 通过检查与初始像素的原始颜色相同的相邻像素并修改其颜色来继续 重复 此过程。
//  4. 当 没有 其它原始颜色的相邻像素时 停止 操作。
// 最后返回经过上色渲染 修改 后的图像 。
//  
// 示例 1:
// [https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg]
// 输入：image = [[1,1,1],[1,1,0],[1,0,1]]，sr = 1, sc = 1, color = 2
// 输出：[[2,2,2],[2,2,0],[2,0,1]]
// 解释：在图像的正中间，坐标 (sr,sc)=(1,1) （即红色像素）,在路径上所有符合条件的像 素点的颜色都被更改成相同的新颜色（即蓝色像素）。
// 注意，右下角的像素 没有 更改为2，因为它不是在上下左右四个方向上与初始点相连的像素点。
//  
// 示例 2:
// 输入：image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
// 输出：[[0,0,0],[0,0,0]]
// 解释：初始像素已经用 0 着色，这与目标颜色相同。因此，不会对图像进行任何更改。
//  
// 提示:
//  * m == image.length
//  * n == image[i].length
//  * 1 <= m, n <= 50
//  * 0 <= image[i][j], color < 216
//  * 0 <= sr < m
//  * 0 <= sc < n

// #v1
int m, n, **a, c, d, **ret;
char **v;

void dfs(int i, int j) {
  v[i][j] = 1;

  if (a[i][j] != d) return ;

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

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
  m = imageSize, n = *imageColSize;
  a = image;
  c = color;

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
    for (j = 0; j < n; j++) {
      ret[i][j] = a[i][j];
    }
  }
  v = visited;
  d = a[sr][sc];
  dfs(sr, sc);

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
  ret = floodFill(image, imageSize, &imageColSize, sr, sc, color, &returnSize,
      &returnColumnSizes);
  print_2d_arr(ret, returnSize, returnColumnSizes);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
