#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1385. 两个数组间的距离值 - 给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。
// 「距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。
//  
// 示例 1：
// 输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
// 输出：2
// 解释：
// 对于 arr1[0]=4 我们有：
// |4-10|=6 > d=2
// |4-9|=5 > d=2
// |4-1|=3 > d=2
// |4-8|=4 > d=2
// 所以 arr1[0]=4 符合距离要求
// 对于 arr1[1]=5 我们有：
// |5-10|=5 > d=2
// |5-9|=4 > d=2
// |5-1|=4 > d=2
// |5-8|=3 > d=2
// 所以 arr1[1]=5 也符合距离要求
// 对于 arr1[2]=8 我们有：
// |8-10|=2 <= d=2
// |8-9|=1 <= d=2
// |8-1|=7 > d=2
// |8-8|=0 <= d=2
// 存在距离小于等于 2 的情况，不符合距离要求
// 故而只有 arr1[0]=4 和 arr1[1]=5 两个符合距离要求，距离值为 2
// 示例 2：
// 输入：arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
// 输出：2
// 示例 3：
// 输入：arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
// 输出：1
//  
// 提示：
//  * 1 <= arr1.length, arr2.length <= 500
//  * -10^3 <= arr1[i], arr2[j] <= 10^3
//  * 0 <= d <= 100

// #v1
// sort, binary search
// find lower bound and upper bound of target
// check difference between lower bound and upper bound
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int abs(int x) { return x >= 0 ? x : -x; }

int upperBound(int *a, int n, int t) {
  int l = 0, r = n - 1, m;

  while (l < r) {
    m = (l + r) >> 1;

    if (a[m] >= t) r = m;
    else l = m + 1;
  }

  return a[l];
}

int lowerBound(int *a, int n, int t) {
  int l = 0, r = n - 1, m;

  while (l < r) {
    m = (l + r + 1) >> 1;

    if (a[m] <= t) l = m;
    else r = m - 1;
  }

  return a[l];
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
  int ret = 0, i, l, u;

  qsort(arr2, arr2Size, sizeof(int), cmp);

  for (i = 0; i < arr1Size; i++) {
    l = lowerBound(arr2, arr2Size, arr1[i]);
    u = upperBound(arr2, arr2Size, arr1[i]);

    if (abs(l - arr1[i]) > d && abs(u - arr1[i]) > d) ++ret;
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
  int *a0, n0, *a1, n1, d;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &d);
  printf("%d\n", findTheDistanceValue(a0, n0, a1, n1, d));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
