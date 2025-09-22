#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3005. 最大频率元素计数 - 给你一个由 正整数 组成的数组 nums 。
// 返回数组 nums 中所有具有 最大 频率的元素的 总频率 。
// 元素的 频率 是指该元素在数组中出现的次数。
//  
// 示例 1：
// 输入：nums = [1,2,2,3,1,4]
// 输出：4
// 解释：元素 1 和 2 的频率为 2 ，是数组中的最大频率。
// 因此具有最大频率的元素在数组中的数量是 4 。
// 示例 2：
// 输入：nums = [1,2,3,4,5]
// 输出：5
// 解释：数组中的所有元素的频率都为 1 ，是最大频率。
// 因此具有最大频率的元素在数组中的数量是 5 。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= nums[i] <= 100

// #v1
int maxFrequencyElements(int* nums, int numsSize) {
  if (numsSize == 1) return 1;

  int t[101] = {0}, i, maxFreq = 0, ret = 0;

  for (i = 0; i < numsSize; i++) {
    t[nums[i]] += 1;
    if (t[nums[i]] > maxFreq) maxFreq = t[nums[i]];
  }

  for (i = 1; i <= 100; i++) {
     if (t[i] == maxFreq) ret += t[i];
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
  printf("%d\n", maxFrequencyElements(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
