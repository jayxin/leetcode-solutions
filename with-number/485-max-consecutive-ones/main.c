#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 485. 最大连续 1 的个数 - 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
//  
// 示例 1：
// 输入：nums = [1,1,0,1,1,1]
// 输出：3
// 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
// 示例 2:
// 输入：nums = [1,0,1,1,0,1]
// 输出：2
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * nums[i] 不是 0 就是 1.

// #v1
int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int ret = 0, cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i]) {
      cnt++;
    } else {
      if (cnt > ret) ret = cnt;
      cnt = 0;
    }
  }
  if (cnt > ret) ret = cnt;
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", findMaxConsecutiveOnes(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
