#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3397. 执行操作后不同元素的最大数量 - 给你一个整数数组 nums 和一个整数 k。
// 你可以对数组中的每个元素 最多 执行 一次 以下操作：
//  * 将一个在范围 [-k, k] 内的整数加到该元素上。
// 返回执行这些操作后，nums 中可能拥有的不同元素的 最大 数量。
//  
// 示例 1：
// 输入： nums = [1,2,2,3,3,4], k = 2
// 输出： 6
// 解释：
// 对前四个元素执行操作，nums 变为 [-1, 0, 1, 2, 3, 4]，可以获得 6 个不同的元素。
// 示例 2：
// 输入： nums = [4,4,4,4], k = 1
// 输出： 3
// 解释：
// 对 nums[0] 加 -1，以及对 nums[1] 加 1，nums 变为 [3, 5, 4, 4]，可以获得 3 个不同 的元素。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109
//  * 0 <= k <= 109

// #v1
// 贪心, 排序
#define abs(x) (((x) >= 0) ? (x) : -(x))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maxDistinctElements(int* nums, int numsSize, int k) {
  // sort
  qsort(nums, numsSize, sizeof(int), cmp);

  int t, p, x;

  nums[0] -= k;
  // p 指向唯一元素的末尾
  // 即 nums[0..p] 中的元素互不相同
  p = 0;
  for (int i = 1; i < numsSize; i++) {
    t = nums[p] + 1;
    x = t - nums[i];

    // 检查 t 是否在 nums[i] 可达的范围内
    // [nums[i]-k, nums[i]+k]
    // 若可达, 则将 nums[i] 改为 t 是最优的
    if (abs(x) <= k) nums[i] = t;
    // 否则 nums[i] 取可达范围的最小值
    else nums[i] -= k;

    if (nums[i] > nums[p]) { // 若加入 nums[i] 后数组中的元素仍然唯一
      // 将 nums[i] 加入
      // nums[0] nums[1] ... nums[p] nums[p+1]=nums[i]
      nums[p+1] = nums[i];
      // nums[i] 的值成为唯一数组的末尾
      ++p;
    }
  }

  return p+1;
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
  int n, k, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", maxDistinctElements(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
