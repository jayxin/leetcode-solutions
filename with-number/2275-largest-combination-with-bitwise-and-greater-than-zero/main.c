#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2275. 按位与结果大于零的最长组合 - 对数组 nums 执行 按位与 相当于对数组 nums 中的所有整数执行 按位与 。
//  * 例如，对 nums = [1, 5, 3] 来说，按位与等于 1 &amp; 5 &amp; 3 = 1 。
//  * 同样，对 nums = [7] 而言，按位与等于 7 。
// 给你一个正整数数组 candidates 。计算 candidates 中的数字每种组合下 按位与 的结果 。
// 返回按位与结果大于 0 的 最长 组合的长度。
//  
// 示例 1：
// 输入：candidates = [16,17,71,62,12,24,14]
// 输出：4
// 解释：组合 [16,17,62,24] 的按位与结果是 16 &amp; 17 &amp; 62 &amp; 24 = 16 > 0 。
// 组合长度是 4 。
// 可以证明不存在按位与结果大于 0 且长度大于 4 的组合。
// 注意，符合长度最大的组合可能不止一种。
// 例如，组合 [62,12,24,14] 的按位与结果是 62 &amp; 12 &amp; 24 &amp; 14 = 8 > 0 。
// 示例 2：
// 输入：candidates = [8,8]
// 输出：2
// 解释：最长组合是 [8,8] ，按位与结果 8 &amp; 8 = 8 > 0 。
// 组合长度是 2 ，所以返回 2 。
//  
// 提示：
//  * 1 <= candidates.length <= 105
//  * 1 <= candidates[i] <= 107

// #v1
int largestCombination(int* candidates, int candidatesSize) {
  int bitsCnt[32] = {0}, ret, i, maxBits = 0, j, t;

  // count, 统计 candidates 的每个元素每个位 1 出现的次数
  for (i = 0; i < candidatesSize; i++) {
    t = candidates[i];
    j = 0;

    while (t) {
      if (t & 1) ++bitsCnt[j];

      ++j;
      t >>= 1;
    }

    if (maxBits < j) maxBits = j;
  }

  // find max count
  ret = bitsCnt[0];
  for (i = 1; i < maxBits; i++)
    if (bitsCnt[i] > ret) ret = bitsCnt[i];

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
  printf("%d\n", largestCombination(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
