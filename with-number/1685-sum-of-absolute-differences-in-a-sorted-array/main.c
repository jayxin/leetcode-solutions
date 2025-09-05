#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1685. 有序数组中差绝对值之和 - 给你一个 非递减 有序整数数组 nums 。
// 请你建立并返回一个整数数组 result，它跟 nums 长度相同，且result[i] 等于 nums[i]  与数组中所有其他元素差的绝对值之和。
// 换句话说， result[i] 等于 sum(|nums[i]-nums[j]|) ，其中 0 <= j < nums.length 且 j != i （下标从 0 开始）。
//  
// 示例 1：
// 输入：nums = [2,3,5]
// 输出：[4,3,5]
// 解释：假设数组下标从 0 开始，那么
// result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
// result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
// result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。
// 示例 2：
// 输入：nums = [1,4,6,8,10]
// 输出：[24,15,13,15,21]
//  
// 提示：
//  * 2 <= nums.length <= 105
//  * 1 <= nums[i] <= nums[i + 1] <= 104

// #v1
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * numsSize), i, end = numsSize - 1;
  int *sum = (int *)malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;

  sum[0] = nums[0];
  for (i = 1; i < numsSize; i++) {
    sum[i] = sum[i-1] + nums[i];
  }

  int exp, plus, minus;

  ret[0] = sum[end] - nums[0] * numsSize;
  for (i = 1; i < end; i++) {
    plus = i;
    minus = numsSize - i - 1;
    exp = -1 * sum[i - 1] + sum[end] - sum[i] + plus * nums[i] - minus * nums[i];
    ret[i] = exp;
  }
  ret[end] = nums[end] * end - sum[end - 1];

  free(sum);
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
  int n, retSize;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  int *ret = getSumAbsoluteDifferences(arr, n, &retSize);
  print_1d_arr(ret, retSize);
  free_1d_arr(arr);
  free_1d_arr(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
