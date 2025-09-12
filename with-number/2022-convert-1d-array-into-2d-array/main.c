#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2022. 将一维数组转变成二维数组 - 给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。
// original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。
// 请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/08/26/image-20210826114243-1.png]
// 输入：original = [1,2,3,4], m = 2, n = 2
// 输出：[[1,2],[3,4]]
// 解释：
// 构造出的二维数组应该包含 2 行 2 列。
// original 中第一个 n=2 的部分为 [1,2] ，构成二维数组的第一行。
// original 中第二个 n=2 的部分为 [3,4] ，构成二维数组的第二行。
// 示例 2：
// 输入：original = [1,2,3], m = 1, n = 3
// 输出：[[1,2,3]]
// 解释：
// 构造出的二维数组应该包含 1 行 3 列。
// 将 original 中所有三个元素放入第一行中，构成要求的二维数组。
// 示例 3：
// 输入：original = [1,2], m = 1, n = 1
// 输出：[]
// 解释：
// original 中有 2 个元素。
// 无法将 2 个元素放入到一个 1x1 的二维数组中，所以返回一个空的二维数组。
// 示例 4：
// 输入：original = [3], m = 1, n = 2
// 输出：[]
// 解释：
// original 中只有 1 个元素。
// 无法将 1 个元素放满一个 1x2 的二维数组，所以返回一个空的二维数组。
//  
// 提示：
//  * 1 &lt;= original.length &lt;= 5 * 104
//  * 1 &lt;= original[i] &lt;= 105
//  * 1 &lt;= m, n &lt;= 4 * 104

//// #v1
//int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
  //if (m * n != originalSize) {
    //*returnSize = 0;
    //*returnColumnSizes = NULL;
    //return NULL;
  //}
//
  //// allocate
  //int **ret = (int **)malloc(sizeof(int *) * m);
  ////int *a = (int *)malloc(sizeof(int) * originalSize);
  //int i, j;
  //*returnSize = m;
  //*returnColumnSizes = (int *)malloc(sizeof(int) * m);
  //for (i = 0; i < m; i++) {
    ////ret[i] = &a[i*m];
    //ret[i] = (int *)malloc(sizeof(int) * n);;
    //(*returnColumnSizes)[i] = n;
  //}
//
  //for (i = 0; i < m; i++) {
    //for (j = 0; j < n; j++) {
      //ret[i][j] = original[i * n + j];
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
  if (m * n != originalSize) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
  }

  // allocate
  int **ret = (int **)malloc(sizeof(int *) * m);
  int i, j, l = 0;
  *returnSize = m;
  *returnColumnSizes = (int *)malloc(sizeof(int) * m);

  //for (i = 0; i < m; i++) {
  //  ret[i] = (int *)malloc(sizeof(int) * n);;
  //  (*returnColumnSizes)[i] = n;
  //  for (j = 0; j < n; j++) {
  //    ret[i][j] = original[l++];
  //  }
  //}

  // 不复制, 直接指定原数组
  for (i = 0; i < m; i++) {
    ret[i] = original + i * n;
    (*returnColumnSizes)[i] = n;
  }

  return ret;
}
// #v2

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

int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int l, m, n, *a, **ret, rows, *cols;
  scanf("%d", &l);
  a = read_1d_arr(l);
  scanf("%d%d", &m, &n);
  ret = construct2DArray(a, l, m, n, &rows, &cols);
  print_2d_arr(ret, rows, cols);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
