#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2171. 拿出最少数目的魔法豆 - 给定一个 正整数 数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。
// 请你从每个袋子中 拿出 一些豆子（也可以 不拿出），使得剩下的 非空 袋子中（即 至少 还有一颗 魔法豆的袋子）魔法豆的数目 相等。一旦把魔法豆从袋子中取出，你不能再将它 放到任何袋子中。
// 请返回你需要拿出魔法豆的 最少数目。
//  
// 示例 1：
// 输入：beans = [4,1,6,5]
// 输出：4
// 解释：
// - 我们从有 1 个魔法豆的袋子中拿出 1 颗魔法豆。
//   剩下袋子中魔法豆的数目为：[4,0,6,5]
// - 然后我们从有 6 个魔法豆的袋子中拿出 2 个魔法豆。
//   剩下袋子中魔法豆的数目为：[4,0,4,5]
// - 然后我们从有 5 个魔法豆的袋子中拿出 1 个魔法豆。
//   剩下袋子中魔法豆的数目为：[4,0,4,4]
// 总共拿出了 1 + 2 + 1 = 4 个魔法豆，剩下非空袋子中魔法豆的数目相等。
// 没有比取出 4 个魔法豆更少的方案。
// 示例 2：
// 输入：beans = [2,10,3,2]
// 输出：7
// 解释：
// - 我们从有 2 个魔法豆的其中一个袋子中拿出 2 个魔法豆。
//   剩下袋子中魔法豆的数目为：[0,10,3,2]
// - 然后我们从另一个有 2 个魔法豆的袋子中拿出 2 个魔法豆。
//   剩下袋子中魔法豆的数目为：[0,10,3,0]
// - 然后我们从有 3 个魔法豆的袋子中拿出 3 个魔法豆。
//   剩下袋子中魔法豆的数目为：[0,10,0,0]
// 总共拿出了 2 + 2 + 3 = 7 个魔法豆，剩下非空袋子中魔法豆的数目相等。
// 没有比取出 7 个魔法豆更少的方案。
//  
// 提示：
//  * 1 <= beans.length <= 105
//  * 1 <= beans[i] <= 105
// 1. Notice that if we choose to make x bags of beans empty, we should choose
// the x bags with the least amount of beans.
// 2. Notice that if the minimum number of beans in a non-empty bag is m, then
// the best way to make all bags have an equal amount of beans is to reduce all
// the bags to have m beans.
// 3. Can we iterate over how many bags we should remove and choose the one
// that minimizes the total amount of beans to remove?
// 4. Sort the bags of beans first.

//// #v1
//// signed integer overflow
//int cmp(const void *a, const void *b) {
  //return *(const int *)a - *(const int *)b;
//}
//
//long long minimumRemoval(int* beans, int beansSize) {
  //qsort(beans, beansSize, sizeof(int), cmp);
//
  //int n = beansSize;
  //int prefixSum[n+1];
  //long long ret = -1, tmp;
//
  //prefixSum[0] = 0;
  //for (int i = 0; i < n; i++) {
    //prefixSum[i+1] = prefixSum[i] + beans[i];
  //}
//
  //// 删除 nums[0...(i-1)], 选择 nums[i...(n-1)] 作为最终的非零值
  //// prefixSum[i] + prefixSum[n] - prefixSum[i] - nums[i] * (numsSize - i)
  //for (int i = 0; i < n; i++) {
    //tmp = (long long)prefixSum[n] - beans[i] * (n - i);
    //if (tmp < ret || ret == -1) ret = tmp;
  //}
//
  //return ret;
//}
//// #v1

// #v2
// prefix sum, sort
typedef long long LL;

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

long long minimumRemoval(int* beans, int beansSize) {
  qsort(beans, beansSize, sizeof(int), cmp);

  //int n = beansSize;
  LL ret = -1, tot;

  // we only need prefixSum[n]
  tot = 0LL;
  for (int i = 0; i < beansSize; i++) tot += beans[i];

  // 删除 nums[0...(i-1)], 选择 nums[i...(n-1)] 作为最终的非零值
  // prefixSum[i] + prefixSum[n] - prefixSum[i] - nums[i] * (n - i)
  for (int i = 0; i < beansSize; i++) {
    LL tmp = tot - (LL)beans[i] * (beansSize - i);
    if (tmp < ret || ret == -1) ret = tmp;
  }

  return ret;
}
// #v2

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
  printf("%lld\n", minimumRemoval(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
