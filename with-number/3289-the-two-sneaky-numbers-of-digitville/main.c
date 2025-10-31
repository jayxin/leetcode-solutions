#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3289. 数字小镇中的捣蛋鬼 - 数字小镇 Digitville 中，存在一个数字列表 nums，其中包含从 0 到 n - 1 的整数。每个数字本应 只出现一次，然而，有 两个 顽皮的数字额外多出现了一次，使得列表变得比正常情况下更长。
// 为了恢复 Digitville 的和平，作为小镇中的名侦探，请你找出这两个顽皮的数字。
// 返回一个长度为 2 的数组，包含这两个数字（顺序任意）。
//  
// 示例 1：
// 输入： nums = [0,1,1,0]
// 输出： [0,1]
// 解释：
// 数字 0 和 1 分别在数组中出现了两次。
// 示例 2：
// 输入： nums = [0,3,2,1,3,2]
// 输出： [2,3]
// 解释:
// 数字 2 和 3 分别在数组中出现了两次。
// 示例 3：
// 输入： nums = [7,1,5,4,3,4,6,0,9,5,8,2]
// 输出： [4,5]
// 解释:
// 数字 4 和 5 分别在数组中出现了两次。
//  
// 提示：
//  * 2 <= n <= 100
//  * nums.length == n + 2
//  * 0 <= nums[i] < n
//  * 输入保证 nums 中 恰好 包含两个重复的元素。

// #v1
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
  *returnSize = 2;
  int *ret = calloc(2, sizeof(int)), len = 0;
  char ht[numsSize];

  memset(ht, 0, sizeof(ht));

  for (int i = 0; i < numsSize; i++) {
    if (ht[nums[i]]) {
      ret[len++] = nums[i];
      if (len == 2) return ret;
    }

    // add to hash table
    ht[nums[i]] = 1;
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
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = getSneakyNumbers(a, n, &s);
  printf("%d %d\n", ret[0], ret[1]);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
