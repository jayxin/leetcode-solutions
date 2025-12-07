#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2574. 左右元素和的差值 - 给你一个下标从 0 开始的长度为 n 的整数数组 nums。
// 定义两个数组 leftSum 和 rightSum，其中：
//  * leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
//  * rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
// 返回长度为 n 数组 answer，其中 answer[i] = |leftSum[i] - rightSum[i]|。
//  
// 示例 1：
// 输入：nums = [10,4,8,3]
// 输出：[15,1,11,22]
// 解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
// 数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
// 示例 2：
// 输入：nums = [1]
// 输出：[0]
// 解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
// 数组 answer 为 [|0 - 0|] = [0] 。
//  
// 提示：
//  * 1 <= nums.length <= 1000
//  * 1 <= nums[i] <= 105

// #v1
// prefix sum
int abs(int x) {
  return x >= 0 ? x : -x;
}

int min(int a, int b) {
  return a <= b ? a : b;
}

int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int prefixSum[numsSize+1], *ret = (int *)malloc(sizeof(int) * numsSize);

  prefixSum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    prefixSum[i+1] = prefixSum[i] + nums[i];
  }

  for (int i = 0; i < numsSize; i++) {
    int leftSum = prefixSum[i], rightSum = prefixSum[numsSize] - prefixSum[min(i+1, numsSize)];
    ret[i] = abs(leftSum - rightSum);
  }

  return ret;
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
  int n, *ret, s, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = leftRightDifference(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
