#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1262. 可被三整除的最大和 - 给你一个整数数组 nums，请你找出并返回能被三整除的元素 最 大和。
//  
// 示例 1：
// 输入：nums = [3,6,5,1,8]
// 输出：18
// 解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
// 示例 2：
// 输入：nums = [4]
// 输出：0
// 解释：4 不能被 3 整除，所以无法选出数字，返回 0。
// 示例 3：
// 输入：nums = [1,2,3,4,4]
// 输出：12
// 解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
//  
// 提示：
//  * 1 <= nums.length <= 4 * 104
//  * 1 <= nums[i] <= 104

//// #v1
//// 超时
//// sort, greedy, math, recursion
//
//int cmp(const void *a, const void *b) {
  //return *(const int *)b - *(const int *)a;
//}
//
//int max(int a, int b) {
  //return a >= b ? a : b;
//}
//
//int *a1, *a2, len1, len2;
//
//int f(int i, int j) {
  //if (i == len1) {
    //int ret = 0;
    //while (j+2 < len2) {
      //ret += a2[j] + a2[j+1] + a2[j+2];
      //j += 3;
    //}
    //return ret;
  //}
//
  //if (j == len2) {
    //int ret = 0;
    //while (i + 2 < len1) {
      //ret += a1[i] + a1[i+1] + a1[i+2];
      //i += 3;
    //}
    //return ret;
  //}
//
  //int v1, v2, v3;
//
  //v1 = v2 = v3 = 0;
//
  //v1 = a1[i] + a2[j] + f(i+1, j+1);
//
  //if (i+2 < len1)
    //v2 = a1[i] + a1[i+1] + a1[i+2] + f(i+3, j);
  //if (j+2 < len2)
    //v3 = a2[j] + a2[j+1] + a2[j+2] + f(i, j+3);
//
  //return max(v1, max(v2, v3));
//}
//
//int maxSumDivThree(int* nums, int numsSize) {
  //int ret = 0;
  //// arr1 存储 nums 中 (mod 3) 的余数为 1 的元素
  //// arr2 存储 nums 中 (mod 3) 的余数为 2 的元素
  //int arr1[numsSize], arr2[numsSize];
//
  //a1 = arr1;
  //a2 = arr2;
//
  //len1 = len2 = 0;
  //for (int i = 0; i < numsSize; i++) {
    //int r = nums[i] % 3;
    //switch (r) {
      //case 0:
        //ret += nums[i];
        //break;
      //case 1:
        //a1[len1++] = nums[i];
        //break;
      //case 2:
        //a2[len2++] = nums[i];
        //break;
    //}
  //}
//
  //// sort
  //qsort(a1, len1, sizeof(int), cmp);
  //qsort(a2, len2, sizeof(int), cmp);
//
  //ret += f(0, 0);
//
  //return ret;
//}
//// #v1

//// #v2
//// 超时
//// sort, greedy, math, recursion
//
//int cmp(const void *a, const void *b) {
  //return *(const int *)b - *(const int *)a;
//}
//
//int max(int a, int b) {
  //return a >= b ? a : b;
//}
//
//int *a1, *a2, len1, len2;
//int **tab;
//
//int f(int i, int j) {
  //if (i == len1) {
    //int ret = 0;
    //while (j+2 < len2) {
      //ret += a2[j] + a2[j+1] + a2[j+2];
      //j += 3;
    //}
    //return ret;
  //}
//
  //if (j == len2) {
    //int ret = 0;
    //while (i + 2 < len1) {
      //ret += a1[i] + a1[i+1] + a1[i+2];
      //i += 3;
    //}
    //return ret;
  //}
//
  //if (tab[i][j] >= 0) return tab[i][j];
//
  //int v1, v2, v3;
//
  //v1 = v2 = v3 = 0;
//
  //v1 = a1[i] + a2[j] + f(i+1, j+1);
//
  //if (i+2 < len1)
    //v2 = a1[i] + a1[i+1] + a1[i+2] + f(i+3, j);
  //if (j+2 < len2)
    //v3 = a2[j] + a2[j+1] + a2[j+2] + f(i, j+3);
//
  //tab[i][j] = max(v1, max(v2, v3));
//
  //return tab[i][j];
//}
//
//int maxSumDivThree(int* nums, int numsSize) {
  //int ret = 0;
  //// arr1 存储 nums 中 (mod 3) 的余数为 1 的元素
  //// arr2 存储 nums 中 (mod 3) 的余数为 2 的元素
  //int arr1[numsSize], arr2[numsSize];
//
  //a1 = arr1;
  //a2 = arr2;
//
  //len1 = len2 = 0;
  //for (int i = 0; i < numsSize; i++) {
    //int r = nums[i] % 3;
    //switch (r) {
      //case 0:
        //ret += nums[i];
        //break;
      //case 1:
        //a1[len1++] = nums[i];
        //break;
      //case 2:
        //a2[len2++] = nums[i];
        //break;
    //}
  //}
//
  //// sort
  //qsort(a1, len1, sizeof(int), cmp);
  //qsort(a2, len2, sizeof(int), cmp);
//
  //tab = calloc(len1, sizeof(int *));
  //for (int i = 0; i < len1; i++) {
    //tab[i] = calloc(len2, sizeof(int));
    //memset(tab[i], 0xff, sizeof(int) * len2);
  //}
//
  //ret += f(0, 0);
//
  //return ret;
//}
//// #v2

//// #v3
//// 超时
//// sort, greedy, math, recursion
//
//int cmp(const void *a, const void *b) {
  //return *(const int *)b - *(const int *)a;
//}
//
//int max(int a, int b) {
  //return a >= b ? a : b;
//}
//
//int *a1, *a2, len1, len2;
//int **tab;
//
//int f(int i, int j) {
  //if (tab[i][j] >= 0) return tab[i][j];
//
  //if (i == len1) {
    //int ret = 0, k = j;
    //while (j+2 < len2) {
      //ret += a2[j] + a2[j+1] + a2[j+2];
      //j += 3;
    //}
    //tab[len1][k] = ret;
    //return ret;
  //}
//
  //if (j == len2) {
    //int ret = 0, k = i;
    //while (i + 2 < len1) {
      //ret += a1[i] + a1[i+1] + a1[i+2];
      //i += 3;
    //}
    //tab[k][len2] = ret;
    //return ret;
  //}
//
  //int v1, v2, v3;
//
  //v1 = v2 = v3 = 0;
//
  //v1 = a1[i] + a2[j] + f(i+1, j+1);
//
  //if (i+2 < len1)
    //v2 = a1[i] + a1[i+1] + a1[i+2] + f(i+3, j);
  //if (j+2 < len2)
    //v3 = a2[j] + a2[j+1] + a2[j+2] + f(i, j+3);
//
  //tab[i][j] = max(v1, max(v2, v3));
//
  //return tab[i][j];
//}
//
//int maxSumDivThree(int* nums, int numsSize) {
  //int ret = 0;
  //// arr1 存储 nums 中 (mod 3) 的余数为 1 的元素
  //// arr2 存储 nums 中 (mod 3) 的余数为 2 的元素
  //int arr1[numsSize], arr2[numsSize];
//
  //a1 = arr1;
  //a2 = arr2;
//
  //len1 = len2 = 0;
  //for (int i = 0; i < numsSize; i++) {
    //int r = nums[i] % 3;
    //switch (r) {
      //case 0:
        //ret += nums[i];
        //break;
      //case 1:
        //a1[len1++] = nums[i];
        //break;
      //case 2:
        //a2[len2++] = nums[i];
        //break;
    //}
  //}
//
  //// sort
  //qsort(a1, len1, sizeof(int), cmp);
  //qsort(a2, len2, sizeof(int), cmp);
//
  //tab = calloc(len1+1, sizeof(int *));
  //for (int i = 0; i <= len1; i++) {
    //tab[i] = calloc(len2+1, sizeof(int));
    //memset(tab[i], 0xff, sizeof(int) * (len2+1));
  //}
//
  //ret += f(0, 0);
//
  //return ret;
//}
//// #v3

//// #v4
//// math, dynamic programming
//
//int max(int a, int b) {
  //return a >= b ? a : b;
//}
//
//int maxSumDivThree(int* nums, int numsSize) {
  //// dp[i][0] 表示 nums[0...(i-1)] 中被 3 整除的元素最大和
  //// dp[i][1] 表示 nums[0...(i-1)] 中被 3 除余数为 1 的元素最大和
  //// dp[i][2] 表示 nums[0...(i-1)] 中被 3 除余数为 2 的元素最大和
  //int dp[numsSize+1][3];
//
  //// init
  //dp[0][0] = dp[0][1] = dp[0][2] = 0;
//
  //// compute
  //for (int i = 0; i < numsSize; i++) {
    //// compute remainder
    //int r = nums[i] % 3, t;
//
    //switch (r) {
      //case 0:
        //dp[i+1][0] = dp[i][0] + nums[i];
        //dp[i+1][1] = dp[i][1] + nums[i];
        //dp[i+1][2] = dp[i][2] + nums[i];
        //break;
      //case 1:
        //t = dp[i][2] + nums[i];
        //dp[i+1][0] = dp[i][0];
        //if (t % 3 == 0) dp[i+1][0] = max(t, dp[i+1][0]);
//
        //t = dp[i][0] + nums[i];
        //dp[i+1][1] = dp[i][1];
        //if (t % 3 == 1) dp[i+1][1] = max(t, dp[i+1][1]);
//
        //t = dp[i][1] + nums[i];
        //dp[i+1][2] = dp[i][2];
        //if (t % 3 == 2) dp[i+1][2] = max(t, dp[i+1][2]);
        //break;
      //case 2:
        //t = dp[i][1] + nums[i];
        //dp[i+1][0] = dp[i][0];
        //if (t % 3 == 0) dp[i+1][0] = max(t, dp[i+1][0]);
//
        //t = dp[i][2] + nums[i];
        //dp[i+1][1] = dp[i][1];
        //if (t % 3 == 1) dp[i+1][1] = max(t, dp[i+1][1]);
//
        //t = dp[i][0] + nums[i];
        //dp[i+1][2] = dp[i][2];
        //if (t % 3 == 2) dp[i+1][2] = max(t, dp[i+1][2]);
        //break;
    //}
  //}
//
  //return dp[numsSize][0];
//}
//// #v4

// #v5
// math, dynamic programming

int maxSumDivThree(int* nums, int numsSize) {
  // dp[i][0] 表示 nums[0...(i-1)] 中被 3 整除的元素最大和
  // dp[i][1] 表示 nums[0...(i-1)] 中被 3 除余数为 1 的元素最大和
  // dp[i][2] 表示 nums[0...(i-1)] 中被 3 除余数为 2 的元素最大和
  int dp[numsSize+1][3];

  // init
  dp[0][0] = dp[0][1] = dp[0][2] = 0;

  // compute
  for (int i = 0; i < numsSize; i++) {
    // compute remainder
    int r = nums[i] % 3, t;

    switch (r) {
      case 0:
        dp[i+1][0] = dp[i][0] + nums[i];
        dp[i+1][1] = dp[i][1] + nums[i];
        dp[i+1][2] = dp[i][2] + nums[i];
        break;
      case 1:
        t = dp[i][2] + nums[i];
        dp[i+1][0] = dp[i][0];
        if (t % 3 == 0 && t > dp[i][0]) dp[i+1][0] = t;

        t = dp[i][0] + nums[i];
        dp[i+1][1] = dp[i][1];
        if (t % 3 == 1 && t > dp[i][1]) dp[i+1][1] = t;

        t = dp[i][1] + nums[i];
        dp[i+1][2] = dp[i][2];
        if (t % 3 == 2 && t > dp[i][2]) dp[i+1][2] = t;
        break;
      case 2:
        t = dp[i][1] + nums[i];
        dp[i+1][0] = dp[i][0];
        if (t % 3 == 0 && t > dp[i][0]) dp[i+1][0] = t;

        t = dp[i][2] + nums[i];
        dp[i+1][1] = dp[i][1];
        if (t % 3 == 1 && t > dp[i][1]) dp[i+1][1] = t;

        t = dp[i][0] + nums[i];
        dp[i+1][2] = dp[i][2];
        if (t % 3 == 2 && t > dp[i][2]) dp[i+1][2] = t;
        break;
    }
  }

  return dp[numsSize][0];
}
// #v5

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
  printf("%d\n", maxSumDivThree(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
