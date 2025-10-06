#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2961. 双模 幂运算 - 给你一个下标从 0 开始的二维数组 variables ，其中 variables[i] = [ai, bi, ci, mi]，以及一个整数 target 。
// 如果满足以下公式，则下标 i 是 好下标：
//  * 0 <= i < variables.length
//  * (((a_i)^(b_i) % 10)^(c_i)) % m_i == target
// 返回一个由 好下标 组成的数组，顺序不限 。
//  
// 示例 1：
// 输入：variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
// 输出：[0,2]
// 解释：对于 variables 数组中的每个下标 i ：
// 1) 对于下标 0 ，variables[0] = [2,3,3,10] ，(23 % 10)3 % 10 = 2 。
// 2) 对于下标 1 ，variables[1] = [3,3,3,1] ，(33 % 10)3 % 1 = 0 。
// 3) 对于下标 2 ，variables[2] = [6,1,1,4] ，(61 % 10)1 % 4 = 2 。
// 因此，返回 [0,2] 作为答案。
// 示例 2：
// 输入：variables = [[39,3,1000,1000]], target = 17
// 输出：[]
// 解释：对于 variables 数组中的每个下标 i ：
// 1) 对于下标 0 ，variables[0] = [39,3,1000,1000] ，(393 % 10)1000 % 1000 = 1 。
// 因此，返回 [] 作为答案。
//  
// 提示：
//  * 1 <= variables.length <= 100
//  * variables[i] == [ai, bi, ci, mi]
//  * 1 <= ai, bi, ci, mi <= 103
//  * 0 <= target <= 103

// #v1
int mypow(int a, int x, int mod) {
  int ret = 1;

  while (x) {
    if (x & 1) {
      ret = (ret * a) % mod;
    }

    a = (a * a) % mod;
    x >>= 1;
  }

  return ret;
}

int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * variablesSize), a, b, c, m, tmp;
  int retLen = 0;

  for (int i = 0; i < variablesSize; i++) {
    a = variables[i][0], b = variables[i][1],
    c = variables[i][2], m = variables[i][3];

    tmp = mypow(a, b, 10);
    tmp = mypow(tmp, c, m);

    if (tmp == target) ret[retLen++] = i;
  }

  *returnSize = retLen;

  return ret;
}
// #v1

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

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
  int n, **a, *ret, s, c = 4, t;
  scanf("%d", &n);
  a = read_2d_arr(n, c);
  scanf("%d", &t);

  ret = getGoodIndices(a, n, &c, t, &s);

  print_1d_arr(ret, s);

  free(ret);

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
