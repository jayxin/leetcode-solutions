#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 832. 翻转图像 - 给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
// 水平翻转图片就是将图片的每一行都进行翻转，即逆序。
//  * 例如，水平翻转 [1,1,0] 的结果是 [0,1,1]。
// 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
//  * 例如，反转 [0,1,1] 的结果是 [1,0,0]。
//  
// 示例 1：
// 输入：image = [[1,1,0],[1,0,1],[0,0,0]]
// 输出：[[1,0,0],[0,1,0],[1,1,1]]
// 解释：首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
//      然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
// 示例 2：
// 输入：image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// 输出：[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// 解释：首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
//      然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
//  
// 提示：
//  * n == image.length
//  * n == image[i].length
//  * 1 &lt;= n &lt;= 20
//  * images[i][j] == 0 或 1.

// #v1
void reverse(int *a, int n) {
  if (n <=  1) return ;

  int l = n >> 1, t;

  for (int i = 0; i < l; i++) {
    t = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = t;
  }
}

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = imageSize;

  int **ret = (int **)malloc(sizeof(int *) * imageSize), i, j;
  *returnColumnSizes = (int *)malloc(sizeof(int) * imageSize);

  for (i = 0; i < imageSize; i++) {
    ret[i] = (int *)malloc(sizeof(int) * imageSize);
    (*returnColumnSizes)[i] = imageSize;

    reverse(image[i], imageSize);

    for (j = 0; j < imageSize; j++) {
      ret[i][j] = !image[i][j];
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
  int n, **a, **ret, r, *c;
  scanf("%d", &n);
  a = read_2d_arr(n, n);
  ret = flipAndInvertImage(a, n, &n, &r, &c);
  print_2d_arr(ret, r, c);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
