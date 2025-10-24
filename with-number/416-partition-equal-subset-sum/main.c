#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 416. 分割 等和子集 - 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//  
// 示例 1：
// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
// 示例 2：
// 输入：nums = [1,2,3,5]
// 输出：false
// 解释：数组不能分割成两个元素和相等的子集。
//  
// 提示：
//  * 1 <= nums.length <= 200
//  * 1 <= nums[i] <= 100

//// #v1
//// 超时
//int *a, nn;
//
//bool check(int pos, int sum0, int sum1) {
  //if (pos == nn) {
    //return sum0 == sum1;
  //}
//
  //int v = a[pos++];
  //return check(pos, sum0+v, sum1) || check(pos, sum0, sum1+v);
//}
//
//bool canPartition(int* nums, int numsSize) {
  //a = nums;
  //nn = numsSize;
//
  //return check(0, 0, 0);
//}
//// #v1

//// #v2
//int *a, nn, h, **t;
//
//bool check(int pos, int sum) {
  //if (pos == nn) return sum == h;
//
  //if (t[pos][sum] >= 0) return t[pos][sum];
//
  //char f1 = 0, f2 = 0;
//
  //if (sum + a[pos] <= h) {
    //f1 = check(pos+1, sum+a[pos]);
  //}
  //f2 = check(pos+1, sum);
  //t[pos][sum] = f1 || f2;
//
  //return t[pos][sum];
//}
//
//bool canPartition(int* nums, int numsSize) {
  //a = nums;
  //nn = numsSize;
//
  //int sum = 0, i, *tab[numsSize];
//
  //for (i = 0; i < numsSize; i++) sum += nums[i];
//
  //if (sum & 1) return false;
//
  //h = sum >> 1;
//
  //for (i = 0; i < numsSize; i++) {
    //tab[i] = (int *)malloc(sizeof(int) * (h+1));
    //memset(tab[i], 0xff, sizeof(int) * (h+1));
  //}
  //t = tab;
//
  //return check(0, 0);
//}
//// #v2

//// #v3
//// 动态规划, 递推
//bool canPartition(int* nums, int numsSize) {
  //int sum = 0, i, j, *dp[numsSize], h;
//
  //for (i = 0; i < numsSize; i++) sum += nums[i];
  //// 数组元素和为奇数, 无法分割
  //if (sum & 1) return false;
  //h = sum>>1;
//
  //for (i = 0; i < numsSize; i++) {
    //dp[i] = (int *)malloc(sizeof(int) * (h+1));
    //memset(dp[i], 0, sizeof(int) * (h+1));
//
    //if (nums[i] <= h) dp[i][nums[i]] = 1;
  //}
//
  //// dp[i][j] 表示遍历至 nums[i] 时能否得到一个和为 j 的子集
//
  //for (i = 1; i < numsSize; i++) {
    //for (j = 0; j <= h; j++) {
      //dp[i][j] = dp[i-1][j];
//
      //if (j - nums[i] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
    //}
  //}
//
  //return dp[numsSize-1][h];
//}
//// #v3

// #v4
// 动态规划, 递推
bool canPartition(int* nums, int numsSize) {
  int sum = 0, i, j, h, maxVal = nums[0];
  char *p0, *p1, *tmp;
  bool ret;

  for (i = 0; i < numsSize; i++) {
    sum += nums[i];
    if (nums[i] > maxVal) maxVal = nums[i];
  }
  // 数组元素和为奇数, 无法分割
  if (sum & 1) return false;
  h = sum>>1;
  if (maxVal > h) return false;

  size_t bytes = sizeof(char) * (h + 1);
  p0 = (char *)malloc(bytes);
  p1 = (char *)malloc(bytes);
  memset(p0, 0, bytes);
  // 表示和为 nums[0] 的子集存在
  if (nums[0] <= h) p0[nums[0]] = 1;

  for (i = 1; i < numsSize; i++) {
    int b = nums[i];
    if (h < b) b = h;

    // 复制 nums[i-1] 的状态
    for (j = 0; j <= b; j++) p1[j] = p0[j];

    // 判断加入子集和不加入的状态
    for (j = nums[i]; j <= h; j++) {
      p1[j] = p0[j] || p0[j-nums[i]];
    }

    // swap
    tmp = p0;
    p0 = p1;
    p1 = tmp;
  }

  ret = p0[h];

  free(p0);
  free(p1);

  return ret;
}
// #v4

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
  if (canPartition(a, n))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
