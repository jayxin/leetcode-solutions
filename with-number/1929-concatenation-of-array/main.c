#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1929. 数组串 联 - 给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，数组下标 从 0 开始计数 ，对于所有 0 <= i < n 的 i ，满足下述所有要求：
//  * ans[i] == nums[i]
//  * ans[i + n] == nums[i]
// 具体而言，ans 由两个 nums 数组 串联 形成。
// 返回数组 ans 。
//  
// 示例 1：
// 输入：nums = [1,2,1]
// 输出：[1,2,1,1,2,1]
// 解释：数组 ans 按下述方式形成：
// - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
// - ans = [1,2,1,1,2,1]
// 示例 2：
// 输入：nums = [1,3,2,1]
// 输出：[1,3,2,1,1,3,2,1]
// 解释：数组 ans 按下述方式形成：
// - ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
// - ans = [1,3,2,1,1,3,2,1]
//  
// 提示：
//  * n == nums.length
//  * 1 <= n <= 1000
//  * 1 <= nums[i] <= 1000

// #v1
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
  int l = (numsSize << 1), *ret;

  *returnSize = l;
  ret = (int *)malloc(sizeof(int) * l);

  for (int i = 0; i < numsSize; i++) ret[i] = ret[i + numsSize] = nums[i];

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
  ret = getConcatenation(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
