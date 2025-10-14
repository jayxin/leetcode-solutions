#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2679. 矩阵 中的和 - 给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。你需要执行以下操作直到矩阵变为空：
//  1. 矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一 个并删除。
//  2. 在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
// 请你返回最后的 分数 。
//  
// 示例 1：
// 输入：nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
// 输出：15
// 解释：第一步操作中，我们删除 7 ，6 ，6 和 3 ，将分数增加 7 。下一步操作中，删除 2 ，4 ，5 和 2 ，将分数增加 5 。最后删除 1 ，2 ，3 和 1 ，将分数增加 3 。所以总得 分为 7 + 5 + 3 = 15 。
// 示例 2：
// 输入：nums = [[1]]
// 输出：1
// 解释：我们删除 1 并将分数增加 1 ，所以返回 1 。
//  
// 提示：
//  * 1 <= nums.length <= 300
//  * 1 <= nums[i].length <= 500
//  * 0 <= nums[i][j] <= 103
// Sort the numbers in each row in decreasing order.
// The answer is the summation of the max number in every column after sorting
// the rows.

// #v1
// decreasing
int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int matrixSum(int** nums, int numsSize, int* numsColSize) {
  int ret = 0, i, j;

  // sort
  for (i = 0; i < numsSize; i++) {
    qsort(nums[i], *numsColSize, sizeof(int), cmp);
  }

  for (j = 0; j < *numsColSize; j++) {
    // find max in each column
    int maxVal = nums[0][j];
    for (i = 1; i < numsSize; i++) {
      if (nums[i][j] > maxVal) maxVal = nums[i][j];
    }

    // update result
    ret += maxVal;
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
  int n, **a, m;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  printf("%d\n", matrixSum(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
