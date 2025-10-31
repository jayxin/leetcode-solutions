#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2815. 数组中的最大数对和 - 给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。
// 返回最大和，如果不存在满足题意的数字对，返回 -1 。
//  
// 示例 1：
// 输入：nums = [51,71,17,24,42]
// 输出：88
// 解释：
// i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。
// i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
// 可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：-1
// 解释：不存在数对满足数位上最大的数字相等。
//  
// 提示：
//  * 2 <= nums.length <= 100
//  * 1 <= nums[i] <= 104

//// #v1
//int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
//
//int maxSum(int* nums, int numsSize) {
  //int ret = -1, *tab[10], lens[10], i;
//
  //// init
  //for (i = 1; i <= 9; i++) {
    //tab[i] = calloc(numsSize, sizeof(int));
    //lens[i] = 0;
  //}
//
  //// compute
  //for (i = 0; i < numsSize; i++) {
    //int t = nums[i], maxDigit = 0, d;
//
    //while (t) {
      //d = t % 10;
      //if (d > maxDigit) maxDigit = d;
      //t /= 10;
    //}
//
    //tab[maxDigit][lens[maxDigit]++] = nums[i];
  //}
//
  //for (i = 1; i <= 9; i++) {
    //if (lens[i] <= 1) continue;
//
    //qsort(tab[i], lens[i], sizeof(int), cmp);
//
    //int t = tab[i][lens[i] - 1] + tab[i][lens[i] - 2];
    //if (t > ret) ret = t;
    //free(tab[i]);
  //}
//
  //return ret;
//}
//// #v1

// #v2
int maxSum(int* nums, int numsSize) {
  int ret = -1, *tab[10], i;

  // init
  for (i = 1; i <= 9; i++) {
    tab[i] = calloc(2, sizeof(int));
    tab[i][0] = tab[i][1] = -1;
  }

  // compute
  for (i = 0; i < numsSize; i++) {
    int t = nums[i], maxDigit = 0, d;

    // find the max digit of nums[i]
    while (t) {
      d = t % 10;
      if (d > maxDigit) maxDigit = d;
      t /= 10;
    }

    int *a = tab[maxDigit], *minPos = &a[0];

    // find min value of a[0] and a[1]
    if (a[0] > a[1]) minPos = &a[1];

    // update
    if (nums[i] > *minPos) *minPos = nums[i];
  }

  for (i = 1; i <= 9; i++) {
    if (tab[i][1] == -1) continue;

    int t = tab[i][0] + tab[i][1];
    if (t > ret) ret = t;

    free(tab[i]);
  }

  return ret;
}
// #v2

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

  printf("%d\n", maxSum(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
