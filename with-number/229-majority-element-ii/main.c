#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 229. 多数元素 II - 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//  
// 示例 1：
// 输入：nums = [3,2,3]
// 输出：[3]
// 示例 2：
// 输入：nums = [1]
// 输出：[1]
// 示例 3：
// 输入：nums = [1,2]
// 输出：[1,2]
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 5 * 104
//  * -109 &lt;= nums[i] &lt;= 109
//  
// 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
// Think about the possible number of elements that can appear more than ⌊ n/3 ⌋ times in the array.
// It can be at most two. Why?
// Consider using Boyer-Moore Voting Algorithm, which is efficient for finding
// elements that appear more than a certain threshold.

// #v1
// Boyer-Moore Voting Algorithm
int* majorityElement(int* nums, int numsSize, int* returnSize) {
  int *ret = NULL, limit = numsSize / 3, i, c0, c1, v0, v1, retLen = 0;

  ret = (int *)malloc(sizeof(int) * 2);
  c0 = c1 = 0;

  for (i = 0; i < numsSize; i++) {
    if (c0 > 0 && nums[i] == v0) {
      ++c0;
    } else if (c1 > 0 && nums[i] == v1) {
      ++c1;
    } else if (c0 == 0) {
      v0 = nums[i];
      ++c0;
    } else if (c1 == 0) {
      v1 = nums[i];
      ++c1;
    } else { // 3 个元素均不同, 相互抵消
      --c0;
      --c1;
    }
  }

  c0 = c1 = 0;
  // count
  for (i = 0; i < numsSize; i++) {
    if (v0 == nums[i]) ++c0;
    else if (v1 == nums[i]) ++c1;
  }

  // check
  if (c0 > limit) ret[retLen++] = v0;
  if (c1 > limit) ret[retLen++] = v1;

  *returnSize = retLen;

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  if (n <= 0) return NULL;

  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", ret + i);
  return ret;
}

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }

  putchar('\n');
}

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = majorityElement(a, n, &s);
  print_1d_arr(ret, s);
  if (a) free(a);
  if (ret) free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
