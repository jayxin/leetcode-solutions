#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2784. 检查数组是否是好的 - 给你一个整数数组 nums ，如果它是数组 base[n] 的一个排列，我们称它是个 好 数组。
// base[n] = [1, 2, ..., n - 1, n, n] （换句话说，它是一个长度为 n + 1 且包含 1 到 n - 1 恰好各一次，包含 n  两次的一个数组）。比方说，base[1] = [1, 1] ，base[3] = [1, 2, 3, 3] 。
// 如果数组是一个好数组，请你返回 true ，否则返回 false 。
// 注意：数组的排列是这些数字按任意顺序排布后重新得到的数组。
//  
// 示例 1：
// 输入：nums = [2, 1, 3]
// 输出：false
// 解释：因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 。但是 base[3] 有 4 个元素，但数组 nums 只有 3 个元素，所以无法得到 base[3] = [1, 2, 3, 3] 的排列，所以答案为 false 。
// 示例 2：
// 输入：nums = [1, 3, 3, 2]
// 输出：true
// 解释：因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 ，可以看出数组是 base[3] = [1, 2, 3, 3] 的一个排列（交换 nums 中第二个和第四个元素）。 所以答案为 true 。
// 示例 3：
// 输入：nums = [1, 1]
// 输出：true
// 解释：因为数组的最大元素是 1 ，唯一可以构成这个数组的 base[n] 对应的 n = 1，可以 看出数组是 base[1] = [1, 1] 的一个排列。所以答案为 true 。
// 示例 4：
// 输入：nums = [3, 4, 4, 1, 2, 1]
// 输出：false
// 解释：因为数组的最大元素是 4 ，唯一可以构成这个数组的 base[n] 对应的 n = 4 。但是 base[n] 有 5 个元素而 nums 有 6 个元素。所以答案为 false 。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= num[i] <= 200

// #v1
bool isGood(int* nums, int numsSize) {
  int maxVal = nums[0], *t, i;

  for (i = 1; i < numsSize; i++) {
    if (nums[i] > maxVal) maxVal = nums[i];
  }

  if (maxVal + 1 != numsSize) return false;

  t = (int *)malloc(sizeof(int) * (maxVal + 1));
  memset(t, 0, sizeof(int) * (maxVal + 1));

  for (i = 0; i < numsSize; i++) {
    ++t[nums[i]];
  }

  for (i = 1; i < maxVal; i++) {
    if (t[i] != 1) return false;
  }
  if (t[maxVal] == 2) return true;

  return false;
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
  if (isGood(a, n))
    printf("true\n");
  else
    printf("false\n");
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
