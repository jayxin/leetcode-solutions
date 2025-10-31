#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 442.  数组中重复的数据 - 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范 围 [1, n] 内，且每个整数出现 最多两次 。请你找出所有出现 两次 的整数，并以数组形 式返回。
// 你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间（不包括存储输出所需的 空间）的算法解决此问题。
//  
// 示例 1：
// 输入：nums = [4,3,2,7,8,2,3,1]
// 输出：[2,3]
// 示例 2：
// 输入：nums = [1,1,2]
// 输出：[1]
// 示例 3：
// 输入：nums = [1]
// 输出：[]
//  
// 提示：
//  * n == nums.length
//  * 1 <= n <= 105
//  * 1 <= nums[i] <= n
//  * nums 中的每个元素出现 一次 或 两次

// #v1
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
  int *ret = calloc(numsSize, sizeof(int)), retLen = 0, t;

  for (int i = 0; i < numsSize; i++) {
    t = nums[i] - 1;
    if (t == i) continue;

    int tmp;

    while (nums[t] != nums[i]) {
      // swap
      tmp = nums[i];
      nums[i] = nums[t];
      nums[t] = tmp;

      // update
      t = nums[i] - 1;
    }
  }

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != i + 1) ret[retLen++] = nums[i];
  }

  *returnSize = retLen;

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
  ret = findDuplicates(a, n, &s);
  print_1d_arr(ret ,s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
