#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2149.  按符号重排数组 - 给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目 相等 的正整数和负整数组成。
// 你需要返回满足下述条件的数组 nums：
//  1. 任意 连续 的两个整数 符号相反
//  2. 对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
//  3. 重排后数组以正整数开头。
// 重排元素满足上述条件后，返回修改后的数组。
//  
// 示例 1：
// 输入：nums = [3,1,-2,-5,2,-4]
// 输出：[3,-2,1,-5,2,-4]
// 解释：
// nums 中的正整数是 [3,1,2] ，负整数是 [-2,-5,-4] 。
// 重排的唯一可行方案是 [3,-2,1,-5,2,-4]，能满足所有条件。
// 像 [1,-2,2,-5,3,-4]、[3,1,2,-2,-5,-4]、[-2,3,-5,1,-4,2] 这样的其他方案是不正确的 ，因为不满足一个或者多个条件。
// 示例 2：
// 输入：nums = [-1,1]
// 输出：[1,-1]
// 解释：
// 1 是 nums 中唯一一个正整数，-1 是 nums 中唯一一个负整数。
// 所以 nums 重排为 [1,-1] 。
//  
// 提示：
//  * 2 <= nums.length <= 2 * 105
//  * nums.length 是 偶数
//  * 1 <= |nums[i]| <= 105
//  * nums 由 相等 数量的正整数和负整数组成
//  
// 不需要原地进行修改。

// #v1
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;

  int pos[numsSize/2], neg[numsSize/2], p = 0, q = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0) pos[p++] = nums[i];
    else neg[q++] = nums[i];
  }

  p = q = 0;
  for (int i = 0; i < numsSize; i++) {
    nums[i] = (i & 1) ? neg[q++] : pos[p++];
  }

  return nums;
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
  int n, *a, *ret, returnSize;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = rearrangeArray(a, n, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
