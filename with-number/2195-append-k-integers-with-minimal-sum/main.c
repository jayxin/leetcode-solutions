#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2195. 向数组中追加 K 个整数 - 给你一个整数数组 nums 和一个整数 k 。请你向 nums 中追加 k 个 未 出现在 nums 中的、互不相同 的 正 整数，并使结果数组的元素和 最小 。
// 返回追加到 nums 中的 k 个整数之和。
//  
// 示例 1：
// 输入：nums = [1,4,25,10,25], k = 2
// 输出：5
// 解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 2 和 3 。
// nums 最终元素和为 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70 ，这是所有情况中的最小值。
// 所以追加到数组中的两个整数之和是 2 + 3 = 5 ，所以返回 5 。
// 示例 2：
// 输入：nums = [5,6], k = 6
// 输出：25
// 解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 1 、2 、3 、4 、7 和 8 。
// nums 最终元素和为 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36 ，这是所有情况中的最小值。
// 所以追加到数组中的两个整数之和是 1 + 2 + 3 + 4 + 7 + 8 = 25 ，所以返回 25 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i], k <= 109
// 1. The k smallest numbers that do not appear in nums will result in the
// minimum sum.
// 2. Recall that the sum of the first n positive numbers is equal to n * (n+1) / 2.
// 3. Initialize the answer as the sum of 1 to k. Then, adjust the answer
// depending on the values in nums.

// #v1
// sort, math
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long minimalKSum(int* nums, int numsSize, int k) {
  long long ret = (1LL+k)*k/2;

  qsort(nums, numsSize, sizeof(int), cmp);

  for (int i = 0; i < numsSize; i++) {
    // skip duplication
    if (i && nums[i] == nums[i-1]) continue;

    if (nums[i] <= k) {
      ret -= nums[i];
      ++k;
      ret += k;
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
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%lld\n", minimalKSum(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
