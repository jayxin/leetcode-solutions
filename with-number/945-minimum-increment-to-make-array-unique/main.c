#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 945. 使数组唯一的最小增量 - 给你一个整数数组 nums 。每次 move 操作将会选择任意一个 满足 0 &lt;= i &lt; nums.length 的下标 i，并将 nums[i] 递增 1。
// 返回使 nums 中的每个值都变成唯一的所需要的最少操作次数。
// 生成的测试用例保证答案在 32 位整数范围内。
//  
// 示例 1：
// 输入：nums = [1,2,2]
// 输出：1
// 解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
// 示例 2：
// 输入：nums = [3,2,1,2,1,7]
// 输出：6
// 解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
// 可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 105
//  * 0 &lt;= nums[i] &lt;= 105

// #v1
int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int minIncrementForUnique(int* nums, int numsSize) {
  int max, ret = 0, i;

  qsort(nums, numsSize, sizeof(int), cmp);
  // 记录当前最大值
  max = nums[0];

  for (i = 1; i < numsSize; i++) {
    if (nums[i] <= max) { // not unique
      ret += max + 1 - nums[i];
      ++max;
    } else { // update max
      max = nums[i];
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", minIncrementForUnique(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
