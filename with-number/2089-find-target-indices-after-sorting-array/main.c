#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2089. 找出数组排序后的目标下标 - 给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
// 目标下标 是一个满足 nums[i] == target 的下标 i 。
// 将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下 标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。
//  
// 示例 1：
// 输入：nums = [1,2,5,2,3], target = 2
// 输出：[1,2]
// 解释：排序后，nums 变为 [1,2,2,3,5] 。
// 满足 nums[i] == 2 的下标是 1 和 2 。
// 示例 2：
// 输入：nums = [1,2,5,2,3], target = 3
// 输出：[3]
// 解释：排序后，nums 变为 [1,2,2,3,5] 。
// 满足 nums[i] == 3 的下标是 3 。
// 示例 3：
// 输入：nums = [1,2,5,2,3], target = 5
// 输出：[4]
// 解释：排序后，nums 变为 [1,2,2,3,5] 。
// 满足 nums[i] == 5 的下标是 4 。
// 示例 4：
// 输入：nums = [1,2,5,2,3], target = 4
// 输出：[]
// 解释：nums 中不含值为 4 的元素。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 100
//  * 1 &lt;= nums[i], target &lt;= 100

// #v1
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int lower_bound(int *a, int n, int t) {
  int l = 0, r = n - 1, m;

  while (l < r) {
    m = (l + r) >> 1;

    if (a[m] >= t) r = m;
    else l = m + 1;
  }

  return l;
}

int upper_bound(int *a, int n, int t) {
  int l = 0, r = n - 1, m;

  while (l < r) {
    m = (l + r + 1) >> 1;

    if (a[m] <= t) l = m;
    else r = m - 1;
  }

  return l;
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
  // sort
  qsort(nums, numsSize, sizeof(int), cmp);

  // find lower bound and upper bound of target
  int l = lower_bound(nums, numsSize, target),
      u = upper_bound(nums, numsSize, target);
  int *ret = NULL;

  // 数组中不存在 target
  if (nums[l] != target && nums[u] != target) {
    *returnSize = 0;
    return ret;
  }

  // 数组中存在 1 个元素为 target
  if (l == u && nums[l] == target) {
    *returnSize = 1;
    ret = (int *)malloc(sizeof(int) * 1);
    ret[0] = l;
    return ret;
  }

  // 数组中存在多个元素为 target
  *returnSize = u - l + 1;
  ret = (int *)malloc(sizeof(int) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) {
    ret[i] = l + i;
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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *a, *ret, s, t;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &t);
  ret = targetIndices(a, n, t, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
