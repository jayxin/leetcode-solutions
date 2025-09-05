#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 给定一个含有 n 个正整数的数组和一个正整数 target 。
//
// 找出该数组中满足其总和大于等于 target 的长度最小的
//  [num_sl, num_sl+1, ..., num_sr-1, num_sr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

//  1 <= target <= 10^9
//  1 <= nums.length <= 10^5
//  1 <= nums[i] <= 10^4

//// #v1
//// 穷举, 超时
//#define min(a, b) (a < b ? a : b)
//
//int minSubArrayLen(int target, int *nums, int numsSize) {
  //// prefix sum
  //int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
  //sum[0] = 0;
  //sum[1] = nums[0];
  //for (int i = 2; i <= numsSize; ++i) {
    //sum[i] = sum[i - 1] + nums[i - 1];
  //}
//
  //if (sum[numsSize] < target) {
    //free(sum);
    //return 0;
  //}
//
  //int l = 0, r = numsSize - 1;
  //int ret = numsSize;
  //int is_ge = 0;
//
  //while (r >= 0) {
    //l = r;
    //if (nums[r] >= target) {
      //return 1;
    //}
    //while (l >= 0) {
      //if (sum[r + 1] - sum[l] >= target) {
        //is_ge = 1;
        //break;
      //}
      //l--;
    //}
    //if (is_ge) {
      //is_ge = 0;
      //ret = min(ret, r - l + 1);
    //}
    //r--;
  //}
//
  //free(sum);
//
  //return ret;
//}
//// #v1

// #v2
// 双指针
#define min(a, b) (a < b ? a : b)

int minSubArrayLen(int target, int *nums, int numsSize) {
  // prefix sum
  // sum[1..numsSize] -> nums[0..numsSize]
  int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
  sum[0] = 0;
  sum[1] = nums[0];
  for (int i = 2; i <= numsSize; ++i) {
    sum[i] = sum[i - 1] + nums[i - 1];
  }

  if (sum[numsSize] < target) {
    free(sum);
    return 0;
  }

  int r = numsSize - 1, l = r;
  int ret = numsSize;

  while (r >= 0 && l >= 0) {
    if (sum[r + 1] - sum[l] >= target) { // 满足条件
      ret = min(ret, r - l + 1);
      r--; // 移动右指针
    } else {
      l--; // 移动左指针
    }
  }

  free(sum);

  return ret;
}
// #v2

int main(int argc, char *argv[])
{
  int target;
  int *arr = (int *)malloc(sizeof(int) * 100);
  int len = 0;
  scanf("%d", &target);
  while (scanf("%d", arr + len) == 1) {
    len++;
  }

  printf("%d\n", minSubArrayLen(target, arr, len));

  free(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
