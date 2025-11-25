#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 455. 分发饼干 - 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一 块饼干。
// 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。
//  
// 示例 1:
// 输入: g = [1,2,3], s = [1,1]
// 输出: 1
// 解释:
// 你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。
// 虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。
// 所以你应该输出 1。
// 示例 2:
// 输入: g = [1,2], s = [1,2,3]
// 输出: 2
// 解释:
// 你有两个孩子和三块小饼干，2 个孩子的胃口值分别是 1,2。
// 你拥有的饼干数量和尺寸都足以让所有孩子满足。
// 所以你应该输出 2。
//  
// 提示：
//  * 1 <= g.length <= 3 * 104
//  * 0 <= s.length <= 3 * 104
//  * 1 <= g[i], s[j] <= 231 - 1
//  
// 注意：本题与 2410. 运动员和训练师的最大匹配数 [https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/] 题相同。

// #v1
// sort, greedy method
int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
  qsort(g, gSize, sizeof(int), cmp);
  qsort(s, sSize, sizeof(int), cmp);

  int c = 0, j = 0;

  for (int i = 0; i < gSize; i++) {
    while (j < sSize && g[i] > s[j]) ++j;
    if (j == sSize) break;

    ++c;
    ++j;
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
  int n0, *a0, *a1, n1;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  printf("%d\n", findContentChildren(a0, n0, a1, n1));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
