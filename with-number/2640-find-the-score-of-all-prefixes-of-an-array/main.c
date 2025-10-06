#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2640. 一个数组所有前缀的分数 - 定义一个数组 arr 的 转换数组 conver 为：
//  * conver[i] = arr[i] + max(arr[0..i])，其中 max(arr[0..i]) 是满足 0 <= j <= i 的所有 arr[j] 中的最大值。
// 定义一个数组 arr 的 分数 为 arr 转换数组中所有元素的和。
// 给你一个下标从 0 开始长度为 n 的整数数组 nums ，请你返回一个长度为 n 的数组 ans  ，其中 ans[i]是前缀 nums[0..i] 的分数。
//  
// 示例 1：
// 输入：nums = [2,3,7,5,10]
// 输出：[4,10,24,36,56]
// 解释：
// 对于前缀 [2] ，转换数组为 [4] ，所以分数为 4 。
// 对于前缀 [2, 3] ，转换数组为 [4, 6] ，所以分数为 10 。
// 对于前缀 [2, 3, 7] ，转换数组为 [4, 6, 14] ，所以分数为 24 。
// 对于前缀 [2, 3, 7, 5] ，转换数组为 [4, 6, 14, 12] ，所以分数为 36 。
// 对于前缀 [2, 3, 7, 5, 10] ，转换数组为 [4, 6, 14, 12, 20] ，所以分数为 56 。
// 示例 2：
// 输入：nums = [1,1,2,4,8,16]
// 输出：[2,4,8,16,32,64]
// 解释：
// 对于前缀 [1] ，转换数组为 [2] ，所以分数为 2 。
// 对于前缀 [1, 1]，转换数组为 [2, 2] ，所以分数为 4 。
// 对于前缀 [1, 1, 2]，转换数组为 [2, 2, 4] ，所以分数为 8 。
// 对于前缀 [1, 1, 2, 4]，转换数组为 [2, 2, 4, 8] ，所以分数为 16 。
// 对于前缀 [1, 1, 2, 4, 8]，转换数组为 [2, 2, 4, 8, 16] ，所以分数为 32 。
// 对于前缀 [1, 1, 2, 4, 8, 16]，转换数组为 [2, 2, 4, 8, 16, 32] ，所以分数为 64 。
//  
// 提示：
//  * 1 <= nums.length <= 10^5
//  * 1 <= nums[i] <= 10^9

// #v1
// prefix sum
long long* findPrefixScore(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;

  long long *ret = (long long *)malloc(sizeof(long long) * numsSize);
  int max = nums[0];

  // init
  ret[0] = max + nums[0];

  for (int i = 1; i < numsSize; i++) {
    // record max value
    if (nums[i] > max) max = nums[i];

    // prefix sum
    ret[i] = ret[i-1] + nums[i] + max;
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

void print_1d_arr(long long *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%lld", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *a, s;
  long long *ret;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findPrefixScore(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
