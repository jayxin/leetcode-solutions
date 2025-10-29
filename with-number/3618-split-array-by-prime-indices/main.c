#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3618. 根据质数下标分割数组 - 给你一个整数数组 nums。
// 根据以下规则将 nums 分割成两个数组 A 和 B：
//  * nums 中位于 质数 下标的元素必须放入数组 A。
//  * 所有其他元素必须放入数组 B。
// 返回两个数组和的 绝对 差值：|sum(A) - sum(B)|。
// 质数 是一个大于 1 的自然数，它只有两个因子，1和它本身。
// 注意：空数组的和为 0。
//  
// 示例 1:
// 输入: nums = [2,3,4]
// 输出: 1
// 解释:
//  * 数组中唯一的质数下标是 2，所以 nums[2] = 4 被放入数组 A。
//  * 其余元素 nums[0] = 2 和 nums[1] = 3 被放入数组 B。
//  * sum(A) = 4，sum(B) = 2 + 3 = 5。
//  * 绝对差值是 |4 - 5| = 1。
// 示例 2:
// 输入: nums = [-1,5,7,0]
// 输出: 3
// 解释:
//  * 数组中的质数下标是 2 和 3，所以 nums[2] = 7 和 nums[3] = 0 被放入数组 A。
//  * 其余元素 nums[0] = -1 和 nums[1] = 5 被放入数组 B。
//  * sum(A) = 7 + 0 = 7，sum(B) = -1 + 5 = 4。
//  * 绝对差值是 |7 - 4| = 3。
//  
// 提示:
//  * 1 <= nums.length <= 105
//  * -109 <= nums[i] <= 109

//// #v1
//#define abs(x) ((x) >= 0 ? (x) : -(x))
//
//long long splitArray(int* nums, int numsSize) {
  //if (numsSize == 1) return abs(nums[0]);
//
  //int64_t sumA = 0LL, sumB = 0LL;
  //char isPrime[numsSize + 1];
//
  //memset(isPrime, 1, sizeof(isPrime));
  //sumB += nums[0] + nums[1];
//
  //for (int i = 2; i < numsSize; i++) {
    //if (isPrime[i]) {
      //sumA += nums[i];
//
      //for (int j = i; j <= numsSize / i; j++) {
        //isPrime[i*j] = 0;
      //}
    //} else {
      //sumB += nums[i];
    //}
  //}
//
  //sumA -= sumB;
//
  //return abs(sumA);
//}
//// #v1

// #v2
#define abs(x) ((x) >= 0 ? (x) : -(x))

long long splitArray(int* nums, int numsSize) {
  // edge case
  if (numsSize == 1) return abs(nums[0]);

  int64_t sumA = 0LL;
  char isPrime[numsSize + 1];

  // init
  memset(isPrime, 1, sizeof(isPrime));
  sumA -= nums[0] + nums[1];

  // compute
  for (int i = 2; i < numsSize; i++) {
    if (isPrime[i]) {
      sumA += nums[i];

      for (int j = i; j <= numsSize / i; j++) isPrime[i*j] = 0;
    } else {
      sumA -= nums[i];
    }
  }

  return abs(sumA);
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%lld\n", splitArray(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
