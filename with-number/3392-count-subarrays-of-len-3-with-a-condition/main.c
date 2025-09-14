#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3392. 统计符合条件长度为 3 的子数组数目 - 给你一个整数数组 nums ，请 你返回长度为 3 的 子数组 的数量，满足第一个数和第三个数的和恰好为第二个数的一半。
// 子数组 指的是一个数组中连续 非空 的元素序列。
//  
// 示例 1：
// 输入：nums = [1,2,1,4,1]
// 输出：1
// 解释：
// 只有子数组 [1,4,1] 包含 3 个元素且第一个和第三个数字之和是中间数字的一半。number.
// 示例 2：
// 输入：nums = [1,1,1]
// 输出：0
// 解释：
// [1,1,1] 是唯一长度为 3 的子数组，但第一个数和第三个数的和不是第二个数的一半。
//  
// 提示：
//  * 3 &lt;= nums.length &lt;= 100
//  * -100 &lt;= nums[i] &lt;= 100

// #v1
int countSubarrays(int* nums, int numsSize) {
  int ret = 0, l = 0, r = 2;

  while (r < numsSize) {
    if ((nums[l] + nums[r]) * 2 == nums[l+1]) ++ret;
    ++l;
    ++r;
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
  printf("%d\n", countSubarrays(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
