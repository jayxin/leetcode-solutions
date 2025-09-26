#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 747. 至少是其他数字两倍的最大数 - 给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
// 请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则 返回 最大元素的下标 ，否则返回 -1 。
//  
// 示例 1：
// 输入：nums = [3,6,1,0]
// 输出：1
// 解释：6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下 标是 1 ，所以返回 1 。
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：-1
// 解释：4 没有超过 3 的两倍大，所以返回 -1 。
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 50
//  * 0 &lt;= nums[i] &lt;= 100
//  * nums 中的最大元素是唯一的

// #v1
int dominantIndex(int* nums, int numsSize) {
  int maxIdx = 0, max = nums[0], i;

  for (i = 1; i < numsSize; i++) {
    if (nums[i] > max) {
      max = nums[i];
      maxIdx = i;
    }
  }

  for (i = 0; i < numsSize; i++) {
    if (i != maxIdx) {
      if ((nums[i] << 1) > max) return -1;
    }
  }

  return maxIdx;
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
  printf("%d\n", dominantIndex(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
