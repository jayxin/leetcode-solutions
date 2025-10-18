#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 713. 乘积小于 K 的子数组 - 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
//  
// 示例 1：
// 输入：nums = [10,5,2,6], k = 100
// 输出：8
// 解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6] 、[5,2,6]。
// 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
// 示例 2：
// 输入：nums = [1,2,3], k = 0
// 输出：0
//  
// 提示: 
//  * 1 <= nums.length <= 3 * 104
//  * 1 <= nums[i] <= 1000
//  * 0 <= k <= 106

//// #v1
//// 乘法溢出错误
//// 前缀和, 滑动窗口, 二分查找
//int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
  //int i, j, cnt = 0;
  //int64_t prefixProduct[numsSize + 1];
//
  //prefixProduct[0] = 1;
  //for (i = 0; i < numsSize; i++) {
    //// NOTE: 这里存在乘法溢出
    //prefixProduct[i+1] = prefixProduct[i] * nums[i];
  //}
//
  //// j 是窗口的右边界
  //j = 0;
  //while (j < numsSize) {
    //if (nums[j] <= k) {
      //// 通过二分查找确定窗口的左边界
      //int l = 0, r = j, m;
      //while (l < r) {
        //m = (l + r) >> 1;
//
        //if (prefixProduct[j+1] / prefixProduct[m] < k) r = m;
        //else l = m + 1;
      //}
//
      //if (prefixProduct[j+1] / prefixProduct[l] < k) cnt += j - l + 1;
    //}
//
    //// 增加窗口的右边界
    //++j;
  //}
//
  //return cnt;
//}
//// #v1

// #v2
// 前缀和, 滑动窗口
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
  int cnt = 0, l, r, product;

  // l 是窗口的左边界, r 是窗口的右边界
  l = r = 0;
  // product 是窗口中所有元素的乘积
  // product == nums[l] * nums[l+1] * ... * nums[r]
  product = 1;
  while (r < numsSize) {
    if (nums[r] <= k) { // nums[r] 可以加入窗口
      // nums[r] 加入窗口
      product *= nums[r];

      while (l <= r) {
        if (product >= k) {
          // nums[l] 移出窗口
          product /= nums[l];
          ++l;
        }
        else break;
      }

      if (product < k) cnt += r - l + 1;
    } else {
      // 更新窗口的左边界, 准备进入下一次循环
      l = r + 1;
    }

    // 增加窗口的右边界
    ++r;
  }

  return cnt;
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
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", numSubarrayProductLessThanK(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
