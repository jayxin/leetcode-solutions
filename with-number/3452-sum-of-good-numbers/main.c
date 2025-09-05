#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3452. 好数 字之和 - 给定一个整数数组 nums 和一个整数 k，如果元素 nums[i] 严格 大于下标 i - k 和 i + k 处的元素（如果这些元素存在），则该元素 nums[i] 被认为是 好 的。如果这两个下标至少一个不存在，那么 nums[i] 仍然被认为是 好 的。
// 返回数组中所有 好 元素的 和。
//  
// 示例 1：
// 输入： nums = [1,3,2,1,5,4], k = 2
// 输出： 12
// 解释：
// 好的数字包括 nums[1] = 3，nums[4] = 5 和 nums[5] = 4，因为它们严格大于下标 i - k 和 i + k 处的数字。
// 示例 2：
// 输入： nums = [2,1], k = 1
// 输出： 2
// 解释：
// 唯一的好数字是 nums[0] = 2，因为它严格大于 nums[1]。
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 100
//  * 1 &lt;= nums[i] &lt;= 1000
//  * 1 &lt;= k &lt;= floor(nums.length / 2)

// #v1
int sumOfGoodNumbers(int* nums, int numsSize, int k) {
  int ret = 0, i1, i2;
  for (int i = 0; i < numsSize; i++) {
    i1 = i - k;
    i2 = i + k;

    if (i1 >= 0 && nums[i] <= nums[i1]) {
      continue;
    }
    if (i2 < numsSize && nums[i] <= nums[i2]) {
      continue;
    }
    ret += nums[i];
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, k;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", sumOfGoodNumbers(arr, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
