#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 153. 寻找旋转排序数组中的最小值 - 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化 后可能得到：
//  * 若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
//  * 若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
// 给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
// 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
//  
// 示例 1：
// 输入：nums = [3,4,5,1,2]
// 输出：1
// 解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
// 示例 2：
// 输入：nums = [4,5,6,7,0,1,2]
// 输出：0
// 解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
// 示例 3：
// 输入：nums = [11,13,15,17]
// 输出：11
// 解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
//  
// 提示：
//  * n == nums.length
//  * 1 &lt;= n &lt;= 5000
//  * -5000 &lt;= nums[i] &lt;= 5000
//  * nums 中的所有整数 互不相同
//  * nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转

//// #v1
//int findMin(int* nums, int numsSize) {
  //// 数组长度为 1, 直接返回第 1 个元素
  //if (numsSize == 1) return nums[0];
//
  //int l = 0, r = numsSize - 1, m, prev, next;
//
  //// nums[l] <  nums[m] < nums[r]
  //// nums[l] <  nums[m] > nums[r]
  //// nums[l] >  nums[m] > nums[r]
  //// nums[l] >  nums[m] < nums[r]
  //while (l < r) {
    //// 选取中点
    //m = (l + r) >> 1;
//
    //if (nums[l] < nums[m] && nums[m] < nums[r]) {
      //return nums[l];
    //}
//
    //if (m == 0 && nums[m] < nums[m+1] && nums[m] < nums[r]) { // 第一个元素
      //return nums[0];
    //} else if (m == numsSize - 1 && nums[m] < nums[0] && nums[m] < nums[m-1]) { // 最后一个元素
      //return nums[numsSize - 1];
    //} else {
      //prev = m - 1;
      //next = m + 1;
      //if (prev >= 0 && next < numsSize) {
        //if (nums[m] < nums[prev] && nums[m] < nums[next]) { // 中间元素
          //return nums[m];
        //}
      //}
    //}
//
    //if (nums[l] < nums[m] && nums[m] > nums[r]) {
      //l = m + 1;
    //} else if (nums[l] > nums[m] && nums[m] < nums[r]) {
      //r = m;
    //} else if (nums[m] < nums[l] && nums[m] < nums[r]) {
      //r = m;
    //} else {
      //l = m + 1;
    //}
  //}
//
  //return nums[l];
//}
//// #v1

// #v2
int findMin(int* nums, int numsSize) {
  int l = 0, r = numsSize - 1, m, prev, next;

  // nums[l] <  nums[m] < nums[r]
  // nums[l] <  nums[m] > nums[r]
  // nums[l] >  nums[m] > nums[r]
  // nums[l] >  nums[m] < nums[r]
  while (l < r) {
    // 选取中点
    m = (l + r) >> 1;

    // nums[l] < nums[m] < nums[r], [l, r] 区间内的数整体有序
    if (nums[l] < nums[m] && nums[m] < nums[r]) {
      return nums[l];
    }

    // 注意这里的索引计算, 始终保持 prev 和 next 在 [0, numsSize - 1]
    prev = m - 1;
    next = (m + 1) % numsSize;
    if (prev < 0) {
      prev += numsSize;
    }
    // nums[prev] > nums[m] < nums[next]
    if (nums[m] < nums[prev] && nums[m] < nums[next]) {
      return nums[m];
    }

    // nums[l] < nums[m] > nums[r]
    if (nums[l] < nums[m] && nums[m] > nums[r]) {
      l = m + 1;
    } else if (nums[l] > nums[m] && nums[m] < nums[r]) { // nums[l] > nums[m] < nums[r]
      r = m;
    } else { // nums[l] > nums[m] > nums[r]
      l = m + 1;
    }
  }

  return nums[l];
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
  printf("%d\n", findMin(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
