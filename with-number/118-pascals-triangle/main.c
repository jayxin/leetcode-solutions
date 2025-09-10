#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 118. 杨辉三角 - 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
// [https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif]
//  
// 示例 1:
// 输入: numRows = 5
// 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// 示例 2:
// 输入: numRows = 1
// 输出: [[1]]
//  
// 提示:
//  * 1 &lt;= numRows &lt;= 30

// #v1
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
  *returnSize = numRows;
  int **ret = (int **)malloc(sizeof(int *) * numRows), i, j;
  *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);

  for (i = 0; i < numRows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * (i+1));
    (*returnColumnSizes)[i] = i + 1;
  }

  for (i = 0; i < numRows; i++) {
    ret[i][0] = 1;
    ret[i][i] = 1;
    if (i <= 1) continue;
    for (j = 1; j < i; j++) {
      ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
    }
  }

  return ret;
}
// #v1

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
  int n, r, *cols, **ret;
  scanf("%d", &n);
  ret = generate(n, &r, &cols);
  print_2d_arr(ret, r, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
