#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2605. 从两个数字数组里生成最小数字 - 给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至 少 包含这个数字的某个数位。
//  
// 示例 1：
// 输入：nums1 = [4,1,3], nums2 = [5,7]
// 输出：15
// 解释：数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
// 示例 2：
// 输入：nums1 = [3,5,2,6], nums2 = [3,1,7]
// 输出：3
// 解释：数字 3 的数位 3 在两个数组中都出现了。
//  
// 提示：
//  * 1 <= nums1.length, nums2.length <= 9
//  * 1 <= nums1[i], nums2[i] <= 9
//  * 每个数组中，元素 互不相同 。

// #v1
int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  char t[10] = {0}, min1 = 11, min2 = 11;
  int i;

  for (i = 0; i < nums1Size; i++) {
    ++t[nums1[i]];
    if (nums1[i] < min1) min1 = nums1[i];
  }

  for (i = 0; i < nums2Size; i++) {
    ++t[nums2[i]];
    if (nums2[i] < min2) min2 = nums2[i];
  }

  for (int i = 0; i < 10; i++) {
    if (t[i] == 2) return i;
  }

  if (min1 > min2) return min2 * 10 + min1;

  return min1 * 10 + min2;
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
  int *a0, n0, *a1, n1;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  printf("%d\n", minNumber(a0, n0, a1, n1));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
