#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 350. 两个数组的交集 II - 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的 交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出 现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
//  
// 示例 1：
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2,2]
// 示例 2:
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[4,9]
//  
// 提示：
//  * 1 <= nums1.length, nums2.length <= 1000
//  * 0 <= nums1[i], nums2[i] <= 1000
//  
// 进阶：
//  * 如果给定的数组已经排好序呢？你将如何优化你的算法？
//  * 如果 nums1 的大小比 nums2 小，哪种方法更优？
//  * 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内 存中，你该怎么办？

// #v1
#define min(a, b) ((a) > (b) ? (b) : (a))
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int tab1[1001], tab2[1001];
  memset(tab1, 0, sizeof(int) * 1001);
  memset(tab2, 0, sizeof(int) * 1001);

  int *ret = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
  int retLen = 0, times, i, j;

  for (i = 0; i < nums1Size; i++) {
    tab1[nums1[i]] += 1;
  }

  for (i = 0; i < nums2Size; i++) {
    tab2[nums2[i]] += 1;
  }

  for (i = 0; i < nums1Size; i++) {
    if (tab2[nums1[i]] && tab1[nums1[i]]) {
      times = min(tab2[nums1[i]], tab1[nums1[i]]);
      for (j = 0; j < times; j++) {
        ret[retLen++] = nums1[i];
      }
      tab1[nums1[i]] = 0;
    }
  }

  *returnSize = retLen;

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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n1, n2, *a, *b, retSize;
  scanf("%d", &n1);
  a = read_1d_arr(n1);
  scanf("%d", &n2);
  b = read_1d_arr(n2);
  int *ret = intersect(a, n1, b, n2, &retSize);
  print_1d_arr(ret, retSize);
  free(a);
  free(b);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
