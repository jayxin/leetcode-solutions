#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2536.  子矩阵元素加 1 - 给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩 阵 mat ，矩阵中填满了 0 。
// 另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i, col2i] ，请你执行下述操作：
//  * 找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i) 的子矩阵，将子矩阵中的 每个元素 加 1 。也就是给所有满足 row1i <= x <= row2i 和 col1i <= y <= col2i 的 mat[x][y] 加 1 。
// 返回执行完所有操作后得到的矩阵 mat 。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2022/11/24/p2example11.png]
// 输入：n = 3, queries = [[1,1,2,2],[0,0,1,1]]
// 输出：[[1,1,0],[1,2,1],[0,1,1]]
// 解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后 的矩阵。
// - 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。
// - 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2022/11/24/p2example22.png]
// 输入：n = 2, queries = [[0,0,1,1]]
// 输出：[[1,1],[1,1]]
// 解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。
// - 第一个操作：将矩阵中的每个元素加 1 。
//  
// 提示：
//  * 1 <= n <= 500
//  * 1 <= queries.length <= 104
//  * 0 <= row1i <= row2i < n
//  * 0 <= col1i <= col2i < n
// 1. Imagine each row as a separate array. Instead of updating the whole
// submatrix together, we can use prefix sum to update each row separately.
// 2. For each query, iterate over the rows i in the range [row1, row2] and add
// 1 to prefix sum S[i][col1], and subtract 1 from S[i][col2 + 1].
// 3. After doing this operation for all the queries, update each row separately
// with S[i][j] = S[i][j] + S[i][j - 1].

//// #v1
//// prefix sum
//int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
  //*returnSize = n;
  //*returnColumnSizes = calloc(n, sizeof(int));
//
  //int **ret = calloc(n, sizeof(int *));
//
  //// init
  //for (int i = 0; i < n; i++) {
    //ret[i] = calloc(n, sizeof(int));
    //(*returnColumnSizes)[i] = n;
    //memset(ret[i], 0, sizeof(int)*n);
  //}
//
  //// process queries
  //for (int i = 0; i < queriesSize; i++) {
    //int row1 = queries[i][0], col1 = queries[i][1],
        //row2 = queries[i][2], col2 = queries[i][3];
//
    //for (int j = row1; j <= row2; j++) {
      //ret[j][col1] += 1;
      //if (col2+1 < n) ret[j][col2+1] -= 1;
    //}
  //}
//
  //for (int i = 0; i < n; i++) {
    //for (int j = 1; j < n; j++) {
      //ret[i][j] += ret[i][j-1];
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
// prefix sum
int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = n;
  *returnColumnSizes = calloc(n, sizeof(int));

  int **ret = calloc(n, sizeof(int *));

  // init
  for (int i = 0; i < n; i++) {
    ret[i] = calloc(n, sizeof(int));
    (*returnColumnSizes)[i] = n;
    // calloc 会将内存置 0
    //memset(ret[i], 0, sizeof(int)*n);
  }

  // process queries
  // (row1, col1) .......... (row1, col2+1)
  // .......
  // ............(row2, col2)
  // (row2+1, col1)..........(row2+1, col2+1)
  for (int i = 0; i < queriesSize; i++) {
    int row1 = queries[i][0], col1 = queries[i][1],
        row2 = queries[i][2], col2 = queries[i][3];

    ++ret[row1][col1];
    if (col2 + 1 < n) --ret[row1][col2 + 1];
    if (row2 + 1 < n) --ret[row2 + 1][col1];
    if (row2 + 1 < n && col2 + 1 < n) ++ret[row2 + 1][col2 + 1];
  }

  // compute prefix sum for each row
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      ret[i][j] += ret[i][j-1];
    }
  }

  // compute prefix sum for each column
  for (int j = 0; j < n; j++) {
    for (int i = 1; i < n; i++) {
      ret[i][j] += ret[i-1][j];
    }
  }

  return ret;
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
  int n, **queries, queriesSize, queriesColSize, **ret, returnSize, *returnColumnSizes;
  scanf("%d", &n);
  scanf("%d%d", &queriesSize, &queriesColSize);
  queries = read_2d_arr(queriesSize, queriesColSize);
  ret = rangeAddQueries(n, queries, queriesSize, &queriesColSize, &returnSize, &returnColumnSizes);
  print_2d_arr(ret, returnSize, returnColumnSizes);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
