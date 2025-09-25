#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 377. 组合总 和 Ⅳ - 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
// 题目数据保证答案符合 32 位整数范围。
//  
// 示例 1：
// 输入：nums = [1,2,3], target = 4
// 输出：7
// 解释：
// 所有可能的组合为：
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// 请注意，顺序不同的序列被视作不同的组合。
// 示例 2：
// 输入：nums = [9], target = 3
// 输出：0
//  
// 提示：
//  * 1 <= nums.length <= 200
//  * 1 <= nums[i] <= 1000
//  * nums 中的所有元素 互不相同
//  * 1 <= target <= 1000
//  
// 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现， 需要向题目中添加哪些限制条件？

//// #v1
//// 正确但超时, 通过计算组合数累加答案
//// 因为阶乘时乘法溢出所以采用分解质因数的方式进行组合数的计算
//// 但因为递归枚举的解空间过大超出时间限制
//int ret, t[1000], *cnts;
//
//int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
//
//bool isPrime[1001];
//
//void divide(int n, int *c) {
  //if (isPrime[n]) { // 质数
    //c[n]++;
    //return ;
  //}
//
  //for (int i = 2; i <= sqrt(n); i++) {
    //if (n % i == 0) {
      //while (n % i == 0) {
        //n /= i;
        //c[i]++;
      //}
    //}
  //}
//
  //if (n > 1) { // 质数
    //isPrime[n] = true;
    //c[n]++;
  //}
//}
//
//void _combinationSum(int* a, int len, int target, int tLen) {
  //if (!len && target) return ;
//
  //if (target == 0) {
    //char visited[1001] = {0};
    //int i, j, q = 1, c = tLen;
    //int numerator[1001] = {0}, arrLen = 0;
//
    //for (i = 0; i < tLen; i++) {
      //if (visited[t[i]]) continue;
//
      //// 分解质因数
      //for (j = 2; j <= cnts[t[i]]; j++) {
        //divide(j, numerator);
      //}
//
      //visited[t[i]] = 1;
    //}
//
    //q = 1;
//
    //for (i = 2; i <= c; i++) {
      //int denominator[1001] = {0};
      //// 分解质因数
      //divide(i, denominator);
      //for (j = 2; j <= c; j++) {
        //if (denominator[j]) {
          //while (denominator[j] > 0 && numerator[j] > 0) {
            //--denominator[j];
            //--numerator[j];
          //}
          //// 分母有剩余, 计入答案
          //while (denominator[j]--) {
            //q *= j;
          //}
        //}
      //}
    //}
//
    //// 累加答案
    //ret += q;
//
    //return ;
  //}
//
  //// 剪枝
  //if (target < a[0]) return ;
//
  //// 递归枚举
  //int l = target / a[0];
  //int i, j;
//
  //for (i = l; i >= 0; i--) {
    //for (j = 0; j < i; j++) t[tLen + j] = a[0];
//
    //cnts[a[0]] += i;
    //_combinationSum(a + 1, len - 1, target - a[0] * i, tLen + i);
    //cnts[a[0]] -= i;
  //}
//}
//
//
//int combinationSum4(int* nums, int numsSize, int target) {
  //int c[1001] = {0};
//
  //ret = 0;
  //cnts = c;
  //qsort(nums, numsSize, sizeof(int), cmp);
  //memset(isPrime, 0, sizeof(bool) * 1001);
//
  //_combinationSum(nums, numsSize, target, 0);
//
  //return ret;
//}
//// #v1

// #v2
// 动态规划
int *arr, len, *t;
char *visited;
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int _combinationSum4(int n) {
  if (visited[n]) return t[n];
  if (n <= 0) return 0;

  for (int j = 0; j < len; j++) {
    if (arr[j] >= n) break;

    t[n] += _combinationSum4(n - arr[j]);
  }
  visited[n] = 1;

  return t[n];
}

int combinationSum4(int* nums, int numsSize, int target) {
  // dp[i] 表示和为 i 的元素组合的个数
  int dp[1001] = {0};
  char v[1001] = {0};

  // init
  arr = nums;
  len = numsSize;
  visited = v;
  t = dp;
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 0; i < numsSize; i++) dp[nums[i]] = 1;

  // 这里存在加法溢出
  //for (i = 1; i <= target; i++) {
  //  for (j = 0; j < numsSize; j++) {
  //    if (nums[j] >= i) break;

  //    dp[i] += dp[i - nums[j]];
  //  }
  //}

  return _combinationSum4(target);
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
  int n, *a, target;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &target);
  printf("%d\n", combinationSum4(a, n, target));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
