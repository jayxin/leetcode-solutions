#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2956. 找到两个数组中的公共元素 - 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们分别含有 n 和 m 个元素。请你计算以下两个数值：
//  * answer1：使得 nums1[i] 在 nums2 中出现的下标 i 的数量。
//  * answer2：使得 nums2[i] 在 nums1 中出现的下标 i 的数量。
// 返回 [answer1, answer2]。
//  
// 示例 1：
// 输入：nums1 = [2,3,2], nums2 = [1,2]
// 输出：[2,1]
// 解释：
// [https://assets.leetcode.com/uploads/2024/05/26/3488_find_common_elements_between_two_arrays-t1.gif]
// 示例 2：
// 输入：nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
// 输出：[3,4]
// 解释：
// nums1 中下标在 1，2，3 的元素在 nums2 中也存在。所以 answer1 为 3。
// nums2 中下标在 0，1，3，4 的元素在 nums1 中也存在。所以 answer2 为 4。
// 示例 3：
// 输入：nums1 = [3,4,2,3], nums2 = [1,5]
// 输出：[0,0]
// 解释：
// nums1 和 nums2 中没有相同的数字，所以答案是 [0,0]。
//  
// 提示：
//  * n == nums1.length
//  * m == nums2.length
//  * 1 <= n, m <= 100
//  * 1 <= nums1[i], nums2[i] <= 100

// #v1
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  *returnSize = 2;
  int *ret = (int *)malloc(sizeof(int) * 2), i;
  char t1[101] = {0}, t2[101] = {0};

  ret[0] = ret[1] = 0;

  for (i = 0; i < nums1Size; i++) t1[nums1[i]] = 1;
  for (i = 0; i < nums2Size; i++) t2[nums2[i]] = 1;

  for (i = 0; i < nums1Size; i++) {
    if (t2[nums1[i]]) ++ret[0];
  }

  for (i = 0; i < nums2Size; i++) {
    if (t1[nums2[i]]) ++ret[1];
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

int main(int argc, char *argv[])
{
  int n0, n1, *a0, *a1, *ret, s;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  ret = findIntersectionValues(a0, n0, a1, n1, &s);
  print_1d_arr(ret, s);
  free(a0);
  free(a1);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
