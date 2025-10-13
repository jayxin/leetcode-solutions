#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 152. 乘 积最大子数组 - 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（ 该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
// 测试用例的答案是一个 32-位 整数。
//  
// 示例 1:
// 输入: nums = [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:
// 输入: nums = [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
//  
// 提示:
//  * 1 &lt;= nums.length &lt;= 2 * 104
//  * -10 &lt;= nums[i] &lt;= 10
//  * nums 的任何子数组的乘积都 保证 是一个 32-位 整数

//// #v1
//// 动态规划
//int max(int a, int b) { return a >= b ? a : b; }
//int min(int a, int b) { return a >= b ? b : a; }
//
//int maxProduct(int* nums, int numsSize) {
  //// maxState[i] 表示以 nums[i] 结尾的最大子数组的乘积值
  //// minState[i] 表示以 nums[i] 结尾的最小子数组的乘积值
  //// 因为数组中出现负数, 所以需要记录 minState
  //int maxState[numsSize], minState[numsSize], ret;
//
  //// init
  //maxState[0] = minState[0] = ret = nums[0];
//
  //// compute
  //for (int i = 1; i < numsSize; i++) {
    //maxState[i] = max(maxState[i-1]*nums[i], max(minState[i-1]*nums[i], nums[i]));
    //minState[i] = min(minState[i-1]*nums[i], min(maxState[i-1]*nums[i], nums[i]));
    //if (maxState[i] > ret) ret = maxState[i];
  //}
//
  //return ret;
//}
//// #v1

// #v2
// 动态规划
// 空间优化
//int max(int a, int b) { return a >= b ? a : b; }
//int min(int a, int b) { return a >= b ? b : a; }
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define min(a, b) ((a) >= (b) ? (b) : (a))

int maxProduct(int* nums, int numsSize) {
  // 因为数组中出现负数, 所以需要记录 minState
  int prevMaxState, prevMinState, maxState, minState, ret, v0, v1;

  // init
  prevMaxState = prevMinState = ret = nums[0];

  // compute
  for (int i = 1; i < numsSize; i++) {
    // state transfer
    //maxState = max(prevMaxState*nums[i], max(prevMinState*nums[i], nums[i]));
    //minState = min(prevMinState*nums[i], min(prevMaxState*nums[i], nums[i]));
    v0 = nums[i] * prevMinState;
    v1 = nums[i] * prevMaxState;
    maxState = max(v1, max(v0, nums[i]));
    minState = min(v1, min(v0, nums[i]));

    // update max value
    if (maxState > ret) ret = maxState;

    // update old value
    prevMaxState = maxState;
    prevMinState = minState;
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
  printf("%d\n", maxProduct(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
