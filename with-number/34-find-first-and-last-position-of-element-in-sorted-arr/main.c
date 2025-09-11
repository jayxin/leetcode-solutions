#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 34. 在排序数组中查找元素的第一个和最后一个位置 - 给你一个按照 非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的 开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//  
// 示例 1：
// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 示例 2：
// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 示例 3：
// 输入：nums = [], target = 0
// 输出：[-1,-1]
//  
// 提示：
//  * 0 <= nums.length <= 105
//  * -109 <= nums[i] <= 109
//  * nums 是一个非递减数组
//  * -109 <= target <= 109

// #v1
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;

  int *ret = (int *)malloc(sizeof(int) * 2), l = 0, r = numsSize - 1, m;
  ret[0] = ret[1] = -1;;

  // 特殊情况, 数组长度为 0
  if (numsSize == 0) return ret;

  // 查找左边界, 太大往左走
  while (l < r) {
    m = (l + r) >> 1; // 这里不用 +1

    if (nums[m] >= target) { // 在左半段
      r = m;
    } else { // 在右半段
      l = m + 1;
    }
  }
  if (nums[l] == target)
    ret[0] = l;

  // 查找右边界, 太小往右走
  l = 0; r = numsSize - 1;
  while (l < r) {
    m = (l + r + 1) >> 1; // 这里 +1 防止死循环

    if (nums[m] <= target) { // 在右半段
      l = m;
    } else { // 在左半段
      r = m - 1;
    }
  }
  if (nums[l] == target)
    ret[1] = l;

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  if (!n) return NULL;
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
  int n, *a, *ret, s, target;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &target);
  ret = searchRange(a, n, target, &s);
  print_1d_arr(ret, s);

  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
