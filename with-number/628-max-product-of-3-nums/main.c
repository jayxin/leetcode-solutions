#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 628.  三个数的最大乘积 - 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//  
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：6
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：24
// 示例 3：
// 输入：nums = [-1,-2,-3]
// 输出：-6
//  
// 提示：
//  * 3 &lt;= nums.length &lt;= 104
//  * -1000 &lt;= nums[i] &lt;= 1000

//// #v1
//int iCmp(const void *a, const void *b) {
  //return *(int *)a - *(int *)b;
//}
//
//int max(int a, int b) {
  //return a > b ? a : b;
//}
//
//int min(int a, int b) {
  //return a < b ? a : b;
//}
//
//int maximumProduct(int* nums, int numsSize) {
  //if (numsSize == 3) return nums[0] * nums[1] * nums[2];
//
  //int t[2001] = {0}, ret = 1, positiveCnt = 0, negativeCnt = 0, zeroCnt = 0, i,
      //cnt, j;
//
  //for (i = 0; i < numsSize; i++) {
    //if (nums[i] > 0) {
      //++positiveCnt;
    //} else if (nums[i] < 0) {
      //++negativeCnt;
    //} else {
      //++zeroCnt;
    //}
    //t[nums[i] + 1000] += 1;
  //}
//
  //// 全为 0
  //if (zeroCnt == numsSize) return 0;
//
  //// 0, 正数
  //if (negativeCnt == 0) {
    //cnt = 3;
    //ret = 1;
    //int times;
//
    //for (i = 2000; i >= 1001; i--) {
      //if (t[i]) {
        //times = min(t[i], cnt);
        //for (j = 0; j < times; j++) {
          //ret *= (i - 1000);
        //}
        //cnt -= times;
        //if (cnt == 0) break;
      //}
    //}
//
    //if (cnt) ret = 0;
    //return ret;
  //}
//
  //// 0, 负数
  //if (positiveCnt == 0) {
    //cnt = 3;
    //ret = 1;
    //int times;
//
    //// 存在 0
    //if (t[1000]) return 0;
//
    //for (i = 999; i >= 0; i--) {
      //if (t[i]) {
        //times = min(t[i], cnt);
        //for (j = 0; j < times; j++) {
          //ret *= (i - 1000);
        //}
        //cnt -= times;
        //if (cnt == 0) break;
      //}
    //}
//
    //return ret;
  //}
//
  //// 0, 正数, 负数
  //if (negativeCnt == 1 && positiveCnt == 1) return 0;
//
  //qsort(nums, numsSize, sizeof(int), iCmp);
//
  //return max(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 1] *
      //nums[numsSize - 2] * nums[numsSize - 3]);
//}
//// #v1

// #v2
int iCmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int maximumProduct(int* nums, int numsSize) {
  if (numsSize == 3) return nums[0] * nums[1] * nums[2];

  qsort(nums, numsSize, sizeof(int), iCmp);
  return max(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 1] *
      nums[numsSize - 2] * nums[numsSize - 3]);
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
  printf("%d\n", maximumProduct(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
