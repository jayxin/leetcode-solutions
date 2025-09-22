#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面 试题 17.04. 消失的数字 - 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
// 注意：本题相对书上原题稍作改动
// 示例 1：
// 输入：[3,0,1]
// 输出：2
//  
// 示例 2：
// 输入：[9,6,4,2,3,5,7,0,1]
// 输出：8

// #v1
int missingNumber(int* nums, int numsSize) {
  int r = 0, i;

  for (i = 1; i <= numsSize; i++) r ^= i;

  for (i = 0; i < numsSize; i++) r ^= nums[i];

  return r;
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", missingNumber(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
