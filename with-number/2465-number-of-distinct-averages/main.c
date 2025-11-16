#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2465. 不同的平均值数目 - 给你一个下标从 0 开始长度为 偶数 的整数数组 nums 。
// 只要 nums 不是 空数组，你就重复执行以下步骤：
//  * 找到 nums 中的最小值，并删除它。
//  * 找到 nums 中的最大值，并删除它。
//  * 计算删除两数的平均值。
// 两数 a 和 b 的 平均值 为 (a + b) / 2 。
//  * 比方说，2 和 3 的平均值是 (2 + 3) / 2 = 2.5 。
// 返回上述过程能得到的 不同 平均值的数目。
// 注意 ，如果最小值或者最大值有重复元素，可以删除任意一个。
//  
// 示例 1：
// 输入：nums = [4,1,4,0,3,5]
// 输出：2
// 解释：
// 1. 删除 0 和 5 ，平均值是 (0 + 5) / 2 = 2.5 ，现在 nums = [4,1,4,3] 。
// 2. 删除 1 和 4 ，平均值是 (1 + 4) / 2 = 2.5 ，现在 nums = [4,3] 。
// 3. 删除 3 和 4 ，平均值是 (3 + 4) / 2 = 3.5 。
// 2.5 ，2.5 和 3.5 之中总共有 2 个不同的数，我们返回 2 。
// 示例 2：
// 输入：nums = [1,100]
// 输出：1
// 解释：
// 删除 1 和 100 后只有一个平均值，所以我们返回 1 。
//  
// 提示：
//  * 2 <= nums.length <= 100
//  * nums.length 是偶数。
//  * 0 <= nums[i] <= 100

// #v1
int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int distinctAverages(int* nums, int numsSize) {
  int c = 0, htLen = 0;
  double ht[101];

  qsort(nums, numsSize, sizeof(int), cmp);

  int l = 0, r = numsSize - 1;

  while (l < r) {
    double avg = (nums[l] + nums[r]) / 2.0;

    int f = 1;
    for (int i = 0; i < htLen; i++) {
      if (ht[i] == avg) {
        f = 0;
        break;
      }
    }

    if (f) {
      ht[htLen++] = avg;
      ++c;
    }

    ++l;
    --r;
  }

  return c;
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
  printf("%d\n", distinctAverages(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
