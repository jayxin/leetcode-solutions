#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 905. 按 奇偶排序数组 - 给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面 ，后跟所有奇数元素。
// 返回满足此条件的 任一数组 作为答案。
//  
// 示例 1：
// 输入：nums = [3,1,2,4]
// 输出：[2,4,3,1]
// 解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
// 示例 2：
// 输入：nums = [0]
// 输出：[0]
//  
// 提示：
//  * 1 <= nums.length <= 5000
//  * 0 <= nums[i] <= 5000

// #v1
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int i = 0, j = 0;

  while (i < numsSize) {
    if (!(nums[i] & 1)) {
      int t = nums[i];
      nums[i] = nums[j];
      nums[j] = t;
      ++j;
    }

    ++i;
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
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = sortArrayByParity(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
