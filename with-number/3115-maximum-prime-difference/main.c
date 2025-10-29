#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3115.  质数的最大距离 - 给你一个整数数组 nums。
// 返回两个（不一定不同的）质数在 nums 中 下标 的 最大距离。
//  
// 示例 1：
// 输入： nums = [4,2,9,5,3]
// 输出： 3
// 解释： nums[1]、nums[3] 和 nums[4] 是质数。因此答案是 |4 - 1| = 3。
// 示例 2：
// 输入： nums = [4,8,2,8]
// 输出： 0
// 解释： nums[2] 是质数。因为只有一个质数，所以答案是 |2 - 2| = 0。
//  
// 提示：
//  * 1 <= nums.length <= 3 * 105
//  * 1 <= nums[i] <= 100
//  * 输入保证 nums 中至少有一个质数。

//// #v1
//int maximumPrimeDifference(int* nums, int numsSize) {
  //char *isPrime;
  //int maxVal = nums[0], i, j, primeIdx[numsSize], len = 0;
//
  //// find max value of nums
  //for (i = 1; i < numsSize; i++)
    //if (nums[i] > maxVal) maxVal = nums[i];
//
  //// allocate and init
  //isPrime = (char *)malloc(sizeof(char) * (maxVal + 1));
  //memset(isPrime, 1, sizeof(char) * (maxVal + 1));
  //isPrime[0] = isPrime[1] = 0;
//
  //// find all primes in [1, maxVal]
  //for (i = 2; i <= maxVal; i++) {
    //if (isPrime[i]) {
      //for (j = i; j <= maxVal / i; j++) {
        //isPrime[i * j] = 0;
      //}
    //}
  //}
//
  //// find all indexes of primes
  //for (i = 0; i < numsSize; i++) {
    //if (isPrime[nums[i]]) primeIdx[len++] = i;
  //}
//
  //free(isPrime);
//
  //if (len == 1) return 0;
//
  //return primeIdx[len - 1] - primeIdx[0];
//}
//// #v1

//// #v2
//int maximumPrimeDifference(int* nums, int numsSize) {
  //char isPrime[101];
  //// minIdx: nums 中素数元素的最小索引
  //// maxIdx: nums 中素数元素的最大索引
  //int i, minIdx = -1, maxIdx = -1;
//
  //// allocate and init
  //memset(isPrime, 1, sizeof(isPrime));
  //isPrime[0] = isPrime[1] = isPrime[100] = isPrime[99] = isPrime[98] = 0;
//
  //// find all primes
  //for (i = 2; i <= 97; i++) {
    //if (isPrime[i]) {
      //printf("%d ", i);
      //for (int j = i; j <= 97/i; j++) isPrime[i*j] = 0;
    //}
  //}
//
  //i = 0;
  //while (1) {
    //if (isPrime[nums[i]]) {
      //minIdx = i;
      //break;
    //}
    //++i;
  //}
//
  //i = numsSize - 1;
  //while (1) {
    //if (isPrime[nums[i]]) {
      //maxIdx = i;
      //break;
    //}
    //--i;
  //}
//
  //return maxIdx - minIdx;
//}
//// #v2

// #v3
int maximumPrimeDifference(int* nums, int numsSize) {
  char isPrime[101] = {0};
  // minIdx: nums 中素数元素的最小索引
  // maxIdx: nums 中素数元素的最大索引
  int i, minIdx, maxIdx;

  isPrime[2] = 1;
  isPrime[3] = 1;
  isPrime[5] = 1;
  isPrime[7] = 1;
  isPrime[11] = 1;
  isPrime[13] = 1;
  isPrime[17] = 1;
  isPrime[19] = 1;
  isPrime[23] = 1;
  isPrime[29] = 1;
  isPrime[31] = 1;
  isPrime[37] = 1;
  isPrime[41] = 1;
  isPrime[43] = 1;
  isPrime[47] = 1;
  isPrime[53] = 1;
  isPrime[59] = 1;
  isPrime[61] = 1;
  isPrime[67] = 1;
  isPrime[71] = 1;
  isPrime[73] = 1;
  isPrime[79] = 1;
  isPrime[83] = 1;
  isPrime[89] = 1;
  isPrime[97] = 1;

  i = 0;
  while (!isPrime[nums[i]]) ++i;
  minIdx = i;

  i = numsSize - 1;
  while (!isPrime[nums[i]]) --i;
  maxIdx = i;

  return maxIdx - minIdx;
}
// #v3

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
  printf("%d\n", maximumPrimeDifference(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
