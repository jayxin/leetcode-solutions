#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1502. 判断能否形成等差数列 - 给你一个数字数组 arr 。
// 如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
// 如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：arr = [3,5,1]
// 输出：true
// 解释：对数组重新排序得到 [1,3,5] 或者 [5,3,1] ，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。
// 示例 2：
// 输入：arr = [1,2,4]
// 输出：false
// 解释：无法通过重新排序得到等差数列。
//  
// 提示：
//  * 2 &lt;= arr.length &lt;= 1000
//  * -10^6 &lt;= arr[i] &lt;= 10^6

// #v1
int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
  if (arrSize == 2) return true;

  qsort(arr, arrSize, sizeof(int), cmp);

  int diff = arr[1] - arr[0], t;

  for (int i = 2; i < arrSize; i++) {
    t = arr[i] - arr[i - 1];
    if (t != diff) return false;
  }

  return true;
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
  if (canMakeArithmeticProgression(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
