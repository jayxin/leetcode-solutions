#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 面试 题 08.01. 三步问题 - 三步问题。有个小孩正在上楼梯，楼梯有 n 阶台阶，小孩一次可以 上 1 阶、2 阶或 3 阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大， 你需要对结果模 1000000007。
// 示例 1：
//  输入：n = 3
//  输出：4
//  说明：有四种走法
// 示例 2：
//  输入：n = 5
//  输出：13
// 提示:
//  1. n 范围在[1, 1000000]之间

//// #v1
//// 递推
//int waysToStep(int n) {
  //switch (n) {
    //case 1:
      //return 1;
    //case 2:
      //return 2;
    //case 3:
      //return 4;
  //}
//
  //long long prev1, prev2, prev3, ret;
  //int mod = 1000000007;
  //prev1 = 1LL;
  //prev2 = 2LL;
  //prev3 = 4LL;
//
  //for (int i = 4; i <= n; ++i) {
    //ret = prev1 + prev2 + prev3;
    //prev1 = prev2;
    //prev2 = prev3;
    //prev3 = ret % mod;
  //}
//
  //return (ret % mod);
//}
//// #v1

// #v2
// 组合数学 矩阵
// 不完全矩阵
// f(n) = f(n-1)+f(n-2)+f(n-3)

// f(n) =
// |1, 1, 1|
// *
// |f(n-1)|
// |f(n-2)|
// |f(n-3)|

//|f(n)  |
//|f(n-1)|
//|f(n-2)|
// =
// |1, 1, 1|
// |1, 0, 0|
// |0, 1, 0|
// *
// |f(n-1)|
// |f(n-2)|
// |f(n-3)|
// =
// |1, 1, 1|^2
// |1, 0, 0|
// |0, 1, 0|
// *
// |f(n-2)|
// |f(n-3)|
// |f(n-4)|
// =
// ...
// =
// |1, 1, 1|^(n-3)
// |1, 0, 0|
// |0, 1, 0|
// *
// |f(3)|
// |f(2)|
// |f(1)|

// 内存分配
long** alloc_2d_arr(int rows, int cols);
// 内存释放
void free_2d_arr(long **arr, int rows);

// 矩阵乘法
long** matrix_multiply(long **a, long **b);
// 矩阵的幂
long** matrix_pow(long **a, int i);

int mod = 1000000007;

int waysToStep(int n) {
  // base case
  switch (n) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 4;
  }

  long **m = (long **)alloc_2d_arr(3, 3);
  // 矩阵第1行
  m[0][0] = 1;
  m[0][1] = 1;
  m[0][2] = 1;

  // 矩阵第2行
  m[1][0] = 1;
  m[1][1] = 0;
  m[1][2] = 0;

  // 矩阵第3行
  m[2][0] = 0;
  m[2][1] = 1;
  m[2][2] = 0;

  long **mn = matrix_pow(m, n - 3);
  long ret = (mn[0][0] * 4 + mn[0][1] * 2 + mn[0][2] * 1) % mod;

  return ret;
}

long** alloc_2d_arr(int rows, int cols) {
  long **ret = (long **)malloc(sizeof(long *) * rows);
  size_t s = sizeof(long);
  for (int i = 0; i < rows; ++i) {
    ret[i] = (long *)malloc(s * cols);
    memset(ret[i], 0, s * cols);
  }
  return ret;
}

void free_2d_arr(long **arr, int rows) {
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
}

long** matrix_multiply(long **a, long **b) {
  long **c = alloc_2d_arr(3, 3);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      long s = 0;
      for (int k = 0; k < 3; ++k) {
        s = (s + a[i][k] * b[k][j] % mod) % mod;
      }
      c[i][j] = s % mod;
    }
  }

  return c;
}

long** matrix_pow(long **a, int i) {
  // 初始值是单位矩阵
  long **ret = (long **)alloc_2d_arr(3, 3);
  long **tmp;
  ret[0][0] = 1;
  ret[1][1] = 1;
  ret[2][2] = 1;

  // 快速幂
  while (i) { // 指数非 0
    if (i & 1) { // 加入结果
      tmp = ret;
      ret = matrix_multiply(ret, a);
      free_2d_arr(tmp, 3);
    }

    tmp = a;
    a = matrix_multiply(a, a);
    free_2d_arr(tmp, 3);

    // 进入下一位
    i >>= 1;
  }

  return ret;
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", waysToStep(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
