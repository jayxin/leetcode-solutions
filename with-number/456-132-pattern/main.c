#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 456. 132 模式 - 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
// 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：nums = [1,2,3,4]
// 输出：false
// 解释：序列中不存在 132 模式的子序列。
// 示例 2：
// 输入：nums = [3,1,4,2]
// 输出：true
// 解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
// 示例 3：
// 输入：nums = [-1,3,2,0]
// 输出：true
// 解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
//  
// 提示：
//  * n == nums.length
//  * 1 <= n <= 2 * 105
//  * -109 <= nums[i] <= 109

// #v1
// 单调栈
// 正难则反
bool find132pattern(int* nums, int numsSize) {
  if (numsSize < 3) return false;

  int stack[numsSize], top = -1, l = -1e9;

  // 从后往前寻找 231 模式
  for (int i = numsSize - 1; i >= 0; i--) {
    // 2 - 3 - 1
    // l - stack[top] - nums[i]
    // l 维护 2, stack[top] 维护 3, nums[i] 维护 1
    if (nums[i] < l) return true;

    while (top >= 0 && stack[top] < nums[i]) {
      // 选择栈中的元素成为 2
      l = stack[top];
      // pop
      --top;
    }

    // push
    // 选择 nums[i] 成为 3
    stack[++top] = nums[i];
  }

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
  if (find132pattern(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
