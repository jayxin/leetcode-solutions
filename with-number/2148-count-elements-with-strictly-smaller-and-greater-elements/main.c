#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2148. 元素计 数 - 给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。
//  
// 示例 1：
// 输入：nums = [11,7,2,15]
// 输出：2
// 解释：元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
// 元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
// 总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
// 示例 2：
// 输入：nums = [-3,3,3,90]
// 输出：2
// 解释：元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
// 由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素 和一个严格较大元素。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * -105 <= nums[i] <= 105

// #v1
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int countElements(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int min = nums[0], max = nums[numsSize - 1], ret = numsSize, i;

  // edge case
  if (min == max) return 0;

  for (i = 0; i < numsSize; i++) {
    if (nums[i] == min) --ret;
    else break;
  }

  for (i = numsSize - 1; i >= 0; i--) {
    if (nums[i] == max) --ret;
    else break;
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", countElements(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
