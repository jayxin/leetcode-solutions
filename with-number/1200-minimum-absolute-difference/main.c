#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1200. 最小 绝对差 - 给你个整数数组 arr，其中每个元素都 不相同。
// 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
// 每对元素对 [a,b] 如下：
//  * a , b 均为数组 arr 中的元素
//  * a &lt; b
//  * b - a 等于 arr 中任意两个元素的最小绝对差
//  
// 示例 1：
// 输入：arr = [4,2,1,3]
// 输出：[[1,2],[2,3],[3,4]]
// 示例 2：
// 输入：arr = [1,3,6,10,15]
// 输出：[[1,3]]
// 示例 3：
// 输入：arr = [3,8,-10,23,19,-4,-14,27]
// 输出：[[-14,-10],[19,23],[23,27]]
//  
// 提示：
//  * 2 &lt;= arr.length &lt;= 10^5
//  * -10^6 &lt;= arr[i] &lt;= 10^6

// #v1
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
  int retLen = 0, i, j;
  int **ret = (int **)malloc(sizeof(int *) * arrSize), minDiff = 0x3f3f3f3f, t;
  *returnColumnSizes = (int *)malloc(sizeof(int) * arrSize);

  qsort(arr, arrSize, sizeof(int), cmp);

  for (i = 1; i < arrSize; i++) {
    t = arr[i] - arr[i-1];
    if (t < minDiff) minDiff = t;
  }

  for (i = 1; i < arrSize; i++) {
    j = i - 1;
    t = arr[i] - arr[j];

    if (t == minDiff) {
      ret[retLen] = (int *)malloc(sizeof(int) * 2);

      ret[retLen][0] = arr[j], ret[retLen][1] = arr[i];
      (*returnColumnSizes)[retLen] = 2;

      retLen++;
    }
  }

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
  int n, *a, **ret, s, *cols;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = minimumAbsDifference(a, n, &s, &cols);
  print_2d_arr(ret, s, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
