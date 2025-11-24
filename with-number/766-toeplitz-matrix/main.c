#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 766. 托普 利茨矩阵 - 给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true  ；否则，返回 false 。
// 如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵  。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg]
// 输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// 输出：true
// 解释：
// 在上述矩阵中, 其对角线为:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
// 各条对角线上的所有元素均相同, 因此答案是 True 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg]
// 输入：matrix = [[1,2],[2,2]]
// 输出：false
// 解释：
// 对角线 "[1, 2]" 上的元素不同。
//  
// 提示：
//  * m == matrix.length
//  * n == matrix[i].length
//  * 1 <= m, n <= 20
//  * 0 <= matrix[i][j] <= 99
//  
// 进阶：
//  * 如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
//  * 如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
// Check whether each value is equal to the value of it's top-left neighbor.

// #v1
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
  for (int i = 1; i < matrixSize; i++) {
    for (int j = 1; j < *matrixColSize; j++) {
      if (matrix[i][j] != matrix[i-1][j-1]) return false;
    }
  }
  return true;
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
  if (isToeplitzMatrix(a, m, &n))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
