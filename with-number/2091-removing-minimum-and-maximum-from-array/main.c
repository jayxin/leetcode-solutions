#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2091. 从数组中移除最大值和最小值 - 给你一个下标从 0 开始的数组 nums ，数组由若干 互不相同 的整数组成。
// nums 中有一个值最小的元素和一个值最大的元素。分别称为 最小值 和 最大值 。你的目标是从数组中移除这两个元素。
// 一次 删除 操作定义为从数组的 前面 移除一个元素或从数组的 后面 移除一个元素。
// 返回将数组中最小值和最大值 都 移除需要的最小删除次数。
//  
// 示例 1：
// 输入：nums = [2,10,7,5,4,1,8,6]
// 输出：5
// 解释：
// 数组中的最小元素是 nums[5] ，值为 1 。
// 数组中的最大元素是 nums[1] ，值为 10 。
// 将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
// 结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。
// 示例 2：
// 输入：nums = [0,-4,19,1,8,-2,-3,5]
// 输出：3
// 解释：
// 数组中的最小元素是 nums[1] ，值为 -4 。
// 数组中的最大元素是 nums[2] ，值为 19 。
// 将最大值和最小值都移除需要从数组前面移除 3 个元素。
// 结果是 3 ，这是所有可能情况中的最小删除次数。
// 示例 3：
// 输入：nums = [101]
// 输出：1
// 解释：
// 数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
// 移除它只需要 1 次删除操作。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * -105 <= nums[i] <= 105
//  * nums 中的整数 互不相同
// There can only be three scenarios for deletions such that both minimum and
// maximum elements are removed:
// Scenario 1: Both elements are removed by only deleting from the front.
// Scenario 2: Both elements are removed by only deleting from the back.
// Scenario 3: Delete from the front to remove one of the elements, and delete from the back to remove the other element.
// Compare which of the three scenarios results in the minimum number of moves.

// #v1
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define min(a, b) ((a) <= (b) ? (a) : (b))

int minimumDeletions(int* nums, int numsSize) {
  int minIdx = 0, maxIdx = 0;
  int v1, v2, v3;

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] < nums[minIdx]) minIdx = i;
    if (nums[i] > nums[maxIdx]) maxIdx = i;
  }

  // all delete from front
  v1 = max(minIdx, maxIdx) + 1;
  // all delete from back
  v2 = numsSize - min(minIdx, maxIdx);
  // one delete from front, one delete from end
  v3 = min(minIdx, maxIdx) + 1 + numsSize - max(minIdx, maxIdx);

  return min(v1, min(v2, v3));
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", minimumDeletions(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
