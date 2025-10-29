#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2523. 范围内最接近的两个质数 - 给你两个正整数 left 和 right ，请你找到两个整数 num1 和 num2 ，它们满足：
//  * left <= nums1 < nums2 <= right  。
//  * nums1 和 nums2 都是 质数 。
//  * nums2 - nums1 是满足上述条件的质数对中的 最小值 。
// 请你返回正整数数组 ans = [nums1, nums2] 。如果有多个整数对满足上述条件，请你返回 nums1 最小的质数对。如果不存在符合题意的质数对，请你返回 [-1, -1] 。
//  
// 示例 1：
// 输入：left = 10, right = 19
// 输出：[11,13]
// 解释：10 到 19 之间的质数为 11 ，13 ，17 和 19 。
// 质数对的最小差值是 2 ，[11,13] 和 [17,19] 都可以得到最小差值。
// 由于 11 比 17 小，我们返回第一个质数对。
// 示例 2：
// 输入：left = 4, right = 6
// 输出：[-1,-1]
// 解释：给定范围内只有一个质数，所以题目条件无法被满足。
//  
// 提示：
//  * 1 <= left <= right <= 106

//// #v1
//int* closestPrimes(int left, int right, int* returnSize) {
  //int *ret = (int *)malloc(sizeof(int)*2), prev, diff, i, j, d;
  //char isPrime[right + 1];
//
  //// init
  //*returnSize = 2;
  //ret[0] = ret[1] = -1;
  //memset(isPrime, 1, sizeof(isPrime));
  //isPrime[0] = isPrime[1] = 0;
//
  //for (i = 2; i <= right; i++) {
    //if (isPrime[i]) {
      //for (j = i; j <= right / i; j++) {
        //isPrime[i*j] = 0;
      //}
    //}
  //}
//
  //diff = 0x7fffffff;
  //prev = 0;
  //for (i = left; i <= right; i++) {
    //if (isPrime[i]) {
      //if (prev) {
        //d = i - prev;
        //if (d < diff) {
          //ret[0] = prev;
          //ret[1] = i;
          //diff = d;
        //}
      //}
//
      //prev = i;
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
int* closestPrimes(int left, int right, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int)*2), prev;
  char isPrime[right+1];

  // init
  *returnSize = 2;
  ret[0] = ret[1] = -1;
  memset(isPrime, 1, sizeof(isPrime));
  prev = 0;

  for (int i = 2; i <= right; i++) {
    if (isPrime[i]) {
      if (i >= left && prev >= left) {
        if (i - prev < ret[1] - ret[0] || ret[0] == -1) {
          ret[0] = prev;
          ret[1] = i;
        }
      }

      prev = i;

      for (int j = i; j <= right/i; j++) isPrime[i*j] = 0;
    }
  }

  return ret;
}
// #v2

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

int main(int argc, char *argv[])
{
  int l, r, s, *ret;
  scanf("%d%d", &l, &r);
  ret = closestPrimes(l, r, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
