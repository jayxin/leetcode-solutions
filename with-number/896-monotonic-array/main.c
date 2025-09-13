#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 896. 单调数列 - 如果数组是单调递增或单调递减的，那么它是 单调 的。
// 如果对于所有 i &lt;= j，nums[i] &lt;= nums[j]，那么数组 nums 是单调递增的。 如果 对于所有 i &lt;= j，nums[i] &gt;= nums[j]，那么数组 nums 是单调递减的。
// 当给定的数组 nums 是单调数组时返回 true，否则返回 false。
//  
// 示例 1：
// 输入：nums = [1,2,2,3]
// 输出：true
// 示例 2：
// 输入：nums = [6,5,4,4]
// 输出：true
// 示例 3：
// 输入：nums = [1,3,2]
// 输出：false
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 105
//  * -105 &lt;= nums[i] &lt;= 105

// #v1
bool isMonotonic(int* nums, int numsSize) {
  int i;
  bool f1 = true ,f2 = true;

  for (i = 1; i < numsSize; i++) {
    if (nums[i - 1] > nums[i]) {
      f1 = false;
      break;
    }
  }

  for (i = 1; i < numsSize; i++) {
    if (nums[i - 1] < nums[i]) {
      f2 = false;
      break;
    }
  }

  return f1 || f2;
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
  if (isMonotonic(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
