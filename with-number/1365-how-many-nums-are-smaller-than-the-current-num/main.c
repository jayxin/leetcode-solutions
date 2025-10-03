#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1365. 有多少小于当前数字的数字 - 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
// 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] &lt; nums[i] 。
// 以数组形式返回答案。
//  
// 示例 1：
// 输入：nums = [8,1,2,2,3]
// 输出：[4,0,1,1,3]
// 解释：
// 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
// 对于 nums[1]=1 不存在比它小的数字。
// 对于 nums[2]=2 存在一个比它小的数字：（1）。
// 对于 nums[3]=2 存在一个比它小的数字：（1）。
// 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
// 示例 2：
// 输入：nums = [6,5,4,8]
// 输出：[2,1,0,3]
// 示例 3：
// 输入：nums = [7,7,7,7]
// 输出：[0,0,0,0]
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 500
//  * 0 &lt;= nums[i] &lt;= 100

// #v1
struct Pair { int val, idx; };

int cmp(const void *a, const void *b) {
  return ((struct Pair *)a)->val - ((struct Pair *)b)->val;
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int *ret = (int *)malloc(sizeof(int) * numsSize), i;
  struct Pair p[numsSize];

  for (i = 0; i < numsSize; i++) {
    p[i].val = nums[i];
    p[i].idx = i;
  }

  qsort(p, numsSize, sizeof(struct Pair), cmp);

  for (i = 0; i < numsSize; i++) {
    if (i && p[i].val == p[i-1].val) {
      ret[p[i].idx] = ret[p[i-1].idx];
    } else {
      ret[p[i].idx] = i;
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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = smallerNumbersThanCurrent(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
