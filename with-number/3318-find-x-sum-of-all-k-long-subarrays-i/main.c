#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3318. 计算子数组的 x-sum I - 给你一个由 n 个整数组成的数组 nums，以及两个整数 k 和 x。
// 数组的 x-sum 计算按照以下步骤进行：
//  * 统计数组中所有元素的出现次数。
//  * 仅保留出现次数最多的前 x 个元素的每次出现。如果两个元素的出现次数相同，则数值 较大 的元素被认为出现次数更多。
//  * 计算结果数组的和。
// 注意，如果数组中的不同元素少于 x 个，则其 x-sum 是数组的元素总和。
// 返回一个长度为 n - k + 1 的整数数组 answer，其中 answer[i] 是 子数组 nums[i..i + k - 1] 的 x-sum。
// 子数组 是数组内的一个连续 非空 的元素序列。
//  
// 示例 1：
// 输入：nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
// 输出：[6,10,12]
// 解释：
//  * 对于子数组 [1, 1, 2, 2, 3, 4]，只保留元素 1 和 2。因此，answer[0] = 1 + 1 + 2 + 2。
//  * 对于子数组 [1, 2, 2, 3, 4, 2]，只保留元素 2 和 4。因此，answer[1] = 2 + 2 + 2 + 4。注意 4 被保留是因为其数值大于出现其他出现次数相同的元素（3 和 1）。
//  * 对于子数组 [2, 2, 3, 4, 2, 3]，只保留元素 2 和 3。因此，answer[2] = 2 + 2 + 2 + 3 + 3。
// 示例 2：
// 输入：nums = [3,8,7,8,7,5], k = 2, x = 2
// 输出：[11,15,15,15,12]
// 解释：
// 由于 k == x，answer[i] 等于子数组 nums[i..i + k - 1] 的总和。
//  
// 提示：
//  * 1 <= n == nums.length <= 50
//  * 1 <= nums[i] <= 50
//  * 1 <= x <= k <= nums.length

// #v1
struct Pair {
  int val, cnt;
};

int cmp(const void *a, const void *b) {
  struct Pair *aa = (struct Pair *)a;
  struct Pair *bb = (struct Pair *)b;
  if (aa->cnt != bb->cnt) return bb->cnt - aa->cnt;
  return bb->val - aa->val;
}

int xSum(int *a, int n, int x) {
  int c[51] = {0}, pLen = 0, sum = 0;
  struct Pair p[60];

  for (int i = 0; i < n; i++) {
    ++c[a[i]];
  }

  for (int i = 1; i <= 50; i++) {
    if (c[i]) {
      p[pLen].val = i;
      p[pLen++].cnt = c[i];
    }
  }

  if (pLen <= x) {
    for (int i = 0; i < pLen; i++) sum += p[i].val * p[i].cnt;
    return sum;
  }

  qsort(p, pLen, sizeof(struct Pair), cmp);

  for (int i = 0; i < x; i++) sum += p[i].val * p[i].cnt;

  return sum;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
  *returnSize = numsSize - k + 1;

  int *ret = calloc(*returnSize, sizeof(int));

  for (int i = 0; i < *returnSize; i++) {
    ret[i] = xSum(nums + i, k, x);
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
  int *a, n, k, x, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d%d", &k, &x);
  ret = findXSum(a, n, k, x, &s);
  print_1d_arr(ret ,s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
