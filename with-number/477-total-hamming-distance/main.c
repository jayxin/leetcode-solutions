#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 477. 汉明 距离总和 - 两个整数的 汉明距离 [https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB/475174?fr=aladdin] 指的是这两个数字的二进制数对应位不同的数量。
// 给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和 。
//  
// 示例 1：
// 输入：nums = [4,14,2]
// 输出：6
// 解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示 是为了体现后四位之间关系）
// 所以答案为：
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6
// 示例 2：
// 输入：nums = [4,14,4]
// 输出：4
//  
// 提示：
//  * 1 <= nums.length <= 10^4
//  * 0 <= nums[i] <= 10^9
//  * 给定输入的对应答案符合 32-bit 整数范围

//// #v1
//int totalHammingDistance(int* nums, int numsSize) {
  //int zeroCnt, oneCnt, i, ret = 0, maxBits = 0, maxVal = nums[0], j;
//
  //// find max value in nums
  //for (i = 1; i < numsSize; i++) {
    //if (nums[i] > maxVal) maxVal = nums[i];
  //}
//
  //// count bits of max value
  //while (maxVal) {
    //++maxBits;
    //maxVal >>= 1;
  //}
//
  //for (i = 0; i < maxBits; i++) {
    //zeroCnt = oneCnt = 0;
//
    //for (j = 0; j < numsSize; j++) {
      //if (nums[j] & 1) ++oneCnt; // count one
      //else ++zeroCnt; // count zero
      //// shift
      //nums[j] >>= 1;
    //}
//
    //// update result
    //ret += zeroCnt * oneCnt;
  //}
//
  //return ret;
//}
//// #v1

//// #v2
//int totalHammingDistance(int* nums, int numsSize) {
  //int oneCnt, i, ret = 0, maxBits = 0, maxVal = nums[0], j;
//
  //// find max value in nums
  //for (i = 1; i < numsSize; i++) {
    //if (nums[i] > maxVal) maxVal = nums[i];
  //}
//
  //// count bits of max value
  //while (maxVal) {
    //++maxBits;
    //maxVal >>= 1;
  //}
//
  //for (i = 0; i < maxBits; i++) {
    //oneCnt = 0;
//
    //for (j = 0; j < numsSize; j++) {
      //if (nums[j] & 1) ++oneCnt; // count one
      //// shift
      //nums[j] >>= 1;
    //}
//
    //// update result
    //ret += (numsSize - oneCnt) * oneCnt;
  //}
//
  //return ret;
//}
//// #v2

// #v3
int totalHammingDistance(int* nums, int numsSize) {
  int i, j, oneCnt, ret = 0;
  int maxBits = 0, maxVal, andVal, orVal;

  maxVal = andVal = orVal = nums[0];

  // find max value in nums
  for (i = 1; i < numsSize; i++) {
    andVal &= nums[i];
    orVal |= nums[i];
    if (nums[i] > maxVal) maxVal = nums[i];
  }

  // count bits of max value
  while (maxVal) {
    ++maxBits;
    maxVal >>= 1;
  }

  for (i = 0; i < maxBits; i++) {
    //// all bit is 1
    //if (andVal>>i & 1) continue;
    //// all bit is 0
    //if (!(orVal>>i & 1)) continue;

    if ((andVal>>i & 1) || !(orVal>>i & 1)) continue;

    oneCnt = 0;
    for (j = 0; j < numsSize; j++) {
      if (nums[j]>>i & 1) ++oneCnt; // count one
    }

    // update result
    ret += (numsSize - oneCnt) * oneCnt;
  }

  return ret;
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
  printf("%d\n", totalHammingDistance(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
