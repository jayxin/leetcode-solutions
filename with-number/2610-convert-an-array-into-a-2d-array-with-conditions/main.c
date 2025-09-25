#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2610. 转 换二维数组 - 给你一个整数数组 nums 。请你创建一个满足以下条件的二维数组：
//  * 二维数组应该 只 包含数组 nums 中的元素。
//  * 二维数组中的每一行都包含 不同 的整数。
//  * 二维数组的行数应尽可能 少 。
// 返回结果数组。如果存在多种答案，则返回其中任何一种。
// 请注意，二维数组的每一行上可以存在不同数量的元素。
//  
// 示例 1：
// 输入：nums = [1,3,4,1,2,3,1]
// 输出：[[1,3,4,2],[1,3],[1]]
// 解释：根据题目要求可以创建包含以下几行元素的二维数组：
// - 1,3,4,2
// - 1,3
// - 1
// nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
// 可以证明无法创建少于三行且符合题目要求的二维数组。
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：[[4,3,2,1]]
// 解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 200
//  * 1 &lt;= nums[i] &lt;= nums.length

// #v1
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  char t[201][201] = {0};
  int **ret = (int **)malloc(sizeof(int *) * numsSize), retLen = 0, i, j, *c;
  bool f;

  *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize);
  c = *returnColumnSizes;

  // 遍历数组的每个元素
  for (i = 0; i < numsSize; i++) {
    f = false;

    for (j = 0; j < retLen; j++) {
      if (t[j][nums[i]] == 0) { // 可以添加到某行
        // mark
        f = true;
        t[j][nums[i]] = 1;

        // add
        ret[j][c[j]++] = nums[i];

        break;
      }
    }

    // 数组的当前元素无法加到已有的任何一行, 则新增一行
    if (!f) {
      // allocate
      ret[retLen] = (int *)malloc(sizeof(int) * numsSize);
      c[retLen] = 0;

      // add
      ret[retLen][c[retLen]++] = nums[i];

      // mark
      t[retLen][nums[i]] = 1;

      // create new row
      retLen++;
    }
  }

  // record the number of rows
  *returnSize = retLen;

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
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
  int n, *a, **ret, r, *c;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findMatrix(a, n, &r, &c);
  print_2d_arr(ret, r, c);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
