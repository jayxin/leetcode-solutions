#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2279. 装满石头的背包的最大数量 - 现有编号从 0 到 n - 1 的 n 个背包。给你两个下标从 0 开始的整数数组 capacity 和 rocks 。第 i 个背包最大可以装 capacity[i] 块石 头，当前已经装了 rocks[i] 块石头。另给你一个整数 additionalRocks ，表示你可以放置的额外石头数量，石头可以往 任意 背包中放置。
// 请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 最大 数量。
//  
// 示例 1：
// 输入：capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
// 输出：3
// 解释：
// 1 块石头放入背包 0 ，1 块石头放入背包 1 。
// 每个背包中的石头总数是 [2,3,4,4] 。
// 背包 0 、背包 1 和 背包 2 都装满石头。
// 总计 3 个背包装满石头，所以返回 3 。
// 可以证明不存在超过 3 个背包装满石头的情况。
// 注意，可能存在其他放置石头的方案同样能够得到 3 这个结果。
// 示例 2：
// 输入：capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
// 输出：3
// 解释：
// 8 块石头放入背包 0 ，2 块石头放入背包 2 。
// 每个背包中的石头总数是 [10,2,2] 。
// 背包 0 、背包 1 和背包 2 都装满石头。
// 总计 3 个背包装满石头，所以返回 3 。
// 可以证明不存在超过 3 个背包装满石头的情况。
// 注意，不必用完所有的额外石头。
//  
// 提示：
//  * n == capacity.length == rocks.length
//  * 1 <= n <= 5 * 104
//  * 1 <= capacity[i] <= 109
//  * 0 <= rocks[i] <= capacity[i]
//  * 1 <= additionalRocks <= 109

// #v1
int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
  int diff[capacitySize], diffLen = 0, ret = 0, i;

  for (i = 0; i < capacitySize; i++) {
    int tmp = capacity[i] - rocks[i];
    if (!tmp) ++ret;
    else diff[diffLen++] = tmp;
  }

  qsort(diff, diffLen, sizeof(int), cmp);

  for (i = 0; i < diffLen; i++) {
    if (additionalRocks >= diff[i]) {
      additionalRocks -= diff[i];
      ++ret;
    } else {
      break;
    }
  }

  return ret;
}
// #v1

//// #v2
//int cmp(const void *a, const void *b) {
  //return *(const int *)a - *(const int *)b;
//}
//
//int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
  //int diff[capacitySize], ret = 0, i;
//
  //for (i = 0; i < capacitySize; i++) {
    //diff[i] = capacity[i] - rocks[i];
  //}
//
  //qsort(diff, capacitySize, sizeof(int), cmp);
//
  //i = 0;
  //while (i < capacitySize && diff[i] == 0) {
    //++i;
    //++ret;
  //}
//
  //for (; i < capacitySize; i++) {
    //if (additionalRocks >= diff[i]) {
      //additionalRocks -= diff[i];
      //++ret;
    //} else {
      //break;
    //}
  //}
//
  //return ret;
//}
//// #v2

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
  int n0, n1, *a0, *a1, k;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &k);
  printf("%d\n", maximumBags(a0, n0, a1, n1, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
