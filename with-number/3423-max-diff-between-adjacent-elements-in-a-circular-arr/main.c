#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3423. 循环数组中相邻元素的最大差值 - 给你一个 循环 数组 nums ，请你找出相 邻元素之间的 最大 绝对差值。
// 注意：一个循环数组中，第一个元素和最后一个元素是相邻的。
//  
// 示例 1：
// 输入：nums = [1,2,4]
// 输出：3
// 解释：
// 由于 nums 是循环的，nums[0] 和 nums[2] 是相邻的，它们之间的绝对差值是最大值 |4 - 1| = 3 。
// 示例 2：
// 输入：nums = [-5,-10,-5]
// 输出：5
// 解释：
// 相邻元素 nums[0] 和 nums[1] 之间的绝对差值为最大值 |-5 - (-10)| = 5 。
//  
// 提示：
//  * 2 <= nums.length <= 100
//  * -100 <= nums[i] <= 100

// #v1
int abs(int a) {
  return (a >= 0 ? a : -a);
}

int max(int a, int b) {
  return (a > b ? a : b);
}

int maxAdjacentDistance(int* nums, int numsSize) {
  int ret = nums[0] - nums[numsSize - 1], t, b = numsSize - 1;
  ret = abs(ret);
  for (int i = 0; i < b; i++) {
    t = nums[i] - nums[i + 1];
    t = abs(t);
    ret = max(ret, t);
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
  int n;
  scanf("%d", &n);
  int *a = read_1d_arr(n);
  printf("%d\n", maxAdjacentDistance(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
