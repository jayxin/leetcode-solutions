#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2529. 正整数和负整数的最大计数 - 给你一个按 非递减顺序 排列的数组 nums ，返回 正整数数目和负整数数目中的最大值。
//  * 换句话讲，如果 nums 中正整数的数目是 pos ，而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。
// 注意：0 既不是正整数也不是负整数。
//  
// 示例 1：
// 输入：nums = [-2,-1,-1,1,2,3]
// 输出：3
// 解释：共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
// 示例 2：
// 输入：nums = [-3,-2,-1,0,0,1,2]
// 输出：3
// 解释：共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
// 示例 3：
// 输入：nums = [5,20,66,1314]
// 输出：4
// 解释：共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。
//  
// 提示：
//  * 1 <= nums.length <= 2000
//  * -2000 <= nums[i] <= 2000
//  * nums 按 非递减顺序 排列。
//  
// 进阶：你可以设计并实现时间复杂度为 O(log(n)) 的算法解决此问题吗？

//// #v1
//// 计数, 遍历整个数组
//#define max(a, b) ((a) >= (b) ? (a) : (b))
//int maximumCount(int* nums, int numsSize) {
  //int pos = 0, neg = 0;
//
  //for (int i = 0; i < numsSize; i++) {
    //if (nums[i] > 0) ++pos;
    //else if (nums[i] < 0) ++neg;
  //}
//
  //return max(neg, pos);
//}
//// #v1

// #v2
// binary search
#define max(a, b) ((a) >= (b) ? (a) : (b))
int maximumCount(int* nums, int numsSize) {
  int l, r, m;
  int pos = 0, neg = 0;

  // 查找最右边的负数
  l = 0, r = numsSize - 1;
  while (l < r) {
    m = (l + r + 1) >> 1;

    if (nums[m] < 0) l = m;
    else r = m - 1;
  }
  if (nums[l] < 0) neg = l + 1;

  // 查找最左边的正数
  l = 0, r = numsSize - 1;
  while (l < r) {
    m = (l + r) >> 1;

    if (nums[m] > 0) r = m;
    else l = m + 1;
  }
  if (nums[l] > 0) pos = numsSize - l;

  return max(neg, pos);
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
  printf("%d\n", maximumCount(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
