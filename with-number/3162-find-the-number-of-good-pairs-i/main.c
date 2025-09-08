#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3162. 优质数对的总数 I - 给你两个整数数组 nums1 和 nums2，长度分别为 n 和 m。同时给你 一个正整数 k。
// 如果 nums1[i] 可以除尽 nums2[j] * k，则称数对 (i, j) 为 优质数对（0 <= i <= n - 1, 0 <= j <= m - 1）。
// 返回 优质数对 的总数。
//  
// 示例 1：
// 输入：nums1 = [1,3,4], nums2 = [1,3,4], k = 1
// 输出：5
// 解释：
// 5个优质数对分别是 (0, 0), (1, 0), (1, 1), (2, 0), 和 (2, 2)。
// 示例 2：
// 输入：nums1 = [1,2,4,12], nums2 = [2,4], k = 3
// 输出：2
// 解释：
// 2个优质数对分别是 (3, 0) 和 (3, 1)。
//  
// 提示：
//  * 1 <= n, m <= 50
//  * 1 <= nums1[i], nums2[j] <= 50
//  * 1 <= k <= 50

// #v1
int numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
  int ret = 0, i, j, a;
  for (i = 0; i < nums1Size; i++) {
    for (j = 0; j < nums2Size; j++) {
      a = nums2[j] * k;
      if ((nums1[i] >= a) && (nums1[i] % a) == 0) {
        ret++;
      }
    }
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
  int n1, n2, *a1, *a2, k;
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &n2);
  a2 = read_1d_arr(n2);
  scanf("%d", &k);
  printf("%d\n", numberOfPairs(a1, n1, a2, n2, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
