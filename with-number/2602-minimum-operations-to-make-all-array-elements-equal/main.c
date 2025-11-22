#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2602. 使数组元素全部相等的最少操作次数 - 给你一个正整数数组 nums 。
// 同时给你一个长度为 m 的整数数组 queries 。第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。你可以执行以下操作 任意 次：
//  * 将数组里一个元素 增大 或者 减小 1 。
// 请你返回一个长度为 m 的数组 answer ，其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。
// 注意，每次查询后，数组变回最开始的值。
//  
// 示例 1：
// 输入：nums = [3,1,6,8], queries = [1,5]
// 输出：[14,10]
// 解释：第一个查询，我们可以执行以下操作：
// - 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
// - 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
// - 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
// 第一个查询的总操作次数为 2 + 5 + 7 = 14 。
// 第二个查询，我们可以执行以下操作：
// - 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
// - 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
// - 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
// - 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
// 第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。
// 示例 2：
// 输入：nums = [2,9,6,3], queries = [10]
// 输出：[20]
// 解释：我们可以将数组中所有元素都增大到 10 ，总操作次数为 8 + 1 + 4 + 7 = 20 。
//  
// 提示：
//  * n == nums.length
//  * m == queries.length
//  * 1 <= n, m <= 105
//  * 1 <= nums[i], queries[i] <= 109

// #v1
// prefix sum, sort, binary search
typedef long long LL;

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

long long* minOperations(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
  *returnSize = queriesSize;

  LL prefixSum[numsSize+1];
  LL *ret = (LL *)malloc(sizeof(LL) * queriesSize);

  // sort
  qsort(nums, numsSize, sizeof(int), cmp);

  // compute prefix sum of nums
  prefixSum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    prefixSum[i+1] = prefixSum[i] + nums[i];
  }

  // process queries
  for (int i = 0; i < queriesSize; i++) {
    // binary search
    int l = 0, r = numsSize - 1, m;
    while (l < r) {
      m = (l + r) >> 1;

      if (nums[m] >= queries[i]) r = m;
      else l = m + 1;
    }

    //if (nums[l] >= queries[i]) {
    //  ret[i] = (LL)queries[i] * l - prefixSum[l];
    //  ret[i] += prefixSum[numsSize] - prefixSum[l] - queries[i] * (numsSize - l);
    //} else {
    //  ret[i] = (LL)queries[i] * numsSize - prefixSum[numsSize];
    //}
    if (nums[l] >= queries[i]) {
      ret[i] = prefixSum[numsSize] - (prefixSum[l]<<1) + (LL)((l<<1) - numsSize) * queries[i];
    } else {
      ret[i] = (LL)queries[i] * numsSize - prefixSum[numsSize];
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

void print_1d_arr(LL *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%lld", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int *nums, numsSize, *queries, queriesSize, returnSize;
  long long *ret;
  scanf("%d", &numsSize);
  nums = read_1d_arr(numsSize);
  scanf("%d", &queriesSize);
  queries = read_1d_arr(queriesSize);
  ret = minOperations(nums, numsSize, queries, queriesSize, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
