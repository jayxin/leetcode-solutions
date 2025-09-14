#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3487. 删除后的最大子数组元素和 - 给你一个整数数组 nums 。
// 你可以从数组 nums 中删除任意数量的元素，但不能将其变为 空 数组。执行删除操作后， 选出 nums 中满足下述条件的一个子数组：
//  1. 子数组中的所有元素 互不相同 。
//  2. 最大化 子数组的元素和。
// 返回子数组的 最大元素和 。
// 子数组 是数组的一个连续、非空 的元素序列。
//  
// 示例 1：
// 输入：nums = [1,2,3,4,5]
// 输出：15
// 解释：
// 不删除任何元素，选中整个数组得到最大元素和。
// 示例 2：
// 输入：nums = [1,1,0,1,1]
// 输出：1
// 解释：
// 删除元素 nums[0] == 1、nums[1] == 1、nums[2] == 0 和 nums[3] == 1 。选中整个数组 [1] 得到最大元素和。
// 示例 3：
// 输入：nums = [1,2,-1,-2,1,0,-1]
// 输出：3
// 解释：
// 删除元素 nums[2] == -1 和 nums[3] == -2 ，从 [1, 2, 1, 0, -1] 中选中子数组 [2, 1] 以获得最大元素和。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 100
//  * -100 &lt;= nums[i] &lt;= 100

// #v1
int maxSum(int* nums, int numsSize) {
  if (numsSize == 1) return nums[0];

  int ret = 0, i, tab[201] = {0};

  // 将 nums 的元素映射到 [0, 200]
  for (i = 0; i < numsSize; ++i) {
    tab[nums[i] + 100] = 1;
  }

  // 统计正数
  for (i = 200; i >= 101; i--) {
    if (tab[i]) ret += i - 100;
  }

  if (!ret && !tab[100]) { // 没有正数且 0 没有出现
    for (i = 99; i >= 0; i--) {
      if (tab[i]) {
        ret += i - 100;
        break; // 负数只加一个就最大了
      }
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
  printf("%d\n", maxSum(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
