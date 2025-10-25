#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2761. 和等于目标值的质数对 - 给你一个整数 n 。如果两个整数 x 和 y 满足下述条件，则认为二者形成一个质数对：
//  * 1 <= x <= y <= n
//  * x + y == n
//  * x 和 y 都是质数
// 请你以二维有序列表的形式返回符合题目要求的所有 [xi, yi] ，列表需要按 xi 的 非递减顺序 排序。如果不存在符合要求的质数对，则返回一个空数组。
// 注意：质数是大于 1 的自然数，并且只有两个因子，即它本身和 1 。
//  
// 示例 1：
// 输入：n = 10
// 输出：[[3,7],[5,5]]
// 解释：在这个例子中，存在满足条件的两个质数对。
// 这两个质数对分别是 [3,7] 和 [5,5]，按照题面描述中的方式排序后返回。
// 示例 2：
// 输入：n = 2
// 输出：[]
// 解释：可以证明不存在和为 2 的质数对，所以返回一个空数组。
//  
// 提示：
//  * 1 <= n <= 106

//// #v1
///**
 //* Return an array of arrays of size *returnSize.
 //* The sizes of the arrays are returned as *returnColumnSizes array.
 //* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 //*/
//char *v;
//
//void computePrime(int n) {
  //memset(v, 1, sizeof(char) * n);
//
  //int j, t;
//
  //for (int i = 2; i <= n; i++) {
    //if (v[i]) {
      //t = n / i;
      //for (j = i; j <= t; j++) v[i * j] = 0;
    //}
  //}
//}
//
//int** findPrimePairs(int n, int* returnSize, int** returnColumnSizes) {
  //char isPrime[n+1];
  //int **ret, retLen = 0, h;
//
  //v = isPrime;
  //computePrime(n);
//
  //h = n >> 1;
  //ret = (int **)malloc(sizeof(int *) * h);
  //*returnColumnSizes = (int *)malloc(sizeof(int) * h);
//
  //for (int i = 2; i <= h; i++) {
    //if (isPrime[i] && isPrime[n-i]) {
      //ret[retLen] = (int *)malloc(sizeof(int) * 2);
      //ret[retLen][0] = i;
      //ret[retLen][1] = n - i;
      //(*returnColumnSizes)[retLen++] = 2;
    //}
  //}
//
  //*returnSize = retLen;
//
  //return ret;
//}
//// #v1

// #v2
int** findPrimePairs(int n, int* returnSize, int** returnColumnSizes) {
  char isPrime[n+1];
  int **ret, retLen = 0, h, i, j, t;

  // init
  h = n >> 1;
  memset(isPrime, 1, sizeof(char) * n);
  ret = (int **)malloc(sizeof(int *) * h);
  *returnColumnSizes = (int *)malloc(sizeof(int) * h);

  // compute prime
  for (i = 2; i <= h; i++) {
    if (isPrime[i]) {
      t = n / i;
      for (j = i; j <= t; j++) isPrime[i * j] = 0;
    }
  }

  for (i = 2; i <= h; i++) {
    if (isPrime[i] && isPrime[n-i]) {
      ret[retLen] = (int *)malloc(sizeof(int) * 2);
      ret[retLen][0] = i;
      ret[retLen][1] = n - i;
      (*returnColumnSizes)[retLen++] = 2;
    }
  }

  *returnSize = retLen;

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

int main(int argc, char *argv[])
{
  int n, **ret, r, *c;
  scanf("%d", &n);
  ret = findPrimePairs(n, &r, &c);
  print_2d_arr(ret, r, c);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
