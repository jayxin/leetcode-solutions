#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1480. 一维数组的动态和 - 给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
// 请返回 nums 的动态和。
//  
// 示例 1：
// 输入：nums = [1,2,3,4]
// 输出：[1,3,6,10]
// 解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
// 示例 2：
// 输入：nums = [1,1,1,1,1]
// 输出：[1,2,3,4,5]
// 解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
// 示例 3：
// 输入：nums = [3,1,2,10,1]
// 输出：[3,4,6,16,17]
// 提示：
//  * 1 <= nums.length <= 1000
//  * -10^6 <= nums[i] <= 10^6

// #v1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
  if (!nums) return NULL;
  *returnSize = numsSize;
  int *ret = (int *)malloc(sizeof(int) * numsSize);
  ret[0] = nums[0];
  for (int i = 1; i < numsSize; i++) {
    ret[i] = ret[i - 1] + nums[i];
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, len;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  int *ret = runningSum(arr, n, &len);
  print_1d_arr(ret, len);
  free_1d_arr(arr);
  free_1d_arr(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
