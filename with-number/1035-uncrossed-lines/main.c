#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1035. 不相 交的线 - 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
// 现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足 ：
//  *  nums1[i] == nums2[j]
//  * 且绘制的直线不与任何其他连线（非水平线）相交。
// 请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
// 以这种方法绘制线条，并返回可以绘制的最大连线数。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2019/04/26/142.png]
// 输入：nums1 = [1,4,2], nums2 = [1,2,4]
// 输出：2
// 解释：可以画出两条不交叉的线，如上图所示。
// 但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
// 示例 2：
// 输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
// 输出：3
// 示例 3：
// 输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
// 输出：2
//  
// 提示：
//  * 1 <= nums1.length, nums2.length <= 500
//  * 1 <= nums1[i], nums2[j] <= 2000

//// #v1
//// 基础模型
//int max(int a, int b) { return a >= b ? a : b; }
//
//int *a1, *a2, n1, n2;
//
//int f(int i, int j) {
  //if (i == n1 || j == n2) return 0;
//
  //if (a1[i] == a2[j]) return 1 + f(i+1, j+1);
//
  //int v1 = f(i+1, j);
  //int v2 = f(i, j+1);
  //int v3 = f(i+1, j+1);
//
  //return max(v1, max(v2, v3));
//}
//
//int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  //a1 = nums1;
  //n1 = nums1Size;
  //a2 = nums2;
  //n2 = nums2Size;
//
  //return f(0, 0);
//}
//// #v1

//// #v2
//// 动态规划, 记忆化搜索
//int max(int a, int b) { return a >= b ? a : b; }
//
//int *a1, *a2, n1, n2, **tab;
//
//int f(int i, int j) {
  ////if (i == n1 || j == n2) return 0;
//
  //if (tab[i][j] >= 0) return tab[i][j];
//
  //if (a1[i] == a2[j]) {
    //tab[i][j] = 1 + f(i+1, j+1);
    //return tab[i][j];
  //}
//
  //int v1 = f(i+1, j);
  //int v2 = f(i, j+1);
//
  //tab[i][j] = max(v1, v2);
//
  //return tab[i][j];
//}
//
//int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  //a1 = nums1;
  //n1 = nums1Size;
  //a2 = nums2;
  //n2 = nums2Size;
//
  //int *t[n1+1], ret;
//
  //// init
  //for (int i = 0; i <= n1; i++) {
    //t[i] = calloc(n2+1, sizeof(int));
    //memset(t[i], 0xff, sizeof(int) *(n2+1));
    //t[i][n2] = 0;
  //}
  ////for (int i = 0; i <= n1; i++) t[i][n2] = 0;
  ////for (int j = 0; j <= n2; j++) t[n1][j] = 0;
  //memset(t[n1], 0, sizeof(int) * (n2+1));
  //tab = t;
//
  //// compute
  //ret = f(0, 0);
//
  //// free
  //for (int i = 0; i <= n1; i++) free(t[i]);
//
  //return ret;
//}
//// #v2

// #v3
// 动态规划, 递推
int max(int a, int b) { return a >= b ? a : b; }

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  // dp[i][j] 表示 nums1[0...(i-1)] 和 nums2[0...(j-1)] 可以绘制的最大连线数
  int dp[nums1Size+1][nums2Size+1], i, j;

  // init
  dp[0][0] = 0;
  for (i = 1; i <= nums1Size; i++) dp[i][0] = 0;
  for (j = 1; j <= nums2Size; j++) dp[0][j] = 0;

  // compute
  for (i = 0; i < nums1Size; i++) {
    for (j = 0; j < nums2Size; j++) {
      if (nums1[i] == nums2[j]) {
        dp[i+1][j+1] = 1 + dp[i][j];
      } else {
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
      }
    }
  }

  return dp[nums1Size][nums2Size];
}
// #v3

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
  int *a0, *a1, n0, n1;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  printf("%d\n", maxUncrossedLines(a0, n0, a1, n1));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
