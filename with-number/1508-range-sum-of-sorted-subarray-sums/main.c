#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1508. 子数组和排序后的区间和 - 给你一个数组 nums ，它包含 n 个正整数。你需要计算所有非空连续子数组的和，并将它们按升序排序，得到一个新的包含 n * (n + 1) / 2 个数字的数组。
// 请你返回在新数组中下标为 left 到 right （下标从 1 开始）的所有数字和（包括左右端 点）。由于答案可能很大，请你将它对 10^9 + 7 取模后返回。
//  
// 示例 1：
// 输入：nums = [1,2,3,4], n = 4, left = 1, right = 5
// 输出：13
// 解释：所有的子数组和为 1, 3, 6, 10, 2, 5, 9, 3, 7, 4 。将它们升序排序后，我们得到新的数组 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] 。下标从 le = 1 到 ri = 5 的和为 1 + 2 + 3 + 3 + 4 = 13 。
// 示例 2：
// 输入：nums = [1,2,3,4], n = 4, left = 3, right = 4
// 输出：6
// 解释：给定数组与示例 1 一样，所以新数组为 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] 。下标 从 le = 3 到 ri = 4 的和为 3 + 3 = 6 。
// 示例 3：
// 输入：nums = [1,2,3,4], n = 4, left = 1, right = 10
// 输出：50
//  
// 提示：
//  * 1 <= nums.length <= 10^3
//  * nums.length == n
//  * 1 <= nums[i] <= 100
//  * 1 <= left <= right <= n * (n + 1) / 2

//// #v1
//int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
//
//int rangeSum(int* nums, int numsSize, int n, int left, int right) {
  //const int mod = 1000000007;
  //int sum[n], i, j, ret = 0, arr[n * (n + 1) / 2], len = 0;
//
  //// prefix sum
  //sum[0] = nums[0];
  //for (i = 1; i < n; i++) {
    //sum[i] = sum[i-1] + nums[i];
  //}
//
  //for (i = 0; i < n; i++) {
    //for (j = i; j < n; j++) {
      //if (i)
        //arr[len++] = sum[j] - sum[i-1];
      //else
        //arr[len++] = sum[j];
    //}
  //}
//
  //qsort(arr, n * (n + 1) / 2, sizeof(int), cmp);
//
  //--left;
//
  //for (i = left; i < right; i++) {
    //ret += arr[i] % mod;
    //ret %= mod;
  //}
//
  //return ret;
//}
//// #v1

// #v2
// binary search, prefix sum, count

int mod;

// 计算子数组的和为 sum 的子数组的个数
int getCnt(int *prefixSum, int n, int sum) {
  int cnt = 0, j = 1, i;

  for (i = 0; i < n; i++) {
    // find j that prefixSum[j] - prefixSum[i] > sum
    // j 的有效范围是 [1, n]
    // prefixSum[j] - prefixSum[i] 是 num[i..j-1] 的和
    while (j <= n && prefixSum[j] - prefixSum[i] <= sum) ++j;
    // backward
    --j;

    // update counter
    cnt += j - i;
  }

  return cnt;
}

// 计算第 k 小的子数组的和
// binary search
int getKth(int *prefixSum, int n, int k) {
  int l = 0, r = prefixSum[n], m, cnt;

  while (l < r) {
    m = (l + r) >> 1;

    // 计算子数组的和 <= m 的子数组个数
    cnt = getCnt(prefixSum, n, m);

    // 子数组的和为 m 时, <= m 的子数组个数 < k
    // 说明第 k 小的子数组的和 > m
    if (cnt < k) l = m + 1;
    // 子数组的和为 m 时, <= m 的子数组个数 >= k
    // 说明第 k 小的子数组的和 <= m
    else r = m;
  }

  return l;
}

// 计算所有子数组的和中最小的 k 个之和
int getSum(int *prefixSum, int *prefixPrefixSum, int n, int k) {
  // v 是第 k 小的子数组和
  int v = getKth(prefixSum, n, k), sum = 0, cnt = 0, i, j;

  // 累加 < v 的子数组的和
  for (i = 0, j = 1; i < n; i++) {
    // j 的有效范围是 [1, n]
    // prefixSum[j] - prefixSum[i] 是 num[i..j-1] 的和
    while (j <= n && prefixSum[j] - prefixSum[i] < v) ++j;
    // backward
    --j;

    // prefixPrefixSum[j] - prefixPrefixSum[i] 是 prefixSum[i..j-1] 的和
    sum = ((int64_t)sum + prefixPrefixSum[j]-prefixPrefixSum[i] -prefixSum[i]*(j-i)) % mod;
    // 累计 < v 的子数组和的个数
    cnt += j - i;
  }

  // == v 单独计算
  sum = ((int64_t)sum + v * (k - cnt)) % mod;

  return sum;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
  mod = 1000000007;

  int prefixSum[n+1], prefixPrefixSum[n+1], i, j;

  // prefix sum of nums
  prefixSum[0] = 0;
  for (i = 0; i < n; i++) {
    prefixSum[i+1] = prefixSum[i] + nums[i];
  }

  // prefix sum of prefix sum
  prefixPrefixSum[0] = 0;
  for (i = 0; i < n; i++) {
    prefixPrefixSum[i+1] = prefixPrefixSum[i] + prefixSum[i+1];
  }

  // 大段 - 小段, 类似前缀和 [1, right] - [1, left-1] ==> [left, right]
  return ((int64_t)getSum(prefixSum, prefixPrefixSum, n, right) -
      getSum(prefixSum, prefixPrefixSum, n, left - 1)) % mod;
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
  int n, *a, l, r;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d%d", &l, &r);
  printf("%d\n", rangeSum(a, n, n, l, r));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
