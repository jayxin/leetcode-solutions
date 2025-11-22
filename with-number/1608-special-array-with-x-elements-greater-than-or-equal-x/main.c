#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1608. 特殊数组的特征值 - 给你一个非负整数数组 nums 。如果存在一个数 x ，使得 nums 中恰好有 x 个元素 大于或者等于 x ，那么就称 nums 是一个 特殊数组 ，而 x 是该数组的 特征值 。
// 注意： x 不必 是 nums 的中的元素。
// 如果数组 nums 是一个 特殊数组 ，请返回它的特征值 x 。否则，返回 -1 。可以证明的是，如果 nums 是特殊数组，那么其特征值 x 是 唯一的 。
//  
// 示例 1：
// 输入：nums = [3,5]
// 输出：2
// 解释：有 2 个元素（3 和 5）大于或等于 2 。
// 示例 2：
// 输入：nums = [0,0]
// 输出：-1
// 解释：没有满足题目要求的特殊数组，故而也不存在特征值 x 。
// 如果 x = 0，应该有 0 个元素 >= x，但实际有 2 个。
// 如果 x = 1，应该有 1 个元素 >= x，但实际有 0 个。
// 如果 x = 2，应该有 2 个元素 >= x，但实际有 0 个。
// x 不能取更大的值，因为 nums 中只有两个元素。
// 示例 3：
// 输入：nums = [0,4,3,0,4]
// 输出：3
// 解释：有 3 个元素大于或等于 3 。
// 示例 4：
// 输入：nums = [3,6,7,7,0]
// 输出：-1
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 0 <= nums[i] <= 1000

// #v1
// sort, binary search

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int specialArray(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);

  for (int i = 0; i <= numsSize; i++) {
    int l = 0, r = numsSize - 1, m;
    while (l < r) {
      m = (l + r) >> 1;

      if (nums[m] >= i) r = m;
      else l = m + 1;
    }

    if (nums[l] >= i && numsSize - l == i) {
      return i;
    }
  }

  return -1;
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", specialArray(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
