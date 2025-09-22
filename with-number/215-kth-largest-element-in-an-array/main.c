#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 215. 数组中的第K个最大元素 - 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
//  
// 示例 1:
// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5
// 示例 2:
// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4
//  
// 提示：
//  * 1 &lt;= k &lt;= nums.length &lt;= 105
//  * -104 &lt;= nums[i] &lt;= 104

// #v1
// 快速选择
int partition(int *a, int n) {
  //int s = 0, end = n - 1, val = a[n>>1], t;

  //for (int i = 0; i < end; i++) {
  //  if (a[i] <= val) {
  //    if (i == s) {
  //      ++s;
  //      continue;
  //    }
  //    t = a[i];
  //    a[i] = a[s];
  //    a[s] = t;
  //    s++;
  //  }
  //}

  //a[end] = a[s];
  //a[s] = val;

  // corner case
  if (n == 1) return 0;
  if (n == 2) {
    if (a[0] > a[1]) {
      int tmp = a[0];
      a[0] = a[1];
      a[1] = tmp;
    }
    return 1;
  }

  int end = n - 1, val = a[n>>1], t, l = 1, r = end;
  a[n>>1] = a[0];

  while (l < r) {
    // 移动指针
    while (l < end && a[l] <= val) l++;
    while (r > 0 && a[r] >= val) r--;

    // 交换
    if (l < r && a[l] > a[r]) {
      t = a[l];
      a[l] = a[r];
      a[r] = t;
    }
  }

  a[0] = a[r];
  a[r] = val;

  return r;
}

int selectK(int *a, int n, int k) {
  if (n <= 0) return 0;
  if (n == 1) return a[0];

  int q = partition(a, n);
  if (q == k) {
    return a[q];
  } else if (q < k) {
    int t = q + 1;
    return selectK(a + t, n - t, k - t);
  }
  return selectK(a, q, k);
}

int findKthLargest(int* nums, int numsSize, int k) {
  // 第 k 大元素就是第 numsSize-k+1 小元素
  return selectK(nums, numsSize, numsSize - k);
}
// #v1

//// #v2
//// 大根堆, 弹出 k-1 个
//int *h, size, tmp;
//
//void HeapSwap(int i, int j) {
  //tmp = h[i];
  //h[i] = h[j];
  //h[j] = tmp;
//}
//
//void HeapUp(int p) { // 向上调整
  //while (p > 1) {
    //if (h[p] > h[p>>1]) {
      //HeapSwap(p, p>>1);
      //p >>= 1;
    //} else {
      //return ;
    //}
  //}
//}
//
//void HeapDown(int p) { // 向下调整
  //int s = p << 1;
//
  //while (s <= size) {
    //if (s < size && h[s] < h[s+1]) s++;
    //if (h[s] > h[p]) {
      //HeapSwap(s, p);
      //p = s;
      //s <<= 1;
    //} else {
      //return ;
    //}
  //}
//}
//
//void HeapInsert(int v) {
  //h[++size] = v;
  //HeapUp(size);
//}
//
//void HeapExtract() {
  //h[1] = h[size--];
  //HeapDown(1);
//}
//
//int findKthLargest(int* nums, int numsSize, int k) {
  //int t[numsSize+1];
  //h = t;
  //size = 0;
//
  //for (int i = 0; i < numsSize; i++) {
    //HeapInsert(nums[i]);
  //}
//
  //while (--k) {
    //HeapExtract();
  //}
//
  //return h[1];
//}
//// #v2

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
  printf("%d\n", findKthLargest(a, n, k));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
