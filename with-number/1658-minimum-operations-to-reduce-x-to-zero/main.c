#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1658. 将 x 减到 0 的最小操作数 - 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。
// 如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
//  
// 示例 1：
// 输入：nums = [1,1,4,2,3], x = 5
// 输出：2
// 解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
// 示例 2：
// 输入：nums = [5,6,7,8,9], x = 4
// 输出：-1
// 示例 3：
// 输入：nums = [3,2,20,1,1,3], x = 10
// 输出：5
// 解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 104
//  * 1 <= x <= 109

// #v1
// prefix sum, sliding window

#define INF 0x7fffffff

int minOperations(int* nums, int numsSize, int x) {
  int prefixSum[numsSize+1], target, ret = INF;

  prefixSum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    prefixSum[i+1] = prefixSum[i] + nums[i];
  }
  target = prefixSum[numsSize] - x;
  // nums[i] + ... + nums[j] == prefixSum[j+1] - prefixSum[i]
  // prefixSum[numsSize] - (prefixSum[j+1] - prefixSum[i]) == x
  // nums[i] >= 1

  // edge case
  if (target == 0) return numsSize;

  // sliding window
  int l = 0, r = l;

  while (l < numsSize) {
    r = r >= l ? r : l;
    int windowSum = prefixSum[r+1] - prefixSum[l];

    // 扩展窗口的右边界
    while (r < numsSize-1 && windowSum < target) {
      ++r;
      windowSum = prefixSum[r+1] - prefixSum[l];
    }

    if (windowSum == target) {
      int cnt = numsSize - (r - l + 1);
      if (cnt < ret) ret = cnt;
    }

    // 扩展窗口的左边界
    ++l;
  }

  if (ret == INF) return -1;

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
  int n, x, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &x);
  printf("%d\n", minOperations(a, n, x));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
